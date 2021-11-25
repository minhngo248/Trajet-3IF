sejours: main.o Trajet.o TrajetSimple.o TrajetCompose.o ListeTrajet.o NodeTrajet.o Catalogue.o
	g++ -o sejours *.o
main: main.cpp
	g++ -c main.cpp -std=c++11
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

