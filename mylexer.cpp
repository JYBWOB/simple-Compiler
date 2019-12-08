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
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 12/08/19
* Time: 21:34:53
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

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
	OpK, ConstK, IdK, IdArrK
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

#line 103 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
#line 78 ".\\mylexer.l"

	// place any extra initialisation code here

#line 127 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 83 ".\\mylexer.l"

	// place any extra cleanup code here

#line 139 "mylexer.cpp"
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
#line 147 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 210 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 153 ".\\mylexer.l"
; /* do nothing */
#line 217 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 155 ".\\mylexer.l"
return INPUT;
#line 224 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 156 ".\\mylexer.l"
return OUTPUT;
#line 231 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 158 ".\\mylexer.l"
return RETURN;
#line 238 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 159 ".\\mylexer.l"
return INT;
#line 245 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 160 ".\\mylexer.l"
return FLOAT;
#line 252 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 161 ".\\mylexer.l"
return DOUBLE;
#line 259 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 162 ".\\mylexer.l"
return CHAR;
#line 266 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 163 ".\\mylexer.l"
return VOID;
#line 273 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 164 ".\\mylexer.l"
return MAIN;
#line 280 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 165 ".\\mylexer.l"
return BREAK;
#line 287 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 166 ".\\mylexer.l"
return INCLUDE;
#line 294 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 167 ".\\mylexer.l"
return WHILE;
#line 301 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 168 ".\\mylexer.l"
return FOR;
#line 308 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 169 ".\\mylexer.l"
return SWITCH;
#line 315 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 170 ".\\mylexer.l"
return LBRACE;
#line 322 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 171 ".\\mylexer.l"
return RBRACE;
#line 329 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 172 ".\\mylexer.l"
return IF;
#line 336 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 173 ".\\mylexer.l"
return ELSE;
#line 343 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 174 ".\\mylexer.l"
return BE;
#line 350 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 175 ".\\mylexer.l"
return BNE;
#line 357 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 176 ".\\mylexer.l"
return LE;
#line 364 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 177 ".\\mylexer.l"
return LNE;
#line 371 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 178 ".\\mylexer.l"
return EQUAL;
#line 378 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 179 ".\\mylexer.l"
return ASSIGN;
#line 385 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 180 ".\\mylexer.l"
return AND_BIT;
#line 392 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 181 ".\\mylexer.l"
return AND;
#line 399 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 182 ".\\mylexer.l"
return OR_BIT;
#line 406 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 183 ".\\mylexer.l"
return OR;
#line 413 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 184 ".\\mylexer.l"
return NOT;
#line 420 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 185 ".\\mylexer.l"
return NOT_EQ;
#line 427 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 186 ".\\mylexer.l"
return LINEEND;
#line 434 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 187 ".\\mylexer.l"
return LPAREN;
#line 441 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 188 ".\\mylexer.l"
return RPAREN;
#line 448 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 189 ".\\mylexer.l"
return LFPA;
#line 455 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 190 ".\\mylexer.l"
return RFPA;
#line 462 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 191 ".\\mylexer.l"
return COMMA;
#line 469 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 192 ".\\mylexer.l"
return ADD;
#line 476 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 193 ".\\mylexer.l"
return SUB;
#line 483 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 194 ".\\mylexer.l"
return MUL;
#line 490 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 195 ".\\mylexer.l"
return DIV;
#line 497 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 196 ".\\mylexer.l"
return MOD;
#line 504 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 197 ".\\mylexer.l"

    Node* temp = newExpNode(IdK);
    temp->attr.name = new char[10];
    strcpy(temp->attr.name, yytext);
    yylval = temp;
    return ID;

#line 517 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 204 ".\\mylexer.l"

            Node* temp = newExpNode(ConstK);
            temp->attr.value.floatVal = atof(yytext);
            temp->type = Float;
            yylval = temp;
            return FLOAT_NUMBER;
        
#line 530 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 211 ".\\mylexer.l"

            Node* temp = newExpNode(ConstK);
            temp->attr.value.intVal = atoi(yytext);
            temp->type = Integer;
            yylval = temp;
            return INT_NUMBER;
        
#line 543 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 218 ".\\mylexer.l"

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
	
#line 563 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 232 ".\\mylexer.l"

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
	
#line 589 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 252 ".\\mylexer.l"

		Node* temp = newExpNode(ConstK);
		temp->attr.value.chVal = yytext[1];
		temp->type = Char;
		yylval = temp;
		return CHARACTER;
	
#line 602 "mylexer.cpp"
		}
		break;
#line 259 ".\\mylexer.l"
	
#line 607 "mylexer.cpp"
	case 49:
		{
#line 260 ".\\mylexer.l"
;
#line 612 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 261 ".\\mylexer.l"
;
#line 619 "mylexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 248;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 3, 1 },
		{ 3, 1 },
		{ 3, 1 },
		{ 44, 15 },
		{ 76, 57 },
		{ 42, 87 },
		{ 56, 29 },
		{ 0, 101 },
		{ 85, 66 },
		{ 54, 28 },
		{ 39, 4 },
		{ 42, 14 },
		{ 55, 28 },
		{ 86, 66 },
		{ 57, 29 },
		{ 66, 101 },
		{ 43, 14 },
		{ 77, 57 },
		{ 101, 87 },
		{ 67, 101 },
		{ 40, 6 },
		{ 78, 57 },
		{ 3, 1 },
		{ 4, 1 },
		{ 58, 30 },
		{ 59, 31 },
		{ 60, 32 },
		{ 5, 1 },
		{ 6, 1 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 61, 33 },
		{ 14, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 62, 34 },
		{ 17, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 44, 16 },
		{ 63, 35 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 68, 68 },
		{ 64, 37 },
		{ 65, 41 },
		{ 46, 15 },
		{ 0, 43 },
		{ 0, 7 },
		{ 70, 50 },
		{ 22, 1 },
		{ 71, 51 },
		{ 23, 1 },
		{ 72, 52 },
		{ 73, 53 },
		{ 74, 54 },
		{ 75, 55 },
		{ 24, 1 },
		{ 25, 1 },
		{ 26, 1 },
		{ 27, 1 },
		{ 28, 1 },
		{ 47, 18 },
		{ 79, 58 },
		{ 29, 1 },
		{ 80, 59 },
		{ 81, 60 },
		{ 82, 61 },
		{ 30, 1 },
		{ 83, 62 },
		{ 31, 1 },
		{ 84, 63 },
		{ 48, 19 },
		{ 32, 1 },
		{ 33, 1 },
		{ 87, 67 },
		{ 49, 20 },
		{ 34, 1 },
		{ 35, 1 },
		{ 50, 24 },
		{ 88, 70 },
		{ 90, 72 },
		{ 36, 1 },
		{ 37, 1 },
		{ 38, 1 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 89, 71 },
		{ 91, 73 },
		{ 92, 74 },
		{ 93, 76 },
		{ 94, 77 },
		{ 95, 79 },
		{ 96, 80 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 97, 81 },
		{ 98, 82 },
		{ 99, 83 },
		{ 100, 84 },
		{ 21, 116 },
		{ 42, 85 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 21, 116 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 51, 25 },
		{ 102, 88 },
		{ 103, 90 },
		{ 104, 92 },
		{ 105, 93 },
		{ 106, 94 },
		{ 107, 96 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 45, 45 },
		{ 45, 45 },
		{ 45, 45 },
		{ 45, 45 },
		{ 45, 45 },
		{ 45, 45 },
		{ 45, 45 },
		{ 45, 45 },
		{ 108, 97 },
		{ 109, 98 },
		{ 110, 100 },
		{ 52, 26 },
		{ 111, 103 },
		{ 112, 105 },
		{ 113, 107 },
		{ 114, 108 },
		{ 115, 109 },
		{ 116, 112 },
		{ 53, 27 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 116, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 1 },
		{ 0, -49, 30 },
		{ 0, 0, 42 },
		{ 0, -16, 26 },
		{ -41, 71, 0 },
		{ 0, 0, 33 },
		{ 0, 0, 34 },
		{ 0, 0, 40 },
		{ 0, 0, 38 },
		{ 0, 0, 37 },
		{ 0, 0, 39 },
		{ 0, -29, 41 },
		{ 45, -41, 45 },
		{ 0, 9, 45 },
		{ 0, 0, 32 },
		{ 0, 34, 23 },
		{ 0, 44, 25 },
		{ 0, 48, 21 },
		{ 116, 0, 43 },
		{ 0, 0, 35 },
		{ 0, 0, 36 },
		{ 116, -2, 43 },
		{ 116, 99, 43 },
		{ 116, 116, 43 },
		{ 116, 126, 43 },
		{ 116, -97, 43 },
		{ 116, -94, 43 },
		{ 116, -71, 43 },
		{ 116, -90, 43 },
		{ 116, -73, 43 },
		{ 116, -81, 43 },
		{ 116, -61, 43 },
		{ 116, -48, 43 },
		{ 0, 0, 16 },
		{ 0, -47, 28 },
		{ 0, 0, 17 },
		{ 0, 0, 31 },
		{ 0, 0, 27 },
		{ 0, 39, 0 },
		{ 101, 0, 0 },
		{ -43, 70, 49 },
		{ 68, 0, 0 },
		{ 0, 168, 46 },
		{ 69, 0, 0 },
		{ 0, 0, 22 },
		{ 0, 0, 24 },
		{ 0, 0, 20 },
		{ 116, -19, 43 },
		{ 116, -13, 43 },
		{ 116, -31, 43 },
		{ 116, -28, 43 },
		{ 116, -23, 43 },
		{ 116, -25, 43 },
		{ 116, 0, 18 },
		{ 116, -93, 43 },
		{ 116, -9, 43 },
		{ 116, -18, 43 },
		{ 116, -17, 43 },
		{ 116, -5, 43 },
		{ 116, -3, 43 },
		{ 116, -1, 43 },
		{ 0, 0, 29 },
		{ 0, 0, 48 },
		{ -42, -32, 0 },
		{ 101, 66, 0 },
		{ 0, 19, 44 },
		{ 0, 145, 47 },
		{ 116, 16, 43 },
		{ 116, 14, 43 },
		{ 116, 16, 43 },
		{ 116, 28, 43 },
		{ 116, 33, 43 },
		{ 116, 0, 14 },
		{ 116, 23, 43 },
		{ 116, 15, 43 },
		{ 116, 0, 5 },
		{ 116, 23, 43 },
		{ 116, 22, 43 },
		{ 116, 44, 43 },
		{ 116, 46, 43 },
		{ 116, 63, 43 },
		{ 116, 56, 43 },
		{ 87, 119, 0 },
		{ 0, 0, 50 },
		{ 67, -27, 0 },
		{ 116, 97, 43 },
		{ 116, 0, 8 },
		{ 116, 97, 43 },
		{ 116, 0, 19 },
		{ 116, 90, 43 },
		{ 116, 90, 43 },
		{ 116, 92, 43 },
		{ 116, 0, 10 },
		{ 116, 92, 43 },
		{ 116, 110, 43 },
		{ 116, 126, 43 },
		{ 116, 0, 9 },
		{ 116, 125, 43 },
		{ -42, -25, 50 },
		{ 116, 0, 11 },
		{ 116, 127, 43 },
		{ 116, 0, 6 },
		{ 116, 129, 43 },
		{ 116, 0, 2 },
		{ 116, 114, 43 },
		{ 116, 121, 43 },
		{ 116, 128, 43 },
		{ 116, 0, 13 },
		{ 116, 0, 7 },
		{ 116, 132, 43 },
		{ 116, 0, 3 },
		{ 116, 0, 4 },
		{ 116, 0, 15 },
		{ 0, 70, 12 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 263 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section


