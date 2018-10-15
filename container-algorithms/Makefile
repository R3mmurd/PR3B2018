CXX = clang++ -std=c++14

OPT = -Ofast


all: container-algorithms-impl

container-algorithms-impl: container-algorithms-impl.C
	$(CXX) $(OPT) $@.C -o $@

clean:
	$(RM) *~ container-algorithms-impl
