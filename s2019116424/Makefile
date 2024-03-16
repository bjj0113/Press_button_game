CC = gcc

ALL: main.o game.o ticker.o	
	gcc -o playgame main.o game.o ticker.o -lcurses
main.0 : main.c
	gcc -c -o main.o main.c -lcurses
game.o : game.c
	gcc -c -o game.o game.c -lcurses
ticker.o : ticker.c
	gcc -c -o ticker.o ticker.c -lcurses
clean: 
	rm -f *.o
		      
