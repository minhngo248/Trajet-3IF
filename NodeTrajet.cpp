/*************************************************************************
                           NodeTrajet
                             -------------------
    d�but                : 23 novembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- R�alisation de la classe <NodeTrajet> (fichier NodeTrajet.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "NodeTrajet.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur

NodeTrajet::NodeTrajet() {
	next = nullptr;
	trajet = new Trajet();
} //------ Fin du Constructeur

NodeTrajet::~NodeTrajet() {
	delete trajet;
	if(this->next != nullptr) {
		delete next;
	}
} //------- Fin du Destructeur 
