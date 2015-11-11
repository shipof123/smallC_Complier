#include <string>
#include <vector>
#include <iostream>
using namespace std;


enum Node_t{ EXP, STMT, FUNC, DEC, PROG};
enum Dec_t{Dec_global_var_arr,
		   Dec_global_struct,
		   Dec_local_var_arr,
		   Dec_local_struct};

enum Exp_t{ Exp_assign,
			Exp_unaryAssign,
			Exp_int,
			Exp_binaryOp,
			Exp_unaryOp,
			Exp_variable,
			Exp_array,
			Exp_function,
			Exp_struct};

enum Stmt_t{Stmt_break,
			Stmt_continue,
			Stmt_return,
			Stmt_if,
			Stmt_ifElse,
			Stmt_stmtBlock,
			Stmt_for,
			Stmt_read,
			Stmt_write};
enum Op_t{  Op_MUL,
			Op_DIV,
			Op_MOD,
			OP_PLUS,
			Op_MINUS,
			Op_SHL,
			Op_SHR,
			Op_GT,
			Op_GE,
			Op_LT,
			Op_LE,
			Op_EQU,
			Op_NEQ,
			Op_BITAND,
			Op_BITXOR,
			Op_BITOR,
			Op_BITNOT,
			Op_LOGAND,
			Op_LOGOR,
			Op_LOGNOT,
			Op_PLUSPLUS,
			Op_MINUSMINUS};
struct Node;

enum Exp_t{ Exp_assign,
			Exp_unaryAssign,
			Exp_int,
			Exp_binaryOp,
			Exp_unaryOp,
			Exp_variable,
			Exp_array,
			Exp_function,
			Exp_struct};

struct ExpNode
{
	//-------------------------------------------------//
	Exp_t exp_type;
	bool exp_islvalue;
	string exp_name;
	// int expression
	int exp_int_val;
	// variable expression
	vector<Node*>* exp_array_vector;
	// array expression
	vector<Node*>* exp_argument_vector;
	// struct member expression
	string exp_struct_name;
	// Op expression
	Node* exp_left;
	Node* exp_right;
	Op_t exp_op;
	void init_expr_assign(Node* left, Node* right) {
		exp_type = Exp_assign;
		exp_left = left;
		exp_right = right;
	}
	void init_expr_unaryAssign(Op_t op, Node* right) {
		exp_type = Exp_unaryAssign;
		exp_op = op;
		exp_right = right;
	}
	void init_expr_int(int val) {
		exp_type = Exp_int;
		exp_int_val = val;
	}
	void init_expr_binaryOp(Node* left, Op_t op, Node* right) {
		exp_type = Exp_binaryOp;
		exp_left = left;
		exp_right = right;
		exp_op = op;
	}
	void init_expr_unaryOp(Op_t op, Node* right) {
		exp_type = Exp_unaryOp;
		exp_op = op;
		exp_right = right;
	}
	void init_expr_variable_array(string* name, vector<Node*>* array_vector) {
		exp_name = *name;
		if(array_vector->size() == 0)
			exp_type = Exp_variable;
		else {
			exp_type = Exp_array;
			exp_array_vector = array_vector;
		}
	}
	void init_expr_function(string* name, vector<Node*> argument_vector) {
		exp_type = Exp_function;
		exp_name = *name;
		exp_argument_vector = argument_vector;
	}
	void init_expr_struct(string* name, string* membername) {
		exp_type = Exp_struct;
		exp_name = name;
		exp_struct_name = membername;
	}
};
struct var_array
{
	string var_name;
	vector<int> var_array_vector;
	vector<Node*>* var_init_vector;
};
struct DecNode
{
	//-------------------------------------------------//
	Dec_t dec_type;
	// variable array declaration
	vector<var_array* >* dec_var_array_vector;
	// struct declaration
	string dec_struct_name;
	vector<string>* dec_struct_member;
	vector<string>* dec_struct_vector;
};
struct StmtNode
{
	Stmt_t stmt_type;
	// return expression
	Node* return_expr;
	// if then (else) expression
	Node* if_expr;
	Node* then_stmt;
	Node* else_stmt;
	// for stmt
	Node* init_expr;
	Node* cond_expr;
	Node* update_expr;
	Node* for_stmt;
	// stmt block
	vector<Node*>* dec_in_block;
	vector<Node*>* stmt_in_block;
	// read and write
	Node* io_expr;
};
struct FuncNode
{
	vector<string>* paras;
	Node* func_body;
};

struct Node
{
	Node* parent;
	int n_lineno;
	Node_t node_type;
	//string n_name;

	ExpNode* expression;
	DecNode* declaration;
	StmtNode* statement;
	FuncNode* function;
	// Program
	vector<Node*> extern_decs;

	Node(int lineno, Node_t type) {
		n_lineno = lineno;
		node_type = type;
	}
};
