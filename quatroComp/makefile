etapa4:	y.tab.o lex.yy.o main.o hash.o astree.o 
	gcc -o etapa4 main.o hash.o astree.o

main.o: main.c 
	gcc -c main.c

hash.o: hash.c
	gcc -c hash.c

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
	rm *.o lex.yy.c y.tab.c y.tab.h etapa4

