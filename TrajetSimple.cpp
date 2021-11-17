using namespace std;
#include <iostream>
#include <cstring>

#include "TrajetSimple.h"

TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple ) {
	strcpy(villeDepart, unTrajetSimple.villeDepart);
	strcpy(villeArrivee, unTrajetSimple.villeArrivee);
	strcpy(moyTrans, unTrajetSimple.moyTrans);
}


TrajetSimple::TrajetSimple () {
	
}

TrajetSimple(const char* villeDepart,const char* villeArrivee,const char* unMoyTrans): Trajet(villeDepart, villeArrivee), moyTrans(unMoyTrans) {
	strcpy (moyTrans, unMoyTrans);
}
	

TrajetSimple::~TrajetSimple () {
	Trajet::~Trajet();
	delete[] moyTrans;
} 

