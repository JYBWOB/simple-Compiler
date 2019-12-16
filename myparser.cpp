/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 68 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 12/16/19
* Time: 21:54:16
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\myparser.y"

/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2019年11月10日
****************************************************************************/

#include "mylexer.h"
#include "tree.h"
#include "generate.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
int LINENO = 0;

int temp = 0;
int labelNum = 0;
int tempMaxNum = 0;
ofstream fout("result.asm");

extern string kindName[];

struct variable {
	string name;
	enum TypeKind type;
	union {int intVal;double doubleVal;
		   float floatVal;char chVal; bool booleanVal;} value;
		   
};
 
unordered_map<string, variable*> idTable;
unordered_map<string, variable*>::iterator it;

void printIdTable() {
	cout << endl << endl << "variable\t" << "type"<< endl;
	for(auto x : idTable) {
		cout << x.second->name << "\t\t" << kindName[x.second->type] << endl;
	}
}

#line 83 "myparser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 60 ".\\myparser.y"

	// place any extra initialisation code here

#line 107 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 65 ".\\myparser.y"

	// place any extra cleanup code here

#line 121 "myparser.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 113 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(CompK);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(5 - 6);
                
                if(yyattribute(5 - 6)->error != Normal) {
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
                }
                
                postOrderTraverse((*(YYSTYPE YYFAR*)yyvalptr));
                printIdTable();
                
                if((*(YYSTYPE YYFAR*)yyvalptr)->error == Normal)
					genAsmCode(fout, (*(YYSTYPE YYFAR*)yyvalptr));
				else {
					cout << endl << "Error exists" << endl;
					cout << "Can't generate asm code" << endl;
				}
                system("pause");
            
#line 249 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 134 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
                Node* temp = yyattribute(1 - 2);
                while(temp->sibling != nullptr) {
                    temp = temp->sibling;
                }
                temp->sibling = yyattribute(2 - 2);
                if(yyattribute(2 - 2)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = SibError;
            
#line 271 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 144 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
            
#line 286 "myparser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 150 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 301 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 154 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ReturnK);
		(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 3);
	
#line 317 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 158 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
	
#line 332 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 161 ".\\myparser.y"

            if(isDebug) {
                cout << "assign_stmt" << endl;
            }
            temp--;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = -1;
            (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
        
#line 352 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 169 ".\\myparser.y"

            if(isDebug) {
                cout << "declare_stmt" << endl;
            }
            (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
        
#line 370 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 175 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 383 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 176 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 396 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 177 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 409 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 178 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(CompK);
			(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 3);
			
			if(yyattribute(2 - 3)->error != Normal)
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
		
#line 428 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 185 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(InputK);
			(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
			
			// 未声明
			it = idTable.find(yyattribute(3 - 5)->attr.name);
			if(it == idTable.end()) {
				yyattribute(3 - 5)->error = NotDef;
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
			}
			else
				yyattribute(3 - 5)->type = it->second->type;
		
#line 453 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 198 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(InputK);
		(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
		
		// 未声明
		it = idTable.find(yyattribute(3 - 5)->child[0]->attr.name);
		if(it == idTable.end()) {
			yyattribute(3 - 5)->error = NotDef;
			(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
		}
		else
			yyattribute(3 - 5)->type = it->second->type;
	
#line 478 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 211 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(OutputK);
			(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
			
			// 输出Bool
			if(yyattribute(3 - 5)->type == Bool)
				(*(YYSTYPE YYFAR*)yyvalptr)->error = OutBool;
			if(yyattribute(3 - 5)->type == Void)
				(*(YYSTYPE YYFAR*)yyvalptr)->error = OutVoid;
			if(yyattribute(3 - 5)->error != Normal) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
			}
			
			if(yyattribute(3 - 5)->nodeKind == StmtK && yyattribute(3 - 5)->kind.stmtKind == CallK)
				(*(YYSTYPE YYFAR*)yyvalptr)->error = Normal;
			
			if(yyattribute(3 - 5)->kind.expKind == OpK)
					temp--;
			//temp = temp < 0 ? 0 : temp;
		
#line 510 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 231 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(EmptyK);
		
#line 525 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 236 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(FuncK);
		(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 7);
		(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 7);
		(*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(6 - 7);
	
#line 543 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 244 ".\\myparser.y"

			yyattribute(1 - 3)->sibling = yyattribute(3 - 3);
			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
		
#line 559 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 248 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 574 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#line 251 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = nullptr;
		
#line 584 "myparser.cpp"
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 256 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(DeclK);
			(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 2);
			(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(2 - 2);
		
#line 600 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 263 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(CallK);
			(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 4);
			(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 4);
		
#line 617 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 270 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
			yyattribute(1 - 3)->sibling = yyattribute(2 - 3);
		
#line 633 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 275 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 648 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#line 278 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = nullptr;
		
#line 658 "myparser.cpp"
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 283 ".\\myparser.y"

                
                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(AssignK);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
                strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, "=");
                
				it = idTable.find(string(yyattribute(1 - 3)->attr.name));
				// 未定义
				if(it == idTable.end()) {
					yyattribute(1 - 3)->error = NotDef;
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
				}
				else {
					yyattribute(1 - 3)->type = it->second->type;
					// ID/连续赋值，右部出错
					if(yyattribute(3 - 3)->error != Normal) {
						(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
					}
					// 类型不一致
					else if(yyattribute(1 - 3)->type != yyattribute(3 - 3)->type) {
						(*(YYSTYPE YYFAR*)yyvalptr)->error = getDiffError(yyattribute(1 - 3)->type, yyattribute(3 - 3)->type);
					}
					else {
						(*(YYSTYPE YYFAR*)yyvalptr)->type = yyattribute(1 - 3)->type;
					}
					
					if(isDebug)
						cout << yyattribute(1 - 3)->attr.name << ':' << yyattribute(1 - 3)->type << endl;
				}
				
				temp = temp - 1;
				(*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
				tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
				//temp = temp < 0 ? 0 : temp;
		
#line 706 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 320 ".\\myparser.y"

			    (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(AssignK);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
                (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
                strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, "=");
                
                it = idTable.find(string(yyattribute(1 - 3)->child[0]->attr.name));
				// 未定义
				if(it == idTable.end()) {
					yyattribute(1 - 3)->error = NotDef;
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
				}
				else {
					yyattribute(1 - 3)->type = it->second->type;
					yyattribute(1 - 3)->child[0]->type = it->second->type;
					// ID/连续赋值，右部出错
					if(yyattribute(3 - 3)->error != Normal) {
						(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
					}
					// 类型不一致
					else if(yyattribute(1 - 3)->type != yyattribute(3 - 3)->type) {
						(*(YYSTYPE YYFAR*)yyvalptr)->error = getDiffError(yyattribute(1 - 3)->type, yyattribute(3 - 3)->type);
					}
					else {
						(*(YYSTYPE YYFAR*)yyvalptr)->type = yyattribute(1 - 3)->type;
					}
					
					if(isDebug)
						cout << yyattribute(1 - 3)->attr.name << ':' << yyattribute(1 - 3)->type << endl;
				}
                
                temp = temp - 2;
                (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
				tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
		
#line 754 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 358 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(DeclK);
                    (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 2);
                    (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(2 - 2); 
                    
                    // $$->type = $1->type;
                    
                    Node* idNode = yyattribute(2 - 2);
                    while(idNode) {
						string idName;
						if(idNode->kind.expKind == IdArrK) {
							idName = idNode->child[0]->attr.name;
						}
						else idName = idNode->attr.name;
						idNode->type = yyattribute(1 - 2)->type;
						// 重定义
						if((it = idTable.find(idName)) != idTable.end()) {
							idNode->error = ReDef;
							idNode = idNode->sibling;
							(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
							continue;
						}
						// 首次定义
						variable* newVar = new variable;
						newVar->name = idName;
						newVar->type = yyattribute(1 - 2)->type;
						idTable.insert({idName, newVar});
						if(isDebug)
							cout << idNode->attr.name << ':' << idNode->type << endl;
						idNode = idNode->sibling;
                    } 
                
#line 798 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 392 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr) = newTypeNode(Void);
                
#line 813 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 395 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr) = newTypeNode(Integer);
                
#line 828 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 398 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr) = newTypeNode(Float);
                
#line 843 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 401 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr) = newTypeNode(Double);
                
#line 858 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 404 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr) = newTypeNode(Char);
                
#line 873 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 409 ".\\myparser.y"

                yyattribute(1 - 3)->sibling = yyattribute(3 - 3);
                (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
            
#line 889 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 413 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 902 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 414 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); temp--;
#line 915 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 415 ".\\myparser.y"

                yyattribute(1 - 3)->sibling = yyattribute(3 - 3);
                (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
                temp--;
            
#line 932 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 422 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(IfK);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 7);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 7);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(7 - 7);
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
				(*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "trueL" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "falseL" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "endL" + to_string(labelNum++);
                
                if(yyattribute(3 - 7)->error != Normal 
				   || yyattribute(5 - 7)->error != Normal
				   || yyattribute(7 - 7)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
				else if(yyattribute(3 - 7)->type != Bool) {
					(*(YYSTYPE YYFAR*)yyvalptr)->error = LogNotBool;
				}
				
				temp = temp - 1;
				//temp = temp < 0 ? 0 : temp;
				
            
#line 967 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 445 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(IfK);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 5);
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[2];
				(*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "trueL" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "endL" + to_string(labelNum++);
                
                if(yyattribute(3 - 5)->error != Normal 
				   || yyattribute(5 - 5)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
				else if(yyattribute(3 - 5)->type != Bool) {
					(*(YYSTYPE YYFAR*)yyvalptr)->error = LogNotBool;
				}
				
				temp = temp - 1;
				//temp = temp < 0 ? 0 : temp;
            
#line 998 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 466 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(WhileK);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 5);
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
                (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "startL" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "trueL" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "endLabel" + to_string(labelNum++);
				
                if(yyattribute(3 - 5)->error != Normal 
				   || yyattribute(5 - 5)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
				else if(yyattribute(3 - 5)->type != Bool) {
					(*(YYSTYPE YYFAR*)yyvalptr)->error = LogNotBool;
				}
				
				temp = temp - 1;
				//temp = temp < 0 ? 0 : temp;
            
#line 1030 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 488 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);   
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 9);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 9);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(7 - 9); 
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(9 - 9);
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
                (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "startLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "trueLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "endLabel" + to_string(labelNum++);
                
                if(yyattribute(3 - 9)->error != Normal 
				   || yyattribute(5 - 9)->error != Normal
				   || yyattribute(7 - 9)->error != Normal
				   || yyattribute(9 - 9)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
				else if(yyattribute(5 - 9)->type != Bool) {
					(*(YYSTYPE YYFAR*)yyvalptr)->error = LogNotBool;
				}
				
				temp = temp - 3;
				//temp = temp < 0 ? 0 : temp;
            
#line 1066 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 512 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);   
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(4 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(6 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(8 - 8); 
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
                (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "startLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "trueLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "endLabel" + to_string(labelNum++);
                
                if(yyattribute(4 - 8)->error != Normal 
				   || yyattribute(6 - 8)->error != Normal
				   || yyattribute(8 - 8)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
				else if(yyattribute(4 - 8)->type != Bool) {
					(*(YYSTYPE YYFAR*)yyvalptr)->error = LogNotBool;
				}
				
				temp = temp - 2;
				//temp = temp < 0 ? 0 : temp;
            
#line 1101 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 535 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);   
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(6 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(8 - 8); 
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
                (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "startLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "trueLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "endLabel" + to_string(labelNum++);
                
                if(yyattribute(3 - 8)->error != Normal 
				   || yyattribute(6 - 8)->error != Normal
				   || yyattribute(8 - 8)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
					
				temp = temp - 2;
				//temp = temp < 0 ? 0 : temp;
            
#line 1133 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 555 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);   
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(8 - 8);
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
                (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "startLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "trueLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "endLabel" + to_string(labelNum++);
				
                if(yyattribute(3 - 8)->error != Normal 
				   || yyattribute(5 - 8)->error != Normal
				   || yyattribute(8 - 8)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
				else if(yyattribute(5 - 8)->type != Bool) {
					(*(YYSTYPE YYFAR*)yyvalptr)->error = LogNotBool;
				}
				
				temp = temp - 2;
				//temp = temp < 0 ? 0 : temp;
            
#line 1168 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 578 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);   
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(5 - 7);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(7 - 7);
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
                (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "startLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "trueLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "endLabel" + to_string(labelNum++);
                
                if(yyattribute(5 - 7)->error != Normal 
				   || yyattribute(7 - 7)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
					
				temp = temp - 1;
				//temp = temp < 0 ? 0 : temp;
            
#line 1199 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 597 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);   
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(4 - 7);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(7 - 7);
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
                (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "startLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "trueLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "endLabel" + to_string(labelNum++);
                
                if(yyattribute(4 - 7)->error != Normal 
				   || yyattribute(7 - 7)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
				else if(yyattribute(4 - 7)->type != Bool) {
					(*(YYSTYPE YYFAR*)yyvalptr)->error = LogNotBool;
				}
				
				temp = temp - 1;
				//temp = temp < 0 ? 0 : temp;
            
#line 1233 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 619 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);   
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 7);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(7 - 7);
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
                (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "startLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "trueLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "endLabel" + to_string(labelNum++);
                
                if(yyattribute(3 - 7)->error != Normal 
				   || yyattribute(7 - 7)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
		
				temp = temp - 1;
				//temp = temp < 0 ? 0 : temp;
            
#line 1264 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 638 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);   
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(6 - 6);
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
                (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "startLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "trueLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "endLabel" + to_string(labelNum++);
                
                if(yyattribute(6 - 6)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
					
            
#line 1292 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 656 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
            (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
            strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, ">");
            (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
            (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
            
            (*(YYSTYPE YYFAR*)yyvalptr)->type = Bool;
            
            if(yyattribute(1 - 3)->error != Normal || yyattribute(3 - 3)->error != Normal) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
            }
            else if(yyattribute(1 - 3)->type != yyattribute(3 - 3)->type) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = getDiffError(yyattribute(1 - 3)->type, yyattribute(3 - 3)->type);
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
			
            if(isDebug) 
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo <<": >" << endl;
        
#line 1328 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 680 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
            (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
            strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, ">=");
            (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
            (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
            
            (*(YYSTYPE YYFAR*)yyvalptr)->type = Bool;
            
            if(yyattribute(1 - 3)->error != Normal || yyattribute(3 - 3)->error != Normal) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
            }
            else if(yyattribute(1 - 3)->type != yyattribute(3 - 3)->type) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = getDiffError(yyattribute(1 - 3)->type, yyattribute(3 - 3)->type);
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
			tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
			
            if(isDebug) 
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo << ": >=" << endl;
        
#line 1364 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 704 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
            (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
            strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, "<");
            (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
            (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
            
            (*(YYSTYPE YYFAR*)yyvalptr)->type = Bool;
            
            if(yyattribute(1 - 3)->error != Normal || yyattribute(3 - 3)->error != Normal) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
            }
            else if(yyattribute(1 - 3)->type != yyattribute(3 - 3)->type) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = getDiffError(yyattribute(1 - 3)->type, yyattribute(3 - 3)->type);
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug) 
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo << ": <" << endl;
        
#line 1399 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 727 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
            (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
            strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, "<=");
            (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
            (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
            
            (*(YYSTYPE YYFAR*)yyvalptr)->type = Bool;
            
            if(yyattribute(1 - 3)->error != Normal || yyattribute(3 - 3)->error != Normal) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
            }
            else if(yyattribute(1 - 3)->type != yyattribute(3 - 3)->type) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = getDiffError(yyattribute(1 - 3)->type, yyattribute(3 - 3)->type);
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug) 
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo << ": <=" << endl;
        
#line 1434 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 750 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
            (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
            strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, "==");
            (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
            (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
            
            (*(YYSTYPE YYFAR*)yyvalptr)->type = Bool;
            if(yyattribute(1 - 3)->error != Normal || yyattribute(3 - 3)->error != Normal) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
            }
            else if(yyattribute(1 - 3)->type != yyattribute(3 - 3)->type) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = getDiffError(yyattribute(1 - 3)->type, yyattribute(3 - 3)->type);
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug)
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo << ": ==" << endl;
        
#line 1468 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 772 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
            (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
            strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, "!=");
            (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
            (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
            
            (*(YYSTYPE YYFAR*)yyvalptr)->type = Bool;
            
            if(yyattribute(1 - 3)->error != Normal || yyattribute(3 - 3)->error != Normal) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
            }
            else if(yyattribute(1 - 3)->type != yyattribute(3 - 3)->type) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = getDiffError(yyattribute(1 - 3)->type, yyattribute(3 - 3)->type);
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug)
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo << ": !=" << endl;
		
#line 1503 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 795 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
            (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
            strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, "&&");
            (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
            (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
            
            (*(YYSTYPE YYFAR*)yyvalptr)->type = Bool;
            if(yyattribute(1 - 3)->error != Normal || yyattribute(3 - 3)->error != Normal) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
            }
            else if(!(yyattribute(1 - 3)->type == Bool && yyattribute(3 - 3)->type == Bool)) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = LogNotBool;
			}
			
			(*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
            (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "trueL" + to_string(labelNum++);
            (*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "trueL" + to_string(labelNum++);
			(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "falseL" + to_string(labelNum++);
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug)
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo << ": &&" << endl;
		
#line 1542 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 822 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
            (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
            strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, "||");
            (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
            (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
            
            (*(YYSTYPE YYFAR*)yyvalptr)->type = Bool;
            if(yyattribute(1 - 3)->error != Normal || yyattribute(3 - 3)->error != Normal) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
            }
            else if(!(yyattribute(1 - 3)->type == Bool && yyattribute(3 - 3)->type == Bool)) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = LogNotBool;
			}
			
			(*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
            (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "falseL" + to_string(labelNum++);
            (*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "falseL" + to_string(labelNum++);
			(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "trueL" + to_string(labelNum++);
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug)
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo << ": ||" << endl;
		
#line 1581 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 849 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
            (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
            strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, "!");
            (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 2);
            
            (*(YYSTYPE YYFAR*)yyvalptr)->type = Bool;
            if(yyattribute(2 - 2)->error != Normal) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
            }
            else if(!(yyattribute(2 - 2)->type == Bool)) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = LogNotBool;
			}
			
			(*(YYSTYPE YYFAR*)yyvalptr)->label = new string[2];
            (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "trueL" + to_string(labelNum++);
			(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "falseL" + to_string(labelNum++);
			
			temp = temp - 1 ;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            
            if(isDebug)
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo << ": !" << endl;
		
#line 1619 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 877 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			(*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
			tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
		
#line 1636 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 882 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
            (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
            strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, "+");
            (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
            (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
            
            if(yyattribute(1 - 3)->error != Normal || yyattribute(3 - 3)->error != Normal) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
            }
            else if(yyattribute(1 - 3)->type != yyattribute(3 - 3)->type) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = getDiffError(yyattribute(1 - 3)->type, yyattribute(3 - 3)->type);
			}
			else {
				(*(YYSTYPE YYFAR*)yyvalptr)->type = yyattribute(1 - 3)->type;
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug) 
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo << ": +" << endl;
        
#line 1672 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 906 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
            (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
            strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, "-");
            (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
            (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
            
            if(yyattribute(1 - 3)->error != Normal || yyattribute(3 - 3)->error != Normal) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
            }
            else if(yyattribute(1 - 3)->type != yyattribute(3 - 3)->type) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = getDiffError(yyattribute(1 - 3)->type, yyattribute(3 - 3)->type);
			}
			else {
				(*(YYSTYPE YYFAR*)yyvalptr)->type = yyattribute(1 - 3)->type;
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug) 
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo << ": -" << endl;
        
#line 1708 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 930 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
            (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
            strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, "*");
            (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
            (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
            
            if(yyattribute(1 - 3)->error != Normal || yyattribute(3 - 3)->error != Normal) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
            }
            else if(yyattribute(1 - 3)->type != yyattribute(3 - 3)->type) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = getDiffError(yyattribute(1 - 3)->type, yyattribute(3 - 3)->type);
			}
			else {
				(*(YYSTYPE YYFAR*)yyvalptr)->type = yyattribute(1 - 3)->type;
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug) 
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo << ": *" << endl;
        
#line 1744 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 954 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
            (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
            strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, "/");
            (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
            (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
            
            if(yyattribute(1 - 3)->error != Normal || yyattribute(3 - 3)->error != Normal) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
            }
            else if(yyattribute(1 - 3)->type != yyattribute(3 - 3)->type) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = getDiffError(yyattribute(1 - 3)->type, yyattribute(3 - 3)->type);
			}
			else {
				(*(YYSTYPE YYFAR*)yyvalptr)->type = yyattribute(1 - 3)->type;
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug) 
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo << ": /" << endl;
        
#line 1780 "myparser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 978 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
            (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
            strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, "%");
            (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
            (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
            
            if(yyattribute(1 - 3)->error != Normal || yyattribute(3 - 3)->error != Normal) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
            }
            else if(yyattribute(1 - 3)->type != yyattribute(3 - 3)->type) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = getDiffError(yyattribute(1 - 3)->type, yyattribute(3 - 3)->type);
			}
			else {
				(*(YYSTYPE YYFAR*)yyvalptr)->type = yyattribute(1 - 3)->type;
			}
			
			temp = temp - 2;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug) 
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo << ": %" << endl;
		
#line 1816 "myparser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1002 ".\\myparser.y"

		        (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
				strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, "&");
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
				
				if(yyattribute(1 - 3)->error != Normal || yyattribute(3 - 3)->error != Normal) {
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
				}
				else if(yyattribute(1 - 3)->type != yyattribute(3 - 3)->type) {
					(*(YYSTYPE YYFAR*)yyvalptr)->error = getDiffError(yyattribute(1 - 3)->type, yyattribute(3 - 3)->type);
				}
				else {
					(*(YYSTYPE YYFAR*)yyvalptr)->type = yyattribute(1 - 3)->type;
				}
				
				temp = temp - 2 ;
				//temp = temp < 0 ? 0 : temp;
				(*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
				tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
			
#line 1850 "myparser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1024 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
				(*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
				strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, "|");
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
				(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
				
				if(yyattribute(1 - 3)->error != Normal || yyattribute(3 - 3)->error != Normal) {
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
				}
				else if(yyattribute(1 - 3)->type != yyattribute(3 - 3)->type) {
					(*(YYSTYPE YYFAR*)yyvalptr)->error = getDiffError(yyattribute(1 - 3)->type, yyattribute(3 - 3)->type);
				}
				else {
					(*(YYSTYPE YYFAR*)yyvalptr)->type = yyattribute(1 - 3)->type;
				}
				
				temp = temp - 2 ;
				//temp = temp < 0 ? 0 : temp;
				(*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
				tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
		
#line 1884 "myparser.cpp"
			}
		}
		break;
	case 65:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1046 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
        
#line 1899 "myparser.cpp"
			}
		}
		break;
	case 66:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1049 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
            
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
        
#line 1917 "myparser.cpp"
			}
		}
		break;
	case 67:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1055 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
			(*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
			tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
		
#line 1935 "myparser.cpp"
			}
		}
		break;
	case 68:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1061 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
            if((it = idTable.find(yyattribute(1 - 1)->attr.name)) == idTable.end())
				(*(YYSTYPE YYFAR*)yyvalptr)->error = NotDef;
			else
				(*(YYSTYPE YYFAR*)yyvalptr)->type = it->second->type;
				
			(*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
			tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
        
#line 1957 "myparser.cpp"
			}
		}
		break;
	case 69:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1071 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			if((it = idTable.find(yyattribute(1 - 1)->child[0]->attr.name)) == idTable.end())
				(*(YYSTYPE YYFAR*)yyvalptr)->error = NotDef;
			else {
				(*(YYSTYPE YYFAR*)yyvalptr)->type = it->second->type;
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]->type = (*(YYSTYPE YYFAR*)yyvalptr)->type;
			}
		
#line 1978 "myparser.cpp"
			}
		}
		break;
	case 70:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1080 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 1993 "myparser.cpp"
			}
		}
		break;
	case 71:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1083 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2006 "myparser.cpp"
			}
		}
		break;
	case 72:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1085 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(IdArrK);
			(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 4);
			(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 4);
			
			temp--;
			(*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
			tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
		
#line 2027 "myparser.cpp"
			}
		}
		break;
	case 73:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1096 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2040 "myparser.cpp"
			}
		}
		break;
	case 74:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1097 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2053 "myparser.cpp"
			}
		}
		break;
	case 75:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1098 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2066 "myparser.cpp"
			}
		}
		break;
	case 76:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1099 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2079 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "error", 256 },
		{ "MAIN", 257 },
		{ "RETURN", 258 },
		{ "INT", 261 },
		{ "DOUBLE", 262 },
		{ "FLOAT", 263 },
		{ "CHAR", 264 },
		{ "VOID", 265 },
		{ "WHILE", 266 },
		{ "FOR", 268 },
		{ "LBRACE", 269 },
		{ "RBRACE", 270 },
		{ "IF", 271 },
		{ "ELSE", 272 },
		{ "ASSIGN", 273 },
		{ "AND_BIT", 274 },
		{ "AND", 275 },
		{ "OR_BIT", 276 },
		{ "OR", 277 },
		{ "BNE", 278 },
		{ "LNE", 279 },
		{ "BE", 280 },
		{ "LE", 281 },
		{ "EQUAL", 282 },
		{ "NOT_EQ", 283 },
		{ "NOT", 284 },
		{ "LINEEND", 285 },
		{ "LPAREN", 286 },
		{ "RPAREN", 287 },
		{ "COMMA", 288 },
		{ "LFPA", 289 },
		{ "RFPA", 290 },
		{ "ADD", 291 },
		{ "SUB", 292 },
		{ "MUL", 293 },
		{ "DIV", 294 },
		{ "MOD", 295 },
		{ "ID", 296 },
		{ "INT_NUMBER", 297 },
		{ "FLOAT_NUMBER", 298 },
		{ "OCT_NUMBER", 299 },
		{ "HEX_NUMBER", 300 },
		{ "CHARACTER", 301 },
		{ "INPUT", 302 },
		{ "OUTPUT", 303 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: program",
		"program: MAIN LPAREN RPAREN LBRACE stmts RBRACE",
		"stmts: stmts stmt",
		"stmts: stmt",
		"stmt: function",
		"stmt: RETURN expr LINEEND",
		"stmt: callfun LINEEND",
		"stmt: assign_stmt LINEEND",
		"stmt: declare_stmt LINEEND",
		"stmt: if_stmt",
		"stmt: while_stmt",
		"stmt: for_stmt",
		"stmt: LBRACE stmts RBRACE",
		"stmt: INPUT LPAREN ID RPAREN LINEEND",
		"stmt: INPUT LPAREN ArrID RPAREN LINEEND",
		"stmt: OUTPUT LPAREN expr RPAREN LINEEND",
		"stmt: LINEEND",
		"function: paramDecl LPAREN paramList RPAREN LBRACE stmts RBRACE",
		"paramList: paramDecl COMMA paramList",
		"paramList: paramDecl",
		"paramList:",
		"paramDecl: var_type ID",
		"callfun: ID LPAREN inParamList RPAREN",
		"inParamList: expr COMMA inParamList",
		"inParamList: expr",
		"inParamList:",
		"assign_stmt: ID ASSIGN expr",
		"assign_stmt: ArrID ASSIGN expr",
		"declare_stmt: var_type idList",
		"var_type: VOID",
		"var_type: INT",
		"var_type: FLOAT",
		"var_type: DOUBLE",
		"var_type: CHAR",
		"idList: ID COMMA idList",
		"idList: ID",
		"idList: ArrID",
		"idList: ArrID COMMA idList",
		"if_stmt: IF LPAREN expr RPAREN stmt ELSE stmt",
		"if_stmt: IF LPAREN expr RPAREN stmt",
		"while_stmt: WHILE LPAREN expr RPAREN stmt",
		"for_stmt: FOR LPAREN expr LINEEND expr LINEEND expr RPAREN stmt",
		"for_stmt: FOR LPAREN LINEEND expr LINEEND expr RPAREN stmt",
		"for_stmt: FOR LPAREN expr LINEEND LINEEND expr RPAREN stmt",
		"for_stmt: FOR LPAREN expr LINEEND expr LINEEND RPAREN stmt",
		"for_stmt: FOR LPAREN LINEEND LINEEND expr RPAREN stmt",
		"for_stmt: FOR LPAREN LINEEND expr LINEEND RPAREN stmt",
		"for_stmt: FOR LPAREN expr LINEEND LINEEND RPAREN stmt",
		"for_stmt: FOR LPAREN LINEEND LINEEND RPAREN stmt",
		"logical_expr:",
		"logical_expr: expr BNE expr",
		"logical_expr: expr BE expr",
		"logical_expr: expr LNE expr",
		"logical_expr: expr LE expr",
		"logical_expr: expr EQUAL expr",
		"logical_expr: expr NOT_EQ expr",
		"logical_expr: expr AND expr",
		"logical_expr: expr OR expr",
		"logical_expr: NOT expr",
		"expr: callfun",
		"expr: expr ADD expr",
		"expr: expr SUB expr",
		"expr: expr MUL expr",
		"expr: expr DIV expr",
		"expr: expr MOD expr",
		"expr: expr AND_BIT expr",
		"expr: expr OR_BIT expr",
		"expr: LPAREN expr RPAREN",
		"expr: NUMBER",
		"expr: CHARACTER",
		"expr: ID",
		"expr: ArrID",
		"expr: assign_stmt",
		"expr: logical_expr",
		"ArrID: ID LFPA expr RFPA",
		"NUMBER: INT_NUMBER",
		"NUMBER: FLOAT_NUMBER",
		"NUMBER: HEX_NUMBER",
		"NUMBER: OCT_NUMBER",
		"Grammar:"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 6, 0 },
		{ 2, 2, 1 },
		{ 2, 1, 2 },
		{ 3, 1, 3 },
		{ 3, 3, 4 },
		{ 3, 2, 5 },
		{ 3, 2, 6 },
		{ 3, 2, 7 },
		{ 3, 1, 8 },
		{ 3, 1, 9 },
		{ 3, 1, 10 },
		{ 3, 3, 11 },
		{ 3, 5, 12 },
		{ 3, 5, 13 },
		{ 3, 5, 14 },
		{ 3, 1, 15 },
		{ 4, 7, 16 },
		{ 5, 3, 17 },
		{ 5, 1, 18 },
		{ 5, 0, 19 },
		{ 6, 2, 20 },
		{ 7, 4, 21 },
		{ 8, 3, 22 },
		{ 8, 1, 23 },
		{ 8, 0, 24 },
		{ 9, 3, 25 },
		{ 9, 3, 26 },
		{ 10, 2, 27 },
		{ 11, 1, 28 },
		{ 11, 1, 29 },
		{ 11, 1, 30 },
		{ 11, 1, 31 },
		{ 11, 1, 32 },
		{ 12, 3, 33 },
		{ 12, 1, 34 },
		{ 12, 1, 35 },
		{ 12, 3, 36 },
		{ 13, 7, 37 },
		{ 13, 5, 38 },
		{ 14, 5, 39 },
		{ 15, 9, 40 },
		{ 15, 8, 41 },
		{ 15, 8, 42 },
		{ 15, 8, 43 },
		{ 15, 7, 44 },
		{ 15, 7, 45 },
		{ 15, 7, 46 },
		{ 15, 6, 47 },
		{ 16, 0, -1 },
		{ 16, 3, 48 },
		{ 16, 3, 49 },
		{ 16, 3, 50 },
		{ 16, 3, 51 },
		{ 16, 3, 52 },
		{ 16, 3, 53 },
		{ 16, 3, 54 },
		{ 16, 3, 55 },
		{ 16, 2, 56 },
		{ 17, 1, 57 },
		{ 17, 3, 58 },
		{ 17, 3, 59 },
		{ 17, 3, 60 },
		{ 17, 3, 61 },
		{ 17, 3, 62 },
		{ 17, 3, 63 },
		{ 17, 3, 64 },
		{ 17, 3, 65 },
		{ 17, 1, 66 },
		{ 17, 1, 67 },
		{ 17, 1, 68 },
		{ 17, 1, 69 },
		{ 17, 1, 70 },
		{ 17, 1, 71 },
		{ 18, 4, 72 },
		{ 19, 1, 73 },
		{ 19, 1, 74 },
		{ 19, 1, 75 },
		{ 19, 1, 76 },
		{ 20, 0, -1 }
	};
	yyreduction = reduction;

	yytokenaction_size = 605;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 162, YYAT_SHIFT, 67 },
		{ 162, YYAT_SHIFT, 68 },
		{ 162, YYAT_SHIFT, 69 },
		{ 162, YYAT_SHIFT, 70 },
		{ 162, YYAT_SHIFT, 71 },
		{ 162, YYAT_SHIFT, 72 },
		{ 162, YYAT_SHIFT, 73 },
		{ 162, YYAT_SHIFT, 74 },
		{ 162, YYAT_SHIFT, 75 },
		{ 162, YYAT_SHIFT, 76 },
		{ 128, YYAT_SHIFT, 95 },
		{ 128, YYAT_SHIFT, 52 },
		{ 60, YYAT_REDUCE, 21 },
		{ 162, YYAT_SHIFT, 168 },
		{ 60, YYAT_SHIFT, 95 },
		{ 60, YYAT_SHIFT, 52 },
		{ 155, YYAT_SHIFT, 164 },
		{ 162, YYAT_SHIFT, 78 },
		{ 162, YYAT_SHIFT, 79 },
		{ 162, YYAT_SHIFT, 80 },
		{ 162, YYAT_SHIFT, 81 },
		{ 162, YYAT_SHIFT, 82 },
		{ 89, YYAT_SHIFT, 67 },
		{ 89, YYAT_SHIFT, 68 },
		{ 89, YYAT_SHIFT, 69 },
		{ 89, YYAT_SHIFT, 70 },
		{ 89, YYAT_SHIFT, 71 },
		{ 89, YYAT_SHIFT, 72 },
		{ 89, YYAT_SHIFT, 73 },
		{ 89, YYAT_SHIFT, 74 },
		{ 89, YYAT_SHIFT, 75 },
		{ 89, YYAT_SHIFT, 76 },
		{ 113, YYAT_SHIFT, 80 },
		{ 113, YYAT_SHIFT, 81 },
		{ 113, YYAT_SHIFT, 82 },
		{ 91, YYAT_ERROR, 0 },
		{ 89, YYAT_SHIFT, 122 },
		{ 152, YYAT_SHIFT, 160 },
		{ 91, YYAT_SHIFT, 124 },
		{ 89, YYAT_SHIFT, 78 },
		{ 89, YYAT_SHIFT, 79 },
		{ 89, YYAT_SHIFT, 80 },
		{ 89, YYAT_SHIFT, 81 },
		{ 89, YYAT_SHIFT, 82 },
		{ 168, YYAT_SHIFT, 6 },
		{ 150, YYAT_SHIFT, 158 },
		{ 140, YYAT_SHIFT, 154 },
		{ 168, YYAT_SHIFT, 7 },
		{ 168, YYAT_SHIFT, 8 },
		{ 168, YYAT_SHIFT, 9 },
		{ 168, YYAT_SHIFT, 10 },
		{ 168, YYAT_SHIFT, 11 },
		{ 168, YYAT_SHIFT, 12 },
		{ 136, YYAT_SHIFT, 148 },
		{ 168, YYAT_SHIFT, 13 },
		{ 168, YYAT_SHIFT, 14 },
		{ 34, YYAT_SHIFT, 50 },
		{ 168, YYAT_SHIFT, 15 },
		{ 97, YYAT_SHIFT, 67 },
		{ 97, YYAT_SHIFT, 68 },
		{ 97, YYAT_SHIFT, 69 },
		{ 97, YYAT_SHIFT, 70 },
		{ 97, YYAT_SHIFT, 71 },
		{ 97, YYAT_SHIFT, 72 },
		{ 97, YYAT_SHIFT, 73 },
		{ 97, YYAT_SHIFT, 74 },
		{ 97, YYAT_SHIFT, 75 },
		{ 97, YYAT_SHIFT, 76 },
		{ 17, YYAT_SHIFT, 50 },
		{ 34, YYAT_SHIFT, 51 },
		{ 133, YYAT_SHIFT, 146 },
		{ 168, YYAT_SHIFT, 16 },
		{ 34, YYAT_SHIFT, 52 },
		{ 127, YYAT_SHIFT, 144 },
		{ 126, YYAT_SHIFT, 143 },
		{ 97, YYAT_SHIFT, 78 },
		{ 97, YYAT_SHIFT, 79 },
		{ 97, YYAT_SHIFT, 80 },
		{ 97, YYAT_SHIFT, 81 },
		{ 97, YYAT_SHIFT, 82 },
		{ 125, YYAT_SHIFT, 142 },
		{ 17, YYAT_SHIFT, 51 },
		{ 168, YYAT_SHIFT, 17 },
		{ 119, YYAT_SHIFT, 137 },
		{ 17, YYAT_SHIFT, 52 },
		{ 112, YYAT_SHIFT, 80 },
		{ 112, YYAT_SHIFT, 81 },
		{ 112, YYAT_SHIFT, 82 },
		{ 168, YYAT_SHIFT, 18 },
		{ 168, YYAT_SHIFT, 19 },
		{ 88, YYAT_SHIFT, 67 },
		{ 88, YYAT_SHIFT, 68 },
		{ 88, YYAT_SHIFT, 69 },
		{ 88, YYAT_SHIFT, 70 },
		{ 88, YYAT_SHIFT, 71 },
		{ 88, YYAT_SHIFT, 72 },
		{ 88, YYAT_SHIFT, 73 },
		{ 88, YYAT_SHIFT, 74 },
		{ 88, YYAT_SHIFT, 75 },
		{ 88, YYAT_SHIFT, 76 },
		{ 132, YYAT_SHIFT, 7 },
		{ 132, YYAT_SHIFT, 8 },
		{ 132, YYAT_SHIFT, 9 },
		{ 132, YYAT_SHIFT, 10 },
		{ 132, YYAT_SHIFT, 11 },
		{ 100, YYAT_SHIFT, 133 },
		{ 99, YYAT_SHIFT, 132 },
		{ 88, YYAT_SHIFT, 78 },
		{ 88, YYAT_SHIFT, 79 },
		{ 88, YYAT_SHIFT, 80 },
		{ 88, YYAT_SHIFT, 81 },
		{ 88, YYAT_SHIFT, 82 },
		{ 105, YYAT_SHIFT, 67 },
		{ 105, YYAT_SHIFT, 68 },
		{ 98, YYAT_SHIFT, 131 },
		{ 96, YYAT_SHIFT, 128 },
		{ 105, YYAT_SHIFT, 71 },
		{ 105, YYAT_SHIFT, 72 },
		{ 105, YYAT_SHIFT, 73 },
		{ 105, YYAT_SHIFT, 74 },
		{ 105, YYAT_SHIFT, 75 },
		{ 105, YYAT_SHIFT, 76 },
		{ 111, YYAT_SHIFT, 78 },
		{ 111, YYAT_SHIFT, 79 },
		{ 111, YYAT_SHIFT, 80 },
		{ 111, YYAT_SHIFT, 81 },
		{ 111, YYAT_SHIFT, 82 },
		{ 94, YYAT_SHIFT, 127 },
		{ 93, YYAT_SHIFT, 126 },
		{ 105, YYAT_SHIFT, 78 },
		{ 105, YYAT_SHIFT, 79 },
		{ 105, YYAT_SHIFT, 80 },
		{ 105, YYAT_SHIFT, 81 },
		{ 105, YYAT_SHIFT, 82 },
		{ 104, YYAT_SHIFT, 67 },
		{ 104, YYAT_SHIFT, 68 },
		{ 90, YYAT_SHIFT, 123 },
		{ 87, YYAT_SHIFT, 121 },
		{ 104, YYAT_SHIFT, 71 },
		{ 104, YYAT_SHIFT, 72 },
		{ 104, YYAT_SHIFT, 73 },
		{ 104, YYAT_SHIFT, 74 },
		{ 104, YYAT_SHIFT, 75 },
		{ 104, YYAT_SHIFT, 76 },
		{ 103, YYAT_SHIFT, 71 },
		{ 103, YYAT_SHIFT, 72 },
		{ 103, YYAT_SHIFT, 73 },
		{ 103, YYAT_SHIFT, 74 },
		{ 103, YYAT_SHIFT, 75 },
		{ 103, YYAT_SHIFT, 76 },
		{ 85, YYAT_SHIFT, 120 },
		{ 104, YYAT_SHIFT, 78 },
		{ 104, YYAT_SHIFT, 79 },
		{ 104, YYAT_SHIFT, 80 },
		{ 104, YYAT_SHIFT, 81 },
		{ 104, YYAT_SHIFT, 82 },
		{ 83, YYAT_SHIFT, 117 },
		{ 103, YYAT_SHIFT, 78 },
		{ 103, YYAT_SHIFT, 79 },
		{ 103, YYAT_SHIFT, 80 },
		{ 103, YYAT_SHIFT, 81 },
		{ 103, YYAT_SHIFT, 82 },
		{ 102, YYAT_SHIFT, 71 },
		{ 102, YYAT_SHIFT, 72 },
		{ 102, YYAT_SHIFT, 73 },
		{ 102, YYAT_SHIFT, 74 },
		{ 102, YYAT_SHIFT, 75 },
		{ 102, YYAT_SHIFT, 76 },
		{ 153, YYAT_SHIFT, 32 },
		{ 66, YYAT_SHIFT, 101 },
		{ 153, YYAT_SHIFT, 33 },
		{ 153, YYAT_SHIFT, 161 },
		{ 139, YYAT_SHIFT, 153 },
		{ 61, YYAT_SHIFT, 96 },
		{ 139, YYAT_ERROR, 0 },
		{ 102, YYAT_SHIFT, 78 },
		{ 102, YYAT_SHIFT, 79 },
		{ 102, YYAT_SHIFT, 80 },
		{ 102, YYAT_SHIFT, 81 },
		{ 102, YYAT_SHIFT, 82 },
		{ 153, YYAT_SHIFT, 34 },
		{ 153, YYAT_SHIFT, 35 },
		{ 153, YYAT_SHIFT, 36 },
		{ 153, YYAT_SHIFT, 37 },
		{ 153, YYAT_SHIFT, 38 },
		{ 153, YYAT_SHIFT, 39 },
		{ 138, YYAT_SHIFT, 32 },
		{ 53, YYAT_SHIFT, 92 },
		{ 138, YYAT_SHIFT, 33 },
		{ 138, YYAT_SHIFT, 151 },
		{ 48, YYAT_SHIFT, 86 },
		{ 92, YYAT_SHIFT, 125 },
		{ 137, YYAT_SHIFT, 32 },
		{ 92, YYAT_SHIFT, 52 },
		{ 137, YYAT_SHIFT, 33 },
		{ 137, YYAT_SHIFT, 149 },
		{ 43, YYAT_SHIFT, 63 },
		{ 42, YYAT_SHIFT, 77 },
		{ 138, YYAT_SHIFT, 34 },
		{ 138, YYAT_SHIFT, 35 },
		{ 138, YYAT_SHIFT, 36 },
		{ 138, YYAT_SHIFT, 37 },
		{ 138, YYAT_SHIFT, 38 },
		{ 138, YYAT_SHIFT, 39 },
		{ 137, YYAT_SHIFT, 34 },
		{ 137, YYAT_SHIFT, 35 },
		{ 137, YYAT_SHIFT, 36 },
		{ 137, YYAT_SHIFT, 37 },
		{ 137, YYAT_SHIFT, 38 },
		{ 137, YYAT_SHIFT, 39 },
		{ 122, YYAT_SHIFT, 32 },
		{ 30, YYAT_SHIFT, 64 },
		{ 122, YYAT_SHIFT, 33 },
		{ 122, YYAT_REDUCE, 25 },
		{ 29, YYAT_SHIFT, 63 },
		{ 28, YYAT_SHIFT, 60 },
		{ 120, YYAT_SHIFT, 32 },
		{ 120, YYAT_SHIFT, 138 },
		{ 120, YYAT_SHIFT, 33 },
		{ 26, YYAT_SHIFT, 59 },
		{ 24, YYAT_SHIFT, 58 },
		{ 23, YYAT_SHIFT, 56 },
		{ 122, YYAT_SHIFT, 34 },
		{ 122, YYAT_SHIFT, 35 },
		{ 122, YYAT_SHIFT, 36 },
		{ 122, YYAT_SHIFT, 37 },
		{ 122, YYAT_SHIFT, 38 },
		{ 122, YYAT_SHIFT, 39 },
		{ 120, YYAT_SHIFT, 34 },
		{ 120, YYAT_SHIFT, 35 },
		{ 120, YYAT_SHIFT, 36 },
		{ 120, YYAT_SHIFT, 37 },
		{ 120, YYAT_SHIFT, 38 },
		{ 120, YYAT_SHIFT, 39 },
		{ 118, YYAT_SHIFT, 32 },
		{ 22, YYAT_SHIFT, 55 },
		{ 118, YYAT_SHIFT, 33 },
		{ 118, YYAT_SHIFT, 135 },
		{ 19, YYAT_SHIFT, 54 },
		{ 18, YYAT_SHIFT, 53 },
		{ 84, YYAT_SHIFT, 32 },
		{ 84, YYAT_SHIFT, 118 },
		{ 84, YYAT_SHIFT, 33 },
		{ 15, YYAT_SHIFT, 49 },
		{ 13, YYAT_SHIFT, 47 },
		{ 12, YYAT_SHIFT, 46 },
		{ 118, YYAT_SHIFT, 34 },
		{ 118, YYAT_SHIFT, 35 },
		{ 118, YYAT_SHIFT, 36 },
		{ 118, YYAT_SHIFT, 37 },
		{ 118, YYAT_SHIFT, 38 },
		{ 118, YYAT_SHIFT, 39 },
		{ 84, YYAT_SHIFT, 34 },
		{ 84, YYAT_SHIFT, 35 },
		{ 84, YYAT_SHIFT, 36 },
		{ 84, YYAT_SHIFT, 37 },
		{ 84, YYAT_SHIFT, 38 },
		{ 84, YYAT_SHIFT, 39 },
		{ 51, YYAT_SHIFT, 32 },
		{ 4, YYAT_SHIFT, 5 },
		{ 51, YYAT_SHIFT, 33 },
		{ 51, YYAT_REDUCE, 25 },
		{ 3, YYAT_SHIFT, 4 },
		{ 2, YYAT_ACCEPT, 0 },
		{ 47, YYAT_SHIFT, 32 },
		{ 47, YYAT_SHIFT, 84 },
		{ 47, YYAT_SHIFT, 33 },
		{ 1, YYAT_SHIFT, 3 },
		{ 0, YYAT_SHIFT, 1 },
		{ -1, YYAT_ERROR, 0 },
		{ 51, YYAT_SHIFT, 34 },
		{ 51, YYAT_SHIFT, 35 },
		{ 51, YYAT_SHIFT, 36 },
		{ 51, YYAT_SHIFT, 37 },
		{ 51, YYAT_SHIFT, 38 },
		{ 51, YYAT_SHIFT, 39 },
		{ 47, YYAT_SHIFT, 34 },
		{ 47, YYAT_SHIFT, 35 },
		{ 47, YYAT_SHIFT, 36 },
		{ 47, YYAT_SHIFT, 37 },
		{ 47, YYAT_SHIFT, 38 },
		{ 47, YYAT_SHIFT, 39 },
		{ 82, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 82, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 81, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 81, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 82, YYAT_SHIFT, 34 },
		{ 82, YYAT_SHIFT, 35 },
		{ 82, YYAT_SHIFT, 36 },
		{ 82, YYAT_SHIFT, 37 },
		{ 82, YYAT_SHIFT, 38 },
		{ 82, YYAT_SHIFT, 39 },
		{ 81, YYAT_SHIFT, 34 },
		{ 81, YYAT_SHIFT, 35 },
		{ 81, YYAT_SHIFT, 36 },
		{ 81, YYAT_SHIFT, 37 },
		{ 81, YYAT_SHIFT, 38 },
		{ 81, YYAT_SHIFT, 39 },
		{ 80, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 80, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 79, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 79, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 80, YYAT_SHIFT, 34 },
		{ 80, YYAT_SHIFT, 35 },
		{ 80, YYAT_SHIFT, 36 },
		{ 80, YYAT_SHIFT, 37 },
		{ 80, YYAT_SHIFT, 38 },
		{ 80, YYAT_SHIFT, 39 },
		{ 79, YYAT_SHIFT, 34 },
		{ 79, YYAT_SHIFT, 35 },
		{ 79, YYAT_SHIFT, 36 },
		{ 79, YYAT_SHIFT, 37 },
		{ 79, YYAT_SHIFT, 38 },
		{ 79, YYAT_SHIFT, 39 },
		{ 78, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 78, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 76, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 76, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 78, YYAT_SHIFT, 34 },
		{ 78, YYAT_SHIFT, 35 },
		{ 78, YYAT_SHIFT, 36 },
		{ 78, YYAT_SHIFT, 37 },
		{ 78, YYAT_SHIFT, 38 },
		{ 78, YYAT_SHIFT, 39 },
		{ 76, YYAT_SHIFT, 34 },
		{ 76, YYAT_SHIFT, 35 },
		{ 76, YYAT_SHIFT, 36 },
		{ 76, YYAT_SHIFT, 37 },
		{ 76, YYAT_SHIFT, 38 },
		{ 76, YYAT_SHIFT, 39 },
		{ 75, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 75, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 74, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 74, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 75, YYAT_SHIFT, 34 },
		{ 75, YYAT_SHIFT, 35 },
		{ 75, YYAT_SHIFT, 36 },
		{ 75, YYAT_SHIFT, 37 },
		{ 75, YYAT_SHIFT, 38 },
		{ 75, YYAT_SHIFT, 39 },
		{ 74, YYAT_SHIFT, 34 },
		{ 74, YYAT_SHIFT, 35 },
		{ 74, YYAT_SHIFT, 36 },
		{ 74, YYAT_SHIFT, 37 },
		{ 74, YYAT_SHIFT, 38 },
		{ 74, YYAT_SHIFT, 39 },
		{ 73, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 73, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 72, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 72, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 73, YYAT_SHIFT, 34 },
		{ 73, YYAT_SHIFT, 35 },
		{ 73, YYAT_SHIFT, 36 },
		{ 73, YYAT_SHIFT, 37 },
		{ 73, YYAT_SHIFT, 38 },
		{ 73, YYAT_SHIFT, 39 },
		{ 72, YYAT_SHIFT, 34 },
		{ 72, YYAT_SHIFT, 35 },
		{ 72, YYAT_SHIFT, 36 },
		{ 72, YYAT_SHIFT, 37 },
		{ 72, YYAT_SHIFT, 38 },
		{ 72, YYAT_SHIFT, 39 },
		{ 71, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 71, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 70, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 70, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 71, YYAT_SHIFT, 34 },
		{ 71, YYAT_SHIFT, 35 },
		{ 71, YYAT_SHIFT, 36 },
		{ 71, YYAT_SHIFT, 37 },
		{ 71, YYAT_SHIFT, 38 },
		{ 71, YYAT_SHIFT, 39 },
		{ 70, YYAT_SHIFT, 34 },
		{ 70, YYAT_SHIFT, 35 },
		{ 70, YYAT_SHIFT, 36 },
		{ 70, YYAT_SHIFT, 37 },
		{ 70, YYAT_SHIFT, 38 },
		{ 70, YYAT_SHIFT, 39 },
		{ 69, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 69, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 68, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 68, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 69, YYAT_SHIFT, 34 },
		{ 69, YYAT_SHIFT, 35 },
		{ 69, YYAT_SHIFT, 36 },
		{ 69, YYAT_SHIFT, 37 },
		{ 69, YYAT_SHIFT, 38 },
		{ 69, YYAT_SHIFT, 39 },
		{ 68, YYAT_SHIFT, 34 },
		{ 68, YYAT_SHIFT, 35 },
		{ 68, YYAT_SHIFT, 36 },
		{ 68, YYAT_SHIFT, 37 },
		{ 68, YYAT_SHIFT, 38 },
		{ 68, YYAT_SHIFT, 39 },
		{ 67, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 67, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 63, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 63, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 67, YYAT_SHIFT, 34 },
		{ 67, YYAT_SHIFT, 35 },
		{ 67, YYAT_SHIFT, 36 },
		{ 67, YYAT_SHIFT, 37 },
		{ 67, YYAT_SHIFT, 38 },
		{ 67, YYAT_SHIFT, 39 },
		{ 63, YYAT_SHIFT, 34 },
		{ 63, YYAT_SHIFT, 35 },
		{ 63, YYAT_SHIFT, 36 },
		{ 63, YYAT_SHIFT, 37 },
		{ 63, YYAT_SHIFT, 38 },
		{ 63, YYAT_SHIFT, 39 },
		{ 54, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 54, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 52, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 52, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 54, YYAT_SHIFT, 34 },
		{ 54, YYAT_SHIFT, 35 },
		{ 54, YYAT_SHIFT, 36 },
		{ 54, YYAT_SHIFT, 37 },
		{ 54, YYAT_SHIFT, 38 },
		{ 54, YYAT_SHIFT, 39 },
		{ 52, YYAT_SHIFT, 34 },
		{ 52, YYAT_SHIFT, 35 },
		{ 52, YYAT_SHIFT, 36 },
		{ 52, YYAT_SHIFT, 37 },
		{ 52, YYAT_SHIFT, 38 },
		{ 52, YYAT_SHIFT, 39 },
		{ 50, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 50, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 49, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 49, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 50, YYAT_SHIFT, 34 },
		{ 50, YYAT_SHIFT, 35 },
		{ 50, YYAT_SHIFT, 36 },
		{ 50, YYAT_SHIFT, 37 },
		{ 50, YYAT_SHIFT, 38 },
		{ 50, YYAT_SHIFT, 39 },
		{ 49, YYAT_SHIFT, 34 },
		{ 49, YYAT_SHIFT, 35 },
		{ 49, YYAT_SHIFT, 36 },
		{ 49, YYAT_SHIFT, 37 },
		{ 49, YYAT_SHIFT, 38 },
		{ 49, YYAT_SHIFT, 39 },
		{ 46, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 46, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 33, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 33, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 46, YYAT_SHIFT, 34 },
		{ 46, YYAT_SHIFT, 35 },
		{ 46, YYAT_SHIFT, 36 },
		{ 46, YYAT_SHIFT, 37 },
		{ 46, YYAT_SHIFT, 38 },
		{ 46, YYAT_SHIFT, 39 },
		{ 33, YYAT_SHIFT, 34 },
		{ 33, YYAT_SHIFT, 35 },
		{ 33, YYAT_SHIFT, 36 },
		{ 33, YYAT_SHIFT, 37 },
		{ 33, YYAT_SHIFT, 38 },
		{ 33, YYAT_SHIFT, 39 },
		{ 32, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 32, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 6, YYAT_SHIFT, 32 },
		{ -1, YYAT_ERROR, 0 },
		{ 6, YYAT_SHIFT, 33 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 32, YYAT_SHIFT, 34 },
		{ 32, YYAT_SHIFT, 35 },
		{ 32, YYAT_SHIFT, 36 },
		{ 32, YYAT_SHIFT, 37 },
		{ 32, YYAT_SHIFT, 38 },
		{ 32, YYAT_SHIFT, 39 },
		{ 6, YYAT_SHIFT, 34 },
		{ 6, YYAT_SHIFT, 35 },
		{ 6, YYAT_SHIFT, 36 },
		{ 6, YYAT_SHIFT, 37 },
		{ 6, YYAT_SHIFT, 38 },
		{ 6, YYAT_SHIFT, 39 },
		{ 110, YYAT_SHIFT, 78 },
		{ 110, YYAT_SHIFT, 79 },
		{ 110, YYAT_SHIFT, 80 },
		{ 110, YYAT_SHIFT, 81 },
		{ 110, YYAT_SHIFT, 82 },
		{ 109, YYAT_SHIFT, 78 },
		{ 109, YYAT_SHIFT, 79 },
		{ 109, YYAT_SHIFT, 80 },
		{ 109, YYAT_SHIFT, 81 },
		{ 109, YYAT_SHIFT, 82 },
		{ 108, YYAT_SHIFT, 78 },
		{ 108, YYAT_SHIFT, 79 },
		{ 108, YYAT_SHIFT, 80 },
		{ 108, YYAT_SHIFT, 81 },
		{ 108, YYAT_SHIFT, 82 },
		{ 107, YYAT_SHIFT, 78 },
		{ 107, YYAT_SHIFT, 79 },
		{ 107, YYAT_SHIFT, 80 },
		{ 107, YYAT_SHIFT, 81 },
		{ 107, YYAT_SHIFT, 82 },
		{ 106, YYAT_SHIFT, 78 },
		{ 106, YYAT_SHIFT, 79 },
		{ 106, YYAT_SHIFT, 80 },
		{ 106, YYAT_SHIFT, 81 },
		{ 106, YYAT_SHIFT, 82 },
		{ 65, YYAT_SHIFT, 78 },
		{ 65, YYAT_SHIFT, 79 },
		{ 65, YYAT_SHIFT, 80 },
		{ 65, YYAT_SHIFT, 81 },
		{ 65, YYAT_SHIFT, 82 },
		{ 64, YYAT_SHIFT, 7 },
		{ 64, YYAT_SHIFT, 8 },
		{ 64, YYAT_SHIFT, 9 },
		{ 64, YYAT_SHIFT, 10 },
		{ 64, YYAT_SHIFT, 11 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 11, 1, YYAT_ERROR, 0 },
		{ -19, 1, YYAT_ERROR, 0 },
		{ 263, 1, YYAT_ERROR, 0 },
		{ -25, 1, YYAT_ERROR, 0 },
		{ -10, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 168 },
		{ 268, 1, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ -41, 1, YYAT_ERROR, 0 },
		{ -42, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 168 },
		{ -43, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ -205, 1, YYAT_ERROR, 0 },
		{ -47, 1, YYAT_ERROR, 0 },
		{ -48, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ -50, 1, YYAT_ERROR, 0 },
		{ -49, 1, YYAT_DEFAULT, 168 },
		{ -65, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ -66, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ -81, 1, YYAT_ERROR, 0 },
		{ -59, 1, YYAT_ERROR, 0 },
		{ -75, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 262, 1, YYAT_REDUCE, 49 },
		{ 244, 1, YYAT_REDUCE, 49 },
		{ -217, 1, YYAT_REDUCE, 70 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 0, 0, YYAT_REDUCE, 69 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ -88, 1, YYAT_DEFAULT, 139 },
		{ -77, 1, YYAT_REDUCE, 71 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ 0, 0, YYAT_REDUCE, 68 },
		{ 238, 1, YYAT_REDUCE, 49 },
		{ -20, 1, YYAT_REDUCE, 49 },
		{ -80, 1, YYAT_DEFAULT, 168 },
		{ 220, 1, YYAT_REDUCE, 49 },
		{ 214, 1, YYAT_REDUCE, 49 },
		{ -26, 1, YYAT_REDUCE, 49 },
		{ 196, 1, YYAT_REDUCE, 49 },
		{ -109, 1, YYAT_ERROR, 0 },
		{ 190, 1, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ -274, 1, YYAT_REDUCE, 35 },
		{ -115, 1, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 172, 1, YYAT_REDUCE, 49 },
		{ 339, 1, YYAT_REDUCE, 20 },
		{ 304, 1, YYAT_REDUCE, 58 },
		{ -118, 1, YYAT_DEFAULT, 162 },
		{ 166, 1, YYAT_REDUCE, 49 },
		{ 148, 1, YYAT_REDUCE, 49 },
		{ 142, 1, YYAT_REDUCE, 49 },
		{ 124, 1, YYAT_REDUCE, 49 },
		{ 118, 1, YYAT_REDUCE, 49 },
		{ 100, 1, YYAT_REDUCE, 49 },
		{ 94, 1, YYAT_REDUCE, 49 },
		{ 76, 1, YYAT_REDUCE, 49 },
		{ 70, 1, YYAT_REDUCE, 49 },
		{ 52, 1, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 46, 1, YYAT_REDUCE, 49 },
		{ 28, 1, YYAT_REDUCE, 49 },
		{ 22, 1, YYAT_REDUCE, 49 },
		{ 4, 1, YYAT_REDUCE, 49 },
		{ -2, 1, YYAT_REDUCE, 49 },
		{ -131, 1, YYAT_DEFAULT, 162 },
		{ -44, 1, YYAT_REDUCE, 49 },
		{ -135, 1, YYAT_DEFAULT, 139 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ -150, 1, YYAT_DEFAULT, 162 },
		{ -184, 1, YYAT_REDUCE, 26 },
		{ -252, 1, YYAT_REDUCE, 24 },
		{ -151, 1, YYAT_ERROR, 0 },
		{ -252, 1, YYAT_DEFAULT, 162 },
		{ -96, 1, YYAT_ERROR, 0 },
		{ -159, 1, YYAT_ERROR, 0 },
		{ -160, 1, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 96 },
		{ -181, 1, YYAT_ERROR, 0 },
		{ -216, 1, YYAT_REDUCE, 27 },
		{ -182, 1, YYAT_ERROR, 0 },
		{ -182, 1, YYAT_REDUCE, 19 },
		{ -182, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 67 },
		{ -116, 1, YYAT_REDUCE, 65 },
		{ -134, 1, YYAT_REDUCE, 56 },
		{ -140, 1, YYAT_REDUCE, 66 },
		{ -162, 1, YYAT_REDUCE, 57 },
		{ 299, 1, YYAT_REDUCE, 50 },
		{ 294, 1, YYAT_REDUCE, 52 },
		{ 289, 1, YYAT_REDUCE, 51 },
		{ 284, 1, YYAT_REDUCE, 53 },
		{ 279, 1, YYAT_REDUCE, 54 },
		{ -169, 1, YYAT_REDUCE, 55 },
		{ -208, 1, YYAT_REDUCE, 60 },
		{ -261, 1, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 0, 0, YYAT_DEFAULT, 168 },
		{ -50, 1, YYAT_REDUCE, 49 },
		{ -202, 1, YYAT_DEFAULT, 139 },
		{ -68, 1, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_DEFAULT, 168 },
		{ -74, 1, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ -205, 1, YYAT_ERROR, 0 },
		{ -211, 1, YYAT_ERROR, 0 },
		{ -212, 1, YYAT_ERROR, 0 },
		{ -278, 1, YYAT_REDUCE, 35 },
		{ 0, 0, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 37 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ -161, 1, YYAT_REDUCE, 20 },
		{ -199, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 40 },
		{ 0, 0, YYAT_DEFAULT, 168 },
		{ -234, 1, YYAT_DEFAULT, 162 },
		{ -92, 1, YYAT_REDUCE, 49 },
		{ -98, 1, YYAT_REDUCE, 49 },
		{ -113, 1, YYAT_DEFAULT, 162 },
		{ -226, 1, YYAT_REDUCE, 39 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_DEFAULT, 168 },
		{ 0, 0, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_DEFAULT, 168 },
		{ 0, 0, YYAT_DEFAULT, 168 },
		{ -242, 1, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 168 },
		{ -250, 1, YYAT_DEFAULT, 162 },
		{ -116, 1, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_DEFAULT, 168 },
		{ -254, 1, YYAT_DEFAULT, 168 },
		{ 0, 0, YYAT_REDUCE, 45 },
		{ 0, 0, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_DEFAULT, 168 },
		{ 0, 0, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_DEFAULT, 168 },
		{ 0, 0, YYAT_DEFAULT, 168 },
		{ -274, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 38 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 42 },
		{ 0, 0, YYAT_REDUCE, 43 },
		{ 0, 0, YYAT_REDUCE, 44 },
		{ -214, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 41 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 75;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 168, 169 },
		{ 168, 25 },
		{ 161, 167 },
		{ 168, 30 },
		{ 168, 22 },
		{ 160, 166 },
		{ 168, 24 },
		{ 168, 26 },
		{ 168, 28 },
		{ 122, 141 },
		{ 168, 27 },
		{ 168, 20 },
		{ 168, 31 },
		{ 96, 130 },
		{ 153, 40 },
		{ 168, 29 },
		{ 153, 41 },
		{ 158, 165 },
		{ 122, 89 },
		{ 96, 61 },
		{ 155, 57 },
		{ 132, 145 },
		{ 132, 99 },
		{ 153, 44 },
		{ 153, 162 },
		{ 153, 43 },
		{ 153, 45 },
		{ 132, 98 },
		{ 146, 155 },
		{ 146, 21 },
		{ 154, 163 },
		{ 151, 159 },
		{ 149, 157 },
		{ 148, 156 },
		{ 138, 152 },
		{ 137, 150 },
		{ 135, 147 },
		{ 121, 140 },
		{ 120, 139 },
		{ 118, 136 },
		{ 117, 134 },
		{ 95, 129 },
		{ 84, 119 },
		{ 82, 116 },
		{ 81, 115 },
		{ 80, 114 },
		{ 79, 113 },
		{ 78, 112 },
		{ 76, 111 },
		{ 75, 110 },
		{ 74, 109 },
		{ 73, 108 },
		{ 72, 107 },
		{ 71, 106 },
		{ 70, 105 },
		{ 69, 104 },
		{ 68, 103 },
		{ 67, 102 },
		{ 64, 100 },
		{ 63, 97 },
		{ 54, 94 },
		{ 53, 93 },
		{ 52, 91 },
		{ 51, 90 },
		{ 50, 88 },
		{ 49, 87 },
		{ 47, 85 },
		{ 46, 83 },
		{ 33, 66 },
		{ 32, 65 },
		{ 28, 62 },
		{ 14, 48 },
		{ 6, 42 },
		{ 5, 23 },
		{ 0, 2 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 73, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 71, 146 },
		{ 55, 153 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 69, 146 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 155 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 58, 96 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 52, 153 },
		{ 51, 153 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 50, 153 },
		{ 49, 153 },
		{ 0, 155 },
		{ 48, 153 },
		{ 47, 153 },
		{ 55, 122 },
		{ 45, 153 },
		{ 43, -1 },
		{ 43, 153 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 42, 153 },
		{ 53, 132 },
		{ 0, -1 },
		{ 0, -1 },
		{ 40, 153 },
		{ 39, 153 },
		{ 38, 153 },
		{ 37, 153 },
		{ 36, 153 },
		{ 35, 153 },
		{ 34, 153 },
		{ 33, 153 },
		{ 32, 153 },
		{ 31, 153 },
		{ 0, -1 },
		{ 30, 153 },
		{ 29, 153 },
		{ 28, 153 },
		{ 27, 153 },
		{ 26, 153 },
		{ 0, -1 },
		{ 25, 153 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 29, 96 },
		{ 1, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 37, 168 },
		{ 22, 153 },
		{ 0, -1 },
		{ 21, 153 },
		{ 34, 168 },
		{ 1, 153 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 16, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 33, 168 },
		{ 0, -1 },
		{ 18, 153 },
		{ 17, 153 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 26, 168 },
		{ 0, -1 },
		{ 30, 168 },
		{ 29, 168 },
		{ 0, -1 },
		{ 28, 168 },
		{ 0, -1 },
		{ 7, -1 },
		{ 27, 168 },
		{ 17, 168 },
		{ 0, -1 },
		{ 0, -1 },
		{ 14, 168 },
		{ 0, -1 },
		{ 2, 168 },
		{ -1, 168 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -3, -1 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 1106 ".\\myparser.y"


/////////////////////////////////////////////////////////////////////////////
// programs section

int main(void)
{
	int n = 1;
	mylexer lexer;
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			lexer.yyin = new ifstream("test1.txt");
			n = parser.yyparse();
		}
	}
	return n;
}


