etapa5:	y.tab.o lex.yy.o main.o hash.o astree.o expressionChecker.o tac.o generateTac.o
	gcc -o etapa5 main.o hash.o astree.o tac.o

main.o: main.c 
	gcc -c main.c

hash.o: hash.c
	gcc -c hash.c

tac.o: tac.c
	gcc -c tac.c
	
generateTac.o: generateTac.c
	gcc -c generateTac.c

expressionChecker.o: expressionChecker.c
	gcc -c expressionChecker.c

astree.o: astree.c
	gcc -c astree.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: scanner.l y.tab.h
	flex --header-file=lex.yy.h scanner.l

y.tab.o: y.tab.c
	gcc -c y.tab.c

y.tab.c: parser.y
	 yacc -v -d parser.y

y.tab.h: parser.y
	 yacc -d parser.y


clean:
	rm *.o lex.yy.c y.tab.c y.tab.h etapa5

