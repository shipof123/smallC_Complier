/*******************************************************************************************
* File: semantic.h
* entrance: semantics(Node*)
* semantic analysis for the AST
*
********************************************************************************************/

#ifndef FILE_SEMANTICS_H
#define FILE_SEMANTICS_H
#include <vector>
#include <map>
#include "includes.h"
#include "ast.h"

using namespace std;
#define MAX_LEVEL 100
#define MAX_DEPTH 100
#define MAX_FUNCS 100
struct ptr_cmp { // for comparision of char*
	bool operator()(const char* s1, const char* s2) const {
		return strcmp(s1,s2) < 0;
	}
};
struct SymbolTable {
	map <const char*,const char*,ptr_cmp> table; // id table
	map <char*, vector<char *>, ptr_cmp > struct_table; // struct member table
	map <char*, vector<char *>, ptr_cmp > struct_id_table;// struct name table
	map < char*, int, ptr_cmp > struct_name_width_table;//
        map <char*, int, ptr_cmp> width_table; // records the num of "int"s, the actual width should be 4 times of that
	map <char*, vector<int>, ptr_cmp> array_size_table;
	int parent_index;//which record the index of his parent in the upper level; -1 means it's the gloabl scope
} env[MAX_LEVEL][MAX_DEPTH];

int case_extvars = 0; // to determine scheme for extvar

int level = 0,cnt[MAX_LEVEL];// keep track num of symbol tables of this level
map <char*, vector<int>, ptr_cmp > func_table;
map <char*, int, ptr_cmp> func_cnt_table;
map <char*,map<int,char*>, ptr_cmp > func_overload_table;
vector <int> tmp_array_size_vector;
vector <int> func_vector[MAX_FUNCS];
vector <char*> struct_vector[MAX_FUNCS];
set <char*, ptr_cmp> func_set[MAX_FUNCS], struct_set[MAX_FUNCS];
int func_cnt = 0, struct_cnt = 0, tmp_num_of_var = 0, func_vector_cnt = 0, struct_vector_cnt = 0, tmp_num = 1, tmp_num_struct = 0;
bool in_func = false, in_for = false, bool_main = false;//to help check classify whether a 'return' happens in a func

int StringToInt(char *s);
bool isReserved(char* s);
void report_err(const char *s1,const char *s2, int linenum);
int get_width_semantics(char* s);
void semantics_check(Node* p);
void semantics_check_program(Node* p);
void semantics_check_extdefs(Node* p);
void semantics_check_init(Node *p);
void semantics_check_fexp(Node *p, char *s);
void semantics_check_extdef(Node* p);
void semantics_check_sextvars(Node *p);
void semantics_check_stspec(Node* p);
void semantics_check_paras(Node *p,char *s);
char* semantics_check_type(Node *p);
void semantics_check_func(Node *p);
void semantics_check_extvars(Node *p);
void semantics_check_sextvars_1(char *s, Node *p);
bool semantics_check_id(char* s,int num);
void semantics_check_var(Node *p);
void semantics_check_stmtblock(Node *p);
void semantics_check_decs(Node *p);
void semantics_check_defs(Node* p);
void semantics_check_sdefs(Node *p);
void semantics_check_sdecs(Node *p, int in);
void semantics_check_extvar(Node *p);
void semantics_check_stmts(Node* p);
void semantics_check_arrs(Node *p);
void semantics_check_args(Node *p, char *s);
void semantics_check_exp(Node *p);
void check_left_value_exps(Node *p);
bool find_id(Node *p);
int find_struct_id(char* s, char*s2);
void semantics_check_stmt(Node *p);
void semantics(Node *p);


void semantics(Node *p) {
	semantics_check(p);
	if (!bool_main) {
		fprintf(stderr,"fatal error! undefined reference to main()\n");
		exit(1);
	}
}
void semantics_check(Node* p) {
	switch (p->node_type) {
		case Program: semantics_check_program(p); break;
		case Stmtblock: semantics_check_stmtblock(p); break;
		case Extdefs: semantics_check_extdefs(p); break;
		case Extdef: semantics_check_extdef(p); break;
		case Extvars: 
			if(case_extvars == 1)
			{
				semantics_check_extvars(p); break;
			}
			if(case_extvars == 2)
			{
				semantics_check_sextvars(p); break;
			}
		case Extvar: semantics_check_extvars(p); break;
		case Spec: semantics_check_stspec(p); break;
		case Stspec: semantics_check_stspec(p); break;
		case Func: semantics_check_func(p); break;
		case Type: semantics_check_type(p); break;
		case Stmts: semantics_check_stmts(p); break;
		case Stmt: semantics_check_stmt(p); break;
		case Defs: semantics_check_defs(p); break;
		//case _SDEFS: semantics_check_sdefs(p); break;
		case Decs: semantics_check_decs(p); break;
		case Var: semantics_check_var(p); break;
		case Init: semantics_check_init(p); break;
		case Fexp: semantics_check_fexp(p,NULL); break;
		case Exp: semantics_check_exp(p); break;
		case Arrs: semantics_check_arrs(p); break;
		case Operator: break;
		case Int: break;
		case Null: break;//do nothing
		//default: fprintf(stderr,"%s \n", p->name); assert(0);
	}
}

void semantics_check_program(Node* p) {//OK
	semantics_check_extdefs(p->children[0]);
}

void semantics_check_extdefs(Node* p) {//OK
	if(p->size !=0)
	{
		semantics_check_extdef(p->children[0]);
		semantics_check_extdefs(p->children[1]);
	}
}
void semantics_check_extdef(Node* p) {
	if (p->size == 2) {
		if (p->children[0]->children[0]->node_type == Type) // EXTDEF=>SPEC=>TYPE 
		{
			case_extvars = 1;
			semantics_check_extvars(p->children[1]); // extvars
		}
		else if (p->children[0]->children[0]->node_type == Stspec)
		{
			semantics_check_stspec(p->children[0]->children[0]);
			Node* nodeStspec = p->children[0]->children[0];
			if (nodeStspec->size==3) { // struct id sdefs case
				env[level][cnt[level]].struct_id_table[nodeStspec->children[1]->children[0]->name] = struct_vector[struct_vector_cnt];
				env[level][cnt[level]].struct_name_width_table[nodeStspec->children[1]->children[0]->name] = tmp_num_struct;
			}
			if (nodeStspec->size==2 && nodeStspec->children[1]->node_type == Id) { // struct ID case
				semantics_check_sextvars_1(nodeStspec->children[1]->name,p->children[1]); // sextvars
			}
			else {
				case_extvars = 2;
				semantics_check_sextvars(p->children[1]); // extvars struct id{} id; case
			}
		}
	}
	else { //function declarations
		semantics_check_func(p->children[1]);
		in_func = true;
		semantics_check_stmtblock(p->children[2]);
		in_func = false;
	}
}
void semantics_check_extvars(Node* p) {
	if(p->size == 0) return;
	else {
		semantics_check_extvar(p->children[0]);
	}
} 
void semantics_check_extvar(Node *p) {
	tmp_num = 1;
	tmp_array_size_vector.clear();
	Node* extvar = p;
	if(extvar->size == 1) {
		Node* dec = extvar->children[0];
		if(dec->size  == 1) {
			semantics_check_var(dec->children[0]);
		}
		else {
			semantics_check_var(dec->children[0]);				
			semantics_check_init(dec->children[2]);
		}	
	}
	else {
		Node* dec = extvar->children[0];
		if(dec->size  == 1) {
			semantics_check_var(dec->children[0]);
		}
		else {
			semantics_check_var(dec->children[0]);				
			semantics_check_init(dec->children[2]);
		}	
		semantics_check_extvar(extvar->children[1]);
	}	
}
void semantics_check_init(Node *p) {
	if (p->children[0]->node_type == Exp) {
		semantics_check_exp(p->children[0]);
	}
	else {
		semantics_check_args(p,NULL); //array initialization
	}
}

void semantics_check_fexp(Node *p,char* s) {
	int i;
	if (s!=NULL) {
		if (p->size==0);
		else {++func_cnt_table[s];}
	}
	if (p->size>0) {
		semantics_check_exp(p->children[0]);
	}
}

void semantics_check_sextvars_1(char *s, Node *p) {
	if (p->size==0) return;
	int tmp_level = level, tmp_depth = cnt[level];
	while (1) {
		if (env[tmp_level][tmp_depth].struct_id_table.find(s)!=env[tmp_level][tmp_depth].struct_id_table.end()) { 
			break;
		}
		else {
			int parent = env[tmp_level][tmp_depth].parent_index;
			if (parent==-1||tmp_level==0) {report_err("No such struct named~",s,p->line_num);}
			else {
				tmp_level--;
				tmp_depth = parent;
			}
		}
	}
	if (semantics_check_id(p->children[0]->name,p->children[0]->line_num)&&func_table.find(p->children[0]->name)!=func_table.end()) {
		report_err("redefinition of",p->children[0]->name,p->children[0]->line_num);
	}
	else {
		env[level][cnt[level]].struct_table[p->children[0]->name] = env[tmp_level][tmp_depth].struct_id_table[s];
		env[level][cnt[level]].table[p->children[0]->name] = "struct";
		//fprintf(stderr,"flag %s  \n", p->children[0]->name);
		env[level][cnt[level]].width_table[p->children[0]->name] = env[tmp_level][tmp_depth].struct_name_width_table[s];
	}
	if (p->size==2) semantics_check_sextvars_1(s,p->children[1]);
}

void semantics_check_sextvars(Node *p) {
	if (p->size==0) return;
	if (semantics_check_id(p->children[0]->name,p->children[0]->line_num)&&func_table.find(p->children[0]->name)==func_table.end()) {
		env[level][cnt[level]].table[p->children[0]->name] = "struct";
		env[level][cnt[level]].struct_table[p->children[0]->name] = struct_vector[struct_vector_cnt];
		env[level][cnt[level]].width_table[p->children[0]->name] = tmp_num_struct;
		if (level>0)
			env[level][cnt[level]].parent_index = cnt[level-1]; //which stmtblock in the upper level is my parent
		else 	env[level][cnt[level]].parent_index = -1;
	}
	else {
		report_err("redefinition of",p->children[0]->name,p->children[0]->line_num);
	}
	if (p->size==2) { semantics_check_sextvars(p->children[1]);}
}

void semantics_check_stspec(Node* p) {  //struct
	++struct_cnt;
	if (!strcmp(p->name,"stspec identifier {}")) {
		++struct_vector_cnt;
		tmp_num_struct = 0;
		semantics_check_sdefs(p->children[2]);
	}
	else if (!strcmp(p->name,"stspec {}")) {
		++struct_vector_cnt;
		tmp_num_struct = 0;
		semantics_check_sdefs(p->children[1]);
	}
}

void semantics_check_paras(Node *p,char *s) {
	if (p->size>=1) {
		++tmp_num_of_var;
		if (env[level+1][cnt[level+1]+1].table.find(p->children[0]->name)==env[level+1][cnt[level+1]+1].table.end()) {
		 // to see whether multiple declarations of a variable
			env[level+1][cnt[level+1]+1].table[p->children[0]->name] = "int";
			env[level+1][cnt[level+1]+1].width_table[p->children[0]->name] = 1;
		}
		else {
			report_err("redefinition of", p->children[1]->name,p->children[1]->line_num);
		}
	}
	if (p->size==2) {semantics_check_paras(p->children[1],s);}
}


char* semantics_check_type(Node *p) {
	return p->name;
}

bool vector_find(vector<int> p, int num) {
	int i, sz = p.size();
	for (i = 0; i < sz; ++i) {
		if (p[i]==num) return true;
	}
	return false;
}

void rename(Node *p, int num) {
	char *s = new char[strlen(p->name)+2];
	s[0] = '_';
	s[1] = num + '0';
	int i;
	for (i = 2; i < 2+strlen(p->name); ++i) {
		s[i] = p->name[i-2];
	}
	p->name = s;
}

void semantics_check_func(Node *p) { 
	++func_cnt;
	if (semantics_check_id(p->children[0]->name,p->children[0]->line_num)) { // no conflict with the name of int variables and struct variables
		tmp_num_of_var = 0;
		semantics_check_paras(p->children[1],p->children[0]->name);
		if (func_table.find(p->children[0]->name)==func_table.end()) { // new function name
			if (!strcmp(p->children[0]->name,"main")) {bool_main = true;}
			func_table[p->children[0]->name] = func_vector[func_vector_cnt];
			func_table[p->children[0]->name].push_back(tmp_num_of_var);
			++func_vector_cnt;
		}
		else {	// function name exists, check whether it's an overloaded function
			/*just rename it!!!!!!!!!!!*/
			if (!vector_find(func_table[p->children[0]->name],tmp_num_of_var)) { //overloaded function
		   		func_table[p->children[0]->name].push_back(tmp_num_of_var);
				if (func_table[p->children[0]->name].size()>=2) {
					func_overload_table[p->children[0]->name][func_table[p->children[0]->name][0]] = p->children[0]->name;
					char *ch = p->children[0]->name;
					rename(p->children[0],tmp_num_of_var);
					func_overload_table[ch][tmp_num_of_var] = p->children[0]->name;
					func_table[p->children[0]->name] = func_vector[func_vector_cnt];
					func_table[p->children[0]->name].push_back(tmp_num_of_var);
					++func_vector_cnt;
				}
			}
			else report_err("multiple definitions of", p->children[0]->name,p->children[0]->line_num);
		}
		
	}
	else {
		report_err("conflicting names of", p->children[0]->name,p->children[0]->line_num);
	}
}



bool semantics_check_id(char* s,int num) { 
	if (isReserved(s)) {
		report_err("Reserved words can not be used as identifiers", s,num);
		return false;
	}
	if (env[level][cnt[level]].table.find(s)!=env[level][cnt[level]].table.end()){	//already exist
				report_err("redeclearation of",s,num);
				return false; 
	}
	else return true; //new variable name
}

void semantics_check_var(Node *p) {//OK
	if (p->size==1) {
		if (semantics_check_id(p->children[0]->name,p->children[0]->line_num)) {  //new variable name
			if (level==0&&func_table.find(p->children[0]->name)!=func_table.end()) 
				{report_err("redefinition of", p->children[0]->name,p->children[0]->line_num);}
			env[level][cnt[level]].table[p->children[0]->name] = "int";
			env[level][cnt[level]].width_table[p->children[0]->name] = tmp_num;
			int i,j;
			vector <int> final_vector;
			for (i = 0; i < tmp_array_size_vector.size(); ++i) {
				int t = 4;
				for (j = i+1; j < tmp_array_size_vector.size(); ++j) {
					t *= tmp_array_size_vector[i];
				}
				final_vector.push_back(t);
			}
			env[level][cnt[level]].array_size_table[p->children[0]->name] = final_vector;
		}
		else {report_err("redefinition of", p->children[0]->name,p->children[0]->line_num);}
	}
	else {
		int intnum = StringToInt(p->children[1]->name);
		if (intnum < 0) report_err("index can't be less than zero",NULL,p->line_num);
		tmp_array_size_vector.push_back(intnum);
		tmp_num *= intnum;
		semantics_check_var(p->children[0]);
	}
}

void semantics_check_stmtblock(Node *p) {
	++level;
	++cnt[level];
	if (level>0)
		env[level][cnt[level]].parent_index = cnt[level-1]; //which stmtblock in the upper level is my parent
	else 	env[level][cnt[level]].parent_index = -1;
	semantics_check_defs(p->children[0]);
	semantics_check_stmts(p->children[1]);
	--level;
}

void semantics_check_defs(Node* p) {
	int i;
	if (p->size==0) return;
	if (!strcmp(p->name,"defs1")) {
		semantics_check(p->children[0]);
		semantics_check(p->children[1]);
		semantics_check(p->children[2]);
		return;
	}
	if (p->children[0]->size==2&&!strcmp(p->children[0]->name,"stspec")) {
			semantics_check_stspec(p->children[0]);
			semantics_check_sextvars_1(p->children[0]->children[1]->name,p->children[1]);
			return;
		}
	for (i = 0; i < p->size; ++i) {
		semantics_check(p->children[i]);
	}
}

void semantics_check_decs(Node *p)
{	
	int i;
	tmp_num = 1;
	tmp_array_size_vector.clear();
	semantics_check_var(p->children[0]);
	for (i = 1; i < p->size;++i) {
		semantics_check(p->children[i]);
	}
}

void semantics_check_sdefs(Node *p) { //inside of a struct
	int i;
	if (p->size==0) return;
	semantics_check_sdecs(p->children[1],1);
	semantics_check_sdefs(p->children[2]);
}

void semantics_check_sdecs(Node *p, int in_struct) {
	if (in_struct) {
		++tmp_num_struct;
		if (struct_set[struct_cnt].find(p->children[0]->name)==struct_set[struct_cnt].end()) {//no multiple declarations in a struct
			struct_set[struct_cnt].insert(p->children[0]->name);
			struct_vector[struct_vector_cnt].push_back(p->children[0]->name);
		}
		else {
			report_err("redefinition of", p->children[0]->name,p->children[0]->line_num);
		}
		if (p->size==2) {
			semantics_check_sdecs(p->children[1], in_struct);
		}
	}
	else {
	if (semantics_check_id(p->children[0]->name,p->children[0]->line_num)&&func_table.find(p->children[0]->name)==func_table.end()) {
			env[level][cnt[level]].table[p->children[0]->name] = "struct";
			env[level][cnt[level]].struct_table[p->children[0]->name] = struct_vector[struct_vector_cnt];
			env[level][cnt[level]].width_table[p->children[0]->name] = tmp_num_struct;
		if (level>0)
			env[level][cnt[level]].parent_index = cnt[level-1]; //which stmtblock in the upper level is my parent
		else 	env[level][cnt[level]].parent_index = -1;
		}
		else {
			report_err("redefinition of",p->children[0]->name,p->children[0]->line_num);
		}
	}
}

void semantics_check_stmts(Node* p) {
	int i;
	for (i = 0; i < p->size; ++i) {
		semantics_check(p->children[i]);
	}
}

void semantics_check_arrs(Node *p) { //arrays
	int i;
	for (i = 0; i < p->size; ++i) {
		semantics_check(p->children[i]);
	}
}

void semantics_check_args(Node *p, char *s) { //arguments of function
	//cout << "args" << endl;
	if (s==NULL) return;
	if (p->size==2) {
		semantics_check_fexp(p->children[0],s);//1 means it's the check process of arguemnts
		semantics_check_args(p->children[1],s);
	}
	else {
		semantics_check_fexp(p->children[0],s);
	}
}

int vector_find_index(vector <int> s, int num) {
	int sz =  s.size();
	int i;
	for (i = 0; i < sz; ++i) {
		if (s[i]==num) return i;
	}
}

void semantics_check_exp(Node *p) {
	if (p->size == 2 && p->children[1]->node_type == Args) { // id args
		if (func_table.find(p->children[0]->name)==func_table.end()) { //don't find the function
			report_err(p->children[0]->name,"not declared",p->children[0]->line_num);
		}
		else {
			int func_tmp = func_cnt_table[p->children[0]->name];
			func_cnt_table[p->children[0]->name] = 0;
			semantics_check_args(p->children[1],p->children[0]->name);
		if (vector_find(func_table[p->children[0]->name],func_cnt_table[p->children[0]->name])) {
				// num of variables match!
				int v_num = vector_find_index(func_table[p->children[0]->name],func_cnt_table[p->children[0]->name]);
				if (v_num>0) {
					int t_num = func_cnt_table[p->children[0]->name];
					rename(p->children[0],t_num); 
				}
			}
			else {
				report_err("number of arguments doesn't match: function", p->children[0]->name,p->children[0]->line_num);
			}
			func_cnt_table[p->children[0]->name] = func_tmp;
		}
	}
	else if (p->size == 1 && p->children[0]->node_type == Exp) {
		semantics_check_exp(p->children[0]);
	}
	else if (p->size == 2 && (p->children[1]->node_type == Arrs || p->children[1]->node_type == Null)) { //intergers or arrays!!!!
		if (!find_id(p->children[0])) {
			report_err("No variable named",p->children[0]->name,p->children[0]->line_num);
		}
		if (find_struct_id(p->children[0]->name,NULL)) {
				report_err(p->children[0]->name,"is a struct",p->children[0]->line_num);
		}
		if (p->children[1]->size==0) {
			if (get_width_semantics(p->children[0]->name)!=1) {
				report_err(p->children[0]->name,"is not an integer",p->children[0]->line_num);
			}
		}
		if (p->children[1]->size!=0) {  // it should be an array
			if (get_width_semantics(p->children[0]->name)==1) {
				report_err(p->children[0]->name,"is not array",p->children[0]->line_num);
			}
		}
	}
	else if (p->size == 2 && p->children[0]->node_type == UnaryOp) { //unary operations
		if (!strcmp(p->children[0]->name,"++")||!strcmp(p->children[0]->name,"--")) {
			check_left_value_exps(p->children[1]);
		}
		semantics_check_exp(p->children[1]);
	}
	else if (p->size == 3 && p->children[2]->node_type == Id) { //structs!!!
		int sjtu = find_struct_id(p->children[0]->children[0]->name,p->children[2]->name);
		if (sjtu==0) {
			report_err("No such struct named", p->children[0]->name,p->children[0]->line_num);
		}
		else if (sjtu==-1){
			report_err("struct has no varibale named", p->children[2]->name,p->children[2]->line_num);
		}
	}
	else if (p->size == 3 && strcmp(p->children[1]->name, "=") ==0) {
		check_left_value_exps(p->children[0]);
		semantics_check_exp(p->children[0]);
		semantics_check_exp(p->children[1]);
	}
	else if (!strcmp(p->children[0]->name, "read")) {
		check_left_value_exps(p->children[1]);
	}
	else if (!strcmp(p->children[0]->name, "write")) {
		check_left_value_exps(p->children[1]);
	}	
	else if (p->size == 3 && p->children[2]->node_type == Exp){
		semantics_check_exp(p->children[0]);
		semantics_check_exp(p->children[2]);
	}
}

int find_struct_id(char *s,char *s2) {
	int tmp_level = level, tmp_depth = cnt[level];
        int bool_find = 0;
	while (1) {
if (env[tmp_level][tmp_depth].table.find(s)!=env[tmp_level][tmp_depth].table.end()&&!strcmp(env[tmp_level][tmp_depth].table[s],"struct")) { 
			//find
			if (s2==NULL) return 1;
			int i;
			for (i = 0; i < env[tmp_level][tmp_depth].struct_table[s].size(); ++i) {
				
				if (!strcmp(env[tmp_level][tmp_depth].struct_table[s][i],s2)) return 1;
			}
			return -1;
		}
		else {
			int parent = env[tmp_level][tmp_depth].parent_index;
			if (parent==-1||tmp_level==0) break;
			else {
				tmp_level--;
				tmp_depth = parent;
			}
		}
	}
	return bool_find;
}

bool find_id(Node *p) {
	int tmp_level = level, tmp_depth = cnt[level];
	bool bool_find = false;
	while (1) {
		//cout << "tmp_level" << tmp_level << "tmp_depth" << tmp_depth << endl;
		if (env[tmp_level][tmp_depth].table.find(p->name)!=env[tmp_level][tmp_depth].table.end()) { //find
			//cout << "find" << endl;
			return true;
		}
		else {
			int parent = env[tmp_level][tmp_depth].parent_index;
			if (parent==-1||tmp_level==0) break;
			else {
				tmp_level--;
				tmp_depth = parent;
			}
		}
	}
	return bool_find;
}

void check_left_value_exps(Node *p) {
	//cout << "p->name " << p->name << endl;
	if (p->node_type == Exp) {
		return;
	}
	if (p->size == 3 && strcmp(p->children[0]->name, "=") == 0) {
		check_left_value_exps(p->children[0]);
		semantics_check_exp(p->children[2]);
	}
	else if (p->size == 3 && p->children[2]->node_type == Id) { //structs!!!
		return;
	}
	else if (p->size == 2 && (p->children[1]->node_type == Arrs || p->children[1]->node_type == Null)) { //intergers or arrays!!!!
		return;
	}	
	else if (p->size == 1 && p->children[0]->node_type == Exp) {
		return;
	}
	else {report_err("lvalue required as left operand assignment",NULL,p->line_num);}
}

void semantics_check_stmt(Node *p) {
	if (p->size == 1 && (p->children[0]->node_type == Exp || p->children[0]->node_type == Stmtblock)) { // exp or stmtblock
		int i;
		for (i = 0; i < p->size; ++i) {
			semantics_check(p->children[i]);
		}
	}
	else if (p->size == 2) { // return exp
		if (!in_func) report_err("return not in a function",NULL,p->line_num);
		semantics_check_exp(p->children[1]);
	}
	else if (p->size == 4) { // if (x) {} else{}
		int i;
		for (i = 0; i < p->size; ++i) {
			semantics_check(p->children[i]);
		}
	}
	else if (p->size == 5) { // for (;;) {}
		int i;
		for (i = 1; i <= 3; ++i) {
			semantics_check_fexp(p->children[i],NULL);
		}
		in_for = true;
		semantics_check_stmt(p->children[p->size-1]);
		in_for =  false;
	}
	else { // break and continue
		if (!in_for) {
			report_err(p->children[0]->name,"not in a loop",p->children[0]->line_num);
		}
	}
}
int get_width_semantics(char* s) {
	int tmp_level = level, tmp_depth = cnt[level];
	while (1) {
		if (env[tmp_level][tmp_depth].table.find(s)!=env[tmp_level][tmp_depth].table.end()) { //find
			return env[tmp_level][tmp_depth].width_table[s];
		}
		else {
			int parent = env[tmp_level][tmp_depth].parent_index;
			if (parent==-1||tmp_level==0) assert(0);
			else {
				tmp_level--;
				tmp_depth = parent;
			}
		}
	}
}

int StringToInt(char *s) {
	assert(s!=NULL);
	if (strlen(s)>=2&&s[0]=='0'&&(s[1]=='x'||s[1]=='X')) return strtol(s,NULL,16);
	if (strlen(s)>=2&&s[0]=='0'&&s[1]!='x'&&s[1]!='X') return strtol(s,NULL,8);
	return strtol(s,NULL,10);	
}

bool isReserved(char* s) {
	if (strcmp(s,"int")==0||strcmp(s,"return")==0||strcmp(s,"break")==0||strcmp(s,"for")==0||strcmp(s,"if")==0) return true;
	if (strcmp(s,"else")==0||strcmp(s,"continue")==0||strcmp(s,"struct")==0||strcmp(s,"read")==0||strcmp(s,"write")==0) return true;
	return false;
}

void report_err(const char *s1, const char *s2, int linenum) {
	fprintf(stderr,"at line %d:\t",linenum);
	if (s1!=NULL) fprintf(stderr,"%s ",s1);
	if (s2!=NULL) fprintf(stderr,"%s ",s2);
	fprintf(stderr,"\n");
	exit(1);
}



#endif
