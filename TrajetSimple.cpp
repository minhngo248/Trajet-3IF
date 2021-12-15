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

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple () {
	moyTrans.assign("\0");
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //------ Fin de TrajetSimple

TrajetSimple::TrajetSimple(const string villeDepart,const string villeArrivee, const string unMoyTrans)
: Trajet(villeDepart, villeArrivee) {
	moyTrans = unMoyTrans;
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //------ Fin de TrajetSimple

TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple ) {
	villeDepart = unTrajetSimple.villeDepart;
	villeArrivee = unTrajetSimple.villeArrivee;
	moyTrans = unTrajetSimple.moyTrans;
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
} //------ Fin de TrajetSimple (constructeur de copie)

TrajetSimple::~TrajetSimple() {
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //------ Fin de ~TrajetSimple

//----------------------------------------------------- Méthodes publiques

string TrajetSimple::GetVille(const int i) const{
	return Trajet::GetVille(i);
} // ------- Fin de Methode

void TrajetSimple::GetTrajet( string& villeStart, string& villeFinish) const{
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

