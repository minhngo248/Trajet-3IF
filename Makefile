prog: main.o TrajetSimple.o ListeTrajet.o NodeTrajet.o Catalogue.o Trajet.o
	g++ -o prog main.o TrajetSimple.o ListeTrajet.o NodeTrajet.o Catalogue.o Trajet.o
main: main.cpp
	g++ -c main.cpp
TrajetSimple: TrajetSimple.cpp
	g++ -c TrajetSimple.cpp
ListeTrajet: ListeTrajet.cpp
	g++ -c ListeTrajet.cpp
NodeTrajet: NodeTrajet.cpp
	g++ -c NodeTrajet.cpp
Catalogue: Catalogue.cpp
	g++ -c Catalogue.cpp
Trajet: Trajet.cpp
	g++ -c Trajet.cpp
