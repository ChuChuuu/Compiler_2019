/*	Definition section */
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUF_SIZE 512
extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[BUF_SIZE];  // Get current code line from lex
char table_buf[4096];//to print table
char message_buf[128];//to print error message
char attribute_buf[128];//to save attribute(type)
int test_flag;
int print_sym_flag;//symbol=1,sementic=2
int print_semantic_flag;
int error_flag;//test if print symbol table at last
/* Symbol table function - you can add new function if needed. */
int lookup_symbol(char* name,char* kind);
int lookup_global(char* name,char* kind);
int lookup_func_implement_times(char* name);
void create_symbol();
void insert_symbol(char* name,char* type,char* kind,char* attribute);
void insert_func_implement(char* name);
void dump_symbol();
void kill_symbol();
void yyerror(char *s);
void se_error(char *s);
/*some variable*/
typedef struct {
	int index;
	int scope;
	int implementation_flag;//to check if the function have implement
	char* name;
	char* kind;
	char* type;
	char* attribute;
}Symbol_Table;
struct node{
	Symbol_Table STable[30];
	int var_index;
	int Scope;
	struct node* next;
};
typedef struct node Node;

Node* First;
Node* Current;
int scope_flag = 0;
int func_declare_flag = 0;
%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    char* string_val;
	char* type_val;
	char* id_val;
}

/* Token without return */
%token PRINT 
%token IF ELSE FOR WHILE
%token SEMICOLON
%token ADD SUB MUL DIV MOD INC DEC
%token MT LT MTE LTE EQ NE
%token ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR NOT
%token LB RB LCB RCB LSB RSB COMMA
%token FALSE TRUE
%token RET
//%token COMMENT
%nonassoc THEN
%nonassoc ELSE
/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string_val> STR_CONST
%token <type_val> STRING
%token <type_val> INT
%token <type_val> FLOAT
%token <type_val> BOOL
%token <type_val> VOID
%token <id_val> ID
/* Nonterminal with return, which need to sepcify type */
//%type <f_val> stat
%type <type_val> type_specifier
%type <type_val>parameter_declaration
%type <id_val>direct_declarator
%type <id_val>declarator
%type <id_val>init_declarator
%type <id_val>primary_expression
%type <id_val>postfix_expression
/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : program external_declaration{}
	| external_declaration{}
;
external_declaration
	: declaration
	| function_definition
;
function_definition
	:type_specifier declarator{} compound_statement{
		func_declare_flag = 0;
        if(lookup_symbol($2,"function") == 0 && lookup_symbol($2,"variable") == 0){
            insert_symbol($2,$1,"function",attribute_buf);
			insert_func_implement($2);
        }
		else if(lookup_symbol($2,"function") == 2){
			if(lookup_func_implement_times($2) != 1){
				insert_func_implement($2);//first time implement
			}
			else{
                //print_sym_flag = 2;
				print_semantic_flag = 1;
                strcat(message_buf,"Redeclared function ");
                strcat(message_buf,$2);
			}
        }

		strcpy(attribute_buf,"");
	}
;
compound_statement
	:LCB {	if(func_declare_flag == 0){
				scope_flag++;
                create_symbol(scope_flag);
            }
            else{
                func_declare_flag = 0;
			}
	}
	RCB{
		scope_flag--;
		dump_symbol();
	}
	|LCB {	if(func_declare_flag == 0){
				scope_flag++;
				create_symbol(scope_flag);
			}
			else{
				func_declare_flag = 0;
			}
	}
	block_item_list RCB{
		scope_flag--;
		print_sym_flag = 1;
		dump_symbol();
	}
;
block_item_list/*may have block in block*/
	:block_item
	|block_item_list block_item
;
block_item/*action in block*/
	:declaration
	|statement
;
statement/*if,loop,expression,return,print*/
	:compound_statement
	|expression_statement
	|iteration_statement
	|selection_statement
	|jump_statement
	|print_function
;
print_function
	:PRINT LB print_content RB SEMICOLON
;
print_content
	:STR_CONST{}
	|ID{
		if(lookup_symbol($1,"variable")==0 && lookup_global($1,"variable")==0 &&lookup_symbol($1,"parameter") == 0 && lookup_global($1,"parameter") == 0){
			//print_sym_flag = 2;
			print_semantic_flag = 1;
			strcat(message_buf,"Undeclared variable ");
			strcat(message_buf,$1);
		}
	}
;

jump_statement
	:RET SEMICOLON
	|RET expression SEMICOLON
;
selection_statement
	:IF LB expression RB statement %prec THEN
	|IF LB expression RB statement ELSE statement;
;
iteration_statement/*while loop*/
	:WHILE LB expression RB statement
;
expression_statement
	:SEMICOLON
	|expression SEMICOLON
;
expression/*situation like a = 10 , b=20;*/
	:assignment_expression
	|expression COMMA assignment_expression
;

declaration
	:type_specifier init_declarator SEMICOLON{
		if(func_declare_flag == 1){
			func_declare_flag = 0;
			scope_flag--;
			kill_symbol();
			if(lookup_symbol($2,"function") == 0 && lookup_global($2,"function")==0 && lookup_symbol($2,"variable") == 0 && lookup_global($2,"variable") == 0){
				insert_symbol($2,$1,"function",attribute_buf);
				strcpy(attribute_buf,"");
			}
			else{
				//print_sym_flag = 2;
				print_semantic_flag =1;
				strcat(message_buf,"Redeclared function ");
                strcat(message_buf,$2);
				printf("test\n");
			}
		}
		else{
			if(lookup_symbol($2,"variable") == 0&&lookup_symbol($2,"parameter") == 0&&lookup_symbol($2,"function") == 0&&lookup_global($2,"function")==0){
				insert_symbol($2,$1,"variable","");
			}
			else{
				//print_sym_flag = 2;
				print_semantic_flag = 1;
				strcat(message_buf,"Redeclared variable ");
				strcat(message_buf,$2);
			}
        }
	
	}
;

init_declarator
	:declarator ASGN initializer{$$=$1;}
	|declarator{$$=$1;}
;
declarator
	:direct_declarator{$$=$1;}
;
direct_declarator
	:ID{	/*if(lookup_symbol($1) == 0){
				insert_symbol($1);
			}*/
			$$=$1;
	}
	|direct_declarator LB{func_declare_flag = 1;scope_flag++;create_symbol(scope_flag);} RB
	|direct_declarator LB{func_declare_flag = 1;scope_flag++;create_symbol(scope_flag);} parameter_type_list RB
	|direct_declarator LB identifier_list RB/*ex. int a = f(5);*/
;
identifier_list
	:ID
	|identifier_list COMMA ID
;
parameter_type_list
	:parameter_list
;
parameter_list
	:parameter_declaration{
		strcpy(attribute_buf,$1);
		strcat(attribute_buf,"\0");
	}
	|parameter_list COMMA parameter_declaration{
		strcat(attribute_buf,", ");
		strcat(attribute_buf,$3);
		strcat(attribute_buf,"\0");
	}
;
parameter_declaration
	:type_specifier declarator{
		$$=$1;
		if(lookup_symbol($2,"paremeter") == 0){
            insert_symbol($2,$1,"parameter","");                                              
        }
		else{
			print_semantic_flag = 1;
			strcat(message_buf,"Redeclared parameter ");
            strcat(message_buf,$2);
		}
	}
;
initializer
	:assignment_expression
;
assignment_expression
	:relational_expression
	|unary_expression assignment_operator assignment_expression
;

assignment_operator
	:ASGN
	|ADDASGN
	|SUBASGN
	|MULASGN
	|DIVASGN
	|MODASGN
;
relational_expression
	:additive_expression
	|relational_expression MT additive_expression
	|relational_expression LT additive_expression
	|relational_expression MTE additive_expression
	|relational_expression LTE additive_expression
	|relational_expression EQ additive_expression
	|relational_expression NE additive_expression
;
additive_expression
	:multiplicative_expression
	|additive_expression ADD multiplicative_expression
	|additive_expression SUB multiplicative_expression
;
multiplicative_expression
	:unary_expression
	|multiplicative_expression MUL unary_expression
	|multiplicative_expression DIV unary_expression
	|multiplicative_expression MOD unary_expression
;
unary_expression
	:postfix_expression
	|INC unary_expression
	|DEC unary_expression
	|unary_operation unary_expression
;
unary_operation
	:ADD
	|SUB
;

postfix_expression
	:primary_expression{$$=$1;}
	|postfix_expression INC
	|postfix_expression DEC
	|postfix_expression LB argument_expression_list RB/*function execute ex.f(x,y)*/{
		if(lookup_global($1,"function") != 2){
			//print_sym_flag = 2;
			print_semantic_flag =1;
			strcpy(message_buf,"Undeclared function ");
			strcat(message_buf,$1);
		}
	}
	|postfix_expression LB RB{
		if(lookup_global($1,"function") != 2){
            //print_sym_flag = 2;
			print_semantic_flag =1;
            strcpy(message_buf,"Undeclared function ");
            strcat(message_buf,$1);
        }

	}
;
argument_expression_list
	:assignment_expression
	|argument_expression_list COMMA assignment_expression
;
primary_expression
	:ID{
		$$=$1;
		if(lookup_global($1,"variable") == 0 && lookup_symbol($1,"variable" )==0 &&lookup_global($1,"parameter") == 0 && lookup_symbol($1,"parameter")==0 &&lookup_global($1,"function") == 0 && lookup_symbol($1,"function" )==0){
			//print_sym_flag = 2;
			print_semantic_flag =1;
			strcat(message_buf,"Undeclared variable ");
			strcat(message_buf,$1);
		}
	
	}
	|constant
	|string
	|boolean
;
boolean
	:TRUE
	|FALSE
;
constant
	:I_CONST
	|F_CONST
;
string
	:STR_CONST
;
type_specifier
    : INT { $$ = $1;}
    | FLOAT { $$ = $1; }
    | BOOL  { $$ = $1; }
    | STRING { $$ = $1; }
    | VOID { $$ = $1; }
;
/*
stat
    : declaration{}
    | compound_stat
    | expression_stat
    | print_func
;

declaration
    : type ID ASGN initializer SEMICOLON{
    | type ID SEMICOLON
;
initializer
	:I_CONST
	|F_CONST
	|TRUE
	|FALSE
;
 actions can be taken when meet the token or rule 
type_specifier
    : INT { $$ = $1;}
    | FLOAT { $$ = $1; }
    | BOOL  { $$ = $1; }
    | STRING { $$ = $1; }
    | VOID { $$ = $1; }
;
*/
%%

/* C code section */
int main(int argc, char** argv)
{
	scope_flag = 0;
	First = (Node*)malloc(sizeof(Node));
	First->Scope = scope_flag;
	First->var_index = 0;
	First->next = NULL;
	Current = First;
    yylineno = 0;
	print_sym_flag = 0;
	print_semantic_flag = 0;
	yyparse();
	if(error_flag == 0){
		dump_symbol();
		printf("%s",table_buf);
		error_flag = 0;
		printf("\nTotal lines: %d \n",yylineno);
	}

    return 0;
}

void yyerror(char *s)
{
	error_flag = 1;
	printf("%d: %s\n",yylineno+1,buf);  
	if( print_semantic_flag == 1){
	    printf("\n|-----------------------------------------------|\n");
		printf("| Error found in line %d: %s\n", yylineno+1, buf);
		printf("| %s", message_buf);
		printf("\n|-----------------------------------------------|\n\n");

	}
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno+1, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
	strcpy(buf,"");
}
void se_error(char *s){
	printf("%d: %s\n",yylineno,buf);
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
    strcpy(buf,"");
}
void create_symbol(int scope) {
	if(Current->Scope == scope_flag){
		return;
	}
	Node* newnode;
	newnode = (Node*)malloc(sizeof(Node));
	newnode->Scope = scope;
	newnode->var_index = 0;
	newnode->next = NULL;
	Current->next = newnode;
	Current = newnode;

}
void insert_symbol(char* name,char* type,char* kind,char* attribute) {
	int index;
	index = Current->var_index;
	if(index >= 30){
		printf("error:number of variable > 30");
		return ;
	}
	Current->STable[index].name = strdup(name);
	Current->STable[index].index = index;
	Current->STable[index].scope = Current->Scope;
	Current->STable[index].type = strdup(type);
	Current->STable[index].kind = strdup(kind);
	Current->STable[index].attribute = strdup(attribute);
	Current->var_index++;


}
void insert_func_implement(char* name){
	int i;
	for( i = 0 ; i < Current->var_index;i++){
		Current->STable[i].implementation_flag = 0;
		if(strcmp(name,Current->STable[i].name)==0){
			Current->STable[i].implementation_flag = 1;
		}
	}
}
int lookup_symbol(char* name,char* kind) {
	int i;
	for(i = 0 ; i < Current->var_index ; i++){
	        if(strcmp(name,Current->STable[i].name) == 0 && strcmp(kind,"function") ==0&& strcmp(Current->STable[i].kind,"function")==0){
                return 2;
            }
            else if(strcmp(name,Current->STable[i].name) == 0 && strcmp(kind,"variable") == 0 && strcmp(Current->STable[i].kind,"variable") == 0){
                return 1;
            }
            else if(strcmp(name,Current->STable[i].name) == 0 && strcmp(kind,"parameter") == 0 && strcmp(Current->STable[i].kind,"parameter") == 0){
                return 3;
            } 
	}
	return 0;
}
int lookup_func_implement_times(char* name){
	int i;
	for(i = 0; i < Current->var_index;i++){
		if(strcmp(name,Current->STable[i].name) == 0 && Current->STable[i].implementation_flag == 1){
			return 1;
		}
	}
	return 0;
}
int lookup_global(char* name,char* kind) {
    int i;
	Node* tempnode;
	tempnode = First;
	while(tempnode != NULL && tempnode != Current){
		for(i = 0 ; i < tempnode->var_index ; i++){
			if(strcmp(name,tempnode->STable[i].name) == 0 && strcmp(kind,"function") ==0&& strcmp(tempnode->STable[i].kind,"function")==0){
				return 2;
			}
			else if(strcmp(name,tempnode->STable[i].name) == 0 && strcmp(kind,"variable") == 0 && strcmp(tempnode->STable[i].kind,"variable") == 0){
				return 1;
			}
			else if(strcmp(name,tempnode->STable[i].name) == 0 && strcmp(kind,"parameter") == 0 && strcmp(tempnode->STable[i].kind,"parameter") == 0){
				return 3;
			}
		}
		tempnode = tempnode->next;
    }
    return 0;
}


void dump_symbol() {
	char tempbuf[128];
	if(Current->var_index > 0){
	    sprintf(tempbuf,"\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n","Index", "Name", "Kind", "Type", "Scope", "Attribute");
		strcat(table_buf,tempbuf);
		int i;
		for(i = 0 ; i < Current->var_index ; i++){
			if(strcmp(Current->STable[i].attribute,"")==0){
				sprintf(tempbuf,"%-10d%-10s%-12s%-10s%-10d\n",Current->STable[i].index,Current->STable[i].name,Current->STable[i].kind,Current->STable[i].type,Current->STable[i].scope);
			}
			else{
				sprintf(tempbuf,"%-10d%-10s%-12s%-10s%-10d%s\n",Current->STable[i].index,Current->STable[i].name,Current->STable[i].kind,Current->STable[i].type,Current->STable[i].scope,Current->STable[i].attribute);
			}
				strcat(table_buf,tempbuf);
		}
		strcat(table_buf,"\n");
	}
	Node* previous;
	Node* temp;
	previous = First;
	while(previous->next != Current && previous->next != NULL){
		previous = previous->next;
	}
	temp=Current;
	Current = previous;
	Current->next = NULL;
	free(temp);	
}
void kill_symbol(){
	Node* previous;
    Node* temp;
    previous = First;
    while(previous->next != Current && previous->next != NULL){
        previous = previous->next;
    }
    temp=Current;
    Current = previous;
    Current->next = NULL;
    free(temp);
}
