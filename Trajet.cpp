using namespace std;
#include <iostream>
#include <cstring>

#include "Trajet.h"

Trajet::Trajet (const Trajet & unTrajet) {
	strcpy(villeDepart, unTrajet.villeDepart);
	strcpy(villeArrivee, unTrajet.villeArrivee);
}


Trajet (const char* uneVilleDepart,const char* uneVilleArrivee) {
	strcpy (villeDepart, uneVilleDepart);
	strcpy (villeArrivee, uneVilleArrivee);
}
	

Trajet::~Trajet() {
	delete[] villeArrivee;
	delete[] villeDepart;
} 
