CXX = g++ -std=c++0x
CC = -c
DEBUG = -g
OP = -Wall -O0
CXX_FLAGS = $(CXX) $(DEBUG)
#List of Targets
All: test
test: Date.o User.o Meeting.o Storage.o test.cpp
	$(CXX) Date.o User.o Meeting.o Storage.o test.cpp -o test
Date.o:	Date.h Date.cpp
	$(CXX) $(CC) Date.cpp
User.o: User.h User.cpp
	$(CXX) $(CC) User.cpp
Meeting.o: Meeting.h Meeting.cpp
	$(CXX) $(CC) Meeting.cpp
Storage.o: Storage.h Storage.cpp
	$(CXX) $(CC) Storage.cpp
clean :
	rm -rf *.o test
