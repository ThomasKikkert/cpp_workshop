cpp = g++ -std=c++2a -O3
sdlFlag = `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf

all: clean main

main: screen/screen.o texture/texture.o dvd_logo/dvd_logo.o input/input.o
	$(cpp) main.cpp screen/screen.o texture/texture.o dvd_logo/dvd_logo.o \
	input/input.o $(sdlFlag) -o main

screen: 
	$(cpp) -c screen/screen.cpp $(sdlFlag) -o screen/screen.o

texture:
	$(cpp) -c texture/texture.cpp $(sdlFlag) -o texture/texture.o

dvd_logo:
	$(cpp) -c dvd_logo/dvd_logo.cpp $(sdlFlag) -o dvd_logo/dvd_logo.o

input:
	$(cpp) -c input/input.cpp $(sdlFlag) -o input/input.o

clean: 
	find . -name "*.o" -delete
	clear

run: main
	./main
