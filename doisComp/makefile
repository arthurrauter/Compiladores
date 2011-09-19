etapa2:	y.tab.o lex.yy.o main.o hash.o
	gcc -o etapa2 main.o hash.o

main.o: main.c 
	gcc -c main.c

hash.o: hash.c
	gcc -c hash.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: scanner.l y.tab.h
	flex --header-file=lex.yy.h scanner.l

y.tab.o: y.tab.c
	gcc -c y.tab.c

y.tab.c: parser.y
	 yacc -v parser.y

y.tab.h: parser.y
	 yacc -d parser.y

clean:
	rm *.o lex.yy.c y.tab.c etapa2

