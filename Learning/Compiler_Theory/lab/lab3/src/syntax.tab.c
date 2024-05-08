/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./syntax.y"

#include <stdio.h>
#include "lex.yy.c"
#include"tree.c"
int yyerror(char* msg);
extern struct Node* root;
extern int yylineno;
extern int LexError;

#line 80 "syntax.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    ID = 260,
    SEMI = 261,
    COMMA = 262,
    ASSIGNOP = 263,
    RELOP = 264,
    PLUS = 265,
    MINUS = 266,
    STAR = 267,
    DIV = 268,
    AND = 269,
    OR = 270,
    DOT = 271,
    NOT = 272,
    TYPE = 273,
    LP = 274,
    RP = 275,
    LB = 276,
    RB = 277,
    LC = 278,
    RC = 279,
    STRUCT = 280,
    RETURN = 281,
    IF = 282,
    ELSE = 283,
    WHILE = 284,
    HIGHER_MINUS = 285,
    LOWER_THAN_ELSE = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "./syntax.y"

    int type_int;
    float type_float;
    double type_double;
    struct Node* node;

#line 171 "syntax.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   406

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

#define YYUNDEFTOK  2
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    61,    65,    67,    71,    75,    79,    84,
      87,    88,    89,    90,    92,    96,   101,   102,   106,   110,
     115,   119,   124,   126,   128,   132,   134,   140,   144,   149,
     150,   152,   156,   161,   162,   163,   165,   169,   173,   176,
     182,   189,   193,   195,   199,   203,   207,   211,   216,   221,
     223,   226,   227,   231,   235,   237,   243,   245,   249,   254,
     258,   265,   269,   273,   277,   281,   285,   289,   293,   297,
     301,   305,   309,   313,   317,   321,   325,   329,   333,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     353,   355,   359,   364
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "ID", "SEMI", "COMMA",
  "ASSIGNOP", "RELOP", "PLUS", "MINUS", "STAR", "DIV", "AND", "OR", "DOT",
  "NOT", "TYPE", "LP", "RP", "LB", "RB", "LC", "RC", "STRUCT", "RETURN",
  "IF", "ELSE", "WHILE", "HIGHER_MINUS", "LOWER_THAN_ELSE", "$accept",
  "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

#define YYPACT_NINF (-70)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,    14,   -70,    13,    29,   -70,    12,   373,   -70,    38,
      50,    61,    53,    75,    81,   -70,   -70,   -70,    45,    50,
     -70,    55,    72,    15,   -70,     7,   111,   -70,   -70,    48,
      54,   -70,   -70,   -70,   164,   140,   -70,   -70,   -70,   100,
     -70,   112,     8,   137,   186,    59,   111,   139,   142,   143,
     -70,   -70,   143,   -70,   136,    25,    49,   150,   -70,   -70,
      49,   158,    93,   166,   179,   174,   -70,   -70,   169,    91,
     134,   151,   248,    52,    56,   -70,   161,    59,   260,   -70,
     -70,   -70,   -70,   -70,   -70,   100,   -70,   -70,   -70,   248,
     -70,   112,   -70,   129,   -70,   126,   -70,   126,   182,   304,
     110,   -70,   248,   -70,   248,   -70,   -70,   -70,   156,   173,
     178,   195,   200,   217,   222,   239,   208,   248,   346,   -70,
     187,   -70,   275,   188,   -70,   -70,   -70,   -70,   318,   332,
     -70,   346,   -70,   379,   -70,   385,   -70,   385,   -70,   126,
     -70,   126,   -70,   372,   -70,   359,   -70,   -70,   289,   244,
     244,   -70,    86,    86,   -70,   -70,   -70,   165,   -70,    86,
     -70
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    18,     0,     0,     2,     0,     0,    19,     0,
       0,     0,     0,    26,     0,    21,     1,     3,    10,    27,
       6,     0,    14,     0,    35,     0,    54,    11,    22,     0,
       0,    12,     9,     5,     0,     0,    13,     8,     7,    33,
      32,     0,     0,    37,     0,     0,    54,     0,     0,     0,
      27,    17,    16,    15,     0,     0,     0,    39,    34,    31,
       0,     0,    59,     0,    57,     0,    77,    78,    76,     0,
       0,     0,     0,     0,     0,    44,     0,     0,     0,    53,
      23,    20,    29,    30,    28,     0,    38,    36,    56,     0,
      55,     0,    49,     0,    88,    70,    89,    71,     0,     0,
       0,    51,     0,    52,     0,    40,    41,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    58,
       0,    73,    92,     0,    87,    69,    50,    45,     0,     0,
      79,    61,    82,    64,    83,    65,    84,    66,    85,    67,
      86,    68,    80,    62,    81,    63,    90,    75,     0,     0,
       0,    72,     0,     0,    74,    93,    91,    46,    48,     0,
      47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,   209,   -70,   201,     5,   -70,   -70,   -70,   -37,
     203,   204,   -70,    -1,   130,   -53,   -23,   -70,   125,   -70,
     -69,   -22
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    21,    41,     8,    14,    15,    22,
      11,    42,    43,    75,    76,    77,    45,    46,    63,    64,
      78,   123
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      95,    97,    99,   100,    57,     7,    48,    62,    39,    58,
      27,     7,    -4,     1,    12,     9,    36,    31,    13,    10,
     118,    37,    38,    79,   122,     2,    83,    40,    59,    16,
       2,    44,     3,   128,    44,   129,   -25,     3,    26,   131,
     133,   135,   137,   139,   141,   143,   145,    84,   148,    47,
      85,    44,    30,   101,    62,    49,    32,   103,    24,    50,
      65,    33,    66,    67,    68,    24,     2,     2,    26,    25,
      69,   102,   -54,     3,     3,   104,    70,    28,    71,    34,
     122,   122,    26,   -42,    26,    72,    73,    65,    74,    66,
      67,    68,    94,    35,    66,    67,    68,    69,   -24,   157,
     158,    89,    69,    70,    29,    71,   160,    56,    70,    26,
      71,   126,    72,    73,    35,    74,   127,    50,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   155,   156,     2,
     120,   117,    66,    67,    68,    96,     3,    66,    67,    68,
      69,    54,   116,    55,    60,    69,    70,   117,    71,   121,
      30,    70,    98,    71,    66,    67,    68,   130,    82,    66,
      67,    68,    69,    80,    88,    52,    81,    69,    70,    50,
      71,    35,    90,    70,   132,    71,    66,    67,    68,   134,
      92,    66,    67,    68,    69,   105,    91,    61,    93,    69,
      70,    50,    71,   159,   149,    70,   136,    71,    66,    67,
      68,   138,   124,    66,    67,    68,    69,   106,   151,   146,
      23,    69,    70,   147,    71,    17,   119,    70,   140,    71,
      66,    67,    68,   142,     0,    66,    67,    68,    69,     0,
       0,    51,     0,    69,    70,    53,    71,     0,     0,    70,
     144,    71,    66,    67,    68,   120,     0,    66,    67,    68,
      69,    66,    67,    68,     0,    69,    70,     0,    71,    69,
      86,    70,     0,    71,    87,    70,   107,    71,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,     0,     0,
       0,   117,   150,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,     0,     0,     0,   117,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
     117,   154,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,     0,     0,   125,   117,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,     0,     0,   152,   117,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     0,
       0,     0,   153,   117,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,     0,     0,     0,   117,   109,   110,
     111,   112,   113,   114,    18,   116,     0,     0,    19,    20,
     117,   109,   110,   111,   112,   113,     0,     0,   116,   110,
     111,   112,   113,   117,     0,   116,     0,   112,   113,     0,
     117,   116,     0,     0,     0,     0,   117
};

static const yytype_int16 yycheck[] =
{
      69,    70,    71,    72,    41,     0,    29,    44,     1,     1,
      11,     6,     0,     1,     1,     1,     1,    18,     5,     5,
      89,     6,    23,    46,    93,    18,     1,    20,    20,     0,
      18,    26,    25,   102,    29,   104,    23,    25,    23,   108,
     109,   110,   111,   112,   113,   114,   115,    22,   117,     1,
       1,    46,     7,     1,    91,     1,     1,     1,    20,     5,
       1,     6,     3,     4,     5,    20,    18,    18,    23,    19,
      11,    19,    24,    25,    25,    19,    17,    24,    19,     7,
     149,   150,    23,    24,    23,    26,    27,     1,    29,     3,
       4,     5,     1,    21,     3,     4,     5,    11,    23,   152,
     153,     8,    11,    17,    23,    19,   159,     7,    17,    23,
      19,     1,    26,    27,    21,    29,     6,     5,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   149,   150,    18,
       1,    21,     3,     4,     5,     1,    25,     3,     4,     5,
      11,     1,    16,     3,     7,    11,    17,    21,    19,    20,
       7,    17,     1,    19,     3,     4,     5,     1,    22,     3,
       4,     5,    11,    24,     6,     1,    24,    11,    17,     5,
      19,    21,     6,    17,     1,    19,     3,     4,     5,     1,
       6,     3,     4,     5,    11,    24,     7,     1,    19,    11,
      17,     5,    19,    28,     7,    17,     1,    19,     3,     4,
       5,     1,    20,     3,     4,     5,    11,    77,    20,     1,
       7,    11,    17,     5,    19,     6,    91,    17,     1,    19,
       3,     4,     5,     1,    -1,     3,     4,     5,    11,    -1,
      -1,    30,    -1,    11,    17,    34,    19,    -1,    -1,    17,
       1,    19,     3,     4,     5,     1,    -1,     3,     4,     5,
      11,     3,     4,     5,    -1,    11,    17,    -1,    19,    11,
      56,    17,    -1,    19,    60,    17,     6,    19,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    21,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    21,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      21,    22,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    20,    21,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    20,    21,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    20,    21,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    21,     9,    10,
      11,    12,    13,    14,     1,    16,    -1,    -1,     5,     6,
      21,     9,    10,    11,    12,    13,    -1,    -1,    16,    10,
      11,    12,    13,    21,    -1,    16,    -1,    12,    13,    -1,
      21,    16,    -1,    -1,    -1,    -1,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    18,    25,    33,    34,    35,    37,    38,     1,
       5,    42,     1,     5,    39,    40,     0,    34,     1,     5,
       6,    36,    41,    42,    20,    19,    23,    45,    24,    23,
       7,    45,     1,     6,     7,    21,     1,     6,    45,     1,
      20,    37,    43,    44,    37,    48,    49,     1,    48,     1,
       5,    36,     1,    36,     1,     3,     7,    41,     1,    20,
       7,     1,    41,    50,    51,     1,     3,     4,     5,    11,
      17,    19,    26,    27,    29,    45,    46,    47,    52,    48,
      24,    24,    22,     1,    22,     1,    43,    43,     6,     8,
       6,     7,     6,    19,     1,    52,     1,    52,     1,    52,
      52,     1,    19,     1,    19,    24,    46,     6,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    21,    52,    50,
       1,    20,    52,    53,    20,    20,     1,     6,    52,    52,
       1,    52,     1,    52,     1,    52,     1,    52,     1,    52,
       1,    52,     1,    52,     1,    52,     1,     5,    52,     7,
       7,    20,    20,    20,    22,    53,    53,    47,    47,    28,
      47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    36,    36,    36,    36,    37,    37,
      38,    38,    38,    38,    39,    39,    40,    41,    41,    41,
      41,    42,    42,    42,    42,    42,    43,    43,    43,    44,
      45,    46,    46,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    53,    53,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     3,     3,
       2,     3,     3,     3,     1,     3,     3,     3,     1,     1,
       5,     2,     3,     5,     1,     0,     1,     1,     4,     4,
       4,     4,     3,     3,     4,     2,     3,     1,     3,     2,
       4,     2,     0,     2,     1,     3,     5,     7,     5,     2,
       3,     2,     2,     2,     0,     3,     3,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     4,     3,     4,     3,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     3,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 56 "./syntax.y"
                    {
        root=init("Program",(yyloc).first_line,0);
        (yyval.node)=root;
        insert((yyval.node),(yyvsp[0].node));
    }
#line 1620 "syntax.tab.c"
    break;

  case 3:
#line 61 "./syntax.y"
                              {
        (yyval.node)=init("ExtDefList",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1629 "syntax.tab.c"
    break;

  case 4:
#line 65 "./syntax.y"
                 {(yyval.node)=NULL;}
#line 1635 "syntax.tab.c"
    break;

  case 5:
#line 67 "./syntax.y"
                                  {
        (yyval.node)=init("ExtDef",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1644 "syntax.tab.c"
    break;

  case 6:
#line 71 "./syntax.y"
                    {
        (yyval.node)=init("ExtDef",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1653 "syntax.tab.c"
    break;

  case 7:
#line 75 "./syntax.y"
                             {
        (yyval.node)=init("ExtDef",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1662 "syntax.tab.c"
    break;

  case 8:
#line 79 "./syntax.y"
                           {
        (yyval.node)=init("ExtDef",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1671 "syntax.tab.c"
    break;

  case 9:
#line 84 "./syntax.y"
                               {printf("Error type B at Line %d: Specifier ExtDecList error.\n",(yylsp[0]).first_line);}
#line 1677 "syntax.tab.c"
    break;

  case 10:
#line 87 "./syntax.y"
                    {printf("Error type B at Line %d: Specifier error.\n",(yylsp[0]).first_line);}
#line 1683 "syntax.tab.c"
    break;

  case 11:
#line 88 "./syntax.y"
                        {printf("Error type B at Line %d: error FunDec CompSt.\n",(yylsp[-2]).first_line);}
#line 1689 "syntax.tab.c"
    break;

  case 12:
#line 89 "./syntax.y"
                           {printf("Error type B at Line %d: Specifier error CompSt.\n",(yylsp[-1]).first_line);}
#line 1695 "syntax.tab.c"
    break;

  case 13:
#line 90 "./syntax.y"
                           {printf("Error type B at Line %d: Specifier FunDec error.\n",(yylsp[0]).first_line);}
#line 1701 "syntax.tab.c"
    break;

  case 14:
#line 92 "./syntax.y"
                   {
        (yyval.node)=init("ExtDecList",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[0].node));
    }
#line 1710 "syntax.tab.c"
    break;

  case 15:
#line 96 "./syntax.y"
                             {
        (yyval.node)=init("ExtDecList",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1719 "syntax.tab.c"
    break;

  case 16:
#line 101 "./syntax.y"
                       {printf("Error type B at Line %d: VarDec COMMA error.\n",(yylsp[0]).first_line);}
#line 1725 "syntax.tab.c"
    break;

  case 17:
#line 102 "./syntax.y"
                           {printf("Error type B at Line %d: error COMMA ExtDecList.\n",(yylsp[-2]).first_line);}
#line 1731 "syntax.tab.c"
    break;

  case 18:
#line 106 "./syntax.y"
                 {
        (yyval.node)=init("Specifier",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[0].node));
    }
#line 1740 "syntax.tab.c"
    break;

  case 19:
#line 110 "./syntax.y"
                      {
        (yyval.node)=init("Specifier",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[0].node));
    }
#line 1749 "syntax.tab.c"
    break;

  case 20:
#line 115 "./syntax.y"
                                             {
        (yyval.node)=init("StructSpecifier",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-4].node));insert((yyval.node),(yyvsp[-3].node));insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1758 "syntax.tab.c"
    break;

  case 21:
#line 119 "./syntax.y"
                {
        (yyval.node)=init("StructSpecifier",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1767 "syntax.tab.c"
    break;

  case 22:
#line 124 "./syntax.y"
                    {printf("Error type B at Line %d: STRUCT error RC.\n",(yylsp[-1]).first_line);}
#line 1773 "syntax.tab.c"
    break;

  case 23:
#line 126 "./syntax.y"
                              {printf("Error type B at Line %d: STRUCT OptTag LC error RC.\n",(yylsp[-1]).first_line);}
#line 1779 "syntax.tab.c"
    break;

  case 24:
#line 128 "./syntax.y"
            {
        (yyval.node)=init("OptTag",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[0].node));
    }
#line 1788 "syntax.tab.c"
    break;

  case 25:
#line 132 "./syntax.y"
                 {(yyval.node)=NULL;}
#line 1794 "syntax.tab.c"
    break;

  case 26:
#line 134 "./syntax.y"
         {
        (yyval.node)=init("Tag",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[0].node));
    }
#line 1803 "syntax.tab.c"
    break;

  case 27:
#line 140 "./syntax.y"
           {
        (yyval.node)=init("VarDec",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[0].node));
    }
#line 1812 "syntax.tab.c"
    break;

  case 28:
#line 144 "./syntax.y"
                      {
        (yyval.node)=init("VarDec",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-3].node));insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1821 "syntax.tab.c"
    break;

  case 29:
#line 149 "./syntax.y"
                       {printf("Error type B at Line %d: VarDec LB error RB.\n",(yylsp[-1]).first_line);}
#line 1827 "syntax.tab.c"
    break;

  case 30:
#line 150 "./syntax.y"
                        {printf("Error type B at Line %d: VarDec LB INT error.\n",(yylsp[0]).first_line);}
#line 1833 "syntax.tab.c"
    break;

  case 31:
#line 152 "./syntax.y"
                         {
        (yyval.node)=init("FunDec",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-3].node));insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1842 "syntax.tab.c"
    break;

  case 32:
#line 156 "./syntax.y"
               {
        (yyval.node)=init("FunDec",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1851 "syntax.tab.c"
    break;

  case 33:
#line 161 "./syntax.y"
                {printf("Error type B at Line %d: ID LP error.\n",(yylsp[0]).first_line);}
#line 1857 "syntax.tab.c"
    break;

  case 34:
#line 162 "./syntax.y"
                        {printf("Error type B at Line %d: ID LP VarList error.\n",(yylsp[0]).first_line);}
#line 1863 "syntax.tab.c"
    break;

  case 35:
#line 163 "./syntax.y"
             {printf("Error type B at Line %d: error RP.\n",(yylsp[-1]).first_line);}
#line 1869 "syntax.tab.c"
    break;

  case 36:
#line 165 "./syntax.y"
                                {
        (yyval.node)=init("VarList",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1878 "syntax.tab.c"
    break;

  case 37:
#line 169 "./syntax.y"
              {
        (yyval.node)=init("VarList",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[0].node));
    }
#line 1887 "syntax.tab.c"
    break;

  case 38:
#line 173 "./syntax.y"
                        {printf("Error type B at Line %d: error COMMA VarList.\n",(yylsp[-2]).first_line);}
#line 1893 "syntax.tab.c"
    break;

  case 39:
#line 176 "./syntax.y"
                           {
        (yyval.node)=init("ParamDec",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1902 "syntax.tab.c"
    break;

  case 40:
#line 182 "./syntax.y"
                               {
        (yyval.node)=init("CompSt",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-3].node));insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1911 "syntax.tab.c"
    break;

  case 41:
#line 189 "./syntax.y"
                         {
        (yyval.node)=init("StmtList",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1920 "syntax.tab.c"
    break;

  case 42:
#line 193 "./syntax.y"
                 {(yyval.node)=NULL;}
#line 1926 "syntax.tab.c"
    break;

  case 43:
#line 195 "./syntax.y"
               {
        (yyval.node)=init("Stmt",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1935 "syntax.tab.c"
    break;

  case 44:
#line 199 "./syntax.y"
            {
        (yyval.node)=init("Stmt",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[0].node));
    }
#line 1944 "syntax.tab.c"
    break;

  case 45:
#line 203 "./syntax.y"
                     {
        (yyval.node)=init("Stmt",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1953 "syntax.tab.c"
    break;

  case 46:
#line 207 "./syntax.y"
                                             {
        (yyval.node)=init("Stmt",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-4].node));insert((yyval.node),(yyvsp[-3].node));insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1962 "syntax.tab.c"
    break;

  case 47:
#line 211 "./syntax.y"
                                 {
        (yyval.node)=init("Stmt",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-6].node));insert((yyval.node),(yyvsp[-5].node));insert((yyval.node),(yyvsp[-4].node));insert((yyval.node),(yyvsp[-3].node));
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1972 "syntax.tab.c"
    break;

  case 48:
#line 216 "./syntax.y"
                          {
        (yyval.node)=init("Stmt",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-4].node));insert((yyval.node),(yyvsp[-3].node));insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 1981 "syntax.tab.c"
    break;

  case 49:
#line 221 "./syntax.y"
               {printf("Error type B at Line %d: error SEMI.\n",(yylsp[-1]).first_line);}
#line 1987 "syntax.tab.c"
    break;

  case 50:
#line 223 "./syntax.y"
                     {printf("Error type B at Line %d: RETURN Exp error.\n",(yylsp[0]).first_line);}
#line 1993 "syntax.tab.c"
    break;

  case 51:
#line 226 "./syntax.y"
             {printf("Error type B at Line %d: IF error.\n",(yylsp[0]).first_line);}
#line 1999 "syntax.tab.c"
    break;

  case 52:
#line 227 "./syntax.y"
                {printf("Error type B at Line %d: WHILE error.\n",(yylsp[0]).first_line);}
#line 2005 "syntax.tab.c"
    break;

  case 53:
#line 231 "./syntax.y"
                     {
        (yyval.node)=init("DefList",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2014 "syntax.tab.c"
    break;

  case 54:
#line 235 "./syntax.y"
                 {(yyval.node)=NULL;}
#line 2020 "syntax.tab.c"
    break;

  case 55:
#line 237 "./syntax.y"
                            {
        (yyval.node)=init("Def",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2029 "syntax.tab.c"
    break;

  case 56:
#line 243 "./syntax.y"
                         {printf("Error type B at Line %d: Specifier error SEMI.\n",(yylsp[-1]).first_line);}
#line 2035 "syntax.tab.c"
    break;

  case 57:
#line 245 "./syntax.y"
             {
        (yyval.node)=init("DecList",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[0].node));
    }
#line 2044 "syntax.tab.c"
    break;

  case 58:
#line 249 "./syntax.y"
                       {
        (yyval.node)=init("DecList",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2053 "syntax.tab.c"
    break;

  case 59:
#line 254 "./syntax.y"
            {
        (yyval.node)=init("Dec",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[0].node));
    }
#line 2062 "syntax.tab.c"
    break;

  case 60:
#line 258 "./syntax.y"
                         {
        (yyval.node)=init("Dec",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2071 "syntax.tab.c"
    break;

  case 61:
#line 265 "./syntax.y"
                      {
        (yyval.node)=init("Exp",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2080 "syntax.tab.c"
    break;

  case 62:
#line 269 "./syntax.y"
                 {
        (yyval.node)=init("Exp",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2089 "syntax.tab.c"
    break;

  case 63:
#line 273 "./syntax.y"
                {
        (yyval.node)=init("Exp",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2098 "syntax.tab.c"
    break;

  case 64:
#line 277 "./syntax.y"
                   {
        (yyval.node)=init("Exp",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2107 "syntax.tab.c"
    break;

  case 65:
#line 281 "./syntax.y"
                  {
        (yyval.node)=init("Exp",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2116 "syntax.tab.c"
    break;

  case 66:
#line 285 "./syntax.y"
                   {
        (yyval.node)=init("Exp",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2125 "syntax.tab.c"
    break;

  case 67:
#line 289 "./syntax.y"
                  {
        (yyval.node)=init("Exp",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2134 "syntax.tab.c"
    break;

  case 68:
#line 293 "./syntax.y"
                 {
        (yyval.node)=init("Exp",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2143 "syntax.tab.c"
    break;

  case 69:
#line 297 "./syntax.y"
               {
        (yyval.node)=init("Exp",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2152 "syntax.tab.c"
    break;

  case 70:
#line 301 "./syntax.y"
                                  {
        (yyval.node)=init("Exp",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2161 "syntax.tab.c"
    break;

  case 71:
#line 305 "./syntax.y"
             {
        (yyval.node)=init("Exp",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2170 "syntax.tab.c"
    break;

  case 72:
#line 309 "./syntax.y"
                   {
        (yyval.node)=init("Exp",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-3].node));insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2179 "syntax.tab.c"
    break;

  case 73:
#line 313 "./syntax.y"
              {
        (yyval.node)=init("Exp",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2188 "syntax.tab.c"
    break;

  case 74:
#line 317 "./syntax.y"
                   {
        (yyval.node)=init("Exp",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-3].node));insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2197 "syntax.tab.c"
    break;

  case 75:
#line 321 "./syntax.y"
                {
        (yyval.node)=init("Exp",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2206 "syntax.tab.c"
    break;

  case 76:
#line 325 "./syntax.y"
        {
        (yyval.node)=init("Exp",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[0].node));
    }
#line 2215 "syntax.tab.c"
    break;

  case 77:
#line 329 "./syntax.y"
         {
        (yyval.node)=init("Exp",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[0].node));
    }
#line 2224 "syntax.tab.c"
    break;

  case 78:
#line 333 "./syntax.y"
           {
        (yyval.node)=init("Exp",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[0].node));
    }
#line 2233 "syntax.tab.c"
    break;

  case 79:
#line 338 "./syntax.y"
                       {printf("Error type B at Line %d: Exp ASSIGNOP error.\n",(yylsp[0]).first_line);}
#line 2239 "syntax.tab.c"
    break;

  case 80:
#line 339 "./syntax.y"
                  {printf("Error type B at Line %d: Exp AND error.\n",(yylsp[0]).first_line);}
#line 2245 "syntax.tab.c"
    break;

  case 81:
#line 340 "./syntax.y"
                 {printf("Error type B at Line %d: Exp OR error.\n",(yylsp[0]).first_line);}
#line 2251 "syntax.tab.c"
    break;

  case 82:
#line 341 "./syntax.y"
                    {printf("Error type B at Line %d: Exp RELOP error.\n",(yylsp[0]).first_line);}
#line 2257 "syntax.tab.c"
    break;

  case 83:
#line 342 "./syntax.y"
                   {printf("Error type B at Line %d: Exp PLUS error.\n",(yylsp[0]).first_line);}
#line 2263 "syntax.tab.c"
    break;

  case 84:
#line 343 "./syntax.y"
                    {printf("Error type B at Line %d: Exp MINUS error.\n",(yylsp[0]).first_line);}
#line 2269 "syntax.tab.c"
    break;

  case 85:
#line 344 "./syntax.y"
                   {printf("Error type B at Line %d: Exp STAR error.\n",(yylsp[0]).first_line);}
#line 2275 "syntax.tab.c"
    break;

  case 86:
#line 345 "./syntax.y"
                  {printf("Error type B at Line %d: Exp DIV error.\n",(yylsp[0]).first_line);}
#line 2281 "syntax.tab.c"
    break;

  case 87:
#line 346 "./syntax.y"
                {printf("Error type B at Line %d: LP error RP.\n",(yylsp[-1]).first_line);}
#line 2287 "syntax.tab.c"
    break;

  case 88:
#line 347 "./syntax.y"
                                   {printf("Error type B at Line %d: MINUS error.\n",(yylsp[0]).first_line);}
#line 2293 "syntax.tab.c"
    break;

  case 89:
#line 348 "./syntax.y"
              {printf("Error type B at Line %d: NOT error.\n",(yylsp[0]).first_line);}
#line 2299 "syntax.tab.c"
    break;

  case 90:
#line 353 "./syntax.y"
                  {printf("Error type B at Line %d: Exp DOT error.\n",(yylsp[0]).first_line);}
#line 2305 "syntax.tab.c"
    break;

  case 91:
#line 355 "./syntax.y"
                     {
        (yyval.node)=init("Args",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[-2].node));insert((yyval.node),(yyvsp[-1].node));insert((yyval.node),(yyvsp[0].node));
    }
#line 2314 "syntax.tab.c"
    break;

  case 92:
#line 359 "./syntax.y"
         {
        (yyval.node)=init("Args",(yyloc).first_line,0);
        insert((yyval.node),(yyvsp[0].node));
    }
#line 2323 "syntax.tab.c"
    break;

  case 93:
#line 364 "./syntax.y"
                     {printf("Error type B at Line %d: syntax error.\n",(yylsp[-2]).first_line);}
#line 2329 "syntax.tab.c"
    break;


#line 2333 "syntax.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
  return yyresult;
}
#line 368 "./syntax.y"

int yyerror(char*msg){
    LexError_NUM+=1;
}
