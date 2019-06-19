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
char Jcode_buf[512];//用來存javacode
int test_flag;
int print_sym_flag;//symbol=1,sementic=2
int print_semantic_flag;
int error_flag;//test if print symbol table at last
int var_ini_flag;//用來看某個變數被宣告時有沒有被初始化
int global_int=0;//存全域變數
float global_float=0;//存全域變數
char global_string[50];//存全域變數
int global_bool;
int assign_right;//看id是不是在“=”右邊
int exe_float_flag;//看運算式中有沒有出現float的符號
int isFun_flag;//現在用來看如果expression是function或是可以單獨做的話就要load出來
int isWhile_flag;//用來看是while的話就算沒有“=”也要可以load
int isIf_flag;//用來看是if的話就算沒有“=”也要可以load
int isReturn_flag;//用來看現在這個ID是不是用來return的
int noinitial_flag;//用來看宣告的變數有沒有初始化
int declare_zero;//用來看declare的是不是zero
char function_pra_type[10];//用來存function的參數符號
char function_arg_type[10];//用來存functon的引數buf
int look_function_type_flag;//看一開始function是什麼type，return就要什麼type
void lookfunction_att(char* fun_name);//用來找一個function的type 是合起來的形式ex.II,
char att_buf[10];//用來借存lookfunction_att的結果
int while_label_num;//用來記住while用的label
int while_label_stack;//用來記現在在哪個stack
int while_stack[50];//label的stack
int if_label_num;//用來記住if用的label
int if_label_stack;//用來記現在在哪個stack
int if_stack[50];//用來記住if用的label
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
int compare_type(char* var_name);
//產生用函式
void writeCode(char* codeline);//寫出文件
int getStackindex(char* var_name);//得到變數在stack的位置
int lookglobal_type(char* var_name);//用來看globalvar的type，int=1，float=2，string=3，bool=4，void=5
int lookNglobal_type(char* var_name);//用來看global以外的type int=1，float=2
void Jinsert_function(char* name,char* Jattribute);//用來多給function ex.FF 的形式的function
void Jinsert_zero(char* var_name,int check);//插入某變數是否為0，check=1就是=0，check=0就是被註銷過了
int check_zero(char* var_name);//用來看是不是初始化為0的變數或是常數=0->如果是的話就return1
void Storefunction(char* left,char* right);//用來做Jcode的load
void Loadfunction(char* left);//用來做load的function//只會用在+=之類的
void RE_cha_function(char* left , char* right);//在relative用來看要不要轉成int的function，因為要用fcmpl
void ADDfunction(char* left,char* right);//用來做add的運算
void SUBfunction(char* left,char* right);//用來做sub的運算
void MULfunction(char* left,char* right);//用來做mul的運算
void MODfunction(char* left,char* right);//用來做mod的運算
void DIVfunction(char* left,char* right);//用來做div的運算
void ADDASGNfunction(char* left ,char* right);
void SUBASGNfunction(char* left ,char* right);
void MULASGNfunction(char* left ,char* right);
void MODASGNfunction(char* left ,char* right);
void DIVASGNfunction(char* left ,char* right);
/*some variable*/
typedef struct {
	int int_flag;
	int float_flag;
}Type_set;

Type_set type_set;
typedef struct {
	int index;
	int scope;
	int implementation_flag;//to check if the function have implement
	int zero_flag;//用來看這東西初始化是不是zero
	char* name;
	char* kind;
	char* type;
	char* attribute;
	char* Jatt;
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

FILE *file;//to generate .j file for jasmin
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
	int assign_flag;
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
%type <id_val>unary_expression
%type <id_val>multiplicative_expression
%type <id_val>relational_expression
%type <id_val>additive_expression
%type <id_val>assignment_expression
%type <id_val>initializer
%type <id_val>expression
%type <id_val>constant
%type <id_val>string
%type <id_val>unary_operation
%type <assign_flag>assignment_operator
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
	:type_specifier declarator {
		//下Jcode的function的參數
		sprintf(Jcode_buf,".method public static %s(",$2);
		if( strcmp($2,"main") == 0){
			strcat(Jcode_buf,"[Ljava/lang/String;)");
		}
		else{
			strcat(Jcode_buf,function_pra_type);
			strcat(Jcode_buf,")");

		}
		//Jcode去加上function的type
		if( strcmp($1,"void") == 0){
			strcat(Jcode_buf,"V");
			look_function_type_flag = 5;
		}
		else if( strcmp($1,"int") == 0){
			strcat(Jcode_buf,"I");
			look_function_type_flag = 1;
		}
		else if( strcmp($1,"float") == 0){
			strcat(Jcode_buf,"F");
			look_function_type_flag = 2;
		}
		else if( strcmp($1,"bool") == 0){
			strcat(Jcode_buf,"I");
			look_function_type_flag = 4;
		}
		else if( strcmp($1,"string") == 0){
			look_function_type_flag = 3;
			//感覺不用做，不知道後面要用什麼type
		}
		writeCode(Jcode_buf);
		//Jcode加上stack local
		sprintf(Jcode_buf,".limit stack 50\n.limit locals 50");
		writeCode(Jcode_buf);

	}
	compound_statement{
		look_function_type_flag = 0;//function結束了，looktype初始化。
		func_declare_flag = 0;
        if(lookup_symbol($2,"function") == 0 && lookup_symbol($2,"variable") == 0){
            insert_symbol($2,$1,"function",attribute_buf);
			Jinsert_function($2,function_pra_type);
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
		//function完成後要加end
		sprintf(Jcode_buf,".end method");
		writeCode(Jcode_buf);
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
	:STR_CONST{
		sprintf(Jcode_buf,"\tldc \"%s\"",$1);
        writeCode(Jcode_buf);
        sprintf(Jcode_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
        writeCode(Jcode_buf);
        sprintf(Jcode_buf,"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V");
        writeCode(Jcode_buf);
	}
	|I_CONST{
        sprintf(Jcode_buf,"\tldc %d",$1);
        writeCode(Jcode_buf);
        sprintf(Jcode_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
        writeCode(Jcode_buf);
        sprintf(Jcode_buf,"\tinvokevirtual java/io/PrintStream/println(I)V");
        writeCode(Jcode_buf);
	}
	|F_CONST{
		sprintf(Jcode_buf,"\tldc %f",$1);
        writeCode(Jcode_buf);
        sprintf(Jcode_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
        writeCode(Jcode_buf);
        sprintf(Jcode_buf,"\tinvokevirtual java/io/PrintStream/println(F)V");
        writeCode(Jcode_buf);
	}
	|ID{
		if(lookup_symbol($1,"variable")==0 && lookup_global($1,"variable")==0 &&lookup_symbol($1,"parameter") == 0 && lookup_global($1,"parameter") == 0){
			//print_sym_flag = 2;
			print_semantic_flag = 1;
			strcat(message_buf,"Undeclared variable ");
			strcat(message_buf,$1);
		}
		//沒有問題的部分
		else{
			//不是global
			if(getStackindex($1) != -1){
				//是int
				if(lookNglobal_type($1) == 1){
					sprintf(Jcode_buf,"\tiload %d",getStackindex($1));
					writeCode(Jcode_buf);
					sprintf(Jcode_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
					writeCode(Jcode_buf);
					sprintf(Jcode_buf,"\tinvokevirtual java/io/PrintStream/println(I)V");
					writeCode(Jcode_buf);
				}
				//是float
				else if(lookNglobal_type($1) == 2){
					sprintf(Jcode_buf,"\tfload %d",getStackindex($1));
					writeCode(Jcode_buf);
					sprintf(Jcode_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
					writeCode(Jcode_buf);
					sprintf(Jcode_buf,"\tinvokevirtual java/io/PrintStream/println(F)V");
					writeCode(Jcode_buf);
				}
				else if(lookNglobal_type($1) == 3){
					sprintf(Jcode_buf,"\taload %d",getStackindex($1));
					writeCode(Jcode_buf);
					sprintf(Jcode_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
					writeCode(Jcode_buf);
					sprintf(Jcode_buf,"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V");
					writeCode(Jcode_buf);
				}

			}
			//是global
			else if( getStackindex($1) == -1){
				printf("look:%d\n",lookglobal_type($1));
				//是int
				if(lookglobal_type($1) == 1){
					sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s I",$1);
					writeCode(Jcode_buf);
					sprintf(Jcode_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
					writeCode(Jcode_buf);
					sprintf(Jcode_buf,"\tinvokevirtual java/io/PrintStream/println(I)V");
					writeCode(Jcode_buf);
				}
				//是float
				else if(lookglobal_type($1) == 2){
                    sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s F",$1);
                    writeCode(Jcode_buf);
                    sprintf(Jcode_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
                    writeCode(Jcode_buf);
                    sprintf(Jcode_buf,"\tinvokevirtual java/io/PrintStream/println(F)V");
                    writeCode(Jcode_buf);
                }
				//是string
				else if(lookglobal_type($1) == 3){
                    sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s Ljava/lang/String;",$1);
                    writeCode(Jcode_buf);
                    sprintf(Jcode_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
                    writeCode(Jcode_buf);
                    sprintf(Jcode_buf,"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V");
                    writeCode(Jcode_buf);
                }
			}
		}
	}
;

jump_statement
	:RET SEMICOLON{
		//只有void可以不回傳東西！
		if(look_function_type_flag == 5){
			sprintf(Jcode_buf,"\treturn");
			writeCode(Jcode_buf);
		}
		else{
			print_semantic_flag = 1;
            strcat(message_buf,"回傳的型態要跟函式型態一致喔！");
		}
//		look_function_type_flag = 0;//初始化一下
		//應該不用在這裡初始化，因為有可能function中有複數個return嗎？
	}
	|RET{isReturn_flag = 1;} expression SEMICOLON{
		exe_float_flag = 0;
		isReturn_flag = 0;//return的flag要歸回
		printf("return:%s\n",$3);
		//如果reutrn的type與function有一致
		if(look_function_type_flag == lookglobal_type($3) || look_function_type_flag == lookNglobal_type($3)){
			//是int
			if(look_function_type_flag == 1){
				sprintf(Jcode_buf,"\tireturn");
			}
			//是float
			else if(look_function_type_flag == 2){
				sprintf(Jcode_buf,"\tfreturn");
			}
			writeCode(Jcode_buf);
		}
		//return的type與function的type不一致
		else{
            print_semantic_flag = 1;
            strcat(message_buf,"回傳的型態要跟函式型態一致喔！");
		}
//		look_function_type_flag = 0;//
		
	}
;
if_condition
	:IF {isIf_flag = 1;}LB expression RB{
	    isIf_flag = 0;//while判斷的結束
		//把label++
		if_label_num++;
		if_label_stack++;
		//放進stack
		if_stack[if_label_stack] = if_label_num;
        printf("compare:%s\n",$4);
        //判斷是什麼compare，如果是錯的就跳轉
        if( strcmp($4,"MT") == 0 || strcmp($4,"LT") == 0){
            sprintf(Jcode_buf,"\tifle LABEL_IF_FALSE_%d",if_stack[if_label_stack]);
        }
        else if( strcmp($4,"MTE") == 0 || strcmp($4,"LTE") == 0){
            sprintf(Jcode_buf,"\tiflt LABEL_IF_FALSE_%d",if_stack[if_label_stack]);
        }
        else if( strcmp($4,"EQ") == 0 ){
            sprintf(Jcode_buf,"\tifne LABEL_IF_FALSE_%d",if_stack[if_label_stack]);
        }
        else if( strcmp($4,"NE") == 0){
            sprintf(Jcode_buf,"\tifeq LABEL_IF_FALSE_%d",if_stack[if_label_stack]);
        }
        writeCode(Jcode_buf);
	}
;
selection_statement
	:if_condition statement %prec THEN{
        //不要if要去的地方
        sprintf(Jcode_buf,"LABEL_IF_FALSE_%d:",if_stack[if_label_stack]);
        writeCode(Jcode_buf);
        //拔掉TOS
        if_label_stack--;   
	}
	|if_condition  statement ELSE{
		//if完要去的地方
		sprintf(Jcode_buf,"goto LABEL_IF_EXIT_%d",if_stack[if_label_stack]);
		writeCode(Jcode_buf);
		//不是if要去的地方
        sprintf(Jcode_buf,"LABEL_IF_FALSE_%d:",if_stack[if_label_stack]);
        writeCode(Jcode_buf);
	} statement{
		//整個ifelse的出口
        sprintf(Jcode_buf,"LABEL_IF_EXIT_%d:",if_stack[if_label_stack]);
        writeCode(Jcode_buf);
        //拔掉TOS
		if_label_stack--;
		
	}
;
iteration_statement/*while loop*/
	:WHILE{
		//label數++
		while_label_num++;
		//放到stack中
		while_label_stack++;
		while_stack[while_label_stack]=while_label_num;
		sprintf(Jcode_buf,"LABEL_WHILE_BEGIN_%d:",while_stack[while_label_stack]);
		writeCode(Jcode_buf);
		//while判斷的開始
		isWhile_flag = 1;
	}
	LB expression RB{
		isWhile_flag = 0;//while判斷的結束
		printf("compare:%s\n",$4);
		//判斷是什麼compare，如果是錯的就跳轉
		if( strcmp($4,"MT") == 0 || strcmp($4,"LT") == 0){
			sprintf(Jcode_buf,"\tifle LABEL_WHILE_FALSE_%d",while_stack[while_label_stack]);
		}
		else if( strcmp($4,"MTE") == 0 || strcmp($4,"LTE") == 0){
            sprintf(Jcode_buf,"\tiflt LABEL_WHILE_FALSE_%d",while_stack[while_label_stack]);
        }
		else if( strcmp($4,"EQ") == 0 ){
            sprintf(Jcode_buf,"\tifne LABEL_WHILE_FALSE_%d",while_stack[while_label_stack]);
        }
		else if( strcmp($4,"NE") == 0){
            sprintf(Jcode_buf,"\tifeq LABEL_WHILE_FALSE_%d",while_stack[while_label_stack]);
        }
		writeCode(Jcode_buf);

	}
	statement{
		//回去再判斷的地方
		sprintf(Jcode_buf,"\tgoto LABEL_WHILE_BEGIN_%d",while_stack[while_label_stack]);
		writeCode(Jcode_buf);
		//跳出loop要去的地方
		sprintf(Jcode_buf,"LABEL_WHILE_FALSE_%d:",while_stack[while_label_stack]);
		writeCode(Jcode_buf);
		//取出TOS
		while_label_stack--;
	}
;
expression_statement
	:SEMICOLON
	|expression SEMICOLON
;
expression/*situation like a = 10 , b=20;*/
	:assignment_expression{$$=$1;}
	|expression COMMA assignment_expression
;

declaration
	:type_specifier init_declarator SEMICOLON{
//好像用不到		isFun_flag = 0;//用來看declare是不是function的flag結束
		if(func_declare_flag == 1){
			func_declare_flag = 0;
			scope_flag--;
			kill_symbol();
			if(lookup_symbol($2,"function") == 0 && lookup_global($2,"function")==0 && lookup_symbol($2,"variable") == 0 && lookup_global($2,"variable") == 0){
				insert_symbol($2,$1,"function",attribute_buf);
				Jinsert_function($2,function_pra_type);
				strcpy(attribute_buf,"");
			}
			else{
				//print_sym_flag = 2;
				print_semantic_flag =1;
				strcat(message_buf,"Redeclared function ");
                strcat(message_buf,$2);
			}
		}
		else{
			if(lookup_symbol($2,"variable") == 0&&lookup_symbol($2,"parameter") == 0&&lookup_symbol($2,"function") == 0&&lookup_global($2,"function")==0){
				insert_symbol($2,$1,"variable","");
				//如果scope是0表示是global的
				if(scope_flag == 0){
					if( strcmp($1,"float") == 0){
						sprintf(Jcode_buf,".field public static %s F = %f",$2,global_float);
						writeCode(Jcode_buf);
						if(global_float == 0){
							Jinsert_zero($2,1);//發現宣告是0
							printf("ddddd\n");
						}
						global_float = 0;
					}
					else if( strcmp($1,"int") == 0){
						sprintf(Jcode_buf,".field public static %s I = %d",$2,global_int);
						writeCode(Jcode_buf);
						if(global_int == 0){
							Jinsert_zero($2,1);//發現宣告是0
						}
						global_int = 0;
					}
					else if( strcmp($1,"string")==0){
						sprintf(Jcode_buf,".field public static %s Ljava/lang/String; = \"%s\"",$2,global_string);
						writeCode(Jcode_buf);
						strcpy(global_string,"");
					}
					else if( strcmp($1,"bool") ==0){
					    sprintf(Jcode_buf,".field public static %s I = %d",$2,global_bool);
                        writeCode(Jcode_buf);
                        global_bool = 0;
					}
				}
				//宣告的地方不是global的
				else{
					//如果後面沒有float
					if( exe_float_flag == 0){
						if(strcmp($1,"int")==0){
							//沒有初始化
							if(noinitial_flag ==1){
								sprintf(Jcode_buf,"\tldc 0");
								writeCode(Jcode_buf);
								Jinsert_zero($2,1);//表示會是0
								noinitial_flag = 0;
							}
							sprintf(Jcode_buf,"\tistore %d",getStackindex($2));
							writeCode(Jcode_buf);
						}
						else if(strcmp($1,"float")==0){
                            //沒有初始化
                            if(noinitial_flag ==1){
                                sprintf(Jcode_buf,"\tldc 0");
                                writeCode(Jcode_buf);
								Jinsert_zero($2,1);//表示會是0
                                noinitial_flag = 0;                                                                                                           
                            }
							sprintf(Jcode_buf,"\ti2f");
							writeCode(Jcode_buf);
							sprintf(Jcode_buf,"\tfstore %d",getStackindex($2));
							writeCode(Jcode_buf);
						}
					}
					//如果後面有float
					else if( exe_float_flag == 1){
						if(strcmp($1,"int")==0){
							sprintf(Jcode_buf,"\tf2i");
							writeCode(Jcode_buf);
							sprintf(Jcode_buf,"\tistore %d",getStackindex($2));
							writeCode(Jcode_buf);
						}
						else if(strcmp($1,"float")==0){
							sprintf(Jcode_buf,"\tfstore %d",getStackindex($2));
							writeCode(Jcode_buf);
						}
					}
					//跟上面沒關係，如果宣告的是string
					if( strcmp($1,"string") == 0){
						sprintf(Jcode_buf,"\tastore %d",getStackindex($2));
						writeCode(Jcode_buf);
					}
					//跟上面沒關係，如果宣告的是bool
					if( strcmp($1,"bool") == 0){
						//沒有初始化
						if(noinitial_flag ==1){
							sprintf(Jcode_buf,"\tldc 0");
							writeCode(Jcode_buf);
							noinitial_flag = 0;
						}
						sprintf(Jcode_buf,"\tistore %d",getStackindex($2));
						writeCode(Jcode_buf);
					}
				}
				exe_float_flag = 0;

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
	:declarator ASGN{
		exe_float_flag = 0;//宣告的算式開始處，結束在宣告的grammar
		assign_right = 1;//開始“=”右邊
	} 
	initializer{
		$$=$1;
		assign_right = 0;//“=”右邊使用結束
		printf("itype:%s\n",$4);
		if(strcmp($4,"IZERO") == 0 || strcmp($4,"FZERO") == 0){
			declare_zero = 1;
		}
	}
	|declarator{
		$$=$1;
		/*
		if( scope_flag > 0 ){
			printf("func_flag:%d\n",func_declare_flag);
			sprintf(Jcode_buf,"\tldc 0");
			writeCode(Jcode_buf);
			type_set.int_flag = 1;
			type_set.float_flag = 0;
		}
		*/
		noinitial_flag = 1;
	}
	
;
declarator
	:direct_declarator{$$=$1;}
;
direct_declarator
	:ID{	
		$$=$1;
	}
	|direct_declarator LB{printf("111\n");func_declare_flag = 1;scope_flag++;create_symbol(scope_flag);} RB
	|direct_declarator LB{printf("333\n");func_declare_flag = 1;scope_flag++;create_symbol(scope_flag);} parameter_type_list RB
	|direct_declarator LB identifier_list RB/*ex. int a = f(5);*///好像沒用到
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
		//Jcode用的type
		if( strcmp($1,"int") == 0){
			strcpy(function_pra_type,"I");
		}
		else if( strcmp($1,"flaot") == 0){
			strcpy(function_pra_type,"F");
		}
		else if( strcmp($1,"bool") == 0){
			strcpy(function_pra_type,"I");
		}
	}
	|parameter_list COMMA parameter_declaration{
		strcat(attribute_buf,", ");
		strcat(attribute_buf,$3);
		strcat(attribute_buf,"\0");
		//Jcode用的type
		if( strcmp($3,"int") == 0){
            strcat(function_pra_type,"I");
        }
        else if( strcmp($3,"flaot") == 0){
            strcat(function_pra_type,"F");
        }
		else if( strcmp($3,"bool") == 0){
			strcat(function_pra_type,"I");
		}

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
	:assignment_expression{$$ = $1;}
;
assignment_expression
	:relational_expression{$$=$1;}
	|unary_expression assignment_operator{
		assign_right = 1;
		exe_float_flag = 0;
	} 
	assignment_expression{
		assign_right = 0;//完成之後要把flag設回去
		//"="符號
		if($2 == 1){
			//不是global
			if(getStackindex($1) != -1){
				//等號左邊是int
				if(lookNglobal_type($1) == 1){
					//右邊是int
					if(exe_float_flag == 0){
						sprintf(Jcode_buf,"\tistore %d",getStackindex($1));
						writeCode(Jcode_buf);
					}
					//右邊是float
					else if(exe_float_flag == 1){
						sprintf(Jcode_buf,"\tf2i");
						writeCode(Jcode_buf);
						sprintf(Jcode_buf,"\tistore %d",getStackindex($1));
						writeCode(Jcode_buf);
					}
				}
				//等號左邊是float
				else if(lookNglobal_type($1) == 2){
					//右邊是int
					if(exe_float_flag == 0){
						sprintf(Jcode_buf,"\ti2f\n");
						writeCode(Jcode_buf);
						sprintf(Jcode_buf,"\tfstore %d",getStackindex($1));
						writeCode(Jcode_buf);
					}
					//右邊是float
					else if(exe_float_flag == 1){
						sprintf(Jcode_buf,"\tfstore %d",getStackindex($1));
						writeCode(Jcode_buf);
					}
				}
				//等號左邊是bool
				else if(lookNglobal_type($1) == 4){
					sprintf(Jcode_buf,"\tistore %d",getStackindex($1));
					writeCode(Jcode_buf);
				}
				//string不用考慮先宣告才賦值
			}
			//是global
			else if(getStackindex($1) == -1){
				//等號左邊是int
                if(lookglobal_type($1) == 1){
                    //右邊是int
                    if(exe_float_flag == 0){
                        sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s I",$1);
                        writeCode(Jcode_buf);
                    }   
                    //右邊是float
                    else if(exe_float_flag == 1){
                        sprintf(Jcode_buf,"\tf2i");
                        writeCode(Jcode_buf);
                        sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s I",$1);
                        writeCode(Jcode_buf);
                    }   
                }   
                //等號左邊是float
                else if(lookglobal_type($1) == 2){
                    //右邊是int
                    if(exe_float_flag == 0){
                        sprintf(Jcode_buf,"\ti2f\n");
                        writeCode(Jcode_buf);
                        sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s F",$1);
                        writeCode(Jcode_buf);
                    }   
                    //右邊是float
                    else if(exe_float_flag == 1){
                        sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s F",$1);
                        writeCode(Jcode_buf);
                    }   
                }
				//等號左邊是bool
				else if(lookglobal_type($1) == 4){
					sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s I",$1);
					writeCode(Jcode_buf);
				}
				//string不用考慮先宣告再賦值

			}
			exe_float_flag = 0;//回歸沒有
		}
		//是“+=”
		else if($2 == 2){
			printf("test:%s\n",$4);
			ADDASGNfunction($1,$4);
		}
		//是“-=”
		else if($2 == 3){
			SUBASGNfunction($1,$4);
		}
		//是“*=”
		else if($2 == 4){
			MULASGNfunction($1,$4);
		}
		else if($2 == 5){
		}
		else if($2 == 6){
			MODASGNfunction($1,$4);
		}
		exe_float_flag = 0;
	}
;

assignment_operator
	:ASGN{$$ = 1;}
	|ADDASGN{$$ = 2;}
	|SUBASGN{$$ = 3;}
	|MULASGN{$$ = 4;}
	|DIVASGN{$$ = 5;}
	|MODASGN{$$ = 6;}
;
relational_expression
	:additive_expression{$$=$1;}
	|relational_expression MT additive_expression{
		//來看要不要轉float
		RE_cha_function($1,$3);
		//如果前面大於後面就會是1
		sprintf(Jcode_buf,"\tfcmpl");
		writeCode(Jcode_buf);
		$$ ="MT";

	}
	|relational_expression LT additive_expression{
		RE_cha_function($1,$3);
		//先做swap，這樣就會反過來，如果前面小於後面就會是1
		sprintf(Jcode_buf,"\tswap");
		writeCode(Jcode_buf);
		sprintf(Jcode_buf,"\tfcmpl");
		writeCode(Jcode_buf);
		$$ ="LT";

	}
	|relational_expression MTE additive_expression{
		RE_cha_function($1,$3);
		//如果前面大於等於後面就會是0or1
		sprintf(Jcode_buf,"\tfcmpl");
		writeCode(Jcode_buf);
		$$ = "MTE";
	}
	|relational_expression LTE additive_expression{
		RE_cha_function($1,$3);
		//先做swap，這樣就會反過來，如果前面小於等於後面就會是0or1
		sprintf(Jcode_buf,"\tswap");
		writeCode(Jcode_buf);
		sprintf(Jcode_buf,"\tfcmpl");
		writeCode(Jcode_buf);
		$$ = "LTE";
	}
	|relational_expression EQ additive_expression{
		RE_cha_function($1,$3);
		//如果前面等於後面就是0
		sprintf(Jcode_buf,"\tfcmpl");
		writeCode(Jcode_buf);
		$$ = "EQ";
	}
	|relational_expression NE additive_expression{
		RE_cha_function($1,$3);
		//如果前面不等於後面就會是1or-1
		sprintf(Jcode_buf,"\tfcmpl");
		writeCode(Jcode_buf);
		$$ = "NE";
	}
;
additive_expression
	:multiplicative_expression{$$ = $1;}
	|additive_expression ADD multiplicative_expression{
		ADDfunction($1,$3);
		//處理cast的問題
		//兩個都是int
		if( (lookglobal_type($1) == 1 || lookNglobal_type($1) == 1) && (lookglobal_type($3) == 1 || lookNglobal_type($3) == 1) ){
//			sprintf(Jcode_buf,"\tiadd");
//			writeCode(Jcode_buf);
			$$ = "typeI";
		}
		//兩個都是float
		else if ( (lookglobal_type($1) == 2 || lookNglobal_type($1) == 2) && (lookglobal_type($3) == 2 || lookNglobal_type($3) == 2)){
//			sprintf(Jcode_buf,"\tfadd");
//			writeCode(Jcode_buf);
			//發現有float
//			exe_float_flag = 1;
			$$ = "typeF";
		}
		//前面是float後面是int
		else if ( (lookglobal_type($1) == 2 || lookNglobal_type($1) == 2) && (lookglobal_type($3) == 1 || lookNglobal_type($3) == 1)){
//			sprintf(Jcode_buf,"\ti2f\n");
//			strcat(Jcode_buf,"\tfadd");
//			writeCode(Jcode_buf);
			//發現有float
//			exe_float_flag = 1;
			$$ = "typeF";

		}
		//前面是int後面是float
		else if ( (lookglobal_type($1) == 1 || lookNglobal_type($1) == 1) && (lookglobal_type($3) == 2 || lookNglobal_type($3) == 2)){
//			sprintf(Jcode_buf,"\tswap\n");
//			strcat(Jcode_buf,"\ti2f\n");
//			strcat(Jcode_buf,"\tswap\n");
//			strcat(Jcode_buf,"\tfadd");
//			writeCode(Jcode_buf);
			//發現有float
//			exe_float_flag = 1;
			$$ = "typeF";
		}
	}
	|additive_expression SUB multiplicative_expression{
		//處理cast的問題
        //兩個都是int
        printf("%s %s\n",$1,$3);
        printf("%d \n",lookNglobal_type($1));
        if( (lookglobal_type($1) == 1 || lookNglobal_type($1) == 1) && (lookglobal_type($3) == 1 || lookNglobal_type($3) == 1) ){
            sprintf(Jcode_buf,"\tisub");
            writeCode(Jcode_buf);
            $$ = "typeI";
        }
        //兩個都是float
        else if ( (lookglobal_type($1) == 2 || lookNglobal_type($1) == 2) && (lookglobal_type($3) == 2 || lookNglobal_type($3) == 2)){
            sprintf(Jcode_buf,"\tfsub");
            writeCode(Jcode_buf);
            //發現有float
            exe_float_flag = 1;
            $$ = "typeF";
        }
        //前面是float後面是int
        else if ( (lookglobal_type($1) == 2 || lookNglobal_type($1) == 2) && (lookglobal_type($3) == 1 || lookNglobal_type($3) == 1)){
            sprintf(Jcode_buf,"\ti2f\n");
            strcat(Jcode_buf,"\tfsub");
            writeCode(Jcode_buf);
            //發現有float
            exe_float_flag = 1;
            $$ = "typeF";

        }
        //前面是int後面是float
        else if ( (lookglobal_type($1) == 1 || lookNglobal_type($1) == 1) && (lookglobal_type($3) == 2 || lookNglobal_type($3) == 2)){
            sprintf(Jcode_buf,"\tswap\n");
            strcat(Jcode_buf,"\ti2f\n");
			strcat(Jcode_buf,"\tswap\n");
            strcat(Jcode_buf,"\tfsub");
            writeCode(Jcode_buf);
            //發現有float
            exe_float_flag = 1;
            $$ = "typeF";
        }
	}
;
multiplicative_expression
	:unary_expression{$$ = $1;}
	|multiplicative_expression MUL unary_expression{
		//處理cast的問題
        //兩個都是int
        printf("%s %s\n",$1,$3);
        printf("%d \n",lookNglobal_type($1));
        if( (lookglobal_type($1) == 1 || lookNglobal_type($1) == 1) && (lookglobal_type($3) == 1 || lookNglobal_type($3) == 1) ){
            sprintf(Jcode_buf,"\timul");
            writeCode(Jcode_buf);
            $$ = "typeI";
        }
        //兩個都是float
        else if ( (lookglobal_type($1) == 2 || lookNglobal_type($1) == 2) && (lookglobal_type($3) == 2 || lookNglobal_type($3) == 2)){
            sprintf(Jcode_buf,"\tfmul");
            writeCode(Jcode_buf);
            //發現有float
            exe_float_flag = 1;
            $$ = "typeF";
        }
        //前面是float後面是int
        else if ( (lookglobal_type($1) == 2 || lookNglobal_type($1) == 2) && (lookglobal_type($3) == 1 || lookNglobal_type($3) == 1)){
            sprintf(Jcode_buf,"\ti2f\n");
            strcat(Jcode_buf,"\tfmul");
            writeCode(Jcode_buf);
            //發現有float
            exe_float_flag = 1;
            $$ = "typeF";

        }
        //前面是int後面是float
        else if ( (lookglobal_type($1) == 1 || lookNglobal_type($1) == 1) && (lookglobal_type($3) == 2 || lookNglobal_type($3) == 2)){
            sprintf(Jcode_buf,"\tswap\n");
            strcat(Jcode_buf,"\ti2f\n");
			strcat(Jcode_buf,"\tswap\n");
            strcat(Jcode_buf,"\tfmul");
            writeCode(Jcode_buf);
            //發現有float
            exe_float_flag = 1;
            $$ = "typeF";
        }

	}
	|multiplicative_expression DIV unary_expression{
		//DIV的function
		DIVfunction($1,$3);
		//處理cast的問題
        //兩個都是int
        printf("%s %s\n",$1,$3);
        printf("%d \n",lookNglobal_type($1));
        if( (lookglobal_type($1) == 1 || lookNglobal_type($1) == 1) && (lookglobal_type($3) == 1 || lookNglobal_type($3) == 1) ){
            $$ = "typeI";
        }
        //兩個都是float
        else if ( (lookglobal_type($1) == 2 || lookNglobal_type($1) == 2) && (lookglobal_type($3) == 2 || lookNglobal_type($3) == 2)){
            $$ = "typeF";
        }
        //前面是float後面是int
        else if ( (lookglobal_type($1) == 2 || lookNglobal_type($1) == 2) && (lookglobal_type($3) == 1 || lookNglobal_type($3) == 1)){
            $$ = "typeF";

        }
        //前面是int後面是float
        else if ( (lookglobal_type($1) == 1 || lookNglobal_type($1) == 1) && (lookglobal_type($3) == 2 || lookNglobal_type($3) == 2)){
            $$ = "typeF";
        }
	}
	|multiplicative_expression MOD unary_expression{
        //沒有cast的問題
        printf("%s %s\n",$1,$3);
        printf("%d \n",lookNglobal_type($1));
		//MOD的function
		MODfunction($1,$3);
		//兩個都是INT
        if( (lookglobal_type($1) == 1 || lookNglobal_type($1) == 1) && (lookglobal_type($3) == 1 || lookNglobal_type($3) == 1) ){
            $$ = "typeI";
        }
	}
;
unary_expression
	:postfix_expression{$$=$1;}
	|INC unary_expression
	|DEC unary_expression
	|unary_operation unary_expression{
		if(strcmp($1,"minus") == 0){
			if( lookNglobal_type($2) == 1 || lookglobal_type($2)==1){
				sprintf(Jcode_buf,"\tisub");
				writeCode(Jcode_buf);
				$$ = "typeI";
			}
			else if( lookNglobal_type($2) == 2|| lookglobal_type($2)==2){
				sprintf(Jcode_buf,"\tswap\n\ti2f\n\tswap\n");
				strcat(Jcode_buf,"\tfsub");
				writeCode(Jcode_buf);
				exe_float_flag = 1;
				$$ = "typeF";
			}
		}
		else if(strcmp($1,"plus") == 0){
            if( lookNglobal_type($2) == 1 || lookglobal_type($2)==1){
                $$ = "typeI";
            }
            else if( lookNglobal_type($2) == 2|| lookglobal_type($2)==2){
                exe_float_flag = 1;
                $$ = "typeF";
            }
		}
	}
;
unary_operation
	:ADD{
		$$ = "plus";
	}
	|SUB{
		$$ = "minus";
		sprintf(Jcode_buf,"\tldc 0");
		writeCode(Jcode_buf);
	}
;

postfix_expression
	:primary_expression{$$=$1;}
	|postfix_expression INC{
		//如果要++的型態是int
		if(lookNglobal_type($1) == 1 || lookglobal_type($1) == 1){
			$$ = "typeI";
			//global
			if(getStackindex($1) == -1){
				sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s I",$1);
			}
			//not global
			else{
				sprintf(Jcode_buf,"\tiload %d",getStackindex($1));
			}
			writeCode(Jcode_buf);
			sprintf(Jcode_buf,"\tldc 1");
			writeCode(Jcode_buf);
			sprintf(Jcode_buf,"\tiadd");
			writeCode(Jcode_buf);
			//global
			if(getStackindex($1) == -1){
				 sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s I",$1);
			}
			//notglobal
			else{
				sprintf(Jcode_buf,"\tistore %d",getStackindex($1));
            }
			writeCode(Jcode_buf);
		}
		//++的型態是float
		else if(lookNglobal_type($1) == 2 || lookglobal_type($1) == 2){
            $$ = "typeF";
			//global
            if(getStackindex($1) == -1){
                sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s F",$1);
            }
            //not global
            else{
                sprintf(Jcode_buf,"\tfload %d",getStackindex($1));
            }
            writeCode(Jcode_buf);
            sprintf(Jcode_buf,"\tldc 1.0");
            writeCode(Jcode_buf);
            sprintf(Jcode_buf,"\tfadd");
            writeCode(Jcode_buf);
            //global
            if(getStackindex($1) == -1){
                 sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s F",$1);
            }
            //notglobal
            else{
                sprintf(Jcode_buf,"\tfstore %d",getStackindex($1));
            }
            writeCode(Jcode_buf);			
		}
	}
	|postfix_expression DEC{
		//--型態是int
        if(lookNglobal_type($1) == 1 || lookglobal_type($1) == 1){
			$$ = "typeI";
            //global
            if(getStackindex($1) == -1){
                sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s I",$1);
            }
            //not global
            else{
                sprintf(Jcode_buf,"\tiload %d",getStackindex($1));
            }
            writeCode(Jcode_buf);
            sprintf(Jcode_buf,"\tldc 1");
            writeCode(Jcode_buf);
            sprintf(Jcode_buf,"\tisub");
            writeCode(Jcode_buf);
            //global
            if(getStackindex($1) == -1){
                 sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s I",$1);
            }
            //notglobal
            else{
                sprintf(Jcode_buf,"\tistore %d",getStackindex($1));
            }
            writeCode(Jcode_buf);
        }
        //++的型態是float
        else if(lookNglobal_type($1) == 2 || lookglobal_type($1) == 2){
			$$ = "typeF";
            //global
            if(getStackindex($1) == -1){
                sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s F",$1);
            }
            //not global
            else{
                sprintf(Jcode_buf,"\tfload %d",getStackindex($1));
            }
            writeCode(Jcode_buf);
            sprintf(Jcode_buf,"\tldc 1.0");
            writeCode(Jcode_buf);
            sprintf(Jcode_buf,"\tfsub");
            writeCode(Jcode_buf);
            //global
            if(getStackindex($1) == -1){
                 sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s F",$1);
            }
            //notglobal
            else{
                sprintf(Jcode_buf,"\tfstore %d",getStackindex($1));
            }
            writeCode(Jcode_buf);           
        }
	}
	|postfix_expression LB{isFun_flag = 1;strcpy(function_arg_type,"");} argument_expression_list RB/*function execute ex.f(x,y)*/{
		isFun_flag = 0;//function結束，argement也輸入完
		if(lookup_global($1,"function") != 2){
			//print_sym_flag = 2;
			print_semantic_flag =1;
			strcpy(message_buf,"Undeclared function ");
			strcat(message_buf,$1);
		}
		//Jcode處理callfunction的部分
		else{
			lookfunction_att($1);//使用這個function搭配att_buf
            //看這個function是什麼type
            if(lookglobal_type($1) == 1){
                $$ = "typeI";
            }
            else if(lookglobal_type($1) == 2){
                exe_float_flag = 1;
                $$ = "typeF";                                                                                                                                 
            }
            else if(lookglobal_type($1) == 5){
                $$ = "typeV";
            }			
			sprintf(Jcode_buf,"\tinvokestatic compiler_hw3/%s(%s)",$1,att_buf);
			//檢查argument和parameter有沒有一樣
			printf("arg:%s\n",function_arg_type);
			printf("att:%s\n",att_buf);
			if( strcmp(function_arg_type,att_buf) != 0){
				print_semantic_flag =1;
				strcpy(message_buf,"函式輸入的argument與宣告的相比有誤");
			}
			strcpy(function_arg_type,"");//清空
			strcpy(att_buf,"");//清空buf為了安全
			if(lookglobal_type($1) == 1){
				strcat(Jcode_buf,"I");
			}
			else if(lookglobal_type($1) == 2){
				strcat(Jcode_buf,"F");
			}
			else if(lookglobal_type($1) == 5){
				strcat(Jcode_buf,"V");
			}
			writeCode(Jcode_buf);
		}
	}
	|postfix_expression LB RB{
		if(lookup_global($1,"function") != 2){
            //print_sym_flag = 2;
			print_semantic_flag =1;
            strcpy(message_buf,"Undeclared function ");
            strcat(message_buf,$1);
        }
        //Jcode處理callfunction的部分
        else{
            lookfunction_att($1);//使用這個function搭配att_buf
            sprintf(Jcode_buf,"\tinvokestatic compiler_hw3/%s(%s)",$1,att_buf);
            //看這個function是什麼type
            if(lookglobal_type($1) == 1){
				$$ = "typeI";
            }
			else if(lookglobal_type($1) == 2){
				exe_float_flag = 1;
                $$ = "typeF";
			}
			else if(lookglobal_type($1) == 5){
				$$ = "typeV";
			}

            //檢查argument和parameter有沒有一樣
            printf("arg:%s\n",function_arg_type);
            printf("att:%s\n",att_buf);
            if( strcmp(function_arg_type,att_buf) != 0){
                print_semantic_flag =1;
                strcpy(message_buf,"函式輸入的argument與宣告的相比有誤");
            }
            strcpy(function_arg_type,"");//清空
            strcpy(att_buf,"");//清空buf為了安全
            if(lookglobal_type($1) == 1){
                strcat(Jcode_buf,"I");
            }
            else if(lookglobal_type($1) == 2){
                strcat(Jcode_buf,"F");
            }
            else if(lookglobal_type($1) == 5){
                strcat(Jcode_buf,"V");
            }
            writeCode(Jcode_buf);
        } 

	}
;
argument_expression_list
	:assignment_expression{
		//用來紀錄輸入了哪些argument
		printf("::%s\n",$1);
		if(lookglobal_type($1) == 1 || lookNglobal_type($1) == 1){
			strcat(function_arg_type,"I");
		}
		else if(lookglobal_type($1) == 2 || lookNglobal_type($1) == 2){
            strcat(function_arg_type,"F");
        }


	}
	|argument_expression_list COMMA assignment_expression{
		 //用來紀錄輸入了哪些argument
        printf("::%s\n",$3);
        if(lookglobal_type($3) == 1 || lookNglobal_type($3) == 1){
            strcat(function_arg_type,"I");
        }
        else if(lookglobal_type($3) == 2 || lookNglobal_type($3) == 2){
            strcat(function_arg_type,"F");
        }
	}
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
		//不是在等於的右邊就不用load
		if(assign_right == 1){
			//輸入的是全域變數且這個ID並不是function
			if(getStackindex($1) == -1 && lookup_global($1,"function") != 2){
				sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s ",$1);
				if(lookglobal_type($1) == 1){
					strcat(Jcode_buf,"I");
				}
				else if(lookglobal_type($1) ==2){
					strcat(Jcode_buf,"F");
					exe_float_flag = 1;//是float
				}
				writeCode(Jcode_buf);
			}
			else{
				if(lookNglobal_type($1) == 1){
					sprintf(Jcode_buf,"\tiload %d",getStackindex($1));
					writeCode(Jcode_buf);
				}
				else if( lookNglobal_type($1) == 2){
					sprintf(Jcode_buf,"\tfload %d",getStackindex($1));
					writeCode(Jcode_buf);
					exe_float_flag = 1;//是float
				}
			}
		}
		//如果不是在“=”左邊，但是是function 的話
		else if(isFun_flag == 1){
            //輸入的是全域變數且這個ID並不是function
            if(getStackindex($1) == -1 && lookup_global($1,"function") != 2){
                sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s ",$1);
                if(lookglobal_type($1) == 1){
                    strcat(Jcode_buf,"I");
                }
                else if(lookglobal_type($1) ==2){
                    strcat(Jcode_buf,"F");
                    exe_float_flag = 1;//是float
                }
                writeCode(Jcode_buf);
            }
            else{
                if(lookNglobal_type($1) == 1){
                    printf("HI:%d\n",assign_right);
                    sprintf(Jcode_buf,"\tiload %d",getStackindex($1));
                    writeCode(Jcode_buf);
                }
                else if( lookNglobal_type($1) == 2){
                    sprintf(Jcode_buf,"\tfload %d",getStackindex($1));
                    writeCode(Jcode_buf);
                    exe_float_flag = 1;//是float
                }
            }

		}
		else if(isReturn_flag == 1){
            //輸入的是全域變數且這個ID並不是function
            if(getStackindex($1) == -1 && lookup_global($1,"function") != 2){
                sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s ",$1);
                if(lookglobal_type($1) == 1){
                    strcat(Jcode_buf,"I");
                }
                else if(lookglobal_type($1) ==2){
                    strcat(Jcode_buf,"F");
                    exe_float_flag = 1;//是float
                }
                writeCode(Jcode_buf);
            }
            else{
                if(lookNglobal_type($1) == 1){
                    printf("HI:%d\n",assign_right);
                    sprintf(Jcode_buf,"\tiload %d",getStackindex($1));
                    writeCode(Jcode_buf);
                }
                else if( lookNglobal_type($1) == 2){
                    sprintf(Jcode_buf,"\tfload %d",getStackindex($1));
                    writeCode(Jcode_buf);
                    exe_float_flag = 1;//是float
                }
            }
		}
		else if(isWhile_flag ==1){
			//輸入的是全域變數且這個ID並不是function
            if(getStackindex($1) == -1 && lookup_global($1,"function") != 2){
                sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s ",$1);
                if(lookglobal_type($1) == 1){
                    strcat(Jcode_buf,"I");
                }
                else if(lookglobal_type($1) ==2){
                    strcat(Jcode_buf,"F");
                    exe_float_flag = 1;//是float
                }
                writeCode(Jcode_buf);
            }
            else{
                if(lookNglobal_type($1) == 1){
                    printf("HI:%d\n",assign_right);
                    sprintf(Jcode_buf,"\tiload %d",getStackindex($1));
                    writeCode(Jcode_buf);
                }
                else if( lookNglobal_type($1) == 2){
                    sprintf(Jcode_buf,"\tfload %d",getStackindex($1));
                    writeCode(Jcode_buf);
                    exe_float_flag = 1;//是float
                }
            }
		}
		else if(isIf_flag == 1){
			//輸入的是全域變數且這個ID並不是function
            if(getStackindex($1) == -1 && lookup_global($1,"function") != 2){
                sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s ",$1);
                if(lookglobal_type($1) == 1){
                    strcat(Jcode_buf,"I");
                }
                else if(lookglobal_type($1) ==2){
                    strcat(Jcode_buf,"F");
                    exe_float_flag = 1;//是float
                }
                writeCode(Jcode_buf);
            }
            else{
                if(lookNglobal_type($1) == 1){
                    printf("HI:%d\n",assign_right);
                    sprintf(Jcode_buf,"\tiload %d",getStackindex($1));
                    writeCode(Jcode_buf);
                }
                else if( lookNglobal_type($1) == 2){
                    sprintf(Jcode_buf,"\tfload %d",getStackindex($1));
                    writeCode(Jcode_buf);
                    exe_float_flag = 1;//是float
                }
            }
		}
	
	}
	|constant{$$ = $1;}
	|string
	|boolean
;
boolean
	:TRUE{
		global_bool = 1;
		if(scope_flag > 0){
			sprintf(Jcode_buf,"\tldc 1");
			writeCode(Jcode_buf);
		}
	}
	|FALSE{
		global_bool = 0;
		if(scope_flag > 0){
			sprintf(Jcode_buf,"\tldc 0");
			writeCode(Jcode_buf);
		}
	}
;
constant
	:I_CONST{
		//要看這個常數是不是0
		if( $1 == 0 ){
			$$ = "IZERO";
		}
		else{
			$$ = "ICONST";
		}
		global_int = $1;
		type_set.int_flag = 1;
		type_set.float_flag = 0;
		if(scope_flag > 0){
			sprintf(Jcode_buf,"\tldc %d",$1);
			writeCode(Jcode_buf);
		}
	}
	|F_CONST{
		//要看這個常數是不是0
		if( $1 == 0){
			$$ = "FZERO";
		}
		else{
			$$ = "FCONST";
		}
		global_float = $1;
		type_set.int_flag = 0;
		type_set.float_flag = 1;
		exe_float_flag = 1;//發現是float
		if(scope_flag > 0){
			sprintf(Jcode_buf,"\tldc %f",$1);
			writeCode(Jcode_buf);
		}
	}
;
string
	:STR_CONST{
		$$ = "STRCONST";
		sprintf(global_string,"%s",$1);
		if(scope_flag > 0){
			sprintf(Jcode_buf,"\tldc \"%s\"",$1);
			writeCode(Jcode_buf);
		}
	}
;
type_specifier
    : INT { $$ = $1;}
    | FLOAT { $$ = $1; }
    | BOOL  { $$ = $1; }
    | STRING { $$ = $1; }
    | VOID { $$ = $1; }
;
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
	//.j file的開頭
	file = fopen("compiler_hw3.j","w");
	fprintf(file,".class public compiler_hw3\n"
						".super java/lang/Object\n");
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
void Jinsert_function(char* name,char* Jattribute){
	int index;
	index = Current->var_index-1;
	Current->STable[index].Jatt = strdup(Jattribute);
}
void Jinsert_zero(char* var_name,int check){
	int index;
	index = Current->var_index-1;
	Current->STable[index].zero_flag = check;
}
void insert_func_implement(char* name){
	int i;
	for( i = 0 ; i < Current->var_index;i++){
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
//generation
void generateHeader(){
	


}
void writeCode(char* codeline){
	fprintf(file,"%s\n",codeline);
	strcpy(Jcode_buf,"");
	return;
}
int compare_type(char* var_name){
    int i;
	int same_not = 0;
    Node* tempnode;
    tempnode = First->next;
    while(tempnode != NULL){
        for(i = 0 ; i < tempnode->var_index ; i++){
            if(strcmp(var_name,tempnode->STable[i].name) == 0){
				if(type_set.int_flag == 1){
					if( strcmp(tempnode->STable[i].type,"float") == 0){
						same_not = 1;
					}
				}
				else if(type_set.float_flag == 1){
					if( strcmp(tempnode->STable[i].type,"int") == 0){
						same_not = 1;
					}
				}
            }
        }
        tempnode = tempnode->next;
    }
    return same_not;
}

int getStackindex(char* var_name){
	int i;
	int scope;
	int stack_index=0;
	Node* tempnode;
	tempnode = First;
	while(tempnode!=NULL){
		scope = tempnode->Scope;
		for(i = 0 ; i < tempnode->var_index ; i++){
			if(strcmp(var_name,tempnode->STable[i].name) == 0){
				if(scope == 0){
					return -1;
				}
				else{
					return stack_index;
				}
			}
			else{
				if(scope > 0){
					stack_index++;
				}
					
			}
		}
		tempnode = tempnode->next;
	}
	return -2;

}
int lookglobal_type(char* var_name){
	int i;
	int type=-1;//1是int，2是float,-1是找不到
	Node* tempnode;
	tempnode=First;
	for(i = 0 ; i < tempnode->var_index ; i++){
		if(strcmp(var_name,tempnode->STable[i].name)==0){
			if( strcmp(tempnode->STable[i].type,"int") == 0){
				type = 1;
			}
			else if( strcmp(tempnode->STable[i].type,"float")==0){
				type = 2;
			}
			else if( strcmp(tempnode->STable[i].type,"string")==0){
				type = 3;
			}
			else if( strcmp(tempnode->STable[i].type,"bool") == 0){
				type = 4;
			}
			else if( strcmp(tempnode->STable[i].type,"void") == 0){
                type = 5;
            }
		}
	}
	return type;
}


int lookNglobal_type(char* var_name){
    int i;
    int type = -1;//1 is int,2 is float，-1 is not find
    Node* tempnode;
    tempnode = First->next;
	if( strcmp(var_name,"ICONST") == 0 || strcmp(var_name,"typeI") == 0 || strcmp(var_name,"IZERO") == 0){
		return 1;
	}
	else if( strcmp(var_name,"FCONST") == 0 || strcmp(var_name,"typeF") == 0 || strcmp(var_name,"FZERO") == 0){
		return 2;
	}

    while(tempnode != NULL){
        for(i = 0 ; i < tempnode->var_index ; i++){
            if(strcmp(var_name,tempnode->STable[i].name) == 0){
                if( strcmp(tempnode->STable[i].type,"int") == 0){
                     type = 1;
                }
                else if( strcmp(tempnode->STable[i].type,"float") == 0){
                    type = 2;
                }
				else if( strcmp(tempnode->STable[i].type,"string") == 0){
					type = 3;
				}
				else if( strcmp(tempnode->STable[i].type,"bool") == 0){
					type = 4;
				}
				else if( strcmp(tempnode->STable[i].type,"void") == 0){
					type = 5;
				}
            }
        }
        tempnode = tempnode->next;
    }
    return type;
}
void lookfunction_att(char* fun_name){
    int i;
	char Jatt[10]="";
    Node* tempnode;
    tempnode=First;
    for(i = 0 ; i < tempnode->var_index ; i++){
        if(strcmp(fun_name,tempnode->STable[i].name)==0){
			strcpy(Jatt,tempnode->STable[i].Jatt);
			printf("Jatt:%s\n",tempnode->STable[i].Jatt);
        }
    }
	strcpy(att_buf,Jatt);
}
int check_zero(char* var_name){
	int is_zero = 0;
	int i;
	Node* tempnode;
	tempnode=First;
	if(strcmp( var_name,"IZERO") == 0 || strcmp(var_name,"FZERO") == 0){
		is_zero = 1;
	}
	else{

		while(tempnode != NULL){
			for(i = 0 ; i < tempnode->var_index ; i++){
				if(strcmp(var_name,tempnode->STable[i].name) == 0){
					if( tempnode->STable[i].zero_flag  == 1){
						 is_zero = 1;
					}
					else{
						is_zero = 0;
					}
				}
			}
			tempnode = tempnode->next;
		}
	}

	return is_zero;
}
void Loadfunction(char* left){
	//要load出來
    //不是global
    if(getStackindex(left) != -1){
        if(lookNglobal_type(left) == 1){
            sprintf(Jcode_buf,"\tiload %d",getStackindex(left));
        }
        else if(lookNglobal_type(left) == 2){
            sprintf(Jcode_buf,"\tfload %d",getStackindex(left));
        }
        writeCode(Jcode_buf);
    }
    //是global
    else if(getStackindex(left) == -1){
        if(lookglobal_type(left) == 1){
            sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s I",left);
        }
        else if(lookglobal_type(left) ==2){
            sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s F",left);
        }
        writeCode(Jcode_buf);
    }

}
void Storefunction(char* left,char* right){
	//不是global
	if(getStackindex(left) != -1){
		//等號左邊是int
		if(lookNglobal_type(left) == 1){
			//右邊是int
			if(lookNglobal_type(right) == 1){
				sprintf(Jcode_buf,"\tistore %d",getStackindex(left));
				writeCode(Jcode_buf);
			}
			//右邊是float
			else if(lookNglobal_type(right) == 2){
				sprintf(Jcode_buf,"\tf2i");
				writeCode(Jcode_buf);
				sprintf(Jcode_buf,"\tistore %d",getStackindex(left));
				writeCode(Jcode_buf);
			}
		}
		//等號左邊是float
		else if(lookNglobal_type(left) == 2){
			//右邊是int//不需要i2f，因為先做運算之後就會變成float了
			if(lookNglobal_type(right) == 1){
				sprintf(Jcode_buf,"\tfstore %d",getStackindex(left));
				writeCode(Jcode_buf);
			}
			//右邊是float
			else if(lookNglobal_type(right) == 2){
				sprintf(Jcode_buf,"\tfstore %d",getStackindex(left));
				writeCode(Jcode_buf);
			}
		}
		//等號左邊是bool
		else if(lookNglobal_type(left) == 4){
			sprintf(Jcode_buf,"\tistore %d",getStackindex(left));
			writeCode(Jcode_buf);
		}
		//string不用考慮先宣告才賦值
	}
	//是global
	else if(getStackindex(left) == -1){
		//等號左邊是int
		if(lookglobal_type(left) == 1){
			//右邊是int
			if(lookglobal_type(right) == 1){
				sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s I",left);
				writeCode(Jcode_buf);
			}   
			//右邊是float
			else if(lookglobal_type(right)  == 2){
				sprintf(Jcode_buf,"\tf2i");
				writeCode(Jcode_buf);
				sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s I",left);
				writeCode(Jcode_buf);
			}   
		}   
		//等號左邊是float
		else if(lookglobal_type(left) == 2){
			//右邊是int//不需要i2f，因為先做運算之後就會變成float了
			if(lookglobal_type(right) == 1){
				sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s F",left);
				writeCode(Jcode_buf);
			}   
			//右邊是float
			else if(lookglobal_type(right) == 2){
				sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s F",left);
				writeCode(Jcode_buf);
			}   
		}
		//等號左邊是bool
		else if(lookglobal_type(left) == 4){
			sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s I",left);
			writeCode(Jcode_buf);
		}
		//string不用考慮先宣告再賦值

	}
}
void ADDfunction(char* left,char* right){
	    //處理cast的問題
        //兩個都是int
        if( (lookglobal_type(left) == 1 || lookNglobal_type(left) == 1) && (lookglobal_type(right) == 1 || lookNglobal_type(right) == 1) ){
            sprintf(Jcode_buf,"\tiadd");
            writeCode(Jcode_buf);
        }
        //兩個都是float
        else if ( (lookglobal_type(left) == 2 || lookNglobal_type(left) == 2) && (lookglobal_type(right) == 2 || lookNglobal_type(right) == 2)){
            sprintf(Jcode_buf,"\tfadd");
            writeCode(Jcode_buf);
            //發現有float
            exe_float_flag = 1;
        }
        //前面是float後面是int
        else if ( (lookglobal_type(left) == 2 || lookNglobal_type(left) == 2) && (lookglobal_type(right) == 1 || lookNglobal_type(right) == 1)){
            sprintf(Jcode_buf,"\ti2f\n");
            strcat(Jcode_buf,"\tfadd");
            writeCode(Jcode_buf);
            //發現有float
            exe_float_flag = 1;

        }
        //前面是int後面是float
        else if ( (lookglobal_type(left) == 1 || lookNglobal_type(left) == 1) && (lookglobal_type(right) == 2 || lookNglobal_type(right) == 2)){
            sprintf(Jcode_buf,"\tswap\n");
            strcat(Jcode_buf,"\ti2f\n");
            strcat(Jcode_buf,"\tswap\n");
            strcat(Jcode_buf,"\tfadd");
            writeCode(Jcode_buf);
            //發現有float
            exe_float_flag = 1;
        }
}
void ADDASGNfunction(char* left , char* right){
	//要load出來
	//不是global
	if(getStackindex(left) != -1){
		if(lookNglobal_type(left) == 1){
			sprintf(Jcode_buf,"\tiload %d",getStackindex(left));
		}
		else if(lookNglobal_type(left) == 2){
			sprintf(Jcode_buf,"\tfload %d",getStackindex(left));
		}
		writeCode(Jcode_buf);
	}
	//是global
	else if(getStackindex(left) == -1){
		if(lookglobal_type(left) == 1){
			sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s I",left);
		}
		else if(lookglobal_type(left) ==2){
			sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s F",left);
		}
		writeCode(Jcode_buf);
	}
	//做swap
	sprintf(Jcode_buf,"\tswap");
	writeCode(Jcode_buf);
	//做add
	ADDfunction(left,right);

	//不是global
	if(getStackindex(left) != -1){
		//等號左邊是int
		if(lookNglobal_type(left) == 1){
			//右邊是int
			if(lookNglobal_type(right) == 1){
				sprintf(Jcode_buf,"\tistore %d",getStackindex(left));
				writeCode(Jcode_buf);
			}
			//右邊是float
			else if(lookNglobal_type(right) == 2){
				sprintf(Jcode_buf,"\tf2i");
				writeCode(Jcode_buf);
				sprintf(Jcode_buf,"\tistore %d",getStackindex(left));
				writeCode(Jcode_buf);
			}
		}
		//等號左邊是float
		else if(lookNglobal_type(left) == 2){
			//右邊是int//不需要i2f，因為先做運算之後就會變成float了
			if(lookNglobal_type(right) == 1){
				sprintf(Jcode_buf,"\tfstore %d",getStackindex(left));
				writeCode(Jcode_buf);
			}
			//右邊是float
			else if(lookNglobal_type(right) == 2){
				sprintf(Jcode_buf,"\tfstore %d",getStackindex(left));
				writeCode(Jcode_buf);
			}
		}
		//等號左邊是bool
		else if(lookNglobal_type(left) == 4){
			sprintf(Jcode_buf,"\tistore %d",getStackindex(left));
			writeCode(Jcode_buf);
		}
		//string不用考慮先宣告才賦值
	}
	//是global
	else if(getStackindex(left) == -1){
		//等號左邊是int
		if(lookglobal_type(left) == 1){
			//右邊是int
			if(lookglobal_type(right) == 1){
				sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s I",left);
				writeCode(Jcode_buf);
			}   
			//右邊是float
			else if(lookglobal_type(right)  == 2){
				sprintf(Jcode_buf,"\tf2i");
				writeCode(Jcode_buf);
				sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s I",left);
				writeCode(Jcode_buf);
			}   
		}   
		//等號左邊是float
		else if(lookglobal_type(left) == 2){
			//右邊是int//不需要i2f，因為先做運算之後就會變成float了
			if(lookglobal_type(right) == 1){
				sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s F",left);
				writeCode(Jcode_buf);
			}   
			//右邊是float
			else if(lookglobal_type(right) == 2){
				sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s F",left);
				writeCode(Jcode_buf);
			}   
		}
		//等號左邊是bool
		else if(lookglobal_type(left) == 4){
			sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s I",left);
			writeCode(Jcode_buf);
		}
		//string不用考慮先宣告再賦值

	}
	exe_float_flag = 0;//回歸沒有

}
void SUBfunction(char* left, char* right){
	//處理cast的問題
	//兩個都是int
	if( (lookglobal_type(left) == 1 || lookNglobal_type(left) == 1) && (lookglobal_type(right) == 1 || lookNglobal_type(right) == 1) ){
		sprintf(Jcode_buf,"\tisub");
		writeCode(Jcode_buf);
	}
	//兩個都是float
	else if ( (lookglobal_type(left) == 2 || lookNglobal_type(left) == 2) && (lookglobal_type(right) == 2 || lookNglobal_type(right) == 2)){
		sprintf(Jcode_buf,"\tfsub");
		writeCode(Jcode_buf);
		//發現有float
		exe_float_flag = 1;
	}
	//前面是float後面是int
	else if ( (lookglobal_type(left) == 2 || lookNglobal_type(left) == 2) && (lookglobal_type(right) == 1 || lookNglobal_type(right) == 1)){
		sprintf(Jcode_buf,"\ti2f\n");
		strcat(Jcode_buf,"\tfsub");
		writeCode(Jcode_buf);
		//發現有float
		exe_float_flag = 1;

	}
	//前面是int後面是float
	else if ( (lookglobal_type(left) == 1 || lookNglobal_type(left) == 1) && (lookglobal_type(right) == 2 || lookNglobal_type(right) == 2)){
		sprintf(Jcode_buf,"\tswap\n");
		strcat(Jcode_buf,"\ti2f\n");
		strcat(Jcode_buf,"\tswap\n");
		strcat(Jcode_buf,"\tfsub");
		writeCode(Jcode_buf);
		//發現有float
		exe_float_flag = 1;                                                                                                                               
	}
}
void SUBASGNfunction(char* left,char* right){
	//根據左邊的型態把他load出來
	Loadfunction(left);
	//要做swap
	sprintf(Jcode_buf,"\tswap");
	writeCode(Jcode_buf);
	//要做sub
	SUBfunction(left,right);
	Storefunction(left,right);

}
void MULfunction(char* left,char* right){
	//處理cast的問題
    //兩個都是int
    if( (lookglobal_type(left) == 1 || lookNglobal_type(left) == 1) && (lookglobal_type(right) == 1 || lookNglobal_type(right) == 1) ){
        sprintf(Jcode_buf,"\timul");
        writeCode(Jcode_buf);
    }
    //兩個都是float
    else if ( (lookglobal_type(left) == 2 || lookNglobal_type(left) == 2) && (lookglobal_type(right) == 2 || lookNglobal_type(right) == 2)){
        sprintf(Jcode_buf,"\tfmul");
        writeCode(Jcode_buf);
        //發現有float
        exe_float_flag = 1;
    }
    //前面是float後面是int
    else if ( (lookglobal_type(left) == 2 || lookNglobal_type(left) == 2) && (lookglobal_type(right) == 1 || lookNglobal_type(right) == 1)){
        sprintf(Jcode_buf,"\ti2f\n");
        strcat(Jcode_buf,"\tfmul");
        writeCode(Jcode_buf);
        //發現有float
        exe_float_flag = 1;

    }
    //前面是int後面是float
    else if ( (lookglobal_type(left) == 1 || lookNglobal_type(left) == 1) && (lookglobal_type(right) == 2 || lookNglobal_type(right) == 2)){
        sprintf(Jcode_buf,"\tswap\n");
        strcat(Jcode_buf,"\ti2f\n");
        strcat(Jcode_buf,"\tswap\n");
        strcat(Jcode_buf,"\tfmul");
        writeCode(Jcode_buf);
        //發現有float
        exe_float_flag = 1;
    }
}
void MULASGNfunction(char* left,char* right){
	//load出來
	Loadfunction(left);
	//要swap
	sprintf(Jcode_buf,"\tswap");
	writeCode(Jcode_buf);
	//做MUL
	MULfunction(left,right);
	//存回去
	Storefunction(left,right);
}
void MODfunction(char* left, char* right){
	//沒有cast的問題
    //兩個都是int
    if( (lookglobal_type(left) == 1 || lookNglobal_type(left) == 1) && (lookglobal_type(right) == 1 || lookNglobal_type(right) == 1) ){
        sprintf(Jcode_buf,"\tirem");
        writeCode(Jcode_buf);
    }
    else{
        print_semantic_flag = 1;
        strcpy(message_buf,"MOD只能用INT喔");
		
    }
}
void MODASGNfunction(char* left,char* right){
	//沒有cast的問題
	//load進來
	Loadfunction(left);
	//做swap
	sprintf(Jcode_buf,"\tswap");
	writeCode(Jcode_buf);
	//做mod
	MODfunction(left,right);
	Storefunction(left,right);
}
void DIVfunction(char* left,char*right){
	//處理有沒有ZERO的問題
	if( check_zero(right) == 1){
		print_semantic_flag = 1;
		strcpy(message_buf,"不能除以0喔");
	}
    //處理cast的問題
    //兩個都是int
    if( (lookglobal_type(left) == 1 || lookNglobal_type(left) == 1) && (lookglobal_type(right) == 1 || lookNglobal_type(right) == 1) ){
        sprintf(Jcode_buf,"\tidiv");
        writeCode(Jcode_buf);
    }
    //兩個都是float
    else if ( (lookglobal_type(left) == 2 || lookNglobal_type(left) == 2) && (lookglobal_type(right) == 2 || lookNglobal_type(right) == 2)){
        sprintf(Jcode_buf,"\tfdiv");
        writeCode(Jcode_buf);
        //發現有float
        exe_float_flag = 1;
    }
    //前面是float後面是int
    else if ( (lookglobal_type(left) == 2 || lookNglobal_type(left) == 2) && (lookglobal_type(right) == 1 || lookNglobal_type(right) == 1)){
        sprintf(Jcode_buf,"\ti2f\n");
        strcat(Jcode_buf,"\tfdiv");
        writeCode(Jcode_buf);
        //發現有float
        exe_float_flag = 1;

    }
    //前面是int後面是float
    else if ( (lookglobal_type(left) == 1 || lookNglobal_type(left) == 1) && (lookglobal_type(right) == 2 || lookNglobal_type(right) == 2)){
        sprintf(Jcode_buf,"\tswap\n");
        strcat(Jcode_buf,"\ti2f\n");
        strcat(Jcode_buf,"\tswap\n");
        strcat(Jcode_buf,"\tfdiv");
        writeCode(Jcode_buf);
        //發現有float
        exe_float_flag = 1;                                                                                                                                   
    }
}
void RE_cha_function(char* left,char* right){
    //處理比較時要換type的問題
    //兩個都是int->兩個都換成float
    if( (lookglobal_type(left) == 1 || lookNglobal_type(left) == 1) && (lookglobal_type(right) == 1 || lookNglobal_type(right) == 1) ){
        sprintf(Jcode_buf,"\ti2f\n");
		strcat(Jcode_buf,"\tswap\n");
		strcat(Jcode_buf,"\ti2f\n");
		strcat(Jcode_buf,"\tswap");
        writeCode(Jcode_buf);
    }
    //兩個都是float->就什麼都不用做
    else if ( (lookglobal_type(left) == 2 || lookNglobal_type(left) == 2) && (lookglobal_type(right) == 2 || lookNglobal_type(right) == 2)){
		;//什麼都不用
    }
    //前面是float後面是int
    //前面是int後面是float
    else{
		print_semantic_flag = 1;
		strcpy(message_buf,"這次比較不用考慮兩種不一樣的型態");
    } 	
}
