#ifndef NODE_H
#define NODE_H

typedef enum {
	Expr,// expression
	Stmt,// statement
	Func,// function
	Decl,// declaration
	Prog // program
} NodeType;
typedef enum {
	Expr_Assign,
	Expr_UnaryAssign,
}ExprType;
typedef enum {
	Stmt_Break;
	Stmt_Continue;
	Stmt_Return;
	Stmt_If;
	Stmt_For;
	Stmt_IfElse;
	Stmt_StatementBlock
}StmtType;
struct Node {
	Node*		parent;
	int		line_num;
	string		node_name;	
	NodeType 	node_type;

	ExprType	expr_type;
	bool 		is_lvalue_expr; 
	Node*		eleft;
	Node*		right;


}

#endif //NODE_H
