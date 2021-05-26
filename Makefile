CXX = g++


CXXFLAGS = -ansi -pedantic -Wall -std=c++11 


all:: test
Utilisateur.o: Utilisateur.cpp Utilisateur.h
	$(CXX) -o Utilisateur.o -c Utilisateur.cpp $(CXXFLAGS)

Admin.o: Admin.cpp Admin.h Utilisateur.h
	$(CXX) -o Admin.o -c Admin.cpp $(CXXFLAGS)

Gouvernement.o: Gouvernement.cpp Gouvernement.h Utilisateur.h
	$(CXX) -o Gouvernement.o -c Gouvernement.cpp $(CXXFLAGS)

Particulier.o: Particulier.cpp Particulier.h Utilisateur.h
	$(CXX) -o Particulier.o -c Particulier.cpp $(CXXFLAGS)

Provider.o: Provider.cpp Provider.h Utilisateur.h
	$(CXX) -o Provider.o -c Provider.cpp $(CXXFLAGS)

test.o: test.cpp Admin.h Gouvernement.h Particulier.h Provider.h Utilisateur.h
	$(CXX) -o test.o -c test.cpp $(CXXFLAGS)

test: Utilisateur.o Admin.o Gouvernement.o Particulier.o Provider.o test.o
	$(CXX) -o test test.o Utilisateur.o Provider.o Particulier.o Gouvernement.o Admin.o $(CXXFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf test