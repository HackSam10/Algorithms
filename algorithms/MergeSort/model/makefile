ALGORITHM_FILE = algorithm

all: main.o function.o $(ALGORITHM_FILE).o

	gcc main.o function.o $(ALGORITHM_FILE).o -pthread -o $(ALGORITHM_FILE)
	rm -f *.o
	clear


main.o: src/header.h
		gcc -c src/main.c -o main.o

function.o: src/header.h
		gcc -c src/functions.c -o function.o

$(ALGORITHM_FILE).o: src/header.h
		gcc -c $(ALGORITHM_FILE).c -o $(ALGORITHM_FILE).o 
