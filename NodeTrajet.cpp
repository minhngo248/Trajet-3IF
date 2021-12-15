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
	cout << "Constructeur NodeTrajet" << endl;
#ifdef MAP
    cout << "Appel au constructeur de <NodeTrajet>" << endl;
#endif
} //------ Fin de NodeTrajet

NodeTrajet::NodeTrajet(const NodeTrajet& unNT) {
	next = nullptr;
	trajet = new Trajet();
	trajet = unNT.GetTrajet();
#ifdef MAP
    cout << "Appel au constructeur de copie de <NodeTrajet>" << endl;
#endif
} //----- Fin de NodeTrajet (constructeur de copie)

NodeTrajet::~NodeTrajet() {
	delete trajet;
	if(next != nullptr) {
		delete next;
	}
	cout << "Destructeur NodeTrajet" << endl;
#ifdef MAP
    cout << "Appel au destructeur de <NodeTrajet>" << endl;
#endif
} //------ Fin de ~NodeTrajet 

//----------------------------------------------------- M�thodes publiques

Trajet* NodeTrajet::GetTrajet() const{
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
