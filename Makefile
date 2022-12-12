CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = bard.o bard_functions.o

bard: $(OBJECTS)
		$(CXX) -g $(CXXFLAGS) -o $@ bard.o bard_functions.o 

bard.o: bard.cpp bard_functions.h bard_functions.cpp 
		$(CXX) -g $(CXXFLAGS) -c bard.cpp 
	
bard_functions.o: bard_functions.cpp bard_functions.h 
		$(CXX) -g $(CXXFLAGS) -c bard_functions.cpp 

clean:
	rm *.o 
	rm bard
	