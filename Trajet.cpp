/*************************************************************************
                           Trajet
                             -------------------
    début                : 23 novembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"
//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet() {
	villeDepart = new char[50];
	villeArrivee = new char[50];
} // ------ Fin du Constructeur

Trajet::Trajet (const char* uneVilleDepart, const char* uneVilleArrivee) {
	villeDepart = new char[50];
	villeArrivee = new char[50];
	strcpy (villeDepart, uneVilleDepart);
	strcpy (villeArrivee, uneVilleArrivee);
} // ------ Fin du Constructeur

Trajet::Trajet (const Trajet & unTrajet) {
	strcpy(villeDepart, unTrajet.villeDepart);
	strcpy(villeArrivee, unTrajet.villeArrivee);
} // ------- Fin du Constructeur

//----------------------------------------------------- Méthodes publiques
void Trajet::GetTrajet( char* villeStart, char* villeFinish ) {
	strcpy(villeStart , villeDepart);
	strcpy(villeFinish, villeArrivee);
} // ------- Fin de Methode

char* Trajet::GetVille(int i) {
	if (i == 1) {
		return this->villeDepart;
	}
	return this->villeArrivee;
} // ------- Fin de Methode
	
void Trajet::afficher(const int i) const {
	cout << "de " << villeDepart << " a " << villeArrivee;  
} // ------- Fin de Methode
	
//-------------------------------------------- Constructeurs - destructeur	
Trajet::~Trajet() {
	delete[] villeDepart;
	delete[] villeArrivee;
} // ----- Fin du Destructeur
