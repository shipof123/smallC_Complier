LEX=flex
YACC=yacc
CC=g++

scc:lex.yy.c y.tab.c y.tab.h lex.yy.o y.tab.o 
	$(CC) y.tab.c -g -ly -ll -o scc
lex.yy.o:lex.yy.c y.tab.h
	$(CC) -c lex.yy.c 
y.tab.o:y.tab.c node.h includes.h
	$(CC) -c y.tab.c 
y.tab.c y.tab.h:smallC.y node.h includes.h
	$(YACC) smallC.y -v -d

lex.yy.c:
	$(LEX) smallC.l
clean:
	rm -f lex.yy.c y.tab.h y.tab.c y.output *.o
