CXX = g++ -std=c++0x
CC = -c
DEBUG = -g
OP = -Wall -O0
CXX_FLAGS = $(CXX) $(DEBUG)
#List of Targets
All: Date.o User.o Meeting.o Storage.o AgendaService.o AgendaUI.o
AgendaUI.o: AgendaUI.h AgendaUI.cpp
	$(CXX) $(CC) AgendaUI.cpp
AgendaService.o: AgendaService.h AgendaService.cpp
	$(CXX) $(CC) AgendaService.cpp
Date.o:	Date.h Date.cpp
	$(CXX) $(CC) Date.cpp
User.o: User.h User.cpp
	$(CXX) $(CC) User.cpp
Meeting.o: Meeting.h Meeting.cpp
	$(CXX) $(CC) Meeting.cpp
Storage.o: Storage.h Storage.cpp
	$(CXX) $(CC) Storage.cpp
clean :
	rm -rf *.o
