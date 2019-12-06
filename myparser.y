%{
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
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// parser name
%name myparser

// class definition
{
	// place any extra class members here
    bool isDebug = false;

}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// attribute type
%include {
#ifndef YYSTYPE
#define YYSTYPE Node* 
#endif
}

// place any declarations here
%token MAIN
%token RETURN INCLUDE BREAK 
%token INT DOUBLE FLOAT CHAR VOID
%token WHILE SWITCH FOR SWITCH LBRACE RBRACE IF ELSE
%token ASSIGN AND_BIT AND OR_BIT OR BNE LNE BE LE EQUAL NOT_EQ NOT
%token LINEEND LPAREN RPAREN LBRACE RBRACE COMMA
%token ADD SUB MUL DIV MOD
%token ID
%token INT_NUMBER
%token FLOAT_NUMBER
%token OCT_NUMBER
%token HEX_NUMBER
%token CHARACTER
%token INPUT
%token OUTPUT


%left COMMA
%right ASSIGN

%left OR OR_BIT
%left AND_BIT AND
%left LNE LE BNE BE EQUAL NOT_EQ
%left NOT

%left ADD SUB
%left MUL DIV MOD
%right UMINUS

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

program :   MAIN LPAREN RPAREN LBRACE stmts RBRACE {
                $$ = newStmtNode(CompK);
                $$->child[0] = $5;
                
                if($5->error != Normal) {
					$$->error = ChildError;
                }
                
                postOrderTraverse($$);
                printIdTable();
                
                if($$->error == Normal)
					genAsmCode(fout, $$);
				else {
					cout << endl << "Error exists" << endl;
					cout << "Can't generate asm code" << endl;
				}
                system("pause");
            }
        ;

stmts   :   stmts stmt {
                $$ = $1;
                Node* temp = $1;
                while(temp->sibling != nullptr) {
                    temp = temp->sibling;
                }
                temp->sibling = $2;
                if($2->error != Normal)
					$$->error = SibError;
            }
        |   stmt {
                $$ = $1;
            }
        ;


stmt :  assign_stmt LINEEND {
            if(isDebug) {
                cout << "assign_stmt" << endl;
            }
            temp--;
            $$->tempNum = -1;
            $$ = $1;
        }
     |  declare_stmt LINEEND{
            if(isDebug) {
                cout << "declare_stmt" << endl;
            }
            $$ = $1;
        }  
     |  if_stmt {$$ = $1;}
     |  while_stmt {$$ = $1;}
     |  for_stmt {$$ = $1;}
     |  LBRACE stmts RBRACE {
			$$ = newStmtNode(CompK);
			$$->child[0] = $2;
			
			if($2->error != Normal)
				$$->error = ChildError;
		}  
	 |	INPUT LPAREN ID RPAREN LINEEND{
			$$ = newStmtNode(InputK);
			$$->child[0] = $3;
			
			// 未声明
			it = idTable.find($3->attr.name);
			if(it == idTable.end()) {
				$3->error = NotDef;
				$$->error = ChildError;
			}
			else
				$3->type = it->second->type;
		}
	 |	OUTPUT LPAREN expr RPAREN LINEEND{
			$$ = newStmtNode(OutputK);
			$$->child[0] = $3;
			
			// 输出Bool
			if($3->type == Bool)
				$$->error = OutBool;
			if($3->type == Void)
				$$->error = OutVoid;
			if($3->error != Normal) {
				$$->error = ChildError;
			}
			
			if($3->kind.expKind == OpK)
					temp--;
			//temp = temp < 0 ? 0 : temp;
		} 
     |  LINEEND {
			$$ = newStmtNode(EmptyK);
		}
     ;

assign_stmt:	ID ASSIGN expr {
                
                $$ = newStmtNode(AssignK);
                $$->child[0] = $1;
                $$->child[1] = $3;
                $$->attr.op = new char[10];
                strcpy($$->attr.op, "=");
                
				it = idTable.find(string($1->attr.name));
				// 未定义
				if(it == idTable.end()) {
					$1->error = NotDef;
					$$->error = ChildError;
				}
				else {
					$1->type = it->second->type;
					// ID/连续赋值，右部出错
					if($3->error != Normal) {
						$$->error = ChildError;
					}
					// 类型不一致
					else if($1->type != $3->type) {
						$$->error = getDiffError($1->type, $3->type);
					}
					else {
						$$->type = $1->type;
					}
					
					if(isDebug)
						cout << $1->attr.name << ':' << $1->type << endl;
				}
				
				temp = temp - 1;
				$$->tempNum = temp++;
				tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
				//temp = temp < 0 ? 0 : temp;
		}
		;

declare_stmt:   var_type idList {
                    $$ = newStmtNode(DeclK);
                    $$->child[0] = $1;
                    $$->child[1] = $2; 
                    
                    // $$->type = $1->type;
                    
                    Node* idNode = $2;
                    while(idNode) {
						string idName = idNode->attr.name;
						idNode->type = $1->type;
						// 重定义
						if((it = idTable.find(idName)) != idTable.end()) {
							idNode->error = ReDef;
							idNode = idNode->sibling;
							$$->error = ChildError;
							continue;
						}
						// 首次定义
						variable* newVar = new variable;
						newVar->name = idName;
						newVar->type = $1->type;
						idTable.insert({idName, newVar});
						if(isDebug)
							cout << idNode->attr.name << ':' << idNode->type << endl;
						idNode = idNode->sibling;
                    } 
                }
            ;

var_type    :   VOID {
                    $$ = newTypeNode(Void);
                }
            |   INT {
                    $$ = newTypeNode(Integer);
                }
            |   FLOAT {
                    $$ = newTypeNode(Float);
                }
            |   DOUBLE {
                    $$ = newTypeNode(Double);
                }
            |   CHAR {
                    $$ = newTypeNode(Char);
                }
            ;

idList:     ID COMMA idList {
                $1->sibling = $3;
                $$ = $1;
            }
      |     ID {$$ = $1;}
      ;

if_stmt:    IF LPAREN expr RPAREN stmt ELSE stmt {
                $$ = newStmtNode(IfK);
                $$->child[0] = $3;
                $$->child[1] = $5;
                $$->child[2] = $7;
                
                $$->label = new string[3];
				$$->label[0] = "trueL" + to_string(labelNum++);
				$$->label[1] = "falseL" + to_string(labelNum++);
				$$->label[2] = "endL" + to_string(labelNum++);
                
                if($3->error != Normal 
				   || $5->error != Normal
				   || $7->error != Normal)
					$$->error = ChildError;
				else if($3->type != Bool) {
					$$->error = LogNotBool;
				}
				
				temp = temp - 1;
				//temp = temp < 0 ? 0 : temp;
				
            }
       |    IF LPAREN expr RPAREN stmt {
                $$ = newStmtNode(IfK);
                $$->child[0] = $3;
                $$->child[1] = $5;
                
                $$->label = new string[2];
				$$->label[0] = "trueL" + to_string(labelNum++);
				$$->label[1] = "endL" + to_string(labelNum++);
                
                if($3->error != Normal 
				   || $5->error != Normal)
					$$->error = ChildError;
				else if($3->type != Bool) {
					$$->error = LogNotBool;
				}
				
				temp = temp - 1;
				//temp = temp < 0 ? 0 : temp;
            }
       ;

while_stmt: WHILE LPAREN expr RPAREN stmt {
                $$ = newStmtNode(WhileK);
                $$->child[0] = $3;
                $$->child[1] = $5;
                
                $$->label = new string[3];
                $$->label[0] = "startL" + to_string(labelNum++);
				$$->label[1] = "trueL" + to_string(labelNum++);
				$$->label[2] = "endLabel" + to_string(labelNum++);
				
                if($3->error != Normal 
				   || $5->error != Normal)
					$$->error = ChildError;
				else if($3->type != Bool) {
					$$->error = LogNotBool;
				}
				
				temp = temp - 1;
				//temp = temp < 0 ? 0 : temp;
            }
          ;

for_stmt: FOR LPAREN expr LINEEND expr LINEEND expr RPAREN stmt {
                $$ = newStmtNode(ForK);   
                $$->child[0] = $3;
                $$->child[1] = $5;
                $$->child[2] = $7; 
                $$->child[3] = $9;
                
                $$->label = new string[3];
                $$->label[0] = "startLabel" + to_string(labelNum++);
				$$->label[1] = "trueLabel" + to_string(labelNum++);
				$$->label[2] = "endLabel" + to_string(labelNum++);
                
                if($3->error != Normal 
				   || $5->error != Normal
				   || $7->error != Normal
				   || $9->error != Normal)
					$$->error = ChildError;
				else if($5->type != Bool) {
					$$->error = LogNotBool;
				}
				
				temp = temp - 3;
				//temp = temp < 0 ? 0 : temp;
            }
        | FOR LPAREN      LINEEND expr LINEEND expr RPAREN stmt {
                $$ = newStmtNode(ForK);   
                $$->child[0] = nullptr;
                $$->child[1] = $4;
                $$->child[2] = $6;
                $$->child[3] = $8; 
                
                $$->label = new string[3];
                $$->label[0] = "startLabel" + to_string(labelNum++);
				$$->label[1] = "trueLabel" + to_string(labelNum++);
				$$->label[2] = "endLabel" + to_string(labelNum++);
                
                if($4->error != Normal 
				   || $6->error != Normal
				   || $8->error != Normal)
					$$->error = ChildError;
				else if($4->type != Bool) {
					$$->error = LogNotBool;
				}
				
				temp = temp - 2;
				//temp = temp < 0 ? 0 : temp;
            }
        | FOR LPAREN expr LINEEND      LINEEND expr RPAREN stmt {
                $$ = newStmtNode(ForK);   
                $$->child[0] = $3;
                $$->child[1] = nullptr;
                $$->child[2] = $6;
                $$->child[3] = $8; 
                
                $$->label = new string[3];
                $$->label[0] = "startLabel" + to_string(labelNum++);
				$$->label[1] = "trueLabel" + to_string(labelNum++);
				$$->label[2] = "endLabel" + to_string(labelNum++);
                
                if($3->error != Normal 
				   || $6->error != Normal
				   || $8->error != Normal)
					$$->error = ChildError;
					
				temp = temp - 2;
				//temp = temp < 0 ? 0 : temp;
            }
        | FOR LPAREN expr LINEEND expr LINEEND      RPAREN stmt {
                $$ = newStmtNode(ForK);   
                $$->child[0] = $3;
                $$->child[1] = $5;
                $$->child[2] = nullptr;
                $$->child[3] = $8;
                
                $$->label = new string[3];
                $$->label[0] = "startLabel" + to_string(labelNum++);
				$$->label[1] = "trueLabel" + to_string(labelNum++);
				$$->label[2] = "endLabel" + to_string(labelNum++);
				
                if($3->error != Normal 
				   || $5->error != Normal
				   || $8->error != Normal)
					$$->error = ChildError;
				else if($5->type != Bool) {
					$$->error = LogNotBool;
				}
				
				temp = temp - 2;
				//temp = temp < 0 ? 0 : temp;
            }
        | FOR LPAREN      LINEEND      LINEEND expr RPAREN stmt {
                $$ = newStmtNode(ForK);   
                $$->child[0] = nullptr;
                $$->child[1] = nullptr;
                $$->child[2] = $5;
                $$->child[3] = $7;
                
                $$->label = new string[3];
                $$->label[0] = "startLabel" + to_string(labelNum++);
				$$->label[1] = "trueLabel" + to_string(labelNum++);
				$$->label[2] = "endLabel" + to_string(labelNum++);
                
                if($5->error != Normal 
				   || $7->error != Normal)
					$$->error = ChildError;
					
				temp = temp - 1;
				//temp = temp < 0 ? 0 : temp;
            }
        | FOR LPAREN      LINEEND expr LINEEND      RPAREN stmt {
                $$ = newStmtNode(ForK);   
                $$->child[0] = nullptr;
                $$->child[1] = $4;
                $$->child[2] = nullptr;
                $$->child[3] = $7;
                
                $$->label = new string[3];
                $$->label[0] = "startLabel" + to_string(labelNum++);
				$$->label[1] = "trueLabel" + to_string(labelNum++);
				$$->label[2] = "endLabel" + to_string(labelNum++);
                
                if($4->error != Normal 
				   || $7->error != Normal)
					$$->error = ChildError;
				else if($4->type != Bool) {
					$$->error = LogNotBool;
				}
				
				temp = temp - 1;
				//temp = temp < 0 ? 0 : temp;
            }
        | FOR LPAREN expr LINEEND      LINEEND      RPAREN stmt {
                $$ = newStmtNode(ForK);   
                $$->child[0] = $3;
                $$->child[1] = nullptr;
                $$->child[2] = nullptr;
                $$->child[3] = $7;
                
                $$->label = new string[3];
                $$->label[0] = "startLabel" + to_string(labelNum++);
				$$->label[1] = "trueLabel" + to_string(labelNum++);
				$$->label[2] = "endLabel" + to_string(labelNum++);
                
                if($3->error != Normal 
				   || $7->error != Normal)
					$$->error = ChildError;
		
				temp = temp - 1;
				//temp = temp < 0 ? 0 : temp;
            }
        | FOR LPAREN      LINEEND      LINEEND      RPAREN stmt {
                $$ = newStmtNode(ForK);   
                $$->child[0] = nullptr;
                $$->child[1] = nullptr;
                $$->child[2] = nullptr;
                $$->child[3] = $6;
                
                $$->label = new string[3];
                $$->label[0] = "startLabel" + to_string(labelNum++);
				$$->label[1] = "trueLabel" + to_string(labelNum++);
				$$->label[2] = "endLabel" + to_string(labelNum++);
                
                if($6->error != Normal)
					$$->error = ChildError;
					
            }
        ;
        
logical_expr :     |   expr BNE expr {
            $$ = newExpNode(OpK);
            $$->attr.op = new char[10];
            strcpy($$->attr.op, ">");
            $$->child[0] = $1;
            $$->child[1] = $3;
            
            $$->type = Bool;
            
            if($1->error != Normal || $3->error != Normal) {
				$$->error = ChildError;
            }
            else if($1->type != $3->type) {
				$$->error = getDiffError($1->type, $3->type);
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            $$->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
			
            if(isDebug) 
                cout << $$->lineNo <<": >" << endl;
        }
    |   expr BE expr {
            $$ = newExpNode(OpK);
            $$->attr.op = new char[10];
            strcpy($$->attr.op, ">=");
            $$->child[0] = $1;
            $$->child[1] = $3;
            
            $$->type = Bool;
            
            if($1->error != Normal || $3->error != Normal) {
				$$->error = ChildError;
            }
            else if($1->type != $3->type) {
				$$->error = getDiffError($1->type, $3->type);
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            $$->tempNum = temp++;
			tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
			
            if(isDebug) 
                cout << $$->lineNo << ": >=" << endl;
        }
    |   expr LNE expr {
            $$ = newExpNode(OpK);
            $$->attr.op = new char[10];
            strcpy($$->attr.op, "<");
            $$->child[0] = $1;
            $$->child[1] = $3;
            
            $$->type = Bool;
            
            if($1->error != Normal || $3->error != Normal) {
				$$->error = ChildError;
            }
            else if($1->type != $3->type) {
				$$->error = getDiffError($1->type, $3->type);
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            $$->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug) 
                cout << $$->lineNo << ": <" << endl;
        }
    |   expr LE expr {
            $$ = newExpNode(OpK);
            $$->attr.op = new char[10];
            strcpy($$->attr.op, "<=");
            $$->child[0] = $1;
            $$->child[1] = $3;
            
            $$->type = Bool;
            
            if($1->error != Normal || $3->error != Normal) {
				$$->error = ChildError;
            }
            else if($1->type != $3->type) {
				$$->error = getDiffError($1->type, $3->type);
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            $$->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug) 
                cout << $$->lineNo << ": <=" << endl;
        }
    |   expr EQUAL expr {
            $$ = newExpNode(OpK);
            $$->attr.op = new char[10];
            strcpy($$->attr.op, "==");
            $$->child[0] = $1;
            $$->child[1] = $3;
            
            $$->type = Bool;
            if($1->error != Normal || $3->error != Normal) {
				$$->error = ChildError;
            }
            else if($1->type != $3->type) {
				$$->error = getDiffError($1->type, $3->type);
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            $$->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug)
                cout << $$->lineNo << ": ==" << endl;
        }
    |	expr NOT_EQ expr {
            $$ = newExpNode(OpK);
            $$->attr.op = new char[10];
            strcpy($$->attr.op, "!=");
            $$->child[0] = $1;
            $$->child[1] = $3;
            
            $$->type = Bool;
            
            if($1->error != Normal || $3->error != Normal) {
				$$->error = ChildError;
            }
            else if($1->type != $3->type) {
				$$->error = getDiffError($1->type, $3->type);
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            $$->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug)
                cout << $$->lineNo << ": !=" << endl;
		}
	|	expr AND expr {
            $$ = newExpNode(OpK);
            $$->attr.op = new char[10];
            strcpy($$->attr.op, "&&");
            $$->child[0] = $1;
            $$->child[1] = $3;
            
            $$->type = Bool;
            if($1->error != Normal || $3->error != Normal) {
				$$->error = ChildError;
            }
            else if(!($1->type == Bool && $3->type == Bool)) {
				$$->error = LogNotBool;
			}
			
			$$->label = new string[3];
            $$->label[0] = "trueL" + to_string(labelNum++);
            $$->label[1] = "trueL" + to_string(labelNum++);
			$$->label[2] = "falseL" + to_string(labelNum++);
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            $$->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug)
                cout << $$->lineNo << ": &&" << endl;
		}
	| expr OR expr {
            $$ = newExpNode(OpK);
            $$->attr.op = new char[10];
            strcpy($$->attr.op, "||");
            $$->child[0] = $1;
            $$->child[1] = $3;
            
            $$->type = Bool;
            if($1->error != Normal || $3->error != Normal) {
				$$->error = ChildError;
            }
            else if(!($1->type == Bool && $3->type == Bool)) {
				$$->error = LogNotBool;
			}
			
			$$->label = new string[3];
            $$->label[0] = "falseL" + to_string(labelNum++);
            $$->label[1] = "falseL" + to_string(labelNum++);
			$$->label[2] = "trueL" + to_string(labelNum++);
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            $$->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug)
                cout << $$->lineNo << ": ||" << endl;
		}
	| NOT expr {
            $$ = newExpNode(OpK);
            $$->attr.op = new char[10];
            strcpy($$->attr.op, "!");
            $$->child[0] = $2;
            
            $$->type = Bool;
            if($2->error != Normal) {
				$$->error = ChildError;
            }
            else if(!($2->type == Bool)) {
				$$->error = LogNotBool;
			}
			
			$$->label = new string[2];
            $$->label[0] = "trueL" + to_string(labelNum++);
			$$->label[1] = "falseL" + to_string(labelNum++);
			
			temp = temp - 1 ;
			//temp = temp < 0 ? 0 : temp;
            $$->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            
            if(isDebug)
                cout << $$->lineNo << ": !" << endl;
		}
	;

expr	:	expr ADD expr	{
            $$ = newExpNode(OpK);
            $$->attr.op = new char[10];
            strcpy($$->attr.op, "+");
            $$->child[0] = $1;
            $$->child[1] = $3;
            
            if($1->error != Normal || $3->error != Normal) {
				$$->error = ChildError;
            }
            else if($1->type != $3->type) {
				$$->error = getDiffError($1->type, $3->type);
			}
			else {
				$$->type = $1->type;
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            $$->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug) 
                cout << $$->lineNo << ": +" << endl;
        }
	|	expr SUB expr	{
            $$ = newExpNode(OpK);
            $$->attr.op = new char[10];
            strcpy($$->attr.op, "-");
            $$->child[0] = $1;
            $$->child[1] = $3;
            
            if($1->error != Normal || $3->error != Normal) {
				$$->error = ChildError;
            }
            else if($1->type != $3->type) {
				$$->error = getDiffError($1->type, $3->type);
			}
			else {
				$$->type = $1->type;
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            $$->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug) 
                cout << $$->lineNo << ": -" << endl;
        }
	|	expr MUL expr	{
            $$ = newExpNode(OpK);
            $$->attr.op = new char[10];
            strcpy($$->attr.op, "*");
            $$->child[0] = $1;
            $$->child[1] = $3;
            
            if($1->error != Normal || $3->error != Normal) {
				$$->error = ChildError;
            }
            else if($1->type != $3->type) {
				$$->error = getDiffError($1->type, $3->type);
			}
			else {
				$$->type = $1->type;
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            $$->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug) 
                cout << $$->lineNo << ": *" << endl;
        }
	|	expr DIV expr	{
            $$ = newExpNode(OpK);
            $$->attr.op = new char[10];
            strcpy($$->attr.op, "/");
            $$->child[0] = $1;
            $$->child[1] = $3;
            
            if($1->error != Normal || $3->error != Normal) {
				$$->error = ChildError;
            }
            else if($1->type != $3->type) {
				$$->error = getDiffError($1->type, $3->type);
			}
			else {
				$$->type = $1->type;
			}
			
			temp = temp - 2 ;
			//temp = temp < 0 ? 0 : temp;
            $$->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug) 
                cout << $$->lineNo << ": /" << endl;
        }
	   | expr MOD expr {
            $$ = newExpNode(OpK);
            $$->attr.op = new char[10];
            strcpy($$->attr.op, "%");
            $$->child[0] = $1;
            $$->child[1] = $3;
            
            if($1->error != Normal || $3->error != Normal) {
				$$->error = ChildError;
            }
            else if($1->type != $3->type) {
				$$->error = getDiffError($1->type, $3->type);
			}
			else {
				$$->type = $1->type;
			}
			
			temp = temp - 2;
			//temp = temp < 0 ? 0 : temp;
            $$->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
            if(isDebug) 
                cout << $$->lineNo << ": %" << endl;
		}
		| expr AND_BIT expr {
		        $$ = newExpNode(OpK);
				$$->attr.op = new char[10];
				strcpy($$->attr.op, "&");
				$$->child[0] = $1;
				$$->child[1] = $3;
				
				if($1->error != Normal || $3->error != Normal) {
					$$->error = ChildError;
				}
				else if($1->type != $3->type) {
					$$->error = getDiffError($1->type, $3->type);
				}
				else {
					$$->type = $1->type;
				}
				
				temp = temp - 2 ;
				//temp = temp < 0 ? 0 : temp;
				$$->tempNum = temp++;
				tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
			}
		| expr OR_BIT expr {
            $$ = newExpNode(OpK);
				$$->attr.op = new char[10];
				strcpy($$->attr.op, "|");
				$$->child[0] = $1;
				$$->child[1] = $3;
				
				if($1->error != Normal || $3->error != Normal) {
					$$->error = ChildError;
				}
				else if($1->type != $3->type) {
					$$->error = getDiffError($1->type, $3->type);
				}
				else {
					$$->type = $1->type;
				}
				
				temp = temp - 2 ;
				//temp = temp < 0 ? 0 : temp;
				$$->tempNum = temp++;
				tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
		}
	|	LPAREN expr RPAREN	{
			$$ = $2;
        }
	|	NUMBER	{
            $$ = $1;
            $$->tempNum = temp++;
            tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
        }
    |	CHARACTER {
			$$ = $1;
			$$->tempNum = temp++;
			tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
		}
	|	ID	{
            $$ = $1;
            if((it = idTable.find($1->attr.name)) == idTable.end())
				$$->error = NotDef;
			else
				$$->type = it->second->type;
			$$->tempNum = temp++;
			tempMaxNum = tempMaxNum < temp ? temp : tempMaxNum;
        }
    |   assign_stmt {
			$$ = $1;
		}
    |	logical_expr {$$ = $1;}
	;

NUMBER  :   INT_NUMBER {$$ = $1;}
        |   FLOAT_NUMBER {$$ = $1;}
        |   HEX_NUMBER {$$ = $1;}
        |   OCT_NUMBER  {$$ = $1;}
        ;

Grammar
	: /* empty */
	;

%%

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

