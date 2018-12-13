/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_GETDATE_YY_GETDATE_PARSER_H_INCLUDED
# define YY_GETDATE_YY_GETDATE_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int getdate_yydebug;
#endif
/* "%code requires" blocks.  */
#line 48 "getdate-parser.y" /* yacc.c:1910  */

    #include <sys/types.h>
    #include <sys/timeb.h>
    #include "getdate-timezones.h"
    /*
    **  Daylight-savings mode:  on, off, or not yet known.
    */
    typedef enum _DSTMODE {
        DSTon, DSToff, DSTmaybe
    } DSTMODE;

    /*
    **  Meridian:  am, pm, or 24-hour style.
    */
    typedef enum _MERIDIAN {
        MERam, MERpm, MER24
    } MERIDIAN;

    /*
    **  Global variables.  We could get rid of most of these by using a good
    **  union as the yacc stack.  (This routine was originally written before
    **  yacc had the %union construct.)  Maybe someday; right now we only use
    **  the %union very rarely.
    */
     char	*yyInput;
     DSTMODE	yyDSTmode;
     time_t	yyDayOrdinal;
     time_t	yyDayNumber;
     int	yyHaveDate;
     int	yyHaveDay;
     int	yyHaveRel;
     int	yyHaveTime;
     int	yyHaveZone;
     int	yyOrdinal;
     time_t	yyTimezone;
     time_t	yyDay;
     time_t	yyHour;
     time_t	yyMinutes;
     time_t	yyMonth;
     time_t	yySeconds;
     time_t	yyYear;
     MERIDIAN yyMeridian;
     time_t	yyRelMonth;
     time_t	yyRelSeconds;

#line 90 "getdate-parser.h" /* yacc.c:1910  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tAGO = 258,
    tDAY = 259,
    tDAYZONE = 260,
    tID = 261,
    tMERIDIAN = 262,
    tMINUTE_UNIT = 263,
    tMONTH = 264,
    tMONTH_UNIT = 265,
    tSEC_UNIT = 266,
    tSNUMBER = 267,
    tUNUMBER = 268,
    tZONE = 269,
    tDST = 270,
    tORDINAL = 271
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 153 "getdate-parser.y" /* yacc.c:1910  */

    time_t		Number;
    enum _MERIDIAN	Meridian;

#line 124 "getdate-parser.h" /* yacc.c:1910  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int getdate_yyparse (void);
/* "%code provides" blocks.  */
#line 94 "getdate-parser.y" /* yacc.c:1910  */

    int getdate_yylex (YYSTYPE *yylval);
    __attribute__((visibility("default")))
    time_t get_date(char *, struct timeb *);

#line 142 "getdate-parser.h" /* yacc.c:1910  */

#endif /* !YY_GETDATE_YY_GETDATE_PARSER_H_INCLUDED  */
