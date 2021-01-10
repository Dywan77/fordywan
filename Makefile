LIB=-lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio -std=c++17
CC=g++
SRC=$(wildcard *.cpp)
APP=APP

all: ${SRC:.cpp=.o}
			${CC} ${SRC} -o ${APP} ${LIB}

clean:
	rm -rf ${APP}

mrproper: clean
	rm -rf *.o

//voila c'est fait, j'ai copier
