using namespace std;
#include <iostream>
#include <cstring>

#include "Trajet.h"

Trajet::Trajet() {
	
}

Trajet::Trajet (const char* uneVilleDepart, const char* uneVilleArrivee) {
	villeDepart = new char [50];
	villeArrivee = new char [50];
	strcpy (villeDepart, uneVilleDepart);
	strcpy (villeArrivee, uneVilleArrivee);
}

Trajet::Trajet (const Trajet & unTrajet) {
	strcpy(villeDepart, unTrajet.villeDepart);
	strcpy(villeArrivee, unTrajet.villeArrivee);
}

	
void Trajet::afficher() const {
	cout <<"de " << villeDepart << "a "<< villeArrivee;
}
	
Trajet::~Trajet() {
	TrajetSimple::~TrajetSimple();
	TrajetCompose::~TrajetCompose();
} 
