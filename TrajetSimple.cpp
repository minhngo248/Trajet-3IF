using namespace std;
#include <iostream>
#include <cstring>

#include "TrajetSimple.h"


TrajetSimple::TrajetSimple () {
	
}

TrajetSimple::TrajetSimple(const char* villeDepart,const char* villeArrivee, char* unMoyTrans)
: Trajet(villeDepart, villeArrivee), moyTrans(unMoyTrans) {
	moyTrans = new char[50];
	strcpy (moyTrans, unMoyTrans);
}

TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple ) {
	strcpy(villeDepart, unTrajetSimple.villeDepart);
	strcpy(villeArrivee, unTrajetSimple.villeArrivee);
	strcpy(moyTrans, unTrajetSimple.moyTrans);
}
	
void TrajetSimple::afficher() const {
	Trajet::afficher();
	cout << " en" << moyTrans;
}
TrajetSimple::~TrajetSimple() {
	delete[] villeArrivee;
	delete[] villeDepart;
	delete[] moyTrans;
} 

