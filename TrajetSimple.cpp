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
	this->moyTrans = "\0";
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //------ Fin de TrajetSimple

TrajetSimple::TrajetSimple(const string uneVilleDepart,const string uneVilleArrivee, const string unMoyTrans)
: Trajet(uneVilleDepart, uneVilleArrivee) {
	this->moyTrans = unMoyTrans;
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //------ Fin de TrajetSimple

TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple ):Trajet(unTrajetSimple) 
{
	this->moyTrans = unTrajetSimple.moyTrans;
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

void TrajetSimple::FicWrite(ofstream & fic , const int i) {
	if (i == 1) {
		fic << "TS: "; 
		Trajet::FicWrite(fic,i);
		fic << ", " << moyTrans;
		fic << endl;
	}else{
		Trajet::FicWrite(fic,i);
		fic << ", " << moyTrans;
	}
} // ------- Fin de Methode

