# Autor: Alejandro J. Mujica

CXX = clang++ -std=c++14

OPTIMIZATION = -Ofast

WARN = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings \
       -Wno-parentheses

FLAGS = $(OPTIMIZATION) $(WARN)

INCLUDE = -I.

all: sstime bstime selectionsortime insertionsorttime

sstime: sstime.C
	$(CXX) $(FLAGS) $(INCLUDE) $@.C -o $@

bstime: bstime.C
	$(CXX) $(FLAGS) $(INCLUDE) $@.C -o $@

selectionsorttime: selectionsorttime.C
	$(CXX) $(FLAGS) $(INCLUDE) $@.C -o $@

insertionsorttime: insertionsorttime.C
	$(CXX) $(FLAGS) $(INCLUDE) $@.C -o $@

clean:
	$(RM) *~ *.o sstime bstime selectionsorttime insertionsorttime *.png *.gp *.dat
