/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PRINT = 258,
     IF = 259,
     ELSE = 260,
     FOR = 261,
     WHILE = 262,
     SEMICOLON = 263,
     ADD = 264,
     SUB = 265,
     MUL = 266,
     DIV = 267,
     MOD = 268,
     INC = 269,
     DEC = 270,
     MT = 271,
     LT = 272,
     MTE = 273,
     LTE = 274,
     EQ = 275,
     NE = 276,
     ASGN = 277,
     ADDASGN = 278,
     SUBASGN = 279,
     MULASGN = 280,
     DIVASGN = 281,
     MODASGN = 282,
     AND = 283,
     OR = 284,
     NOT = 285,
     LB = 286,
     RB = 287,
     LCB = 288,
     RCB = 289,
     LSB = 290,
     RSB = 291,
     COMMA = 292,
     FALSE = 293,
     TRUE = 294,
     RET = 295,
     THEN = 296,
     I_CONST = 297,
     F_CONST = 298,
     STR_CONST = 299,
     STRING = 300,
     INT = 301,
     FLOAT = 302,
     BOOL = 303,
     VOID = 304,
     ID = 305
   };
#endif
/* Tokens.  */
#define PRINT 258
#define IF 259
#define ELSE 260
#define FOR 261
#define WHILE 262
#define SEMICOLON 263
#define ADD 264
#define SUB 265
#define MUL 266
#define DIV 267
#define MOD 268
#define INC 269
#define DEC 270
#define MT 271
#define LT 272
#define MTE 273
#define LTE 274
#define EQ 275
#define NE 276
#define ASGN 277
#define ADDASGN 278
#define SUBASGN 279
#define MULASGN 280
#define DIVASGN 281
#define MODASGN 282
#define AND 283
#define OR 284
#define NOT 285
#define LB 286
#define RB 287
#define LCB 288
#define RCB 289
#define LSB 290
#define RSB 291
#define COMMA 292
#define FALSE 293
#define TRUE 294
#define RET 295
#define THEN 296
#define I_CONST 297
#define F_CONST 298
#define STR_CONST 299
#define STRING 300
#define INT 301
#define FLOAT 302
#define BOOL 303
#define VOID 304
#define ID 305




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw3.y"

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
int isReturn_flag;//用來看現在這個ID是不是用來return的
int noinitial_flag;//用來看宣告的變數有沒有初始化
int declare_zero;//用來看declare的是不是zero
char function_pra_type[10];//用來存function的參數符號
char function_arg_type[10];//用來存functon的引數buf
int look_function_type_flag;//看一開始function是什麼type，return就要什麼type
void lookfunction_att(char* fun_name);//用來找一個function的type 是合起來的形式ex.II,
char att_buf[10];//用來借存lookfunction_att的結果
int while_label_num;//用來記住while用的labe
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


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 106 "compiler_hw3.y"
{
    int i_val;
    double f_val;
    char* string_val;
	char* type_val;
	char* id_val;
	int assign_flag;
}
/* Line 193 of yacc.c.  */
#line 306 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 319 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNRULES -- Number of states.  */
#define YYNSTATES  159

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    12,    13,    18,    19,
      23,    24,    29,    31,    34,    36,    38,    40,    42,    44,
      46,    48,    50,    56,    58,    60,    62,    64,    67,    68,
      73,    79,    80,    89,    90,    91,    99,   101,   104,   106,
     110,   114,   115,   120,   122,   124,   126,   127,   132,   133,
     139,   144,   146,   150,   152,   154,   158,   161,   163,   165,
     166,   171,   173,   175,   177,   179,   181,   183,   185,   189,
     193,   197,   201,   205,   209,   211,   215,   219,   221,   225,
     229,   233,   235,   238,   241,   244,   246,   248,   250,   253,
     256,   257,   263,   267,   269,   273,   275,   277,   279,   281,
     283,   285,   287,   289,   291,   293,   295,   297,   299
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    52,    53,    -1,    53,    -1,    73,    -1,
      54,    -1,    -1,   100,    76,    55,    56,    -1,    -1,    33,
      57,    34,    -1,    -1,    33,    58,    59,    34,    -1,    60,
      -1,    59,    60,    -1,    73,    -1,    61,    -1,    56,    -1,
      71,    -1,    68,    -1,    66,    -1,    64,    -1,    62,    -1,
       3,    31,    63,    32,     8,    -1,    44,    -1,    42,    -1,
      43,    -1,    50,    -1,    40,     8,    -1,    -1,    40,    65,
      72,     8,    -1,     4,    31,    72,    32,    61,    -1,    -1,
       4,    31,    72,    32,    61,     5,    67,    61,    -1,    -1,
      -1,     7,    69,    31,    72,    32,    70,    61,    -1,     8,
      -1,    72,     8,    -1,    85,    -1,    72,    37,    85,    -1,
     100,    74,     8,    -1,    -1,    76,    22,    75,    84,    -1,
      76,    -1,    77,    -1,    50,    -1,    -1,    77,    31,    78,
      32,    -1,    -1,    77,    31,    79,    81,    32,    -1,    77,
      31,    80,    32,    -1,    50,    -1,    80,    37,    50,    -1,
      82,    -1,    83,    -1,    82,    37,    83,    -1,   100,    76,
      -1,    85,    -1,    88,    -1,    -1,    91,    87,    86,    85,
      -1,    22,    -1,    23,    -1,    24,    -1,    25,    -1,    26,
      -1,    27,    -1,    89,    -1,    88,    16,    89,    -1,    88,
      17,    89,    -1,    88,    18,    89,    -1,    88,    19,    89,
      -1,    88,    20,    89,    -1,    88,    21,    89,    -1,    90,
      -1,    89,     9,    90,    -1,    89,    10,    90,    -1,    91,
      -1,    90,    11,    91,    -1,    90,    12,    91,    -1,    90,
      13,    91,    -1,    93,    -1,    14,    91,    -1,    15,    91,
      -1,    92,    91,    -1,     9,    -1,    10,    -1,    96,    -1,
      93,    14,    -1,    93,    15,    -1,    -1,    93,    31,    94,
      95,    32,    -1,    93,    31,    32,    -1,    85,    -1,    95,
      37,    85,    -1,    50,    -1,    98,    -1,    99,    -1,    97,
      -1,    39,    -1,    38,    -1,    42,    -1,    43,    -1,    44,
      -1,    46,    -1,    47,    -1,    48,    -1,    45,    -1,    49,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   166,   166,   167,   170,   171,   174,   174,   239,   239,
     251,   251,   266,   267,   270,   271,   274,   275,   276,   277,
     278,   279,   282,   285,   293,   301,   309,   384,   397,   397,
     422,   425,   425,   430,   437,   430,   468,   469,   472,   473,
     477,   601,   601,   613,   629,   632,   635,   635,   636,   636,
     637,   640,   641,   644,   647,   661,   679,   692,   695,   696,
     696,   808,   809,   810,   811,   812,   813,   816,   817,   826,
     836,   843,   852,   859,   868,   869,   908,   950,   951,   992,
    1016,  1029,  1030,  1031,  1032,  1059,  1062,  1070,  1071,  1125,
    1179,  1179,  1212,  1223,  1235,  1247,  1363,  1364,  1365,  1368,
    1375,  1384,  1400,  1419,  1429,  1430,  1431,  1432,  1433
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "IF", "ELSE", "FOR", "WHILE",
  "SEMICOLON", "ADD", "SUB", "MUL", "DIV", "MOD", "INC", "DEC", "MT", "LT",
  "MTE", "LTE", "EQ", "NE", "ASGN", "ADDASGN", "SUBASGN", "MULASGN",
  "DIVASGN", "MODASGN", "AND", "OR", "NOT", "LB", "RB", "LCB", "RCB",
  "LSB", "RSB", "COMMA", "FALSE", "TRUE", "RET", "THEN", "I_CONST",
  "F_CONST", "STR_CONST", "STRING", "INT", "FLOAT", "BOOL", "VOID", "ID",
  "$accept", "program", "external_declaration", "function_definition",
  "@1", "compound_statement", "@2", "@3", "block_item_list", "block_item",
  "statement", "print_function", "print_content", "jump_statement", "@4",
  "selection_statement", "@5", "iteration_statement", "@6", "@7",
  "expression_statement", "expression", "declaration", "init_declarator",
  "@8", "declarator", "direct_declarator", "@9", "@10", "identifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "initializer", "assignment_expression", "@11", "assignment_operator",
  "relational_expression", "additive_expression",
  "multiplicative_expression", "unary_expression", "unary_operation",
  "postfix_expression", "@12", "argument_expression_list",
  "primary_expression", "boolean", "constant", "string", "type_specifier", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    55,    54,    57,    56,
      58,    56,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    62,    63,    63,    63,    63,    64,    65,    64,
      66,    67,    66,    69,    70,    68,    71,    71,    72,    72,
      73,    75,    74,    74,    76,    77,    78,    77,    79,    77,
      77,    80,    80,    81,    82,    82,    83,    84,    85,    86,
      85,    87,    87,    87,    87,    87,    87,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    89,    90,    90,    90,
      90,    91,    91,    91,    91,    92,    92,    93,    93,    93,
      94,    93,    93,    95,    95,    96,    96,    96,    96,    97,
      97,    98,    98,    99,   100,   100,   100,   100,   100
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     0,     4,     0,     3,
       0,     4,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     1,     1,     1,     1,     2,     0,     4,
       5,     0,     8,     0,     0,     7,     1,     2,     1,     3,
       3,     0,     4,     1,     1,     1,     0,     4,     0,     5,
       4,     1,     3,     1,     1,     3,     2,     1,     1,     0,
       4,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     2,     1,     1,     1,     2,     2,
       0,     5,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   107,   104,   105,   106,   108,     0,     3,     5,     4,
       0,     1,     2,    45,     0,     6,    44,    40,    41,     0,
      48,     0,    10,     7,    51,     0,     0,     0,    85,    86,
       0,     0,   100,    99,   101,   102,   103,    95,    42,    57,
      58,    67,    74,    77,     0,    81,    87,    98,    96,    97,
       0,     0,    47,     0,    53,    54,     0,    50,     0,    82,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,    62,    63,    64,    65,    66,    59,    84,
      88,    89,    90,     9,     0,     0,    33,    36,    28,    16,
       0,    12,    15,    21,    20,    19,    18,    17,     0,    14,
      38,     0,    49,     0,    56,    52,    68,    77,    69,    70,
      71,    72,    73,    75,    76,    78,    79,    80,     0,    92,
       0,     0,     0,     0,    27,     0,    11,    13,    37,     0,
      43,    55,    60,    93,     0,    24,    25,    23,    26,     0,
       0,     0,     0,    39,    91,     0,     0,     0,     0,    29,
      94,    22,    30,    34,    31,     0,     0,    35,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    19,    89,    50,    51,    90,    91,
      92,    93,   139,    94,   125,    95,   156,    96,   123,   155,
      97,    98,     9,    14,    21,    15,    16,    25,    26,    27,
      53,    54,    55,    38,   100,   118,    78,    40,    41,    42,
      43,    44,    45,   120,   134,    46,    47,    48,    49,    10
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -132
static const yytype_int16 yypact[] =
{
     105,  -132,  -132,  -132,  -132,  -132,     2,  -132,  -132,  -132,
     -45,  -132,  -132,  -132,     3,     1,   -13,  -132,  -132,   -12,
     -28,    46,    -4,  -132,  -132,    21,   105,   -20,  -132,  -132,
      46,    46,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
     128,    34,    90,   162,    46,     5,  -132,  -132,  -132,  -132,
      43,    72,  -132,    51,    54,  -132,   -45,  -132,    45,  -132,
    -132,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,    66,  -132,    73,    75,  -132,  -132,    99,  -132,
      24,  -132,  -132,  -132,  -132,  -132,  -132,  -132,    -2,  -132,
    -132,   -45,  -132,   105,  -132,  -132,    34,  -132,    34,    34,
      34,    34,    34,    90,    90,  -132,  -132,  -132,    46,  -132,
      46,    50,    46,    78,  -132,    46,  -132,  -132,  -132,    46,
      91,  -132,  -132,  -132,     8,  -132,  -132,  -132,  -132,    95,
       9,    46,     0,  -132,  -132,    46,   115,   122,    22,  -132,
    -132,  -132,   123,  -132,  -132,   122,   122,  -132,  -132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,   127,  -132,  -132,   116,  -132,  -132,  -132,    44,
    -131,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -112,   -48,  -132,  -132,   -49,  -132,  -132,  -132,  -132,
    -132,  -132,    35,  -132,   -21,  -132,  -132,  -132,   129,   -53,
     112,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,   -25
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -47
static const yytype_int16 yytable[] =
{
      39,    56,    11,    99,   -46,    13,   128,   104,   149,   -43,
     140,    17,    57,   142,   113,   114,   152,    58,    20,    80,
      81,    22,    24,    18,   157,   158,   101,    84,    85,   148,
      -8,    86,    87,    28,    29,   129,    82,   129,    30,    31,
     144,   147,    99,    67,    68,   145,   129,     1,     2,     3,
       4,     5,   130,    52,   153,    28,    29,    22,   126,   129,
      30,    31,    32,    33,    88,   101,    34,    35,    36,     1,
       2,     3,     4,     5,    37,    84,    85,    83,    56,    86,
      87,    28,    29,   102,    32,    33,    30,    31,    34,    35,
      36,   103,   135,   136,   137,   105,    37,   132,   119,   133,
     138,    69,    70,    71,   121,    22,   122,   124,   143,   141,
      32,    33,    88,    18,    34,    35,    36,     1,     2,     3,
       4,     5,    37,   151,   150,    84,    85,   146,   154,    86,
      87,    28,    29,    12,   127,    23,    30,    31,   131,     0,
       0,     0,    59,    60,    61,    62,    63,    64,    65,    66,
       1,     2,     3,     4,     5,    22,    79,     0,     0,     0,
      32,    33,    88,     0,    34,    35,    36,     0,     0,     0,
       0,     0,    37,   107,   107,   107,   107,   107,   107,   107,
     107,   115,   116,   117,    72,    73,    74,    75,    76,    77,
     106,   108,   109,   110,   111,   112
};

static const yytype_int16 yycheck[] =
{
      21,    26,     0,    51,    32,    50,     8,    56,     8,     8,
     122,     8,    32,   125,    67,    68,   147,    37,    31,    14,
      15,    33,    50,    22,   155,   156,    51,     3,     4,   141,
      34,     7,     8,     9,    10,    37,    31,    37,    14,    15,
      32,    32,    90,     9,    10,    37,    37,    45,    46,    47,
      48,    49,   101,    32,    32,     9,    10,    33,    34,    37,
      14,    15,    38,    39,    40,    90,    42,    43,    44,    45,
      46,    47,    48,    49,    50,     3,     4,    34,   103,     7,
       8,     9,    10,    32,    38,    39,    14,    15,    42,    43,
      44,    37,    42,    43,    44,    50,    50,   118,    32,   120,
      50,    11,    12,    13,    31,    33,    31,     8,   129,    31,
      38,    39,    40,    22,    42,    43,    44,    45,    46,    47,
      48,    49,    50,     8,   145,     3,     4,    32,     5,     7,
       8,     9,    10,     6,    90,    19,    14,    15,   103,    -1,
      -1,    -1,    30,    31,    16,    17,    18,    19,    20,    21,
      45,    46,    47,    48,    49,    33,    44,    -1,    -1,    -1,
      38,    39,    40,    -1,    42,    43,    44,    -1,    -1,    -1,
      -1,    -1,    50,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    22,    23,    24,    25,    26,    27,
      61,    62,    63,    64,    65,    66
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    46,    47,    48,    49,    52,    53,    54,    73,
     100,     0,    53,    50,    74,    76,    77,     8,    22,    55,
      31,    75,    33,    56,    50,    78,    79,    80,     9,    10,
      14,    15,    38,    39,    42,    43,    44,    50,    84,    85,
      88,    89,    90,    91,    92,    93,    96,    97,    98,    99,
      57,    58,    32,    81,    82,    83,   100,    32,    37,    91,
      91,    16,    17,    18,    19,    20,    21,     9,    10,    11,
      12,    13,    22,    23,    24,    25,    26,    27,    87,    91,
      14,    15,    31,    34,     3,     4,     7,     8,    40,    56,
      59,    60,    61,    62,    64,    66,    68,    71,    72,    73,
      85,   100,    32,    37,    76,    50,    89,    91,    89,    89,
      89,    89,    89,    90,    90,    91,    91,    91,    86,    32,
      94,    31,    31,    69,     8,    65,    34,    60,     8,    37,
      76,    83,    85,    85,    95,    42,    43,    44,    50,    63,
      72,    31,    72,    85,    32,    37,    32,    32,    72,     8,
      85,     8,    61,    32,     5,    70,    67,    61,    61
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 166 "compiler_hw3.y"
    {}
    break;

  case 3:
#line 167 "compiler_hw3.y"
    {}
    break;

  case 6:
#line 174 "compiler_hw3.y"
    {
		//下Jcode的function的參數
		sprintf(Jcode_buf,".method public static %s(",(yyvsp[(2) - (2)].id_val));
		if( strcmp((yyvsp[(2) - (2)].id_val),"main") == 0){
			strcat(Jcode_buf,"[Ljava/lang/String;)");
		}
		else{
			strcat(Jcode_buf,function_pra_type);
			strcat(Jcode_buf,")");

		}
		//Jcode去加上function的type
		if( strcmp((yyvsp[(1) - (2)].type_val),"void") == 0){
			strcat(Jcode_buf,"V");
			look_function_type_flag = 5;
		}
		else if( strcmp((yyvsp[(1) - (2)].type_val),"int") == 0){
			strcat(Jcode_buf,"I");
			look_function_type_flag = 1;
		}
		else if( strcmp((yyvsp[(1) - (2)].type_val),"float") == 0){
			strcat(Jcode_buf,"F");
			look_function_type_flag = 2;
		}
		else if( strcmp((yyvsp[(1) - (2)].type_val),"bool") == 0){
			strcat(Jcode_buf,"I");
			look_function_type_flag = 4;
		}
		else if( strcmp((yyvsp[(1) - (2)].type_val),"string") == 0){
			look_function_type_flag = 3;
			//感覺不用做，不知道後面要用什麼type
		}
		writeCode(Jcode_buf);
		//Jcode加上stack local
		sprintf(Jcode_buf,".limit stack 50\n.limit locals 50");
		writeCode(Jcode_buf);

	}
    break;

  case 7:
#line 212 "compiler_hw3.y"
    {
		look_function_type_flag = 0;//function結束了，looktype初始化。
		func_declare_flag = 0;
        if(lookup_symbol((yyvsp[(2) - (4)].id_val),"function") == 0 && lookup_symbol((yyvsp[(2) - (4)].id_val),"variable") == 0){
            insert_symbol((yyvsp[(2) - (4)].id_val),(yyvsp[(1) - (4)].type_val),"function",attribute_buf);
			Jinsert_function((yyvsp[(2) - (4)].id_val),function_pra_type);
			insert_func_implement((yyvsp[(2) - (4)].id_val));
        }
		else if(lookup_symbol((yyvsp[(2) - (4)].id_val),"function") == 2){
			if(lookup_func_implement_times((yyvsp[(2) - (4)].id_val)) != 1){
				insert_func_implement((yyvsp[(2) - (4)].id_val));//first time implement
			}
			else{
                //print_sym_flag = 2;
				print_semantic_flag = 1;
                strcat(message_buf,"Redeclared function ");
                strcat(message_buf,(yyvsp[(2) - (4)].id_val));
			}
        }

		strcpy(attribute_buf,"");
		//function完成後要加end
		sprintf(Jcode_buf,".end method");
		writeCode(Jcode_buf);
	}
    break;

  case 8:
#line 239 "compiler_hw3.y"
    {	if(func_declare_flag == 0){
				scope_flag++;
                create_symbol(scope_flag);
            }
            else{
                func_declare_flag = 0;
			}
	}
    break;

  case 9:
#line 247 "compiler_hw3.y"
    {
		scope_flag--;
		dump_symbol();
	}
    break;

  case 10:
#line 251 "compiler_hw3.y"
    {	if(func_declare_flag == 0){
				scope_flag++;
				create_symbol(scope_flag);
			}
			else{
				func_declare_flag = 0;
			}
	}
    break;

  case 11:
#line 259 "compiler_hw3.y"
    {
		scope_flag--;
		print_sym_flag = 1;
		dump_symbol();
	}
    break;

  case 23:
#line 285 "compiler_hw3.y"
    {
		sprintf(Jcode_buf,"\tldc \"%s\"",(yyvsp[(1) - (1)].string_val));
        writeCode(Jcode_buf);
        sprintf(Jcode_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
        writeCode(Jcode_buf);
        sprintf(Jcode_buf,"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V");
        writeCode(Jcode_buf);
	}
    break;

  case 24:
#line 293 "compiler_hw3.y"
    {
        sprintf(Jcode_buf,"\tldc %d",(yyvsp[(1) - (1)].i_val));
        writeCode(Jcode_buf);
        sprintf(Jcode_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
        writeCode(Jcode_buf);
        sprintf(Jcode_buf,"\tinvokevirtual java/io/PrintStream/println(I)V");
        writeCode(Jcode_buf);
	}
    break;

  case 25:
#line 301 "compiler_hw3.y"
    {
		sprintf(Jcode_buf,"\tldc %f",(yyvsp[(1) - (1)].f_val));
        writeCode(Jcode_buf);
        sprintf(Jcode_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
        writeCode(Jcode_buf);
        sprintf(Jcode_buf,"\tinvokevirtual java/io/PrintStream/println(F)V");
        writeCode(Jcode_buf);
	}
    break;

  case 26:
#line 309 "compiler_hw3.y"
    {
		if(lookup_symbol((yyvsp[(1) - (1)].id_val),"variable")==0 && lookup_global((yyvsp[(1) - (1)].id_val),"variable")==0 &&lookup_symbol((yyvsp[(1) - (1)].id_val),"parameter") == 0 && lookup_global((yyvsp[(1) - (1)].id_val),"parameter") == 0){
			//print_sym_flag = 2;
			print_semantic_flag = 1;
			strcat(message_buf,"Undeclared variable ");
			strcat(message_buf,(yyvsp[(1) - (1)].id_val));
		}
		//沒有問題的部分
		else{
			//不是global
			if(getStackindex((yyvsp[(1) - (1)].id_val)) != -1){
				//是int
				if(lookNglobal_type((yyvsp[(1) - (1)].id_val)) == 1){
					sprintf(Jcode_buf,"\tiload %d",getStackindex((yyvsp[(1) - (1)].id_val)));
					writeCode(Jcode_buf);
					sprintf(Jcode_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
					writeCode(Jcode_buf);
					sprintf(Jcode_buf,"\tinvokevirtual java/io/PrintStream/println(I)V");
					writeCode(Jcode_buf);
				}
				//是float
				else if(lookNglobal_type((yyvsp[(1) - (1)].id_val)) == 2){
					sprintf(Jcode_buf,"\tfload %d",getStackindex((yyvsp[(1) - (1)].id_val)));
					writeCode(Jcode_buf);
					sprintf(Jcode_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
					writeCode(Jcode_buf);
					sprintf(Jcode_buf,"\tinvokevirtual java/io/PrintStream/println(F)V");
					writeCode(Jcode_buf);
				}
				else if(lookNglobal_type((yyvsp[(1) - (1)].id_val)) == 3){
					sprintf(Jcode_buf,"\taload %d",getStackindex((yyvsp[(1) - (1)].id_val)));
					writeCode(Jcode_buf);
					sprintf(Jcode_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
					writeCode(Jcode_buf);
					sprintf(Jcode_buf,"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V");
					writeCode(Jcode_buf);
				}

			}
			//是global
			else if( getStackindex((yyvsp[(1) - (1)].id_val)) == -1){
				printf("look:%d\n",lookglobal_type((yyvsp[(1) - (1)].id_val)));
				//是int
				if(lookglobal_type((yyvsp[(1) - (1)].id_val)) == 1){
					sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s I",(yyvsp[(1) - (1)].id_val));
					writeCode(Jcode_buf);
					sprintf(Jcode_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
					writeCode(Jcode_buf);
					sprintf(Jcode_buf,"\tinvokevirtual java/io/PrintStream/println(I)V");
					writeCode(Jcode_buf);
				}
				//是float
				else if(lookglobal_type((yyvsp[(1) - (1)].id_val)) == 2){
                    sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s F",(yyvsp[(1) - (1)].id_val));
                    writeCode(Jcode_buf);
                    sprintf(Jcode_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
                    writeCode(Jcode_buf);
                    sprintf(Jcode_buf,"\tinvokevirtual java/io/PrintStream/println(F)V");
                    writeCode(Jcode_buf);
                }
				//是string
				else if(lookglobal_type((yyvsp[(1) - (1)].id_val)) == 3){
                    sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s Ljava/lang/String;",(yyvsp[(1) - (1)].id_val));
                    writeCode(Jcode_buf);
                    sprintf(Jcode_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
                    writeCode(Jcode_buf);
                    sprintf(Jcode_buf,"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V");
                    writeCode(Jcode_buf);
                }
			}
		}
	}
    break;

  case 27:
#line 384 "compiler_hw3.y"
    {
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
    break;

  case 28:
#line 397 "compiler_hw3.y"
    {isReturn_flag = 1;}
    break;

  case 29:
#line 397 "compiler_hw3.y"
    {
		isReturn_flag = 0;//return的flag要歸回
		printf("return:%s\n",(yyvsp[(3) - (4)].id_val));
		//如果reutrn的type與function有一致
		if(look_function_type_flag == lookglobal_type((yyvsp[(3) - (4)].id_val)) || look_function_type_flag == lookNglobal_type((yyvsp[(3) - (4)].id_val))){
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
    break;

  case 30:
#line 422 "compiler_hw3.y"
    {
		writeCode("test2");
	}
    break;

  case 31:
#line 425 "compiler_hw3.y"
    {}
    break;

  case 32:
#line 425 "compiler_hw3.y"
    {
		writeCode("test22");
	}
    break;

  case 33:
#line 430 "compiler_hw3.y"
    {
		//產生label
		sprintf(Jcode_buf,"LABEL_WHILE_BEGIN_%d:",while_label_num);
		writeCode(Jcode_buf);
		//while判斷的開始
		isWhile_flag = 1;
	}
    break;

  case 34:
#line 437 "compiler_hw3.y"
    {
		isWhile_flag = 0;//while判斷的結束
		printf("compare:%s\n",(yyvsp[(4) - (5)].id_val));
		//判斷是什麼compare，如果是錯的就跳轉
		if( strcmp((yyvsp[(4) - (5)].id_val),"MT") == 0 || strcmp((yyvsp[(4) - (5)].id_val),"LT") == 0){
			sprintf(Jcode_buf,"\tifle LABEL_WHILE_FALSE_%d",while_label_num);
		}
		else if( strcmp((yyvsp[(4) - (5)].id_val),"MTE") == 0 || strcmp((yyvsp[(4) - (5)].id_val),"LTE") == 0){
            sprintf(Jcode_buf,"\tiflt LABEL_WHILE_FALSE_%d",while_label_num);
        }
		else if( strcmp((yyvsp[(4) - (5)].id_val),"EQ") == 0 ){
            sprintf(Jcode_buf,"\tifne LABEL_WHILE_FALSE_%d",while_label_num);
        }
		else if( strcmp((yyvsp[(4) - (5)].id_val),"NE") == 0){
            sprintf(Jcode_buf,"\tifeq LABEL_WHILE_FALSE_%d",while_label_num);
        }
		writeCode(Jcode_buf);

	}
    break;

  case 35:
#line 456 "compiler_hw3.y"
    {
		//回去再判斷的地方
		sprintf(Jcode_buf,"\tgoto LABEL_WHILE_BEGIN_%d",while_label_num);
		writeCode(Jcode_buf);
		//跳出loop要去的地方
		sprintf(Jcode_buf,"LABEL_WHILE_FALSE_%d:",while_label_num);
		writeCode(Jcode_buf);
		//label數+1
		while_label_num++;
	}
    break;

  case 38:
#line 472 "compiler_hw3.y"
    {(yyval.id_val)=(yyvsp[(1) - (1)].id_val);}
    break;

  case 40:
#line 477 "compiler_hw3.y"
    {
//好像用不到		isFun_flag = 0;//用來看declare是不是function的flag結束
		if(func_declare_flag == 1){
			func_declare_flag = 0;
			scope_flag--;
			kill_symbol();
			if(lookup_symbol((yyvsp[(2) - (3)].id_val),"function") == 0 && lookup_global((yyvsp[(2) - (3)].id_val),"function")==0 && lookup_symbol((yyvsp[(2) - (3)].id_val),"variable") == 0 && lookup_global((yyvsp[(2) - (3)].id_val),"variable") == 0){
				insert_symbol((yyvsp[(2) - (3)].id_val),(yyvsp[(1) - (3)].type_val),"function",attribute_buf);
				Jinsert_function((yyvsp[(2) - (3)].id_val),function_pra_type);
				strcpy(attribute_buf,"");
			}
			else{
				//print_sym_flag = 2;
				print_semantic_flag =1;
				strcat(message_buf,"Redeclared function ");
                strcat(message_buf,(yyvsp[(2) - (3)].id_val));
			}
		}
		else{
			if(lookup_symbol((yyvsp[(2) - (3)].id_val),"variable") == 0&&lookup_symbol((yyvsp[(2) - (3)].id_val),"parameter") == 0&&lookup_symbol((yyvsp[(2) - (3)].id_val),"function") == 0&&lookup_global((yyvsp[(2) - (3)].id_val),"function")==0){
				insert_symbol((yyvsp[(2) - (3)].id_val),(yyvsp[(1) - (3)].type_val),"variable","");
				//如果scope是0表示是global的
				if(scope_flag == 0){
					if( strcmp((yyvsp[(1) - (3)].type_val),"float") == 0){
						sprintf(Jcode_buf,".field public static %s F = %f",(yyvsp[(2) - (3)].id_val),global_float);
						writeCode(Jcode_buf);
						if(global_float == 0){
							Jinsert_zero((yyvsp[(2) - (3)].id_val),1);//發現宣告是0
						}
						global_float = 0;
					}
					else if( strcmp((yyvsp[(1) - (3)].type_val),"int") == 0){
						sprintf(Jcode_buf,".field public static %s I = %d",(yyvsp[(2) - (3)].id_val),global_int);
						writeCode(Jcode_buf);
						if(global_int == 0){
							Jinsert_zero((yyvsp[(2) - (3)].id_val),1);//發現宣告是0
						}
						global_int = 0;
					}
					else if( strcmp((yyvsp[(1) - (3)].type_val),"string")==0){
						sprintf(Jcode_buf,".field public static %s Ljava/lang/String; = \"%s\"",(yyvsp[(2) - (3)].id_val),global_string);
						writeCode(Jcode_buf);
						strcpy(global_string,"");
					}
					else if( strcmp((yyvsp[(1) - (3)].type_val),"bool") ==0){
					    sprintf(Jcode_buf,".field public static %s I = %d",(yyvsp[(2) - (3)].id_val),global_bool);
                        writeCode(Jcode_buf);
                        global_bool = 0;
					}
				}
				//宣告的地方不是global的
				else{
					//如果後面沒有float
					if( exe_float_flag == 0){
						if(strcmp((yyvsp[(1) - (3)].type_val),"int")==0){
							//沒有初始化
							if(noinitial_flag ==1){
								sprintf(Jcode_buf,"\tldc 0");
								writeCode(Jcode_buf);
								Jinsert_zero((yyvsp[(2) - (3)].id_val),1);//表示會是0
								noinitial_flag = 0;
							}
							sprintf(Jcode_buf,"\tistore %d",getStackindex((yyvsp[(2) - (3)].id_val)));
							writeCode(Jcode_buf);
						}
						else if(strcmp((yyvsp[(1) - (3)].type_val),"float")==0){
                            //沒有初始化
                            if(noinitial_flag ==1){
                                sprintf(Jcode_buf,"\tldc 0");
                                writeCode(Jcode_buf);
								Jinsert_zero((yyvsp[(2) - (3)].id_val),1);//表示會是0
                                noinitial_flag = 0;                                                                                                           
                            }
							sprintf(Jcode_buf,"\ti2f");
							writeCode(Jcode_buf);
							sprintf(Jcode_buf,"\tfstore %d",getStackindex((yyvsp[(2) - (3)].id_val)));
							writeCode(Jcode_buf);
						}
					}
					//如果後面有float
					else if( exe_float_flag == 1){
						if(strcmp((yyvsp[(1) - (3)].type_val),"int")==0){
							sprintf(Jcode_buf,"\tf2i");
							writeCode(Jcode_buf);
							sprintf(Jcode_buf,"\tistore %d",getStackindex((yyvsp[(2) - (3)].id_val)));
							writeCode(Jcode_buf);
						}
						else if(strcmp((yyvsp[(1) - (3)].type_val),"float")==0){
							sprintf(Jcode_buf,"\tfstore %d",getStackindex((yyvsp[(2) - (3)].id_val)));
							writeCode(Jcode_buf);
						}
					}
					//跟上面沒關係，如果宣告的是string
					if( strcmp((yyvsp[(1) - (3)].type_val),"string") == 0){
						sprintf(Jcode_buf,"\tastore %d",getStackindex((yyvsp[(2) - (3)].id_val)));
						writeCode(Jcode_buf);
					}
					//跟上面沒關係，如果宣告的是bool
					if( strcmp((yyvsp[(1) - (3)].type_val),"bool") == 0){
						//沒有初始化
						if(noinitial_flag ==1){
							sprintf(Jcode_buf,"\tldc 0");
							writeCode(Jcode_buf);
							noinitial_flag = 0;
						}
						sprintf(Jcode_buf,"\tistore %d",getStackindex((yyvsp[(2) - (3)].id_val)));
						writeCode(Jcode_buf);
					}
				}
				exe_float_flag = 0;

			}
			else{
				//print_sym_flag = 2;
				print_semantic_flag = 1;
				strcat(message_buf,"Redeclared variable ");
				strcat(message_buf,(yyvsp[(2) - (3)].id_val));
			}
        }
	
	}
    break;

  case 41:
#line 601 "compiler_hw3.y"
    {
		exe_float_flag = 0;//宣告的算式開始處，結束在宣告的grammar
		assign_right = 1;//開始“=”右邊
	}
    break;

  case 42:
#line 605 "compiler_hw3.y"
    {
		(yyval.id_val)=(yyvsp[(1) - (4)].id_val);
		assign_right = 0;//“=”右邊使用結束
		printf("itype:%s\n",(yyvsp[(4) - (4)].id_val));
		if(strcmp((yyvsp[(4) - (4)].id_val),"IZERO") == 0 || strcmp((yyvsp[(4) - (4)].id_val),"FZERO") == 0){
			declare_zero = 1;
		}
	}
    break;

  case 43:
#line 613 "compiler_hw3.y"
    {
		(yyval.id_val)=(yyvsp[(1) - (1)].id_val);
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
    break;

  case 44:
#line 629 "compiler_hw3.y"
    {(yyval.id_val)=(yyvsp[(1) - (1)].id_val);}
    break;

  case 45:
#line 632 "compiler_hw3.y"
    {	
		(yyval.id_val)=(yyvsp[(1) - (1)].id_val);
	}
    break;

  case 46:
#line 635 "compiler_hw3.y"
    {printf("111\n");func_declare_flag = 1;scope_flag++;create_symbol(scope_flag);}
    break;

  case 48:
#line 636 "compiler_hw3.y"
    {printf("333\n");func_declare_flag = 1;scope_flag++;create_symbol(scope_flag);}
    break;

  case 54:
#line 647 "compiler_hw3.y"
    {
		strcpy(attribute_buf,(yyvsp[(1) - (1)].type_val));
		strcat(attribute_buf,"\0");
		//Jcode用的type
		if( strcmp((yyvsp[(1) - (1)].type_val),"int") == 0){
			strcpy(function_pra_type,"I");
		}
		else if( strcmp((yyvsp[(1) - (1)].type_val),"flaot") == 0){
			strcpy(function_pra_type,"F");
		}
		else if( strcmp((yyvsp[(1) - (1)].type_val),"bool") == 0){
			strcpy(function_pra_type,"I");
		}
	}
    break;

  case 55:
#line 661 "compiler_hw3.y"
    {
		strcat(attribute_buf,", ");
		strcat(attribute_buf,(yyvsp[(3) - (3)].type_val));
		strcat(attribute_buf,"\0");
		//Jcode用的type
		if( strcmp((yyvsp[(3) - (3)].type_val),"int") == 0){
            strcat(function_pra_type,"I");
        }
        else if( strcmp((yyvsp[(3) - (3)].type_val),"flaot") == 0){
            strcat(function_pra_type,"F");
        }
		else if( strcmp((yyvsp[(3) - (3)].type_val),"bool") == 0){
			strcat(function_pra_type,"I");
		}

	}
    break;

  case 56:
#line 679 "compiler_hw3.y"
    {
		(yyval.type_val)=(yyvsp[(1) - (2)].type_val);
		if(lookup_symbol((yyvsp[(2) - (2)].id_val),"paremeter") == 0){
            insert_symbol((yyvsp[(2) - (2)].id_val),(yyvsp[(1) - (2)].type_val),"parameter","");                                              
        }
		else{
			print_semantic_flag = 1;
			strcat(message_buf,"Redeclared parameter ");
            strcat(message_buf,(yyvsp[(2) - (2)].id_val));
		}
	}
    break;

  case 57:
#line 692 "compiler_hw3.y"
    {(yyval.id_val) = (yyvsp[(1) - (1)].id_val);}
    break;

  case 58:
#line 695 "compiler_hw3.y"
    {(yyval.id_val)=(yyvsp[(1) - (1)].id_val);}
    break;

  case 59:
#line 696 "compiler_hw3.y"
    {
		assign_right = 1;
		exe_float_flag = 0;
	}
    break;

  case 60:
#line 700 "compiler_hw3.y"
    {
		assign_right = 0;//完成之後要把flag設回去
		//"="符號
		if((yyvsp[(2) - (4)].assign_flag) == 1){
			//不是global
			if(getStackindex((yyvsp[(1) - (4)].id_val)) != -1){
				//等號左邊是int
				if(lookNglobal_type((yyvsp[(1) - (4)].id_val)) == 1){
					//右邊是int
					if(exe_float_flag == 0){
						sprintf(Jcode_buf,"\tistore %d",getStackindex((yyvsp[(1) - (4)].id_val)));
						writeCode(Jcode_buf);
					}
					//右邊是float
					else if(exe_float_flag == 1){
						sprintf(Jcode_buf,"\tf2i");
						writeCode(Jcode_buf);
						sprintf(Jcode_buf,"\tistore %d",getStackindex((yyvsp[(1) - (4)].id_val)));
						writeCode(Jcode_buf);
					}
				}
				//等號左邊是float
				else if(lookNglobal_type((yyvsp[(1) - (4)].id_val)) == 2){
					//右邊是int
					if(exe_float_flag == 0){
						sprintf(Jcode_buf,"\ti2f\n");
						writeCode(Jcode_buf);
						sprintf(Jcode_buf,"\tfstore %d",getStackindex((yyvsp[(1) - (4)].id_val)));
						writeCode(Jcode_buf);
					}
					//右邊是float
					else if(exe_float_flag == 1){
						sprintf(Jcode_buf,"\tfstore %d",getStackindex((yyvsp[(1) - (4)].id_val)));
						writeCode(Jcode_buf);
					}
				}
				//等號左邊是bool
				else if(lookNglobal_type((yyvsp[(1) - (4)].id_val)) == 4){
					sprintf(Jcode_buf,"\tistore %d",getStackindex((yyvsp[(1) - (4)].id_val)));
					writeCode(Jcode_buf);
				}
				//string不用考慮先宣告才賦值
			}
			//是global
			else if(getStackindex((yyvsp[(1) - (4)].id_val)) == -1){
				//等號左邊是int
                if(lookglobal_type((yyvsp[(1) - (4)].id_val)) == 1){
                    //右邊是int
                    if(exe_float_flag == 0){
                        sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s I",(yyvsp[(1) - (4)].id_val));
                        writeCode(Jcode_buf);
                    }   
                    //右邊是float
                    else if(exe_float_flag == 1){
                        sprintf(Jcode_buf,"\tf2i");
                        writeCode(Jcode_buf);
                        sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s I",(yyvsp[(1) - (4)].id_val));
                        writeCode(Jcode_buf);
                    }   
                }   
                //等號左邊是float
                else if(lookglobal_type((yyvsp[(1) - (4)].id_val)) == 2){
                    //右邊是int
                    if(exe_float_flag == 0){
                        sprintf(Jcode_buf,"\ti2f\n");
                        writeCode(Jcode_buf);
                        sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s F",(yyvsp[(1) - (4)].id_val));
                        writeCode(Jcode_buf);
                    }   
                    //右邊是float
                    else if(exe_float_flag == 1){
                        sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s F",(yyvsp[(1) - (4)].id_val));
                        writeCode(Jcode_buf);
                    }   
                }
				//等號左邊是bool
				else if(lookglobal_type((yyvsp[(1) - (4)].id_val)) == 4){
					sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s I",(yyvsp[(1) - (4)].id_val));
					writeCode(Jcode_buf);
				}
				//string不用考慮先宣告再賦值

			}
			exe_float_flag = 0;//回歸沒有
		}
		//是“+=”
		else if((yyvsp[(2) - (4)].assign_flag) == 2){
			printf("test:%s\n",(yyvsp[(4) - (4)].id_val));
			ADDASGNfunction((yyvsp[(1) - (4)].id_val),(yyvsp[(4) - (4)].id_val));
		}
		//是“-=”
		else if((yyvsp[(2) - (4)].assign_flag) == 3){
			SUBASGNfunction((yyvsp[(1) - (4)].id_val),(yyvsp[(4) - (4)].id_val));
		}
		//是“*=”
		else if((yyvsp[(2) - (4)].assign_flag) == 4){
			MULASGNfunction((yyvsp[(1) - (4)].id_val),(yyvsp[(4) - (4)].id_val));
		}
		else if((yyvsp[(2) - (4)].assign_flag) == 5){
		}
		else if((yyvsp[(2) - (4)].assign_flag) == 6){
			MODASGNfunction((yyvsp[(1) - (4)].id_val),(yyvsp[(4) - (4)].id_val));
		}
		exe_float_flag = 0;
	}
    break;

  case 61:
#line 808 "compiler_hw3.y"
    {(yyval.assign_flag) = 1;}
    break;

  case 62:
#line 809 "compiler_hw3.y"
    {(yyval.assign_flag) = 2;}
    break;

  case 63:
#line 810 "compiler_hw3.y"
    {(yyval.assign_flag) = 3;}
    break;

  case 64:
#line 811 "compiler_hw3.y"
    {(yyval.assign_flag) = 4;}
    break;

  case 65:
#line 812 "compiler_hw3.y"
    {(yyval.assign_flag) = 5;}
    break;

  case 66:
#line 813 "compiler_hw3.y"
    {(yyval.assign_flag) = 6;}
    break;

  case 67:
#line 816 "compiler_hw3.y"
    {(yyval.id_val)=(yyvsp[(1) - (1)].id_val);}
    break;

  case 68:
#line 817 "compiler_hw3.y"
    {
		//來看要不要轉float
		RE_cha_function((yyvsp[(1) - (3)].id_val),(yyvsp[(3) - (3)].id_val));
		//如果前面大於後面就會是1
		sprintf(Jcode_buf,"\tfcmpl");
		writeCode(Jcode_buf);
		(yyval.id_val) ="MT";

	}
    break;

  case 69:
#line 826 "compiler_hw3.y"
    {
		RE_cha_function((yyvsp[(1) - (3)].id_val),(yyvsp[(3) - (3)].id_val));
		//先做swap，這樣就會反過來，如果前面小於後面就會是1
		sprintf(Jcode_buf,"\tswap");
		writeCode(Jcode_buf);
		sprintf(Jcode_buf,"\tfcmpl");
		writeCode(Jcode_buf);
		(yyval.id_val) ="LT";

	}
    break;

  case 70:
#line 836 "compiler_hw3.y"
    {
		RE_cha_function((yyvsp[(1) - (3)].id_val),(yyvsp[(3) - (3)].id_val));
		//如果前面大於等於後面就會是0or1
		sprintf(Jcode_buf,"\tfcmpl");
		writeCode(Jcode_buf);
		(yyval.id_val) = "MTE";
	}
    break;

  case 71:
#line 843 "compiler_hw3.y"
    {
		RE_cha_function((yyvsp[(1) - (3)].id_val),(yyvsp[(3) - (3)].id_val));
		//先做swap，這樣就會反過來，如果前面小於等於後面就會是0or1
		sprintf(Jcode_buf,"\tswap");
		writeCode(Jcode_buf);
		sprintf(Jcode_buf,"\tfcmpl");
		writeCode(Jcode_buf);
		(yyval.id_val) = "LTE";
	}
    break;

  case 72:
#line 852 "compiler_hw3.y"
    {
		RE_cha_function((yyvsp[(1) - (3)].id_val),(yyvsp[(3) - (3)].id_val));
		//如果前面等於後面就是0
		sprintf(Jcode_buf,"\tfcmpl");
		writeCode(Jcode_buf);
		(yyval.id_val) = "EQ";
	}
    break;

  case 73:
#line 859 "compiler_hw3.y"
    {
		RE_cha_function((yyvsp[(1) - (3)].id_val),(yyvsp[(3) - (3)].id_val));
		//如果前面不等於後面就會是1or-1
		sprintf(Jcode_buf,"\tfcmpl");
		writeCode(Jcode_buf);
		(yyval.id_val) = "NE";
	}
    break;

  case 74:
#line 868 "compiler_hw3.y"
    {(yyval.id_val) = (yyvsp[(1) - (1)].id_val);}
    break;

  case 75:
#line 869 "compiler_hw3.y"
    {
		ADDfunction((yyvsp[(1) - (3)].id_val),(yyvsp[(3) - (3)].id_val));
		//處理cast的問題
		//兩個都是int
		if( (lookglobal_type((yyvsp[(1) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(1) - (3)].id_val)) == 1) && (lookglobal_type((yyvsp[(3) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 1) ){
//			sprintf(Jcode_buf,"\tiadd");
//			writeCode(Jcode_buf);
			(yyval.id_val) = "typeI";
		}
		//兩個都是float
		else if ( (lookglobal_type((yyvsp[(1) - (3)].id_val)) == 2 || lookNglobal_type((yyvsp[(1) - (3)].id_val)) == 2) && (lookglobal_type((yyvsp[(3) - (3)].id_val)) == 2 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 2)){
//			sprintf(Jcode_buf,"\tfadd");
//			writeCode(Jcode_buf);
			//發現有float
//			exe_float_flag = 1;
			(yyval.id_val) = "typeF";
		}
		//前面是float後面是int
		else if ( (lookglobal_type((yyvsp[(1) - (3)].id_val)) == 2 || lookNglobal_type((yyvsp[(1) - (3)].id_val)) == 2) && (lookglobal_type((yyvsp[(3) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 1)){
//			sprintf(Jcode_buf,"\ti2f\n");
//			strcat(Jcode_buf,"\tfadd");
//			writeCode(Jcode_buf);
			//發現有float
//			exe_float_flag = 1;
			(yyval.id_val) = "typeF";

		}
		//前面是int後面是float
		else if ( (lookglobal_type((yyvsp[(1) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(1) - (3)].id_val)) == 1) && (lookglobal_type((yyvsp[(3) - (3)].id_val)) == 2 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 2)){
//			sprintf(Jcode_buf,"\tswap\n");
//			strcat(Jcode_buf,"\ti2f\n");
//			strcat(Jcode_buf,"\tswap\n");
//			strcat(Jcode_buf,"\tfadd");
//			writeCode(Jcode_buf);
			//發現有float
//			exe_float_flag = 1;
			(yyval.id_val) = "typeF";
		}
	}
    break;

  case 76:
#line 908 "compiler_hw3.y"
    {
		//處理cast的問題
        //兩個都是int
        printf("%s %s\n",(yyvsp[(1) - (3)].id_val),(yyvsp[(3) - (3)].id_val));
        printf("%d \n",lookNglobal_type((yyvsp[(1) - (3)].id_val)));
        if( (lookglobal_type((yyvsp[(1) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(1) - (3)].id_val)) == 1) && (lookglobal_type((yyvsp[(3) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 1) ){
            sprintf(Jcode_buf,"\tisub");
            writeCode(Jcode_buf);
            (yyval.id_val) = "typeI";
        }
        //兩個都是float
        else if ( (lookglobal_type((yyvsp[(1) - (3)].id_val)) == 2 || lookNglobal_type((yyvsp[(1) - (3)].id_val)) == 2) && (lookglobal_type((yyvsp[(3) - (3)].id_val)) == 2 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 2)){
            sprintf(Jcode_buf,"\tfsub");
            writeCode(Jcode_buf);
            //發現有float
            exe_float_flag = 1;
            (yyval.id_val) = "typeF";
        }
        //前面是float後面是int
        else if ( (lookglobal_type((yyvsp[(1) - (3)].id_val)) == 2 || lookNglobal_type((yyvsp[(1) - (3)].id_val)) == 2) && (lookglobal_type((yyvsp[(3) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 1)){
            sprintf(Jcode_buf,"\ti2f\n");
            strcat(Jcode_buf,"\tfsub");
            writeCode(Jcode_buf);
            //發現有float
            exe_float_flag = 1;
            (yyval.id_val) = "typeF";

        }
        //前面是int後面是float
        else if ( (lookglobal_type((yyvsp[(1) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(1) - (3)].id_val)) == 1) && (lookglobal_type((yyvsp[(3) - (3)].id_val)) == 2 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 2)){
            sprintf(Jcode_buf,"\tswap\n");
            strcat(Jcode_buf,"\ti2f\n");
			strcat(Jcode_buf,"\tswap\n");
            strcat(Jcode_buf,"\tfsub");
            writeCode(Jcode_buf);
            //發現有float
            exe_float_flag = 1;
            (yyval.id_val) = "typeF";
        }
	}
    break;

  case 77:
#line 950 "compiler_hw3.y"
    {(yyval.id_val) = (yyvsp[(1) - (1)].id_val);}
    break;

  case 78:
#line 951 "compiler_hw3.y"
    {
		//處理cast的問題
        //兩個都是int
        printf("%s %s\n",(yyvsp[(1) - (3)].id_val),(yyvsp[(3) - (3)].id_val));
        printf("%d \n",lookNglobal_type((yyvsp[(1) - (3)].id_val)));
        if( (lookglobal_type((yyvsp[(1) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(1) - (3)].id_val)) == 1) && (lookglobal_type((yyvsp[(3) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 1) ){
            sprintf(Jcode_buf,"\timul");
            writeCode(Jcode_buf);
            (yyval.id_val) = "typeI";
        }
        //兩個都是float
        else if ( (lookglobal_type((yyvsp[(1) - (3)].id_val)) == 2 || lookNglobal_type((yyvsp[(1) - (3)].id_val)) == 2) && (lookglobal_type((yyvsp[(3) - (3)].id_val)) == 2 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 2)){
            sprintf(Jcode_buf,"\tfmul");
            writeCode(Jcode_buf);
            //發現有float
            exe_float_flag = 1;
            (yyval.id_val) = "typeF";
        }
        //前面是float後面是int
        else if ( (lookglobal_type((yyvsp[(1) - (3)].id_val)) == 2 || lookNglobal_type((yyvsp[(1) - (3)].id_val)) == 2) && (lookglobal_type((yyvsp[(3) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 1)){
            sprintf(Jcode_buf,"\ti2f\n");
            strcat(Jcode_buf,"\tfmul");
            writeCode(Jcode_buf);
            //發現有float
            exe_float_flag = 1;
            (yyval.id_val) = "typeF";

        }
        //前面是int後面是float
        else if ( (lookglobal_type((yyvsp[(1) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(1) - (3)].id_val)) == 1) && (lookglobal_type((yyvsp[(3) - (3)].id_val)) == 2 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 2)){
            sprintf(Jcode_buf,"\tswap\n");
            strcat(Jcode_buf,"\ti2f\n");
			strcat(Jcode_buf,"\tswap\n");
            strcat(Jcode_buf,"\tfmul");
            writeCode(Jcode_buf);
            //發現有float
            exe_float_flag = 1;
            (yyval.id_val) = "typeF";
        }

	}
    break;

  case 79:
#line 992 "compiler_hw3.y"
    {
		//DIV的function
		DIVfunction((yyvsp[(1) - (3)].id_val),(yyvsp[(3) - (3)].id_val));
		//處理cast的問題
        //兩個都是int
        printf("%s %s\n",(yyvsp[(1) - (3)].id_val),(yyvsp[(3) - (3)].id_val));
        printf("%d \n",lookNglobal_type((yyvsp[(1) - (3)].id_val)));
        if( (lookglobal_type((yyvsp[(1) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(1) - (3)].id_val)) == 1) && (lookglobal_type((yyvsp[(3) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 1) ){
            (yyval.id_val) = "typeI";
        }
        //兩個都是float
        else if ( (lookglobal_type((yyvsp[(1) - (3)].id_val)) == 2 || lookNglobal_type((yyvsp[(1) - (3)].id_val)) == 2) && (lookglobal_type((yyvsp[(3) - (3)].id_val)) == 2 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 2)){
            (yyval.id_val) = "typeF";
        }
        //前面是float後面是int
        else if ( (lookglobal_type((yyvsp[(1) - (3)].id_val)) == 2 || lookNglobal_type((yyvsp[(1) - (3)].id_val)) == 2) && (lookglobal_type((yyvsp[(3) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 1)){
            (yyval.id_val) = "typeF";

        }
        //前面是int後面是float
        else if ( (lookglobal_type((yyvsp[(1) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(1) - (3)].id_val)) == 1) && (lookglobal_type((yyvsp[(3) - (3)].id_val)) == 2 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 2)){
            (yyval.id_val) = "typeF";
        }
	}
    break;

  case 80:
#line 1016 "compiler_hw3.y"
    {
        //沒有cast的問題
        printf("%s %s\n",(yyvsp[(1) - (3)].id_val),(yyvsp[(3) - (3)].id_val));
        printf("%d \n",lookNglobal_type((yyvsp[(1) - (3)].id_val)));
		//MOD的function
		MODfunction((yyvsp[(1) - (3)].id_val),(yyvsp[(3) - (3)].id_val));
		//兩個都是INT
        if( (lookglobal_type((yyvsp[(1) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(1) - (3)].id_val)) == 1) && (lookglobal_type((yyvsp[(3) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 1) ){
            (yyval.id_val) = "typeI";
        }
	}
    break;

  case 81:
#line 1029 "compiler_hw3.y"
    {(yyval.id_val)=(yyvsp[(1) - (1)].id_val);}
    break;

  case 84:
#line 1032 "compiler_hw3.y"
    {
		if(strcmp((yyvsp[(1) - (2)].id_val),"minus") == 0){
			if( lookNglobal_type((yyvsp[(2) - (2)].id_val)) == 1 || lookglobal_type((yyvsp[(2) - (2)].id_val))==1){
				sprintf(Jcode_buf,"\tisub");
				writeCode(Jcode_buf);
				(yyval.id_val) = "typeI";
			}
			else if( lookNglobal_type((yyvsp[(2) - (2)].id_val)) == 2|| lookglobal_type((yyvsp[(2) - (2)].id_val))==2){
				sprintf(Jcode_buf,"\tswap\n\ti2f\n\tswap\n");
				strcat(Jcode_buf,"\tfsub");
				writeCode(Jcode_buf);
				exe_float_flag = 1;
				(yyval.id_val) = "typeF";
			}
		}
		else if(strcmp((yyvsp[(1) - (2)].id_val),"plus") == 0){
            if( lookNglobal_type((yyvsp[(2) - (2)].id_val)) == 1 || lookglobal_type((yyvsp[(2) - (2)].id_val))==1){
                (yyval.id_val) = "typeI";
            }
            else if( lookNglobal_type((yyvsp[(2) - (2)].id_val)) == 2|| lookglobal_type((yyvsp[(2) - (2)].id_val))==2){
                exe_float_flag = 1;
                (yyval.id_val) = "typeF";
            }
		}
	}
    break;

  case 85:
#line 1059 "compiler_hw3.y"
    {
		(yyval.id_val) = "plus";
	}
    break;

  case 86:
#line 1062 "compiler_hw3.y"
    {
		(yyval.id_val) = "minus";
		sprintf(Jcode_buf,"\tldc 0");
		writeCode(Jcode_buf);
	}
    break;

  case 87:
#line 1070 "compiler_hw3.y"
    {(yyval.id_val)=(yyvsp[(1) - (1)].id_val);}
    break;

  case 88:
#line 1071 "compiler_hw3.y"
    {
		//如果要++的型態是int
		if(lookNglobal_type((yyvsp[(1) - (2)].id_val)) == 1 || lookglobal_type((yyvsp[(1) - (2)].id_val)) == 1){
			(yyval.id_val) = "typeI";
			//global
			if(getStackindex((yyvsp[(1) - (2)].id_val)) == -1){
				sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s I",(yyvsp[(1) - (2)].id_val));
			}
			//not global
			else{
				sprintf(Jcode_buf,"\tiload %d",getStackindex((yyvsp[(1) - (2)].id_val)));
			}
			writeCode(Jcode_buf);
			sprintf(Jcode_buf,"\tldc 1");
			writeCode(Jcode_buf);
			sprintf(Jcode_buf,"\tiadd");
			writeCode(Jcode_buf);
			//global
			if(getStackindex((yyvsp[(1) - (2)].id_val)) == -1){
				 sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s I",(yyvsp[(1) - (2)].id_val));
			}
			//notglobal
			else{
				sprintf(Jcode_buf,"\tistore %d",getStackindex((yyvsp[(1) - (2)].id_val)));
            }
			writeCode(Jcode_buf);
		}
		//++的型態是float
		else if(lookNglobal_type((yyvsp[(1) - (2)].id_val)) == 2 || lookglobal_type((yyvsp[(1) - (2)].id_val)) == 2){
            (yyval.id_val) = "typeF";
			//global
            if(getStackindex((yyvsp[(1) - (2)].id_val)) == -1){
                sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s F",(yyvsp[(1) - (2)].id_val));
            }
            //not global
            else{
                sprintf(Jcode_buf,"\tfload %d",getStackindex((yyvsp[(1) - (2)].id_val)));
            }
            writeCode(Jcode_buf);
            sprintf(Jcode_buf,"\tldc 1.0");
            writeCode(Jcode_buf);
            sprintf(Jcode_buf,"\tfadd");
            writeCode(Jcode_buf);
            //global
            if(getStackindex((yyvsp[(1) - (2)].id_val)) == -1){
                 sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s F",(yyvsp[(1) - (2)].id_val));
            }
            //notglobal
            else{
                sprintf(Jcode_buf,"\tfstore %d",getStackindex((yyvsp[(1) - (2)].id_val)));
            }
            writeCode(Jcode_buf);			
		}
	}
    break;

  case 89:
#line 1125 "compiler_hw3.y"
    {
		//--型態是int
        if(lookNglobal_type((yyvsp[(1) - (2)].id_val)) == 1 || lookglobal_type((yyvsp[(1) - (2)].id_val)) == 1){
			(yyval.id_val) = "typeI";
            //global
            if(getStackindex((yyvsp[(1) - (2)].id_val)) == -1){
                sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s I",(yyvsp[(1) - (2)].id_val));
            }
            //not global
            else{
                sprintf(Jcode_buf,"\tiload %d",getStackindex((yyvsp[(1) - (2)].id_val)));
            }
            writeCode(Jcode_buf);
            sprintf(Jcode_buf,"\tldc 1");
            writeCode(Jcode_buf);
            sprintf(Jcode_buf,"\tisub");
            writeCode(Jcode_buf);
            //global
            if(getStackindex((yyvsp[(1) - (2)].id_val)) == -1){
                 sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s I",(yyvsp[(1) - (2)].id_val));
            }
            //notglobal
            else{
                sprintf(Jcode_buf,"\tistore %d",getStackindex((yyvsp[(1) - (2)].id_val)));
            }
            writeCode(Jcode_buf);
        }
        //++的型態是float
        else if(lookNglobal_type((yyvsp[(1) - (2)].id_val)) == 2 || lookglobal_type((yyvsp[(1) - (2)].id_val)) == 2){
			(yyval.id_val) = "typeF";
            //global
            if(getStackindex((yyvsp[(1) - (2)].id_val)) == -1){
                sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s F",(yyvsp[(1) - (2)].id_val));
            }
            //not global
            else{
                sprintf(Jcode_buf,"\tfload %d",getStackindex((yyvsp[(1) - (2)].id_val)));
            }
            writeCode(Jcode_buf);
            sprintf(Jcode_buf,"\tldc 1.0");
            writeCode(Jcode_buf);
            sprintf(Jcode_buf,"\tfsub");
            writeCode(Jcode_buf);
            //global
            if(getStackindex((yyvsp[(1) - (2)].id_val)) == -1){
                 sprintf(Jcode_buf,"\tputstatic compiler_hw3/%s F",(yyvsp[(1) - (2)].id_val));
            }
            //notglobal
            else{
                sprintf(Jcode_buf,"\tfstore %d",getStackindex((yyvsp[(1) - (2)].id_val)));
            }
            writeCode(Jcode_buf);           
        }
	}
    break;

  case 90:
#line 1179 "compiler_hw3.y"
    {isFun_flag = 1;strcpy(function_arg_type,"");}
    break;

  case 91:
#line 1179 "compiler_hw3.y"
    {
		isFun_flag = 0;//function結束，argement也輸入完
		if(lookup_global((yyvsp[(1) - (5)].id_val),"function") != 2){
			//print_sym_flag = 2;
			print_semantic_flag =1;
			strcpy(message_buf,"Undeclared function ");
			strcat(message_buf,(yyvsp[(1) - (5)].id_val));
		}
		//Jcode處理callfunction的部分
		else{
			lookfunction_att((yyvsp[(1) - (5)].id_val));//使用這個function搭配att_buf
			sprintf(Jcode_buf,"\tinvokestatic compiler_hw3/%s(%s)",(yyvsp[(1) - (5)].id_val),att_buf);
			//檢查argument和parameter有沒有一樣
			printf("arg:%s\n",function_arg_type);
			printf("att:%s\n",att_buf);
			if( strcmp(function_arg_type,att_buf) != 0){
				print_semantic_flag =1;
				strcpy(message_buf,"函式輸入的argument與宣告的相比有誤");
			}
			strcpy(function_arg_type,"");//清空
			strcpy(att_buf,"");//清空buf為了安全
			if(lookglobal_type((yyvsp[(1) - (5)].id_val)) == 1){
				strcat(Jcode_buf,"I");
			}
			else if(lookglobal_type((yyvsp[(1) - (5)].id_val)) == 2){
				strcat(Jcode_buf,"F");
			}
			else if(lookglobal_type((yyvsp[(1) - (5)].id_val)) == 5){
				strcat(Jcode_buf,"V");
			}
			writeCode(Jcode_buf);
		}
	}
    break;

  case 92:
#line 1212 "compiler_hw3.y"
    {
		if(lookup_global((yyvsp[(1) - (3)].id_val),"function") != 2){
            //print_sym_flag = 2;
			print_semantic_flag =1;
            strcpy(message_buf,"Undeclared function ");
            strcat(message_buf,(yyvsp[(1) - (3)].id_val));
        }

	}
    break;

  case 93:
#line 1223 "compiler_hw3.y"
    {
		//用來紀錄輸入了哪些argument
		printf("::%s\n",(yyvsp[(1) - (1)].id_val));
		if(lookglobal_type((yyvsp[(1) - (1)].id_val)) == 1 || lookNglobal_type((yyvsp[(1) - (1)].id_val)) == 1){
			strcat(function_arg_type,"I");
		}
		else if(lookglobal_type((yyvsp[(1) - (1)].id_val)) == 2 || lookNglobal_type((yyvsp[(1) - (1)].id_val)) == 2){
            strcat(function_arg_type,"F");
        }


	}
    break;

  case 94:
#line 1235 "compiler_hw3.y"
    {
		 //用來紀錄輸入了哪些argument
        printf("::%s\n",(yyvsp[(3) - (3)].id_val));
        if(lookglobal_type((yyvsp[(3) - (3)].id_val)) == 1 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 1){
            strcat(function_arg_type,"I");
        }
        else if(lookglobal_type((yyvsp[(3) - (3)].id_val)) == 2 || lookNglobal_type((yyvsp[(3) - (3)].id_val)) == 2){
            strcat(function_arg_type,"F");
        }
	}
    break;

  case 95:
#line 1247 "compiler_hw3.y"
    {
		(yyval.id_val)=(yyvsp[(1) - (1)].id_val);
		if(lookup_global((yyvsp[(1) - (1)].id_val),"variable") == 0 && lookup_symbol((yyvsp[(1) - (1)].id_val),"variable" )==0 &&lookup_global((yyvsp[(1) - (1)].id_val),"parameter") == 0 && lookup_symbol((yyvsp[(1) - (1)].id_val),"parameter")==0 &&lookup_global((yyvsp[(1) - (1)].id_val),"function") == 0 && lookup_symbol((yyvsp[(1) - (1)].id_val),"function" )==0){
			//print_sym_flag = 2;
			print_semantic_flag =1;
			strcat(message_buf,"Undeclared variable ");
			strcat(message_buf,(yyvsp[(1) - (1)].id_val));
		}
		//不是在等於的右邊就不用load
		if(assign_right == 1){
			//輸入的是全域變數且這個ID並不是function
			if(getStackindex((yyvsp[(1) - (1)].id_val)) == -1 && lookup_global((yyvsp[(1) - (1)].id_val),"function") != 2){
				sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s ",(yyvsp[(1) - (1)].id_val));
				if(lookglobal_type((yyvsp[(1) - (1)].id_val)) == 1){
					strcat(Jcode_buf,"I");
				}
				else if(lookglobal_type((yyvsp[(1) - (1)].id_val)) ==2){
					strcat(Jcode_buf,"F");
					exe_float_flag = 1;//是float
				}
				writeCode(Jcode_buf);
			}
			else{
				if(lookNglobal_type((yyvsp[(1) - (1)].id_val)) == 1){
					sprintf(Jcode_buf,"\tiload %d",getStackindex((yyvsp[(1) - (1)].id_val)));
					writeCode(Jcode_buf);
				}
				else if( lookNglobal_type((yyvsp[(1) - (1)].id_val)) == 2){
					sprintf(Jcode_buf,"\tfload %d",getStackindex((yyvsp[(1) - (1)].id_val)));
					writeCode(Jcode_buf);
					exe_float_flag = 1;//是float
				}
			}
		}
		//如果不是在“=”左邊，但是是function 的話
		else if(isFun_flag == 1){
            //輸入的是全域變數且這個ID並不是function
            if(getStackindex((yyvsp[(1) - (1)].id_val)) == -1 && lookup_global((yyvsp[(1) - (1)].id_val),"function") != 2){
                sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s ",(yyvsp[(1) - (1)].id_val));
                if(lookglobal_type((yyvsp[(1) - (1)].id_val)) == 1){
                    strcat(Jcode_buf,"I");
                }
                else if(lookglobal_type((yyvsp[(1) - (1)].id_val)) ==2){
                    strcat(Jcode_buf,"F");
                    exe_float_flag = 1;//是float
                }
                writeCode(Jcode_buf);
            }
            else{
                if(lookNglobal_type((yyvsp[(1) - (1)].id_val)) == 1){
                    printf("HI:%d\n",assign_right);
                    sprintf(Jcode_buf,"\tiload %d",getStackindex((yyvsp[(1) - (1)].id_val)));
                    writeCode(Jcode_buf);
                }
                else if( lookNglobal_type((yyvsp[(1) - (1)].id_val)) == 2){
                    sprintf(Jcode_buf,"\tfload %d",getStackindex((yyvsp[(1) - (1)].id_val)));
                    writeCode(Jcode_buf);
                    exe_float_flag = 1;//是float
                }
            }

		}
		else if(isReturn_flag == 1){
            //輸入的是全域變數且這個ID並不是function
            if(getStackindex((yyvsp[(1) - (1)].id_val)) == -1 && lookup_global((yyvsp[(1) - (1)].id_val),"function") != 2){
                sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s ",(yyvsp[(1) - (1)].id_val));
                if(lookglobal_type((yyvsp[(1) - (1)].id_val)) == 1){
                    strcat(Jcode_buf,"I");
                }
                else if(lookglobal_type((yyvsp[(1) - (1)].id_val)) ==2){
                    strcat(Jcode_buf,"F");
                    exe_float_flag = 1;//是float
                }
                writeCode(Jcode_buf);
            }
            else{
                if(lookNglobal_type((yyvsp[(1) - (1)].id_val)) == 1){
                    printf("HI:%d\n",assign_right);
                    sprintf(Jcode_buf,"\tiload %d",getStackindex((yyvsp[(1) - (1)].id_val)));
                    writeCode(Jcode_buf);
                }
                else if( lookNglobal_type((yyvsp[(1) - (1)].id_val)) == 2){
                    sprintf(Jcode_buf,"\tfload %d",getStackindex((yyvsp[(1) - (1)].id_val)));
                    writeCode(Jcode_buf);
                    exe_float_flag = 1;//是float
                }
            }
		}
		else if(isWhile_flag ==1){
			//輸入的是全域變數且這個ID並不是function
            if(getStackindex((yyvsp[(1) - (1)].id_val)) == -1 && lookup_global((yyvsp[(1) - (1)].id_val),"function") != 2){
                sprintf(Jcode_buf,"\tgetstatic compiler_hw3/%s ",(yyvsp[(1) - (1)].id_val));
                if(lookglobal_type((yyvsp[(1) - (1)].id_val)) == 1){
                    strcat(Jcode_buf,"I");
                }
                else if(lookglobal_type((yyvsp[(1) - (1)].id_val)) ==2){
                    strcat(Jcode_buf,"F");
                    exe_float_flag = 1;//是float
                }
                writeCode(Jcode_buf);
            }
            else{
                if(lookNglobal_type((yyvsp[(1) - (1)].id_val)) == 1){
                    printf("HI:%d\n",assign_right);
                    sprintf(Jcode_buf,"\tiload %d",getStackindex((yyvsp[(1) - (1)].id_val)));
                    writeCode(Jcode_buf);
                }
                else if( lookNglobal_type((yyvsp[(1) - (1)].id_val)) == 2){
                    sprintf(Jcode_buf,"\tfload %d",getStackindex((yyvsp[(1) - (1)].id_val)));
                    writeCode(Jcode_buf);
                    exe_float_flag = 1;//是float
                }
            }
		}
	
	}
    break;

  case 96:
#line 1363 "compiler_hw3.y"
    {(yyval.id_val) = (yyvsp[(1) - (1)].id_val);}
    break;

  case 99:
#line 1368 "compiler_hw3.y"
    {
		global_bool = 1;
		if(scope_flag > 0){
			sprintf(Jcode_buf,"\tldc 1");
			writeCode(Jcode_buf);
		}
	}
    break;

  case 100:
#line 1375 "compiler_hw3.y"
    {
		global_bool = 0;
		if(scope_flag > 0){
			sprintf(Jcode_buf,"\tldc 0");
			writeCode(Jcode_buf);
		}
	}
    break;

  case 101:
#line 1384 "compiler_hw3.y"
    {
		//要看這個常數是不是0
		if( (yyvsp[(1) - (1)].i_val) == 0 ){
			(yyval.id_val) = "IZERO";
		}
		else{
			(yyval.id_val) = "ICONST";
		}
		global_int = (yyvsp[(1) - (1)].i_val);
		type_set.int_flag = 1;
		type_set.float_flag = 0;
		if(scope_flag > 0){
			sprintf(Jcode_buf,"\tldc %d",(yyvsp[(1) - (1)].i_val));
			writeCode(Jcode_buf);
		}
	}
    break;

  case 102:
#line 1400 "compiler_hw3.y"
    {
		//要看這個常數是不是0
		if( (yyvsp[(1) - (1)].f_val) == 0){
			(yyval.id_val) = "FZERO";
		}
		else{
			(yyval.id_val) = "FCONST";
		}
		global_int = (yyvsp[(1) - (1)].f_val);
		type_set.int_flag = 0;
		type_set.float_flag = 1;
		exe_float_flag = 1;//發現是float
		if(scope_flag > 0){
			sprintf(Jcode_buf,"\tldc %f",(yyvsp[(1) - (1)].f_val));
			writeCode(Jcode_buf);
		}
	}
    break;

  case 103:
#line 1419 "compiler_hw3.y"
    {
		(yyval.id_val) = "STRCONST";
		sprintf(global_string,"%s",(yyvsp[(1) - (1)].string_val));
		if(scope_flag > 0){
			sprintf(Jcode_buf,"\tldc \"%s\"",(yyvsp[(1) - (1)].string_val));
			writeCode(Jcode_buf);
		}
	}
    break;

  case 104:
#line 1429 "compiler_hw3.y"
    { (yyval.type_val) = (yyvsp[(1) - (1)].type_val);}
    break;

  case 105:
#line 1430 "compiler_hw3.y"
    { (yyval.type_val) = (yyvsp[(1) - (1)].type_val); }
    break;

  case 106:
#line 1431 "compiler_hw3.y"
    { (yyval.type_val) = (yyvsp[(1) - (1)].type_val); }
    break;

  case 107:
#line 1432 "compiler_hw3.y"
    { (yyval.type_val) = (yyvsp[(1) - (1)].type_val); }
    break;

  case 108:
#line 1433 "compiler_hw3.y"
    { (yyval.type_val) = (yyvsp[(1) - (1)].type_val); }
    break;


/* Line 1267 of yacc.c.  */
#line 3178 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1435 "compiler_hw3.y"


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
