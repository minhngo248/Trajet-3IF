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

Trajet::Trajet (const char* uneVilleDepart, const char* uneVilleArrivee) {
	villeDepart = new char[50];
	villeArrivee = new char[50];
	strcpy (villeDepart, uneVilleDepart);
	strcpy (villeArrivee, uneVilleArrivee);
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //------ Fin de Trajet

Trajet::Trajet (const Trajet & unTrajet) {
	strcpy(villeDepart, unTrajet.villeDepart);
	strcpy(villeArrivee, unTrajet.villeArrivee);
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
} //----- Fin de Trajet (constructeur de copie)

Trajet::~Trajet() {
	delete[] villeDepart;
	delete[] villeArrivee;
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //------ Fin de ~Trajet

//----------------------------------------------------- Méthodes publiques
void Trajet::GetTrajet( char* villeStart, char* villeFinish ) const{
	strcpy(villeStart , villeDepart);
	strcpy(villeFinish, villeArrivee);
} // ------- Fin de Methode

char* Trajet::GetVille(int i) const{
	if (i == 1) {
		return this->villeDepart;
	}
	return this->villeArrivee;
} // ------- Fin de Methode
	
void Trajet::Afficher(const int i) const {
	cout << "de " << villeDepart << " a " << villeArrivee;  
} // ------- Fin de Methode

