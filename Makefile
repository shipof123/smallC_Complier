scc:lex.yy.c y.tab.c y.tab.h lex.yy.o y.tab.o 
	g++ y.tab.c -g -ly -ll -o scc
lex.yy.o:lex.yy.c y.tab.h
	g++ -c lex.yy.c 
y.tab.o:y.tab.c node.h includes.h llvm.h semantic.h
	g++ -c y.tab.c 
y.tab.c y.tab.h:smallC.y node.h includes.h llvm.h
	yacc smallC.y -v -d
lex.yy.c:
	flex smallC.l
clean:
	rm -f lex.yy.c y.tab.h y.tab.c *.output *.o scc
