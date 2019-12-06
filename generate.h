#pragma once
#include <fstream>
#include "tree.h"
#include <string>
using namespace std;

extern int tempMaxNum;
// 生成代码调用
extern void genAsmCode(ofstream& fout, Node *root);
// asm代码的最初代码部分
extern void initFile(ofstream& fout);
// 写数据段
extern void writeDataCode(ofstream& fout, Node* root);
// 根据声明语句节点，写对应的变量代码段
extern void gen_data_code(ofstream& fout, Node* declNode);
// 针对节点生成代码/递归函数
extern void recursive_gen_code(ofstream& fout, Node* root);

extern void stmt_gen_code(ofstream& fout, Node* root);
extern void expr_gen_code(ofstream& fout, Node* root);

void genAsmCode(ofstream& fout, Node *root) {
	initFile(fout);
	writeDataCode(fout, root);
	fout << "\t.code" << endl;
	recursive_gen_code(fout, root);
}

void initFile(ofstream& fout) {
	fout << "\t.486" << endl;
	fout << "\t.model flat, stdcall" << endl;
	fout << endl;
	fout << "\tinclude \\masm32\\include\\msvcrt.inc" << endl;
	fout << "\tincludelib \\masm32\\lib\\msvcrt.lib" << endl;
	fout << endl;
}

// 写数据段.data
void writeDataCode(ofstream& fout, Node* root) {
	fout << "\t.data" << endl;
	Node* stmt = root->child[0];
	while (stmt)
	{
		if (stmt->nodeKind == StmtK && stmt->kind.stmtKind == DeclK)
			gen_data_code(fout, stmt);
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
	case Void:
		break;
	case Integer:
		str = " DWORD 0";
		break;
	case Char:
		str = " BYTTE 0";
		break;
	case Bool:
		str = " BYTE 0";
		break;
	default:
		break;
	}

	assert(str != "");

	for (auto curID = declNode->child[1]; curID != nullptr; curID = curID->sibling) {
		fout << "\t\t_" << curID->attr.name << str << endl;
	}

	fout << endl;
}

void recursive_gen_code(ofstream& fout, Node* root) {
	if (root->nodeKind == StmtK)
		stmt_gen_code(fout, root);
	else if (root->nodeKind == ExpK)
		expr_gen_code(fout, root);
}

void stmt_gen_code(ofstream& fout, Node* root) {
	if (root->kind.stmtKind == CompK) {
		for (auto node = root->child[0]; node != nullptr; node = node->sibling) {
			recursive_gen_code(fout, node);
		}
	}
	else {
		switch (root->kind.stmtKind)
		{
		case IfK:
			recursive_gen_code(fout, root->child[0]);
			// 有else分支
			if (root->child[2]) { 
				fout << "\t\tMOV eax 0" << endl;
				fout << "\t\tcmp eax t" << root->child[0]->tempNum << endl;
				fout << "\t\tje " << root->label[1] << endl;
				recursive_gen_code(fout, root->child[1]);
				fout << root->label[1] << ":" << endl;
				recursive_gen_code(fout, root->child[2]);
				fout << root->label[2] << ":" << endl;
			}
			else {
				fout << "\t\tMOV eax 0" << endl;
				fout << "\t\tcmp eax t" << root->child[0]->tempNum << endl;
				fout << "\t\tje " << root->label[1] << endl;
				recursive_gen_code(fout, root->child[1]);
				fout << root->label[1] << ":" << endl;
			}
			fout << endl;
			break;
		case WhileK:
			fout << root->label[0] << ":" << endl;
			recursive_gen_code(fout, root->child[0]);
			fout << "\t\tMOV eax 0" << endl;
			fout << "\t\tcmp eax t" << root->child[0]->tempNum << endl;
			fout << "\t\tje " << root->label[2] << endl;

			recursive_gen_code(fout, root->child[1]);
			fout << "\t\tjmp " << root->label[0] << endl;
			fout << root->label[2] << ":" << endl;
			fout << endl;
			break;
		case AssignK:
			break;
		case ForK:
			break;
		case CompK:
			break;
		case InputK:
			break;
		case OutputK:
			break;
		case DeclK:
			// do nothing
			break;
		case EmptyK:
			break;
		default:
			break;
		}
	}
}

void expr_gen_code(ofstream& fout, Node* root) {
	switch (root->kind.expKind)
	{
	case OpK:
		if (!strcmp(root->attr.op, "+")) {
			Node *e1 = root->child[0];
			Node *e2 = root->child[1];
			if (e1->kind.expKind == IdK) {
				fout << "\tMOV eax, ";
				fout << "_" << e1->attr.name << endl;
			}
			else if (e1->kind.expKind == ConstK) {
				switch (e1->type)
				{
				case Integer:
					fout << e1->attr.value.intVal << endl;
					break;
				case Char:
					fout << e1->attr.value.chVal << endl;
					break;
				case Bool:
					fout << e1->attr.value.booleanVal << endl;
					break;
				default:
					break;
				}
			}
			else {
				recursive_gen_code(fout, e1);
				fout << "t" << e1->tempNum << endl;
			}

		}
		break;
	case ConstK:
		break;
	case IdK:
		break;
	default:
		break;
	}
}