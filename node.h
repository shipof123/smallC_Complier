#pragma once 

#ifndef NODE_H
#define NODE_H
#include "includes.h"

struct Node;
typedef enum {
	Program,
	Extdefs,
	Extdef,
	Extvars,
	Extvar,
	Spec,
	Stspec,
	Opttag,
	Var,
	Func,
	Paras,
	Parasf,
	Para,
	Stmtblock,
	Stmts,
	Stmt,
	Estmt,
	Defs,
	Def,
	Decs,
	Dec,
	Init,
	Fexp,
	Exp,
	Arrs,
	Args,
	Null,
	UnaryOp,
	Operator,
	Int,
	Type,
	Id,
	Keyword 
} NodeType;

struct Node {
	int		line_num;
	char*		name;
	int 		size;
	int 		capacity;	
	NodeType 	node_type;
	Node**		children;
	Node(int lineno, NodeType nt, const char* n, int s, ...) {
		line_num = lineno;
		node_type = nt;
		name = strdup(n);
		size = capacity = s;
		children = new Node*[s];
		
		va_list vl;
		va_start(vl,s);
		for (int i = 0; i<s; ++i) {
			children[i] = va_arg(vl, Node*);
		}
		va_end(vl);
	}
	bool isLeaf()
	{
		return size == 0;
	}	
};
Node* root;
#endif //NODE_H
