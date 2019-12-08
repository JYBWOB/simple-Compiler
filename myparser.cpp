/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 60 of your 30 day trial period.
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
* Date: 12/08/19
* Time: 21:36:00
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
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 150 ".\\myparser.y"

            if(isDebug) {
                cout << "assign_stmt" << endl;
            }
            temp--;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = -1;
            (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
        
#line 306 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 158 ".\\myparser.y"

            if(isDebug) {
                cout << "declare_stmt" << endl;
            }
            (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
        
#line 324 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 164 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 337 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 165 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 350 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 166 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 363 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 167 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(CompK);
			(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 3);
			
			if(yyattribute(2 - 3)->error != Normal)
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
		
#line 382 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 174 ".\\myparser.y"

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
		
#line 407 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 187 ".\\myparser.y"

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
	
#line 432 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 200 ".\\myparser.y"

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
			
			if(yyattribute(3 - 5)->kind.expKind == OpK)
					temp--;
			//temp = temp < 0 ? 0 : temp;
		
#line 461 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 217 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(EmptyK);
		
#line 476 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 222 ".\\myparser.y"

                
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
		
#line 525 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 259 ".\\myparser.y"

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
		
#line 573 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 297 ".\\myparser.y"

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
                
#line 617 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 331 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr) = newTypeNode(Void);
                
#line 632 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 334 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr) = newTypeNode(Integer);
                
#line 647 "myparser.cpp"
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
#line 337 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr) = newTypeNode(Float);
                
#line 662 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 340 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr) = newTypeNode(Double);
                
#line 677 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 343 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr) = newTypeNode(Char);
                
#line 692 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 348 ".\\myparser.y"

                yyattribute(1 - 3)->sibling = yyattribute(3 - 3);
                (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
            
#line 708 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 352 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 721 "myparser.cpp"
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
#line 353 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); temp--;
#line 734 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 354 ".\\myparser.y"

                yyattribute(1 - 3)->sibling = yyattribute(3 - 3);
                (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
                temp--;
            
#line 751 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 361 ".\\myparser.y"

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
				
            
#line 786 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 384 ".\\myparser.y"

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
            
#line 817 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 405 ".\\myparser.y"

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
            
#line 849 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 427 ".\\myparser.y"

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
            
#line 885 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 451 ".\\myparser.y"

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
            
#line 920 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 474 ".\\myparser.y"

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
            
#line 952 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 494 ".\\myparser.y"

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
            
#line 987 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 517 ".\\myparser.y"

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
            
#line 1018 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 536 ".\\myparser.y"

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
            
#line 1052 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 558 ".\\myparser.y"

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
            
#line 1083 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 577 ".\\myparser.y"

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
					
            
#line 1111 "myparser.cpp"
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
#line 595 ".\\myparser.y"

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
        
#line 1147 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 619 ".\\myparser.y"

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
        
#line 1183 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 643 ".\\myparser.y"

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
        
#line 1218 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 666 ".\\myparser.y"

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
        
#line 1253 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 689 ".\\myparser.y"

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
        
#line 1287 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 711 ".\\myparser.y"

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
		
#line 1322 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 734 ".\\myparser.y"

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
		
#line 1361 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 761 ".\\myparser.y"

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
		
#line 1400 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 788 ".\\myparser.y"

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
		
#line 1438 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 816 ".\\myparser.y"

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
        
#line 1474 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 840 ".\\myparser.y"

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
        
#line 1510 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 864 ".\\myparser.y"

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
        
#line 1546 "myparser.cpp"
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
#line 888 ".\\myparser.y"

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
        
#line 1582 "myparser.cpp"
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
#line 912 ".\\myparser.y"

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
		
#line 1618 "myparser.cpp"
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
#line 936 ".\\myparser.y"

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
			
#line 1652 "myparser.cpp"
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
#line 958 ".\\myparser.y"

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
		
#line 1686 "myparser.cpp"
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
#line 980 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
        
#line 1701 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 983 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
            
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
        
#line 1719 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 989 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			
			(*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
			tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
		
#line 1737 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 995 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
            if((it = idTable.find(yyattribute(1 - 1)->attr.name)) == idTable.end())
				(*(YYSTYPE YYFAR*)yyvalptr)->error = NotDef;
			else
				(*(YYSTYPE YYFAR*)yyvalptr)->type = it->second->type;
				
			(*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
			tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
        
#line 1759 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1005 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			if((it = idTable.find(yyattribute(1 - 1)->child[0]->attr.name)) == idTable.end())
				(*(YYSTYPE YYFAR*)yyvalptr)->error = NotDef;
			else {
				(*(YYSTYPE YYFAR*)yyvalptr)->type = it->second->type;
				(*(YYSTYPE YYFAR*)yyvalptr)->child[0]->type = (*(YYSTYPE YYFAR*)yyvalptr)->type;
			}
		
#line 1780 "myparser.cpp"
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
#line 1014 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
		
#line 1795 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1017 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1808 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1019 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(IdArrK);
			(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 4);
			(*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 4);
			
			temp--;
			(*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
			tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
		
#line 1829 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1030 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1842 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1031 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1855 "myparser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1032 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1868 "myparser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1033 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1881 "myparser.cpp"
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
		{ 3, 2, 3 },
		{ 3, 2, 4 },
		{ 3, 1, 5 },
		{ 3, 1, 6 },
		{ 3, 1, 7 },
		{ 3, 3, 8 },
		{ 3, 5, 9 },
		{ 3, 5, 10 },
		{ 3, 5, 11 },
		{ 3, 1, 12 },
		{ 4, 3, 13 },
		{ 4, 3, 14 },
		{ 5, 2, 15 },
		{ 6, 1, 16 },
		{ 6, 1, 17 },
		{ 6, 1, 18 },
		{ 6, 1, 19 },
		{ 6, 1, 20 },
		{ 7, 3, 21 },
		{ 7, 1, 22 },
		{ 7, 1, 23 },
		{ 7, 3, 24 },
		{ 8, 7, 25 },
		{ 8, 5, 26 },
		{ 9, 5, 27 },
		{ 10, 9, 28 },
		{ 10, 8, 29 },
		{ 10, 8, 30 },
		{ 10, 8, 31 },
		{ 10, 7, 32 },
		{ 10, 7, 33 },
		{ 10, 7, 34 },
		{ 10, 6, 35 },
		{ 11, 0, -1 },
		{ 11, 3, 36 },
		{ 11, 3, 37 },
		{ 11, 3, 38 },
		{ 11, 3, 39 },
		{ 11, 3, 40 },
		{ 11, 3, 41 },
		{ 11, 3, 42 },
		{ 11, 3, 43 },
		{ 11, 2, 44 },
		{ 12, 3, 45 },
		{ 12, 3, 46 },
		{ 12, 3, 47 },
		{ 12, 3, 48 },
		{ 12, 3, 49 },
		{ 12, 3, 50 },
		{ 12, 3, 51 },
		{ 12, 3, 52 },
		{ 12, 1, 53 },
		{ 12, 1, 54 },
		{ 12, 1, 55 },
		{ 12, 1, 56 },
		{ 12, 1, 57 },
		{ 12, 1, 58 },
		{ 13, 4, 59 },
		{ 14, 1, 60 },
		{ 14, 1, 61 },
		{ 14, 1, 62 },
		{ 14, 1, 63 },
		{ 15, 0, -1 }
	};
	yyreduction = reduction;

	yytokenaction_size = 531;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 137, YYAT_SHIFT, 71 },
		{ 137, YYAT_SHIFT, 72 },
		{ 137, YYAT_SHIFT, 73 },
		{ 137, YYAT_SHIFT, 74 },
		{ 137, YYAT_SHIFT, 75 },
		{ 137, YYAT_SHIFT, 76 },
		{ 137, YYAT_SHIFT, 77 },
		{ 137, YYAT_SHIFT, 78 },
		{ 137, YYAT_SHIFT, 79 },
		{ 137, YYAT_SHIFT, 80 },
		{ 110, YYAT_SHIFT, 84 },
		{ 110, YYAT_SHIFT, 85 },
		{ 110, YYAT_SHIFT, 86 },
		{ 137, YYAT_SHIFT, 142 },
		{ 36, YYAT_SHIFT, 66 },
		{ 36, YYAT_SHIFT, 33 },
		{ 46, YYAT_SHIFT, 32 },
		{ 137, YYAT_SHIFT, 82 },
		{ 137, YYAT_SHIFT, 83 },
		{ 137, YYAT_SHIFT, 84 },
		{ 137, YYAT_SHIFT, 85 },
		{ 137, YYAT_SHIFT, 86 },
		{ 68, YYAT_SHIFT, 71 },
		{ 68, YYAT_SHIFT, 72 },
		{ 68, YYAT_SHIFT, 73 },
		{ 68, YYAT_SHIFT, 74 },
		{ 68, YYAT_SHIFT, 75 },
		{ 68, YYAT_SHIFT, 76 },
		{ 68, YYAT_SHIFT, 77 },
		{ 68, YYAT_SHIFT, 78 },
		{ 68, YYAT_SHIFT, 79 },
		{ 68, YYAT_SHIFT, 80 },
		{ 46, YYAT_SHIFT, 33 },
		{ 107, YYAT_SHIFT, 82 },
		{ 107, YYAT_SHIFT, 83 },
		{ 107, YYAT_SHIFT, 84 },
		{ 107, YYAT_SHIFT, 85 },
		{ 107, YYAT_SHIFT, 86 },
		{ 16, YYAT_SHIFT, 32 },
		{ 68, YYAT_SHIFT, 82 },
		{ 68, YYAT_SHIFT, 83 },
		{ 68, YYAT_SHIFT, 84 },
		{ 68, YYAT_SHIFT, 85 },
		{ 68, YYAT_SHIFT, 86 },
		{ 61, YYAT_SHIFT, 71 },
		{ 61, YYAT_SHIFT, 72 },
		{ 61, YYAT_SHIFT, 73 },
		{ 61, YYAT_SHIFT, 74 },
		{ 61, YYAT_SHIFT, 75 },
		{ 61, YYAT_SHIFT, 76 },
		{ 61, YYAT_SHIFT, 77 },
		{ 61, YYAT_SHIFT, 78 },
		{ 61, YYAT_SHIFT, 79 },
		{ 61, YYAT_SHIFT, 80 },
		{ 16, YYAT_SHIFT, 33 },
		{ 106, YYAT_SHIFT, 82 },
		{ 106, YYAT_SHIFT, 83 },
		{ 106, YYAT_SHIFT, 84 },
		{ 106, YYAT_SHIFT, 85 },
		{ 106, YYAT_SHIFT, 86 },
		{ 128, YYAT_SHIFT, 135 },
		{ 61, YYAT_SHIFT, 82 },
		{ 61, YYAT_SHIFT, 83 },
		{ 61, YYAT_SHIFT, 84 },
		{ 61, YYAT_SHIFT, 85 },
		{ 61, YYAT_SHIFT, 86 },
		{ 142, YYAT_SHIFT, 6 },
		{ 142, YYAT_SHIFT, 7 },
		{ 142, YYAT_SHIFT, 8 },
		{ 142, YYAT_SHIFT, 9 },
		{ 142, YYAT_SHIFT, 10 },
		{ 142, YYAT_SHIFT, 11 },
		{ 62, YYAT_ERROR, 0 },
		{ 142, YYAT_SHIFT, 12 },
		{ 142, YYAT_SHIFT, 13 },
		{ 62, YYAT_SHIFT, 91 },
		{ 142, YYAT_SHIFT, 14 },
		{ 101, YYAT_SHIFT, 71 },
		{ 101, YYAT_SHIFT, 72 },
		{ 126, YYAT_SHIFT, 133 },
		{ 119, YYAT_SHIFT, 130 },
		{ 101, YYAT_SHIFT, 75 },
		{ 101, YYAT_SHIFT, 76 },
		{ 101, YYAT_SHIFT, 77 },
		{ 101, YYAT_SHIFT, 78 },
		{ 101, YYAT_SHIFT, 79 },
		{ 101, YYAT_SHIFT, 80 },
		{ 109, YYAT_SHIFT, 84 },
		{ 109, YYAT_SHIFT, 85 },
		{ 109, YYAT_SHIFT, 86 },
		{ 142, YYAT_SHIFT, 15 },
		{ 118, YYAT_SHIFT, 129 },
		{ 115, YYAT_SHIFT, 124 },
		{ 118, YYAT_ERROR, 0 },
		{ 101, YYAT_SHIFT, 82 },
		{ 101, YYAT_SHIFT, 83 },
		{ 101, YYAT_SHIFT, 84 },
		{ 101, YYAT_SHIFT, 85 },
		{ 101, YYAT_SHIFT, 86 },
		{ 94, YYAT_SHIFT, 122 },
		{ 63, YYAT_SHIFT, 92 },
		{ 142, YYAT_SHIFT, 16 },
		{ 63, YYAT_SHIFT, 33 },
		{ 93, YYAT_SHIFT, 121 },
		{ 92, YYAT_SHIFT, 120 },
		{ 100, YYAT_SHIFT, 71 },
		{ 100, YYAT_SHIFT, 72 },
		{ 142, YYAT_SHIFT, 17 },
		{ 142, YYAT_SHIFT, 18 },
		{ 100, YYAT_SHIFT, 75 },
		{ 100, YYAT_SHIFT, 76 },
		{ 100, YYAT_SHIFT, 77 },
		{ 100, YYAT_SHIFT, 78 },
		{ 100, YYAT_SHIFT, 79 },
		{ 100, YYAT_SHIFT, 80 },
		{ 99, YYAT_SHIFT, 75 },
		{ 99, YYAT_SHIFT, 76 },
		{ 99, YYAT_SHIFT, 77 },
		{ 99, YYAT_SHIFT, 78 },
		{ 99, YYAT_SHIFT, 79 },
		{ 99, YYAT_SHIFT, 80 },
		{ 88, YYAT_SHIFT, 116 },
		{ 100, YYAT_SHIFT, 82 },
		{ 100, YYAT_SHIFT, 83 },
		{ 100, YYAT_SHIFT, 84 },
		{ 100, YYAT_SHIFT, 85 },
		{ 100, YYAT_SHIFT, 86 },
		{ 70, YYAT_SHIFT, 97 },
		{ 99, YYAT_SHIFT, 82 },
		{ 99, YYAT_SHIFT, 83 },
		{ 99, YYAT_SHIFT, 84 },
		{ 99, YYAT_SHIFT, 85 },
		{ 99, YYAT_SHIFT, 86 },
		{ 98, YYAT_SHIFT, 75 },
		{ 98, YYAT_SHIFT, 76 },
		{ 98, YYAT_SHIFT, 77 },
		{ 98, YYAT_SHIFT, 78 },
		{ 98, YYAT_SHIFT, 79 },
		{ 98, YYAT_SHIFT, 80 },
		{ 129, YYAT_SHIFT, 44 },
		{ 67, YYAT_SHIFT, 36 },
		{ 129, YYAT_SHIFT, 45 },
		{ 129, YYAT_SHIFT, 136 },
		{ 65, YYAT_SHIFT, 94 },
		{ 64, YYAT_SHIFT, 93 },
		{ 60, YYAT_SHIFT, 90 },
		{ 98, YYAT_SHIFT, 82 },
		{ 98, YYAT_SHIFT, 83 },
		{ 98, YYAT_SHIFT, 84 },
		{ 98, YYAT_SHIFT, 85 },
		{ 98, YYAT_SHIFT, 86 },
		{ 129, YYAT_SHIFT, 46 },
		{ 129, YYAT_SHIFT, 47 },
		{ 129, YYAT_SHIFT, 48 },
		{ 129, YYAT_SHIFT, 49 },
		{ 129, YYAT_SHIFT, 50 },
		{ 129, YYAT_SHIFT, 51 },
		{ 117, YYAT_SHIFT, 44 },
		{ 58, YYAT_SHIFT, 89 },
		{ 117, YYAT_SHIFT, 45 },
		{ 117, YYAT_SHIFT, 127 },
		{ 55, YYAT_SHIFT, 39 },
		{ 54, YYAT_SHIFT, 81 },
		{ 116, YYAT_SHIFT, 44 },
		{ 38, YYAT_SHIFT, 67 },
		{ 116, YYAT_SHIFT, 45 },
		{ 116, YYAT_SHIFT, 125 },
		{ 34, YYAT_SHIFT, 63 },
		{ 30, YYAT_SHIFT, 59 },
		{ 117, YYAT_SHIFT, 46 },
		{ 117, YYAT_SHIFT, 47 },
		{ 117, YYAT_SHIFT, 48 },
		{ 117, YYAT_SHIFT, 49 },
		{ 117, YYAT_SHIFT, 50 },
		{ 117, YYAT_SHIFT, 51 },
		{ 116, YYAT_SHIFT, 46 },
		{ 116, YYAT_SHIFT, 47 },
		{ 116, YYAT_SHIFT, 48 },
		{ 116, YYAT_SHIFT, 49 },
		{ 116, YYAT_SHIFT, 50 },
		{ 116, YYAT_SHIFT, 51 },
		{ 89, YYAT_SHIFT, 44 },
		{ 89, YYAT_SHIFT, 117 },
		{ 89, YYAT_SHIFT, 45 },
		{ 27, YYAT_SHIFT, 42 },
		{ 24, YYAT_SHIFT, 41 },
		{ 23, YYAT_SHIFT, 40 },
		{ 87, YYAT_SHIFT, 44 },
		{ 22, YYAT_SHIFT, 39 },
		{ 87, YYAT_SHIFT, 45 },
		{ 87, YYAT_SHIFT, 114 },
		{ 18, YYAT_SHIFT, 35 },
		{ 17, YYAT_SHIFT, 34 },
		{ 89, YYAT_SHIFT, 46 },
		{ 89, YYAT_SHIFT, 47 },
		{ 89, YYAT_SHIFT, 48 },
		{ 89, YYAT_SHIFT, 49 },
		{ 89, YYAT_SHIFT, 50 },
		{ 89, YYAT_SHIFT, 51 },
		{ 87, YYAT_SHIFT, 46 },
		{ 87, YYAT_SHIFT, 47 },
		{ 87, YYAT_SHIFT, 48 },
		{ 87, YYAT_SHIFT, 49 },
		{ 87, YYAT_SHIFT, 50 },
		{ 87, YYAT_SHIFT, 51 },
		{ 57, YYAT_SHIFT, 44 },
		{ 57, YYAT_SHIFT, 87 },
		{ 57, YYAT_SHIFT, 45 },
		{ 14, YYAT_SHIFT, 31 },
		{ 12, YYAT_SHIFT, 29 },
		{ 11, YYAT_SHIFT, 28 },
		{ 29, YYAT_SHIFT, 44 },
		{ 29, YYAT_SHIFT, 57 },
		{ 29, YYAT_SHIFT, 45 },
		{ 4, YYAT_SHIFT, 5 },
		{ 3, YYAT_SHIFT, 4 },
		{ 2, YYAT_ACCEPT, 0 },
		{ 57, YYAT_SHIFT, 46 },
		{ 57, YYAT_SHIFT, 47 },
		{ 57, YYAT_SHIFT, 48 },
		{ 57, YYAT_SHIFT, 49 },
		{ 57, YYAT_SHIFT, 50 },
		{ 57, YYAT_SHIFT, 51 },
		{ 29, YYAT_SHIFT, 46 },
		{ 29, YYAT_SHIFT, 47 },
		{ 29, YYAT_SHIFT, 48 },
		{ 29, YYAT_SHIFT, 49 },
		{ 29, YYAT_SHIFT, 50 },
		{ 29, YYAT_SHIFT, 51 },
		{ 86, YYAT_SHIFT, 44 },
		{ 1, YYAT_SHIFT, 3 },
		{ 86, YYAT_SHIFT, 45 },
		{ 0, YYAT_SHIFT, 1 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 85, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 85, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 86, YYAT_SHIFT, 46 },
		{ 86, YYAT_SHIFT, 47 },
		{ 86, YYAT_SHIFT, 48 },
		{ 86, YYAT_SHIFT, 49 },
		{ 86, YYAT_SHIFT, 50 },
		{ 86, YYAT_SHIFT, 51 },
		{ 85, YYAT_SHIFT, 46 },
		{ 85, YYAT_SHIFT, 47 },
		{ 85, YYAT_SHIFT, 48 },
		{ 85, YYAT_SHIFT, 49 },
		{ 85, YYAT_SHIFT, 50 },
		{ 85, YYAT_SHIFT, 51 },
		{ 84, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 84, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 83, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 83, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 84, YYAT_SHIFT, 46 },
		{ 84, YYAT_SHIFT, 47 },
		{ 84, YYAT_SHIFT, 48 },
		{ 84, YYAT_SHIFT, 49 },
		{ 84, YYAT_SHIFT, 50 },
		{ 84, YYAT_SHIFT, 51 },
		{ 83, YYAT_SHIFT, 46 },
		{ 83, YYAT_SHIFT, 47 },
		{ 83, YYAT_SHIFT, 48 },
		{ 83, YYAT_SHIFT, 49 },
		{ 83, YYAT_SHIFT, 50 },
		{ 83, YYAT_SHIFT, 51 },
		{ 82, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 82, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 80, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 80, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 82, YYAT_SHIFT, 46 },
		{ 82, YYAT_SHIFT, 47 },
		{ 82, YYAT_SHIFT, 48 },
		{ 82, YYAT_SHIFT, 49 },
		{ 82, YYAT_SHIFT, 50 },
		{ 82, YYAT_SHIFT, 51 },
		{ 80, YYAT_SHIFT, 46 },
		{ 80, YYAT_SHIFT, 47 },
		{ 80, YYAT_SHIFT, 48 },
		{ 80, YYAT_SHIFT, 49 },
		{ 80, YYAT_SHIFT, 50 },
		{ 80, YYAT_SHIFT, 51 },
		{ 79, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 79, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 78, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 78, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 79, YYAT_SHIFT, 46 },
		{ 79, YYAT_SHIFT, 47 },
		{ 79, YYAT_SHIFT, 48 },
		{ 79, YYAT_SHIFT, 49 },
		{ 79, YYAT_SHIFT, 50 },
		{ 79, YYAT_SHIFT, 51 },
		{ 78, YYAT_SHIFT, 46 },
		{ 78, YYAT_SHIFT, 47 },
		{ 78, YYAT_SHIFT, 48 },
		{ 78, YYAT_SHIFT, 49 },
		{ 78, YYAT_SHIFT, 50 },
		{ 78, YYAT_SHIFT, 51 },
		{ 77, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 77, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 76, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 76, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 77, YYAT_SHIFT, 46 },
		{ 77, YYAT_SHIFT, 47 },
		{ 77, YYAT_SHIFT, 48 },
		{ 77, YYAT_SHIFT, 49 },
		{ 77, YYAT_SHIFT, 50 },
		{ 77, YYAT_SHIFT, 51 },
		{ 76, YYAT_SHIFT, 46 },
		{ 76, YYAT_SHIFT, 47 },
		{ 76, YYAT_SHIFT, 48 },
		{ 76, YYAT_SHIFT, 49 },
		{ 76, YYAT_SHIFT, 50 },
		{ 76, YYAT_SHIFT, 51 },
		{ 75, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 75, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 74, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 74, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 75, YYAT_SHIFT, 46 },
		{ 75, YYAT_SHIFT, 47 },
		{ 75, YYAT_SHIFT, 48 },
		{ 75, YYAT_SHIFT, 49 },
		{ 75, YYAT_SHIFT, 50 },
		{ 75, YYAT_SHIFT, 51 },
		{ 74, YYAT_SHIFT, 46 },
		{ 74, YYAT_SHIFT, 47 },
		{ 74, YYAT_SHIFT, 48 },
		{ 74, YYAT_SHIFT, 49 },
		{ 74, YYAT_SHIFT, 50 },
		{ 74, YYAT_SHIFT, 51 },
		{ 73, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 73, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 72, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 72, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 73, YYAT_SHIFT, 46 },
		{ 73, YYAT_SHIFT, 47 },
		{ 73, YYAT_SHIFT, 48 },
		{ 73, YYAT_SHIFT, 49 },
		{ 73, YYAT_SHIFT, 50 },
		{ 73, YYAT_SHIFT, 51 },
		{ 72, YYAT_SHIFT, 46 },
		{ 72, YYAT_SHIFT, 47 },
		{ 72, YYAT_SHIFT, 48 },
		{ 72, YYAT_SHIFT, 49 },
		{ 72, YYAT_SHIFT, 50 },
		{ 72, YYAT_SHIFT, 51 },
		{ 71, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 71, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 45, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 45, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 71, YYAT_SHIFT, 46 },
		{ 71, YYAT_SHIFT, 47 },
		{ 71, YYAT_SHIFT, 48 },
		{ 71, YYAT_SHIFT, 49 },
		{ 71, YYAT_SHIFT, 50 },
		{ 71, YYAT_SHIFT, 51 },
		{ 45, YYAT_SHIFT, 46 },
		{ 45, YYAT_SHIFT, 47 },
		{ 45, YYAT_SHIFT, 48 },
		{ 45, YYAT_SHIFT, 49 },
		{ 45, YYAT_SHIFT, 50 },
		{ 45, YYAT_SHIFT, 51 },
		{ 44, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 44, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 39, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 39, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 44, YYAT_SHIFT, 46 },
		{ 44, YYAT_SHIFT, 47 },
		{ 44, YYAT_SHIFT, 48 },
		{ 44, YYAT_SHIFT, 49 },
		{ 44, YYAT_SHIFT, 50 },
		{ 44, YYAT_SHIFT, 51 },
		{ 39, YYAT_SHIFT, 46 },
		{ 39, YYAT_SHIFT, 47 },
		{ 39, YYAT_SHIFT, 48 },
		{ 39, YYAT_SHIFT, 49 },
		{ 39, YYAT_SHIFT, 50 },
		{ 39, YYAT_SHIFT, 51 },
		{ 35, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 35, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 33, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 33, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 35, YYAT_SHIFT, 46 },
		{ 35, YYAT_SHIFT, 47 },
		{ 35, YYAT_SHIFT, 48 },
		{ 35, YYAT_SHIFT, 49 },
		{ 35, YYAT_SHIFT, 50 },
		{ 35, YYAT_SHIFT, 51 },
		{ 33, YYAT_SHIFT, 46 },
		{ 33, YYAT_SHIFT, 47 },
		{ 33, YYAT_SHIFT, 48 },
		{ 33, YYAT_SHIFT, 49 },
		{ 33, YYAT_SHIFT, 50 },
		{ 33, YYAT_SHIFT, 51 },
		{ 32, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 32, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 31, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 31, YYAT_SHIFT, 45 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 32, YYAT_SHIFT, 46 },
		{ 32, YYAT_SHIFT, 47 },
		{ 32, YYAT_SHIFT, 48 },
		{ 32, YYAT_SHIFT, 49 },
		{ 32, YYAT_SHIFT, 50 },
		{ 32, YYAT_SHIFT, 51 },
		{ 31, YYAT_SHIFT, 46 },
		{ 31, YYAT_SHIFT, 47 },
		{ 31, YYAT_SHIFT, 48 },
		{ 31, YYAT_SHIFT, 49 },
		{ 31, YYAT_SHIFT, 50 },
		{ 31, YYAT_SHIFT, 51 },
		{ 28, YYAT_SHIFT, 44 },
		{ -1, YYAT_ERROR, 0 },
		{ 28, YYAT_SHIFT, 45 },
		{ 105, YYAT_SHIFT, 82 },
		{ 105, YYAT_SHIFT, 83 },
		{ 105, YYAT_SHIFT, 84 },
		{ 105, YYAT_SHIFT, 85 },
		{ 105, YYAT_SHIFT, 86 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 28, YYAT_SHIFT, 46 },
		{ 28, YYAT_SHIFT, 47 },
		{ 28, YYAT_SHIFT, 48 },
		{ 28, YYAT_SHIFT, 49 },
		{ 28, YYAT_SHIFT, 50 },
		{ 28, YYAT_SHIFT, 51 },
		{ 104, YYAT_SHIFT, 82 },
		{ 104, YYAT_SHIFT, 83 },
		{ 104, YYAT_SHIFT, 84 },
		{ 104, YYAT_SHIFT, 85 },
		{ 104, YYAT_SHIFT, 86 },
		{ 103, YYAT_SHIFT, 82 },
		{ 103, YYAT_SHIFT, 83 },
		{ 103, YYAT_SHIFT, 84 },
		{ 103, YYAT_SHIFT, 85 },
		{ 103, YYAT_SHIFT, 86 },
		{ 102, YYAT_SHIFT, 82 },
		{ 102, YYAT_SHIFT, 83 },
		{ 102, YYAT_SHIFT, 84 },
		{ 102, YYAT_SHIFT, 85 },
		{ 102, YYAT_SHIFT, 86 },
		{ 69, YYAT_SHIFT, 82 },
		{ 69, YYAT_SHIFT, 83 },
		{ 69, YYAT_SHIFT, 84 },
		{ 69, YYAT_SHIFT, 85 },
		{ 69, YYAT_SHIFT, 86 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -25, 1, YYAT_ERROR, 0 },
		{ -56, 1, YYAT_ERROR, 0 },
		{ 216, 1, YYAT_ERROR, 0 },
		{ -72, 1, YYAT_ERROR, 0 },
		{ -55, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ -76, 1, YYAT_ERROR, 0 },
		{ -77, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ -78, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ -235, 1, YYAT_ERROR, 0 },
		{ -94, 1, YYAT_ERROR, 0 },
		{ -95, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 67 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ -85, 1, YYAT_ERROR, 0 },
		{ -99, 1, YYAT_ERROR, 0 },
		{ -100, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ -86, 1, YYAT_DEFAULT, 142 },
		{ 209, 1, YYAT_REDUCE, 37 },
		{ -73, 1, YYAT_REDUCE, 37 },
		{ -102, 1, YYAT_DEFAULT, 142 },
		{ 191, 1, YYAT_REDUCE, 37 },
		{ 185, 1, YYAT_REDUCE, 37 },
		{ 167, 1, YYAT_REDUCE, 37 },
		{ -129, 1, YYAT_ERROR, 0 },
		{ 161, 1, YYAT_REDUCE, 37 },
		{ -274, 1, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ -124, 1, YYAT_REDUCE, 24 },
		{ 143, 1, YYAT_REDUCE, 37 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 137, 1, YYAT_REDUCE, 37 },
		{ 119, 1, YYAT_REDUCE, 37 },
		{ -257, 1, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ 0, 0, YYAT_REDUCE, 55 },
		{ -125, 1, YYAT_DEFAULT, 137 },
		{ -112, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ -79, 1, YYAT_REDUCE, 37 },
		{ -127, 1, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ -142, 1, YYAT_DEFAULT, 137 },
		{ -230, 1, YYAT_REDUCE, 14 },
		{ -215, 1, YYAT_DEFAULT, 137 },
		{ -187, 1, YYAT_ERROR, 0 },
		{ -143, 1, YYAT_ERROR, 0 },
		{ -144, 1, YYAT_DEFAULT, 137 },
		{ 0, 0, YYAT_DEFAULT, 67 },
		{ -156, 1, YYAT_ERROR, 0 },
		{ -252, 1, YYAT_REDUCE, 15 },
		{ 235, 1, YYAT_REDUCE, 46 },
		{ -160, 1, YYAT_DEFAULT, 137 },
		{ 113, 1, YYAT_REDUCE, 37 },
		{ 95, 1, YYAT_REDUCE, 37 },
		{ 89, 1, YYAT_REDUCE, 37 },
		{ 71, 1, YYAT_REDUCE, 37 },
		{ 65, 1, YYAT_REDUCE, 37 },
		{ 47, 1, YYAT_REDUCE, 37 },
		{ 41, 1, YYAT_REDUCE, 37 },
		{ 23, 1, YYAT_REDUCE, 37 },
		{ 17, 1, YYAT_REDUCE, 37 },
		{ -1, 1, YYAT_REDUCE, 37 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ -7, 1, YYAT_REDUCE, 37 },
		{ -25, 1, YYAT_REDUCE, 37 },
		{ -31, 1, YYAT_REDUCE, 37 },
		{ -49, 1, YYAT_REDUCE, 37 },
		{ -55, 1, YYAT_REDUCE, 37 },
		{ -97, 1, YYAT_REDUCE, 37 },
		{ -164, 1, YYAT_DEFAULT, 118 },
		{ -103, 1, YYAT_REDUCE, 37 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_REDUCE, 61 },
		{ -181, 1, YYAT_ERROR, 0 },
		{ -182, 1, YYAT_ERROR, 0 },
		{ -186, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 54 },
		{ -145, 1, YYAT_REDUCE, 52 },
		{ -163, 1, YYAT_REDUCE, 44 },
		{ -169, 1, YYAT_REDUCE, 53 },
		{ -197, 1, YYAT_REDUCE, 45 },
		{ 230, 1, YYAT_REDUCE, 38 },
		{ 225, 1, YYAT_REDUCE, 40 },
		{ 220, 1, YYAT_REDUCE, 39 },
		{ 205, 1, YYAT_REDUCE, 41 },
		{ -236, 1, YYAT_REDUCE, 42 },
		{ -258, 1, YYAT_REDUCE, 43 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ -206, 1, YYAT_REDUCE, 47 },
		{ -283, 1, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_REDUCE, 50 },
		{ 0, 0, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ -195, 1, YYAT_DEFAULT, 137 },
		{ -121, 1, YYAT_REDUCE, 37 },
		{ -127, 1, YYAT_REDUCE, 37 },
		{ -194, 1, YYAT_DEFAULT, 137 },
		{ -192, 1, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ -208, 1, YYAT_DEFAULT, 137 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ -227, 1, YYAT_DEFAULT, 137 },
		{ -145, 1, YYAT_REDUCE, 37 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ -274, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ -195, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 29 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 62;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 142, 143 },
		{ 142, 23 },
		{ 142, 24 },
		{ 142, 19 },
		{ 129, 56 },
		{ 142, 21 },
		{ 142, 25 },
		{ 142, 20 },
		{ 136, 141 },
		{ 67, 96 },
		{ 142, 22 },
		{ 129, 52 },
		{ 129, 137 },
		{ 129, 55 },
		{ 129, 53 },
		{ 67, 38 },
		{ 13, 30 },
		{ 13, 26 },
		{ 135, 140 },
		{ 133, 139 },
		{ 130, 138 },
		{ 127, 134 },
		{ 125, 132 },
		{ 124, 131 },
		{ 117, 128 },
		{ 116, 126 },
		{ 114, 123 },
		{ 90, 119 },
		{ 89, 118 },
		{ 87, 115 },
		{ 86, 113 },
		{ 85, 112 },
		{ 84, 111 },
		{ 83, 110 },
		{ 82, 109 },
		{ 81, 108 },
		{ 80, 107 },
		{ 79, 106 },
		{ 78, 105 },
		{ 77, 104 },
		{ 76, 103 },
		{ 75, 102 },
		{ 74, 101 },
		{ 73, 100 },
		{ 72, 99 },
		{ 71, 98 },
		{ 66, 95 },
		{ 57, 88 },
		{ 45, 70 },
		{ 44, 69 },
		{ 39, 68 },
		{ 35, 65 },
		{ 34, 64 },
		{ 33, 62 },
		{ 32, 61 },
		{ 31, 60 },
		{ 30, 43 },
		{ 29, 58 },
		{ 28, 54 },
		{ 19, 37 },
		{ 5, 27 },
		{ 0, 2 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 60, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 58, 13 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 14, 142 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 52, 67 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 30 },
		{ 46, 129 },
		{ 45, 129 },
		{ 53, 142 },
		{ 43, 129 },
		{ 42, 129 },
		{ 41, 129 },
		{ 39, -1 },
		{ 39, 129 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 38, 129 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 37, 129 },
		{ 36, 129 },
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
		{ 35, 129 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 39, 67 },
		{ 2, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 33, 129 },
		{ 32, 129 },
		{ 31, 129 },
		{ 30, 129 },
		{ 29, 129 },
		{ 28, 129 },
		{ 27, 129 },
		{ 26, 129 },
		{ 25, 129 },
		{ 24, 129 },
		{ 32, 142 },
		{ 22, 129 },
		{ 21, 129 },
		{ 20, 129 },
		{ 19, 129 },
		{ 18, 129 },
		{ 17, 129 },
		{ 0, -1 },
		{ 16, 129 },
		{ 24, 142 },
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
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 23, 142 },
		{ 0, -1 },
		{ 13, 129 },
		{ 12, 129 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 20, 142 },
		{ 19, 142 },
		{ 0, -1 },
		{ 18, 142 },
		{ 0, -1 },
		{ 0, -1 },
		{ 17, 142 },
		{ 0, -1 },
		{ 0, -1 },
		{ 16, 142 },
		{ 0, -1 },
		{ 15, 142 },
		{ 5, 142 },
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
#line 1040 ".\\myparser.y"


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


