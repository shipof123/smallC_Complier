LEX = flex
YACC = bison 
CC = g++
program: y.tab.o lex.yy.o
	g++ y.tab.c -g -ly -ll -o scc 
lex.yy.o:
	g++ -c lex.yy.c
y.tab.o:
	g++ -c y.tab.c 
y.tab.c y.tab.h:
	bison smallC.y -v -d
lex.yy.c:
	flex smallC.l

clean:
	rm -f *.o
