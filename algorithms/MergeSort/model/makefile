all: main.o function.o algorithm.o

	gcc main.o function.o algorithm.o -o algorithm
	rm -f *.o


main.o: src/header.h
		gcc -c src/main.c -o main.o

function.o: src/header.h
		gcc -c src/functions.c -o function.o

#edit here
algorith.o: src/header.h
		gcc -c algoritm.c -o algorithm.o 
