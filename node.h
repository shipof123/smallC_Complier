#ifndef NODE_H
#define NODE_H

typedef enum {
	PROGRAM,
	EXTDEFS,
	EXTDEF,
	EXTVARS,
	SPEC,
	STSPEC,
	OPTTAG,
	VAR,
	FUNC,
	PARAS,
	PARASF,
	PARA,
	STMTBLOCK,
	STMT,
	ESTMT,
	DEFS,
	DEF,
	DECS,
	DEC,
	INIT,
	FEXP,
	EXP,
	ARRS,
	ARGS
} NodeType;

struct Node {
	int		line_num;
	string		name;
	int 		size;
	int 		capacity;	
	NodeType 	node_type;
	Node**		children;
};

#endif //NODE_H
