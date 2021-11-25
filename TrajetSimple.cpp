using namespace std;
#include <iostream>
#include <cstring>

#include "TrajetSimple.h"


TrajetSimple::TrajetSimple () {
	
}

void TrajetSimple::SetTrajet(const char* uneVilleDepart,const char* uneVilleArrivee, const char* unMoyTrans) {
	strcpy(villeDepart, uneVilleDepart);
	strcpy(villeArrivee, uneVilleArrivee);
	strcpy(moyTrans, unMoyTrans);
}

TrajetSimple::TrajetSimple(const char* villeDepart,const char* villeArrivee, const char* unMoyTrans)
: Trajet(villeDepart, villeArrivee) {
	strcpy (moyTrans, unMoyTrans);
}

TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple ) {
	strcpy(villeDepart, unTrajetSimple.villeDepart);
	strcpy(villeArrivee, unTrajetSimple.villeArrivee);
	strcpy(moyTrans, unTrajetSimple.moyTrans);
}
	
void TrajetSimple::afficher() const {
	cout << "de" << villeDepart << " jusqu'a " << villeArrivee << " en " << moyTrans << "\r\n";
}
TrajetSimple::~TrajetSimple() {
//	delete[] moyTrans;
}
