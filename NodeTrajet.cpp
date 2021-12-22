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
	trajet = new Trajet();
	this->next = nullptr;
#ifdef MAP
    cout << "Appel au constructeur de <NodeTrajet>" << endl;
#endif
} //------ Fin de NodeTrajet

NodeTrajet::NodeTrajet(const NodeTrajet& unNT):trajet(unNT.trajet) 
{
	next = nullptr;
#ifdef MAP
    cout << "Appel au constructeur de copie de <NodeTrajet>" << endl;
#endif
} //----- Fin de NodeTrajet (constructeur de copie)

NodeTrajet::~NodeTrajet() {
	delete trajet;
	if(this->next != nullptr) {
		delete next;
	}
#ifdef MAP
    cout << "Appel au destructeur de <NodeTrajet>" << endl;
#endif
} //------ Fin de ~NodeTrajet 

//----------------------------------------------------- Méthodes publiques

Trajet* NodeTrajet::GetTrajet() {
	return this->trajet;
} //-------- Fin de Methode

NodeTrajet* NodeTrajet::GetNext() const{
	return this->next;
} //-------- Fin de Methode

void NodeTrajet::SetTrajet(Trajet* t){
	this->trajet = t;
} //-------- Fin de Methode

void NodeTrajet::SetNext(NodeTrajet* n) {
	this->next = n;
} //-------- Fin de Methode
