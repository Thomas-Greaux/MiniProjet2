COMPIL= g++ -c
LINK= g++
FLAGS= -Wall -std=c++11
EXE_NAME= prog.exe

SOURCES= main.cpp

LINK_OBJS= $(SOURCES:.cpp=.o)

$(EXE_NAME): $(LINK_OBJS)
	$(LINK) $(LINK_OBJS) -o $@ $(FLAGS)

%.o: %.cpp
	$(COMPIL) $^ -o $@ $(FLAGS)
