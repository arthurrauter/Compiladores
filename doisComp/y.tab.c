#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20100610

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
/*c code*/
#include <stdio.h>
#include "hash.h"

int yyerror (char *str)
    {
        fflush (stderr);
        fprintf (stderr, "Linha %d: erro - %s\n", getLineNumber(), str);
        exit (3);
    }

#line 15 "parser.y"
typedef union
{
    struct _node *hashNode;
} YYSTYPE;
#line 36 "y.tab.c"
/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

extern int YYPARSE_DECL();
extern int YYLEX_DECL();

#define KW_INT 257
#define KW_FLOAT 258
#define KW_BOOL 259
#define KW_CHAR 260
#define KW_IF 261
#define KW_THEN 262
#define KW_ELSE 263
#define KW_WHILE 264
#define KW_DO 265
#define KW_PRINT 266
#define KW_RETURN 267
#define KW_READ 268
#define OPERATOR_LE 269
#define OPERATOR_GE 270
#define OPERATOR_EQ 271
#define OPERATOR_NE 272
#define OPERATOR_AND 273
#define OPERATOR_OR 274
#define TK_IDENTIFIER 275
#define LIT_INTEGER 276
#define LIT_FLOAT 277
#define LIT_FALSE 278
#define LIT_TRUE 279
#define LIT_CHAR 280
#define LIT_STRING 281
#define TOKEN_ERROR 282
#define TK_INDENTIFIER 283
#define vetor 284
#define OPERADOR_AND 285
#define OPERADOR_OR 286
#define OPERADOR_LE 287
#define OPERADOR_GE 288
#define OPERADOR_EQ 289
#define OPERADOR_NE 290
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    0,    1,    1,    3,    3,    3,    3,
    2,    4,    4,    6,    6,    7,    5,    8,    8,    9,
    9,    9,    9,    9,    9,   12,   12,   10,   10,   13,
   13,   13,   13,   13,   13,   13,   13,   13,   13,   13,
   15,   16,   16,   16,   16,   16,   14,   17,   17,   17,
   17,   17,   17,   11,   11,   11,
};
static const short yylen[] = {                            2,
    1,    1,    1,    0,    3,    6,    1,    1,    1,    1,
    6,    1,    0,    1,    3,    2,    3,    3,    0,    1,
    1,    2,    2,    2,    0,    1,    1,    3,    6,    3,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    3,    1,    1,    1,    1,    1,    3,    1,    1,    1,
    1,    1,    1,    6,    8,    5,
};
static const short yydefred[] = {                         0,
    7,    8,   10,    9,    3,    1,    2,    0,    0,    0,
    5,    0,    0,    0,    0,    0,   12,    0,    0,   16,
    0,    0,    6,    0,   11,   15,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   20,   21,    0,    0,   31,
   35,   36,   37,   38,   33,    0,    0,   32,   23,    0,
   39,   40,   34,    0,   22,    0,    0,   17,    0,    0,
    0,    0,   42,   43,   44,   45,   46,   48,   49,   50,
   51,   52,   53,    0,    0,    0,    0,   18,    0,    0,
   30,    0,    0,    0,    0,   56,    0,    0,    0,    0,
   55,
};
static const short yydgoto[] = {                          5,
    6,    7,   15,   16,   25,   17,   18,   34,   35,   36,
   37,   49,   50,   51,   52,   74,   75,
};
static const short yysindex[] = {                      -167,
    0,    0,    0,    0,    0,    0,    0, -224,  -56,  -24,
    0, -267, -167,  -70, -258,  -11,    0,  -12,  -15,    0,
  -77, -167,    0, -188,    0,    0,   13,   18,  -39,   14,
 -226,    2,  -27,  -64,   10,    0,    0,   14,   14,    0,
    0,    0,    0,    0,    0,    0,   14,    0,    0,   -2,
    0,    0,    0,   -2,    0,   14,   14,    0, -188,  -37,
  -30,  -23,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   14,   14,   -2,  -16,    0, -192,  -77,
    0,   -2,   -2,   11,  -77,    0,   14, -189,   -2,  -77,
    0,
};
static const short yyrindex[] = {                        71,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   34,    0,    0,    0,    0,   40,    0,    0,
    0,    0,    0,  -57,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   -9,    0,    0,    0,   23,
    0,    0,    0,   26,    0,    0,    0,    0,  -57,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   27,    0,    0,    0,    0,
    0,   -4,    1,    0,    0,    0,    0,   29,   38,    0,
    0,
};
static const short yygindex[] = {                         0,
    0,    0,   98,    0,  -28,   77,    0,   41,    0,    0,
    0,    0,    9,    0,    0,    0,    0,
};
#define YYTABLESIZE 298
static const short yytable[] = {                         67,
   47,   25,   11,   79,   65,   63,   67,   64,   14,   66,
   80,   65,   63,   67,   64,   13,   66,   81,   65,   63,
   67,   64,   19,   66,   20,   65,   63,   34,   64,   21,
   66,   22,   34,   34,   67,   34,   41,   34,   54,   65,
   63,   47,   64,   23,   66,   24,   60,   61,   55,   26,
    9,   86,   38,   47,   41,   62,   88,   39,   10,   47,
   58,   91,   56,   57,   76,   77,   12,   19,   59,   85,
    4,   87,   27,   90,   13,   28,   84,   29,   30,   31,
   14,   27,   82,   83,   24,   28,   32,   54,   41,    1,
    2,    3,    4,   47,   33,   89,   29,    8,   26,   78,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   40,   41,   42,   43,   44,
   45,   46,    0,    0,   48,    0,    0,   68,   69,   70,
   71,   72,   73,    0,   68,   69,   70,   71,   72,   73,
    0,   68,   69,   70,   71,   72,   73,    0,   68,   69,
   70,   71,   72,   73,    0,   34,   34,   34,   34,   34,
   34,    0,   68,   69,   70,   71,   72,   73,   40,   41,
   42,   43,   44,   45,   53,    0,    0,   48,
};
static const short yycheck[] = {                         37,
   40,   59,   59,   41,   42,   43,   37,   45,  276,   47,
   41,   42,   43,   37,   45,   40,   47,   41,   42,   43,
   37,   45,   93,   47,  283,   42,   43,   37,   45,   41,
   47,   44,   42,   43,   37,   45,   41,   47,   30,   42,
   43,   41,   45,   59,   47,  123,   38,   39,  275,   59,
  275,   80,   40,   40,   59,   47,   85,   40,  283,   59,
  125,   90,   61,   91,   56,   57,   91,  125,   59,  262,
    0,   61,  261,  263,   41,  264,   93,  266,  267,  268,
   41,   59,   74,   75,   59,   59,  275,   59,   93,  257,
  258,  259,  260,   93,  283,   87,   59,    0,   22,   59,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  275,  276,  277,  278,  279,
  280,  281,   -1,   -1,  284,   -1,   -1,  285,  286,  287,
  288,  289,  290,   -1,  285,  286,  287,  288,  289,  290,
   -1,  285,  286,  287,  288,  289,  290,   -1,  285,  286,
  287,  288,  289,  290,   -1,  285,  286,  287,  288,  289,
  290,   -1,  285,  286,  287,  288,  289,  290,  275,  276,
  277,  278,  279,  280,  281,   -1,   -1,  284,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
0,"';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",
0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,"KW_INT","KW_FLOAT","KW_BOOL","KW_CHAR","KW_IF","KW_THEN",
"KW_ELSE","KW_WHILE","KW_DO","KW_PRINT","KW_RETURN","KW_READ","OPERATOR_LE",
"OPERATOR_GE","OPERATOR_EQ","OPERATOR_NE","OPERATOR_AND","OPERATOR_OR",
"TK_IDENTIFIER","LIT_INTEGER","LIT_FLOAT","LIT_FALSE","LIT_TRUE","LIT_CHAR",
"LIT_STRING","TOKEN_ERROR","TK_INDENTIFIER","vetor","OPERADOR_AND",
"OPERADOR_OR","OPERADOR_LE","OPERADOR_GE","OPERADOR_EQ","OPERADOR_NE",
};
static const char *yyrule[] = {
"$accept : programa",
"programa : declaracao",
"programa : funcao",
"programa : programa",
"programa :",
"declaracao : tipo TK_IDENTIFIER ';'",
"declaracao : tipo TK_INDENTIFIER '[' LIT_INTEGER ']' ';'",
"tipo : KW_INT",
"tipo : KW_FLOAT",
"tipo : KW_CHAR",
"tipo : KW_BOOL",
"funcao : tipo TK_INDENTIFIER '(' lista_parametros ')' bloco",
"lista_parametros : mais_parametros",
"lista_parametros :",
"mais_parametros : parametro",
"mais_parametros : parametro ',' mais_parametros",
"parametro : tipo TK_INDENTIFIER",
"bloco : '{' bloco_comandos '}'",
"bloco_comandos : comando ';' bloco_comandos",
"bloco_comandos :",
"comando : atribuicao",
"comando : fluxo",
"comando : KW_READ TK_IDENTIFIER",
"comando : KW_PRINT imprimir",
"comando : KW_RETURN expressao",
"comando :",
"imprimir : LIT_STRING",
"imprimir : expressao",
"atribuicao : TK_IDENTIFIER '=' expressao",
"atribuicao : TK_INDENTIFIER '[' expressao ']' '=' expressao",
"expressao : '(' expressao ')'",
"expressao : TK_IDENTIFIER",
"expressao : vetor",
"expressao : LIT_CHAR",
"expressao : LIT_STRING",
"expressao : LIT_INTEGER",
"expressao : LIT_FLOAT",
"expressao : LIT_FALSE",
"expressao : LIT_TRUE",
"expressao : logica",
"expressao : aritmetica",
"aritmetica : expressao operador_aritmetico expressao",
"operador_aritmetico : '+'",
"operador_aritmetico : '-'",
"operador_aritmetico : '*'",
"operador_aritmetico : '/'",
"operador_aritmetico : '%'",
"logica : expressao operador_logico expressao",
"operador_logico : OPERADOR_AND",
"operador_logico : OPERADOR_OR",
"operador_logico : OPERADOR_LE",
"operador_logico : OPERADOR_GE",
"operador_logico : OPERADOR_EQ",
"operador_logico : OPERADOR_NE",
"fluxo : KW_IF '(' expressao ')' KW_THEN bloco",
"fluxo : KW_IF '(' expressao ')' KW_THEN bloco KW_ELSE bloco",
"fluxo : KW_WHILE '(' expressao ')' bloco",

};
#endif
/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (data->s_base != 0)
          ? (short *)realloc(data->s_base, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (data->l_base != 0)
          ? (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
