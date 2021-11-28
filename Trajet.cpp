using namespace std;
#include <iostream>
#include <cstring>
#include "Trajet.h"
#include "TrajetSimple.h"

Trajet::Trajet() {
	villeDepart = new char[50];
	villeArrivee = new char[50];
}

/*void Trajet::getTrajet(char* getVilleDepart, char* getVilleArrivee) {
	strcpy(getVilleDepart, villeDepart);
	strcpy(getVilleArrivee, villeArrivee);
}*/

Trajet::Trajet (const char* uneVilleDepart, const char* uneVilleArrivee) {
	villeDepart = new char[50];
	villeArrivee = new char[50];
	strcpy (villeDepart, uneVilleDepart);
	strcpy (villeArrivee, uneVilleArrivee);
}

Trajet::Trajet (const Trajet & unTrajet) {
	strcpy(villeDepart, unTrajet.villeDepart);
	strcpy(villeArrivee, unTrajet.villeArrivee);
}

char* Trajet::GetVille(int i) {
	if (i ==1) {
		return this->villeDepart;
	}
	return this->villeArrivee;
}
	
void Trajet::afficher(const int i) const {
	cout << "de " << villeDepart << " jusqu'a " << villeArrivee;  
}
	
Trajet::~Trajet() {
	delete[] villeDepart;
	delete[] villeArrivee;
} 
