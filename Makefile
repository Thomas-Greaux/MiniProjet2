COMPILER = g++ -c
LINK = g++
FLAGS = -Wall -std=c++11 -g
EXE_NAME = algo.ex stat.ex

SOURCES = ./source/algorithm.cc ./source/almost_worst_fit.cc ./source/best_fit.cc ./source/bin_pack.cc ./source/first_fit.cc ./source/next_fit.cc ./source/worst_fit.cc ./source/bin_packing_problem.cc
EXE_SOURCES = ./source/main_algo.cc ./source/main_stat.cc

LINK_OBJS = $(SOURCES:.cc=.o)
EXE_LINK_OBJS = $(EXE_SOURCES:.cc=.o)

all: $(EXE_NAME)

algo.ex: $(LINK_OBJS) ./source/main_algo.o
	$(LINK) $(FLAGS) $^ -o $@

stat.ex: $(LINK_OBJS) ./source/main_stat.o
	$(LINK) $(FLAGS) $^ -o $@

%.o: %.cc
	$(COMPILER) $(FLAGS) $^ -o $@

clean:
	rm -f $(EXE_NAME) $(EXE_LINK_OBJS) $(LINK_OBJS)
