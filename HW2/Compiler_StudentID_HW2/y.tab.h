/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 157 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

