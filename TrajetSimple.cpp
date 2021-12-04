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
} // -------- Fin du Constructeur

TrajetSimple::TrajetSimple(const char* villeDepart,const char* villeArrivee, const char* unMoyTrans)
: Trajet(villeDepart, villeArrivee) {
	moyTrans = new char[50];
	strcpy (moyTrans, unMoyTrans);
} // -------- Fin du Constructeur

TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple ) {
	strcpy(villeDepart, unTrajetSimple.villeDepart);
	strcpy(villeArrivee, unTrajetSimple.villeArrivee);
	strcpy(moyTrans, unTrajetSimple.moyTrans);
} // -------- Fin du Constructeur

//----------------------------------------------------- Méthodes publiques

char* TrajetSimple::GetVille(const int i) {
	return Trajet::GetVille(i);
} // ------- Fin de Methode

void TrajetSimple::GetTrajet( char* villeStart, char* villeFinish) {
	Trajet::GetTrajet(villeStart , villeFinish);
} // ------- Fin de Methode
	
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
} // ------- Fin de Methode

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::~TrajetSimple() {
	delete[] moyTrans;
} // ------- Fin du Destructeur
