sejours: TrajetSimple.o TrajetCompose.o Trajet.o NodeTrajet.o ListeTrajet.o Catalogue.o main.o 
	g++ -o sejours *.o -ansi -pedantic -std=c++11 -Wall 
main: main.cpp
	g++ -c main.cpp 
Trajet: Trajet.cpp
	g++ -c Trajet.cpp
TrajetSimple: TrajetSimple.cpp
	g++ -c TrajetSimple.cpp
TrajetCompose: TrajetCompose.cpp
	g++ -c TrajetCompose.cpp
ListeTrajet: ListeTrajet.cpp
	g++ -c ListeTrajet.cpp
NodeTrajet: NodeTrajet.cpp
	g++ -c NodeTrajet.cpp
Catalogue: Catalogue.cpp
	g++ -c Catalogue.cpp
valgrind: ./sejours
	valgrind ./sejours -g

