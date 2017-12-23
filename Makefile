COMPIL= g++ -c
LINK= g++
FLAGS= -Wall -std=c++11 -g
EXE_NAME= algo.exe stat.exe

SOURCES= ./source/main_stat.cpp ./source/main_algo.cpp

LINK_OBJS= $(SOURCES:.cpp=.o)

all: $(EXE_NAME)

algo.exe: ./source/main_algo.o
	$(LINK) ./source/main_algo.o -o $@ $(FLAGS)

stat.exe: ./source/main_stat.o
	$(LINK) ./source/main_stat.o -o $@ $(FLAGS)

%.o: %.cpp
	$(COMPIL) $^ -o $@ $(FLAGS)

clean:
	rm -f $(LINK_OBJS)
