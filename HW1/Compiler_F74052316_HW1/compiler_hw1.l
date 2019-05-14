/* Definition section */
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	int num_line = 0;
	int num_commentline = 0;
	int string_len;
	int s_str_len = 0;
%}

/* Define regular expression label */

letter [a-zA-Z]
digit [0-9]
id {letter}+({letter}|{digit})*
number {digit}+
%x C_COMMENT
%x IN_STRING
%x STRING_Q
%x STRING_SPE
/* Rules section */
%%rt

" "		{;}
"\t"	{;}
"+" 	{ printf("%s \t ADD\n", yytext); }
"-"		{ printf("%s \t SUB\n", yytext); }
"*"		{ printf("%s \t MUL\n", yytext); }
"/"		{ printf("%s \t DIV\n", yytext); }  
"%"		{ printf("%s \t MOD\n", yytext); } 
"++"	{ printf("%s \t INC\n", yytext); } 
"--"	{ printf("%s \t DEC\n", yytext); }  
">"		{ printf("%s \t MT\n", yytext); }  
"<"		{ printf("%s \t LT\n", yytext); }  
">="	{ printf("%s \t MTE\n", yytext); }  
"<="	{ printf("%s \t LTE\n", yytext); } 
"=="	{ printf("%s \t EQ\n", yytext); }  
"!="	{ printf("%s \t NE\n", yytext); } 
"="		{ printf("%s \t ASGN\n", yytext); }  
"+="	{ printf("%s \t ADDASGN\n", yytext); } 
"-="	{ printf("%s \t SUBASGN\n", yytext); }  
"*="	{ printf("%s \t MULASGN\n", yytext); } 
"/="	{ printf("%s \t DIVASGN\n", yytext); } 
"%="	{ printf("%s \t MODASGN\n", yytext); }  
"&&"	{ printf("%s \t AND\n", yytext); }  
"||"	{ printf("%s \t OR\n", yytext); }  
"!"		{ printf("%s \t NOT\n", yytext); } 
"("		{ printf("%s \t LB\n", yytext); }  
")"		{ printf("%s \t RB\n", yytext); }  
"{"		{ printf("%s \t LCB\n", yytext); }  
"}"		{ printf("%s \t RCB\n", yytext); }  
"["		{ printf("%s \t LSB\n", yytext); }  
"]"		{ printf("%s \t RSB\n", yytext); }  
","		{ printf("%s \t COMMA\n", yytext); } 
";"		{ printf("%s \t SEMICOLON\n", yytext); } 
"\"\""	{ printf("\" \t QUOTA\n\" \t QUOTA\n");}
"\""	{ printf("%s \t QUOTA\n", yytext);s_str_len = 0;BEGIN IN_STRING; }
	<IN_STRING>"\\"+"\"" { printf("%s",yytext);s_str_len+=2;}
	<IN_STRING>[^"\""]	{ printf("%s", yytext) ; s_str_len++;}
	<IN_STRING>"\""	{
						if(s_str_len == 0){
							printf("%s \t QUOTA\n",yytext);
						}
						else{
							printf(" \t STR_CONST\n%s \t QUOTA\n",yytext);
						}
						BEGIN INITIAL;
					}
	<STRING_Q>"\""	{ printf("%s \t QUOTA\n", yytext);BEGIN INITIAL;}
"print"	{ printf("%s \t PRINT\n", yytext); }  
"if"	{ printf("%s \t IF\n", yytext); }  
"else"	{ printf("%s \t ELSE\n", yytext); }  
"for"	{ printf("%s \t FOR\n", yytext); }  
"while"	{ printf("%s \t WHILE\n", yytext); }  
"string"	{ printf("%s \t STRING\n", yytext); } 
"int"	{ printf("%s \t INT\n", yytext); }
"float"	{ printf("%s \t FLOAT\n", yytext); }  
"void"	{ printf("%s \t VOID\n", yytext); }  
"bool"	{ printf("%s \t BOOL\n", yytext); }  
"true"	{ printf("%s \t TRUE\n", yytext); }  
"false"	{ printf("%s \t FALSE\n", yytext); } 
"return"	{ printf("%s \t RET\n", yytext); }  
"continue"	{ printf("%s \t CONT\n", yytext); }  
"break"		{ printf("%s \t BREAK\n", yytext); }  
{digit}+	{ printf("%s \t I_CONST\n", yytext); }  
{digit}+"."{digit}+	{ printf("%s \t F_CONST\n", yytext); } 
"//".*"\n"	{ 
				string_len = 0;
				string_len = strlen(yytext);
				yytext[string_len-1] = '\0';
				printf("%s \t C++ Comment\n", yytext);
				num_commentline++;
				num_line++;
			}
"/*"	{ printf("%s", yytext);BEGIN C_COMMENT; } 
	<C_COMMENT>[^*\n]* { printf("%s", yytext); }  
	<C_COMMENT>\n { printf("%s", yytext);num_line++;num_commentline++; }  
	<C_COMMENT>"*"+"/" { printf("%s \t C Comment\n", yytext);BEGIN INITIAL; }
	<C_COMMENT>"*"+"/\n"	{ 
								string_len = 0;
								string_len = strlen(yytext);
								yytext[string_len-1] = '\0';
								printf("%s \t C Comment\n", yytext);
								num_commentline++;
								num_line++;
								BEGIN INITIAL;
							}
	<C_COMMENT>"*"+[^*/\n]*	{ printf("%s", yytext); }
{id}	{ printf("%s \t ID\n", yytext); }
\n			{num_line++;}

%%

/*	C Code section */
int yywrap(void)
{
    return 1;
}

int main(int argc,char *argv[])
{
	yyin = fopen(argv[1],"r");
	yylex();
	printf("\nParse over, the line number is %d.\n\n",num_line);
	printf("comment: %d lines\n\n",num_commentline);

	return 0;
}
