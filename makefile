# Makefile
# make main

# Variáveis
CC = g++
CFLAGS = -Wall

# Regras
all: main

# Compilar: make main
# Rodar: ./main
main: main.o pessoa.o funcionario.o filme.o jogo.o midia.o endereco.o
	$(CC) $(CFLAGS) -o main main.o pessoa.o funcionario.o filme.o jogo.o midia.o endereco.o

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp

pessoa.o: pessoa.cpp pessoa.h
	$(CC) $(CFLAGS) -c pessoa.cpp

funcionario.o: funcionario.cpp funcionario.h
	$(CC) $(CFLAGS) -c funcionario.cpp

filme.o: filme.cpp filme.h
	$(CC) $(CFLAGS) -c filme.cpp

jogo.o: jogo.cpp jogo.h
	$(CC) $(CFLAGS) -c jogo.cpp

midia.o: midia.cpp midia.h
	$(CC) $(CFLAGS) -c midia.cpp

endereco.o: endereco.cpp endereco.h
	$(CC) $(CFLAGS) -c endereco.cpp

clean:
	rm -f *.o main
