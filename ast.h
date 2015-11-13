#ifndef AST_H
#define AST_H

#include "node.h"
#include "includes.h"

#define MAX_LENGTH 10000000

char buffer[MAX_LENGTH];
void print_ast(Node* ptr, int depth) 
{
  	int i;
    	int n = (depth - 1) * 2;
    	for (i = 0; i < n; i++) {
 	       putchar(buffer[i]);
	}
	if (depth > 0) {
		putchar('|');
		putchar('_');
	}
    	n = depth * 2;
    	buffer[n] = '|';
    	buffer[n + 1] = ' ';
    	if (!ptr->isLeaf()) {
        	printf("%s\n", ptr->name);
    	} else {
        	printf("\033[1;33m%s\033[0m\n", ptr->name);
    	}
    	for (i = 0; i < ptr->size; i++) {
        	if (i == ptr->size - 1) {
            		buffer[n] = ' ';
        	}
        	print_ast(ptr->children[i], depth + 1);
    	}
}
#endif
