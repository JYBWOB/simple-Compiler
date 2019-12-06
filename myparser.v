#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 58 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 12/06/19
# Time: 23:28:47
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : program $end

    1  program : MAIN LPAREN RPAREN LBRACE stmts RBRACE

    2  stmts : stmts stmt
    3        | stmt

    4  stmt : assign_stmt LINEEND
    5       | declare_stmt LINEEND
    6       | if_stmt
    7       | while_stmt
    8       | for_stmt
    9       | LBRACE stmts RBRACE
   10       | INPUT LPAREN ID RPAREN LINEEND
   11       | OUTPUT LPAREN expr RPAREN LINEEND
   12       | LINEEND

   13  assign_stmt : ID ASSIGN expr

   14  declare_stmt : var_type idList

   15  var_type : VOID
   16           | INT
   17           | FLOAT
   18           | DOUBLE
   19           | CHAR

   20  idList : ID COMMA idList
   21         | ID

   22  if_stmt : IF LPAREN expr RPAREN stmt ELSE stmt
   23          | IF LPAREN expr RPAREN stmt

   24  while_stmt : WHILE LPAREN expr RPAREN stmt

   25  for_stmt : FOR LPAREN expr LINEEND expr LINEEND expr RPAREN stmt
   26           | FOR LPAREN LINEEND expr LINEEND expr RPAREN stmt
   27           | FOR LPAREN expr LINEEND LINEEND expr RPAREN stmt
   28           | FOR LPAREN expr LINEEND expr LINEEND RPAREN stmt
   29           | FOR LPAREN LINEEND LINEEND expr RPAREN stmt
   30           | FOR LPAREN LINEEND expr LINEEND RPAREN stmt
   31           | FOR LPAREN expr LINEEND LINEEND RPAREN stmt
   32           | FOR LPAREN LINEEND LINEEND RPAREN stmt

   33  logical_expr :
   34               | expr BNE expr
   35               | expr BE expr
   36               | expr LNE expr
   37               | expr LE expr
   38               | expr EQUAL expr
   39               | expr NOT_EQ expr
   40               | expr AND expr
   41               | expr OR expr
   42               | NOT expr

   43  expr : expr ADD expr
   44       | expr SUB expr
   45       | expr MUL expr
   46       | expr DIV expr
   47       | expr MOD expr
   48       | expr AND_BIT expr
   49       | expr OR_BIT expr
   50       | LPAREN expr RPAREN
   51       | NUMBER
   52       | CHARACTER
   53       | ID
   54       | assign_stmt
   55       | logical_expr

   56  NUMBER : INT_NUMBER
   57         | FLOAT_NUMBER
   58         | HEX_NUMBER
   59         | OCT_NUMBER

   60  Grammar :


##############################################################################
# States
##############################################################################

state 0
	$accept : . program $end

	MAIN  shift 1

	program  goto 2


state 1
	program : MAIN . LPAREN RPAREN LBRACE stmts RBRACE

	LPAREN  shift 3


state 2
	$accept : program . $end  (0)

	$end  accept


state 3
	program : MAIN LPAREN . RPAREN LBRACE stmts RBRACE

	RPAREN  shift 4


state 4
	program : MAIN LPAREN RPAREN . LBRACE stmts RBRACE

	LBRACE  shift 5


state 5
	program : MAIN LPAREN RPAREN LBRACE . stmts RBRACE

	INT  shift 6
	DOUBLE  shift 7
	FLOAT  shift 8
	CHAR  shift 9
	VOID  shift 10
	WHILE  shift 11
	FOR  shift 12
	LBRACE  shift 13
	IF  shift 14
	LINEEND  shift 15
	ID  shift 16
	INPUT  shift 17
	OUTPUT  shift 18

	stmts  goto 19
	stmt  goto 20
	if_stmt  goto 21
	while_stmt  goto 22
	for_stmt  goto 23
	declare_stmt  goto 24
	assign_stmt  goto 25
	var_type  goto 26


state 6
	var_type : INT .  (16)

	.  reduce 16


state 7
	var_type : DOUBLE .  (18)

	.  reduce 18


state 8
	var_type : FLOAT .  (17)

	.  reduce 17


state 9
	var_type : CHAR .  (19)

	.  reduce 19


state 10
	var_type : VOID .  (15)

	.  reduce 15


state 11
	while_stmt : WHILE . LPAREN expr RPAREN stmt

	LPAREN  shift 27


state 12
	for_stmt : FOR . LPAREN expr LINEEND LINEEND RPAREN stmt
	for_stmt : FOR . LPAREN LINEEND LINEEND RPAREN stmt
	for_stmt : FOR . LPAREN expr LINEEND expr LINEEND expr RPAREN stmt
	for_stmt : FOR . LPAREN LINEEND LINEEND expr RPAREN stmt
	for_stmt : FOR . LPAREN LINEEND expr LINEEND RPAREN stmt
	for_stmt : FOR . LPAREN expr LINEEND LINEEND expr RPAREN stmt
	for_stmt : FOR . LPAREN expr LINEEND expr LINEEND RPAREN stmt
	for_stmt : FOR . LPAREN LINEEND expr LINEEND expr RPAREN stmt

	LPAREN  shift 28


state 13
	stmt : LBRACE . stmts RBRACE

	INT  shift 6
	DOUBLE  shift 7
	FLOAT  shift 8
	CHAR  shift 9
	VOID  shift 10
	WHILE  shift 11
	FOR  shift 12
	LBRACE  shift 13
	IF  shift 14
	LINEEND  shift 15
	ID  shift 16
	INPUT  shift 17
	OUTPUT  shift 18

	stmts  goto 29
	stmt  goto 20
	if_stmt  goto 21
	while_stmt  goto 22
	for_stmt  goto 23
	declare_stmt  goto 24
	assign_stmt  goto 25
	var_type  goto 26


state 14
	if_stmt : IF . LPAREN expr RPAREN stmt
	if_stmt : IF . LPAREN expr RPAREN stmt ELSE stmt

	LPAREN  shift 30


state 15
	stmt : LINEEND .  (12)

	.  reduce 12


state 16
	assign_stmt : ID . ASSIGN expr

	ASSIGN  shift 31


state 17
	stmt : INPUT . LPAREN ID RPAREN LINEEND

	LPAREN  shift 32


state 18
	stmt : OUTPUT . LPAREN expr RPAREN LINEEND

	LPAREN  shift 33


state 19
	program : MAIN LPAREN RPAREN LBRACE stmts . RBRACE
	stmts : stmts . stmt

	INT  shift 6
	DOUBLE  shift 7
	FLOAT  shift 8
	CHAR  shift 9
	VOID  shift 10
	WHILE  shift 11
	FOR  shift 12
	LBRACE  shift 13
	RBRACE  shift 34
	IF  shift 14
	LINEEND  shift 15
	ID  shift 16
	INPUT  shift 17
	OUTPUT  shift 18

	stmt  goto 35
	if_stmt  goto 21
	while_stmt  goto 22
	for_stmt  goto 23
	declare_stmt  goto 24
	assign_stmt  goto 25
	var_type  goto 26


state 20
	stmts : stmt .  (3)

	.  reduce 3


state 21
	stmt : if_stmt .  (6)

	.  reduce 6


state 22
	stmt : while_stmt .  (7)

	.  reduce 7


state 23
	stmt : for_stmt .  (8)

	.  reduce 8


state 24
	stmt : declare_stmt . LINEEND

	LINEEND  shift 36


state 25
	stmt : assign_stmt . LINEEND

	LINEEND  shift 37


state 26
	declare_stmt : var_type . idList

	ID  shift 38

	idList  goto 39


state 27
	while_stmt : WHILE LPAREN . expr RPAREN stmt
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 48
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


28: shift-reduce conflict (shift 52, reduce 33) on LINEEND
state 28
	for_stmt : FOR LPAREN . expr LINEEND LINEEND RPAREN stmt
	for_stmt : FOR LPAREN . LINEEND LINEEND RPAREN stmt
	for_stmt : FOR LPAREN . expr LINEEND expr LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN . LINEEND LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN . LINEEND expr LINEEND RPAREN stmt
	for_stmt : FOR LPAREN . expr LINEEND LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN . expr LINEEND expr LINEEND RPAREN stmt
	for_stmt : FOR LPAREN . LINEEND expr LINEEND expr RPAREN stmt
	logical_expr : .  (33)

	NOT  shift 40
	LINEEND  shift 52
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 53
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 29
	stmts : stmts . stmt
	stmt : LBRACE stmts . RBRACE

	INT  shift 6
	DOUBLE  shift 7
	FLOAT  shift 8
	CHAR  shift 9
	VOID  shift 10
	WHILE  shift 11
	FOR  shift 12
	LBRACE  shift 13
	RBRACE  shift 54
	IF  shift 14
	LINEEND  shift 15
	ID  shift 16
	INPUT  shift 17
	OUTPUT  shift 18

	stmt  goto 35
	if_stmt  goto 21
	while_stmt  goto 22
	for_stmt  goto 23
	declare_stmt  goto 24
	assign_stmt  goto 25
	var_type  goto 26


state 30
	if_stmt : IF LPAREN . expr RPAREN stmt
	if_stmt : IF LPAREN . expr RPAREN stmt ELSE stmt
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 55
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 31
	assign_stmt : ID ASSIGN . expr
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 56
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 32
	stmt : INPUT LPAREN . ID RPAREN LINEEND

	ID  shift 57


state 33
	stmt : OUTPUT LPAREN . expr RPAREN LINEEND
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 58
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 34
	program : MAIN LPAREN RPAREN LBRACE stmts RBRACE .  (1)

	.  reduce 1


state 35
	stmts : stmts stmt .  (2)

	.  reduce 2


state 36
	stmt : declare_stmt LINEEND .  (5)

	.  reduce 5


state 37
	stmt : assign_stmt LINEEND .  (4)

	.  reduce 4


state 38
	idList : ID . COMMA idList
	idList : ID .  (21)

	COMMA  shift 59
	.  reduce 21


state 39
	declare_stmt : var_type idList .  (14)

	.  reduce 14


state 40
	logical_expr : NOT . expr
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 60
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 41
	expr : LPAREN . expr RPAREN
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 61
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 42
	assign_stmt : ID . ASSIGN expr
	expr : ID .  (53)

	ASSIGN  shift 31
	.  reduce 53


state 43
	NUMBER : INT_NUMBER .  (56)

	.  reduce 56


state 44
	NUMBER : FLOAT_NUMBER .  (57)

	.  reduce 57


state 45
	NUMBER : OCT_NUMBER .  (59)

	.  reduce 59


state 46
	NUMBER : HEX_NUMBER .  (58)

	.  reduce 58


state 47
	expr : CHARACTER .  (52)

	.  reduce 52


state 48
	while_stmt : WHILE LPAREN expr . RPAREN stmt
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	AND_BIT  shift 62
	AND  shift 63
	OR_BIT  shift 64
	OR  shift 65
	BNE  shift 66
	LNE  shift 67
	BE  shift 68
	LE  shift 69
	EQUAL  shift 70
	NOT_EQ  shift 71
	RPAREN  shift 72
	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77


state 49
	expr : assign_stmt .  (54)

	.  reduce 54


state 50
	expr : NUMBER .  (51)

	.  reduce 51


state 51
	expr : logical_expr .  (55)

	.  reduce 55


52: shift-reduce conflict (shift 78, reduce 33) on LINEEND
state 52
	for_stmt : FOR LPAREN LINEEND . LINEEND RPAREN stmt
	for_stmt : FOR LPAREN LINEEND . LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN LINEEND . expr LINEEND RPAREN stmt
	for_stmt : FOR LPAREN LINEEND . expr LINEEND expr RPAREN stmt
	logical_expr : .  (33)

	NOT  shift 40
	LINEEND  shift 78
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 79
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 53
	for_stmt : FOR LPAREN expr . LINEEND LINEEND RPAREN stmt
	for_stmt : FOR LPAREN expr . LINEEND expr LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN expr . LINEEND LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN expr . LINEEND expr LINEEND RPAREN stmt
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	AND_BIT  shift 62
	AND  shift 63
	OR_BIT  shift 64
	OR  shift 65
	BNE  shift 66
	LNE  shift 67
	BE  shift 68
	LE  shift 69
	EQUAL  shift 70
	NOT_EQ  shift 71
	LINEEND  shift 80
	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77


state 54
	stmt : LBRACE stmts RBRACE .  (9)

	.  reduce 9


state 55
	if_stmt : IF LPAREN expr . RPAREN stmt
	if_stmt : IF LPAREN expr . RPAREN stmt ELSE stmt
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	AND_BIT  shift 62
	AND  shift 63
	OR_BIT  shift 64
	OR  shift 65
	BNE  shift 66
	LNE  shift 67
	BE  shift 68
	LE  shift 69
	EQUAL  shift 70
	NOT_EQ  shift 71
	RPAREN  shift 81
	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77


state 56
	assign_stmt : ID ASSIGN expr .  (13)
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	AND_BIT  shift 62
	AND  shift 63
	OR_BIT  shift 64
	OR  shift 65
	BNE  shift 66
	LNE  shift 67
	BE  shift 68
	LE  shift 69
	EQUAL  shift 70
	NOT_EQ  shift 71
	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77
	.  reduce 13


state 57
	stmt : INPUT LPAREN ID . RPAREN LINEEND

	RPAREN  shift 82


state 58
	stmt : OUTPUT LPAREN expr . RPAREN LINEEND
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	AND_BIT  shift 62
	AND  shift 63
	OR_BIT  shift 64
	OR  shift 65
	BNE  shift 66
	LNE  shift 67
	BE  shift 68
	LE  shift 69
	EQUAL  shift 70
	NOT_EQ  shift 71
	RPAREN  shift 83
	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77


state 59
	idList : ID COMMA . idList

	ID  shift 38

	idList  goto 84


state 60
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : NOT expr .  (42)
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77
	.  reduce 42


state 61
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	expr : LPAREN expr . RPAREN
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	AND_BIT  shift 62
	AND  shift 63
	OR_BIT  shift 64
	OR  shift 65
	BNE  shift 66
	LNE  shift 67
	BE  shift 68
	LE  shift 69
	EQUAL  shift 70
	NOT_EQ  shift 71
	RPAREN  shift 85
	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77


state 62
	expr : expr AND_BIT . expr
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 86
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 63
	logical_expr : expr AND . expr
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 87
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 64
	expr : expr OR_BIT . expr
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 88
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 65
	logical_expr : expr OR . expr
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 89
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 66
	logical_expr : expr BNE . expr
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 90
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 67
	logical_expr : expr LNE . expr
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 91
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 68
	logical_expr : expr BE . expr
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 92
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 69
	logical_expr : expr LE . expr
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 93
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 70
	logical_expr : expr EQUAL . expr
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 94
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 71
	logical_expr : expr NOT_EQ . expr
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 95
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 72
	while_stmt : WHILE LPAREN expr RPAREN . stmt

	INT  shift 6
	DOUBLE  shift 7
	FLOAT  shift 8
	CHAR  shift 9
	VOID  shift 10
	WHILE  shift 11
	FOR  shift 12
	LBRACE  shift 13
	IF  shift 14
	LINEEND  shift 15
	ID  shift 16
	INPUT  shift 17
	OUTPUT  shift 18

	stmt  goto 96
	if_stmt  goto 21
	while_stmt  goto 22
	for_stmt  goto 23
	declare_stmt  goto 24
	assign_stmt  goto 25
	var_type  goto 26


state 73
	expr : expr ADD . expr
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 97
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 74
	expr : expr SUB . expr
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 98
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 75
	expr : expr MUL . expr
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 99
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 76
	expr : expr DIV . expr
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 100
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 77
	expr : expr MOD . expr
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 101
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


78: shift-reduce conflict (shift 102, reduce 33) on RPAREN
state 78
	for_stmt : FOR LPAREN LINEEND LINEEND . RPAREN stmt
	for_stmt : FOR LPAREN LINEEND LINEEND . expr RPAREN stmt
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	RPAREN  shift 102
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 103
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 79
	for_stmt : FOR LPAREN LINEEND expr . LINEEND RPAREN stmt
	for_stmt : FOR LPAREN LINEEND expr . LINEEND expr RPAREN stmt
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	AND_BIT  shift 62
	AND  shift 63
	OR_BIT  shift 64
	OR  shift 65
	BNE  shift 66
	LNE  shift 67
	BE  shift 68
	LE  shift 69
	EQUAL  shift 70
	NOT_EQ  shift 71
	LINEEND  shift 104
	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77


80: shift-reduce conflict (shift 105, reduce 33) on LINEEND
state 80
	for_stmt : FOR LPAREN expr LINEEND . LINEEND RPAREN stmt
	for_stmt : FOR LPAREN expr LINEEND . expr LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN expr LINEEND . LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN expr LINEEND . expr LINEEND RPAREN stmt
	logical_expr : .  (33)

	NOT  shift 40
	LINEEND  shift 105
	LPAREN  shift 41
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 106
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 81
	if_stmt : IF LPAREN expr RPAREN . stmt
	if_stmt : IF LPAREN expr RPAREN . stmt ELSE stmt

	INT  shift 6
	DOUBLE  shift 7
	FLOAT  shift 8
	CHAR  shift 9
	VOID  shift 10
	WHILE  shift 11
	FOR  shift 12
	LBRACE  shift 13
	IF  shift 14
	LINEEND  shift 15
	ID  shift 16
	INPUT  shift 17
	OUTPUT  shift 18

	stmt  goto 107
	if_stmt  goto 21
	while_stmt  goto 22
	for_stmt  goto 23
	declare_stmt  goto 24
	assign_stmt  goto 25
	var_type  goto 26


state 82
	stmt : INPUT LPAREN ID RPAREN . LINEEND

	LINEEND  shift 108


state 83
	stmt : OUTPUT LPAREN expr RPAREN . LINEEND

	LINEEND  shift 109


state 84
	idList : ID COMMA idList .  (20)

	.  reduce 20


state 85
	expr : LPAREN expr RPAREN .  (50)

	.  reduce 50


state 86
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr AND_BIT expr .  (48)
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	BNE  shift 66
	LNE  shift 67
	BE  shift 68
	LE  shift 69
	EQUAL  shift 70
	NOT_EQ  shift 71
	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77
	.  reduce 48


state 87
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr AND expr .  (40)
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	BNE  shift 66
	LNE  shift 67
	BE  shift 68
	LE  shift 69
	EQUAL  shift 70
	NOT_EQ  shift 71
	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77
	.  reduce 40


state 88
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr OR_BIT expr .  (49)
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	AND_BIT  shift 62
	AND  shift 63
	BNE  shift 66
	LNE  shift 67
	BE  shift 68
	LE  shift 69
	EQUAL  shift 70
	NOT_EQ  shift 71
	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77
	.  reduce 49


state 89
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr OR expr .  (41)
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	AND_BIT  shift 62
	AND  shift 63
	BNE  shift 66
	LNE  shift 67
	BE  shift 68
	LE  shift 69
	EQUAL  shift 70
	NOT_EQ  shift 71
	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77
	.  reduce 41


state 90
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr BNE expr .  (34)
	logical_expr : expr . BNE expr

	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77
	.  reduce 34


state 91
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr LNE expr .  (36)
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77
	.  reduce 36


state 92
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr BE expr .  (35)
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77
	.  reduce 35


state 93
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr LE expr .  (37)
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77
	.  reduce 37


state 94
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr EQUAL expr .  (38)
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77
	.  reduce 38


state 95
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr NOT_EQ expr .  (39)
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77
	.  reduce 39


state 96
	while_stmt : WHILE LPAREN expr RPAREN stmt .  (24)

	.  reduce 24


state 97
	expr : expr . SUB expr
	expr : expr ADD expr .  (43)
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	MUL  shift 75
	DIV  shift 76
	MOD  shift 77
	.  reduce 43


state 98
	expr : expr SUB expr .  (44)
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	MUL  shift 75
	DIV  shift 76
	MOD  shift 77
	.  reduce 44


state 99
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr MUL expr .  (45)
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	.  reduce 45


state 100
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr DIV expr .  (46)
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	.  reduce 46


state 101
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr MOD expr .  (47)
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	.  reduce 47


state 102
	for_stmt : FOR LPAREN LINEEND LINEEND RPAREN . stmt

	INT  shift 6
	DOUBLE  shift 7
	FLOAT  shift 8
	CHAR  shift 9
	VOID  shift 10
	WHILE  shift 11
	FOR  shift 12
	LBRACE  shift 13
	IF  shift 14
	LINEEND  shift 15
	ID  shift 16
	INPUT  shift 17
	OUTPUT  shift 18

	stmt  goto 110
	if_stmt  goto 21
	while_stmt  goto 22
	for_stmt  goto 23
	declare_stmt  goto 24
	assign_stmt  goto 25
	var_type  goto 26


state 103
	for_stmt : FOR LPAREN LINEEND LINEEND expr . RPAREN stmt
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	AND_BIT  shift 62
	AND  shift 63
	OR_BIT  shift 64
	OR  shift 65
	BNE  shift 66
	LNE  shift 67
	BE  shift 68
	LE  shift 69
	EQUAL  shift 70
	NOT_EQ  shift 71
	RPAREN  shift 111
	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77


104: shift-reduce conflict (shift 112, reduce 33) on RPAREN
state 104
	for_stmt : FOR LPAREN LINEEND expr LINEEND . RPAREN stmt
	for_stmt : FOR LPAREN LINEEND expr LINEEND . expr RPAREN stmt
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	RPAREN  shift 112
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 113
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


105: shift-reduce conflict (shift 114, reduce 33) on RPAREN
state 105
	for_stmt : FOR LPAREN expr LINEEND LINEEND . RPAREN stmt
	for_stmt : FOR LPAREN expr LINEEND LINEEND . expr RPAREN stmt
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	RPAREN  shift 114
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 115
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 106
	for_stmt : FOR LPAREN expr LINEEND expr . LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN expr LINEEND expr . LINEEND RPAREN stmt
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	AND_BIT  shift 62
	AND  shift 63
	OR_BIT  shift 64
	OR  shift 65
	BNE  shift 66
	LNE  shift 67
	BE  shift 68
	LE  shift 69
	EQUAL  shift 70
	NOT_EQ  shift 71
	LINEEND  shift 116
	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77


107: shift-reduce conflict (shift 117, reduce 23) on ELSE
state 107
	if_stmt : IF LPAREN expr RPAREN stmt .  (23)
	if_stmt : IF LPAREN expr RPAREN stmt . ELSE stmt

	ELSE  shift 117
	.  reduce 23


state 108
	stmt : INPUT LPAREN ID RPAREN LINEEND .  (10)

	.  reduce 10


state 109
	stmt : OUTPUT LPAREN expr RPAREN LINEEND .  (11)

	.  reduce 11


state 110
	for_stmt : FOR LPAREN LINEEND LINEEND RPAREN stmt .  (32)

	.  reduce 32


state 111
	for_stmt : FOR LPAREN LINEEND LINEEND expr RPAREN . stmt

	INT  shift 6
	DOUBLE  shift 7
	FLOAT  shift 8
	CHAR  shift 9
	VOID  shift 10
	WHILE  shift 11
	FOR  shift 12
	LBRACE  shift 13
	IF  shift 14
	LINEEND  shift 15
	ID  shift 16
	INPUT  shift 17
	OUTPUT  shift 18

	stmt  goto 118
	if_stmt  goto 21
	while_stmt  goto 22
	for_stmt  goto 23
	declare_stmt  goto 24
	assign_stmt  goto 25
	var_type  goto 26


state 112
	for_stmt : FOR LPAREN LINEEND expr LINEEND RPAREN . stmt

	INT  shift 6
	DOUBLE  shift 7
	FLOAT  shift 8
	CHAR  shift 9
	VOID  shift 10
	WHILE  shift 11
	FOR  shift 12
	LBRACE  shift 13
	IF  shift 14
	LINEEND  shift 15
	ID  shift 16
	INPUT  shift 17
	OUTPUT  shift 18

	stmt  goto 119
	if_stmt  goto 21
	while_stmt  goto 22
	for_stmt  goto 23
	declare_stmt  goto 24
	assign_stmt  goto 25
	var_type  goto 26


state 113
	for_stmt : FOR LPAREN LINEEND expr LINEEND expr . RPAREN stmt
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	AND_BIT  shift 62
	AND  shift 63
	OR_BIT  shift 64
	OR  shift 65
	BNE  shift 66
	LNE  shift 67
	BE  shift 68
	LE  shift 69
	EQUAL  shift 70
	NOT_EQ  shift 71
	RPAREN  shift 120
	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77


state 114
	for_stmt : FOR LPAREN expr LINEEND LINEEND RPAREN . stmt

	INT  shift 6
	DOUBLE  shift 7
	FLOAT  shift 8
	CHAR  shift 9
	VOID  shift 10
	WHILE  shift 11
	FOR  shift 12
	LBRACE  shift 13
	IF  shift 14
	LINEEND  shift 15
	ID  shift 16
	INPUT  shift 17
	OUTPUT  shift 18

	stmt  goto 121
	if_stmt  goto 21
	while_stmt  goto 22
	for_stmt  goto 23
	declare_stmt  goto 24
	assign_stmt  goto 25
	var_type  goto 26


state 115
	for_stmt : FOR LPAREN expr LINEEND LINEEND expr . RPAREN stmt
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	AND_BIT  shift 62
	AND  shift 63
	OR_BIT  shift 64
	OR  shift 65
	BNE  shift 66
	LNE  shift 67
	BE  shift 68
	LE  shift 69
	EQUAL  shift 70
	NOT_EQ  shift 71
	RPAREN  shift 122
	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77


116: shift-reduce conflict (shift 123, reduce 33) on RPAREN
state 116
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND . expr RPAREN stmt
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND . RPAREN stmt
	logical_expr : .  (33)

	NOT  shift 40
	LPAREN  shift 41
	RPAREN  shift 123
	ID  shift 42
	INT_NUMBER  shift 43
	FLOAT_NUMBER  shift 44
	OCT_NUMBER  shift 45
	HEX_NUMBER  shift 46
	CHARACTER  shift 47
	.  reduce 33

	expr  goto 124
	assign_stmt  goto 49
	NUMBER  goto 50
	logical_expr  goto 51


state 117
	if_stmt : IF LPAREN expr RPAREN stmt ELSE . stmt

	INT  shift 6
	DOUBLE  shift 7
	FLOAT  shift 8
	CHAR  shift 9
	VOID  shift 10
	WHILE  shift 11
	FOR  shift 12
	LBRACE  shift 13
	IF  shift 14
	LINEEND  shift 15
	ID  shift 16
	INPUT  shift 17
	OUTPUT  shift 18

	stmt  goto 125
	if_stmt  goto 21
	while_stmt  goto 22
	for_stmt  goto 23
	declare_stmt  goto 24
	assign_stmt  goto 25
	var_type  goto 26


state 118
	for_stmt : FOR LPAREN LINEEND LINEEND expr RPAREN stmt .  (29)

	.  reduce 29


state 119
	for_stmt : FOR LPAREN LINEEND expr LINEEND RPAREN stmt .  (30)

	.  reduce 30


state 120
	for_stmt : FOR LPAREN LINEEND expr LINEEND expr RPAREN . stmt

	INT  shift 6
	DOUBLE  shift 7
	FLOAT  shift 8
	CHAR  shift 9
	VOID  shift 10
	WHILE  shift 11
	FOR  shift 12
	LBRACE  shift 13
	IF  shift 14
	LINEEND  shift 15
	ID  shift 16
	INPUT  shift 17
	OUTPUT  shift 18

	stmt  goto 126
	if_stmt  goto 21
	while_stmt  goto 22
	for_stmt  goto 23
	declare_stmt  goto 24
	assign_stmt  goto 25
	var_type  goto 26


state 121
	for_stmt : FOR LPAREN expr LINEEND LINEEND RPAREN stmt .  (31)

	.  reduce 31


state 122
	for_stmt : FOR LPAREN expr LINEEND LINEEND expr RPAREN . stmt

	INT  shift 6
	DOUBLE  shift 7
	FLOAT  shift 8
	CHAR  shift 9
	VOID  shift 10
	WHILE  shift 11
	FOR  shift 12
	LBRACE  shift 13
	IF  shift 14
	LINEEND  shift 15
	ID  shift 16
	INPUT  shift 17
	OUTPUT  shift 18

	stmt  goto 127
	if_stmt  goto 21
	while_stmt  goto 22
	for_stmt  goto 23
	declare_stmt  goto 24
	assign_stmt  goto 25
	var_type  goto 26


state 123
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND RPAREN . stmt

	INT  shift 6
	DOUBLE  shift 7
	FLOAT  shift 8
	CHAR  shift 9
	VOID  shift 10
	WHILE  shift 11
	FOR  shift 12
	LBRACE  shift 13
	IF  shift 14
	LINEEND  shift 15
	ID  shift 16
	INPUT  shift 17
	OUTPUT  shift 18

	stmt  goto 128
	if_stmt  goto 21
	while_stmt  goto 22
	for_stmt  goto 23
	declare_stmt  goto 24
	assign_stmt  goto 25
	var_type  goto 26


state 124
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND expr . RPAREN stmt
	expr : expr . SUB expr
	expr : expr . ADD expr
	logical_expr : expr . BE expr
	expr : expr . DIV expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . LE expr
	expr : expr . MUL expr
	logical_expr : expr . AND expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MOD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . LNE expr
	logical_expr : expr . BNE expr

	AND_BIT  shift 62
	AND  shift 63
	OR_BIT  shift 64
	OR  shift 65
	BNE  shift 66
	LNE  shift 67
	BE  shift 68
	LE  shift 69
	EQUAL  shift 70
	NOT_EQ  shift 71
	RPAREN  shift 129
	ADD  shift 73
	SUB  shift 74
	MUL  shift 75
	DIV  shift 76
	MOD  shift 77


state 125
	if_stmt : IF LPAREN expr RPAREN stmt ELSE stmt .  (22)

	.  reduce 22


state 126
	for_stmt : FOR LPAREN LINEEND expr LINEEND expr RPAREN stmt .  (26)

	.  reduce 26


state 127
	for_stmt : FOR LPAREN expr LINEEND LINEEND expr RPAREN stmt .  (27)

	.  reduce 27


state 128
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND RPAREN stmt .  (28)

	.  reduce 28


state 129
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND expr RPAREN . stmt

	INT  shift 6
	DOUBLE  shift 7
	FLOAT  shift 8
	CHAR  shift 9
	VOID  shift 10
	WHILE  shift 11
	FOR  shift 12
	LBRACE  shift 13
	IF  shift 14
	LINEEND  shift 15
	ID  shift 16
	INPUT  shift 17
	OUTPUT  shift 18

	stmt  goto 130
	if_stmt  goto 21
	while_stmt  goto 22
	for_stmt  goto 23
	declare_stmt  goto 24
	assign_stmt  goto 25
	var_type  goto 26


state 130
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND expr RPAREN stmt .  (25)

	.  reduce 25


Rules never reduced
	Grammar :  (60)


##############################################################################
# Summary
##############################################################################

State 28 contains 1 shift-reduce conflict(s)
State 52 contains 1 shift-reduce conflict(s)
State 78 contains 1 shift-reduce conflict(s)
State 80 contains 1 shift-reduce conflict(s)
State 104 contains 1 shift-reduce conflict(s)
State 105 contains 1 shift-reduce conflict(s)
State 107 contains 1 shift-reduce conflict(s)
State 116 contains 1 shift-reduce conflict(s)


43 token(s), 15 nonterminal(s)
61 grammar rule(s), 131 state(s)


##############################################################################
# End of File
##############################################################################
