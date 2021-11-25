using namespace std;
#include <iostream>
#include <cstring>
#include "Trajet.h"
#include "TrajetSimple.h"

Trajet::Trajet() {
	
}

void Trajet::getTrajet(char* getVilleDepart, char* getVilleArrivee) {
	strcpy(getVilleDepart, villeDepart);
	strcpy(getVilleArrivee, villeArrivee);
}

Trajet::Trajet (const char* uneVilleDepart, const char* uneVilleArrivee) {
	strcpy (villeDepart, uneVilleDepart);
	strcpy (villeArrivee, uneVilleArrivee);
}

Trajet::Trajet (const Trajet & unTrajet) {
	strcpy(villeDepart, unTrajet.villeDepart);
	strcpy(villeArrivee, unTrajet.villeArrivee);
}

	
void Trajet::afficher() const {
	cout << "de " << villeDepart << " jusqu'a " << villeArrivee;  
}
	
Trajet::~Trajet() {
//	delete[] villeDepart;
//	delete[] villeArrivee;
} 
