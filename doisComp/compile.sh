rm lex.yy.c y.tab.c y.tab.h *.o
echo 
echo "lex scanner.l"
lex scanner.l
echo 
echo "yacc -d parser.y"
yacc -d parser.y
echo 
echo "gcc -c lex.yy.c"
gcc -c lex.yy.c
echo 
echo "gcc -c y.tab.c"
gcc -c y.tab.c
echo 
echo "gcc -c main.c"
gcc -c main.c
