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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 12/06/19
* Time: 21:26:40
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// myparser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR myparser : public _YL yyfparser {
public:
	myparser();
	virtual ~myparser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
#line 53 ".\\myparser.y"

	// place any extra class members here
    bool isDebug = false;


#line 71 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 70 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE Node* 
#endif

#line 84 "myparser.h"
#define MAIN 257
#define RETURN 258
#define INCLUDE 259
#define BREAK 260
#define INT 261
#define DOUBLE 262
#define FLOAT 263
#define CHAR 264
#define VOID 265
#define WHILE 266
#define SWITCH 267
#define FOR 268
#define LBRACE 269
#define RBRACE 270
#define IF 271
#define ELSE 272
#define ASSIGN 273
#define AND_BIT 274
#define AND 275
#define OR_BIT 276
#define OR 277
#define BNE 278
#define LNE 279
#define BE 280
#define LE 281
#define EQUAL 282
#define NOT_EQ 283
#define NOT 284
#define LINEEND 285
#define LPAREN 286
#define RPAREN 287
#define COMMA 288
#define ADD 289
#define SUB 290
#define MUL 291
#define DIV 292
#define MOD 293
#define ID 294
#define INT_NUMBER 295
#define FLOAT_NUMBER 296
#define OCT_NUMBER 297
#define HEX_NUMBER 298
#define CHARACTER 299
#define INPUT 300
#define OUTPUT 301
#define UMINUS 302
#endif
