using namespace std;
#include <iostream>
#include <cstring>

#include "TrajetSimple.h"


TrajetSimple::TrajetSimple () {
	moyTrans = new char[50];
}

/*void TrajetSimple::SetTrajet(const char* uneVilleDepart,const char* uneVilleArrivee, const char* unMoyTrans) {
	strcpy(villeDepart, uneVilleDepart);
	strcpy(villeArrivee, uneVilleArrivee);
	strcpy(moyTrans, unMoyTrans);
}*/

TrajetSimple::TrajetSimple(const char* villeDepart,const char* villeArrivee, const char* unMoyTrans)
: Trajet(villeDepart, villeArrivee) {
	moyTrans = new char[50];
	strcpy (moyTrans, unMoyTrans);
}

TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple ) {
	strcpy(villeDepart, unTrajetSimple.villeDepart);
	strcpy(villeArrivee, unTrajetSimple.villeArrivee);
	strcpy(moyTrans, unTrajetSimple.moyTrans);
}

char* TrajetSimple::GetVille(const int i) {
	return Trajet::GetVille(i);
}

void TrajetSimple::GetTrajet( char* villeStart, char* villeFinish) {
	Trajet::GetTrajet(villeStart , villeFinish);
}
	
void TrajetSimple::afficher(const int i) const {
	if (i == 1) {
		cout << "TS: "; 
		Trajet::afficher(i);
		cout << " en " << moyTrans;
		cout << endl;
	}else{
		Trajet::afficher(i);
		cout << " en " << moyTrans;
	}
}
TrajetSimple::~TrajetSimple() {
	delete[] moyTrans;
}
