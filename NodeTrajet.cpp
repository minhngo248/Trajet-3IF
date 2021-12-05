/*************************************************************************
                           NodeTrajet
                             -------------------
    début                : 23 novembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- Réalisation de la classe <NodeTrajet> (fichier NodeTrajet.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "NodeTrajet.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur

NodeTrajet::NodeTrajet() {
	next = nullptr;
	trajet = new Trajet();
#ifdef MAP
    cout << "Appel au constructeur de <NodeTrajet>" << endl;
#endif
} //------ Fin de NodeTrajet

NodeTrajet::~NodeTrajet() {
	delete trajet;
	if(this->next != nullptr) {
		delete next;
	}
#ifdef MAP
    cout << "Appel au destructeur de <NodeTrajet>" << endl;
#endif
} //------ Fin de ~NodeTrajet 
