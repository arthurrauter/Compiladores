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
typedef union
{
    struct _node *hashNode;
} YYSTYPE;
extern YYSTYPE yylval;
