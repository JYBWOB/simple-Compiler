/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 58 of your 30 day trial period.
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
* Date: 12/06/19
* Time: 18:52:27
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
                
                genAsmCode(fout, (*(YYSTYPE YYFAR*)yyvalptr));
                system("pause");
            
#line 244 "myparser.cpp"
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
#line 129 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
                Node* temp = yyattribute(1 - 2);
                while(temp->sibling != nullptr) {
                    temp = temp->sibling;
                }
                temp->sibling = yyattribute(2 - 2);
            
#line 264 "myparser.cpp"
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
#line 137 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
            
#line 279 "myparser.cpp"
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
#line 143 ".\\myparser.y"

            if(isDebug) {
                cout << "assign_stmt" << endl;
            }
            (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
        
#line 297 "myparser.cpp"
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
#line 149 ".\\myparser.y"

            if(isDebug) {
                cout << "declare_stmt" << endl;
            }
            (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
        
#line 315 "myparser.cpp"
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
#line 155 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 328 "myparser.cpp"
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
#line 156 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 341 "myparser.cpp"
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
#line 157 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 354 "myparser.cpp"
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
#line 158 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(CompK);
			(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(2 - 3);
			
			if(yyattribute(2 - 3)->error != Normal)
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
		
#line 373 "myparser.cpp"
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
#line 165 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(InputK);
			(*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
			
			// 未声明
			if(it == idTable.end()) {
				yyattribute(3 - 5)->error = NotDef;
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
			}
			else
				yyattribute(3 - 5)->type = it->second->type;
		
#line 397 "myparser.cpp"
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
#line 177 ".\\myparser.y"

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
		
#line 426 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 194 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(EmptyK);
		
#line 441 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 199 ".\\myparser.y"

                
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
				//temp = temp < 0 ? 0 : temp;
		
#line 488 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 236 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(DeclK);
                    (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 2);
                    (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(2 - 2); 
                    
                    // $$->type = $1->type;
                    
                    Node* idNode = yyattribute(2 - 2);
                    while(idNode) {
						string idName = idNode->attr.name;
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
                
#line 528 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 266 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr) = newTypeNode(Void);
                
#line 543 "myparser.cpp"
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
#line 269 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr) = newTypeNode(Integer);
                
#line 558 "myparser.cpp"
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
#line 272 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr) = newTypeNode(Float);
                
#line 573 "myparser.cpp"
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
#line 275 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr) = newTypeNode(Double);
                
#line 588 "myparser.cpp"
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
#line 278 ".\\myparser.y"

                    (*(YYSTYPE YYFAR*)yyvalptr) = newTypeNode(Char);
                
#line 603 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 283 ".\\myparser.y"

                yyattribute(1 - 3)->sibling = yyattribute(3 - 3);
                (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
            
#line 619 "myparser.cpp"
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
#line 287 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 632 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 290 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(IfK);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 7);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 7);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(7 - 7);
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
				(*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "if_startLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "falseLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "if_endLabel" + to_string(labelNum++);
                
                if(yyattribute(3 - 7)->error != Normal 
				   || yyattribute(5 - 7)->error != Normal
				   || yyattribute(7 - 7)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
				else if(yyattribute(3 - 7)->type != Bool) {
					(*(YYSTYPE YYFAR*)yyvalptr)->error = LogNotBool;
				}
				
				temp = temp - 1;
				//temp = temp < 0 ? 0 : temp;
				
            
#line 667 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 313 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(IfK);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 5);
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[2];
				(*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "trueLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "if_endLabel" + to_string(labelNum++);
                
                if(yyattribute(3 - 5)->error != Normal 
				   || yyattribute(5 - 5)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
				else if(yyattribute(3 - 5)->type != Bool) {
					(*(YYSTYPE YYFAR*)yyvalptr)->error = LogNotBool;
				}
				
				temp = temp - 1;
				//temp = temp < 0 ? 0 : temp;
            
#line 698 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 334 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(WhileK);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 5);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 5);
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
                (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "while_startLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "true_label" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "while_endLabel" + to_string(labelNum++);
				
                if(yyattribute(3 - 5)->error != Normal 
				   || yyattribute(5 - 5)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
				else if(yyattribute(3 - 5)->type != Bool) {
					(*(YYSTYPE YYFAR*)yyvalptr)->error = LogNotBool;
				}
				
				temp = temp - 1;
				//temp = temp < 0 ? 0 : temp;
            
#line 730 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 356 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);   
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 9);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 9);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(7 - 9); 
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(9 - 9);
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
                (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "for_startLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "true_label" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "for_endLabel" + to_string(labelNum++);
                
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
            
#line 766 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 380 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);   
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(4 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(6 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(8 - 8); 
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
                (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "for_startLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "true_label" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "for_endLabel" + to_string(labelNum++);
                
                if(yyattribute(4 - 8)->error != Normal 
				   || yyattribute(6 - 8)->error != Normal
				   || yyattribute(8 - 8)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
				else if(yyattribute(4 - 8)->type != Bool) {
					(*(YYSTYPE YYFAR*)yyvalptr)->error = LogNotBool;
				}
				
				temp = temp - 2;
				//temp = temp < 0 ? 0 : temp;
            
#line 801 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 403 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);   
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(6 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(8 - 8); 
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
                (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "for_startLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "true_label" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "for_endLabel" + to_string(labelNum++);
                
                if(yyattribute(3 - 8)->error != Normal 
				   || yyattribute(6 - 8)->error != Normal
				   || yyattribute(8 - 8)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
					
				temp = temp - 2;
				//temp = temp < 0 ? 0 : temp;
            
#line 833 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 423 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);   
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(5 - 8);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(8 - 8);
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
                (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "for_startLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "true_label" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "for_endLabel" + to_string(labelNum++);
                
                if(yyattribute(3 - 8)->error != Normal 
				   || yyattribute(5 - 8)->error != Normal
				   || yyattribute(8 - 8)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
				else if(yyattribute(5 - 8)->type != Bool) {
					(*(YYSTYPE YYFAR*)yyvalptr)->error = LogNotBool;
				}
				
				temp = temp - 2;
				//temp = temp < 0 ? 0 : temp;
            
#line 868 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 446 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);   
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = yyattribute(5 - 7);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(7 - 7);
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
                (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "for_startLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "true_label" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "for_endLabel" + to_string(labelNum++);
                
                if(yyattribute(5 - 7)->error != Normal 
				   || yyattribute(7 - 7)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
					
				temp = temp - 1;
				//temp = temp < 0 ? 0 : temp;
            
#line 899 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 465 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);   
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(4 - 7);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(7 - 7);
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
                (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "for_startLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "true_label" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "for_endLabel" + to_string(labelNum++);
                
                if(yyattribute(4 - 7)->error != Normal 
				   || yyattribute(7 - 7)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
				else if(yyattribute(4 - 7)->type != Bool) {
					(*(YYSTYPE YYFAR*)yyvalptr)->error = LogNotBool;
				}
				
				temp = temp - 1;
				//temp = temp < 0 ? 0 : temp;
            
#line 933 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 487 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);   
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(3 - 7);
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(7 - 7);
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
                (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "for_startLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "true_label" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "for_endLabel" + to_string(labelNum++);
                
                if(yyattribute(3 - 7)->error != Normal 
				   || yyattribute(7 - 7)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
		
				temp = temp - 1;
				//temp = temp < 0 ? 0 : temp;
            
#line 964 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 506 ".\\myparser.y"

                (*(YYSTYPE YYFAR*)yyvalptr) = newStmtNode(ForK);   
                (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[2] = nullptr;
                (*(YYSTYPE YYFAR*)yyvalptr)->child[3] = yyattribute(6 - 6);
                
                (*(YYSTYPE YYFAR*)yyvalptr)->label = new string[3];
                (*(YYSTYPE YYFAR*)yyvalptr)->label[0] = "for_startLabel" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[1] = "true_label" + to_string(labelNum++);
				(*(YYSTYPE YYFAR*)yyvalptr)->label[2] = "for_endLabel" + to_string(labelNum++);
                
                if(yyattribute(6 - 6)->error != Normal)
					(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
					
            
#line 992 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 524 ".\\myparser.y"

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
        
#line 1028 "myparser.cpp"
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
#line 548 ".\\myparser.y"

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
        
#line 1064 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 572 ".\\myparser.y"

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
        
#line 1099 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 595 ".\\myparser.y"

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
        
#line 1134 "myparser.cpp"
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
#line 618 ".\\myparser.y"

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
        
#line 1168 "myparser.cpp"
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
#line 640 ".\\myparser.y"

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
		
#line 1203 "myparser.cpp"
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
#line 663 ".\\myparser.y"

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
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug)
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo << ": &&" << endl;
		
#line 1237 "myparser.cpp"
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
#line 685 ".\\myparser.y"

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
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug)
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo << ": ||" << endl;
		
#line 1271 "myparser.cpp"
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
#line 707 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
            (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
            strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, "&");
            (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
            (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
            
            (*(YYSTYPE YYFAR*)yyvalptr)->type = Bool;
            if(yyattribute(1 - 3)->error != Normal || yyattribute(3 - 3)->error != Normal) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
            }
            else if(!(yyattribute(1 - 3)->type == Bool && yyattribute(3 - 3)->type == Bool)) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = LogNotBool;
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug)
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo << ": &" << endl;
		
#line 1305 "myparser.cpp"
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
#line 729 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = newExpNode(OpK);
            (*(YYSTYPE YYFAR*)yyvalptr)->attr.op = new char[10];
            strcpy((*(YYSTYPE YYFAR*)yyvalptr)->attr.op, "|");
            (*(YYSTYPE YYFAR*)yyvalptr)->child[0] = yyattribute(1 - 3);
            (*(YYSTYPE YYFAR*)yyvalptr)->child[1] = yyattribute(3 - 3);
            
            (*(YYSTYPE YYFAR*)yyvalptr)->type = Bool;
            if(yyattribute(1 - 3)->error != Normal || yyattribute(3 - 3)->error != Normal) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = ChildError;
            }
            else if(!(yyattribute(1 - 3)->type == Bool && yyattribute(3 - 3)->type == Bool)) {
				(*(YYSTYPE YYFAR*)yyvalptr)->error = LogNotBool;
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug)
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo << ": |" << endl;
		
#line 1339 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 751 ".\\myparser.y"

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
			
			temp = temp - 1 ;
			//temp = temp < 0 ? 0 : temp;
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            
            if(isDebug)
                cout << (*(YYSTYPE YYFAR*)yyvalptr)->lineNo << ": !" << endl;
		
#line 1373 "myparser.cpp"
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
#line 775 ".\\myparser.y"

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
        
#line 1409 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 799 ".\\myparser.y"

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
        
#line 1445 "myparser.cpp"
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
#line 823 ".\\myparser.y"

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
        
#line 1481 "myparser.cpp"
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
#line 847 ".\\myparser.y"

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
        
#line 1517 "myparser.cpp"
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
#line 871 ".\\myparser.y"

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
    
		
#line 1554 "myparser.cpp"
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
#line 896 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
        
#line 1569 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 899 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
            (*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
        
#line 1585 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 903 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
			(*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
		
#line 1601 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 907 ".\\myparser.y"

            (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
            if((it = idTable.find(yyattribute(1 - 1)->attr.name)) == idTable.end())
				(*(YYSTYPE YYFAR*)yyvalptr)->error = NotDef;
			else
				(*(YYSTYPE YYFAR*)yyvalptr)->type = it->second->type;
			(*(YYSTYPE YYFAR*)yyvalptr)->tempNum = temp++;
        
#line 1621 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 915 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1634 "myparser.cpp"
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
#line 916 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1647 "myparser.cpp"
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
#line 919 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1660 "myparser.cpp"
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
#line 920 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1673 "myparser.cpp"
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
#line 921 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1686 "myparser.cpp"
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
#line 922 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1699 "myparser.cpp"
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
		{ "ADD", 289 },
		{ "SUB", 290 },
		{ "MUL", 291 },
		{ "DIV", 292 },
		{ "MOD", 293 },
		{ "ID", 294 },
		{ "INT_NUMBER", 295 },
		{ "FLOAT_NUMBER", 296 },
		{ "OCT_NUMBER", 297 },
		{ "HEX_NUMBER", 298 },
		{ "CHARACTER", 299 },
		{ "INPUT", 300 },
		{ "OUTPUT", 301 },
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
		"stmt: OUTPUT LPAREN expr RPAREN LINEEND",
		"stmt: LINEEND",
		"assign_stmt: ID ASSIGN expr",
		"declare_stmt: var_type idList",
		"var_type: VOID",
		"var_type: INT",
		"var_type: FLOAT",
		"var_type: DOUBLE",
		"var_type: CHAR",
		"idList: ID COMMA idList",
		"idList: ID",
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
		"logical_expr: expr AND_BIT expr",
		"logical_expr: expr OR_BIT expr",
		"logical_expr: NOT expr",
		"expr: expr ADD expr",
		"expr: expr SUB expr",
		"expr: expr MUL expr",
		"expr: expr DIV expr",
		"expr: expr MOD expr",
		"expr: LPAREN expr RPAREN",
		"expr: NUMBER",
		"expr: CHARACTER",
		"expr: ID",
		"expr: assign_stmt",
		"expr: logical_expr",
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
		{ 3, 1, 11 },
		{ 4, 3, 12 },
		{ 5, 2, 13 },
		{ 6, 1, 14 },
		{ 6, 1, 15 },
		{ 6, 1, 16 },
		{ 6, 1, 17 },
		{ 6, 1, 18 },
		{ 7, 3, 19 },
		{ 7, 1, 20 },
		{ 8, 7, 21 },
		{ 8, 5, 22 },
		{ 9, 5, 23 },
		{ 10, 9, 24 },
		{ 10, 8, 25 },
		{ 10, 8, 26 },
		{ 10, 8, 27 },
		{ 10, 7, 28 },
		{ 10, 7, 29 },
		{ 10, 7, 30 },
		{ 10, 6, 31 },
		{ 11, 0, -1 },
		{ 11, 3, 32 },
		{ 11, 3, 33 },
		{ 11, 3, 34 },
		{ 11, 3, 35 },
		{ 11, 3, 36 },
		{ 11, 3, 37 },
		{ 11, 3, 38 },
		{ 11, 3, 39 },
		{ 11, 3, 40 },
		{ 11, 3, 41 },
		{ 11, 2, 42 },
		{ 12, 3, 43 },
		{ 12, 3, 44 },
		{ 12, 3, 45 },
		{ 12, 3, 46 },
		{ 12, 3, 47 },
		{ 12, 3, 48 },
		{ 12, 1, 49 },
		{ 12, 1, 50 },
		{ 12, 1, 51 },
		{ 12, 1, 52 },
		{ 12, 1, 53 },
		{ 13, 1, 54 },
		{ 13, 1, 55 },
		{ 13, 1, 56 },
		{ 13, 1, 57 },
		{ 14, 0, -1 }
	};
	yyreduction = reduction;

	yytokenaction_size = 452;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 124, YYAT_SHIFT, 62 },
		{ 124, YYAT_SHIFT, 63 },
		{ 124, YYAT_SHIFT, 64 },
		{ 124, YYAT_SHIFT, 65 },
		{ 124, YYAT_SHIFT, 66 },
		{ 124, YYAT_SHIFT, 67 },
		{ 124, YYAT_SHIFT, 68 },
		{ 124, YYAT_SHIFT, 69 },
		{ 124, YYAT_SHIFT, 70 },
		{ 124, YYAT_SHIFT, 71 },
		{ 98, YYAT_SHIFT, 75 },
		{ 98, YYAT_SHIFT, 76 },
		{ 98, YYAT_SHIFT, 77 },
		{ 124, YYAT_SHIFT, 129 },
		{ 115, YYAT_SHIFT, 122 },
		{ 124, YYAT_SHIFT, 73 },
		{ 124, YYAT_SHIFT, 74 },
		{ 124, YYAT_SHIFT, 75 },
		{ 124, YYAT_SHIFT, 76 },
		{ 124, YYAT_SHIFT, 77 },
		{ 56, YYAT_SHIFT, 62 },
		{ 56, YYAT_SHIFT, 63 },
		{ 56, YYAT_SHIFT, 64 },
		{ 56, YYAT_SHIFT, 65 },
		{ 56, YYAT_SHIFT, 66 },
		{ 56, YYAT_SHIFT, 67 },
		{ 56, YYAT_SHIFT, 68 },
		{ 56, YYAT_SHIFT, 69 },
		{ 56, YYAT_SHIFT, 70 },
		{ 56, YYAT_SHIFT, 71 },
		{ 95, YYAT_SHIFT, 73 },
		{ 95, YYAT_SHIFT, 74 },
		{ 95, YYAT_SHIFT, 75 },
		{ 95, YYAT_SHIFT, 76 },
		{ 95, YYAT_SHIFT, 77 },
		{ 56, YYAT_SHIFT, 73 },
		{ 56, YYAT_SHIFT, 74 },
		{ 56, YYAT_SHIFT, 75 },
		{ 56, YYAT_SHIFT, 76 },
		{ 56, YYAT_SHIFT, 77 },
		{ 129, YYAT_SHIFT, 6 },
		{ 129, YYAT_SHIFT, 7 },
		{ 129, YYAT_SHIFT, 8 },
		{ 129, YYAT_SHIFT, 9 },
		{ 129, YYAT_SHIFT, 10 },
		{ 129, YYAT_SHIFT, 11 },
		{ 113, YYAT_SHIFT, 120 },
		{ 129, YYAT_SHIFT, 12 },
		{ 129, YYAT_SHIFT, 13 },
		{ 107, YYAT_SHIFT, 117 },
		{ 129, YYAT_SHIFT, 14 },
		{ 89, YYAT_SHIFT, 62 },
		{ 89, YYAT_SHIFT, 63 },
		{ 103, YYAT_SHIFT, 111 },
		{ 83, YYAT_SHIFT, 109 },
		{ 89, YYAT_SHIFT, 66 },
		{ 89, YYAT_SHIFT, 67 },
		{ 89, YYAT_SHIFT, 68 },
		{ 89, YYAT_SHIFT, 69 },
		{ 89, YYAT_SHIFT, 70 },
		{ 89, YYAT_SHIFT, 71 },
		{ 97, YYAT_SHIFT, 75 },
		{ 97, YYAT_SHIFT, 76 },
		{ 97, YYAT_SHIFT, 77 },
		{ 129, YYAT_SHIFT, 15 },
		{ 82, YYAT_SHIFT, 108 },
		{ 89, YYAT_SHIFT, 73 },
		{ 89, YYAT_SHIFT, 74 },
		{ 89, YYAT_SHIFT, 75 },
		{ 89, YYAT_SHIFT, 76 },
		{ 89, YYAT_SHIFT, 77 },
		{ 79, YYAT_SHIFT, 104 },
		{ 106, YYAT_SHIFT, 116 },
		{ 129, YYAT_SHIFT, 16 },
		{ 106, YYAT_ERROR, 0 },
		{ 61, YYAT_SHIFT, 85 },
		{ 59, YYAT_SHIFT, 35 },
		{ 88, YYAT_SHIFT, 62 },
		{ 88, YYAT_SHIFT, 63 },
		{ 129, YYAT_SHIFT, 17 },
		{ 129, YYAT_SHIFT, 18 },
		{ 88, YYAT_SHIFT, 66 },
		{ 88, YYAT_SHIFT, 67 },
		{ 88, YYAT_SHIFT, 68 },
		{ 88, YYAT_SHIFT, 69 },
		{ 88, YYAT_SHIFT, 70 },
		{ 88, YYAT_SHIFT, 71 },
		{ 94, YYAT_SHIFT, 73 },
		{ 94, YYAT_SHIFT, 74 },
		{ 94, YYAT_SHIFT, 75 },
		{ 94, YYAT_SHIFT, 76 },
		{ 94, YYAT_SHIFT, 77 },
		{ 88, YYAT_SHIFT, 73 },
		{ 88, YYAT_SHIFT, 74 },
		{ 88, YYAT_SHIFT, 75 },
		{ 88, YYAT_SHIFT, 76 },
		{ 88, YYAT_SHIFT, 77 },
		{ 87, YYAT_SHIFT, 66 },
		{ 87, YYAT_SHIFT, 67 },
		{ 87, YYAT_SHIFT, 68 },
		{ 87, YYAT_SHIFT, 69 },
		{ 87, YYAT_SHIFT, 70 },
		{ 87, YYAT_SHIFT, 71 },
		{ 93, YYAT_SHIFT, 73 },
		{ 93, YYAT_SHIFT, 74 },
		{ 93, YYAT_SHIFT, 75 },
		{ 93, YYAT_SHIFT, 76 },
		{ 93, YYAT_SHIFT, 77 },
		{ 87, YYAT_SHIFT, 73 },
		{ 87, YYAT_SHIFT, 74 },
		{ 87, YYAT_SHIFT, 75 },
		{ 87, YYAT_SHIFT, 76 },
		{ 87, YYAT_SHIFT, 77 },
		{ 86, YYAT_SHIFT, 66 },
		{ 86, YYAT_SHIFT, 67 },
		{ 86, YYAT_SHIFT, 68 },
		{ 86, YYAT_SHIFT, 69 },
		{ 86, YYAT_SHIFT, 70 },
		{ 86, YYAT_SHIFT, 71 },
		{ 116, YYAT_SHIFT, 40 },
		{ 58, YYAT_SHIFT, 83 },
		{ 116, YYAT_SHIFT, 41 },
		{ 116, YYAT_SHIFT, 123 },
		{ 57, YYAT_SHIFT, 82 },
		{ 86, YYAT_SHIFT, 73 },
		{ 86, YYAT_SHIFT, 74 },
		{ 86, YYAT_SHIFT, 75 },
		{ 86, YYAT_SHIFT, 76 },
		{ 86, YYAT_SHIFT, 77 },
		{ 116, YYAT_SHIFT, 42 },
		{ 116, YYAT_SHIFT, 43 },
		{ 116, YYAT_SHIFT, 44 },
		{ 116, YYAT_SHIFT, 45 },
		{ 116, YYAT_SHIFT, 46 },
		{ 116, YYAT_SHIFT, 47 },
		{ 105, YYAT_SHIFT, 40 },
		{ 55, YYAT_SHIFT, 81 },
		{ 105, YYAT_SHIFT, 41 },
		{ 105, YYAT_SHIFT, 114 },
		{ 53, YYAT_SHIFT, 80 },
		{ 48, YYAT_SHIFT, 72 },
		{ 104, YYAT_SHIFT, 40 },
		{ 42, YYAT_SHIFT, 31 },
		{ 104, YYAT_SHIFT, 41 },
		{ 104, YYAT_SHIFT, 112 },
		{ 105, YYAT_SHIFT, 42 },
		{ 105, YYAT_SHIFT, 43 },
		{ 105, YYAT_SHIFT, 44 },
		{ 105, YYAT_SHIFT, 45 },
		{ 105, YYAT_SHIFT, 46 },
		{ 105, YYAT_SHIFT, 47 },
		{ 104, YYAT_SHIFT, 42 },
		{ 104, YYAT_SHIFT, 43 },
		{ 104, YYAT_SHIFT, 44 },
		{ 104, YYAT_SHIFT, 45 },
		{ 104, YYAT_SHIFT, 46 },
		{ 104, YYAT_SHIFT, 47 },
		{ 80, YYAT_SHIFT, 40 },
		{ 80, YYAT_SHIFT, 105 },
		{ 80, YYAT_SHIFT, 41 },
		{ 35, YYAT_SHIFT, 59 },
		{ 32, YYAT_SHIFT, 57 },
		{ 29, YYAT_SHIFT, 54 },
		{ 78, YYAT_SHIFT, 40 },
		{ 23, YYAT_SHIFT, 38 },
		{ 78, YYAT_SHIFT, 41 },
		{ 78, YYAT_SHIFT, 102 },
		{ 80, YYAT_SHIFT, 42 },
		{ 80, YYAT_SHIFT, 43 },
		{ 80, YYAT_SHIFT, 44 },
		{ 80, YYAT_SHIFT, 45 },
		{ 80, YYAT_SHIFT, 46 },
		{ 80, YYAT_SHIFT, 47 },
		{ 78, YYAT_SHIFT, 42 },
		{ 78, YYAT_SHIFT, 43 },
		{ 78, YYAT_SHIFT, 44 },
		{ 78, YYAT_SHIFT, 45 },
		{ 78, YYAT_SHIFT, 46 },
		{ 78, YYAT_SHIFT, 47 },
		{ 52, YYAT_SHIFT, 40 },
		{ 52, YYAT_SHIFT, 78 },
		{ 52, YYAT_SHIFT, 41 },
		{ 22, YYAT_SHIFT, 37 },
		{ 19, YYAT_SHIFT, 34 },
		{ 18, YYAT_SHIFT, 33 },
		{ 28, YYAT_SHIFT, 40 },
		{ 28, YYAT_SHIFT, 52 },
		{ 28, YYAT_SHIFT, 41 },
		{ 17, YYAT_SHIFT, 32 },
		{ 52, YYAT_SHIFT, 42 },
		{ 52, YYAT_SHIFT, 43 },
		{ 52, YYAT_SHIFT, 44 },
		{ 52, YYAT_SHIFT, 45 },
		{ 52, YYAT_SHIFT, 46 },
		{ 52, YYAT_SHIFT, 47 },
		{ 28, YYAT_SHIFT, 42 },
		{ 28, YYAT_SHIFT, 43 },
		{ 28, YYAT_SHIFT, 44 },
		{ 28, YYAT_SHIFT, 45 },
		{ 28, YYAT_SHIFT, 46 },
		{ 28, YYAT_SHIFT, 47 },
		{ 77, YYAT_SHIFT, 40 },
		{ 16, YYAT_SHIFT, 31 },
		{ 77, YYAT_SHIFT, 41 },
		{ 14, YYAT_SHIFT, 30 },
		{ 12, YYAT_SHIFT, 28 },
		{ 11, YYAT_SHIFT, 27 },
		{ 76, YYAT_SHIFT, 40 },
		{ 4, YYAT_SHIFT, 5 },
		{ 76, YYAT_SHIFT, 41 },
		{ 3, YYAT_SHIFT, 4 },
		{ 77, YYAT_SHIFT, 42 },
		{ 77, YYAT_SHIFT, 43 },
		{ 77, YYAT_SHIFT, 44 },
		{ 77, YYAT_SHIFT, 45 },
		{ 77, YYAT_SHIFT, 46 },
		{ 77, YYAT_SHIFT, 47 },
		{ 76, YYAT_SHIFT, 42 },
		{ 76, YYAT_SHIFT, 43 },
		{ 76, YYAT_SHIFT, 44 },
		{ 76, YYAT_SHIFT, 45 },
		{ 76, YYAT_SHIFT, 46 },
		{ 76, YYAT_SHIFT, 47 },
		{ 75, YYAT_SHIFT, 40 },
		{ 2, YYAT_ACCEPT, 0 },
		{ 75, YYAT_SHIFT, 41 },
		{ 1, YYAT_SHIFT, 3 },
		{ 0, YYAT_SHIFT, 1 },
		{ -1, YYAT_ERROR, 0 },
		{ 74, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ 74, YYAT_SHIFT, 41 },
		{ -1, YYAT_ERROR, 0 },
		{ 75, YYAT_SHIFT, 42 },
		{ 75, YYAT_SHIFT, 43 },
		{ 75, YYAT_SHIFT, 44 },
		{ 75, YYAT_SHIFT, 45 },
		{ 75, YYAT_SHIFT, 46 },
		{ 75, YYAT_SHIFT, 47 },
		{ 74, YYAT_SHIFT, 42 },
		{ 74, YYAT_SHIFT, 43 },
		{ 74, YYAT_SHIFT, 44 },
		{ 74, YYAT_SHIFT, 45 },
		{ 74, YYAT_SHIFT, 46 },
		{ 74, YYAT_SHIFT, 47 },
		{ 73, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ 73, YYAT_SHIFT, 41 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 71, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ 71, YYAT_SHIFT, 41 },
		{ -1, YYAT_ERROR, 0 },
		{ 73, YYAT_SHIFT, 42 },
		{ 73, YYAT_SHIFT, 43 },
		{ 73, YYAT_SHIFT, 44 },
		{ 73, YYAT_SHIFT, 45 },
		{ 73, YYAT_SHIFT, 46 },
		{ 73, YYAT_SHIFT, 47 },
		{ 71, YYAT_SHIFT, 42 },
		{ 71, YYAT_SHIFT, 43 },
		{ 71, YYAT_SHIFT, 44 },
		{ 71, YYAT_SHIFT, 45 },
		{ 71, YYAT_SHIFT, 46 },
		{ 71, YYAT_SHIFT, 47 },
		{ 70, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ 70, YYAT_SHIFT, 41 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 69, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ 69, YYAT_SHIFT, 41 },
		{ -1, YYAT_ERROR, 0 },
		{ 70, YYAT_SHIFT, 42 },
		{ 70, YYAT_SHIFT, 43 },
		{ 70, YYAT_SHIFT, 44 },
		{ 70, YYAT_SHIFT, 45 },
		{ 70, YYAT_SHIFT, 46 },
		{ 70, YYAT_SHIFT, 47 },
		{ 69, YYAT_SHIFT, 42 },
		{ 69, YYAT_SHIFT, 43 },
		{ 69, YYAT_SHIFT, 44 },
		{ 69, YYAT_SHIFT, 45 },
		{ 69, YYAT_SHIFT, 46 },
		{ 69, YYAT_SHIFT, 47 },
		{ 68, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ 68, YYAT_SHIFT, 41 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 67, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ 67, YYAT_SHIFT, 41 },
		{ -1, YYAT_ERROR, 0 },
		{ 68, YYAT_SHIFT, 42 },
		{ 68, YYAT_SHIFT, 43 },
		{ 68, YYAT_SHIFT, 44 },
		{ 68, YYAT_SHIFT, 45 },
		{ 68, YYAT_SHIFT, 46 },
		{ 68, YYAT_SHIFT, 47 },
		{ 67, YYAT_SHIFT, 42 },
		{ 67, YYAT_SHIFT, 43 },
		{ 67, YYAT_SHIFT, 44 },
		{ 67, YYAT_SHIFT, 45 },
		{ 67, YYAT_SHIFT, 46 },
		{ 67, YYAT_SHIFT, 47 },
		{ 66, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ 66, YYAT_SHIFT, 41 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 65, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ 65, YYAT_SHIFT, 41 },
		{ -1, YYAT_ERROR, 0 },
		{ 66, YYAT_SHIFT, 42 },
		{ 66, YYAT_SHIFT, 43 },
		{ 66, YYAT_SHIFT, 44 },
		{ 66, YYAT_SHIFT, 45 },
		{ 66, YYAT_SHIFT, 46 },
		{ 66, YYAT_SHIFT, 47 },
		{ 65, YYAT_SHIFT, 42 },
		{ 65, YYAT_SHIFT, 43 },
		{ 65, YYAT_SHIFT, 44 },
		{ 65, YYAT_SHIFT, 45 },
		{ 65, YYAT_SHIFT, 46 },
		{ 65, YYAT_SHIFT, 47 },
		{ 64, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ 64, YYAT_SHIFT, 41 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 63, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ 63, YYAT_SHIFT, 41 },
		{ -1, YYAT_ERROR, 0 },
		{ 64, YYAT_SHIFT, 42 },
		{ 64, YYAT_SHIFT, 43 },
		{ 64, YYAT_SHIFT, 44 },
		{ 64, YYAT_SHIFT, 45 },
		{ 64, YYAT_SHIFT, 46 },
		{ 64, YYAT_SHIFT, 47 },
		{ 63, YYAT_SHIFT, 42 },
		{ 63, YYAT_SHIFT, 43 },
		{ 63, YYAT_SHIFT, 44 },
		{ 63, YYAT_SHIFT, 45 },
		{ 63, YYAT_SHIFT, 46 },
		{ 63, YYAT_SHIFT, 47 },
		{ 62, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ 62, YYAT_SHIFT, 41 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 41, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ 41, YYAT_SHIFT, 41 },
		{ -1, YYAT_ERROR, 0 },
		{ 62, YYAT_SHIFT, 42 },
		{ 62, YYAT_SHIFT, 43 },
		{ 62, YYAT_SHIFT, 44 },
		{ 62, YYAT_SHIFT, 45 },
		{ 62, YYAT_SHIFT, 46 },
		{ 62, YYAT_SHIFT, 47 },
		{ 41, YYAT_SHIFT, 42 },
		{ 41, YYAT_SHIFT, 43 },
		{ 41, YYAT_SHIFT, 44 },
		{ 41, YYAT_SHIFT, 45 },
		{ 41, YYAT_SHIFT, 46 },
		{ 41, YYAT_SHIFT, 47 },
		{ 40, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ 40, YYAT_SHIFT, 41 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 33, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ 33, YYAT_SHIFT, 41 },
		{ -1, YYAT_ERROR, 0 },
		{ 40, YYAT_SHIFT, 42 },
		{ 40, YYAT_SHIFT, 43 },
		{ 40, YYAT_SHIFT, 44 },
		{ 40, YYAT_SHIFT, 45 },
		{ 40, YYAT_SHIFT, 46 },
		{ 40, YYAT_SHIFT, 47 },
		{ 33, YYAT_SHIFT, 42 },
		{ 33, YYAT_SHIFT, 43 },
		{ 33, YYAT_SHIFT, 44 },
		{ 33, YYAT_SHIFT, 45 },
		{ 33, YYAT_SHIFT, 46 },
		{ 33, YYAT_SHIFT, 47 },
		{ 31, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ 31, YYAT_SHIFT, 41 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 30, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ 30, YYAT_SHIFT, 41 },
		{ -1, YYAT_ERROR, 0 },
		{ 31, YYAT_SHIFT, 42 },
		{ 31, YYAT_SHIFT, 43 },
		{ 31, YYAT_SHIFT, 44 },
		{ 31, YYAT_SHIFT, 45 },
		{ 31, YYAT_SHIFT, 46 },
		{ 31, YYAT_SHIFT, 47 },
		{ 30, YYAT_SHIFT, 42 },
		{ 30, YYAT_SHIFT, 43 },
		{ 30, YYAT_SHIFT, 44 },
		{ 30, YYAT_SHIFT, 45 },
		{ 30, YYAT_SHIFT, 46 },
		{ 30, YYAT_SHIFT, 47 },
		{ 27, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ 27, YYAT_SHIFT, 41 },
		{ 92, YYAT_SHIFT, 73 },
		{ 92, YYAT_SHIFT, 74 },
		{ 92, YYAT_SHIFT, 75 },
		{ 92, YYAT_SHIFT, 76 },
		{ 92, YYAT_SHIFT, 77 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 27, YYAT_SHIFT, 42 },
		{ 27, YYAT_SHIFT, 43 },
		{ 27, YYAT_SHIFT, 44 },
		{ 27, YYAT_SHIFT, 45 },
		{ 27, YYAT_SHIFT, 46 },
		{ 27, YYAT_SHIFT, 47 },
		{ 91, YYAT_SHIFT, 73 },
		{ 91, YYAT_SHIFT, 74 },
		{ 91, YYAT_SHIFT, 75 },
		{ 91, YYAT_SHIFT, 76 },
		{ 91, YYAT_SHIFT, 77 },
		{ 90, YYAT_SHIFT, 73 },
		{ 90, YYAT_SHIFT, 74 },
		{ 90, YYAT_SHIFT, 75 },
		{ 90, YYAT_SHIFT, 76 },
		{ 90, YYAT_SHIFT, 77 },
		{ 60, YYAT_SHIFT, 73 },
		{ 60, YYAT_SHIFT, 74 },
		{ 60, YYAT_SHIFT, 75 },
		{ 60, YYAT_SHIFT, 76 },
		{ 60, YYAT_SHIFT, 77 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -30, 1, YYAT_ERROR, 0 },
		{ -60, 1, YYAT_ERROR, 0 },
		{ 224, 1, YYAT_ERROR, 0 },
		{ -77, 1, YYAT_ERROR, 0 },
		{ -61, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 129 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ -80, 1, YYAT_ERROR, 0 },
		{ -81, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 129 },
		{ -82, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ -71, 1, YYAT_ERROR, 0 },
		{ -98, 1, YYAT_ERROR, 0 },
		{ -102, 1, YYAT_ERROR, 0 },
		{ -102, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 59 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ -103, 1, YYAT_ERROR, 0 },
		{ -106, 1, YYAT_DEFAULT, 129 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 137, 1, YYAT_REDUCE, 33 },
		{ -99, 1, YYAT_REDUCE, 33 },
		{ -108, 1, YYAT_DEFAULT, 129 },
		{ 121, 1, YYAT_REDUCE, 33 },
		{ 115, 1, YYAT_REDUCE, 33 },
		{ -133, 1, YYAT_ERROR, 0 },
		{ 99, 1, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ -128, 1, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 93, 1, YYAT_REDUCE, 33 },
		{ 77, 1, YYAT_REDUCE, 33 },
		{ -131, 1, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 52 },
		{ -147, 1, YYAT_DEFAULT, 124 },
		{ 0, 0, YYAT_REDUCE, 54 },
		{ 0, 0, YYAT_REDUCE, 55 },
		{ 0, 0, YYAT_REDUCE, 51 },
		{ -105, 1, YYAT_REDUCE, 33 },
		{ -146, 1, YYAT_DEFAULT, 106 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ -151, 1, YYAT_DEFAULT, 124 },
		{ -254, 1, YYAT_REDUCE, 13 },
		{ -164, 1, YYAT_ERROR, 0 },
		{ -167, 1, YYAT_DEFAULT, 124 },
		{ -218, 1, YYAT_ERROR, 0 },
		{ 158, 1, YYAT_REDUCE, 44 },
		{ -212, 1, YYAT_DEFAULT, 124 },
		{ 71, 1, YYAT_REDUCE, 33 },
		{ 55, 1, YYAT_REDUCE, 33 },
		{ 49, 1, YYAT_REDUCE, 33 },
		{ 33, 1, YYAT_REDUCE, 33 },
		{ 27, 1, YYAT_REDUCE, 33 },
		{ 11, 1, YYAT_REDUCE, 33 },
		{ 5, 1, YYAT_REDUCE, 33 },
		{ -11, 1, YYAT_REDUCE, 33 },
		{ -17, 1, YYAT_REDUCE, 33 },
		{ -33, 1, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_DEFAULT, 129 },
		{ -39, 1, YYAT_REDUCE, 33 },
		{ -55, 1, YYAT_REDUCE, 33 },
		{ -61, 1, YYAT_REDUCE, 33 },
		{ -77, 1, YYAT_REDUCE, 33 },
		{ -83, 1, YYAT_REDUCE, 33 },
		{ -121, 1, YYAT_REDUCE, 33 },
		{ -214, 1, YYAT_DEFAULT, 106 },
		{ -127, 1, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_DEFAULT, 129 },
		{ -220, 1, YYAT_ERROR, 0 },
		{ -231, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 50 },
		{ -165, 1, YYAT_REDUCE, 42 },
		{ -181, 1, YYAT_REDUCE, 40 },
		{ -197, 1, YYAT_REDUCE, 43 },
		{ -223, 1, YYAT_REDUCE, 41 },
		{ 153, 1, YYAT_REDUCE, 34 },
		{ 148, 1, YYAT_REDUCE, 36 },
		{ 135, 1, YYAT_REDUCE, 35 },
		{ -186, 1, YYAT_REDUCE, 37 },
		{ -202, 1, YYAT_REDUCE, 38 },
		{ -259, 1, YYAT_REDUCE, 39 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ -230, 1, YYAT_REDUCE, 45 },
		{ -281, 1, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_DEFAULT, 129 },
		{ -234, 1, YYAT_DEFAULT, 124 },
		{ -143, 1, YYAT_REDUCE, 33 },
		{ -149, 1, YYAT_REDUCE, 33 },
		{ -213, 1, YYAT_DEFAULT, 124 },
		{ -223, 1, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_DEFAULT, 129 },
		{ 0, 0, YYAT_DEFAULT, 129 },
		{ -241, 1, YYAT_DEFAULT, 124 },
		{ 0, 0, YYAT_DEFAULT, 129 },
		{ -273, 1, YYAT_DEFAULT, 124 },
		{ -165, 1, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_DEFAULT, 129 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_DEFAULT, 129 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_DEFAULT, 129 },
		{ 0, 0, YYAT_DEFAULT, 129 },
		{ -274, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ -221, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 25 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 55;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 129, 130 },
		{ 129, 22 },
		{ 129, 19 },
		{ 129, 20 },
		{ 116, 49 },
		{ 129, 24 },
		{ 129, 26 },
		{ 129, 25 },
		{ 13, 29 },
		{ 13, 21 },
		{ 123, 128 },
		{ 116, 50 },
		{ 116, 124 },
		{ 116, 51 },
		{ 122, 127 },
		{ 120, 126 },
		{ 117, 125 },
		{ 114, 121 },
		{ 112, 119 },
		{ 111, 118 },
		{ 105, 115 },
		{ 104, 113 },
		{ 102, 110 },
		{ 81, 107 },
		{ 80, 106 },
		{ 78, 103 },
		{ 77, 101 },
		{ 76, 100 },
		{ 75, 99 },
		{ 74, 98 },
		{ 73, 97 },
		{ 72, 96 },
		{ 71, 95 },
		{ 70, 94 },
		{ 69, 93 },
		{ 68, 92 },
		{ 67, 91 },
		{ 66, 90 },
		{ 65, 89 },
		{ 64, 88 },
		{ 63, 87 },
		{ 62, 86 },
		{ 59, 84 },
		{ 52, 79 },
		{ 41, 61 },
		{ 40, 60 },
		{ 33, 58 },
		{ 31, 56 },
		{ 30, 55 },
		{ 29, 39 },
		{ 28, 53 },
		{ 27, 48 },
		{ 20, 36 },
		{ 5, 23 },
		{ 0, 2 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 53, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 51, 13 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 6, 129 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 45, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 29 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 39, 116 },
		{ 38, 116 },
		{ 46, 129 },
		{ 36, 116 },
		{ 35, 116 },
		{ 0, -1 },
		{ 34, 116 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 33, 116 },
		{ 32, 116 },
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
		{ 31, 116 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 35, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 29, 116 },
		{ 28, 116 },
		{ 27, 116 },
		{ 26, 116 },
		{ 25, 116 },
		{ 24, 116 },
		{ 23, 116 },
		{ 22, 116 },
		{ 21, 116 },
		{ 20, 116 },
		{ 28, 129 },
		{ 18, 116 },
		{ 17, 116 },
		{ 16, 116 },
		{ 15, 116 },
		{ 14, 116 },
		{ 13, 116 },
		{ 0, -1 },
		{ 12, 116 },
		{ 20, 129 },
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
		{ 19, 129 },
		{ 0, -1 },
		{ 9, 116 },
		{ 8, 116 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 16, 129 },
		{ 15, 129 },
		{ 0, -1 },
		{ 14, 129 },
		{ 0, -1 },
		{ 0, -1 },
		{ 13, 129 },
		{ 0, -1 },
		{ 0, -1 },
		{ 12, 129 },
		{ 0, -1 },
		{ 11, 129 },
		{ 7, 129 },
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
#line 929 ".\\myparser.y"


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


