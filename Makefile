all: libmygl2d.a game

libmygl2d.a: mygl2d.cpp mygl2d.hpp
	gcc -c  mygl2d.cpp -I include
	ar rcs libmygl2d.a mygl2d.o

game: main.cpp
	gcc main.cpp -o game -I. -L. -lmygl2d -lglfw -lGL -lGLU -lX11 -lm

clean:
	rm *.o game libmygl2d.a
