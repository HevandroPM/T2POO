# Makefile
# make main

# Variáveis
CC = gcc
CFLAGS = -Wall

# Regras
all: main

#Compilar: make main
#Rodar:    ./main

main: main.o pessoa.o funcionario.o
	$(CC) $(CFLAGS) -o main main.o pessoa.o funcionario.o

main.o: main.cpp pessoa.h
	$(CC) $(CFLAGS) -c main.cpp

pessoa.o: pessoa.cpp pessoa.h
	$(CC) $(CFLAGS) -c pessoa.cpp

funcionario.o: funcionario.cpp funcionario.h
	$(CC) $(CFLAGS) -c funcionario.cpp

clean:
	rm -f *.o main
