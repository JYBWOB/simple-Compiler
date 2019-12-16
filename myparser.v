#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 68 of your 30 day trial period.
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
# Date: 12/16/19
# Time: 21:54:16
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

    4  stmt : function
    5       | RETURN expr LINEEND
    6       | callfun LINEEND
    7       | assign_stmt LINEEND
    8       | declare_stmt LINEEND
    9       | if_stmt
   10       | while_stmt
   11       | for_stmt
   12       | LBRACE stmts RBRACE
   13       | INPUT LPAREN ID RPAREN LINEEND
   14       | INPUT LPAREN ArrID RPAREN LINEEND
   15       | OUTPUT LPAREN expr RPAREN LINEEND
   16       | LINEEND

   17  function : paramDecl LPAREN paramList RPAREN LBRACE stmts RBRACE

   18  paramList : paramDecl COMMA paramList
   19            | paramDecl
   20            |

   21  paramDecl : var_type ID

   22  callfun : ID LPAREN inParamList RPAREN

   23  inParamList : expr COMMA inParamList
   24              | expr
   25              |

   26  assign_stmt : ID ASSIGN expr
   27              | ArrID ASSIGN expr

   28  declare_stmt : var_type idList

   29  var_type : VOID
   30           | INT
   31           | FLOAT
   32           | DOUBLE
   33           | CHAR

   34  idList : ID COMMA idList
   35         | ID
   36         | ArrID
   37         | ArrID COMMA idList

   38  if_stmt : IF LPAREN expr RPAREN stmt ELSE stmt
   39          | IF LPAREN expr RPAREN stmt

   40  while_stmt : WHILE LPAREN expr RPAREN stmt

   41  for_stmt : FOR LPAREN expr LINEEND expr LINEEND expr RPAREN stmt
   42           | FOR LPAREN LINEEND expr LINEEND expr RPAREN stmt
   43           | FOR LPAREN expr LINEEND LINEEND expr RPAREN stmt
   44           | FOR LPAREN expr LINEEND expr LINEEND RPAREN stmt
   45           | FOR LPAREN LINEEND LINEEND expr RPAREN stmt
   46           | FOR LPAREN LINEEND expr LINEEND RPAREN stmt
   47           | FOR LPAREN expr LINEEND LINEEND RPAREN stmt
   48           | FOR LPAREN LINEEND LINEEND RPAREN stmt

   49  logical_expr :
   50               | expr BNE expr
   51               | expr BE expr
   52               | expr LNE expr
   53               | expr LE expr
   54               | expr EQUAL expr
   55               | expr NOT_EQ expr
   56               | expr AND expr
   57               | expr OR expr
   58               | NOT expr

   59  expr : callfun
   60       | expr ADD expr
   61       | expr SUB expr
   62       | expr MUL expr
   63       | expr DIV expr
   64       | expr MOD expr
   65       | expr AND_BIT expr
   66       | expr OR_BIT expr
   67       | LPAREN expr RPAREN
   68       | NUMBER
   69       | CHARACTER
   70       | ID
   71       | ArrID
   72       | assign_stmt
   73       | logical_expr

   74  ArrID : ID LFPA expr RFPA

   75  NUMBER : INT_NUMBER
   76         | FLOAT_NUMBER
   77         | HEX_NUMBER
   78         | OCT_NUMBER

   79  Grammar :


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

	RETURN  shift 6
	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	WHILE  shift 12
	FOR  shift 13
	LBRACE  shift 14
	IF  shift 15
	LINEEND  shift 16
	ID  shift 17
	INPUT  shift 18
	OUTPUT  shift 19

	while_stmt  goto 20
	stmt  goto 21
	callfun  goto 22
	stmts  goto 23
	assign_stmt  goto 24
	function  goto 25
	declare_stmt  goto 26
	if_stmt  goto 27
	var_type  goto 28
	ArrID  goto 29
	paramDecl  goto 30
	for_stmt  goto 31


state 6
	stmt : RETURN . expr LINEEND
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 42
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 7
	var_type : INT .  (30)

	.  reduce 30


state 8
	var_type : DOUBLE .  (32)

	.  reduce 32


state 9
	var_type : FLOAT .  (31)

	.  reduce 31


state 10
	var_type : CHAR .  (33)

	.  reduce 33


state 11
	var_type : VOID .  (29)

	.  reduce 29


state 12
	while_stmt : WHILE . LPAREN expr RPAREN stmt

	LPAREN  shift 46


state 13
	for_stmt : FOR . LPAREN LINEEND LINEEND expr RPAREN stmt
	for_stmt : FOR . LPAREN expr LINEEND LINEEND RPAREN stmt
	for_stmt : FOR . LPAREN LINEEND LINEEND RPAREN stmt
	for_stmt : FOR . LPAREN expr LINEEND expr LINEEND RPAREN stmt
	for_stmt : FOR . LPAREN LINEEND expr LINEEND expr RPAREN stmt
	for_stmt : FOR . LPAREN expr LINEEND expr LINEEND expr RPAREN stmt
	for_stmt : FOR . LPAREN LINEEND expr LINEEND RPAREN stmt
	for_stmt : FOR . LPAREN expr LINEEND LINEEND expr RPAREN stmt

	LPAREN  shift 47


state 14
	stmt : LBRACE . stmts RBRACE

	RETURN  shift 6
	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	WHILE  shift 12
	FOR  shift 13
	LBRACE  shift 14
	IF  shift 15
	LINEEND  shift 16
	ID  shift 17
	INPUT  shift 18
	OUTPUT  shift 19

	while_stmt  goto 20
	stmt  goto 21
	callfun  goto 22
	stmts  goto 48
	assign_stmt  goto 24
	function  goto 25
	declare_stmt  goto 26
	if_stmt  goto 27
	var_type  goto 28
	ArrID  goto 29
	paramDecl  goto 30
	for_stmt  goto 31


state 15
	if_stmt : IF . LPAREN expr RPAREN stmt ELSE stmt
	if_stmt : IF . LPAREN expr RPAREN stmt

	LPAREN  shift 49


state 16
	stmt : LINEEND .  (16)

	.  reduce 16


state 17
	callfun : ID . LPAREN inParamList RPAREN
	assign_stmt : ID . ASSIGN expr
	ArrID : ID . LFPA expr RFPA

	ASSIGN  shift 50
	LPAREN  shift 51
	LFPA  shift 52


state 18
	stmt : INPUT . LPAREN ID RPAREN LINEEND
	stmt : INPUT . LPAREN ArrID RPAREN LINEEND

	LPAREN  shift 53


state 19
	stmt : OUTPUT . LPAREN expr RPAREN LINEEND

	LPAREN  shift 54


state 20
	stmt : while_stmt .  (10)

	.  reduce 10


state 21
	stmts : stmt .  (3)

	.  reduce 3


state 22
	stmt : callfun . LINEEND

	LINEEND  shift 55


state 23
	program : MAIN LPAREN RPAREN LBRACE stmts . RBRACE
	stmts : stmts . stmt

	RETURN  shift 6
	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	WHILE  shift 12
	FOR  shift 13
	LBRACE  shift 14
	RBRACE  shift 56
	IF  shift 15
	LINEEND  shift 16
	ID  shift 17
	INPUT  shift 18
	OUTPUT  shift 19

	while_stmt  goto 20
	stmt  goto 57
	callfun  goto 22
	assign_stmt  goto 24
	function  goto 25
	declare_stmt  goto 26
	if_stmt  goto 27
	var_type  goto 28
	ArrID  goto 29
	paramDecl  goto 30
	for_stmt  goto 31


state 24
	stmt : assign_stmt . LINEEND

	LINEEND  shift 58


state 25
	stmt : function .  (4)

	.  reduce 4


state 26
	stmt : declare_stmt . LINEEND

	LINEEND  shift 59


state 27
	stmt : if_stmt .  (9)

	.  reduce 9


state 28
	declare_stmt : var_type . idList
	paramDecl : var_type . ID

	ID  shift 60

	ArrID  goto 61
	idList  goto 62


state 29
	assign_stmt : ArrID . ASSIGN expr

	ASSIGN  shift 63


state 30
	function : paramDecl . LPAREN paramList RPAREN LBRACE stmts RBRACE

	LPAREN  shift 64


state 31
	stmt : for_stmt .  (11)

	.  reduce 11


state 32
	logical_expr : NOT . expr
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 65
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 33
	expr : LPAREN . expr RPAREN
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 66
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 34
	callfun : ID . LPAREN inParamList RPAREN
	assign_stmt : ID . ASSIGN expr
	expr : ID .  (70)
	ArrID : ID . LFPA expr RFPA

	ASSIGN  shift 50
	LPAREN  shift 51
	LFPA  shift 52
	.  reduce 70


state 35
	NUMBER : INT_NUMBER .  (75)

	.  reduce 75


state 36
	NUMBER : FLOAT_NUMBER .  (76)

	.  reduce 76


state 37
	NUMBER : OCT_NUMBER .  (78)

	.  reduce 78


state 38
	NUMBER : HEX_NUMBER .  (77)

	.  reduce 77


state 39
	expr : CHARACTER .  (69)

	.  reduce 69


state 40
	expr : callfun .  (59)

	.  reduce 59


state 41
	expr : assign_stmt .  (72)

	.  reduce 72


state 42
	stmt : RETURN expr . LINEEND
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	AND_BIT  shift 67
	AND  shift 68
	OR_BIT  shift 69
	OR  shift 70
	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	LINEEND  shift 77
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82


state 43
	assign_stmt : ArrID . ASSIGN expr
	expr : ArrID .  (71)

	ASSIGN  shift 63
	.  reduce 71


state 44
	expr : logical_expr .  (73)

	.  reduce 73


state 45
	expr : NUMBER .  (68)

	.  reduce 68


state 46
	while_stmt : WHILE LPAREN . expr RPAREN stmt
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 83
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


47: shift-reduce conflict (shift 84, reduce 49) on LINEEND
state 47
	for_stmt : FOR LPAREN . LINEEND LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN . expr LINEEND LINEEND RPAREN stmt
	for_stmt : FOR LPAREN . LINEEND LINEEND RPAREN stmt
	for_stmt : FOR LPAREN . expr LINEEND expr LINEEND RPAREN stmt
	for_stmt : FOR LPAREN . LINEEND expr LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN . expr LINEEND expr LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN . LINEEND expr LINEEND RPAREN stmt
	for_stmt : FOR LPAREN . expr LINEEND LINEEND expr RPAREN stmt
	logical_expr : .  (49)

	NOT  shift 32
	LINEEND  shift 84
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 85
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 48
	stmts : stmts . stmt
	stmt : LBRACE stmts . RBRACE

	RETURN  shift 6
	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	WHILE  shift 12
	FOR  shift 13
	LBRACE  shift 14
	RBRACE  shift 86
	IF  shift 15
	LINEEND  shift 16
	ID  shift 17
	INPUT  shift 18
	OUTPUT  shift 19

	while_stmt  goto 20
	stmt  goto 57
	callfun  goto 22
	assign_stmt  goto 24
	function  goto 25
	declare_stmt  goto 26
	if_stmt  goto 27
	var_type  goto 28
	ArrID  goto 29
	paramDecl  goto 30
	for_stmt  goto 31


state 49
	if_stmt : IF LPAREN . expr RPAREN stmt ELSE stmt
	if_stmt : IF LPAREN . expr RPAREN stmt
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 87
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 50
	assign_stmt : ID ASSIGN . expr
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 88
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


51: reduce-reduce conflict (reduce 25, reduce 49) on RPAREN
state 51
	callfun : ID LPAREN . inParamList RPAREN
	inParamList : .  (25)
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	RPAREN  reduce 25
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 89
	ArrID  goto 43
	inParamList  goto 90
	logical_expr  goto 44
	NUMBER  goto 45


state 52
	ArrID : ID LFPA . expr RFPA
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 91
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 53
	stmt : INPUT LPAREN . ID RPAREN LINEEND
	stmt : INPUT LPAREN . ArrID RPAREN LINEEND

	ID  shift 92

	ArrID  goto 93


state 54
	stmt : OUTPUT LPAREN . expr RPAREN LINEEND
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 94
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 55
	stmt : callfun LINEEND .  (6)

	.  reduce 6


state 56
	program : MAIN LPAREN RPAREN LBRACE stmts RBRACE .  (1)

	.  reduce 1


state 57
	stmts : stmts stmt .  (2)

	.  reduce 2


state 58
	stmt : assign_stmt LINEEND .  (7)

	.  reduce 7


state 59
	stmt : declare_stmt LINEEND .  (8)

	.  reduce 8


state 60
	paramDecl : var_type ID .  (21)
	idList : ID .  (35)
	idList : ID . COMMA idList
	ArrID : ID . LFPA expr RFPA

	COMMA  shift 95
	LFPA  shift 52
	LPAREN  reduce 21
	.  reduce 35


state 61
	idList : ArrID .  (36)
	idList : ArrID . COMMA idList

	COMMA  shift 96
	.  reduce 36


state 62
	declare_stmt : var_type idList .  (28)

	.  reduce 28


state 63
	assign_stmt : ArrID ASSIGN . expr
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 97
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 64
	function : paramDecl LPAREN . paramList RPAREN LBRACE stmts RBRACE
	paramList : .  (20)

	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	.  reduce 20

	var_type  goto 98
	paramDecl  goto 99
	paramList  goto 100


state 65
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : NOT expr .  (58)
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82
	.  reduce 58


state 66
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : LPAREN expr . RPAREN
	expr : expr . OR_BIT expr

	AND_BIT  shift 67
	AND  shift 68
	OR_BIT  shift 69
	OR  shift 70
	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	RPAREN  shift 101
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82


state 67
	expr : expr AND_BIT . expr
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 102
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 68
	logical_expr : expr AND . expr
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 103
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 69
	expr : expr OR_BIT . expr
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 104
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 70
	logical_expr : expr OR . expr
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 105
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 71
	logical_expr : expr BNE . expr
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 106
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 72
	logical_expr : expr LNE . expr
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 107
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 73
	logical_expr : expr BE . expr
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 108
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 74
	logical_expr : expr LE . expr
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 109
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 75
	logical_expr : expr EQUAL . expr
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 110
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 76
	logical_expr : expr NOT_EQ . expr
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 111
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 77
	stmt : RETURN expr LINEEND .  (5)

	.  reduce 5


state 78
	expr : expr ADD . expr
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 112
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 79
	expr : expr SUB . expr
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 113
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 80
	expr : expr MUL . expr
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 114
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 81
	expr : expr DIV . expr
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 115
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 82
	expr : expr MOD . expr
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 116
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 83
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	while_stmt : WHILE LPAREN expr . RPAREN stmt
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	AND_BIT  shift 67
	AND  shift 68
	OR_BIT  shift 69
	OR  shift 70
	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	RPAREN  shift 117
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82


84: shift-reduce conflict (shift 118, reduce 49) on LINEEND
state 84
	for_stmt : FOR LPAREN LINEEND . LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN LINEEND . LINEEND RPAREN stmt
	for_stmt : FOR LPAREN LINEEND . expr LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN LINEEND . expr LINEEND RPAREN stmt
	logical_expr : .  (49)

	NOT  shift 32
	LINEEND  shift 118
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 119
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 85
	for_stmt : FOR LPAREN expr . LINEEND LINEEND RPAREN stmt
	logical_expr : expr . BNE expr
	for_stmt : FOR LPAREN expr . LINEEND expr LINEEND RPAREN stmt
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	for_stmt : FOR LPAREN expr . LINEEND expr LINEEND expr RPAREN stmt
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	for_stmt : FOR LPAREN expr . LINEEND LINEEND expr RPAREN stmt
	expr : expr . OR_BIT expr

	AND_BIT  shift 67
	AND  shift 68
	OR_BIT  shift 69
	OR  shift 70
	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	LINEEND  shift 120
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82


state 86
	stmt : LBRACE stmts RBRACE .  (12)

	.  reduce 12


state 87
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	if_stmt : IF LPAREN expr . RPAREN stmt ELSE stmt
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	if_stmt : IF LPAREN expr . RPAREN stmt
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	AND_BIT  shift 67
	AND  shift 68
	OR_BIT  shift 69
	OR  shift 70
	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	RPAREN  shift 121
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82


state 88
	assign_stmt : ID ASSIGN expr .  (26)
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	AND_BIT  shift 67
	AND  shift 68
	OR_BIT  shift 69
	OR  shift 70
	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82
	.  reduce 26


state 89
	inParamList : expr .  (24)
	inParamList : expr . COMMA inParamList
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	AND_BIT  shift 67
	AND  shift 68
	OR_BIT  shift 69
	OR  shift 70
	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	COMMA  shift 122
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82
	.  reduce 24


state 90
	callfun : ID LPAREN inParamList . RPAREN

	RPAREN  shift 123


state 91
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr
	ArrID : ID LFPA expr . RFPA

	AND_BIT  shift 67
	AND  shift 68
	OR_BIT  shift 69
	OR  shift 70
	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	RFPA  shift 124
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82


state 92
	stmt : INPUT LPAREN ID . RPAREN LINEEND
	ArrID : ID . LFPA expr RFPA

	RPAREN  shift 125
	LFPA  shift 52


state 93
	stmt : INPUT LPAREN ArrID . RPAREN LINEEND

	RPAREN  shift 126


state 94
	stmt : OUTPUT LPAREN expr . RPAREN LINEEND
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	AND_BIT  shift 67
	AND  shift 68
	OR_BIT  shift 69
	OR  shift 70
	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	RPAREN  shift 127
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82


state 95
	idList : ID COMMA . idList

	ID  shift 128

	ArrID  goto 61
	idList  goto 129


state 96
	idList : ArrID COMMA . idList

	ID  shift 128

	ArrID  goto 61
	idList  goto 130


state 97
	assign_stmt : ArrID ASSIGN expr .  (27)
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	AND_BIT  shift 67
	AND  shift 68
	OR_BIT  shift 69
	OR  shift 70
	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82
	.  reduce 27


state 98
	paramDecl : var_type . ID

	ID  shift 131


state 99
	paramList : paramDecl .  (19)
	paramList : paramDecl . COMMA paramList

	COMMA  shift 132
	.  reduce 19


state 100
	function : paramDecl LPAREN paramList . RPAREN LBRACE stmts RBRACE

	RPAREN  shift 133


state 101
	expr : LPAREN expr RPAREN .  (67)

	.  reduce 67


state 102
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr AND_BIT expr .  (65)
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82
	.  reduce 65


state 103
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr AND expr .  (56)
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82
	.  reduce 56


state 104
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr OR_BIT expr .  (66)
	expr : expr . OR_BIT expr

	AND_BIT  shift 67
	AND  shift 68
	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82
	.  reduce 66


state 105
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr OR expr .  (57)
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	AND_BIT  shift 67
	AND  shift 68
	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82
	.  reduce 57


state 106
	logical_expr : expr BNE expr .  (50)
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82
	.  reduce 50


state 107
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr LNE expr .  (52)
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82
	.  reduce 52


state 108
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr BE expr .  (51)
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82
	.  reduce 51


state 109
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr LE expr .  (53)
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82
	.  reduce 53


state 110
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr EQUAL expr .  (54)
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82
	.  reduce 54


state 111
	logical_expr : expr . BNE expr
	logical_expr : expr NOT_EQ expr .  (55)
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82
	.  reduce 55


state 112
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr ADD expr .  (60)
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	MUL  shift 80
	DIV  shift 81
	MOD  shift 82
	.  reduce 60


state 113
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr SUB expr .  (61)
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	MUL  shift 80
	DIV  shift 81
	MOD  shift 82
	.  reduce 61


state 114
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr MUL expr .  (62)
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	.  reduce 62


state 115
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr DIV expr .  (63)
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	.  reduce 63


state 116
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr MOD expr .  (64)
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	.  reduce 64


state 117
	while_stmt : WHILE LPAREN expr RPAREN . stmt

	RETURN  shift 6
	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	WHILE  shift 12
	FOR  shift 13
	LBRACE  shift 14
	IF  shift 15
	LINEEND  shift 16
	ID  shift 17
	INPUT  shift 18
	OUTPUT  shift 19

	while_stmt  goto 20
	stmt  goto 134
	callfun  goto 22
	assign_stmt  goto 24
	function  goto 25
	declare_stmt  goto 26
	if_stmt  goto 27
	var_type  goto 28
	ArrID  goto 29
	paramDecl  goto 30
	for_stmt  goto 31


118: shift-reduce conflict (shift 135, reduce 49) on RPAREN
state 118
	for_stmt : FOR LPAREN LINEEND LINEEND . expr RPAREN stmt
	for_stmt : FOR LPAREN LINEEND LINEEND . RPAREN stmt
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	RPAREN  shift 135
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 136
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 119
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	for_stmt : FOR LPAREN LINEEND expr . LINEEND expr RPAREN stmt
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	for_stmt : FOR LPAREN LINEEND expr . LINEEND RPAREN stmt
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	AND_BIT  shift 67
	AND  shift 68
	OR_BIT  shift 69
	OR  shift 70
	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	LINEEND  shift 137
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82


120: shift-reduce conflict (shift 138, reduce 49) on LINEEND
state 120
	for_stmt : FOR LPAREN expr LINEEND . LINEEND RPAREN stmt
	for_stmt : FOR LPAREN expr LINEEND . expr LINEEND RPAREN stmt
	for_stmt : FOR LPAREN expr LINEEND . expr LINEEND expr RPAREN stmt
	for_stmt : FOR LPAREN expr LINEEND . LINEEND expr RPAREN stmt
	logical_expr : .  (49)

	NOT  shift 32
	LINEEND  shift 138
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 139
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 121
	if_stmt : IF LPAREN expr RPAREN . stmt ELSE stmt
	if_stmt : IF LPAREN expr RPAREN . stmt

	RETURN  shift 6
	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	WHILE  shift 12
	FOR  shift 13
	LBRACE  shift 14
	IF  shift 15
	LINEEND  shift 16
	ID  shift 17
	INPUT  shift 18
	OUTPUT  shift 19

	while_stmt  goto 20
	stmt  goto 140
	callfun  goto 22
	assign_stmt  goto 24
	function  goto 25
	declare_stmt  goto 26
	if_stmt  goto 27
	var_type  goto 28
	ArrID  goto 29
	paramDecl  goto 30
	for_stmt  goto 31


122: reduce-reduce conflict (reduce 25, reduce 49) on RPAREN
state 122
	inParamList : expr COMMA . inParamList
	inParamList : .  (25)
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	RPAREN  reduce 25
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 89
	ArrID  goto 43
	inParamList  goto 141
	logical_expr  goto 44
	NUMBER  goto 45


state 123
	callfun : ID LPAREN inParamList RPAREN .  (22)

	.  reduce 22


state 124
	ArrID : ID LFPA expr RFPA .  (74)

	.  reduce 74


state 125
	stmt : INPUT LPAREN ID RPAREN . LINEEND

	LINEEND  shift 142


state 126
	stmt : INPUT LPAREN ArrID RPAREN . LINEEND

	LINEEND  shift 143


state 127
	stmt : OUTPUT LPAREN expr RPAREN . LINEEND

	LINEEND  shift 144


state 128
	idList : ID .  (35)
	idList : ID . COMMA idList
	ArrID : ID . LFPA expr RFPA

	COMMA  shift 95
	LFPA  shift 52
	.  reduce 35


state 129
	idList : ID COMMA idList .  (34)

	.  reduce 34


state 130
	idList : ArrID COMMA idList .  (37)

	.  reduce 37


state 131
	paramDecl : var_type ID .  (21)

	.  reduce 21


state 132
	paramList : paramDecl COMMA . paramList
	paramList : .  (20)

	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	.  reduce 20

	var_type  goto 98
	paramDecl  goto 99
	paramList  goto 145


state 133
	function : paramDecl LPAREN paramList RPAREN . LBRACE stmts RBRACE

	LBRACE  shift 146


state 134
	while_stmt : WHILE LPAREN expr RPAREN stmt .  (40)

	.  reduce 40


state 135
	for_stmt : FOR LPAREN LINEEND LINEEND RPAREN . stmt

	RETURN  shift 6
	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	WHILE  shift 12
	FOR  shift 13
	LBRACE  shift 14
	IF  shift 15
	LINEEND  shift 16
	ID  shift 17
	INPUT  shift 18
	OUTPUT  shift 19

	while_stmt  goto 20
	stmt  goto 147
	callfun  goto 22
	assign_stmt  goto 24
	function  goto 25
	declare_stmt  goto 26
	if_stmt  goto 27
	var_type  goto 28
	ArrID  goto 29
	paramDecl  goto 30
	for_stmt  goto 31


state 136
	for_stmt : FOR LPAREN LINEEND LINEEND expr . RPAREN stmt
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	AND_BIT  shift 67
	AND  shift 68
	OR_BIT  shift 69
	OR  shift 70
	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	RPAREN  shift 148
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82


137: shift-reduce conflict (shift 149, reduce 49) on RPAREN
state 137
	for_stmt : FOR LPAREN LINEEND expr LINEEND . expr RPAREN stmt
	for_stmt : FOR LPAREN LINEEND expr LINEEND . RPAREN stmt
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	RPAREN  shift 149
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 150
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


138: shift-reduce conflict (shift 151, reduce 49) on RPAREN
state 138
	for_stmt : FOR LPAREN expr LINEEND LINEEND . RPAREN stmt
	for_stmt : FOR LPAREN expr LINEEND LINEEND . expr RPAREN stmt
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	RPAREN  shift 151
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 152
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 139
	logical_expr : expr . BNE expr
	for_stmt : FOR LPAREN expr LINEEND expr . LINEEND RPAREN stmt
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	for_stmt : FOR LPAREN expr LINEEND expr . LINEEND expr RPAREN stmt
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	AND_BIT  shift 67
	AND  shift 68
	OR_BIT  shift 69
	OR  shift 70
	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	LINEEND  shift 153
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82


140: shift-reduce conflict (shift 154, reduce 39) on ELSE
state 140
	if_stmt : IF LPAREN expr RPAREN stmt . ELSE stmt
	if_stmt : IF LPAREN expr RPAREN stmt .  (39)

	ELSE  shift 154
	.  reduce 39


state 141
	inParamList : expr COMMA inParamList .  (23)

	.  reduce 23


state 142
	stmt : INPUT LPAREN ID RPAREN LINEEND .  (13)

	.  reduce 13


state 143
	stmt : INPUT LPAREN ArrID RPAREN LINEEND .  (14)

	.  reduce 14


state 144
	stmt : OUTPUT LPAREN expr RPAREN LINEEND .  (15)

	.  reduce 15


state 145
	paramList : paramDecl COMMA paramList .  (18)

	.  reduce 18


state 146
	function : paramDecl LPAREN paramList RPAREN LBRACE . stmts RBRACE

	RETURN  shift 6
	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	WHILE  shift 12
	FOR  shift 13
	LBRACE  shift 14
	IF  shift 15
	LINEEND  shift 16
	ID  shift 17
	INPUT  shift 18
	OUTPUT  shift 19

	while_stmt  goto 20
	stmt  goto 21
	callfun  goto 22
	stmts  goto 155
	assign_stmt  goto 24
	function  goto 25
	declare_stmt  goto 26
	if_stmt  goto 27
	var_type  goto 28
	ArrID  goto 29
	paramDecl  goto 30
	for_stmt  goto 31


state 147
	for_stmt : FOR LPAREN LINEEND LINEEND RPAREN stmt .  (48)

	.  reduce 48


state 148
	for_stmt : FOR LPAREN LINEEND LINEEND expr RPAREN . stmt

	RETURN  shift 6
	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	WHILE  shift 12
	FOR  shift 13
	LBRACE  shift 14
	IF  shift 15
	LINEEND  shift 16
	ID  shift 17
	INPUT  shift 18
	OUTPUT  shift 19

	while_stmt  goto 20
	stmt  goto 156
	callfun  goto 22
	assign_stmt  goto 24
	function  goto 25
	declare_stmt  goto 26
	if_stmt  goto 27
	var_type  goto 28
	ArrID  goto 29
	paramDecl  goto 30
	for_stmt  goto 31


state 149
	for_stmt : FOR LPAREN LINEEND expr LINEEND RPAREN . stmt

	RETURN  shift 6
	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	WHILE  shift 12
	FOR  shift 13
	LBRACE  shift 14
	IF  shift 15
	LINEEND  shift 16
	ID  shift 17
	INPUT  shift 18
	OUTPUT  shift 19

	while_stmt  goto 20
	stmt  goto 157
	callfun  goto 22
	assign_stmt  goto 24
	function  goto 25
	declare_stmt  goto 26
	if_stmt  goto 27
	var_type  goto 28
	ArrID  goto 29
	paramDecl  goto 30
	for_stmt  goto 31


state 150
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	for_stmt : FOR LPAREN LINEEND expr LINEEND expr . RPAREN stmt
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	AND_BIT  shift 67
	AND  shift 68
	OR_BIT  shift 69
	OR  shift 70
	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	RPAREN  shift 158
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82


state 151
	for_stmt : FOR LPAREN expr LINEEND LINEEND RPAREN . stmt

	RETURN  shift 6
	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	WHILE  shift 12
	FOR  shift 13
	LBRACE  shift 14
	IF  shift 15
	LINEEND  shift 16
	ID  shift 17
	INPUT  shift 18
	OUTPUT  shift 19

	while_stmt  goto 20
	stmt  goto 159
	callfun  goto 22
	assign_stmt  goto 24
	function  goto 25
	declare_stmt  goto 26
	if_stmt  goto 27
	var_type  goto 28
	ArrID  goto 29
	paramDecl  goto 30
	for_stmt  goto 31


state 152
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	for_stmt : FOR LPAREN expr LINEEND LINEEND expr . RPAREN stmt
	expr : expr . OR_BIT expr

	AND_BIT  shift 67
	AND  shift 68
	OR_BIT  shift 69
	OR  shift 70
	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	RPAREN  shift 160
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82


153: shift-reduce conflict (shift 161, reduce 49) on RPAREN
state 153
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND . RPAREN stmt
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND . expr RPAREN stmt
	logical_expr : .  (49)

	NOT  shift 32
	LPAREN  shift 33
	RPAREN  shift 161
	ID  shift 34
	INT_NUMBER  shift 35
	FLOAT_NUMBER  shift 36
	OCT_NUMBER  shift 37
	HEX_NUMBER  shift 38
	CHARACTER  shift 39
	.  reduce 49

	callfun  goto 40
	assign_stmt  goto 41
	expr  goto 162
	ArrID  goto 43
	logical_expr  goto 44
	NUMBER  goto 45


state 154
	if_stmt : IF LPAREN expr RPAREN stmt ELSE . stmt

	RETURN  shift 6
	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	WHILE  shift 12
	FOR  shift 13
	LBRACE  shift 14
	IF  shift 15
	LINEEND  shift 16
	ID  shift 17
	INPUT  shift 18
	OUTPUT  shift 19

	while_stmt  goto 20
	stmt  goto 163
	callfun  goto 22
	assign_stmt  goto 24
	function  goto 25
	declare_stmt  goto 26
	if_stmt  goto 27
	var_type  goto 28
	ArrID  goto 29
	paramDecl  goto 30
	for_stmt  goto 31


state 155
	stmts : stmts . stmt
	function : paramDecl LPAREN paramList RPAREN LBRACE stmts . RBRACE

	RETURN  shift 6
	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	WHILE  shift 12
	FOR  shift 13
	LBRACE  shift 14
	RBRACE  shift 164
	IF  shift 15
	LINEEND  shift 16
	ID  shift 17
	INPUT  shift 18
	OUTPUT  shift 19

	while_stmt  goto 20
	stmt  goto 57
	callfun  goto 22
	assign_stmt  goto 24
	function  goto 25
	declare_stmt  goto 26
	if_stmt  goto 27
	var_type  goto 28
	ArrID  goto 29
	paramDecl  goto 30
	for_stmt  goto 31


state 156
	for_stmt : FOR LPAREN LINEEND LINEEND expr RPAREN stmt .  (45)

	.  reduce 45


state 157
	for_stmt : FOR LPAREN LINEEND expr LINEEND RPAREN stmt .  (46)

	.  reduce 46


state 158
	for_stmt : FOR LPAREN LINEEND expr LINEEND expr RPAREN . stmt

	RETURN  shift 6
	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	WHILE  shift 12
	FOR  shift 13
	LBRACE  shift 14
	IF  shift 15
	LINEEND  shift 16
	ID  shift 17
	INPUT  shift 18
	OUTPUT  shift 19

	while_stmt  goto 20
	stmt  goto 165
	callfun  goto 22
	assign_stmt  goto 24
	function  goto 25
	declare_stmt  goto 26
	if_stmt  goto 27
	var_type  goto 28
	ArrID  goto 29
	paramDecl  goto 30
	for_stmt  goto 31


state 159
	for_stmt : FOR LPAREN expr LINEEND LINEEND RPAREN stmt .  (47)

	.  reduce 47


state 160
	for_stmt : FOR LPAREN expr LINEEND LINEEND expr RPAREN . stmt

	RETURN  shift 6
	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	WHILE  shift 12
	FOR  shift 13
	LBRACE  shift 14
	IF  shift 15
	LINEEND  shift 16
	ID  shift 17
	INPUT  shift 18
	OUTPUT  shift 19

	while_stmt  goto 20
	stmt  goto 166
	callfun  goto 22
	assign_stmt  goto 24
	function  goto 25
	declare_stmt  goto 26
	if_stmt  goto 27
	var_type  goto 28
	ArrID  goto 29
	paramDecl  goto 30
	for_stmt  goto 31


state 161
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND RPAREN . stmt

	RETURN  shift 6
	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	WHILE  shift 12
	FOR  shift 13
	LBRACE  shift 14
	IF  shift 15
	LINEEND  shift 16
	ID  shift 17
	INPUT  shift 18
	OUTPUT  shift 19

	while_stmt  goto 20
	stmt  goto 167
	callfun  goto 22
	assign_stmt  goto 24
	function  goto 25
	declare_stmt  goto 26
	if_stmt  goto 27
	var_type  goto 28
	ArrID  goto 29
	paramDecl  goto 30
	for_stmt  goto 31


state 162
	logical_expr : expr . BNE expr
	logical_expr : expr . NOT_EQ expr
	logical_expr : expr . OR expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	logical_expr : expr . LE expr
	expr : expr . SUB expr
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND expr . RPAREN stmt
	logical_expr : expr . EQUAL expr
	logical_expr : expr . BE expr
	logical_expr : expr . LNE expr
	expr : expr . MOD expr
	expr : expr . ADD expr
	expr : expr . AND_BIT expr
	logical_expr : expr . AND expr
	expr : expr . OR_BIT expr

	AND_BIT  shift 67
	AND  shift 68
	OR_BIT  shift 69
	OR  shift 70
	BNE  shift 71
	LNE  shift 72
	BE  shift 73
	LE  shift 74
	EQUAL  shift 75
	NOT_EQ  shift 76
	RPAREN  shift 168
	ADD  shift 78
	SUB  shift 79
	MUL  shift 80
	DIV  shift 81
	MOD  shift 82


state 163
	if_stmt : IF LPAREN expr RPAREN stmt ELSE stmt .  (38)

	.  reduce 38


state 164
	function : paramDecl LPAREN paramList RPAREN LBRACE stmts RBRACE .  (17)

	.  reduce 17


state 165
	for_stmt : FOR LPAREN LINEEND expr LINEEND expr RPAREN stmt .  (42)

	.  reduce 42


state 166
	for_stmt : FOR LPAREN expr LINEEND LINEEND expr RPAREN stmt .  (43)

	.  reduce 43


state 167
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND RPAREN stmt .  (44)

	.  reduce 44


state 168
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND expr RPAREN . stmt

	RETURN  shift 6
	INT  shift 7
	DOUBLE  shift 8
	FLOAT  shift 9
	CHAR  shift 10
	VOID  shift 11
	WHILE  shift 12
	FOR  shift 13
	LBRACE  shift 14
	IF  shift 15
	LINEEND  shift 16
	ID  shift 17
	INPUT  shift 18
	OUTPUT  shift 19

	while_stmt  goto 20
	stmt  goto 169
	callfun  goto 22
	assign_stmt  goto 24
	function  goto 25
	declare_stmt  goto 26
	if_stmt  goto 27
	var_type  goto 28
	ArrID  goto 29
	paramDecl  goto 30
	for_stmt  goto 31


state 169
	for_stmt : FOR LPAREN expr LINEEND expr LINEEND expr RPAREN stmt .  (41)

	.  reduce 41


Rules never reduced
	Grammar :  (79)


##############################################################################
# Summary
##############################################################################

State 47 contains 1 shift-reduce conflict(s)
State 51 contains 1 reduce-reduce conflict(s)
State 84 contains 1 shift-reduce conflict(s)
State 118 contains 1 shift-reduce conflict(s)
State 120 contains 1 shift-reduce conflict(s)
State 122 contains 1 reduce-reduce conflict(s)
State 137 contains 1 shift-reduce conflict(s)
State 138 contains 1 shift-reduce conflict(s)
State 140 contains 1 shift-reduce conflict(s)
State 153 contains 1 shift-reduce conflict(s)


46 token(s), 21 nonterminal(s)
80 grammar rule(s), 170 state(s)


##############################################################################
# End of File
##############################################################################
