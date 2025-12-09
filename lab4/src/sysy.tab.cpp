/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "src/sysy.y"


#include <iostream>
#include <memory>
#include <string>
#include "AST.hpp"

// 声明 lexer 函数和错误处理函数
int yylex();
void yyerror(std::unique_ptr<BaseAST> &ast, const char *s);

// Flex 提供的当前行号（在 sysy.l 中启用了 %option yylineno）
extern int yylineno;
// 当前触发错误附近的词法单元文本，由 Flex 提供
extern char *yytext;

using namespace std;


#line 91 "src/sysy.tab.cpp"

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

#include "sysy.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CONST = 3,                      /* CONST  */
  YYSYMBOL_VOID = 4,                       /* VOID  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_RETURN = 7,                     /* RETURN  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_BREAK = 11,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 12,                  /* CONTINUE  */
  YYSYMBOL_IDENT = 13,                     /* IDENT  */
  YYSYMBOL_INT_CONST = 14,                 /* INT_CONST  */
  YYSYMBOL_FLOAT_CONST = 15,               /* FLOAT_CONST  */
  YYSYMBOL_AND = 16,                       /* AND  */
  YYSYMBOL_OR = 17,                        /* OR  */
  YYSYMBOL_EQ = 18,                        /* EQ  */
  YYSYMBOL_NE = 19,                        /* NE  */
  YYSYMBOL_LE = 20,                        /* LE  */
  YYSYMBOL_GE = 21,                        /* GE  */
  YYSYMBOL_22_ = 22,                       /* '<'  */
  YYSYMBOL_23_ = 23,                       /* '>'  */
  YYSYMBOL_24_ = 24,                       /* '+'  */
  YYSYMBOL_25_ = 25,                       /* '-'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_28_ = 28,                       /* '%'  */
  YYSYMBOL_29_ = 29,                       /* '!'  */
  YYSYMBOL_UPLUS = 30,                     /* UPLUS  */
  YYSYMBOL_UMINUS = 31,                    /* UMINUS  */
  YYSYMBOL_32_ = 32,                       /* ';'  */
  YYSYMBOL_33_ = 33,                       /* ','  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_35_ = 35,                       /* '['  */
  YYSYMBOL_36_ = 36,                       /* ']'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_CompUnit = 42,                  /* CompUnit  */
  YYSYMBOL_CompUnitItems = 43,             /* CompUnitItems  */
  YYSYMBOL_CompUnitItem = 44,              /* CompUnitItem  */
  YYSYMBOL_BType = 45,                     /* BType  */
  YYSYMBOL_Decl = 46,                      /* Decl  */
  YYSYMBOL_ConstDecl = 47,                 /* ConstDecl  */
  YYSYMBOL_ConstDefList = 48,              /* ConstDefList  */
  YYSYMBOL_ConstDef = 49,                  /* ConstDef  */
  YYSYMBOL_ConstArrayDimsOpt = 50,         /* ConstArrayDimsOpt  */
  YYSYMBOL_ConstInitVal = 51,              /* ConstInitVal  */
  YYSYMBOL_ConstInitValListOpt = 52,       /* ConstInitValListOpt  */
  YYSYMBOL_ConstInitValList = 53,          /* ConstInitValList  */
  YYSYMBOL_ConstExp = 54,                  /* ConstExp  */
  YYSYMBOL_VarDecl = 55,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 56,                /* VarDefList  */
  YYSYMBOL_VarDef = 57,                    /* VarDef  */
  YYSYMBOL_VarArrayDimsOpt = 58,           /* VarArrayDimsOpt  */
  YYSYMBOL_InitVal = 59,                   /* InitVal  */
  YYSYMBOL_InitValListOpt = 60,            /* InitValListOpt  */
  YYSYMBOL_InitValList = 61,               /* InitValList  */
  YYSYMBOL_FuncDef = 62,                   /* FuncDef  */
  YYSYMBOL_FuncFParamsOpt = 63,            /* FuncFParamsOpt  */
  YYSYMBOL_FuncFParams = 64,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 65,                /* FuncFParam  */
  YYSYMBOL_FuncFParamArrayDims = 66,       /* FuncFParamArrayDims  */
  YYSYMBOL_Block = 67,                     /* Block  */
  YYSYMBOL_BlockItemsOpt = 68,             /* BlockItemsOpt  */
  YYSYMBOL_BlockItems = 69,                /* BlockItems  */
  YYSYMBOL_BlockItem = 70,                 /* BlockItem  */
  YYSYMBOL_Stmt = 71,                      /* Stmt  */
  YYSYMBOL_LVal = 72,                      /* LVal  */
  YYSYMBOL_LValArrayDims = 73,             /* LValArrayDims  */
  YYSYMBOL_Exp = 74,                       /* Exp  */
  YYSYMBOL_Cond = 75,                      /* Cond  */
  YYSYMBOL_LOrExp = 76,                    /* LOrExp  */
  YYSYMBOL_LAndExp = 77,                   /* LAndExp  */
  YYSYMBOL_EqExp = 78,                     /* EqExp  */
  YYSYMBOL_RelExp = 79,                    /* RelExp  */
  YYSYMBOL_AddExp = 80,                    /* AddExp  */
  YYSYMBOL_MulExp = 81,                    /* MulExp  */
  YYSYMBOL_UnaryExp = 82,                  /* UnaryExp  */
  YYSYMBOL_FuncRParamsOpt = 83,            /* FuncRParamsOpt  */
  YYSYMBOL_FuncRParams = 84,               /* FuncRParams  */
  YYSYMBOL_PrimaryExp = 85,                /* PrimaryExp  */
  YYSYMBOL_Number = 86                     /* Number  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,     2,     2,    28,     2,     2,
      39,    40,    26,    24,    33,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    32,
      22,    34,    23,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    76,    76,    82,    87,    95,    96,   102,   103,   107,
     108,   112,   118,   119,   123,   127,   128,   132,   133,   137,
     138,   142,   143,   147,   151,   157,   158,   162,   163,   167,
     168,   172,   173,   177,   178,   182,   183,   190,   197,   207,
     208,   212,   213,   217,   220,   226,   227,   232,   242,   243,
     247,   252,   260,   261,   266,   272,   277,   280,   283,   289,
     296,   302,   305,   308,   313,   320,   325,   334,   335,   340,
     344,   348,   349,   358,   359,   368,   369,   375,   384,   385,
     391,   397,   403,   412,   413,   419,   428,   429,   435,   441,
     450,   451,   456,   461,   466,   478,   479,   483,   488,   496,
     497,   498,   502,   506
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CONST", "VOID", "INT",
  "FLOAT", "RETURN", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "IDENT",
  "INT_CONST", "FLOAT_CONST", "AND", "OR", "EQ", "NE", "LE", "GE", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UPLUS", "UMINUS",
  "';'", "','", "'='", "'['", "']'", "'{'", "'}'", "'('", "')'", "$accept",
  "CompUnit", "CompUnitItems", "CompUnitItem", "BType", "Decl",
  "ConstDecl", "ConstDefList", "ConstDef", "ConstArrayDimsOpt",
  "ConstInitVal", "ConstInitValListOpt", "ConstInitValList", "ConstExp",
  "VarDecl", "VarDefList", "VarDef", "VarArrayDimsOpt", "InitVal",
  "InitValListOpt", "InitValList", "FuncDef", "FuncFParamsOpt",
  "FuncFParams", "FuncFParam", "FuncFParamArrayDims", "Block",
  "BlockItemsOpt", "BlockItems", "BlockItem", "Stmt", "LVal",
  "LValArrayDims", "Exp", "Cond", "LOrExp", "LAndExp", "EqExp", "RelExp",
  "AddExp", "MulExp", "UnaryExp", "FuncRParamsOpt", "FuncRParams",
  "PrimaryExp", "Number", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-159)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      65,    58,     1,  -159,  -159,    25,    65,  -159,    23,  -159,
    -159,  -159,  -159,    26,     3,  -159,  -159,     8,    74,  -159,
    -159,    98,  -159,    58,    58,    56,  -159,    36,   100,  -159,
      26,    41,    17,    32,  -159,    27,    37,    84,  -159,  -159,
     124,    84,  -159,    40,    43,    58,    43,    -1,  -159,  -159,
      84,    84,    84,    37,    84,  -159,  -159,  -159,    78,    86,
     132,   134,   135,   118,  -159,  -159,  -159,    68,   124,  -159,
    -159,    88,  -159,    84,    85,    16,  -159,  -159,  -159,    84,
      84,    87,  -159,  -159,  -159,  -159,    89,    99,   102,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,  -159,  -159,   109,   107,  -159,   116,    84,    64,
     119,   123,   138,   139,  -159,    36,  -159,  -159,   136,    16,
    -159,  -159,   141,   140,   137,  -159,   142,   143,    84,  -159,
      37,  -159,    86,   132,   134,   134,   135,   135,   135,   135,
     118,   118,  -159,  -159,  -159,  -159,   124,  -159,   144,  -159,
     145,    84,    84,  -159,  -159,  -159,  -159,    84,  -159,  -159,
    -159,    84,   147,  -159,  -159,  -159,  -159,   146,    78,   148,
     149,  -159,  -159,   104,   104,  -159,   169,  -159,   104,  -159
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     7,     8,     0,     2,     3,     0,     5,
       9,    10,     6,     0,     0,     1,     4,    29,     0,    25,
      15,     0,    12,    39,    39,    27,    24,     0,     0,    11,
       0,     0,     0,    40,    41,     0,     0,     0,    29,    26,
       0,     0,    13,    43,     0,     0,     0,    65,   102,   103,
       0,     0,     0,    33,     0,    28,   100,    31,    69,    71,
      73,    75,    78,    83,    86,    90,   101,     0,    19,    14,
      17,     0,    23,     0,    44,    48,    37,    42,    38,     0,
      95,    66,    91,    92,    93,    35,     0,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,    21,     0,    20,    16,     0,     0,     0,
       0,     0,     0,     0,    56,     0,    52,    57,     0,    49,
      50,    53,   100,     0,     0,    97,     0,    96,     0,    32,
       0,    99,    72,    74,    76,    77,    81,    82,    79,    80,
      84,    85,    87,    88,    89,    18,     0,    45,     0,    64,
       0,     0,     0,    61,    62,    47,    51,     0,    55,    67,
      94,     0,     0,    36,    22,    46,    63,     0,    70,     0,
       0,    98,    68,     0,     0,    54,    58,    60,     0,    59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,  -159,   173,     7,   -63,  -159,  -159,   154,  -159,
     -65,  -159,  -159,  -159,  -159,  -159,   158,  -159,   -47,  -159,
    -159,  -159,   163,  -159,   150,  -159,   -11,  -159,  -159,    70,
    -158,   -73,  -159,   -36,    38,    13,   103,   101,    75,    -9,
      71,   -41,  -159,  -159,  -159,  -159
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,    31,     9,    10,    21,    22,    28,
      69,   104,   105,    71,    11,    18,    19,    25,    55,    86,
      87,    12,    32,    33,    34,    74,   117,   118,   119,   120,
     121,    56,    81,   123,   167,    58,    59,    60,    61,    62,
      63,    64,   126,   127,    65,    66
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    67,   122,   103,    70,    72,    85,     8,    13,    82,
      83,    84,   116,     8,    14,   176,   177,    57,    88,     1,
     179,     3,     4,   109,   110,    15,   111,   112,   113,    47,
      48,    49,    70,    76,    79,    78,    17,   107,    80,    20,
      50,    51,    23,   124,   125,    52,   122,    24,   114,    38,
      47,    48,    49,    75,    43,    54,   116,    44,   142,   143,
     144,    50,    51,     3,     4,    45,    52,    46,     1,     2,
       3,     4,   148,   150,    53,    73,    54,    47,    48,    49,
      75,   164,   115,   163,   136,   137,   138,   139,    50,    51,
      36,    37,   162,    52,    57,    89,   149,    47,    48,    49,
     122,   122,    90,    54,   102,   122,    26,    27,    50,    51,
      70,   109,   110,    52,   111,   112,   113,    47,    48,    49,
     108,   170,   128,    54,   106,   171,   115,   129,    50,    51,
      29,    30,   130,    52,    40,    41,   114,    47,    48,    49,
     146,    75,   131,    54,    99,   100,   101,   145,    50,    51,
      91,    92,   147,    52,    93,    94,    95,    96,   151,    97,
      98,    68,   152,    54,   168,   168,   134,   135,   140,   141,
     153,   154,   158,   159,   155,   157,   161,   166,   178,    16,
     165,   175,   160,   172,    42,    39,   173,    35,   174,   156,
     169,   133,   132,     0,     0,    77
};

static const yytype_int16 yycheck[] =
{
      36,    37,    75,    68,    40,    41,    53,     0,     1,    50,
      51,    52,    75,     6,    13,   173,   174,    53,    54,     3,
     178,     5,     6,     7,     8,     0,    10,    11,    12,    13,
      14,    15,    68,    44,    35,    46,    13,    73,    39,    13,
      24,    25,    39,    79,    80,    29,   119,    39,    32,    13,
      13,    14,    15,    37,    13,    39,   119,    40,    99,   100,
     101,    24,    25,     5,     6,    33,    29,    40,     3,     4,
       5,     6,   108,   109,    37,    35,    39,    13,    14,    15,
      37,   146,    75,   130,    93,    94,    95,    96,    24,    25,
      34,    35,   128,    29,   130,    17,    32,    13,    14,    15,
     173,   174,    16,    39,    36,   178,    32,    33,    24,    25,
     146,     7,     8,    29,    10,    11,    12,    13,    14,    15,
      35,   157,    35,    39,    36,   161,   119,    38,    24,    25,
      32,    33,    33,    29,    34,    35,    32,    13,    14,    15,
      33,    37,    40,    39,    26,    27,    28,    38,    24,    25,
      18,    19,    36,    29,    20,    21,    22,    23,    39,    24,
      25,    37,    39,    39,   151,   152,    91,    92,    97,    98,
      32,    32,    32,    36,    38,    34,    33,    32,     9,     6,
      36,    32,    40,    36,    30,    27,    40,    24,    40,   119,
     152,    90,    89,    -1,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    42,    43,    44,    45,    46,
      47,    55,    62,    45,    13,     0,    44,    13,    56,    57,
      13,    48,    49,    39,    39,    58,    32,    33,    50,    32,
      33,    45,    63,    64,    65,    63,    34,    35,    13,    57,
      34,    35,    49,    13,    40,    33,    40,    13,    14,    15,
      24,    25,    29,    37,    39,    59,    72,    74,    76,    77,
      78,    79,    80,    81,    82,    85,    86,    74,    37,    51,
      74,    54,    74,    35,    66,    37,    67,    65,    67,    35,
      39,    73,    82,    82,    82,    59,    60,    61,    74,    17,
      16,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    36,    51,    52,    53,    36,    74,    35,     7,
       8,    10,    11,    12,    32,    45,    46,    67,    68,    69,
      70,    71,    72,    74,    74,    74,    83,    84,    35,    38,
      33,    40,    77,    78,    79,    79,    80,    80,    80,    80,
      81,    81,    82,    82,    82,    38,    33,    36,    74,    32,
      74,    39,    39,    32,    32,    38,    70,    34,    32,    36,
      40,    33,    74,    59,    51,    36,    32,    75,    76,    75,
      74,    74,    36,    40,    40,    32,    71,    71,     9,    71
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    45,    45,    46,
      46,    47,    48,    48,    49,    50,    50,    51,    51,    52,
      52,    53,    53,    54,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    72,    72,    73,    73,    74,
      75,    76,    76,    77,    77,    78,    78,    78,    79,    79,
      79,    79,    79,    80,    80,    80,    81,    81,    81,    81,
      82,    82,    82,    82,    82,    83,    83,    84,    84,    85,
      85,    85,    86,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     4,     0,     4,     1,     3,     0,
       1,     1,     3,     1,     3,     1,     3,     2,     4,     0,
       4,     1,     3,     0,     1,     1,     3,     6,     6,     0,
       1,     1,     3,     2,     3,     3,     4,     3,     0,     1,
       1,     2,     1,     1,     4,     2,     1,     1,     5,     7,
       5,     2,     2,     3,     2,     1,     2,     3,     4,     1,
       1,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     2,     2,     4,     0,     1,     1,     3,     3,
       1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
        yyerror (ast, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, ast); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::unique_ptr<BaseAST> &ast)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (ast);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::unique_ptr<BaseAST> &ast)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, ast);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, std::unique_ptr<BaseAST> &ast)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], ast);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, ast); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, std::unique_ptr<BaseAST> &ast)
{
  YY_USE (yyvaluep);
  YY_USE (ast);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (std::unique_ptr<BaseAST> &ast)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* CompUnit: CompUnitItems  */
#line 76 "src/sysy.y"
                  {
      ast = std::unique_ptr<BaseAST>((yyvsp[0].ast_val));
    }
#line 1566 "src/sysy.tab.cpp"
    break;

  case 3: /* CompUnitItems: CompUnitItem  */
#line 82 "src/sysy.y"
                 {
      auto node = new NodeAST("CompUnit");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = node;
    }
#line 1576 "src/sysy.tab.cpp"
    break;

  case 4: /* CompUnitItems: CompUnitItems CompUnitItem  */
#line 87 "src/sysy.y"
                               {
      auto node = static_cast<NodeAST *>((yyvsp[-1].ast_val));
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = node;
    }
#line 1586 "src/sysy.tab.cpp"
    break;

  case 5: /* CompUnitItem: Decl  */
#line 95 "src/sysy.y"
           { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 1592 "src/sysy.tab.cpp"
    break;

  case 6: /* CompUnitItem: FuncDef  */
#line 96 "src/sysy.y"
            { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 1598 "src/sysy.tab.cpp"
    break;

  case 9: /* Decl: ConstDecl  */
#line 107 "src/sysy.y"
              { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 1604 "src/sysy.tab.cpp"
    break;

  case 10: /* Decl: VarDecl  */
#line 108 "src/sysy.y"
              { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 1610 "src/sysy.tab.cpp"
    break;

  case 11: /* ConstDecl: CONST BType ConstDefList ';'  */
#line 112 "src/sysy.y"
                                 {
      (yyval.ast_val) = new NodeAST("ConstDecl");
    }
#line 1618 "src/sysy.tab.cpp"
    break;

  case 24: /* VarDecl: BType VarDefList ';'  */
#line 151 "src/sysy.y"
                         {
      (yyval.ast_val) = new NodeAST("VarDecl");
    }
#line 1626 "src/sysy.tab.cpp"
    break;

  case 37: /* FuncDef: VOID IDENT '(' FuncFParamsOpt ')' Block  */
#line 190 "src/sysy.y"
                                            {
      std::string name = *(yyvsp[-4].str_val);
      delete (yyvsp[-4].str_val);
      auto node = new NodeAST("FuncDef " + name);
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val))); // Block
      (yyval.ast_val) = node;
    }
#line 1638 "src/sysy.tab.cpp"
    break;

  case 38: /* FuncDef: BType IDENT '(' FuncFParamsOpt ')' Block  */
#line 197 "src/sysy.y"
                                             {
      std::string name = *(yyvsp[-4].str_val);
      delete (yyvsp[-4].str_val);
      auto node = new NodeAST("FuncDef " + name);
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val))); // Block
      (yyval.ast_val) = node;
    }
#line 1650 "src/sysy.tab.cpp"
    break;

  case 43: /* FuncFParam: BType IDENT  */
#line 217 "src/sysy.y"
                {
      // 标量形参，当前不单独在 AST 中展示
    }
#line 1658 "src/sysy.tab.cpp"
    break;

  case 44: /* FuncFParam: BType IDENT FuncFParamArrayDims  */
#line 220 "src/sysy.y"
                                    {
      // 数组形参，同样暂不在 AST 中细化维度信息
    }
#line 1666 "src/sysy.tab.cpp"
    break;

  case 47: /* Block: '{' BlockItemsOpt '}'  */
#line 232 "src/sysy.y"
                          {
      auto node = new NodeAST("Block");
      if ((yyvsp[-1].ast_val)) {
        node->Add(std::unique_ptr<BaseAST>((yyvsp[-1].ast_val)));
      }
      (yyval.ast_val) = node;
    }
#line 1678 "src/sysy.tab.cpp"
    break;

  case 48: /* BlockItemsOpt: %empty  */
#line 242 "src/sysy.y"
                { (yyval.ast_val) = nullptr; }
#line 1684 "src/sysy.tab.cpp"
    break;

  case 49: /* BlockItemsOpt: BlockItems  */
#line 243 "src/sysy.y"
                { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 1690 "src/sysy.tab.cpp"
    break;

  case 50: /* BlockItems: BlockItem  */
#line 247 "src/sysy.y"
              {
      auto list = new NodeAST("BlockItems");
      list->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = list;
    }
#line 1700 "src/sysy.tab.cpp"
    break;

  case 51: /* BlockItems: BlockItems BlockItem  */
#line 252 "src/sysy.y"
                         {
      auto list = static_cast<NodeAST *>((yyvsp[-1].ast_val));
      list->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = list;
    }
#line 1710 "src/sysy.tab.cpp"
    break;

  case 52: /* BlockItem: Decl  */
#line 260 "src/sysy.y"
         { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 1716 "src/sysy.tab.cpp"
    break;

  case 53: /* BlockItem: Stmt  */
#line 261 "src/sysy.y"
         { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 1722 "src/sysy.tab.cpp"
    break;

  case 54: /* Stmt: LVal '=' Exp ';'  */
#line 266 "src/sysy.y"
                     {
      auto node = new NodeAST("Assign");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-3].ast_val)));
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-1].ast_val)));
      (yyval.ast_val) = node;
    }
#line 1733 "src/sysy.tab.cpp"
    break;

  case 55: /* Stmt: Exp ';'  */
#line 272 "src/sysy.y"
            {
      auto node = new NodeAST("ExprStmt");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-1].ast_val)));
      (yyval.ast_val) = node;
    }
#line 1743 "src/sysy.tab.cpp"
    break;

  case 56: /* Stmt: ';'  */
#line 277 "src/sysy.y"
        {
      (yyval.ast_val) = new NodeAST("EmptyStmt");
    }
#line 1751 "src/sysy.tab.cpp"
    break;

  case 57: /* Stmt: Block  */
#line 280 "src/sysy.y"
          {
      (yyval.ast_val) = (yyvsp[0].ast_val);
    }
#line 1759 "src/sysy.tab.cpp"
    break;

  case 58: /* Stmt: IF '(' Cond ')' Stmt  */
#line 283 "src/sysy.y"
                         {
      auto node = new NodeAST("If");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-2].ast_val))); // 条件
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val))); // then
      (yyval.ast_val) = node;
    }
#line 1770 "src/sysy.tab.cpp"
    break;

  case 59: /* Stmt: IF '(' Cond ')' Stmt ELSE Stmt  */
#line 289 "src/sysy.y"
                                   {
      auto node = new NodeAST("IfElse");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-4].ast_val))); // 条件
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-2].ast_val))); // then
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val))); // else
      (yyval.ast_val) = node;
    }
#line 1782 "src/sysy.tab.cpp"
    break;

  case 60: /* Stmt: WHILE '(' Cond ')' Stmt  */
#line 296 "src/sysy.y"
                            {
      auto node = new NodeAST("While");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-2].ast_val))); // 条件
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val))); // 循环体
      (yyval.ast_val) = node;
    }
#line 1793 "src/sysy.tab.cpp"
    break;

  case 61: /* Stmt: BREAK ';'  */
#line 302 "src/sysy.y"
              {
      (yyval.ast_val) = new NodeAST("Break");
    }
#line 1801 "src/sysy.tab.cpp"
    break;

  case 62: /* Stmt: CONTINUE ';'  */
#line 305 "src/sysy.y"
                 {
      (yyval.ast_val) = new NodeAST("Continue");
    }
#line 1809 "src/sysy.tab.cpp"
    break;

  case 63: /* Stmt: RETURN Exp ';'  */
#line 308 "src/sysy.y"
                   {
      auto node = new NodeAST("Return");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-1].ast_val)));
      (yyval.ast_val) = node;
    }
#line 1819 "src/sysy.tab.cpp"
    break;

  case 64: /* Stmt: RETURN ';'  */
#line 313 "src/sysy.y"
               {
      (yyval.ast_val) = new NodeAST("ReturnVoid");
    }
#line 1827 "src/sysy.tab.cpp"
    break;

  case 65: /* LVal: IDENT  */
#line 320 "src/sysy.y"
          {
      std::string name = *(yyvsp[0].str_val);
      delete (yyvsp[0].str_val);
      (yyval.ast_val) = new NodeAST("LVal " + name);
    }
#line 1837 "src/sysy.tab.cpp"
    break;

  case 66: /* LVal: IDENT LValArrayDims  */
#line 325 "src/sysy.y"
                        {
      std::string name = *(yyvsp[-1].str_val);
      delete (yyvsp[-1].str_val);
      // 为简化实现，这里不单独展示每一维的信息
      (yyval.ast_val) = new NodeAST("LValArray " + name);
    }
#line 1848 "src/sysy.tab.cpp"
    break;

  case 69: /* Exp: LOrExp  */
#line 340 "src/sysy.y"
           { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 1854 "src/sysy.tab.cpp"
    break;

  case 70: /* Cond: LOrExp  */
#line 344 "src/sysy.y"
           { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 1860 "src/sysy.tab.cpp"
    break;

  case 71: /* LOrExp: LAndExp  */
#line 348 "src/sysy.y"
            { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 1866 "src/sysy.tab.cpp"
    break;

  case 72: /* LOrExp: LOrExp OR LAndExp  */
#line 349 "src/sysy.y"
                      {
      auto node = new NodeAST("||");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-2].ast_val)));
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = node;
    }
#line 1877 "src/sysy.tab.cpp"
    break;

  case 73: /* LAndExp: EqExp  */
#line 358 "src/sysy.y"
          { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 1883 "src/sysy.tab.cpp"
    break;

  case 74: /* LAndExp: LAndExp AND EqExp  */
#line 359 "src/sysy.y"
                      {
      auto node = new NodeAST("&&");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-2].ast_val)));
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = node;
    }
#line 1894 "src/sysy.tab.cpp"
    break;

  case 75: /* EqExp: RelExp  */
#line 368 "src/sysy.y"
           { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 1900 "src/sysy.tab.cpp"
    break;

  case 76: /* EqExp: EqExp EQ RelExp  */
#line 369 "src/sysy.y"
                    {
      auto node = new NodeAST("==");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-2].ast_val)));
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = node;
    }
#line 1911 "src/sysy.tab.cpp"
    break;

  case 77: /* EqExp: EqExp NE RelExp  */
#line 375 "src/sysy.y"
                    {
      auto node = new NodeAST("!=");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-2].ast_val)));
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = node;
    }
#line 1922 "src/sysy.tab.cpp"
    break;

  case 78: /* RelExp: AddExp  */
#line 384 "src/sysy.y"
           { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 1928 "src/sysy.tab.cpp"
    break;

  case 79: /* RelExp: RelExp '<' AddExp  */
#line 385 "src/sysy.y"
                      {
      auto node = new NodeAST("<");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-2].ast_val)));
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = node;
    }
#line 1939 "src/sysy.tab.cpp"
    break;

  case 80: /* RelExp: RelExp '>' AddExp  */
#line 391 "src/sysy.y"
                      {
      auto node = new NodeAST(">");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-2].ast_val)));
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = node;
    }
#line 1950 "src/sysy.tab.cpp"
    break;

  case 81: /* RelExp: RelExp LE AddExp  */
#line 397 "src/sysy.y"
                     {
      auto node = new NodeAST("<=");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-2].ast_val)));
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = node;
    }
#line 1961 "src/sysy.tab.cpp"
    break;

  case 82: /* RelExp: RelExp GE AddExp  */
#line 403 "src/sysy.y"
                     {
      auto node = new NodeAST(">=");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-2].ast_val)));
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = node;
    }
#line 1972 "src/sysy.tab.cpp"
    break;

  case 83: /* AddExp: MulExp  */
#line 412 "src/sysy.y"
           { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 1978 "src/sysy.tab.cpp"
    break;

  case 84: /* AddExp: AddExp '+' MulExp  */
#line 413 "src/sysy.y"
                      {
      auto node = new NodeAST("+");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-2].ast_val)));
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = node;
    }
#line 1989 "src/sysy.tab.cpp"
    break;

  case 85: /* AddExp: AddExp '-' MulExp  */
#line 419 "src/sysy.y"
                      {
      auto node = new NodeAST("-");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-2].ast_val)));
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = node;
    }
#line 2000 "src/sysy.tab.cpp"
    break;

  case 86: /* MulExp: UnaryExp  */
#line 428 "src/sysy.y"
             { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 2006 "src/sysy.tab.cpp"
    break;

  case 87: /* MulExp: MulExp '*' UnaryExp  */
#line 429 "src/sysy.y"
                        {
      auto node = new NodeAST("*");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-2].ast_val)));
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = node;
    }
#line 2017 "src/sysy.tab.cpp"
    break;

  case 88: /* MulExp: MulExp '/' UnaryExp  */
#line 435 "src/sysy.y"
                        {
      auto node = new NodeAST("/");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-2].ast_val)));
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = node;
    }
#line 2028 "src/sysy.tab.cpp"
    break;

  case 89: /* MulExp: MulExp '%' UnaryExp  */
#line 441 "src/sysy.y"
                        {
      auto node = new NodeAST("%");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[-2].ast_val)));
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = node;
    }
#line 2039 "src/sysy.tab.cpp"
    break;

  case 90: /* UnaryExp: PrimaryExp  */
#line 450 "src/sysy.y"
               { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 2045 "src/sysy.tab.cpp"
    break;

  case 91: /* UnaryExp: '+' UnaryExp  */
#line 451 "src/sysy.y"
                             {
      auto node = new NodeAST("unary+");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = node;
    }
#line 2055 "src/sysy.tab.cpp"
    break;

  case 92: /* UnaryExp: '-' UnaryExp  */
#line 456 "src/sysy.y"
                              {
      auto node = new NodeAST("unary-");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = node;
    }
#line 2065 "src/sysy.tab.cpp"
    break;

  case 93: /* UnaryExp: '!' UnaryExp  */
#line 461 "src/sysy.y"
                 {
      auto node = new NodeAST("!");
      node->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = node;
    }
#line 2075 "src/sysy.tab.cpp"
    break;

  case 94: /* UnaryExp: IDENT '(' FuncRParamsOpt ')'  */
#line 466 "src/sysy.y"
                                 {
      std::string name = *(yyvsp[-3].str_val);
      delete (yyvsp[-3].str_val);
      auto node = new NodeAST("Call " + name);
      if ((yyvsp[-1].ast_val)) {
        node->Add(std::unique_ptr<BaseAST>((yyvsp[-1].ast_val)));
      }
      (yyval.ast_val) = node;
    }
#line 2089 "src/sysy.tab.cpp"
    break;

  case 95: /* FuncRParamsOpt: %empty  */
#line 478 "src/sysy.y"
                { (yyval.ast_val) = nullptr; }
#line 2095 "src/sysy.tab.cpp"
    break;

  case 96: /* FuncRParamsOpt: FuncRParams  */
#line 479 "src/sysy.y"
                 { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 2101 "src/sysy.tab.cpp"
    break;

  case 97: /* FuncRParams: Exp  */
#line 483 "src/sysy.y"
        {
      auto list = new NodeAST("Args");
      list->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = list;
    }
#line 2111 "src/sysy.tab.cpp"
    break;

  case 98: /* FuncRParams: FuncRParams ',' Exp  */
#line 488 "src/sysy.y"
                        {
      auto list = static_cast<NodeAST *>((yyvsp[-2].ast_val));
      list->Add(std::unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.ast_val) = list;
    }
#line 2121 "src/sysy.tab.cpp"
    break;

  case 99: /* PrimaryExp: '(' Exp ')'  */
#line 496 "src/sysy.y"
                { (yyval.ast_val) = (yyvsp[-1].ast_val); }
#line 2127 "src/sysy.tab.cpp"
    break;

  case 100: /* PrimaryExp: LVal  */
#line 497 "src/sysy.y"
                { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 2133 "src/sysy.tab.cpp"
    break;

  case 101: /* PrimaryExp: Number  */
#line 498 "src/sysy.y"
                { (yyval.ast_val) = (yyvsp[0].ast_val); }
#line 2139 "src/sysy.tab.cpp"
    break;

  case 102: /* Number: INT_CONST  */
#line 502 "src/sysy.y"
              {
      auto node = new NodeAST("IntConst(" + std::to_string((yyvsp[0].int_val)) + ")");
      (yyval.ast_val) = node;
    }
#line 2148 "src/sysy.tab.cpp"
    break;

  case 103: /* Number: FLOAT_CONST  */
#line 506 "src/sysy.y"
                {
      auto node = new NodeAST("FloatConst");
      (yyval.ast_val) = node;
    }
#line 2157 "src/sysy.tab.cpp"
    break;


#line 2161 "src/sysy.tab.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (ast, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

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
                      yytoken, &yylval, ast);
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, ast);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (ast, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, ast);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, ast);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 512 "src/sysy.y"


// =================== 错误处理 ===================
// 当语法分析出错时，Bison 会调用该函数。
void yyerror(std::unique_ptr<BaseAST> &ast, const char *s) {
  std::cerr << "Syntax error at line " << yylineno
            << " near \"" << (yytext ? yytext : (char*)"<eof>") << "\": "
            << s << std::endl;
}


