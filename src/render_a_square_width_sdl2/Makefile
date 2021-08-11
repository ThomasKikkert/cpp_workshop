cc = gcc
cflag = -Wall -Wextra -Wconversion -Wpedantic
sdlFlag = `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
cpp = g++

all: clean build_main_c build_main_cpp

build_main_c: c_code/screen/screen.o c_code/square/square.o
	$(cc) $(cflag) c_code/main.c c_code/screen/screen.o c_code/square/square.o $(sdlFlag) -o main_c

screen_:
	$(cc) -c c_code/screen/screen.c $(sdlFlag) -o screen/screen.o

square_:
	$(cc) -c c_code/square/square.c $(sdlFlag) -o square/square.o
	
build_main_cpp: cpp_code/screen/screen.o cpp_code/color/color.o cpp_code/rectangle/rectangle.o
	$(cpp) cpp_code/main.cpp cpp_code/screen/screen.o cpp_code/color/color.o \
	cpp_code/rectangle/rectangle.o $(sdlFlag) -o main_cpp

screen: 
	$(cpp) -c cpp_code/screen/screen.cpp $(sdlFlag) -o screen/screen.o

color:
	$(cpp) -c cpp_code/color/color.cpp $(sdlFlag) -o color/color.o

rectangle:
	$(cpp) -c cpp_code/rectangle/rectangle.cpp $(sdlFlag) -o rectangle/rectangle.o

clean: 
	find . -name "main_*" -delete
	find . -name "*.o" -delete
	clear

run_c:	main_c
	./main_c

run_cpp:	main_cpp
	./main_cpp
