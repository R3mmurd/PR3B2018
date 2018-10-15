CXX = clang++ -std=c++14

OPT = -Ofast

INCLUDE = -I.


all: container-algorithms-impl container-algorithms-stl

container-algorithms-impl: container-algorithms-impl.C
	$(CXX) $(OPT) $(INCLUDE) $@.C -o $@

container-algorithms-stl: container-algorithms-impl.C
	$(CXX) $(OPT) $(INCLUDE) $@.C -o $@

clean:
	$(RM) *~ container-algorithms-impl container-algorithms-stl
