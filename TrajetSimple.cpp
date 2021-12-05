/*************************************************************************
                           TrajetSimple
                             -------------------
    début                : 23 novembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple () {
	moyTrans = new char[50];
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //------ Fin de TrajetSimple

TrajetSimple::TrajetSimple(const char* villeDepart,const char* villeArrivee, const char* unMoyTrans)
: Trajet(villeDepart, villeArrivee) {
	moyTrans = new char[50];
	strcpy (moyTrans, unMoyTrans);
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //------ Fin de TrajetSimple

TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple ) {
	strcpy(villeDepart, unTrajetSimple.villeDepart);
	strcpy(villeArrivee, unTrajetSimple.villeArrivee);
	strcpy(moyTrans, unTrajetSimple.moyTrans);
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
} //------ Fin de TrajetSimple (constructeur de copie)

TrajetSimple::~TrajetSimple() {
	delete[] moyTrans;
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //------ Fin de ~TrajetSimple

//----------------------------------------------------- Méthodes publiques

char* TrajetSimple::GetVille(const int i) const{
	return Trajet::GetVille(i);
} // ------- Fin de Methode

void TrajetSimple::GetTrajet( char* villeStart, char* villeFinish) const{
	Trajet::GetTrajet(villeStart , villeFinish);
} // ------- Fin de Methode
	
void TrajetSimple::Afficher(const int i) const {
	if (i == 1) {
		cout << "TS: "; 
		Trajet::Afficher(i);
		cout << " en " << moyTrans;
		cout << endl;
	}else{
		Trajet::Afficher(i);
		cout << " en " << moyTrans;
	}
} // ------- Fin de Methode

