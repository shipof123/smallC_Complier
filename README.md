# smallC_Complier Poject 1
A complier for the small C language

---

### Commands
Use the following command to compile and run the program.

	$make
	$./scc test.sc test.output
    
The result is in test.output.

-----

###Grammar errors
Somme grammars have errors, I modified it as follows.

#### Expression in if and return can't be empty, so I change the grammar like this.

    FEXP : EXP
	         |
	         ;
    EXP : ...
            ;

#### PARAS in the old gramma can have situations like **(id, ) **, so I modified as follows.
    PARAS		: PARASF			
                		| /* empty */			
	               	;       
    PARASF		: PARA COMMA PARASF		
                    		| PARA			
                    		;
    PARA		: SPEC VAR				
                		;
#### EXTVARS in the old gramma can have situations like ** int a,; ** , so I modified as follows.
    EXTVARS		: EXTVAR			
		| /* empty */			
		;
    EXTVAR		: DEC			
		| DEC COMMA EXTVAR	
		;

----
	
###Conflict handling
There is a conflict in the ESTMT, the empty should have a lower precedence

    %nonassoc LOWER_ELSE
    %nonassoc ELSE

    ESTMT		: ELSE STMT %prec ELSE		
    		| /* empty */%prec LOWER_ELSE
 
----
	
###Error handling
There is a syntax error, it will tells you where the error is located.

    void yyerror(const char *s) {
        	fflush(stdout);
        	fprintf(stderr, "[error] at line [%d] %s %s.\n", yylineno, s, yytext);
    }