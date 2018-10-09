CXX = clang++ -std=c++14

OPT = -Ofast

all: cut_rod

cut_rod: cut_rod.C
	$(CXX) $(OPT) $@.C -o $@

clean:
	$(RM) *~ *.o cut_rod
