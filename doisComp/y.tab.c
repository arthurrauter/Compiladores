#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20090221

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
#ifdef YYPARSE_PARAM_TYPE
#define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
#else
#define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
#endif
#else
#define YYPARSE_DECL() yyparse(void)
#endif /* YYPARSE_PARAM */

extern int YYPARSE_DECL();

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 2 "parser.y"
/*c code*/
/*UFRGS, Compiladores 2011/1. Prof. Marcelo Johann*/
/*Alessandra Leonnhardt - 181895*/
/*Arthur C. Rauter -  180575*/
#include <stdio.h>
#include "hash.h"

int yyerror (char *str)
    {
        fflush (stderr);
        fprintf (stderr, "Linha %d: erro - %s\n", getLineNumber(), str);
        exit (3);
    }

#line 18 "parser.y"
typedef union
{
    struct _node *hashNode;
} YYSTYPE;
#line 54 "y.tab.c"
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
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    0,    1,    1,    3,    3,    3,    3,
    2,    4,    4,    4,    6,    5,    7,    7,    8,    8,
    8,    8,    8,    8,    9,    9,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   13,   14,   14,
   14,   14,   14,   12,   15,   15,   15,   15,   15,   15,
   10,   10,   10,
};
static const short yylen[] = {                            2,
    1,    1,    1,    0,    3,    6,    1,    1,    1,    1,
    6,    1,    3,    0,    2,    3,    3,    0,    1,    1,
    2,    2,    2,    0,    3,    6,    3,    1,    4,    1,
    1,    1,    1,    1,    1,    1,    1,    3,    1,    1,
    1,    1,    1,    3,    1,    1,    1,    1,    1,    1,
    6,    8,    5,
};
static const short yydefred[] = {                         0,
    7,    8,   10,    9,    3,    1,    2,    0,    0,    5,
    0,    0,    0,    0,    0,    0,    0,   15,    0,    0,
    6,    0,   11,   13,    0,    0,    0,    0,    0,    0,
    0,    0,   19,   20,    0,    0,    0,   32,   33,   34,
   35,   30,   31,    0,    0,   36,   37,    0,   21,    0,
    0,   16,    0,    0,    0,    0,    0,   47,   48,   49,
   50,   45,   46,   39,   40,   41,   42,   43,    0,    0,
    0,    0,   17,    0,    0,    0,   27,    0,    0,    0,
    0,   53,   29,    0,    0,    0,    0,   52,
};
static const short yydgoto[] = {                          5,
    6,    7,   14,   15,   23,   16,   31,   32,   33,   34,
   45,   46,   47,   69,   70,
};
static const short yysindex[] = {                      -254,
    0,    0,    0,    0,    0,    0,    0, -267,  -12,    0,
 -265, -254,  -84, -251,  -15,   -6,  -14,    0,  -69, -254,
    0, -186,    0,    0,   19,   21,  -40,  -40, -204,  -60,
  -53,   14,    0,    0,  -40,  -40,  -17,    0,    0,    0,
    0,    0,    0,  -40,   20,    0,    0,   20,    0,  -40,
  -40,    0, -186,  -20,   -8,  -40,   -1,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -40,  -40,
    6,   20,    0, -179,  -69,   13,    0,   20,   20,   23,
  -69,    0,    0,  -40, -177,   20,  -69,    0,
};
static const short yyrindex[] = {                        87,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   47,    0,    0,    0,   49,    0,    0,    0,   47,
    0,  -57,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -27,    0,    0,    0,
    0,    0,    0,    0,   34,    0,    0,   35,    0,    0,
    0,    0,  -57,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   36,    0,    0,    0,    0,    0,  -29,   11,    0,
    0,    0,    0,    0,   37,   39,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  100,   81,  -68,    0,   50,    0,    0,    0,
   41,    0,    0,    0,    0,
};
#define YYTABLESIZE 294
static const short yytable[] = {                         44,
   51,   24,    1,    2,    3,    4,   82,    9,   17,   28,
   13,   38,   85,   28,   28,   28,   68,   28,   88,   28,
   74,   66,   64,   18,   65,   19,   67,   12,   68,   38,
   50,   28,   75,   66,   64,   68,   65,   20,   67,   77,
   66,   64,   68,   65,   21,   67,   10,   66,   64,   68,
   65,   44,   67,   22,   66,   64,   68,   65,   35,   67,
   36,   66,   64,   38,   65,   28,   67,   18,   48,   44,
   49,   52,   53,   56,   25,   54,   55,   26,   11,   27,
   28,   29,   81,   84,   57,   87,    4,   14,   30,   12,
   71,   72,   22,   23,   25,   51,   76,   26,   80,    8,
   24,    0,   73,   44,    0,   83,    0,    0,    0,   78,
   79,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   86,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,   37,   38,   39,   40,   41,   42,
   43,   28,   28,   28,   28,   28,   28,    0,   58,   59,
   60,   61,   62,   63,    0,    0,    0,    0,    0,    0,
   58,   59,   60,   61,   62,   63,    0,   58,   59,   60,
   61,   62,   63,    0,   58,   59,   60,   61,   62,   63,
    0,   58,   59,   60,   61,   62,   63,    0,   58,   59,
   60,   61,   62,   63,
};
static const short yycheck[] = {                         40,
   61,   59,  257,  258,  259,  260,   75,  275,   93,   37,
  276,   41,   81,   41,   42,   43,   37,   45,   87,   47,
   41,   42,   43,  275,   45,   41,   47,   40,   37,   59,
   91,   59,   41,   42,   43,   37,   45,   44,   47,   41,
   42,   43,   37,   45,   59,   47,   59,   42,   43,   37,
   45,   41,   47,  123,   42,   43,   37,   45,   40,   47,
   40,   42,   43,   93,   45,   93,   47,  125,   28,   59,
  275,  125,   59,   91,  261,   35,   36,  264,   91,  266,
  267,  268,  262,   61,   44,  263,    0,   41,  275,   41,
   50,   51,   59,   59,   59,   59,   56,   59,   93,    0,
   20,   -1,   53,   93,   -1,   93,   -1,   -1,   -1,   69,
   70,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   84,   -1,   -1,   -1,   -1,   -1,
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
   -1,   -1,   -1,   -1,  275,  276,  277,  278,  279,  280,
  281,  269,  270,  271,  272,  273,  274,   -1,  269,  270,
  271,  272,  273,  274,   -1,   -1,   -1,   -1,   -1,   -1,
  269,  270,  271,  272,  273,  274,   -1,  269,  270,  271,
  272,  273,  274,   -1,  269,  270,  271,  272,  273,  274,
   -1,  269,  270,  271,  272,  273,  274,   -1,  269,  270,
  271,  272,  273,  274,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 282
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
"LIT_STRING","TOKEN_ERROR",
};
static const char *yyrule[] = {
"$accept : programa",
"programa : declaracao",
"programa : funcao",
"programa : programa",
"programa :",
"declaracao : tipo TK_IDENTIFIER ';'",
"declaracao : tipo TK_IDENTIFIER '[' LIT_INTEGER ']' ';'",
"tipo : KW_INT",
"tipo : KW_FLOAT",
"tipo : KW_CHAR",
"tipo : KW_BOOL",
"funcao : tipo TK_IDENTIFIER '(' lista_parametros ')' bloco",
"lista_parametros : parametro",
"lista_parametros : parametro ',' lista_parametros",
"lista_parametros :",
"parametro : tipo TK_IDENTIFIER",
"bloco : '{' bloco_comandos '}'",
"bloco_comandos : comando ';' bloco_comandos",
"bloco_comandos :",
"comando : atribuicao",
"comando : fluxo",
"comando : KW_READ TK_IDENTIFIER",
"comando : KW_PRINT expressao",
"comando : KW_RETURN expressao",
"comando :",
"atribuicao : TK_IDENTIFIER '=' expressao",
"atribuicao : TK_IDENTIFIER '[' expressao ']' '=' expressao",
"expressao : '(' expressao ')'",
"expressao : TK_IDENTIFIER",
"expressao : TK_IDENTIFIER '[' expressao ']'",
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
"operador_logico : OPERATOR_AND",
"operador_logico : OPERATOR_OR",
"operador_logico : OPERATOR_LE",
"operador_logico : OPERATOR_GE",
"operador_logico : OPERATOR_EQ",
"operador_logico : OPERATOR_NE",
"fluxo : KW_IF '(' expressao ')' KW_THEN bloco",
"fluxo : KW_IF '(' expressao ')' KW_THEN bloco KW_ELSE bloco",
"fluxo : KW_WHILE '(' expressao ')' bloco",

};
#endif
#if YYDEBUG
#include <stdio.h>
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
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static unsigned yystacksize;
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

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

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    yystate = 0;
    *yyssp = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
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
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yyssp = yytable[yyn];
        *++yyvsp = yylval;
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
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yyssp = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
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
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
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
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = (short) yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
