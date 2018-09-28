CXX = clang++ -std=c++14 -Ofast

INCLUDE = -I.

all: search

search: search.C
	$(CXX) $(INCLUDE) $^ -o $@

clean:
	$(RM) *~ search
