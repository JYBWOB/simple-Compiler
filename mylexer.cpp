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
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 12/07/19
* Time: 00:59:29
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
#line 145 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 210 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 151 ".\\mylexer.l"
; /* do nothing */
#line 217 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 153 ".\\mylexer.l"
return INPUT;
#line 224 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 154 ".\\mylexer.l"
return OUTPUT;
#line 231 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 156 ".\\mylexer.l"
return RETURN;
#line 238 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 157 ".\\mylexer.l"
return INT;
#line 245 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 158 ".\\mylexer.l"
return FLOAT;
#line 252 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 159 ".\\mylexer.l"
return DOUBLE;
#line 259 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 160 ".\\mylexer.l"
return CHAR;
#line 266 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 161 ".\\mylexer.l"
return VOID;
#line 273 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 162 ".\\mylexer.l"
return MAIN;
#line 280 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 163 ".\\mylexer.l"
return BREAK;
#line 287 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 164 ".\\mylexer.l"
return INCLUDE;
#line 294 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 165 ".\\mylexer.l"
return WHILE;
#line 301 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 166 ".\\mylexer.l"
return FOR;
#line 308 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 167 ".\\mylexer.l"
return SWITCH;
#line 315 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 168 ".\\mylexer.l"
return LBRACE;
#line 322 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 169 ".\\mylexer.l"
return RBRACE;
#line 329 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 170 ".\\mylexer.l"
return IF;
#line 336 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 171 ".\\mylexer.l"
return ELSE;
#line 343 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 172 ".\\mylexer.l"
return BE;
#line 350 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 173 ".\\mylexer.l"
return BNE;
#line 357 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 174 ".\\mylexer.l"
return LE;
#line 364 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 175 ".\\mylexer.l"
return LNE;
#line 371 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 176 ".\\mylexer.l"
return EQUAL;
#line 378 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 177 ".\\mylexer.l"
return ASSIGN;
#line 385 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 178 ".\\mylexer.l"
return AND_BIT;
#line 392 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 179 ".\\mylexer.l"
return AND;
#line 399 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 180 ".\\mylexer.l"
return OR_BIT;
#line 406 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 181 ".\\mylexer.l"
return OR;
#line 413 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 182 ".\\mylexer.l"
return NOT;
#line 420 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 183 ".\\mylexer.l"
return NOT_EQ;
#line 427 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 184 ".\\mylexer.l"
return LINEEND;
#line 434 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 185 ".\\mylexer.l"
return LPAREN;
#line 441 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 186 ".\\mylexer.l"
return RPAREN;
#line 448 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 187 ".\\mylexer.l"
return COMMA;
#line 455 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 188 ".\\mylexer.l"
return ADD;
#line 462 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 189 ".\\mylexer.l"
return SUB;
#line 469 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 190 ".\\mylexer.l"
return MUL;
#line 476 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 191 ".\\mylexer.l"
return DIV;
#line 483 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 192 ".\\mylexer.l"
return MOD;
#line 490 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 193 ".\\mylexer.l"

    Node* temp = newExpNode(IdK);
    temp->attr.name = new char[10];
    strcpy(temp->attr.name, yytext);
    yylval = temp;
    return ID;

#line 503 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 200 ".\\mylexer.l"

            Node* temp = newExpNode(ConstK);
            temp->attr.value.floatVal = atof(yytext);
            temp->type = Float;
            yylval = temp;
            return FLOAT_NUMBER;
        
#line 516 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 207 ".\\mylexer.l"

            Node* temp = newExpNode(ConstK);
            temp->attr.value.intVal = atoi(yytext);
            temp->type = Integer;
            yylval = temp;
            return INT_NUMBER;
        
#line 529 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 214 ".\\mylexer.l"

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
	
#line 549 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 228 ".\\mylexer.l"

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
	
#line 575 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 248 ".\\mylexer.l"

		Node* temp = newExpNode(ConstK);
		temp->attr.value.chVal = yytext[1];
		temp->type = Char;
		yylval = temp;
		return CHARACTER;
	
#line 588 "mylexer.cpp"
		}
		break;
#line 255 ".\\mylexer.l"
	
#line 593 "mylexer.cpp"
	case 47:
		{
#line 256 ".\\mylexer.l"
;
#line 598 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 257 ".\\mylexer.l"
;
#line 605 "mylexer.cpp"
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
		{ 42, 15 },
		{ 74, 55 },
		{ 40, 85 },
		{ 54, 27 },
		{ 0, 99 },
		{ 83, 64 },
		{ 52, 26 },
		{ 37, 4 },
		{ 40, 14 },
		{ 53, 26 },
		{ 84, 64 },
		{ 55, 27 },
		{ 64, 99 },
		{ 41, 14 },
		{ 75, 55 },
		{ 99, 85 },
		{ 65, 99 },
		{ 38, 6 },
		{ 76, 55 },
		{ 3, 1 },
		{ 4, 1 },
		{ 56, 28 },
		{ 57, 29 },
		{ 58, 30 },
		{ 5, 1 },
		{ 6, 1 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 59, 31 },
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
		{ 60, 32 },
		{ 17, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 42, 16 },
		{ 61, 33 },
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
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 62, 35 },
		{ 63, 39 },
		{ 44, 15 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 0, 41 },
		{ 0, 7 },
		{ 22, 1 },
		{ 23, 1 },
		{ 24, 1 },
		{ 25, 1 },
		{ 26, 1 },
		{ 68, 48 },
		{ 69, 49 },
		{ 27, 1 },
		{ 70, 50 },
		{ 71, 51 },
		{ 72, 52 },
		{ 28, 1 },
		{ 73, 53 },
		{ 29, 1 },
		{ 45, 18 },
		{ 78, 57 },
		{ 30, 1 },
		{ 31, 1 },
		{ 77, 56 },
		{ 79, 58 },
		{ 32, 1 },
		{ 33, 1 },
		{ 80, 59 },
		{ 81, 60 },
		{ 82, 61 },
		{ 34, 1 },
		{ 35, 1 },
		{ 36, 1 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 46, 19 },
		{ 85, 65 },
		{ 47, 20 },
		{ 48, 22 },
		{ 86, 68 },
		{ 87, 69 },
		{ 88, 70 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 89, 71 },
		{ 90, 72 },
		{ 91, 74 },
		{ 92, 75 },
		{ 21, 114 },
		{ 93, 77 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 21, 114 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 94, 78 },
		{ 95, 79 },
		{ 96, 80 },
		{ 97, 81 },
		{ 98, 82 },
		{ 40, 83 },
		{ 49, 23 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 100, 86 },
		{ 101, 88 },
		{ 102, 90 },
		{ 103, 91 },
		{ 104, 92 },
		{ 105, 94 },
		{ 106, 95 },
		{ 107, 96 },
		{ 108, 98 },
		{ 50, 24 },
		{ 109, 101 },
		{ 110, 103 },
		{ 111, 105 },
		{ 112, 106 },
		{ 113, 107 },
		{ 114, 110 },
		{ 51, 25 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 114, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 1 },
		{ 0, -49, 30 },
		{ 0, 0, 40 },
		{ 0, -16, 26 },
		{ -39, 79, 0 },
		{ 0, 0, 33 },
		{ 0, 0, 34 },
		{ 0, 0, 38 },
		{ 0, 0, 36 },
		{ 0, 0, 35 },
		{ 0, 0, 37 },
		{ 0, -29, 39 },
		{ 43, -41, 43 },
		{ 0, 9, 43 },
		{ 0, 0, 32 },
		{ 0, 43, 23 },
		{ 0, 67, 25 },
		{ 0, 69, 21 },
		{ 114, 0, 41 },
		{ 114, 17, 41 },
		{ 114, 105, 41 },
		{ 114, 114, 41 },
		{ 114, 124, 41 },
		{ 114, -97, 41 },
		{ 114, -94, 41 },
		{ 114, -71, 41 },
		{ 114, -90, 41 },
		{ 114, -73, 41 },
		{ 114, -81, 41 },
		{ 114, -61, 41 },
		{ 114, -48, 41 },
		{ 0, 0, 16 },
		{ 0, -47, 28 },
		{ 0, 0, 17 },
		{ 0, 0, 31 },
		{ 0, 0, 27 },
		{ 0, 39, 0 },
		{ 99, 0, 0 },
		{ -41, 78, 47 },
		{ 66, 0, 0 },
		{ 0, 32, 44 },
		{ 67, 0, 0 },
		{ 0, 0, 22 },
		{ 0, 0, 24 },
		{ 0, 0, 20 },
		{ 114, -6, 41 },
		{ 114, -1, 41 },
		{ 114, -19, 41 },
		{ 114, -16, 41 },
		{ 114, -11, 41 },
		{ 114, -12, 41 },
		{ 114, 0, 18 },
		{ 114, -93, 41 },
		{ 114, 3, 41 },
		{ 114, -11, 41 },
		{ 114, -7, 41 },
		{ 114, 7, 41 },
		{ 114, 8, 41 },
		{ 114, 9, 41 },
		{ 0, 0, 29 },
		{ 0, 0, 46 },
		{ -40, -32, 0 },
		{ 99, 87, 0 },
		{ 0, 19, 42 },
		{ 0, 145, 45 },
		{ 114, 35, 41 },
		{ 114, 19, 41 },
		{ 114, 36, 41 },
		{ 114, 60, 41 },
		{ 114, 65, 41 },
		{ 114, 0, 14 },
		{ 114, 55, 41 },
		{ 114, 47, 41 },
		{ 114, 0, 5 },
		{ 114, 56, 41 },
		{ 114, 91, 41 },
		{ 114, 87, 41 },
		{ 114, 89, 41 },
		{ 114, 106, 41 },
		{ 114, 99, 41 },
		{ 85, 161, 0 },
		{ 0, 0, 48 },
		{ 65, -27, 0 },
		{ 114, 109, 41 },
		{ 114, 0, 8 },
		{ 114, 109, 41 },
		{ 114, 0, 19 },
		{ 114, 102, 41 },
		{ 114, 102, 41 },
		{ 114, 104, 41 },
		{ 114, 0, 10 },
		{ 114, 104, 41 },
		{ 114, 108, 41 },
		{ 114, 124, 41 },
		{ 114, 0, 9 },
		{ 114, 123, 41 },
		{ -40, -25, 48 },
		{ 114, 0, 11 },
		{ 114, 125, 41 },
		{ 114, 0, 6 },
		{ 114, 127, 41 },
		{ 114, 0, 2 },
		{ 114, 112, 41 },
		{ 114, 119, 41 },
		{ 114, 126, 41 },
		{ 114, 0, 13 },
		{ 114, 0, 7 },
		{ 114, 130, 41 },
		{ 114, 0, 3 },
		{ 114, 0, 4 },
		{ 114, 0, 15 },
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
		0
	};
	yybackup = backup;
}
#line 259 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section


