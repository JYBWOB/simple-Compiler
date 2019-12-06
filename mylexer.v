#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 57 of your 30 day trial period.
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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 12/06/19
# Time: 15:51:06
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  [ \t\v\f\n]

    2  input

    3  output

    4  return

    5  int

    6  float

    7  double

    8  char

    9  void

   10  main

   11  break

   12  include

   13  while

   14  for

   15  switch

   16  \{

   17  \}

   18  if

   19  else

   20  \>=

   21  \>

   22  \<=

   23  \<

   24  ==

   25  =

   26  &

   27  &&

   28  \|

   29  \|\|

   30  !

   31  !=

   32  ;

   33  \(

   34  \)

   35  ,

   36  \+

   37  -

   38  \*

   39  \/

   40  [a-zA-Z_][a-zA-Z0-9_]*

   41  (([1-9][0-9]*)|(0))(\.)([0-9]+)

   42  ([1-9][0-9]*)|(0)

   43  0[0-7]+

   44  0x[0-9a-fA-F]+

   45  '.'

   46  \/\/.*

   47  \/\*([^*"]*|".*"|\*+[^/])*\*\/


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x09 - 0x0c (4)    goto 3
	0x20               goto 3
	0x21               goto 4
	0x26               goto 5
	0x27               goto 6
	0x28               goto 7
	0x29               goto 8
	0x2a               goto 9
	0x2b               goto 10
	0x2c               goto 11
	0x2d               goto 12
	0x2f               goto 13
	0x30               goto 14
	0x31 - 0x39 (9)    goto 15
	0x3b               goto 16
	0x3c               goto 17
	0x3d               goto 18
	0x3e               goto 19
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61               goto 20
	0x62               goto 21
	0x63               goto 22
	0x64               goto 23
	0x65               goto 24
	0x66               goto 25
	0x67 - 0x68 (2)    goto 20
	0x69               goto 26
	0x6a - 0x6c (3)    goto 20
	0x6d               goto 27
	0x6e               goto 20
	0x6f               goto 28
	0x70 - 0x71 (2)    goto 20
	0x72               goto 29
	0x73               goto 30
	0x74 - 0x75 (2)    goto 20
	0x76               goto 31
	0x77               goto 32
	0x78 - 0x7a (3)    goto 20
	0x7b               goto 33
	0x7c               goto 34
	0x7d               goto 35


state 2
	^INITIAL

	0x09 - 0x0c (4)    goto 3
	0x20               goto 3
	0x21               goto 4
	0x26               goto 5
	0x27               goto 6
	0x28               goto 7
	0x29               goto 8
	0x2a               goto 9
	0x2b               goto 10
	0x2c               goto 11
	0x2d               goto 12
	0x2f               goto 13
	0x30               goto 14
	0x31 - 0x39 (9)    goto 15
	0x3b               goto 16
	0x3c               goto 17
	0x3d               goto 18
	0x3e               goto 19
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61               goto 20
	0x62               goto 21
	0x63               goto 22
	0x64               goto 23
	0x65               goto 24
	0x66               goto 25
	0x67 - 0x68 (2)    goto 20
	0x69               goto 26
	0x6a - 0x6c (3)    goto 20
	0x6d               goto 27
	0x6e               goto 20
	0x6f               goto 28
	0x70 - 0x71 (2)    goto 20
	0x72               goto 29
	0x73               goto 30
	0x74 - 0x75 (2)    goto 20
	0x76               goto 31
	0x77               goto 32
	0x78 - 0x7a (3)    goto 20
	0x7b               goto 33
	0x7c               goto 34
	0x7d               goto 35


state 3
	match 1


state 4
	0x3d               goto 36

	match 30


state 5
	0x26               goto 37

	match 26


state 6
	0x00 - 0x09 (10)   goto 38
	0x0b - 0xff (245)  goto 38


state 7
	match 33


state 8
	match 34


state 9
	match 38


state 10
	match 36


state 11
	match 35


state 12
	match 37


state 13
	0x2a               goto 39
	0x2f               goto 40

	match 39


state 14
	0x2e               goto 41
	0x30 - 0x37 (8)    goto 42
	0x78               goto 43

	match 42


state 15
	0x2e               goto 41
	0x30 - 0x39 (10)   goto 15

	match 42


state 16
	match 32


state 17
	0x3d               goto 44

	match 23


state 18
	0x3d               goto 45

	match 25


state 19
	0x3d               goto 46

	match 21


state 20
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 40


state 21
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x71 (17)   goto 20
	0x72               goto 47
	0x73 - 0x7a (8)    goto 20

	match 40


state 22
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x67 (7)    goto 20
	0x68               goto 48
	0x69 - 0x7a (18)   goto 20

	match 40


state 23
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6e (14)   goto 20
	0x6f               goto 49
	0x70 - 0x7a (11)   goto 20

	match 40


state 24
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6b (11)   goto 20
	0x6c               goto 50
	0x6d - 0x7a (14)   goto 20

	match 40


state 25
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6b (11)   goto 20
	0x6c               goto 51
	0x6d - 0x6e (2)    goto 20
	0x6f               goto 52
	0x70 - 0x7a (11)   goto 20

	match 40


state 26
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x65 (5)    goto 20
	0x66               goto 53
	0x67 - 0x6d (7)    goto 20
	0x6e               goto 54
	0x6f - 0x7a (12)   goto 20

	match 40


state 27
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61               goto 55
	0x62 - 0x7a (25)   goto 20

	match 40


state 28
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x74 (20)   goto 20
	0x75               goto 56
	0x76 - 0x7a (5)    goto 20

	match 40


state 29
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 57
	0x66 - 0x7a (21)   goto 20

	match 40


state 30
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x76 (22)   goto 20
	0x77               goto 58
	0x78 - 0x7a (3)    goto 20

	match 40


state 31
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6e (14)   goto 20
	0x6f               goto 59
	0x70 - 0x7a (11)   goto 20

	match 40


state 32
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x67 (7)    goto 20
	0x68               goto 60
	0x69 - 0x7a (18)   goto 20

	match 40


state 33
	match 16


state 34
	0x7c               goto 61

	match 28


state 35
	match 17


state 36
	match 31


state 37
	match 27


state 38
	0x27               goto 62


state 39
	0x00 - 0x21 (34)   goto 39
	0x23 - 0x29 (7)    goto 39
	0x2a               goto 63
	0x2b - 0x2d (3)    goto 39
	0x2e               goto 64
	0x2f - 0xff (209)  goto 39


state 40
	0x00 - 0x09 (10)   goto 40
	0x0b - 0xff (245)  goto 40

	match 46


state 41
	0x30 - 0x39 (10)   goto 65


state 42
	0x30 - 0x37 (8)    goto 42

	match 43


state 43
	0x30 - 0x39 (10)   goto 66
	0x41 - 0x46 (6)    goto 66
	0x61 - 0x66 (6)    goto 66


state 44
	match 22


state 45
	match 24


state 46
	match 20


state 47
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 67
	0x66 - 0x7a (21)   goto 20

	match 40


state 48
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61               goto 68
	0x62 - 0x7a (25)   goto 20

	match 40


state 49
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x74 (20)   goto 20
	0x75               goto 69
	0x76 - 0x7a (5)    goto 20

	match 40


state 50
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x72 (18)   goto 20
	0x73               goto 70
	0x74 - 0x7a (7)    goto 20

	match 40


state 51
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6e (14)   goto 20
	0x6f               goto 71
	0x70 - 0x7a (11)   goto 20

	match 40


state 52
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x71 (17)   goto 20
	0x72               goto 72
	0x73 - 0x7a (8)    goto 20

	match 40


state 53
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 18


state 54
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x62 (2)    goto 20
	0x63               goto 73
	0x64 - 0x6f (12)   goto 20
	0x70               goto 74
	0x71 - 0x73 (3)    goto 20
	0x74               goto 75
	0x75 - 0x7a (6)    goto 20

	match 40


state 55
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x68 (8)    goto 20
	0x69               goto 76
	0x6a - 0x7a (17)   goto 20

	match 40


state 56
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x73 (19)   goto 20
	0x74               goto 77
	0x75 - 0x7a (6)    goto 20

	match 40


state 57
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x73 (19)   goto 20
	0x74               goto 78
	0x75 - 0x7a (6)    goto 20

	match 40


state 58
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x68 (8)    goto 20
	0x69               goto 79
	0x6a - 0x7a (17)   goto 20

	match 40


state 59
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x68 (8)    goto 20
	0x69               goto 80
	0x6a - 0x7a (17)   goto 20

	match 40


state 60
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x68 (8)    goto 20
	0x69               goto 81
	0x6a - 0x7a (17)   goto 20

	match 40


state 61
	match 29


state 62
	match 45


state 63
	0x00 - 0x29 (42)   goto 39
	0x2a               goto 82
	0x2b - 0x2e (4)    goto 39
	0x2f               goto 83
	0x30 - 0xff (208)  goto 39


state 64
	0x00 - 0x21 (34)   goto 39
	0x23 - 0x29 (7)    goto 39
	0x2a               goto 84
	0x2b - 0x2d (3)    goto 39
	0x2e               goto 64
	0x2f - 0xff (209)  goto 39


state 65
	0x30 - 0x39 (10)   goto 65

	match 41


state 66
	0x30 - 0x39 (10)   goto 66
	0x41 - 0x46 (6)    goto 66
	0x61 - 0x66 (6)    goto 66

	match 44


state 67
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61               goto 85
	0x62 - 0x7a (25)   goto 20

	match 40


state 68
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x71 (17)   goto 20
	0x72               goto 86
	0x73 - 0x7a (8)    goto 20

	match 40


state 69
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61               goto 20
	0x62               goto 87
	0x63 - 0x7a (24)   goto 20

	match 40


state 70
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 88
	0x66 - 0x7a (21)   goto 20

	match 40


state 71
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61               goto 89
	0x62 - 0x7a (25)   goto 20

	match 40


state 72
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 14


state 73
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6b (11)   goto 20
	0x6c               goto 90
	0x6d - 0x7a (14)   goto 20

	match 40


state 74
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x74 (20)   goto 20
	0x75               goto 91
	0x76 - 0x7a (5)    goto 20

	match 40


state 75
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 5


state 76
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6d (13)   goto 20
	0x6e               goto 92
	0x6f - 0x7a (12)   goto 20

	match 40


state 77
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6f (15)   goto 20
	0x70               goto 93
	0x71 - 0x7a (10)   goto 20

	match 40


state 78
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x74 (20)   goto 20
	0x75               goto 94
	0x76 - 0x7a (5)    goto 20

	match 40


state 79
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x73 (19)   goto 20
	0x74               goto 95
	0x75 - 0x7a (6)    goto 20

	match 40


state 80
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x63 (3)    goto 20
	0x64               goto 96
	0x65 - 0x7a (22)   goto 20

	match 40


state 81
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6b (11)   goto 20
	0x6c               goto 97
	0x6d - 0x7a (14)   goto 20

	match 40


state 82
	0x00 - 0x21 (34)   goto 39
	0x22               goto 39
	0x23 - 0x29 (7)    goto 39
	0x2a               goto 84
	0x2b - 0x2d (3)    goto 39
	0x2e               goto 64
	0x2f               goto 39
	0x30 - 0xff (208)  goto 39


state 83
	match 47


state 84
	0x00 - 0x21 (34)   goto 39
	0x22               goto 39
	0x23 - 0x29 (7)    goto 39
	0x2a               goto 84
	0x2b - 0x2d (3)    goto 39
	0x2e               goto 64
	0x2f               goto 98
	0x30 - 0xff (208)  goto 39


state 85
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6a (10)   goto 20
	0x6b               goto 99
	0x6c - 0x7a (15)   goto 20

	match 40


state 86
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 8


state 87
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6b (11)   goto 20
	0x6c               goto 100
	0x6d - 0x7a (14)   goto 20

	match 40


state 88
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 19


state 89
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x73 (19)   goto 20
	0x74               goto 101
	0x75 - 0x7a (6)    goto 20

	match 40


state 90
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x74 (20)   goto 20
	0x75               goto 102
	0x76 - 0x7a (5)    goto 20

	match 40


state 91
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x73 (19)   goto 20
	0x74               goto 103
	0x75 - 0x7a (6)    goto 20

	match 40


state 92
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 10


state 93
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x74 (20)   goto 20
	0x75               goto 104
	0x76 - 0x7a (5)    goto 20

	match 40


state 94
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x71 (17)   goto 20
	0x72               goto 105
	0x73 - 0x7a (8)    goto 20

	match 40


state 95
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x62 (2)    goto 20
	0x63               goto 106
	0x64 - 0x7a (23)   goto 20

	match 40


state 96
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 9


state 97
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 107
	0x66 - 0x7a (21)   goto 20

	match 40


state 98
	0x00 - 0x21 (34)   goto 39
	0x23 - 0x29 (7)    goto 39
	0x2a               goto 63
	0x2b - 0x2d (3)    goto 39
	0x2e               goto 64
	0x2f - 0xff (209)  goto 39

	match 47


state 99
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 11


state 100
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 108
	0x66 - 0x7a (21)   goto 20

	match 40


state 101
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 6


state 102
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x63 (3)    goto 20
	0x64               goto 109
	0x65 - 0x7a (22)   goto 20

	match 40


state 103
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 2


state 104
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x73 (19)   goto 20
	0x74               goto 110
	0x75 - 0x7a (6)    goto 20

	match 40


state 105
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6d (13)   goto 20
	0x6e               goto 111
	0x6f - 0x7a (12)   goto 20

	match 40


state 106
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x67 (7)    goto 20
	0x68               goto 112
	0x69 - 0x7a (18)   goto 20

	match 40


state 107
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 13


state 108
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 7


state 109
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 113
	0x66 - 0x7a (21)   goto 20

	match 40


state 110
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 3


state 111
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 4


state 112
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 15


state 113
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 12


#############################################################################
# Summary
#############################################################################

1 start state(s)
47 expression(s), 113 state(s)


#############################################################################
# End of File
#############################################################################
