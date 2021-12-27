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

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"
//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet() {
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //------ Fin de Trajet

Trajet::Trajet (const string uneVilleDepart, const string uneVilleArrivee) {
	this->villeDepart = uneVilleDepart;
	this->villeArrivee = uneVilleArrivee;
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //------ Fin de Trajet

Trajet::Trajet (const Trajet & unTrajet) {
	this->villeDepart = unTrajet.villeDepart;
	this->villeArrivee = unTrajet.villeArrivee;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
} //----- Fin de Trajet (constructeur de copie)

Trajet::~Trajet() {

#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //------ Fin de ~Trajet

//----------------------------------------------------- Méthodes publiques
void Trajet::GetTrajet( string& villeStart, string& villeFinish ) const{
	villeStart = this->villeDepart;
	villeFinish = this->villeArrivee;
} // ------- Fin de Methode

string Trajet::GetVille(int i) const{
	if (i == 1) {
		return this->villeDepart;
	}
	return this->villeArrivee;
} // ------- Fin de Methode
	
void Trajet::Afficher(const int i) const {
	cout << "de " << villeDepart << " a " << villeArrivee;  
} // ------- Fin de Methode

void Trajet::FicWrite(ofstream & fic , const int i) {
	fic << villeDepart << ", " << villeArrivee;
} // ------- Fin de Methode


