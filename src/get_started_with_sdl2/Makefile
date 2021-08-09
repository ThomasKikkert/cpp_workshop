cc = gcc
cflag = -Wall -Wextra -Wconversion -Wpedantic
sdlFlag = `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
cpp = g++

all: clean build_main_c build_main_cpp

build_main_c:
	$(cc) $(cflag) c_code/main.c $(sdlFlag) -o main_c

build_main_cpp: cpp_code/screen/screen.o
	$(cpp) cpp_code/main.cpp cpp_code/screen/screen.o $(sdlFlag) -o main_cpp

screen: 
	$(cpp) -c cpp_code/screen/screen.cpp $(sdlFlag) -o screen/screen.o

clean: 
	find . -name "main_*" -delete
	find . -name "*.o" -delete
	clear

run_c:	main_c
	./main_c

run_cpp:	main_cpp
	./main_cpp
