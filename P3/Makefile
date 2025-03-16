##################################################################
#
#	Makefile -- P Parser
#
##################################################################

p: lex.yy.o y.tab.o table.o
	gcc -o p lex.yy.o y.tab.o table.o -ll

lex.yy.o: lex.yy.c table.h y.tab.h
	gcc -c -g lex.yy.c

y.tab.o: y.tab.c table.h y.tab.h
	gcc -c -g y.tab.c

lex.yy.c: main.l table.h y.tab.h
	lex main.l

y.tab.c: main.y table.h
	yacc -v main.y

table.o: table.c table.h
	gcc -c -g table.c

clean:
	rm -f p *.o lex.yy.c y.tab.c
