sejours: TrajetSimple.o TrajetCompose.o Trajet.o NodeTrajet.o ListeTrajet.o Catalogue.o main.o 
	g++ -o sejours *.o -ansi -pedantic -std=c++11 -Wall -D MAP
main: main.cpp
	g++ -c main.cpp -D MAP
Trajet: Trajet.cpp
	g++ -c Trajet.cpp -D MAP
TrajetSimple: TrajetSimple.cpp
	g++ -c TrajetSimple.cpp -D MAP
TrajetCompose: TrajetCompose.cpp
	g++ -c TrajetCompose.cpp -D MAP
ListeTrajet: ListeTrajet.cpp
	g++ -c ListeTrajet.cpp -D MAP
NodeTrajet: NodeTrajet.cpp
	g++ -c NodeTrajet.cpp -D MAP
Catalogue: Catalogue.cpp
	g++ -c Catalogue.cpp -D MAP
valgrind: ./sejours
	valgrind ./sejours -g

