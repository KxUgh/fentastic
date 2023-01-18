CXXFLAGS = -std=c++17 -Wall -Wextra
fentastic: pograph
	$(CXX) $(CXXFLAGS) -o fentastic fentastic.cpp pograph/libpograph.a pograph/pograph.h

pograph:
	$(CXX) $(CXXFLAGS) -c -o pograph/pograph.o pograph/pograph.cpp