CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

SRCS = main.cpp pessoa.cpp banco_de_dados.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q /F *.o
	del /Q /F ${TARGET}.exe