#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 60 of your 30 day trial period.
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
# Date: 12/08/19
# Time: 21:36:00
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
   11       | INPUT LPAREN ArrID RPAREN LINEEND
   12       | OUTPUT LPAREN expr RPAREN LINEEND
   13       | LINEEND

   14  assign_stmt : ID ASSIGN expr
   15              | ArrID ASSIGN expr

   16  declare_stmt : var_type idList

   17  var_type : VOID
   18           | INT
   19           | FLOAT
   20           | DOUBLE
   21           | CHAR

   22  idList : ID COMMA idList
   23         | ID
   24         | ArrID
   25         | ArrID COMMA idList

   26  if_stmt : IF LPAREN expr RPAREN stmt ELSE stmt
   27          | IF LPAREN expr RPAREN stmt

   28  while_stmt : WHILE LPAREN expr RPAREN stmt

   29  for_stmt : FOR LPAREN expr LINEEND expr LINEEND expr RPAREN stmt
   30           | FOR LPAREN LINEEND expr LINEEND expr RPAREN stmt
   31           | FOR LPAREN expr LINEEND LINEEND expr RPAREN stmt
   32           | FOR LPAREN expr LINEEND expr LINEEND RPAREN stmt
   33           | FOR LPAREN LINEEND LINEEND expr RPAREN stmt
   34           | FOR LPAREN LINEEND expr LINEEND RPAREN stmt
   35           | FOR LPAREN expr LINEEND LINEEND RPAREN stmt
   36           | FOR LPAREN LINEEND LINEEND RPAREN stmt

   37  logical_expr :
   38               | expr BNE expr
   39               | expr BE expr
   40               | expr LNE expr
   41               | expr LE expr
   42               | expr EQUAL expr
   43               | expr NOT_EQ expr
   44               | expr AND expr
   45               | expr OR expr
   46               | NOT expr

   47  expr : expr ADD expr
   48       | expr SUB expr
   49       | expr MUL expr
   50       | expr DIV expr
   51       | expr MOD expr
   52       | expr AND_BIT expr
   53       | expr OR_BIT expr
   54       | LPAREN expr RPAREN
   55       | NUMBER
   56       | CHARACTER
   57       | ID
   58       | ArrID
   59       | assign_stmt
   60       | logical_expr

   61  ArrID : ID LFPA expr RFPA

   62  NUMBER : INT_NUMBER
   63         | FLOAT_NUMBER
   64         | HEX_NUMBER
   65         | OCT_NUMBER

   66  Grammar :


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

	var_type  goto 19
	for_stmt  goto 20
	if_stmt  goto 21
	ArrID  goto 22
	assign_stmt  goto 23
	declare_stmt  goto 24
	while_stmt  goto 25
	stmt  goto 26
	stmts  goto 27


state 6
	var_type : INT .  (18)

	.  reduce 18


state 7
	var_type : DOUBLE .  (20)

	.  reduce 20


state 8
	var_type : FLOAT .  (19)

	.  reduce 19


state 9
	var_type : CHAR .  (21)

	.  reduce 21


state 10
	var_type : VOID .  (17)

	.  reduce 17


state 11
	while_stmt : WHILE . LPAREN expr RPAREN stmt

	LPAREN  shift 28


state 12
	for_stmt : FOR . LPAREN LINEEND LINEEND expr RPAREN stmt
	for_stmt : FOR . LPAREN expr LINEEND expr LINEEND expr RPAREN stmt
	for_stmt : FOR . LPAREN LINEEND expr LINEEND expr RPAREN stmt
	for_stmt : FOR . LPAREN expr LINEEND LINEEND expr RPAREN stmt
	for_stmt : FOR . LPAREN expr LINEEND expr LINEEND RPAREN stmt
	for_stmt : FOR . LPAREN LINEEND expr LINEEND RPAREN stmt
	for_stmt : FOR . LPAREN expr LINEEND LINEEND RPAREN stmt
	for_stmt : FOR . LPAREN LINEEND LINEEND RPAREN stmt

	LPAREN  shift 29


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

	var_type  goto 19
	for_stmt  goto 20
	if_stmt  goto 21
	ArrID  goto 22
	assign_stmt  goto 23
	declare_stmt  goto 24
	while_stmt  goto 25
	stmt  goto 26
	stmts  goto 30


state 14
	if_stmt : IF . LPAREN expr RPAREN stmt ELSE stmt
	if_stmt : IF . LPAREN expr RPAREN stmt

	LPAREN  shift 31


state 15
	stmt : LINEEND .  (13)

	.  reduce 13


state 16
	ArrID : ID . LFPA expr RFPA
	assign_stmt : ID . ASSIGN expr

	ASSIGN  shift 32
	LFPA  shift 33


state 17
	stmt : INPUT . LPAREN ID RPAREN LINEEND
	stmt : INPUT . LPAREN ArrID RPAREN LINEEND

	LPAREN  shift 34


state 18
	stmt : OUTPUT . LPAREN expr RPAREN LINEEND

	LPAREN  shift 35


state 19
	declare_stmt : var_type . idList

	ID  shift 36

	idList  goto 37
	ArrID  goto 38


state 20
	stmt : for_stmt .  (8)

	.  reduce 8


state 21
	stmt : if_stmt .  (6)

	.  reduce 6


state 22
	assign_stmt : ArrID . ASSIGN expr

	ASSIGN  shift 39


state 23
	stmt : assign_stmt . LINEEND

	LINEEND  shift 40


state 24
	stmt : declare_stmt . LINEEND

	LINEEND  shift 41


state 25
	stmt : while_stmt .  (7)

	.  reduce 7


state 26
	stmts : stmt .  (3)

	.  reduce 3


state 27
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
	RBRACE  shift 42
	IF  shift 14
	LINEEND  shift 15
	ID  shift 16
	INPUT  shift 17
	OUTPUT  shift 18

	var_type  goto 19
	for_stmt  goto 20
	if_stmt  goto 21
	ArrID  goto 22
	assign_stmt  goto 23
	declare_stmt  goto 24
	while_stmt  goto 25
	stmt  goto 43


state 28
	while_stmt : WHILE LPAREN . expr RPAREN stmt
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 54
	ArrID  goto 55
	assign_stmt  goto 56


29: shift-reduce conflict (shift 57, reduce 37) on LINEEND
state 29
	for_stmt : FOR LPAREN . LINEEND LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN . expr LINEEND expr LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN . LINEEND expr LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN . expr LINEEND LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN . expr LINEEND expr LINEEND RPAREN stmt
	for_stmt : FOR LPAREN . LINEEND expr LINEEND RPAREN stmt
	for_stmt : FOR LPAREN . expr LINEEND LINEEND RPAREN stmt
	for_stmt : FOR LPAREN . LINEEND LINEEND RPAREN stmt
	logical_expr : .  (37)

	NOT  shift 44
	LINEEND  shift 57
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 58
	ArrID  goto 55
	assign_stmt  goto 56


state 30
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
	RBRACE  shift 59
	IF  shift 14
	LINEEND  shift 15
	ID  shift 16
	INPUT  shift 17
	OUTPUT  shift 18

	var_type  goto 19
	for_stmt  goto 20
	if_stmt  goto 21
	ArrID  goto 22
	assign_stmt  goto 23
	declare_stmt  goto 24
	while_stmt  goto 25
	stmt  goto 43


state 31
	if_stmt : IF LPAREN . expr RPAREN stmt ELSE stmt
	if_stmt : IF LPAREN . expr RPAREN stmt
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 60
	ArrID  goto 55
	assign_stmt  goto 56


state 32
	assign_stmt : ID ASSIGN . expr
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 61
	ArrID  goto 55
	assign_stmt  goto 56


state 33
	ArrID : ID LFPA . expr RFPA
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 62
	ArrID  goto 55
	assign_stmt  goto 56


state 34
	stmt : INPUT LPAREN . ID RPAREN LINEEND
	stmt : INPUT LPAREN . ArrID RPAREN LINEEND

	ID  shift 63

	ArrID  goto 64


state 35
	stmt : OUTPUT LPAREN . expr RPAREN LINEEND
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 65
	ArrID  goto 55
	assign_stmt  goto 56


state 36
	idList : ID .  (23)
	idList : ID . COMMA idList
	ArrID : ID . LFPA expr RFPA

	COMMA  shift 66
	LFPA  shift 33
	.  reduce 23


state 37
	declare_stmt : var_type idList .  (16)

	.  reduce 16


state 38
	idList : ArrID . COMMA idList
	idList : ArrID .  (24)

	COMMA  shift 67
	.  reduce 24


state 39
	assign_stmt : ArrID ASSIGN . expr
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 68
	ArrID  goto 55
	assign_stmt  goto 56


state 40
	stmt : assign_stmt LINEEND .  (4)

	.  reduce 4


state 41
	stmt : declare_stmt LINEEND .  (5)

	.  reduce 5


state 42
	program : MAIN LPAREN RPAREN LBRACE stmts RBRACE .  (1)

	.  reduce 1


state 43
	stmts : stmts stmt .  (2)

	.  reduce 2


state 44
	logical_expr : NOT . expr
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 69
	ArrID  goto 55
	assign_stmt  goto 56


state 45
	expr : LPAREN . expr RPAREN
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 70
	ArrID  goto 55
	assign_stmt  goto 56


state 46
	expr : ID .  (57)
	ArrID : ID . LFPA expr RFPA
	assign_stmt : ID . ASSIGN expr

	ASSIGN  shift 32
	LFPA  shift 33
	.  reduce 57


state 47
	NUMBER : INT_NUMBER .  (62)

	.  reduce 62


state 48
	NUMBER : FLOAT_NUMBER .  (63)

	.  reduce 63


state 49
	NUMBER : OCT_NUMBER .  (65)

	.  reduce 65


state 50
	NUMBER : HEX_NUMBER .  (64)

	.  reduce 64


state 51
	expr : CHARACTER .  (56)

	.  reduce 56


state 52
	expr : logical_expr .  (60)

	.  reduce 60


state 53
	expr : NUMBER .  (55)

	.  reduce 55


state 54
	while_stmt : WHILE LPAREN expr . RPAREN stmt
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	AND_BIT  shift 71
	AND  shift 72
	OR_BIT  shift 73
	OR  shift 74
	BNE  shift 75
	LNE  shift 76
	BE  shift 77
	LE  shift 78
	EQUAL  shift 79
	NOT_EQ  shift 80
	RPAREN  shift 81
	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86


state 55
	expr : ArrID .  (58)
	assign_stmt : ArrID . ASSIGN expr

	ASSIGN  shift 39
	.  reduce 58


state 56
	expr : assign_stmt .  (59)

	.  reduce 59


57: shift-reduce conflict (shift 87, reduce 37) on LINEEND
state 57
	for_stmt : FOR LPAREN LINEEND . LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN LINEEND . expr LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN LINEEND . expr LINEEND RPAREN stmt
	for_stmt : FOR LPAREN LINEEND . LINEEND RPAREN stmt
	logical_expr : .  (37)

	NOT  shift 44
	LINEEND  shift 87
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 88
	ArrID  goto 55
	assign_stmt  goto 56


state 58
	for_stmt : FOR LPAREN expr . LINEEND expr LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN expr . LINEEND LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN expr . LINEEND expr LINEEND RPAREN stmt
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	for_stmt : FOR LPAREN expr . LINEEND LINEEND RPAREN stmt
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	AND_BIT  shift 71
	AND  shift 72
	OR_BIT  shift 73
	OR  shift 74
	BNE  shift 75
	LNE  shift 76
	BE  shift 77
	LE  shift 78
	EQUAL  shift 79
	NOT_EQ  shift 80
	LINEEND  shift 89
	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86


state 59
	stmt : LBRACE stmts RBRACE .  (9)

	.  reduce 9


state 60
	if_stmt : IF LPAREN expr . RPAREN stmt ELSE stmt
	if_stmt : IF LPAREN expr . RPAREN stmt
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	AND_BIT  shift 71
	AND  shift 72
	OR_BIT  shift 73
	OR  shift 74
	BNE  shift 75
	LNE  shift 76
	BE  shift 77
	LE  shift 78
	EQUAL  shift 79
	NOT_EQ  shift 80
	RPAREN  shift 90
	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86


state 61
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr
	assign_stmt : ID ASSIGN expr .  (14)

	AND_BIT  shift 71
	AND  shift 72
	OR_BIT  shift 73
	OR  shift 74
	BNE  shift 75
	LNE  shift 76
	BE  shift 77
	LE  shift 78
	EQUAL  shift 79
	NOT_EQ  shift 80
	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86
	.  reduce 14


state 62
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	ArrID : ID LFPA expr . RFPA
	logical_expr : expr . BE expr

	AND_BIT  shift 71
	AND  shift 72
	OR_BIT  shift 73
	OR  shift 74
	BNE  shift 75
	LNE  shift 76
	BE  shift 77
	LE  shift 78
	EQUAL  shift 79
	NOT_EQ  shift 80
	RFPA  shift 91
	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86


state 63
	ArrID : ID . LFPA expr RFPA
	stmt : INPUT LPAREN ID . RPAREN LINEEND

	RPAREN  shift 92
	LFPA  shift 33


state 64
	stmt : INPUT LPAREN ArrID . RPAREN LINEEND

	RPAREN  shift 93


state 65
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr
	stmt : OUTPUT LPAREN expr . RPAREN LINEEND

	AND_BIT  shift 71
	AND  shift 72
	OR_BIT  shift 73
	OR  shift 74
	BNE  shift 75
	LNE  shift 76
	BE  shift 77
	LE  shift 78
	EQUAL  shift 79
	NOT_EQ  shift 80
	RPAREN  shift 94
	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86


state 66
	idList : ID COMMA . idList

	ID  shift 36

	idList  goto 95
	ArrID  goto 38


state 67
	idList : ArrID COMMA . idList

	ID  shift 36

	idList  goto 96
	ArrID  goto 38


state 68
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr
	assign_stmt : ArrID ASSIGN expr .  (15)

	AND_BIT  shift 71
	AND  shift 72
	OR_BIT  shift 73
	OR  shift 74
	BNE  shift 75
	LNE  shift 76
	BE  shift 77
	LE  shift 78
	EQUAL  shift 79
	NOT_EQ  shift 80
	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86
	.  reduce 15


state 69
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	logical_expr : NOT expr .  (46)
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86
	.  reduce 46


state 70
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : LPAREN expr . RPAREN
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	AND_BIT  shift 71
	AND  shift 72
	OR_BIT  shift 73
	OR  shift 74
	BNE  shift 75
	LNE  shift 76
	BE  shift 77
	LE  shift 78
	EQUAL  shift 79
	NOT_EQ  shift 80
	RPAREN  shift 97
	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86


state 71
	expr : expr AND_BIT . expr
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 98
	ArrID  goto 55
	assign_stmt  goto 56


state 72
	logical_expr : expr AND . expr
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 99
	ArrID  goto 55
	assign_stmt  goto 56


state 73
	expr : expr OR_BIT . expr
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 100
	ArrID  goto 55
	assign_stmt  goto 56


state 74
	logical_expr : expr OR . expr
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 101
	ArrID  goto 55
	assign_stmt  goto 56


state 75
	logical_expr : expr BNE . expr
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 102
	ArrID  goto 55
	assign_stmt  goto 56


state 76
	logical_expr : expr LNE . expr
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 103
	ArrID  goto 55
	assign_stmt  goto 56


state 77
	logical_expr : expr BE . expr
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 104
	ArrID  goto 55
	assign_stmt  goto 56


state 78
	logical_expr : expr LE . expr
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 105
	ArrID  goto 55
	assign_stmt  goto 56


state 79
	logical_expr : expr EQUAL . expr
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 106
	ArrID  goto 55
	assign_stmt  goto 56


state 80
	logical_expr : expr NOT_EQ . expr
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 107
	ArrID  goto 55
	assign_stmt  goto 56


state 81
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

	var_type  goto 19
	for_stmt  goto 20
	if_stmt  goto 21
	ArrID  goto 22
	assign_stmt  goto 23
	declare_stmt  goto 24
	while_stmt  goto 25
	stmt  goto 108


state 82
	expr : expr ADD . expr
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 109
	ArrID  goto 55
	assign_stmt  goto 56


state 83
	expr : expr SUB . expr
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 110
	ArrID  goto 55
	assign_stmt  goto 56


state 84
	expr : expr MUL . expr
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 111
	ArrID  goto 55
	assign_stmt  goto 56


state 85
	expr : expr DIV . expr
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 112
	ArrID  goto 55
	assign_stmt  goto 56


state 86
	expr : expr MOD . expr
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 113
	ArrID  goto 55
	assign_stmt  goto 56


87: shift-reduce conflict (shift 114, reduce 37) on RPAREN
state 87
	for_stmt : FOR LPAREN LINEEND LINEEND . expr RPAREN stmt
	for_stmt : FOR LPAREN LINEEND LINEEND . RPAREN stmt
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	RPAREN  shift 114
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 115
	ArrID  goto 55
	assign_stmt  goto 56


state 88
	for_stmt : FOR LPAREN LINEEND expr . LINEEND expr RPAREN stmt
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	for_stmt : FOR LPAREN LINEEND expr . LINEEND RPAREN stmt
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	AND_BIT  shift 71
	AND  shift 72
	OR_BIT  shift 73
	OR  shift 74
	BNE  shift 75
	LNE  shift 76
	BE  shift 77
	LE  shift 78
	EQUAL  shift 79
	NOT_EQ  shift 80
	LINEEND  shift 116
	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86


89: shift-reduce conflict (shift 117, reduce 37) on LINEEND
state 89
	for_stmt : FOR LPAREN expr LINEEND . expr LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN expr LINEEND . LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN expr LINEEND . expr LINEEND RPAREN stmt
	for_stmt : FOR LPAREN expr LINEEND . LINEEND RPAREN stmt
	logical_expr : .  (37)

	NOT  shift 44
	LINEEND  shift 117
	LPAREN  shift 45
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 118
	ArrID  goto 55
	assign_stmt  goto 56


state 90
	if_stmt : IF LPAREN expr RPAREN . stmt ELSE stmt
	if_stmt : IF LPAREN expr RPAREN . stmt

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

	var_type  goto 19
	for_stmt  goto 20
	if_stmt  goto 21
	ArrID  goto 22
	assign_stmt  goto 23
	declare_stmt  goto 24
	while_stmt  goto 25
	stmt  goto 119


state 91
	ArrID : ID LFPA expr RFPA .  (61)

	.  reduce 61


state 92
	stmt : INPUT LPAREN ID RPAREN . LINEEND

	LINEEND  shift 120


state 93
	stmt : INPUT LPAREN ArrID RPAREN . LINEEND

	LINEEND  shift 121


state 94
	stmt : OUTPUT LPAREN expr RPAREN . LINEEND

	LINEEND  shift 122


state 95
	idList : ID COMMA idList .  (22)

	.  reduce 22


state 96
	idList : ArrID COMMA idList .  (25)

	.  reduce 25


state 97
	expr : LPAREN expr RPAREN .  (54)

	.  reduce 54


state 98
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr AND_BIT expr .  (52)
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	BNE  shift 75
	LNE  shift 76
	BE  shift 77
	LE  shift 78
	EQUAL  shift 79
	NOT_EQ  shift 80
	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86
	.  reduce 52


state 99
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr AND expr .  (44)
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	BNE  shift 75
	LNE  shift 76
	BE  shift 77
	LE  shift 78
	EQUAL  shift 79
	NOT_EQ  shift 80
	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86
	.  reduce 44


state 100
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr OR_BIT expr .  (53)
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	AND_BIT  shift 71
	AND  shift 72
	BNE  shift 75
	LNE  shift 76
	BE  shift 77
	LE  shift 78
	EQUAL  shift 79
	NOT_EQ  shift 80
	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86
	.  reduce 53


state 101
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr OR expr .  (45)
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	AND_BIT  shift 71
	AND  shift 72
	BNE  shift 75
	LNE  shift 76
	BE  shift 77
	LE  shift 78
	EQUAL  shift 79
	NOT_EQ  shift 80
	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86
	.  reduce 45


state 102
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr BNE expr .  (38)
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86
	.  reduce 38


state 103
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr LNE expr .  (40)
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86
	.  reduce 40


state 104
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr BE expr .  (39)
	logical_expr : expr . BE expr

	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86
	.  reduce 39


state 105
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr LE expr .  (41)
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86
	.  reduce 41


state 106
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr EQUAL expr .  (42)
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86
	.  reduce 42


state 107
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr NOT_EQ expr .  (43)
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86
	.  reduce 43


state 108
	while_stmt : WHILE LPAREN expr RPAREN stmt .  (28)

	.  reduce 28


state 109
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr ADD expr .  (47)
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	MUL  shift 84
	DIV  shift 85
	MOD  shift 86
	.  reduce 47


state 110
	expr : expr SUB expr .  (48)
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	MUL  shift 84
	DIV  shift 85
	MOD  shift 86
	.  reduce 48


state 111
	expr : expr . SUB expr
	expr : expr MUL expr .  (49)
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	.  reduce 49


state 112
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr DIV expr .  (50)
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	.  reduce 50


state 113
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr MOD expr .  (51)
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	.  reduce 51


state 114
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

	var_type  goto 19
	for_stmt  goto 20
	if_stmt  goto 21
	ArrID  goto 22
	assign_stmt  goto 23
	declare_stmt  goto 24
	while_stmt  goto 25
	stmt  goto 123


state 115
	for_stmt : FOR LPAREN LINEEND LINEEND expr . RPAREN stmt
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	AND_BIT  shift 71
	AND  shift 72
	OR_BIT  shift 73
	OR  shift 74
	BNE  shift 75
	LNE  shift 76
	BE  shift 77
	LE  shift 78
	EQUAL  shift 79
	NOT_EQ  shift 80
	RPAREN  shift 124
	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86


116: shift-reduce conflict (shift 125, reduce 37) on RPAREN
state 116
	for_stmt : FOR LPAREN LINEEND expr LINEEND . expr RPAREN stmt
	for_stmt : FOR LPAREN LINEEND expr LINEEND . RPAREN stmt
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	RPAREN  shift 125
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 126
	ArrID  goto 55
	assign_stmt  goto 56


117: shift-reduce conflict (shift 127, reduce 37) on RPAREN
state 117
	for_stmt : FOR LPAREN expr LINEEND LINEEND . expr RPAREN stmt
	for_stmt : FOR LPAREN expr LINEEND LINEEND . RPAREN stmt
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	RPAREN  shift 127
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 128
	ArrID  goto 55
	assign_stmt  goto 56


state 118
	for_stmt : FOR LPAREN expr LINEEND expr . LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN expr LINEEND expr . LINEEND RPAREN stmt
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	AND_BIT  shift 71
	AND  shift 72
	OR_BIT  shift 73
	OR  shift 74
	BNE  shift 75
	LNE  shift 76
	BE  shift 77
	LE  shift 78
	EQUAL  shift 79
	NOT_EQ  shift 80
	LINEEND  shift 129
	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86


119: shift-reduce conflict (shift 130, reduce 27) on ELSE
state 119
	if_stmt : IF LPAREN expr RPAREN stmt . ELSE stmt
	if_stmt : IF LPAREN expr RPAREN stmt .  (27)

	ELSE  shift 130
	.  reduce 27


state 120
	stmt : INPUT LPAREN ID RPAREN LINEEND .  (10)

	.  reduce 10


state 121
	stmt : INPUT LPAREN ArrID RPAREN LINEEND .  (11)

	.  reduce 11


state 122
	stmt : OUTPUT LPAREN expr RPAREN LINEEND .  (12)

	.  reduce 12


state 123
	for_stmt : FOR LPAREN LINEEND LINEEND RPAREN stmt .  (36)

	.  reduce 36


state 124
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

	var_type  goto 19
	for_stmt  goto 20
	if_stmt  goto 21
	ArrID  goto 22
	assign_stmt  goto 23
	declare_stmt  goto 24
	while_stmt  goto 25
	stmt  goto 131


state 125
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

	var_type  goto 19
	for_stmt  goto 20
	if_stmt  goto 21
	ArrID  goto 22
	assign_stmt  goto 23
	declare_stmt  goto 24
	while_stmt  goto 25
	stmt  goto 132


state 126
	for_stmt : FOR LPAREN LINEEND expr LINEEND expr . RPAREN stmt
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	AND_BIT  shift 71
	AND  shift 72
	OR_BIT  shift 73
	OR  shift 74
	BNE  shift 75
	LNE  shift 76
	BE  shift 77
	LE  shift 78
	EQUAL  shift 79
	NOT_EQ  shift 80
	RPAREN  shift 133
	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86


state 127
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

	var_type  goto 19
	for_stmt  goto 20
	if_stmt  goto 21
	ArrID  goto 22
	assign_stmt  goto 23
	declare_stmt  goto 24
	while_stmt  goto 25
	stmt  goto 134


state 128
	for_stmt : FOR LPAREN expr LINEEND LINEEND expr . RPAREN stmt
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	AND_BIT  shift 71
	AND  shift 72
	OR_BIT  shift 73
	OR  shift 74
	BNE  shift 75
	LNE  shift 76
	BE  shift 77
	LE  shift 78
	EQUAL  shift 79
	NOT_EQ  shift 80
	RPAREN  shift 135
	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86


129: shift-reduce conflict (shift 136, reduce 37) on RPAREN
state 129
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND . expr RPAREN stmt
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND . RPAREN stmt
	logical_expr : .  (37)

	NOT  shift 44
	LPAREN  shift 45
	RPAREN  shift 136
	ID  shift 46
	INT_NUMBER  shift 47
	FLOAT_NUMBER  shift 48
	OCT_NUMBER  shift 49
	HEX_NUMBER  shift 50
	CHARACTER  shift 51
	.  reduce 37

	logical_expr  goto 52
	NUMBER  goto 53
	expr  goto 137
	ArrID  goto 55
	assign_stmt  goto 56


state 130
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

	var_type  goto 19
	for_stmt  goto 20
	if_stmt  goto 21
	ArrID  goto 22
	assign_stmt  goto 23
	declare_stmt  goto 24
	while_stmt  goto 25
	stmt  goto 138


state 131
	for_stmt : FOR LPAREN LINEEND LINEEND expr RPAREN stmt .  (33)

	.  reduce 33


state 132
	for_stmt : FOR LPAREN LINEEND expr LINEEND RPAREN stmt .  (34)

	.  reduce 34


state 133
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

	var_type  goto 19
	for_stmt  goto 20
	if_stmt  goto 21
	ArrID  goto 22
	assign_stmt  goto 23
	declare_stmt  goto 24
	while_stmt  goto 25
	stmt  goto 139


state 134
	for_stmt : FOR LPAREN expr LINEEND LINEEND RPAREN stmt .  (35)

	.  reduce 35


state 135
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

	var_type  goto 19
	for_stmt  goto 20
	if_stmt  goto 21
	ArrID  goto 22
	assign_stmt  goto 23
	declare_stmt  goto 24
	while_stmt  goto 25
	stmt  goto 140


state 136
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

	var_type  goto 19
	for_stmt  goto 20
	if_stmt  goto 21
	ArrID  goto 22
	assign_stmt  goto 23
	declare_stmt  goto 24
	while_stmt  goto 25
	stmt  goto 141


state 137
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND expr . RPAREN stmt
	expr : expr . SUB expr
	expr : expr . MUL expr
	logical_expr : expr . EQUAL expr
	expr : expr . OR_BIT expr
	logical_expr : expr . BNE expr
	logical_expr : expr . LE expr
	expr : expr . ADD expr
	expr : expr . DIV expr
	logical_expr : expr . LNE expr
	expr : expr . AND_BIT expr
	expr : expr . MOD expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	logical_expr : expr . AND expr
	logical_expr : expr . BE expr

	AND_BIT  shift 71
	AND  shift 72
	OR_BIT  shift 73
	OR  shift 74
	BNE  shift 75
	LNE  shift 76
	BE  shift 77
	LE  shift 78
	EQUAL  shift 79
	NOT_EQ  shift 80
	RPAREN  shift 142
	ADD  shift 82
	SUB  shift 83
	MUL  shift 84
	DIV  shift 85
	MOD  shift 86


state 138
	if_stmt : IF LPAREN expr RPAREN stmt ELSE stmt .  (26)

	.  reduce 26


state 139
	for_stmt : FOR LPAREN LINEEND expr LINEEND expr RPAREN stmt .  (30)

	.  reduce 30


state 140
	for_stmt : FOR LPAREN expr LINEEND LINEEND expr RPAREN stmt .  (31)

	.  reduce 31


state 141
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND RPAREN stmt .  (32)

	.  reduce 32


state 142
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

	var_type  goto 19
	for_stmt  goto 20
	if_stmt  goto 21
	ArrID  goto 22
	assign_stmt  goto 23
	declare_stmt  goto 24
	while_stmt  goto 25
	stmt  goto 143


state 143
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND expr RPAREN stmt .  (29)

	.  reduce 29


Rules never reduced
	Grammar :  (66)


##############################################################################
# Summary
##############################################################################

State 29 contains 1 shift-reduce conflict(s)
State 57 contains 1 shift-reduce conflict(s)
State 87 contains 1 shift-reduce conflict(s)
State 89 contains 1 shift-reduce conflict(s)
State 116 contains 1 shift-reduce conflict(s)
State 117 contains 1 shift-reduce conflict(s)
State 119 contains 1 shift-reduce conflict(s)
State 129 contains 1 shift-reduce conflict(s)


45 token(s), 16 nonterminal(s)
67 grammar rule(s), 144 state(s)


##############################################################################
# End of File
##############################################################################
