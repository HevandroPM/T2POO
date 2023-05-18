# Makefile
# make main

# Variáveis
CC = gcc
CFLAGS = -Wall

# Regras
all: main

main: main.o pessoa.o
	$(CC) $(CFLAGS) -o main main.o pessoa.o

main.o: main.cpp pessoa.h
	$(CC) $(CFLAGS) -c main.cpp

pessoa.o: pessoa.cpp pessoa.h
	$(CC) $(CFLAGS) -c pessoa.cpp

clean:
	rm -f *.o main
