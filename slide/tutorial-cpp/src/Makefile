CXX=g++
CXXFLAGS=-std=c++11 -Wall

all : complex-demo

complex-demo : complex main

complex : complex.cpp complex.h
	$(CXX) -$(CXXFLAGS) -c -o libcomplex.so $<

main : complex-demo.cpp complex
	$(CXX) -$(CXXFLAGS) -L. -lcomplex $<

clean :
	rm -rf *.so *.out

.PHONY : all clean complex-demo complex main
