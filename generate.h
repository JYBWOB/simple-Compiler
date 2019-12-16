#pragma once
#include <fstream>
#include "tree.h"
#include <string>
#include <stack>
using namespace std;

bool debug = true;

extern int tempMaxNum;
// 生成代码调用
extern void genAsmCode(ofstream& fout, Node *root);
// asm代码的最初代码部分
extern void initFile(ofstream& fout);
// 写数据段
extern void writeDataCode(ofstream& fout, Node* root);
// 写函数定义
extern void writeFunCode(ofstream& fout, Node* root);

// 根据声明语句节点，写对应的变量代码段
extern void gen_data_code(ofstream& fout, Node* declNode);
// 根据函数节点生成函数代码
extern void gen_fun_code(ofstream& fout, Node* root);

// 针对节点生成代码/递归函数
extern void recursive_gen_code(ofstream& fout, Node* root);

extern void stmt_gen_code(ofstream& fout, Node* root);
extern void expr_gen_code(ofstream& fout, Node* root);

// expr节点是否需要递归处理
// ID & Const 不需要递归，返回false，并将对应值存入target寄存器
// Op 需要递归，直接返回true
// assign类型，直接返回true
extern bool needToRecursive(ofstream& fout, Node* root, string target);

void genAsmCode(ofstream& fout, Node *root) {
	initFile(fout);
	writeDataCode(fout, root);
	fout << "\t.code" << endl;
	writeFunCode(fout, root);
	fout << "\t_start:" << endl;
	recursive_gen_code(fout, root);
	fout << "\tinvoke crt_printf, SADD(\"按任意键继续...\")" << endl;
	fout << "\tinvoke crt__getch" << endl;
	fout << "\tinvoke crt__exit, 0" << endl;
	fout << "\tend _start" << endl;
}

void initFile(ofstream& fout) {
	fout << "\t.486" << endl;
	fout << "\t.model flat, stdcall" << endl;
	fout << "\toption casemap :none" << endl;
	fout << endl;
	fout << "\tinclude \\masm32\\macros\\macros.asm" << endl;
	fout << "\tinclude \\masm32\\include\\msvcrt.inc" << endl;
	fout << "\tincludelib \\masm32\\lib\\msvcrt.lib" << endl;
	fout << endl;
}

void recursive_gen_code(ofstream& fout, Node* root) {
	if (root->nodeKind == StmtK)
		stmt_gen_code(fout, root);
	else if (root->nodeKind == ExpK)
		expr_gen_code(fout, root);
}

void stmt_gen_code(ofstream& fout, Node* root) {
	switch (root->kind.stmtKind)
	{
	case IfK:
	{
		fout << "; if stmt" << endl;
		root->child[0]->trueLabel = root->label[0];
		root->child[0]->falseLabel = root->label[1];
		recursive_gen_code(fout, root->child[0]);
		// 有else分支
		if (root->child[2]) {
			fout << root->label[0] << ":" << endl;
			recursive_gen_code(fout, root->child[1]);
			fout << "\tjmp " << root->label[2] << endl;
			fout << root->label[1] << ":" << endl;
			recursive_gen_code(fout, root->child[2]);
			fout << root->label[2] << ":" << endl;
		}
		else {

			fout << root->label[0] << ":" << endl;
			recursive_gen_code(fout, root->child[1]);
			fout << root->label[1] << ":" << endl;
		}
		fout << endl;
		break;
	}
	case WhileK:
	{
		fout << "; while stmt" << endl;
		fout << root->label[0] << ":" << endl;

		root->child[0]->trueLabel = root->label[1];
		root->child[0]->falseLabel = root->label[2];
		recursive_gen_code(fout, root->child[0]);

		fout << root->label[1] << ":" << endl;
		recursive_gen_code(fout, root->child[1]);
		fout << "\tjmp " << root->label[0] << endl;
		fout << root->label[2] << ":" << endl;
		fout << endl;
		break;
	}
	case AssignK:
	{
		fout << "; assign stmt" << endl;
		Node* e1 = root->child[0];
		Node* e2 = root->child[1];
		if (needToRecursive(fout, e2, "eax")) {
			recursive_gen_code(fout, e2);
			fout << "\tMOV eax, t" << e2->tempNum << endl;
		}
		if (e1->kind.expKind == IdArrK) {
			if (needToRecursive(fout, e1->child[1], "ebx")) {
				recursive_gen_code(fout, root->child[1]);
				fout << "\tMOV ebx, t" << root->child[1]->tempNum << endl;
			}
			fout << "\tMOV _" << e1->child[0]->attr.name << "[ebx*4], eax" << endl;
		}
		else {
			fout << "\tMOV _" << e1->attr.name << ", eax" << endl;
		}
		if(root->tempNum != -1)
			fout << "\tMOV t" << root->tempNum << ", eax" << endl;
		fout << endl;
		break;
	}
	case ForK: 
	{
		fout << endl; 
		fout << "; for stmt" << endl;
		Node* expr1 = root->child[0];
		Node* expr2 = root->child[1];
		Node* expr3 = root->child[2];
		Node* body = root->child[3];
		if (expr1) {
			recursive_gen_code(fout, expr1);
		}
		fout << root->label[0] << ":" << endl;
		if (expr2) {
			expr2->trueLabel = root->label[1];
			expr2->falseLabel = root->label[2];
			recursive_gen_code(fout, expr2);
		}
		fout << root->label[1] << ":" << endl;
		recursive_gen_code(fout, body);
		if (expr3) {
			recursive_gen_code(fout, expr3);
		}
		fout << "\tjmp " << root->label[0] << endl;
		fout << root->label[2] << ":" << endl;
		fout << endl;
	}
	break;
	case CompK:
		for (auto node = root->child[0]; node != nullptr; node = node->sibling) {
			recursive_gen_code(fout, node);
		}
		break;
	case InputK:
		fout << "; Input stmt" << endl;
		if (root->child[0]->kind.expKind == IdArrK) {
			Node* idNode = root->child[0]; 
			if (needToRecursive(fout, idNode->child[1], "ebx")) {
				recursive_gen_code(fout, idNode->child[1]);
				fout << "\tMOV ebx, t" << idNode->child[1]->tempNum << endl;
			}
			if (idNode->type == Char) {
				fout << "\tinvoke crt_scanf, SADD(\"%c\", 0), addr _"
					<< idNode->child[0]->attr.name << "[4*ebx]" << endl;
			}
			else
				fout << "\tinvoke crt_scanf, SADD(\"%d\", 0), addr _"
				<< idNode->child[0]->attr.name << "[4*ebx]" << endl;
		}
		else {
			if (root->child[0]->type == Char)
				fout << "\tinvoke crt_scanf, SADD(\"%c\", 0), addr _"
				<< root->child[0]->attr.name << endl;
			else
				fout << "\tinvoke crt_scanf, SADD(\"%d\", 0), addr _"
				<< root->child[0]->attr.name << endl;
		}
		break;
	case OutputK: {
		fout << "; Output stmt" << endl;
		Node* idNode = root->child[0];
		if (idNode->kind.expKind == IdArrK) {
			if (needToRecursive(fout, idNode->child[1], "ebx")) {
				recursive_gen_code(fout, idNode->child[1]);
				fout << "\tMOV ebx, _" << idNode->child[1]->tempNum << endl;
			}
			fout << "\tMOV eax, _"
				<< idNode->child[0]->attr.name << "[4*ebx]" << endl;
		}
		else {
			if (needToRecursive(fout, idNode, "eax")) {
				recursive_gen_code(fout, idNode);
				fout << "\tMOV eax, t" << idNode->tempNum << endl;
			}
		}
		if (idNode->type == Char)
			fout << "\tinvoke crt_printf, SADD(\"%c\", 13, 10), eax" << endl;
		else
			fout << "\tinvoke crt_printf, SADD(\"%d\", 13, 10), eax" << endl;
		fout << endl;
		break;
	}
	case ReturnK:
		
		fout << "\tpop ebx" << endl;
		fout << "\tpop eax" << endl;
		fout << "\tpop ebp" << endl;
		// TODO:
		if (root->child[0] && needToRecursive(fout, root->child[0], "ecx")) {
			recursive_gen_code(fout, root->child[0]);
			fout << "\tMOV ecx, t" << root->child[0]->tempNum << endl;
		}
		fout << "\tret" << endl;
		
		break;
	case CallK: {
			Node* fun = root->child[0];
			Node* params = root->child[1];
			while (params) {
				if (needToRecursive(fout, params, "ecx")) {
					recursive_gen_code(fout, params);
					fout << "\tMOV ecx, t" << params->tempNum<< endl;
				}
				fout << "\tpush ecx" << endl;
				params = params->sibling;
			}
			fout << "\tcall " << fun->attr.name << endl;
			fout << "\tMOV _" << fun->attr.name << ", ecx" << endl;

			params = root->child[1];
			while (params) {
				fout << "\tpop ecx" << endl;
				params = params->sibling;
			}
			
		}
		break;
	case FuncK:
		// do nothing
		break;
	case DeclK:
		// do nothing
		break;
	case EmptyK:
		// do nothing 
		break;
	default:
		break;
	}
}

void expr_gen_code(ofstream& fout, Node* root) {
	switch (root->kind.expKind)
	{
	case OpK:
		if (string(root->attr.op) == "+") {
			Node* e1 = root->child[0];
			Node* e2 = root->child[1];
			
			if(needToRecursive(fout, e1, "eax")) {
				recursive_gen_code(fout, e1);
				fout << "\tMOV eax, t" << e1->tempNum << endl;
			}
			if (needToRecursive(fout, e2, "ebx")) {
				recursive_gen_code(fout, e2);
				fout << "\tMOV ebx, t" << e2->tempNum << endl;
			}
			fout << "\tADD eax, ebx" << endl;
			fout << "\tMOV t" << root->tempNum << ", eax" << endl;
		}
		else if (string(root->attr.op) == "-") {
			Node* e1 = root->child[0];
			Node* e2 = root->child[1];
			if (needToRecursive(fout, e1, "eax")) {
				recursive_gen_code(fout, e1);
				fout << "\tMOV eax, t" << e1->tempNum << endl;
			}
			if (needToRecursive(fout, e2, "ebx")) {
				recursive_gen_code(fout, e2);
				fout << "\tMOV ebx, t" << e2->tempNum << endl;
			}
			fout << "\tSUB eax, ebx" << endl;
			fout << "\tMOV t" << root->tempNum << ", eax" << endl;
		}
		else if (string(root->attr.op) == "*") {
			Node* e1 = root->child[0];
			Node* e2 = root->child[1];
			if (needToRecursive(fout, e1, "eax")) {
				recursive_gen_code(fout, e1);
				fout << "\tMOV eax, t" << e1->tempNum << endl;
			}
			if (needToRecursive(fout, e2, "ebx")) {
				recursive_gen_code(fout, e2);
				fout << "\tMOV ebx, t" << e2->tempNum << endl;
			}
			fout << "\tMUL ebx" << endl;
			fout << "\tMOV t" << root->tempNum << ", eax" << endl;
		}
		else if (string(root->attr.op) == "/") {
			Node* e1 = root->child[0];
			Node* e2 = root->child[1];
			if (needToRecursive(fout, e1, "eax")) {
				recursive_gen_code(fout, e1);
				fout << "\tMOV eax, t" << e1->tempNum << endl;
			}
			if (needToRecursive(fout, e2, "ebx")) {
				recursive_gen_code(fout, e2);
				fout << "\tMOV ebx, t" << e2->tempNum << endl;
			}
			fout << "\tDIV ebx" << endl;
			fout << "\tMOV t" << root->tempNum << ", eax" << endl;
		}
		else if (string(root->attr.op) == "%") {
			Node* e1 = root->child[0];
			Node* e2 = root->child[1];
			if (needToRecursive(fout, e1, "eax")) {
				recursive_gen_code(fout, e1);
				fout << "\tMOV eax, t" << e1->tempNum << endl;
			}
			if (needToRecursive(fout, e2, "ebx")) {
				recursive_gen_code(fout, e2);
				fout << "\tMOV ebx, t" << e2->tempNum << endl;
			}
			fout << "\tDIV ebx" << endl;
			fout << "\tMOV t" << root->tempNum << ", edx" << endl;
		}
		else if (string(root->attr.op) == "&") {
			Node* e1 = root->child[0];
			Node* e2 = root->child[1];
			if (needToRecursive(fout, e1, "eax")) {
				recursive_gen_code(fout, e1);
				fout << "\tMOV eax, t" << e1->tempNum << endl;
			}
			if (needToRecursive(fout, e2, "ebx")) {
				recursive_gen_code(fout, e2);
				fout << "\tMOV ebx, t" << e2->tempNum << endl;
			}
			fout << "\tAND eax, ebx" << endl;
			fout << "\tMOV t" << root->tempNum << ", eax" << endl;
		}
		else if (string(root->attr.op) == "|") {
			Node* e1 = root->child[0];
			Node* e2 = root->child[1];
			if (needToRecursive(fout, e1, "eax")) {
				recursive_gen_code(fout, e1);
				fout << "\tMOV eax, t" << e1->tempNum << endl;
			}
			if (needToRecursive(fout, e2, "ebx")) {
				recursive_gen_code(fout, e2);
				fout << "\tMOV ebx, t" << e2->tempNum << endl;
			}
			fout << "\tOR eax, ebx" << endl;
			fout << "\tMOV t" << root->tempNum << ", eax" << endl;
		}
		else if (string(root->attr.op) == ">") {
			Node* e1 = root->child[0];
			Node* e2 = root->child[1];
			
			if (needToRecursive(fout, e1, "eax")) {
				recursive_gen_code(fout, e1);
				fout << "\tMOV eax, t" << e1->tempNum << endl;
			}
			if (needToRecursive(fout, e2, "ebx")) {
				recursive_gen_code(fout, e2);
				fout << "\tMOV ebx, t" << e2->tempNum << endl;
			}
			fout << "\tCMP eax, ebx" << endl;
			fout << "\tjg " << root->trueLabel << endl;
			fout << "\tjmp " << root->falseLabel << endl;
		}
		else if (string(root->attr.op) == ">=") {
			Node* e1 = root->child[0];
			Node* e2 = root->child[1];

			if (needToRecursive(fout, e1, "eax")) {
				recursive_gen_code(fout, e1);
				fout << "\tMOV eax, t" << e1->tempNum << endl;
			}
			if (needToRecursive(fout, e2, "ebx")) {
				recursive_gen_code(fout, e2);
				fout << "\tMOV ebx, t" << e2->tempNum << endl;
			}
			fout << "\tCMP eax, ebx" << endl;
			fout << "\tjge " << root->trueLabel << endl;
			fout << "\tjmp " << root->falseLabel << endl;
		}
		else if (string(root->attr.op) == "<") {
			Node* e1 = root->child[0];
			Node* e2 = root->child[1];

			if (needToRecursive(fout, e1, "eax")) {
				recursive_gen_code(fout, e1);
				fout << "\tMOV eax, t" << e1->tempNum << endl;
			}
			if (needToRecursive(fout, e2, "ebx")) {
				recursive_gen_code(fout, e2);
				fout << "\tMOV ebx, t" << e2->tempNum << endl;
			}
			fout << "\tCMP eax, ebx" << endl;
			fout << "\tjl " << root->trueLabel << endl;
			fout << "\tjmp " << root->falseLabel << endl;
		}
		else if (string(root->attr.op) == "<=") {
			Node* e1 = root->child[0];
			Node* e2 = root->child[1];

			if (needToRecursive(fout, e1, "eax")) {
				recursive_gen_code(fout, e1);
				fout << "\tMOV eax, t" << e1->tempNum << endl;
			}
			if (needToRecursive(fout, e2, "ebx")) {
				recursive_gen_code(fout, e2);
				fout << "\tMOV ebx, t" << e2->tempNum << endl;
			}
			fout << "\tCMP eax, ebx" << endl;
			fout << "\tjle " << root->trueLabel << endl;
			fout << "\tjmp " << root->falseLabel << endl;
		}
		else if (string(root->attr.op) == "==") {
			Node* e1 = root->child[0];
			Node* e2 = root->child[1];

			if (needToRecursive(fout, e1, "eax")) {
				recursive_gen_code(fout, e1);
				fout << "\tMOV eax, t" << e1->tempNum << endl;
			}
			if (needToRecursive(fout, e2, "ebx")) {
				recursive_gen_code(fout, e2);
				fout << "\tMOV ebx, t" << e2->tempNum << endl;
			}
			fout << "\tCMP eax, ebx" << endl;
			fout << "\tje " << root->trueLabel << endl;
			fout << "\tjmp " << root->falseLabel << endl;
		}
		else if (string(root->attr.op) == "!=") {
			Node* e1 = root->child[0];
			Node* e2 = root->child[1];

			if (needToRecursive(fout, e1, "eax")) {
				recursive_gen_code(fout, e1);
				fout << "\tMOV eax, t" << e1->tempNum << endl;
			}
			if (needToRecursive(fout, e2, "ebx")) {
				recursive_gen_code(fout, e2);
				fout << "\tMOV ebx, t" << e2->tempNum << endl;
			}
			fout << "\tCMP eax, ebx" << endl;
			fout << "\tjne " << root->trueLabel << endl;
			fout << "\tjmp " << root->falseLabel << endl;
		}
		else if (string(root->attr.op) == "&&") {
			Node* e1 = root->child[0];
			Node* e2 = root->child[1];
			e1->trueLabel = root->label[0];
			e1->falseLabel = root->label[2];
			e2->trueLabel = root->label[1];
			e2->falseLabel = root->label[2];

			recursive_gen_code(fout, e1);
			fout << root->label[0] << ":" << endl;
			recursive_gen_code(fout, e2);
			fout << root->label[1] << ":" << endl;
			// 均为真
			fout << "\tjmp " << root->trueLabel << endl;
			fout << root->label[2] << ":" << endl;
			// 一个为假
			fout << "\tjmp " << root->falseLabel << endl;
		}
		else if (string(root->attr.op) == "||") {
			Node* e1 = root->child[0];
			Node* e2 = root->child[1];
			e1->trueLabel = root->label[2];
			e1->falseLabel = root->label[0];
			e2->trueLabel = root->label[2];
			e2->falseLabel = root->label[1];

			recursive_gen_code(fout, e1);
			fout << root->label[0] << ":" << endl;
			recursive_gen_code(fout, e2);
			fout << root->label[1] << ":" << endl;
			// 均为假
			fout << "\tjmp " << root->falseLabel << endl;
			fout << root->label[2] << ":" << endl;
			// 一个为真
			fout << "\tjmp " << root->trueLabel << endl;
		}
		else if (string(root->attr.op) == "!") {
			Node* e = root->child[0];
			e->trueLabel = root->falseLabel;
			e->falseLabel = root->trueLabel;
			recursive_gen_code(fout, e);
		}
		break;
	//case ConstK:
	//	switch (root->type)
	//	{
	//	case Integer:
	//		fout << "\tMOV t" << root->tempNum << ", " << root->attr.value.intVal << endl;
	//		break;
	//	case Char:
	//		fout << "\tMOV t" << root->tempNum << ", " << root->attr.value.chVal << endl;
	//		break;
	//	case Bool:
	//		fout << "\tMOV t" << root->tempNum << ", " << root->attr.value.booleanVal << endl;
	//		break;
	//	default:
	//		break;
	//	}
	//	cout << "Error" << endl;
	//	break;
	//case IdK:
	//	fout << "\tMOV eax" << ",  _" << root->attr.name << endl;
	//	fout << "\tMOV t" << root->tempNum << ", eax" << endl;
	//	cout << "Error" << endl;
	//	break;
	default:
		break;
	}
}

// expr是否需要递归， 
// 不需要则取出值到target寄存器，
// 需要则返回true
bool needToRecursive(ofstream& fout, Node* root, string target) {
	if (root->nodeKind == StmtK && root->kind.stmtKind == AssignK)
		return true;
	if (root->nodeKind == StmtK && root->kind.stmtKind == CallK) {
		recursive_gen_code(fout, root);
		fout << "\tMOV " << target << ", _" << root->child[0]->attr.name << endl;
		return false;
	}
	if (root->kind.expKind == IdK) {
		fout << "\tMOV " << target << ", _" << root->attr.name << endl;
		return false;
	}
	if (root->kind.expKind == IdArrK) {
		if (needToRecursive(fout, root->child[1], "ebx")) {
			recursive_gen_code(fout, root->child[1]);
			fout << "\tMOV ebx, t" << root->child[1]->tempNum << endl;
		}
		if(root->child[0]->type == Char)
			fout << "\tMOV " << target << ", _" << 
				root->child[0]->attr.name <<"[4*ebx]" << endl;
		else 
			fout << "\tMOV " << target << ", _" <<
				root->child[0]->attr.name << "[4*ebx]" << endl;
		return false;
	}
	else if (root->kind.expKind == ConstK) {
		fout << "\tMOV " << target << ", ";
		switch (root->type)
		{
		case Integer:
			fout << root->attr.value.intVal << endl;
			break;
		case Char:
			fout << "\'" << root->attr.value.chVal << "\'" << endl;
			break;
		case Bool:
			fout << root->attr.value.booleanVal << endl;
			break;
		default:
			break;
		}
		return false;
	}
	else
		return true;
}

// 写数据段.data
void writeDataCode(ofstream& fout, Node* root) {
	fout << "\t.data" << endl;
	Node* stmt = root->child[0];
	while (stmt)
	{
		if (stmt->nodeKind == StmtK && stmt->kind.stmtKind == DeclK)
			gen_data_code(fout, stmt);
		// 函数参数
		if (stmt->nodeKind == StmtK && stmt->kind.stmtKind == FuncK) {
			// 函数名前加_ 返回值变量
			Node* result = stmt->child[0];
			fout << "\t\t_" << result->child[1]->attr.name << " DWORD 0" << endl;

			Node* params = stmt->child[1];
			while (params) {
				fout << "\t\t_" << params->child[1]->attr.name << " DWORD 0" << endl;
				params = params->sibling;
			}

			Node* lists = stmt->child[2];
			while (lists) {
				if (lists->nodeKind == StmtK && lists->kind.stmtKind == DeclK)
					gen_data_code(fout, lists);
				lists = lists->sibling;
			}
			fout << endl;
		}

		stmt = stmt->sibling;
	}
	for (int i = 0; i < tempMaxNum; i++) {
		fout << "\t\tt" << i << " DWORD 0" << endl;
	}
	fout << endl;

}

void gen_data_code(ofstream& fout, Node* declNode) {
	Node* typeNode = declNode->child[0];
	string str = "";
	switch (typeNode->type)
	{
	case Integer:
		str = " DWORD 0";
		break;
	case Char:
		str = " DWORD \'0\'";
		break;
	case Bool:
		str = " DWORD 0";
		break;
	default:
		break;
	}

	assert(str != "");

	for (auto curID = declNode->child[1]; curID != nullptr; curID = curID->sibling) {
		if(curID->kind.expKind == IdArrK)
			fout << "\t\t_" << curID->child[0]->attr.name 
				<< " DWORD " <<  curID->child[1]->attr.value.intVal << " DUP(0)" << endl;
		else
			fout << "\t\t_" << curID->attr.name << str << endl;
	}

	fout << endl;
}

void writeFunCode(ofstream& fout, Node* root) {
	Node* stmt = root->child[0];
	while (stmt)
	{
		if (stmt->nodeKind == StmtK && stmt->kind.stmtKind == FuncK)
			gen_fun_code(fout, stmt);
		stmt = stmt->sibling;
	}
	fout << endl;
}

void gen_fun_code(ofstream& fout, Node* root) {
	fout << endl;
	Node* result = root->child[0];
	fout << "\t" << result->child[1]->attr.name << ":" << endl;

	fout << "\tpush ebp" << endl;
	fout << "\tMOV ebp, esp" << endl;
	fout << "\tpush eax" << endl;
	fout << "\tpush ebx" << endl;

	Node* params = root->child[1];
	int len = 0;
	while (params) {
		len++;
		params = params->sibling;
	}
	int i = 0;
	params = root->child[1];
	while (params) {
		int offset = 8 + (len - i - 1)*4;
		char str[256];
		sprintf(str, "\tMOV ebx, DWORD ptr[ebp+%d]\n\tMOV _%s, ebx", 
			offset, params->child[1]->attr.name);
		fout << str << endl;
		params = params->sibling;
		i++;
	}
	fout << endl;

	Node* stmts = root->child[2];
	while (stmts)
	{
		recursive_gen_code(fout, stmts);
		stmts = stmts->sibling;
	}
	
	fout << "\tpop ebx" << endl;
	fout << "\tpop eax" << endl;
	fout << "\tpop ebp" << endl;
	fout << "\tret" << endl;
}