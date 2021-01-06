LIB=-lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio
CC=clang++
SRC=$(wildcard *.cpp)
APP=APP

all: ${SRC:.cpp=.o}
			${CC} ${SRC} -o ${APP} ${LIB}

clean:
	rm -rf ${APP}

mrproper: clean
	rm -rf *.o
