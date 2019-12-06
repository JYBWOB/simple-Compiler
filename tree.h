#pragma once
#include <assert.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


enum ErrorKind {
	Normal, ChildError, SibError,
	NotDef, ReDef, 
	IntToChar, CharToInt, IntToBool, BoolToInt, CharToBool, BoolToChar,
	OutBool, OutVoid,
	LogNotBool
};


enum NodeKind
{
	StmtK, ExpK, TypeK
};

enum StmtKind
{
	IfK, WhileK, AssignK, ForK, CompK, InputK, OutputK, DeclK, EmptyK
};

enum ExpKind
{
	OpK, ConstK, IdK
};

enum TypeKind
{
	Void, Integer, Char, Bool, Float, Double
};

string kindName[] = { "Void", "Integer", "Char", "Bool", "Float", "Double"};


ErrorKind getDiffError(TypeKind type1, TypeKind type2) {
	switch (type1)
	{
	case Integer:
		switch (type2)
		{
		case Char:
			return CharToInt;
			break;
		case Bool:
			return BoolToInt;
			break;
		default:
			break;
		}
		break;
	case Char:
		switch (type2)
		{
		case Integer:
			return IntToChar;
			break;
		case Bool:
			return BoolToChar;
			break;
		default:
			break;
		}
		break;
	case Bool:
		switch (type2)
		{
		case Integer:
			return IntToBool;
			break;
		case Char:
			return CharToBool;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

#define MAXCHILDREN 4
extern int LINENO;

struct Node
{
	Node* child[MAXCHILDREN];
	Node* sibling;
	NodeKind nodeKind;
	union { StmtKind stmtKind; ExpKind expKind; } kind;
	union {
		char* op;
		union {
			int intVal; double doubleVal;
			float floatVal; char chVal; bool booleanVal;
		} value;
		char* name;
	} attr;
	TypeKind type;
	ErrorKind error;
	int lineNo;

	string* label;
	int tempNum;
};

Node* newStmtNode(StmtKind sk) 
{
	Node* result = new Node;
	assert(result != nullptr);
	result->nodeKind = StmtK;
	for(int i = 0; i < MAXCHILDREN; i++)
		result->child[i] = nullptr;
	result->sibling = nullptr;
	result->kind.stmtKind = sk;
	result->lineNo = LINENO++;

	result->type = Void;
	result->error = Normal;

	result->tempNum = -1;
	result->label = nullptr;
	return result;
}

Node* newExpNode(ExpKind ek) 
{
	Node* result = new Node;
	assert(result != nullptr);
	result->nodeKind = ExpK;
	for(int i = 0; i < MAXCHILDREN; i++)
		result->child[i] = nullptr;
	result->sibling = nullptr;
	result->kind.expKind = ek;
    result->type = Void;
	result->error = Normal;
	result->lineNo = LINENO++;

	result->tempNum = -1;
	result->label = nullptr;
	return result;
}

Node* newTypeNode(TypeKind type) 
{
	Node* result = new Node;
	assert(result != nullptr);
	result->nodeKind = TypeK;
	for(int i = 0; i < MAXCHILDREN; i++)
		result->child[i] = nullptr;
	result->sibling = nullptr;
	result->type = type;
	result->error = Normal;
	result->lineNo = LINENO++;

	result->tempNum = -1;
	result->label = nullptr;
	return result;
}

void ShowNode(Node* root) {

	cout << root->lineNo << ": ";
	switch (root->nodeKind)
	{
	case StmtK:
		//IfK, WhileK, AssignK, ForK, CompK, InputK, OutputK, DeclK
		switch (root->kind.stmtKind)
		{
		case IfK:
			cout << "If statement,\t\t\t";
			break;
		case WhileK:
			cout << "While statement,\t\t\t";
			break;
		case AssignK:
			cout << "Assign statement,\t\t\t";
			break;
		case ForK:
			cout << "For statement,\t\t\t";
			break;
		case CompK:
			cout << "Compound statement,\t\t\t";
			break;
		case DeclK:
			cout << "Var Declaration,\t\t\t";
			break;
		case EmptyK:
			cout << "Empty statemtent,\t\t\t";
			break;
		case InputK:
			cout << "Input statement,\t\t\t";
			break;
		case OutputK:
			cout << "Output statement,\t\t\t";
			break;
		default:
			cout << "Error" << endl;
			break;
		}
		break;
	case ExpK:
		switch (root->kind.expKind)
		{
		case OpK:
			cout << "Expr,\t\top:" << root->attr.op << ",\t\t";
			break;
		case ConstK:
			switch (root->type)
			{
			case Integer:
				cout << "Const Declaration,\tvalue:" << root->attr.value.intVal << ",\t";
				break;
			case Char:
				cout << "Const Declaration,\tvalue:" << root->attr.value.chVal << ",\t";
				break;
			case Bool:
				if (root->attr.value.booleanVal)
					cout << "Const Declaration,\tvalue:" << "true" << ",\t";
				else
					cout << "Const Declaration,\tvalue:" << "false" << ",\t";
				break;
			case Float:
				cout << "Const Declaration,\tvalue:" << root->attr.value.floatVal << ",\t";
				break;
			case Double:
				cout << "Const Declaration,\tvalue:" << root->attr.value.doubleVal << ",\t";
				break;
			default:
				cout << "Error" << endl;
				break;
			}
			break;
		case IdK:
			cout << "ID Declaration,\tsymbol:" << root->attr.name << ",\t";
			break;
		default:
			cout << "Error" << endl;
			break;
		}
		break;
	case TypeK:
		cout << "Type Specifier,\t";
		switch (root->type)
		{
		case Void:
			cout << "void,\t";
			break;
		case Integer:
			cout << "integer,\t";
			break;
		case Float:
			cout << "float,\t";
			break;
		case Double:
			cout << "double,\t";
			break;
		case Char:
			cout << "char,\t\t";
			break;
		case Bool:
			cout << "bool,\t";
			break;
		default:
			cout << "Error" << endl;
			break;
		}
		break;
	default:
		cout << "Error" << endl;
		break;
	}
	cout << "Children:";
	for (int i = 0; i < MAXCHILDREN; i++) {
		if (root->child[i] != nullptr) {
			cout << root->child[i]->lineNo << ", ";
			Node* temp = root->child[i]->sibling;
			while (temp) {
				cout << temp->lineNo << ", ";
				temp = temp->sibling;
			}
		}
	}
	// tempÊä³ö
	cout << "\t\t";
	if (root->tempNum != -1) {
		cout << "temp:" << root->tempNum;
	}
	//cout << endl;

	// labelÊä³ö
	//cout << "\t\t";
	//if (root->label != nullptr) {
	//	cout << root->label[0];
	//}
	//cout << endl;


	// ´íÎó¼ì²é
	//cout << "\t\t\t";
	//switch (root->error)
	//{
	//case Normal:
	//	cout << kindName[root->type];
	//	break;
	//case ChildError:
	//	cout << "Error:Children Error";
	//	break;
	//case SibError:
	//	cout << "Error:Sibling Error";
	//	break;
	//case NotDef:
	//	cout << "Error:Undeclared identifier";
	//	break;
	//case ReDef:
	//	cout << "Error:Variable redefinition";
	//	break;
	//case IntToChar:
	//	cout << "Error:Operations on Int to Char";
	//	break;
	//case CharToInt:
	//	cout << "Error:Operations on Char to Int";
	//	break;
	//case IntToBool:
	//	cout << "Error:Operations on Int to Bool";
	//	break;
	//case BoolToInt:
	//	cout << "Error:Operations on Bool to Int";
	//	break;
	//case CharToBool:
	//	cout << "Error:Operations on Char to Bool";
	//	break;
	//case BoolToChar:
	//	cout << "Error:Operations on Bool to Char";
	//	break;
	//case OutBool:
	//	cout << "Error:Can't output boolean type";
	//	break;
	//case OutVoid:
	//	cout << "Error:Can't output void type";
	//	break;
	//case LogNotBool:
	//	cout << "Error:Logical operand is not of type bool";
	//	break;
	//default:
	//	break;
	//}

	cout << endl;

}

void postOrderTraverse(Node* root)
{
	if (root == nullptr)
		return;
	for (int i = 0; i < MAXCHILDREN; i++)
		postOrderTraverse(root->child[i]);

	ShowNode(root);

	postOrderTraverse(root->sibling);
}