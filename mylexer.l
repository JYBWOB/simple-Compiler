%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2019Äê11ÔÂ10ÈÕ
****************************************************************************/

#include "myparser.h"
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


#define MAXCHILDREN 4

struct Node
{
	Node* child[MAXCHILDREN];
	Node* sibling;
	NodeKind nodeKind;
	union {StmtKind stmtKind; ExpKind expKind;} kind;
	union {
		char* op; 
		union {int intVal;double doubleVal;
			   float floatVal;char chVal; bool booleanVal;} value;
		char* name;
	} attr;
    TypeKind type;
	int lineNo;
	
	string* label;
	int tempNum;
};
extern Node* newStmtNode(StmtKind sk); 
extern Node* newExpNode(ExpKind ek);
extern Node* newTypeNode(TypeKind type);
extern int LINENO;
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name mylexer

// class definition
{
	// place any extra class members here
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// place any declarations here
SPACE [ \t\v\f\n]
SINGLE_COMMENT {DIV}{DIV}.*
MULTI_COMMENT {DIV}{MUL}([^*"]*|".*"|\*+[^/])*{MUL}{DIV}

INPUT input
OUTPUT output
RETURN return
INT int
DOUBLE double
FLOAT float
CHAR char
VOID void
MAIN main
BREAK break
INCLUDE include
WHILE while
SWITCH switch
FOR for
LBRACE \{
RBRACE \}
IF if
ELSE else
ASSIGN =
BNE \>
LNE \<
BE {BNE}{ASSIGN}
LE {LNE}{ASSIGN}
AND_BIT &
AND {AND_BIT}{AND_BIT}
OR_BIT \|
OR {OR_BIT}{OR_BIT}
NOT !
NOT_EQ {NOT}{ASSIGN}
EQUAL {ASSIGN}{ASSIGN}
LINEEND ;
LPAREN \(
RPAREN \)
COMMA ,
ADD \+
SUB -
MUL \*
DIV \/
MOD \%
ID [a-zA-Z_][a-zA-Z0-9_]*
INT_NUMBER ([1-9][0-9]*)|(0)
FLOAT_NUMBER ({INT_NUMBER})(\.)([0-9]+)
//EXP_NUMBER ({INT_NUMBER}|{FLOAT_NUMBER})(e|E){INT_NUMBER}
OCT_NUMBER 0[0-7]+
HEX_NUMBER 0x[0-9a-fA-F]+

CHARACTER '.'

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

// place your Lex rules here
{SPACE} {; /* do nothing */}

{INPUT} {return INPUT;}
{OUTPUT} {return OUTPUT;}

{RETURN} {return RETURN;}
{INT} {return INT;}
{FLOAT} {return FLOAT;}
{DOUBLE} {return DOUBLE;}
{CHAR} {return CHAR;}
{VOID} {return VOID;}
{MAIN} {return MAIN;}
{BREAK} {return BREAK;}
{INCLUDE} {return INCLUDE;}
{WHILE} {return WHILE;}
{FOR} {return FOR;}
{SWITCH} {return SWITCH;}
{LBRACE} {return LBRACE;}
{RBRACE} {return RBRACE;}
{IF} {return IF;}
{ELSE} {return ELSE;}
{BE} {return BE;}
{BNE} {return BNE;}
{LE} {return LE;}
{LNE} {return LNE;}
{EQUAL} {return EQUAL;}
{ASSIGN} {return ASSIGN;}
{AND_BIT} {return AND_BIT;}
{AND} {return AND;}
{OR_BIT} {return OR_BIT;}
{OR} {return OR;}
{NOT} {return NOT;}
{NOT_EQ} {return NOT_EQ;}
{LINEEND} {return LINEEND;}
{LPAREN} {return LPAREN;}
{RPAREN} {return RPAREN;}
{COMMA} {return COMMA;}
{ADD} {return ADD;}
{SUB} {return SUB;}
{MUL} {return MUL;}
{DIV} {return DIV;}
{MOD} {return MOD;}
{ID} {
    Node* temp = newExpNode(IdK);
    temp->attr.name = new char[10];
    strcpy(temp->attr.name, yytext);
    yylval = temp;
    return ID;
}
{FLOAT_NUMBER} {
            Node* temp = newExpNode(ConstK);
            temp->attr.value.floatVal = atof(yytext);
            temp->type = Float;
            yylval = temp;
            return FLOAT_NUMBER;
        }
{INT_NUMBER} {
            Node* temp = newExpNode(ConstK);
            temp->attr.value.intVal = atoi(yytext);
            temp->type = Integer;
            yylval = temp;
            return INT_NUMBER;
        }
{OCT_NUMBER} {
		int length = strlen(yytext);
		int value = 0;
		for(int i = 1; i < length; i++)
		{
		    value = value*8;
			value += yytext[i]-'0';
		}
        Node* temp = newExpNode(ConstK);
        temp->attr.value.intVal = value;
        temp->type = Integer;
        yylval = temp;
        return OCT_NUMBER;
	}
{HEX_NUMBER} {
		int length = strlen(yytext);
		int value = 0;
		for(int i = 2; i < length; i++)
		{
			value = value*16;
			if('0' <= yytext[i] && '9' >= yytext[i])
				value += yytext[i] - '0';
			else if('a' <= yytext[i] && 'f' >= yytext[i])
				value += yytext[i] - 'a' + 10;
			else 
				value += yytext[i] - 'A' + 10;
		}
        //intVal = value;
        Node* temp = newExpNode(ConstK);
        temp->attr.value.intVal = value;
        temp->type = Integer;
        yylval = temp;
        return HEX_NUMBER;
	}
{CHARACTER} {
		Node* temp = newExpNode(ConstK);
		temp->attr.value.chVal = yytext[1];
		temp->type = Char;
		yylval = temp;
		return CHARACTER;
	}
	
{SINGLE_COMMENT} {;}
{MULTI_COMMENT} {;}

%%

/////////////////////////////////////////////////////////////////////////////
// programs section

