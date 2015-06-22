all: main
CC = g++
CXX = -c
DEBUG = -g
OP = -Wall -O0 -lglut -lGL -lGLU
CXX_FLAGS = $(CC) $(DEBUG)
#List of Targets
main : Base.h Matrix.h Vector.h main.cpp
	$(CXX_FLAGS)	Base.h Matrix.h Vector.h main.cpp -o main $(OP)
clean :
	rm -rf *.o *.gch main
