#	Twig Griffin
#	2024-11-14
# DSA2 - PermuteTest
#
# makefile

CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = Timer.o

permuteTest : ${OBJS} permuteTest.cpp
	${CXX} $(CXXFLAGS) -o $@ ${OBJS} permuteTest.cpp

# object file depends on header and class 
Timer.o: Timer.hpp Timer.cpp

clean: # -f flag prevents errors if any files do not exist, i.e. test cases were not built or not all objects were built.
	rm -f ${OBJS} permuteTest
