/*************************************************************************
                           ListeTrajet  -  une liste chainee de trajets
                             -------------------
    début                : 23 novembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajet> (fichier ListeTrajet.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstring>
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "ListeTrajet.h"
//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur
ListeTrajet::ListeTrajet() {
	head = new NodeTrajet();
#ifdef MAP
    cout << "Appel au constructeur de <ListeTrajet>" << endl;
#endif	
} //-------- Fin de ListeTrajet

//----------------------------------------------------- Méthodes publiques

NodeTrajet* ListeTrajet::getLastNode() {	
	NodeTrajet* p;
	p = head;
	while(p->next != NULL) {
		p = p->next;
	}
	return p;
} //-------- Fin de Methode

void ListeTrajet::ajouter_en_queue(Trajet* trajet) {
	if (head->trajet->GetVille(1)[0] == '\0') {
		head = new NodeTrajet();
		head->trajet = trajet;
		head->next = nullptr;
	}
	else {
		NodeTrajet* p;
		p = head;
		while(p->next != NULL) {
			p = p->next;
		}
		NodeTrajet* q = new NodeTrajet();
		q->trajet = trajet;
		q->next = nullptr;
		p->next = q; 
	}	
} //-------- Fin de Methode

void ListeTrajet::getVille(char* villeStart, char* villeFinish) {
	char* uneVilleStart = new char [50];
	char* uneVilleFinish = new char [50];
	head->trajet->GetTrajet(uneVilleStart, uneVilleFinish);
	strcpy(villeStart, uneVilleStart);
	NodeTrajet* p = head;
	while(p->next != nullptr)
		p = p->next;
	p->trajet->GetTrajet(uneVilleStart, uneVilleFinish);
	strcpy(villeFinish, uneVilleFinish);
} //-------- Fin de Methode

int ListeTrajet::size() {
	int size = 0;
	NodeTrajet* p = head;
	if (head->trajet->GetVille(1)[0] == '\0') return 0;
	else {
		while (p != nullptr) {
			size++;
			p = p->next;
		}
		return size;
	}
} //-------- Fin de Methode

void ListeTrajet::afficher() {
	NodeTrajet* p = head;
	while (p != nullptr) {
		p->trajet->afficher(1);
		p = p->next;
	}
} //-------- Fin de Methode

//-------------------------------------------- Constructeurs - destructeur
ListeTrajet::~ListeTrajet() {
	delete head;
#ifdef MAP
    cout << "Appel au destructeur de <ListeTrajet>" << endl;
#endif
} //----- Fin de ~ListeTrajet
