/*******************************************************************************************
* File: llvm.h
* entrance: trans_Program(Node*)
* Generating LLVM IR assembly code in after the traverse
*
********************************************************************************************/

#ifndef LLVM_H
#define LLVM_H

#include "includes.h"
int numStructMember = 0;
char* structName;

struct symbol
{
	char* word; // name for id
	int type;   // to determine '%' or '@'
	char* arrSize; // store the size of the array for translation
	char* structName; // stspec name
	int   numStructMem; // size of the struct, 
};
struct symbol* symTable[27][40]={0};

int regNum, callNum, ifNum, forNum, arridxNum; //for register allocation
int paraFlag = 0; //paremetres flag
int paraSize = 0; //parameters point
char* paraArr[10]; //parametres array
int entryDepth = 0; //depth of stmtblocks
int loadFlag = 1; //load or not for left value expression
char* arrName; //array Name
char* arrSize; //array size


int getDim(char ch);

void trans_Program(Node* root);
void trans_Extdefs(Node* root);
void trans_Extdef(Node* rt);
void trans_ExtvarsStruct(Node* rt);
void trans_ExtdefStructOpttag(Node* rt);
void trans_DefsStructOpttag(Node* rt);
void trans_DefStructOpttag(Node* rt);
void trans_ExtdefStructId(Node* rt);
void trans_ExtvarsStructId(Node* rt);
void trans_ExtvarStructId(Node* rt);
void trans_DecStructId(Node* rt);
void trans_ExtvarsType(Node* rt);
void trans_ExtvarType(Node* rt);
void trans_DecExt(Node* rt);
void trans_ArgsExt(Node* rt);
void trans_Func(Node* rt);
void trans_Parasf(Node* rt);
void trans_Para(Node* rt);
void trans_Stmtblock(Node* rt);
void trans_Defs(Node* rt);
void trans_Def(Node* rt);
void trans_Decs(Node* rt);
void trans_DecInner(Node* rt);
void trans_ArgsInner(Node* rt);
void trans_Stmts(Node* rt);
void trans_Stmt(Node* rt);
char* trans_Exp(Node* rt);
void trans_ArgsFunc(Node* rt);
/* help function for symbol table */
int getDim(char ch)
{
	int dim = ch-'a';
        if (dim<0) dim = ch-'A';
        if (ch=='_') dim = 26;
	return dim;
}
/* entrance of the traverse*/
void trans_Program(Node* root)
{  
	printf("@.str = private unnamed_addr constant [3 x i8] c\"%%d\\00\", align 1\n");
    	printf("@.str1 = private unnamed_addr constant [2 x i8] c\"\\0A\\00\", align 1\n"); //这玩意儿是为LLVM IR中的换行符准备的

    	trans_Extdefs(root->children[0]);

    	printf("\ndeclare i32 @__isoc99_scanf(i8*, ...) #1\n");
    	printf("declare i32 @printf(i8*, ...) #1\n");
}
/* for extdefs*/
void trans_Extdefs(Node* root)
{
	if(root->size == 2)
	{
		trans_Extdef(root->children[0]);
		trans_Extdefs(root->children[1]);
	}
}
/* for extdef, namely two kinds, function or not, if it is a spec, determine it is type or not*/
void trans_Extdef(Node* rt)
{
	if(rt->children[1]->node_type != Func) // SPEC EXTVARS SEMI
	{
		if(rt->children[0]->children[0]->node_type == Type) // Type, int case
		{
			// Extvar should not be void, error checking has been done.
			trans_ExtvarsType(rt->children[1]);
		}
		else // STSPEC, struct case
		{
			trans_ExtvarsStruct(rt);
		}
	}
	else	//SPEC FUNC STMTBLOCK
	{
		// return type can only be Type in this case
		trans_Func(rt->children[1]);
		trans_Stmtblock(rt->children[2]);
	}
}
/* for extdef with struct, two kinds, one is only id, the other is need for initialization*/
void trans_ExtvarsStruct(Node* rt) // rt -> Extdef
{
	Node* tmp = rt->children[0]->children[0]; // STSPEC
	if(tmp->children[1]->node_type == Id) // STRUCT ID
	{
		trans_ExtdefStructId(rt);
	}
	else // Struct opttag lc defs rc
	{
		trans_ExtdefStructOpttag(tmp);
	}
}
/* for extdef, with external struct initilizaiton*/
void trans_ExtdefStructOpttag(Node* rt) // Struct opttag lc defs rc, rt->STSPEC
{
	// opttag must be id at this time
	Node* id_node = rt->children[1]->children[0];
	char* tmp = new char[200];
	strcpy(tmp,id_node->name);
	
	printf("%%struct.%s = type { ", tmp);	
	trans_DefsStructOpttag(rt->children[2]);
	printf(" }\n");
	
	numStructMember = 0;	//clear number of struct members, needed for later translation for others
}
/* for defs with members*/
void trans_DefsStructOpttag(Node* rt) // rt-> Defs
{
	if(rt->size == 2) // DEF DEFS
	{
		trans_DefStructOpttag(rt->children[0]);
		numStructMember++;
		if(rt->children[1]->node_type != Null)
		{
			printf(", ");
			trans_DefsStructOpttag(rt->children[1]);
		}
	}
}
/* for def with id, store id in symbol table*/
void trans_DefStructOpttag(Node* rt) // rt-> Def
{
	// definitions inside the struct can only be int variables
	// error checking has been done before :)
	Node* nodeId = rt->children[1]->children[0]->children[0]->children[0]; // DEF->DECS->DEC->VAR->ID
	char* tmp = (char*)malloc(sizeof(char)*200);
	strcpy(tmp,nodeId->name);
	
	int dim = getDim(tmp[0]);
	int i = 0;
	while(symTable[dim][i]) ++i;
	symTable[dim][i] = (struct symbol*)malloc(sizeof(struct symbol));
	
	struct symbol* s = symTable[dim][i];
	s->word = (char*)malloc(sizeof(char)*200);
	strcpy(s->word, tmp);
	s->numStructMem = numStructMember;

	printf("i32");
}
/* for extdef with struct id, store id in symbol table*/
void trans_ExtdefStructId(Node* rt) // struct id, rt->Extdef
{
	Node* nodeId = rt->children[0]->children[0]->children[1]; // ID
	structName = (char*)malloc(sizeof(char)*200);
	strcpy(structName, nodeId->name);
	
	trans_ExtvarsStructId(rt->children[1]);
	
	free(structName);
}
/* for extvars with struct id, store id in symbol table*/
void trans_ExtvarsStructId(Node* rt) // rt->Extvars
{
	if(rt->node_type == Null) return;
	trans_ExtvarStructId(rt->children[0]);
}
/* for extvar with struct id*/
void trans_ExtvarStructId(Node* rt) // rt->Extvar
{
	if(rt->size == 2) //DEC COMMA EXTVAR
	{
		trans_DecStructId(rt->children[0]);
		trans_ExtvarStructId(rt->children[1]);
	}
	else //DEC
	{
		trans_DecStructId(rt->children[0]);
	}	
}
/* for decs with struct id, find id in symbol table*/
void trans_DecStructId(Node* rt) // rt-> Dec
{
	Node* nodeId = rt->children[0]->children[0];
	char* tmp = (char*)malloc(sizeof(char)*200);
	strcpy(tmp, nodeId->name);
	int index = getDim(tmp[0]);
	
	int i=0;
	while (symTable[index][i]) i++;
	symTable[index][i] = (struct symbol*)malloc(sizeof(struct symbol));
	struct symbol* s = symTable[index][i];
	s->word = (char*)malloc(sizeof(char)*200);
	strcpy(s->word,tmp);
	s->structName = (char*)malloc(sizeof(char)*200);
	strcpy(s->structName,structName);
	s->type = 'g';

	printf("@%s",tmp);
	printf(" = common global %%struct.%s zeroinitializer, align 4\n",structName);
}
/* for extvars with type*/
void trans_ExtvarsType(Node* rt) // rt->Extvars, spec->id case
{
	if(rt->node_type == Null) return;
	trans_ExtvarType(rt->children[0]);
}
/* for extvar with type*/
void trans_ExtvarType(Node* rt)
{
	if(rt->size == 2) // DEC COMMA EXTVAR
	{
		trans_DecExt(rt->children[0]);
		trans_ExtvarType(rt->children[1]);
	}
	else // DEC
	{
		trans_DecExt(rt->children[0]);
	}
}
/* for exteral declarations with four cases*/
void trans_DecExt(Node* rt) // rt->Dec
{
	// DEC=> VAR
	//    => VAR ASSIGNOP INIT
	if(rt->size == 1) //var
	{
		Node* nodeVar = rt->children[0]; //node of VAR
		if (nodeVar->size == 1) //case 1. id
		{
			printf("@");
			Node* nodeId = nodeVar->children[0];
			char* tmp = (char*)malloc(sizeof(char)*60);
			strcpy(tmp, nodeId->name);
			
			int index = getDim(tmp[0]);
			int i=0;
			while (symTable[index][i]) i++;
			symTable[index][i] = (struct symbol*)malloc(sizeof(struct symbol));
			struct symbol* s = symTable[index][i];
			s->word = (char*)malloc(sizeof(char)*60);
			strcpy(s->word,tmp);
			s->type = 'g';

			printf("%s",tmp);
			printf(" = common global i32 0, align 4\n");
		}
		else //id[int]
		{
			//@b = common global [20 x i32] zeroinitializer, align 4
			printf("@");
			Node* nodeId = nodeVar->children[0]->children[0]; // only one dimention array

			char* tmp = (char*)malloc(sizeof(char)*60);
			strcpy(tmp, nodeId->name);
			int index = getDim(tmp[0]);
			int i=0;
			while (symTable[index][i]) i++;
			symTable[index][i] = (struct symbol*)malloc(sizeof(struct symbol));
			struct symbol* s = symTable[index][i];
			s->word = (char*)malloc(sizeof(char)*60);
			strcpy(s->word,tmp);
			s->type = 'g';

			printf("%s",tmp);
			printf(" = common global [");
			Node* nodeInt = nodeVar->children[1];
			int trans = strtol(nodeInt->name, NULL, 0); // error checking here, can not smaller than 0
			printf("%d", trans); 

			s->arrSize = (char*)malloc(sizeof(char)*60);
			sprintf(s->arrSize,"%d", trans);

			printf(" x i32] zeroinitializer, align 4\n");
		}
	}
	else // var = init 
	{
		Node* nodeVar = rt->children[0]; //node of VAR
		if (nodeVar->size == 1) //case 1  a = 2 
		{
			 //@ans = global i32 0, align 4
			printf("@");
			Node* nodeId = nodeVar->children[0];
			char* tmp = (char*)malloc(sizeof(char)*60);
			strcpy(tmp, nodeId->name);
			int index = getDim(tmp[0]);
			int i=0;
			while (symTable[index][i]) i++;
			symTable[index][i] = (struct symbol*)malloc(sizeof(struct symbol));
			struct symbol* s = symTable[index][i];
			s->word = (char*)malloc(sizeof(char)*60);
			strcpy(s->word,tmp);
			s->type = 'g';

			printf("%s",tmp);

			Node* nodeInit = rt->children[2]->children[0]->children[0]; // int, error checking
			
			int trans = strtol(nodeInit->name, NULL, 0); // error checking here, can not smaller than 0

			printf(" = global i32 %d, align 4\n", trans);
		}
		else //id[int] = {1,2,3};
		{
			//A little bit complicated
			//@mat = global [4 x i32] [i32 0, i32 1, i32 1, i32 1], align 4
			//@b = common global [20 x i32] zeroinitializer, align 4
			printf("@");
			Node* nodeId = nodeVar->children[0]->children[0];
			char* tmp = (char*)malloc(sizeof(char)*60);
			strcpy(tmp, nodeId->name);
			int index = getDim(tmp[0]);
			int i = 0;
			while (symTable[index][i]) i++;
			symTable[index][i] = (struct symbol*)malloc(sizeof(struct symbol));
			struct symbol* s = symTable[index][i];
			s->word = (char*)malloc(sizeof(char)*60);
			strcpy(s->word,tmp);
			s->type = 'g';

			printf("%s",tmp);
			printf(" = global [");
			Node* nodeInt = nodeVar->children[1];
			int trans = strtol(nodeInt->name, NULL, 0); // error checking here, can not smaller than 0
			printf("%d", trans); 

			s->arrSize = (char*)malloc(sizeof(char)*60);
			sprintf(s->arrSize, "%d", trans);
			printf(" x i32] [");
			trans_ArgsExt(rt->children[2]->children[0]);
			printf("], align 4\n");
		}
	}
}
/* for exteral args*/
void trans_ArgsExt(Node* rt) // args outsize, 1,2,3,4 case, can not be NULL, can not be not the same initializer
{
	if (rt->size == 1) //FEXP
	{
		char* tmp = (char*)malloc(sizeof(char)*60);
		if(rt->children[0]->node_type == Null)
		{
			return;// fuck it
		}
		else
		{
			printf("i32 ");
			char* val = (char*)malloc(sizeof(char)*60);
			val = trans_Exp(rt->children[0]->children[0]);
			printf("%s",val);
		}
	}
	else //EXP COMMA ARGS
	{
		printf("i32 ");
 	  	char* val = (char*)malloc(sizeof(char)*60);
        	val = trans_Exp(rt->children[0]);
       		printf("%s, ",val);
        	trans_ArgsExt(rt->children[1]);
	}
}
/* for function*/
void trans_Func(Node* rt) // rt->Func
{
//	regNum = callNum = ifNum = forNum = arridxNum = 0; // CLEAR for function
	printf("\n");
	printf("define i32 @");
	
	Node* nodeId = rt->children[0];
	char* tmp = (char*)malloc(sizeof(char)*60);
	strcpy(tmp, nodeId->name);
	
	printf("%s(", tmp);
	if(rt->children[1]->node_type == Null)
	{
		paraFlag = 0;
	}
	else
	{
		paraFlag = 1;
		trans_Parasf(rt->children[1]->children[0]);
	}
	printf(") #0\n");
}
/* for parasf*/
void trans_Parasf(Node* rt) // rt->parasf
{
	if(rt->size == 2) // para comma parasf
	{
		trans_Para(rt->children[0]);
		printf(", ");
		trans_Parasf(rt->children[1]);
	}
	else // para
	{
		trans_Para(rt->children[0]);
	}
}
/* for Para, store the id in symbol table and store the paraArr, paraSize*/
void trans_Para(Node* rt) // rt->para
{
	// spec var
	Node* nodeId = rt->children[1]->children[0];
	
	char* tmp = (char*)malloc(sizeof(char)*60);

	strcpy(tmp, nodeId->name);
	int index = getDim(tmp[0]);
	int i=0;
	while (symTable[index][i]) i++;
	symTable[index][i] = (struct symbol*)malloc(sizeof(struct symbol));
	struct symbol* s = symTable[index][i];
	s->word = (char*)malloc(sizeof(char)*60);
	strcpy(s->word,tmp);
	s->type = 'a';

	printf("i32 %%");
	printf("%s",tmp);

	paraArr[paraSize] = (char*)malloc(sizeof(char)*60);
	strcpy(paraArr[paraSize],tmp);
	paraSize++;
}
/* for stmtblock*/
void trans_Stmtblock(Node* rt) // rt->Stmtblock
{
	// entryDepth for whether print "{"
	if (entryDepth == 0)
	{
		printf("{\n");
		printf("entry:\n");
	}

    	if (paraFlag)
    	{
		//%x.addr = alloca i32, align 4
		//store i32 %x, i32* %x.addr, align 4
   	     	int i=0;
    	    	while (paraArr[i])
    	    	{
     	       		printf("  %%%s.addr = alloca i32, align 4\n",paraArr[i]);
     	       		printf("  store i32 %%%s, i32* %%%s.addr, align 4\n",paraArr[i],paraArr[i]);
     	       		free(paraArr[i]);
            		i++;
        	}
        	paraFlag = 0;
        	paraSize = 0;
    	}
	trans_Defs(rt->children[0]);
	trans_Stmts(rt->children[1]);
	
	if (entryDepth ==0)
	{
		printf("}\n");
	}
}

/* for translation of defs*/
void trans_Defs(Node* rt) // rt->Defs
{
	if(rt->node_type == Null) return;
	trans_Def(rt->children[0]);
	trans_Defs(rt->children[1]);
}

/* for translation of def*/
void trans_Def(Node* rt) //rt->Def
{
	// spec decs semi
	trans_Decs(rt->children[1]);
	// deal with spec with type case is enough
}

/* for translation of decs, use dec inner to differ from decext*/
void trans_Decs(Node* rt)
{
	if(rt->size == 1)
	{
		trans_DecInner(rt->children[0]);
	}
	else
	{
		trans_DecInner(rt->children[0]);
		trans_Decs(rt->children[1]);
	}
}

/* for translation of dec, four cases*/
void trans_DecInner(Node* rt)
{
	if(rt->size == 1) // VAR
	{
		Node* nodeVar = rt->children[0]; //node of VAR
		if(rt->children[0]->size == 1) // ID case
		{
			//%a = alloca i32, align 4
			printf("  %%");
			Node* nodeId = nodeVar->children[0];

			char* tmp = (char*)malloc(sizeof(char)*60);
			
			strcpy(tmp, nodeId->name);
			int index = getDim(tmp[0]);
			int i=0;
			while (symTable[index][i]) i++;
			symTable[index][i] = (struct symbol*)malloc(sizeof(struct symbol));
			struct symbol* s = symTable[index][i];
			s->word = (char*)malloc(sizeof(char)*60);
			strcpy(s->word,tmp);
			s->type = 'l';

			printf("%s",tmp);
			printf(" = alloca i32, align 4\n");
		}
		else // var lb int rb a[0] case
		{
			printf("  %%");
			Node* nodeId = nodeVar->children[0]->children[0]; // only one dimention array

			char* tmp = (char*)malloc(sizeof(char)*60);
			strcpy(tmp, nodeId->name);
			int index = getDim(tmp[0]);
			int i=0;
			while (symTable[index][i]) i++;
			symTable[index][i] = (struct symbol*)malloc(sizeof(struct symbol));
			struct symbol* s = symTable[index][i];
			s->word = (char*)malloc(sizeof(char)*60);
			strcpy(s->word,tmp);
			s->type = 'l';

			printf("%s",tmp);
			printf(" = alloca [");
			Node* nodeInt = nodeVar->children[1];
			int trans = strtol(nodeInt->name, NULL, 0); // error checking here, can not smaller than 0
			printf("%d", trans); 

			s->arrSize = (char*)malloc(sizeof(char)*60);
			sprintf(s->arrSize,"%d", trans);

			printf(" x i32], align 4\n");
		}
		
	}
	else // VAR ASSIGNOP INIT
 	{
		Node* nodeVar = rt->children[0]; // var
		if(rt->children[0]->size == 1) // a = 1
		{
			printf("  %%");
			Node* nodeId = nodeVar->children[0];
			char* tmp = (char*)malloc(sizeof(char)*60);
			strcpy(tmp, nodeId->name);
			int index = getDim(tmp[0]);
			int i=0;
			while (symTable[index][i]) i++;
			symTable[index][i] = (struct symbol*)malloc(sizeof(struct symbol));
			struct symbol* s = symTable[index][i];
			s->word = (char*)malloc(sizeof(char)*60);
			strcpy(s->word,tmp);
			s->type = 'l';

			printf("%s",tmp);

			Node* nodeInit = rt->children[2]->children[0]->children[0]; // int, error checking
			
			int trans = strtol(nodeInit->name, NULL, 0); // error checking here, can not smaller than 0

			printf(" = alloca i32 %d, align 4\n", trans);
			printf("  store i32 %d, i32* %%%s, align 4\n", trans, tmp);
		}
		else // a[2] = {0,1}
		{
			//d[2]; d[0] = 10; d[1] = 20，可破回填
			//%d = alloca [2 x i32], align 4
			//%arrayidx = getelementptr inbounds [2 x i32]* %d, i32 0, i32 0
			//store i32 10, i32* %arrayidx, align 4
			//%arrayidx1 = getelementptr inbounds [2 x i32]* %d, i32 0, i32 1
			//store i32 20, i32* %arrayidx1, align 4
			printf("  %%");
			Node* nodeId = nodeVar->children[0]->children[0];
			char* tmp = (char*)malloc(sizeof(char)*60);
			strcpy(tmp, nodeId->name);
			
			int index = getDim(tmp[0]);
			int i=0;
			while (symTable[index][i]) i++;
			symTable[index][i] = (struct symbol*)malloc(sizeof(struct symbol));
			struct symbol* s = symTable[index][i];
			s->word = (char*)malloc(sizeof(char)*60);
			strcpy(s->word,tmp);
			s->type = 'l';

			printf("%s",tmp);
			printf(" = alloca [");
			Node* nodeInt = nodeVar->children[1];

			int trans = strtol(nodeInt->name, NULL, 0);
			printf("%d", trans);

			s->arrSize = (char*)malloc(sizeof(char)*60);
			sprintf(s->arrSize, "%d", trans);

			printf(" x i32], align 4\n");

			arrName = (char*)malloc(sizeof(char)*60);
			arrSize = (char*)malloc(sizeof(char)*60);
			strcpy(arrName,tmp);
			strcpy(arrSize,s->arrSize);

			trans_ArgsInner(rt->children[2]->children[0]);

			free(arrName);
			free(arrSize);
		}
	}
}
/* for translation of args innner*/
void trans_ArgsInner(Node* rt) // rt-> args
{
	if(rt->size == 1) // exp case
	{
		char* val = (char*)malloc(sizeof(char)*60);
        	val = trans_Exp(rt->children[0]->children[0]);// only consider EXP here
        	printf("  %%arrayidx%d = getelementptr inbounds [%s x i32]* %%%s, i32 0, i32 %s\n",arridxNum,arrSize,arrName,val);
        	printf("  store i32 %s, i32* %%arrayidx%d, align 4\n",val,arridxNum);
        	arridxNum++;
	}
	else // exp comma args
	{
		char* val = (char*)malloc(sizeof(char)*60);
		val = trans_Exp(rt->children[0]);
		printf("  %%arrayidx%d = getelementptr inbounds [%s x i32]* %%%s, i32 0, i32 %s\n",arridxNum,arrSize,arrName,val);
		printf("  store i32 %s, i32* %%arrayidx%d, align 4\n",val,arridxNum);
		arridxNum++;
		trans_ArgsInner(rt->children[1]);
	}
}
/* for translation of stmts*/
void trans_Stmts(Node* rt) // rt->Stmts
{
	if(rt->size == 0) return;
	trans_Stmt(rt->children[0]);
	trans_Stmts(rt->children[1]);
}
/* for translation of stmt*/
void trans_Stmt(Node* rt)
{
	if(rt->children[0]->node_type == Stmtblock) // Stmtblock case
	{
		entryDepth++;
		trans_Stmtblock(rt->children[0]);
		entryDepth--;	
	}
	else if(rt->children[0]->node_type == Exp) // exp
	{
		trans_Exp(rt->children[0]);
	}
	else if(strcmp(rt->children[0]->name, "return") == 0) // return
	{
		printf("  %%r%d = alloca i32, align 4\n",regNum);
	       	int oldrNum = regNum;
        	regNum++;

        	char* tmp = (char*)malloc(sizeof(char)*60);
        	tmp = trans_Exp(rt->children[1]);

	        printf("  store i32 %s, i32* %%r%d\n",tmp,oldrNum);
        	printf("  %%r%d = load i32* %%r%d\n",regNum,oldrNum);
        	printf("  ret i32 %%r%d\n",regNum);
        	regNum++;	
	}
	else if(strcmp(rt->children[0]->name, "if") == 0) // if
	{
		if(rt->children[3]->size != 0) // ESTMT is not NULL
		{
			// IF LP EXP RP STMT ESTMT
			char* tmp = (char*)malloc(sizeof(char)*60);
			tmp = trans_Exp(rt->children[1]);
			
			// Exp = dot
			if(rt->children[1]->size > 1 && strcmp(rt->children[1]->children[1]->name, ".") == 0) // dot, special case
			{
				char num[10];
				sprintf(num, "%d", regNum++);
				char* tmpReg = (char*)malloc(sizeof(char)*60);
				strcpy(tmpReg, "%r");
				strcat(tmpReg,num);

				printf(" %s = icmp ne i32 %s, 0\n", tmpReg, tmp);
				strcpy(tmp, tmpReg);
			}		
			printf("  br i1 %s, label %%if%d.then, label %%if%d.else\n\n",tmp, ifNum, ifNum);

           		printf("if%d.then:\n",ifNum);
            		trans_Stmt(rt->children[2]);
           		printf("  br label %%if%d.end\n\n",ifNum);

            		printf("if%d.else:\n",ifNum);
          		trans_Stmt(rt->children[3]->children[1]);
            		printf("  br label %%if%d.end\n\n",ifNum);

            		printf("if%d.end:\n",ifNum);

            		ifNum++;
		}	
		else
		{
			char* tmp = (char*)malloc(sizeof(char)*60);
			tmp = trans_Exp(rt->children[1]);
			
			// Exp = dot
			if(strcmp(rt->children[1]->children[1]->name, ".") == 0) // dot, special case
			{
				char num[10];
				sprintf(num, "%d", regNum++);
				char* tmpReg = (char*)malloc(sizeof(char)*60);
				strcpy(tmpReg, "%r");
				strcat(tmpReg,num);
				printf(" %s = icmp ne i32 %s, 0\n", tmpReg, tmp);
				strcpy(tmp, tmpReg);
			}		
			printf("  br i1 %s, label %%if%d.then, label %%if%d.end\n\n",tmp, ifNum, ifNum);

           		printf("if%d.then:\n",ifNum);
            		trans_Stmt(rt->children[2]);
           		printf("  br label %%if%d.end\n\n",ifNum);

            		printf("if%d.end:\n",ifNum);

            		ifNum++;

		}
	}
	else if(strcmp(rt->children[0]->name, "for") == 0) // for  FOR LP FEXP SEMI FEXP SEMI FEXP RP STMT 
	{
		if(rt->children[1]->size == 0) {} // FEXP == NULL
		else
		{
			trans_Exp(rt->children[1]->children[0]);
		}
		printf("  br label %%for%d.cond\n\n",forNum);

        	printf("for%d.cond:\n",forNum);
		char* tmp = (char*)malloc(sizeof(char)*60);
        	tmp = trans_Exp(rt->children[2]->children[0]);
		
		// consider FEXP-> NULL case
       		if (rt->children[2]->children[0]->size == 2 && \
		   (rt->children[2]->children[0]->children[1]->node_type == Arrs||rt->children[2]->children[0]->children[1]->node_type == Null)) // ID ARRS
        	{
            		//%cmp = icmp sgt i32 %0, 16
            		printf("  %%r%d = icmp sgt i32 %s, 0",regNum,tmp);
            		printf("  br i1 %%r%d, label %%for%d.body, label %%for%d.end\n\n",regNum,forNum,forNum);
            		regNum++;
        	}
        	else
			printf("  br i1 %s, label %%for%d.body, label %%for%d.end\n\n",tmp,forNum,forNum);

       	 	printf("for%d.body:\n",forNum);
        	trans_Stmt(rt->children[4]);
        	printf("  br label %%for%d.inc\n\n",forNum);

        	printf("for%d.inc:\n",forNum);
        	trans_Exp(rt->children[3]);
        	printf("  br label %%for%d.cond\n\n",forNum);

        	printf("for%d.end:\n",forNum);

        	forNum++;
	}
}

/* for translation of expression*/
char* trans_Exp(Node* rt)
{

	if(rt->size == 1 && rt->children[0]->node_type == Int)
	{
		// just return what it is, let strtol deal with this shit
		char* tmp = (char*)malloc(sizeof(char)*60);
    	    	Node* nodeInt = rt->children[0];
		strcpy(tmp, nodeInt->name);
        	return tmp;
	}
	if(rt->size == 1 && rt->children[0]->node_type == Nint)
	{
		// just return what it is, let strtol deal with this shit
		char* tmp = (char*)malloc(sizeof(char)*60);
    	    	Node* nodeInt = rt->children[0];
		strcpy(tmp, nodeInt->name);
        	return tmp;
	}
	else if(rt->size == 1 && rt->children[0]->node_type == Exp)
	{
		trans_Exp(rt->children[0]);
	}
	else if(rt->size == 2 && rt->children[1]->node_type == Nint) // exp Nint a-1 case ; different from a - 1
	{
		char* op1 = (char*)malloc(sizeof(char)*60);
        	op1 = trans_Exp(rt->children[0]);

		char* op2 = (char*)malloc(sizeof(char)*60);
		Node* nodeInt = rt->children[1];
		int len = strlen(nodeInt->name);
		int i; for (i=1;i<=len;i++) op2[i-1] = nodeInt->name[i];

		char num[10];
		sprintf(num, "%d", regNum++);
		char* tmpReg = (char*)malloc(sizeof(char)*60);
		strcpy(tmpReg,"%r");
		strcat(tmpReg,num);

		printf("  %s = sub nsw i32 %s, %s\n",tmpReg,op1,op2);
		return tmpReg;
	}
	else if(strcmp(rt->children[0]->name, "read") == 0)
	{
		char* tmp = (char*)malloc(sizeof(char)*200);
            	loadFlag = 0;
           	tmp = trans_Exp(rt->children[1]);
            	loadFlag = 1;
            	printf("  %%call%d = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %s)\n",callNum,tmp);
            	callNum++;
		return NULL;
	}
	else if(strcmp(rt->children[0]->name, "write") == 0)
	{
		char* tmp = (char*)malloc(sizeof(char)*60);
		tmp = trans_Exp(rt->children[1]);

		int trans;
		if (strlen(tmp)>1 && (tmp[0]=='0' || (tmp[0]=='-' && tmp[1]=='0')))
		{
			trans = strtol(tmp,NULL,0);
			printf("  %%call%d = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32 %d)\n",callNum,trans);
			callNum++;
			printf("  %%call%d = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([2 x i8]* @.str1, i32 0, i32 0))\n",callNum);
			callNum++;
		}
		else
		{
			printf("  %%call%d = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32 %s)\n",callNum,tmp);
			callNum++;
			printf("  %%call%d = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([2 x i8]* @.str1, i32 0, i32 0))\n",callNum);
			callNum++;
		}
		return NULL;
	}
	else if(rt->size == 2 && (rt->children[1]->node_type == Arrs || rt->children[1]->node_type == Null) ) // ID ARRS
	{
		Node* nodeArrs = rt->children[1];
		if(nodeArrs->node_type == Null) // ARRS = Null
		{
			char* tmp = (char*)malloc(sizeof(char)*60);
            		Node* nodeId = rt->children[0]; // Id
            		strcpy(tmp, nodeId->name);

			int index = getDim(tmp[0]);
		        int i=0;
            		while (strcmp(tmp,symTable[index][i]->word)) i++;

            		struct symbol* id = symTable[index][i];
            		switch (id->type)
            		{
                		case 'g':
                			for (i=strlen(tmp);i>=0;i--) tmp[i+1] = tmp[i];
                			tmp[0] = '@';
                			break;

               			case 'l':
                			for (i=strlen(tmp);i>=0;i--) tmp[i+1] = tmp[i];
                			tmp[0] = '%';
                			break;

                		case 'a':
                			for (i=strlen(tmp);i>=0;i--) tmp[i+1] = tmp[i];
                			tmp[0] = '%';
                			strcat(tmp,".addr");
                			break;
            		}

            		if (loadFlag)
            		{
                		char num[10];
                		sprintf(num, "%d", regNum++);
                		char* tmpReg = (char*)malloc(sizeof(char)*60);
                		strcpy(tmpReg,"%r");
                		strcat(tmpReg,num);

		                printf("  %s = load i32* %s, align 4\n",tmpReg,tmp);
                		return tmpReg;
            		}
            		else return tmp;
		}
		else // ARRS -> (EXP) ARRS
		{
			char* tmp = (char*)malloc(sizeof(char)*60);
            		Node* nodeId = rt->children[0]; // Id
            		strcpy(tmp, nodeId->name);
			char* arrsIndex = (char*)malloc(sizeof(char)*60);
            		if (loadFlag==0)
            		{
                		loadFlag = 1;
                		arrsIndex = trans_Exp(rt->children[1]->children[0]); //what we obtained could be register or INT
                		loadFlag = 0;
            		}
	                else
			{
				arrsIndex = trans_Exp(rt->children[1]->children[0]);
			}
			
			char* ret = (char*)malloc(sizeof(char)*60);
            		strcpy(ret,"%arrayidx");

		        char num[10];
                        sprintf(num, "%d", arridxNum++);
                        strcat(ret,num);

			int index = getDim(tmp[0]);

		        int i=0;
			while (strcmp(tmp,symTable[index][i]->word)) i++;

			struct symbol* id = symTable[index][i];
			switch (id->type)
			{
				case 'g':
					for (i=strlen(tmp);i>=0;i--) tmp[i+1] = tmp[i];
					tmp[0] = '@';
					break;

				case 'l':
					for (i=strlen(tmp);i>=0;i--) tmp[i+1] = tmp[i];
					tmp[0] = '%';
					break;

				case 'a':
					for (i=strlen(tmp);i>=0;i--) tmp[i+1] = tmp[i];
					tmp[0] = '%';
					strcat(tmp,".addr");
					break;
            		}

			//%arrayidx4 = getelementptr inbounds [2 x i32]* %d, i32 0, i32 1
			printf("  %s = getelementptr inbounds [%s x i32]* %s, i32 0, i32 %s\n",ret,id->arrSize,tmp,arrsIndex);

			if (loadFlag)
			{
				char num[10];
				sprintf(num, "%d", regNum++);
				char* tmpReg = (char*)malloc(sizeof(char)*60);
				strcpy(tmpReg,"%r");
				strcat(tmpReg,num);

				printf("  %s = load i32* %s, align 4\n",tmpReg,ret);
				return tmpReg;
			}
			else 
				return ret;
		}
	}
	else if(strcmp(rt->children[0]->name, "++") == 0) // ++ EXP
	{
		char* op = (char*)malloc(sizeof(char)*60);
		loadFlag = 0;
		op = trans_Exp(rt->children[1]);
		loadFlag = 1;

		printf("  %%r%d = load i32* %s, align 4\n",regNum,op);
		printf("  %%r%d = add nsw i32 %%r%d, 1\n",regNum+1,regNum);
		printf("  store i32 %%r%d, i32* %s, align 4\n",regNum+1,op);

		regNum+=2;
		return NULL;
	}
	else if(strcmp(rt->children[0]->name, "-") == 0) // - , UMINUS
	{
		char* op = (char*)malloc(sizeof(char)*60);
		loadFlag = 0;
		op = trans_Exp(rt->children[1]);
		loadFlag = 1;

		printf("  %%r%d = load i32* %s, align 4\n",regNum,op);
		printf("  %%r%d = sub nsw i32 0, %%r%d\n",regNum+1,regNum);
		printf("  store i32 %%r%d, i32* %s, align 4\n",regNum+1,op);

		char num[10];
		sprintf(num, "%d", regNum+1);
		char* tmpReg = (char*)malloc(sizeof(char)*60);
		strcpy(tmpReg,"%r");
		strcat(tmpReg,num);

		regNum+=2;
		return tmpReg;
	}
	else if(strcmp(rt->children[0]->name, "!") == 0) // !, lognoot
	{
		char* op = (char*)malloc(sizeof(char)*60);
		op = trans_Exp(rt->children[1]);

		char num[10];
		sprintf(num, "%d", regNum++);
		char* tmpReg = (char*)malloc(sizeof(char)*60);
		strcpy(tmpReg,"%r");
		strcat(tmpReg,num);

		printf("  %s = icmp eq i32 %s, 0\n",tmpReg,op);
		return tmpReg;
	}
	else if(rt->size == 3 && strcmp(rt->children[1]->name, "-") == 0) // 1 - 2
	{
		char* op1 = (char*)malloc(sizeof(char)*60);
        	op1 = trans_Exp(rt->children[0]);

        	char* op2 = (char*)malloc(sizeof(char)*60);
        	op2 = trans_Exp(rt->children[2]);

        	char num[10];
        	sprintf(num, "%d", regNum++);
		char* tmpReg = (char*)malloc(sizeof(char)*60);
		strcpy(tmpReg,"%r");
		strcat(tmpReg,num);

		printf("  %s = sub nsw i32 %s, %s\n",tmpReg,op1,op2);
		return tmpReg;
	}
	else if(rt->size == 3 && strcmp(rt->children[1]->name, "=") == 0) //a = b
	{
		char* op2 = (char*)malloc(sizeof(char)*200);
		op2 = trans_Exp(rt->children[2]);

		loadFlag = 0;
		char* op1 = (char*)malloc(sizeof(char)*200);
		op1 = trans_Exp(rt->children[0]);
		loadFlag = 1;

		printf("  store i32 %s, i32* %s, align 4\n",op2,op1);
		return NULL;
	}
	else if(rt->size == 3 && strcmp(rt->children[1]->name, ".") == 0) // a.b
	{
		char* tmp = (char*)malloc(sizeof(char)*200);
		Node* nodeId = rt->children[0]->children[0];
		strcpy(tmp, nodeId->name);

		int index = getDim(tmp[0]);

		int i=0;
		while (strcmp(tmp,symTable[index][i]->word)) i++;

		struct symbol* id = symTable[index][i];

		char* op1 = (char*)malloc(sizeof(char)*200);
		strcpy(op1,tmp);

		char* opStr = (char*)malloc(sizeof(char)*200);
		strcpy(opStr,id->structName); //opStr, doubleO

		free(tmp);

		nodeId = rt->children[2]; // ID
		tmp = (char*)malloc(sizeof(char)*200);
		strcpy(tmp, nodeId->name);

		index = getDim(tmp[0]);

		i=0;
		while (strcmp(tmp,symTable[index][i]->word)) i++;

		id = symTable[index][i];

		int op2 = id->numStructMem; //op2, 0

		char* ret = (char*)malloc(sizeof(char)*200);
		strcpy(ret,"getelementptr inbounds (%struct.");
		strcat(ret,opStr);
		strcat(ret,"* @");
		strcat(ret,op1);
		strcat(ret,", i32 0, i32 ");
		char indTmp = '0'+op2;
		char* ind = (char*)malloc(sizeof(char)*50); 
		ind[0] = indTmp; 
		ind[1] = '\0';
		strcat(ret,ind);
		strcat(ret,")");

		if (loadFlag)
		{
		    char num[10];
		    sprintf(num, "%d", regNum++);
		    char* tmpReg = (char*)malloc(sizeof(char)*200);
		    strcpy(tmpReg,"%r");
		    strcat(tmpReg,num);

		    printf("  %s = load i32* %s, align 4\n",tmpReg,ret);
		    return tmpReg;
		}
		else return ret;
	}
	else if(rt->size == 3 && strcmp(rt->children[1]->name, "==") == 0) // a == b
	{
		char* op1 = (char*)malloc(sizeof(char)*60);
		op1 = trans_Exp(rt->children[0]);
		char* op2 = (char*)malloc(sizeof(char)*60);
		op2 = trans_Exp(rt->children[2]);

		char num[10];
		sprintf(num, "%d", regNum++);
		char* tmpReg = (char*)malloc(sizeof(char)*60);
		strcpy(tmpReg,"%r");
		strcat(tmpReg,num);

		printf("  %s = icmp eq i32 %s, %s\n",tmpReg,op1,op2);
		return tmpReg;
	}
	else if(rt->size == 3 && strcmp(rt->children[1]->name, "!=") == 0) // a == b
	{
		char* op1 = (char*)malloc(sizeof(char)*60);
		op1 = trans_Exp(rt->children[0]);
		char* op2 = (char*)malloc(sizeof(char)*60);
		op2 = trans_Exp(rt->children[2]);

		char num[10];
		sprintf(num, "%d", regNum++);
		char* tmpReg = (char*)malloc(sizeof(char)*60);
		strcpy(tmpReg,"%r");
		strcat(tmpReg,num);

		printf("  %s = icmp ne i32 %s, %s\n",tmpReg,op1,op2);
		return tmpReg;
	}
	else if(rt->size == 3 && strcmp(rt->children[1]->name, ">") == 0) // a > b
	{
        	char* op1 = (char*)malloc(sizeof(char)*60);
        	op1 = trans_Exp(rt->children[0]);
        	char* op2 = (char*)malloc(sizeof(char)*60);
        	op2 = trans_Exp(rt->children[2]);

	        char num[10];
        	sprintf(num, "%d", regNum++);
        	char* tmpReg = (char*)malloc(sizeof(char)*60);
        	strcpy(tmpReg,"%r");
        	strcat(tmpReg,num);
	
        	printf("  %s = icmp sgt i32 %s, %s\n",tmpReg,op1,op2);
        	return tmpReg;
	}
	else if(rt->size == 3 && strcmp(rt->children[1]->name, "<") == 0) // a < b
	{
		char* op1 = (char*)malloc(sizeof(char)*60);
        	op1 = trans_Exp(rt->children[0]);
        	char* op2 = (char*)malloc(sizeof(char)*60);
        	op2 = trans_Exp(rt->children[2]);

	        char num[10];
        	sprintf(num, "%d", regNum++);
        	char* tmpReg = (char*)malloc(sizeof(char)*60);
        	strcpy(tmpReg,"%r");
        	strcat(tmpReg,num);
	
        	printf("  %s = icmp slt i32 %s, %s\n",tmpReg,op1,op2);
        	return tmpReg;
	}
	else if(rt->size == 3 && strcmp(rt->children[1]->name, "<=") == 0) // a <= b
	{
		char* op1 = (char*)malloc(sizeof(char)*60);
        	op1 = trans_Exp(rt->children[0]);
        	char* op2 = (char*)malloc(sizeof(char)*60);
        	op2 = trans_Exp(rt->children[2]);

	        char num[10];
        	sprintf(num, "%d", regNum++);
        	char* tmpReg = (char*)malloc(sizeof(char)*60);
        	strcpy(tmpReg,"%r");
        	strcat(tmpReg,num);
	
        	printf("  %s = icmp sle i32 %s, %s\n",tmpReg,op1,op2);
        	return tmpReg;
	}
	else if(rt->size == 3 && strcmp(rt->children[1]->name, ">=") == 0) // a >= b
	{
		char* op1 = (char*)malloc(sizeof(char)*60);
        	op1 = trans_Exp(rt->children[0]);
        	char* op2 = (char*)malloc(sizeof(char)*60);
        	op2 = trans_Exp(rt->children[2]);

	        char num[10];
        	sprintf(num, "%d", regNum++);
        	char* tmpReg = (char*)malloc(sizeof(char)*60);
        	strcpy(tmpReg,"%r");
        	strcat(tmpReg,num);
	
        	printf("  %s = icmp sge i32 %s, %s\n",tmpReg,op1,op2);
        	return tmpReg;
	}
	else if(rt->size == 3 && strcmp(rt->children[1]->name, "&&") == 0) // a&&b
	{
		char* op1 = (char*)malloc(sizeof(char)*60);
		op1 = trans_Exp(rt->children[0]);
		char* op2 = (char*)malloc(sizeof(char)*60);
		op2 = trans_Exp(rt->children[2]);

		int reg1 = regNum, reg2 = regNum+1; regNum+=2;
		printf("  %%r%d = icmp ne i1 %s, 0\n",reg1,op1);
		printf("  %%r%d = icmp ne i1 %s, 0\n",reg2,op2);

		int reg3 = regNum; regNum++;
		printf("  %%r%d = and i1 %%r%d, %%r%d\n",reg3,reg1,reg2);

		char num[10];
		sprintf(num, "%d", reg3);
		char* tmpReg = (char*)malloc(sizeof(char)*60);
		strcpy(tmpReg,"%r");
		strcat(tmpReg,num);

		return tmpReg;
	}
	else if(rt->size == 3 && strcmp(rt->children[1]->name, "+") == 0) // a+b
	{
		char* op1 = (char*)malloc(sizeof(char)*60);
		op1 = trans_Exp(rt->children[0]);
		char* op2 = (char*)malloc(sizeof(char)*60);
		op2 = trans_Exp(rt->children[2]);

		char num[10];
		sprintf(num, "%d", regNum++);
		char* tmpReg = (char*)malloc(sizeof(char)*60);
		strcpy(tmpReg,"%r");
		strcat(tmpReg,num);

		printf("  %s = add nsw i32 %s, %s\n",tmpReg,op1,op2);
		return tmpReg;
	}
	else if(rt->size == 3 && strcmp(rt->children[1]->name, "-") == 0) // a-b
	{
		char* op1 = (char*)malloc(sizeof(char)*60);
		op1 = trans_Exp(rt->children[0]);
		char* op2 = (char*)malloc(sizeof(char)*60);
		op2 = trans_Exp(rt->children[2]);

		char num[10];
		sprintf(num, "%d", regNum++);
		char* tmpReg = (char*)malloc(sizeof(char)*60);
		strcpy(tmpReg,"%r");
		strcat(tmpReg,num);

		printf("  %s = sub nsw i32 %s, %s\n",tmpReg,op1,op2);
		return tmpReg;
	}
	else if(rt->size == 3 && strcmp(rt->children[1]->name, "*") == 0) // a+b
	{
		char* op1 = (char*)malloc(sizeof(char)*60);
		op1 = trans_Exp(rt->children[0]);
		char* op2 = (char*)malloc(sizeof(char)*60);
		op2 = trans_Exp(rt->children[2]);

		char num[10];
		sprintf(num, "%d", regNum++);
		char* tmpReg = (char*)malloc(sizeof(char)*60);
		strcpy(tmpReg,"%r");
		strcat(tmpReg,num);

		printf("  %s = mul nsw i32 %s, %s\n",tmpReg,op1,op2);
		return tmpReg;
	}
	else if(rt->size == 3 && strcmp(rt->children[1]->name, "%") == 0) // a%b
	{
		char* op1 = (char*)malloc(sizeof(char)*60);
		op1 = trans_Exp(rt->children[0]);
		char* op2 = (char*)malloc(sizeof(char)*60);
		op2 = trans_Exp(rt->children[2]);

		char num[10];
		sprintf(num, "%d", regNum++);
		char* tmpReg = (char*)malloc(sizeof(char)*60);
		strcpy(tmpReg,"%r");
		strcat(tmpReg,num);

		printf("  %s = srem i32 %s, %s\n",tmpReg,op1,op2);
		return tmpReg;
	}
	else if(rt->size == 3 && strcmp(rt->children[1]->name, "&") == 0) // a&b
	{
		char* op1 = (char*)malloc(sizeof(char)*60);
		op1 = trans_Exp(rt->children[0]);
		char* op2 = (char*)malloc(sizeof(char)*60);
		op2 = trans_Exp(rt->children[2]);

		char num[10];
		sprintf(num, "%d", regNum++);
		char* tmpReg = (char*)malloc(sizeof(char)*60);
		strcpy(tmpReg,"%r");
		strcat(tmpReg,num);

		printf("  %s = and i32 %s, %s\n",tmpReg,op1,op2);
      		sprintf(num, "%d", regNum++);
	       	strcpy(tmpReg,"%r");
		strcat(tmpReg,num);

		printf("  %s = icmp ne i32 %%r%d, 0\n",tmpReg,regNum-2);
		return tmpReg;
	}
	else if(rt->size == 3 && strcmp(rt->children[1]->name, "^") == 0) // a^b
	{
		char* op1 = (char*)malloc(sizeof(char)*60);
		op1 = trans_Exp(rt->children[0]);
		char* op2 = (char*)malloc(sizeof(char)*60);
		op2 = trans_Exp(rt->children[2]);

		char num[10];
		sprintf(num, "%d", regNum++);
		char* tmpReg = (char*)malloc(sizeof(char)*60);
		strcpy(tmpReg,"%r");
		strcat(tmpReg,num);

       		printf("  %s = xor i32 %s, %s\n",tmpReg,op1,op2);
		return tmpReg;
	}
	else if(rt->size == 3 && strcmp(rt->children[1]->name, ">>=") == 0) // a >>= b
	{		
		char* op1 = (char*)malloc(sizeof(char)*60);
		loadFlag = 0;
		op1 = trans_Exp(rt->children[0]);
		loadFlag = 1;
		char* op2 = (char*)malloc(sizeof(char)*60);
		op2 = trans_Exp(rt->children[2]);

		printf("%%r%d = load i32* %s, align 4\n",regNum,op1);
		printf("  %%r%d = ashr i32 %%r%d, %s\n",regNum+1,regNum,op2);
		printf("  store i32 %%r%d, i32* %s, align 4\n",regNum+1,op1);
		regNum+=2;
		return NULL;
	}
	else if(rt->size == 2 && rt->children[1]->node_type == Args) // id (args)
	{
		trans_ArgsFunc(rt->children[1]);

		char num[10];
		sprintf(num, "%d", callNum++);
		char* tmpReg = (char*)malloc(sizeof(char)*60);
		strcpy(tmpReg,"%call");
		strcat(tmpReg,num);

		char* funcName = (char*)malloc(sizeof(char)*60);
		Node* nodeId = rt->children[0];
		strcpy(funcName, nodeId->name);

		printf("  %s = call i32 @%s(",tmpReg,funcName);
		int i;		
		for (i=0;i<paraSize-1;i++)
		{
		    printf("i32 %s, ",paraArr[i]);
		    free(paraArr[i]);
		}
		if (paraSize>0)
		{
		    printf("i32 %s",paraArr[paraSize-1]);
		    free(paraArr[i]);
		    paraSize = 0;
		}
		printf(")\n");

		return tmpReg;
	}
	else 
	{
		return NULL;
	}

}
/* translation of args for function, use para*/
void trans_ArgsFunc(Node* rt) // args for func
{
	if (rt->size == 1) //FEXP
	{
		char* tmp = (char*)malloc(sizeof(char)*60);
		if(rt->children[0]->node_type == Null)
		{
			tmp == NULL;
		}
		else
		{
			tmp = trans_Exp(rt->children[0]->children[0]);
		}
		
		paraArr[paraSize] = (char*)malloc(sizeof(char)*60);
		strcpy(paraArr[paraSize],tmp);
		paraSize++;
	}
	else //EXP COMMA ARGS
	{
		char* tmp = (char*)malloc(sizeof(char)*60);
		tmp = trans_Exp(rt->children[0]);
		paraArr[paraSize] = (char*)malloc(sizeof(char)*60);
		strcpy(paraArr[paraSize],tmp);
		paraSize++;

		trans_ArgsFunc(rt->children[1]);
	}
}
#endif // LLVM_H
