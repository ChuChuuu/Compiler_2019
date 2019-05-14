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
#line 2 "compiler_hw2.y"

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
int error_flag;//test if print symbol table at last
/* Symbol table function - you can add new function if needed. */
int lookup_symbol(char* name,char* kind);
int lookup_global(char* name,char* kind);
void create_symbol();
void insert_symbol(char* name,char* type,char* kind,char* attribute);
void dump_symbol();
void kill_symbol();
void yyerror(char *s);
void se_error(char *s);
/*some variable*/
typedef struct {
	int index;
	int scope;
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
#line 52 "compiler_hw2.y"
{
    int i_val;
    double f_val;
    char* string_val;
	char* type_val;
	char* id_val;
}
/* Line 193 of yacc.c.  */
#line 251 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 264 "y.tab.c"

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
#define YYLAST   229

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNRULES -- Number of states.  */
#define YYNSTATES  149

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
       0,     0,     3,     6,     8,    10,    12,    16,    17,    21,
      22,    27,    29,    32,    34,    36,    38,    40,    42,    44,
      46,    48,    54,    56,    58,    61,    65,    71,    79,    85,
      87,    90,    92,    96,   100,   104,   106,   108,   110,   111,
     116,   117,   123,   128,   130,   134,   136,   138,   142,   145,
     147,   149,   153,   155,   157,   159,   161,   163,   165,   167,
     171,   175,   179,   183,   187,   191,   193,   197,   201,   203,
     207,   211,   215,   217,   220,   223,   226,   228,   230,   232,
     235,   238,   243,   247,   249,   253,   255,   257,   259,   261,
     263,   265,   267,   269,   271,   273,   275,   277,   279
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    52,    53,    -1,    53,    -1,    68,    -1,
      54,    -1,    92,    70,    55,    -1,    -1,    33,    56,    34,
      -1,    -1,    33,    57,    58,    34,    -1,    59,    -1,    58,
      59,    -1,    68,    -1,    60,    -1,    55,    -1,    66,    -1,
      65,    -1,    64,    -1,    63,    -1,    61,    -1,     3,    31,
      62,    32,     8,    -1,    44,    -1,    50,    -1,    40,     8,
      -1,    40,    67,     8,    -1,     4,    31,    67,    32,    60,
      -1,     4,    31,    67,    32,    60,     5,    60,    -1,     7,
      31,    67,    32,    60,    -1,     8,    -1,    67,     8,    -1,
      79,    -1,    67,    37,    79,    -1,    92,    69,     8,    -1,
      70,    22,    78,    -1,    70,    -1,    71,    -1,    50,    -1,
      -1,    71,    31,    72,    32,    -1,    -1,    71,    31,    73,
      75,    32,    -1,    71,    31,    74,    32,    -1,    50,    -1,
      74,    37,    50,    -1,    76,    -1,    77,    -1,    76,    37,
      77,    -1,    92,    70,    -1,    79,    -1,    81,    -1,    84,
      80,    79,    -1,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,    82,    -1,    81,    16,    82,
      -1,    81,    17,    82,    -1,    81,    18,    82,    -1,    81,
      19,    82,    -1,    81,    20,    82,    -1,    81,    21,    82,
      -1,    83,    -1,    82,     9,    83,    -1,    82,    10,    83,
      -1,    84,    -1,    83,    11,    84,    -1,    83,    12,    84,
      -1,    83,    13,    84,    -1,    86,    -1,    14,    84,    -1,
      15,    84,    -1,    85,    84,    -1,     9,    -1,    10,    -1,
      88,    -1,    86,    14,    -1,    86,    15,    -1,    86,    31,
      87,    32,    -1,    86,    31,    32,    -1,    79,    -1,    87,
      37,    79,    -1,    50,    -1,    90,    -1,    91,    -1,    89,
      -1,    39,    -1,    38,    -1,    42,    -1,    43,    -1,    44,
      -1,    46,    -1,    47,    -1,    48,    -1,    45,    -1,    49,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   101,   104,   105,   108,   117,   117,   129,
     129,   144,   145,   148,   149,   152,   153,   154,   155,   156,
     157,   160,   163,   164,   174,   175,   178,   179,   182,   185,
     186,   189,   190,   194,   224,   225,   228,   231,   236,   236,
     237,   237,   238,   241,   242,   245,   248,   252,   259,   267,
     270,   271,   275,   276,   277,   278,   279,   280,   283,   284,
     285,   286,   287,   288,   289,   292,   293,   294,   297,   298,
     299,   300,   303,   304,   305,   306,   309,   310,   314,   315,
     316,   317,   324,   334,   335,   338,   347,   348,   349,   352,
     353,   356,   357,   360,   363,   364,   365,   366,   367
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
  "compound_statement", "@1", "@2", "block_item_list", "block_item",
  "statement", "print_function", "print_content", "jump_statement",
  "selection_statement", "iteration_statement", "expression_statement",
  "expression", "declaration", "init_declarator", "declarator",
  "direct_declarator", "@3", "@4", "identifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "initializer", "assignment_expression", "assignment_operator",
  "relational_expression", "additive_expression",
  "multiplicative_expression", "unary_expression", "unary_operation",
  "postfix_expression", "argument_expression_list", "primary_expression",
  "boolean", "constant", "string", "type_specifier", 0
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
       0,    51,    52,    52,    53,    53,    54,    56,    55,    57,
      55,    58,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    61,    62,    62,    63,    63,    64,    64,    65,    66,
      66,    67,    67,    68,    69,    69,    70,    71,    72,    71,
      73,    71,    71,    74,    74,    75,    76,    76,    77,    78,
      79,    79,    80,    80,    80,    80,    80,    80,    81,    81,
      81,    81,    81,    81,    81,    82,    82,    82,    83,    83,
      83,    83,    84,    84,    84,    84,    85,    85,    86,    86,
      86,    86,    86,    87,    87,    88,    88,    88,    88,    89,
      89,    90,    90,    91,    92,    92,    92,    92,    92
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     3,     0,     3,     0,
       4,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     1,     1,     2,     3,     5,     7,     5,     1,
       2,     1,     3,     3,     3,     1,     1,     1,     0,     4,
       0,     5,     4,     1,     3,     1,     1,     3,     2,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     2,     2,     1,     1,     1,     2,
       2,     4,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    97,    94,    95,    96,    98,     0,     3,     5,     4,
       0,     1,     2,    37,     0,    35,    36,    33,     0,     9,
       6,    40,    76,    77,     0,     0,    90,    89,    91,    92,
      93,    85,    34,    49,    50,    58,    65,    68,     0,    72,
      78,    88,    86,    87,     0,     0,    43,     0,     0,     0,
      73,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,    55,    56,    57,     0,
      75,    79,    80,     0,     8,     0,     0,     0,    29,     0,
      15,     0,    11,    14,    20,    19,    18,    17,    16,     0,
      13,    31,     0,    39,     0,    45,    46,     0,    42,     0,
      59,    68,    60,    61,    62,    63,    64,    66,    67,    69,
      70,    71,    51,    82,    83,     0,     0,     0,     0,    24,
       0,    10,    12,    30,     0,    35,    41,     0,    48,    44,
      81,     0,    22,    23,     0,     0,     0,    25,    32,    47,
      84,     0,     0,     0,    21,    26,    28,     0,    27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    80,    44,    45,    81,    82,    83,
      84,   134,    85,    86,    87,    88,    89,     9,    14,    15,
      16,    47,    48,    49,    94,    95,    96,    32,    91,    69,
      34,    35,    36,    37,    38,    39,   115,    40,    41,    42,
      43,    10
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -127
static const yytype_int16 yypact[] =
{
     111,  -127,  -127,  -127,  -127,  -127,    11,  -127,  -127,  -127,
     -40,  -127,  -127,  -127,     6,   -14,   -13,  -127,   154,    -8,
    -127,   -25,  -127,  -127,   154,   154,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,    82,    57,    50,   183,   154,    -2,
    -127,  -127,  -127,  -127,    -4,    81,  -127,   -12,   111,   -10,
    -127,  -127,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,  -127,  -127,  -127,  -127,  -127,  -127,   154,
    -127,  -127,  -127,   123,  -127,    -7,     2,     5,  -127,   138,
    -127,    31,  -127,  -127,  -127,  -127,  -127,  -127,  -127,    -6,
    -127,  -127,   -40,  -127,    18,    35,  -127,   -40,  -127,    32,
      57,  -127,    57,    57,    57,    57,    57,    50,    50,  -127,
    -127,  -127,  -127,  -127,  -127,    -9,   -35,   154,   154,  -127,
      -5,  -127,  -127,  -127,   154,    46,  -127,   111,  -127,  -127,
    -127,   154,  -127,  -127,    60,    15,    16,  -127,  -127,  -127,
    -127,    85,   101,   101,  -127,    89,  -127,   101,  -127
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,    91,  -127,    92,  -127,  -127,  -127,    36,  -126,
    -127,  -127,  -127,  -127,  -127,  -127,   -74,   -39,  -127,   -43,
    -127,  -127,  -127,  -127,  -127,  -127,   -15,  -127,   -18,  -127,
    -127,   172,    28,   161,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,   -44
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -39
static const yytype_int16 yytable[] =
{
      33,    92,   123,   137,    97,   120,    90,   -38,    18,   132,
      13,    11,    71,    72,    17,   133,   145,   146,    21,    19,
      93,   148,    98,   130,   116,    46,    -7,    99,   131,    73,
      74,   124,   124,   117,    75,    76,   118,    92,    77,    78,
      22,    23,    90,   135,   136,    24,    25,   142,   143,   125,
     126,   112,   124,   124,   128,   114,     1,     2,     3,     4,
       5,    60,    61,    62,    19,   121,    58,    59,    18,    26,
      27,    79,   127,    28,    29,    30,     1,     2,     3,     4,
       5,    31,   129,    97,    75,    76,   107,   108,    77,    78,
      22,    23,   141,   144,   147,    24,    25,    12,    52,    53,
      54,    55,    56,    57,    75,    76,   138,    20,    77,    78,
      22,    23,   139,   140,    19,    24,    25,   122,     0,    26,
      27,    79,     0,    28,    29,    30,     1,     2,     3,     4,
       5,    31,    22,    23,    19,     0,     0,    24,    25,    26,
      27,    79,     0,    28,    29,    30,   119,    22,    23,     0,
       0,    31,    24,    25,     0,   113,     1,     2,     3,     4,
       5,    26,    27,    22,    23,    28,    29,    30,    24,    25,
       0,     0,     0,    31,     0,     0,    26,    27,     0,     0,
      28,    29,    30,     0,     0,    50,    51,     0,    31,     0,
       0,     0,    26,    27,     0,     0,    28,    29,    30,    70,
       0,     0,     0,     0,    31,    63,    64,    65,    66,    67,
      68,     0,     0,   101,   101,   101,   101,   101,   101,   101,
     101,   109,   110,   111,   100,   102,   103,   104,   105,   106
};

static const yytype_int16 yycheck[] =
{
      18,    45,     8,     8,    48,    79,    45,    32,    22,    44,
      50,     0,    14,    15,     8,    50,   142,   143,    31,    33,
      32,   147,    32,    32,    31,    50,    34,    37,    37,    31,
      34,    37,    37,    31,     3,     4,    31,    81,     7,     8,
       9,    10,    81,   117,   118,    14,    15,    32,    32,    92,
      32,    69,    37,    37,    97,    73,    45,    46,    47,    48,
      49,    11,    12,    13,    33,    34,     9,    10,    22,    38,
      39,    40,    37,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    50,   127,     3,     4,    58,    59,     7,     8,
       9,    10,    32,     8,     5,    14,    15,     6,    16,    17,
      18,    19,    20,    21,     3,     4,   124,    15,     7,     8,
       9,    10,   127,   131,    33,    14,    15,    81,    -1,    38,
      39,    40,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,     9,    10,    33,    -1,    -1,    14,    15,    38,
      39,    40,    -1,    42,    43,    44,     8,     9,    10,    -1,
      -1,    50,    14,    15,    -1,    32,    45,    46,    47,    48,
      49,    38,    39,     9,    10,    42,    43,    44,    14,    15,
      -1,    -1,    -1,    50,    -1,    -1,    38,    39,    -1,    -1,
      42,    43,    44,    -1,    -1,    24,    25,    -1,    50,    -1,
      -1,    -1,    38,    39,    -1,    -1,    42,    43,    44,    38,
      -1,    -1,    -1,    -1,    50,    22,    23,    24,    25,    26,
      27,    -1,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    52,    53,    54,    55,    56,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    46,    47,    48,    49,    52,    53,    54,    68,
      92,     0,    53,    50,    69,    70,    71,     8,    22,    33,
      55,    31,     9,    10,    14,    15,    38,    39,    42,    43,
      44,    50,    78,    79,    81,    82,    83,    84,    85,    86,
      88,    89,    90,    91,    56,    57,    50,    72,    73,    74,
      84,    84,    16,    17,    18,    19,    20,    21,     9,    10,
      11,    12,    13,    22,    23,    24,    25,    26,    27,    80,
      84,    14,    15,    31,    34,     3,     4,     7,     8,    40,
      55,    58,    59,    60,    61,    63,    64,    65,    66,    67,
      68,    79,    92,    32,    75,    76,    77,    92,    32,    37,
      82,    84,    82,    82,    82,    82,    82,    83,    83,    84,
      84,    84,    79,    32,    79,    87,    31,    31,    31,     8,
      67,    34,    59,     8,    37,    70,    32,    37,    70,    50,
      32,    37,    44,    50,    62,    67,    67,     8,    79,    77,
      79,    32,    32,    32,     8,    60,    60,     5,    60
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
#line 100 "compiler_hw2.y"
    {}
    break;

  case 3:
#line 101 "compiler_hw2.y"
    {}
    break;

  case 6:
#line 108 "compiler_hw2.y"
    {
		func_declare_flag = 0;
        if(lookup_symbol((yyvsp[(2) - (3)].id_val),"function") == 0){
            insert_symbol((yyvsp[(2) - (3)].id_val),(yyvsp[(1) - (3)].type_val),"function",attribute_buf);
        }
		strcpy(attribute_buf,"");
	}
    break;

  case 7:
#line 117 "compiler_hw2.y"
    {	if(func_declare_flag == 0){
				scope_flag++;
                create_symbol(scope_flag);
            }
            else{
                func_declare_flag = 0;
			}
	}
    break;

  case 8:
#line 125 "compiler_hw2.y"
    {
		scope_flag--;
		dump_symbol();
	}
    break;

  case 9:
#line 129 "compiler_hw2.y"
    {	if(func_declare_flag == 0){
				scope_flag++;
				create_symbol(scope_flag);
			}
			else{
				func_declare_flag = 0;
			}
	}
    break;

  case 10:
#line 137 "compiler_hw2.y"
    {
		scope_flag--;
		print_sym_flag = 1;
		dump_symbol();
	}
    break;

  case 22:
#line 163 "compiler_hw2.y"
    {}
    break;

  case 23:
#line 164 "compiler_hw2.y"
    {
		if(lookup_symbol((yyvsp[(1) - (1)].id_val),"variable")==0 && lookup_global((yyvsp[(1) - (1)].id_val),"variable")==0){
			print_sym_flag = 2;
			strcat(message_buf,"Undeclared variable ");
			strcat(message_buf,(yyvsp[(1) - (1)].id_val));
		}
	}
    break;

  case 33:
#line 194 "compiler_hw2.y"
    {
		if(func_declare_flag == 1){
			func_declare_flag = 0;
			scope_flag--;
			kill_symbol();
			if(lookup_symbol((yyvsp[(2) - (3)].id_val),"function") == 0 && lookup_global((yyvsp[(2) - (3)].id_val),"function")==0){
				insert_symbol((yyvsp[(2) - (3)].id_val),(yyvsp[(1) - (3)].type_val),"function",attribute_buf);
				strcpy(attribute_buf,"");
			}
			else{
				print_sym_flag = 2;
				strcat(message_buf,"Redeclared function ");
                strcat(message_buf,(yyvsp[(2) - (3)].id_val));
			}
		}
		else{
			if(lookup_symbol((yyvsp[(2) - (3)].id_val),"variable") == 0){
				insert_symbol((yyvsp[(2) - (3)].id_val),(yyvsp[(1) - (3)].type_val),"variable","");
			}
			else{
				print_sym_flag = 2;
				strcat(message_buf,"Redeclared variable ");
				strcat(message_buf,(yyvsp[(2) - (3)].id_val));
			}
        }
	
	}
    break;

  case 34:
#line 224 "compiler_hw2.y"
    {(yyval.id_val)=(yyvsp[(1) - (3)].id_val);}
    break;

  case 35:
#line 225 "compiler_hw2.y"
    {(yyval.id_val)=(yyvsp[(1) - (1)].id_val);}
    break;

  case 36:
#line 228 "compiler_hw2.y"
    {(yyval.id_val)=(yyvsp[(1) - (1)].id_val);}
    break;

  case 37:
#line 231 "compiler_hw2.y"
    {	/*if(lookup_symbol($1) == 0){
				insert_symbol($1);
			}*/
			(yyval.id_val)=(yyvsp[(1) - (1)].id_val);
	}
    break;

  case 38:
#line 236 "compiler_hw2.y"
    {/*func_declare_flag = 1;scope_flag++;create_symbol(scope_flag);*/}
    break;

  case 40:
#line 237 "compiler_hw2.y"
    {func_declare_flag = 1;scope_flag++;create_symbol(scope_flag);}
    break;

  case 46:
#line 248 "compiler_hw2.y"
    {
		strcpy(attribute_buf,(yyvsp[(1) - (1)].type_val));
		strcat(attribute_buf,"\0");
	}
    break;

  case 47:
#line 252 "compiler_hw2.y"
    {
		strcat(attribute_buf,", ");
		strcat(attribute_buf,(yyvsp[(3) - (3)].type_val));
		strcat(attribute_buf,"\0");
	}
    break;

  case 48:
#line 259 "compiler_hw2.y"
    {
		(yyval.type_val)=(yyvsp[(1) - (2)].type_val);
		if(lookup_symbol((yyvsp[(2) - (2)].id_val),"paremeter") == 0){
            insert_symbol((yyvsp[(2) - (2)].id_val),(yyvsp[(1) - (2)].type_val),"parameter","");                                              
        }
	}
    break;

  case 78:
#line 314 "compiler_hw2.y"
    {(yyval.id_val)=(yyvsp[(1) - (1)].id_val);}
    break;

  case 81:
#line 317 "compiler_hw2.y"
    {
		if(lookup_global((yyvsp[(1) - (4)].id_val),"function") != 2){
			print_sym_flag = 2;
			strcat(message_buf,"Undeclared function ");
			strcat(message_buf,(yyvsp[(1) - (4)].id_val));
		}
	}
    break;

  case 82:
#line 324 "compiler_hw2.y"
    {
		if(lookup_global((yyvsp[(1) - (3)].id_val),"function") != 2){
            print_sym_flag = 2;
            strcat(message_buf,"Undeclared function ");
            strcat(message_buf,(yyvsp[(1) - (3)].id_val));
        }

	}
    break;

  case 85:
#line 338 "compiler_hw2.y"
    {
		(yyval.id_val)=(yyvsp[(1) - (1)].id_val);
		if(lookup_global((yyvsp[(1) - (1)].id_val),"variable") == 0 && lookup_symbol((yyvsp[(1) - (1)].id_val),"variable" )==0){
			print_sym_flag = 2;
			strcat(message_buf,"Undeclared Variable ");
			strcat(message_buf,(yyvsp[(1) - (1)].id_val));
		}
	
	}
    break;

  case 94:
#line 363 "compiler_hw2.y"
    { (yyval.type_val) = (yyvsp[(1) - (1)].type_val);}
    break;

  case 95:
#line 364 "compiler_hw2.y"
    { (yyval.type_val) = (yyvsp[(1) - (1)].type_val); }
    break;

  case 96:
#line 365 "compiler_hw2.y"
    { (yyval.type_val) = (yyvsp[(1) - (1)].type_val); }
    break;

  case 97:
#line 366 "compiler_hw2.y"
    { (yyval.type_val) = (yyvsp[(1) - (1)].type_val); }
    break;

  case 98:
#line 367 "compiler_hw2.y"
    { (yyval.type_val) = (yyvsp[(1) - (1)].type_val); }
    break;


/* Line 1267 of yacc.c.  */
#line 1863 "y.tab.c"
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


#line 396 "compiler_hw2.y"


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
	if( print_sym_flag == 2){
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
int lookup_symbol(char* name,char* kind) {
	int i;
	for(i = 0 ; i < Current->var_index ; i++){
		if(strcmp(name,Current->STable[i].name) == 0 && strcmp(kind,"function") ==0&& strcmp(Current->STable[i].kind,"function")==0){
			return 2;
		}
		else if(strcmp(name,Current->STable[i].name) == 0){
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
			else if(strcmp(name,tempnode->STable[i].name) == 0){
				return 1;
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

