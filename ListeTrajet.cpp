/*************************************************************************
                           ListeTrajet  -  une liste chainee de trajets
                             -------------------
    début                : 23 novembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajet> (fichier ListeTrajet.cpp) -------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
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

ListeTrajet::ListeTrajet(const ListeTrajet& unLT) {
	head = new NodeTrajet();
	head = unLT.GetHead();
#ifdef MAP
    cout << "Appel au constructeur de copie de <ListeTrajet>" << endl;
#endif
} //----- Fin de ListeTrajet (constructeur de copie)

ListeTrajet::~ListeTrajet() {
	delete head;
#ifdef MAP
    cout << "Appel au destructeur de <ListeTrajet>" << endl;
#endif
} //----- Fin de ~ListeTrajet

//----------------------------------------------------- Méthodes publiques

NodeTrajet* ListeTrajet::GetLastNode() const{	
	NodeTrajet* p;
	p = head;
	while(p->GetNext()!= NULL) {
		p = p->GetNext();
	}
	return p;
} //-------- Fin de Methode

void ListeTrajet::Ajouter_en_queue(Trajet* unTrajet) {
	if (head->GetTrajet()->GetVille(1)[0] == '\0') {
		head = new NodeTrajet();
		head->SetTrajet(unTrajet);
		head->SetNext(nullptr);
	}
	else {
		NodeTrajet* p;
		p = GetLastNode();
		NodeTrajet* q = new NodeTrajet();
		q->SetTrajet(unTrajet);
		q->SetNext(nullptr);
		p->SetNext(q); 
	}	
} //-------- Fin de Methode

void ListeTrajet::GetVille(string villeStart, string villeFinish) const{
	string uneVilleStart;
	string uneVilleFinish;
	head->GetTrajet()->GetTrajet(uneVilleStart, uneVilleFinish);
	villeStart = uneVilleStart;
	NodeTrajet* p = head;
	while(p->GetNext() != nullptr)
		p = p->GetNext();
	p->GetTrajet()->GetTrajet(uneVilleStart, uneVilleFinish);
	villeFinish = uneVilleFinish;
} //-------- Fin de Methode

int ListeTrajet::Size() {
	int size = 0;
	NodeTrajet* p = head;
	if (head->GetTrajet()->GetVille(1)[0] == '\0') return 0;
	else {
		while (p != nullptr) {
			size++;
			p = p->GetNext();
		}
		return size;
	}
} //-------- Fin de Methode

void ListeTrajet::Afficher() const{
	bool b = true;
	NodeTrajet* p = head;
	while (p != nullptr && p->GetTrajet()->GetVille(1)[0] != '\0') {
		p->GetTrajet()->Afficher(1);
		p = p->GetNext();
		b = false;
	}
	if (b) {
		cout << "Il n'y a accun trajet.";
	}
} //-------- Fin de Methode

NodeTrajet* ListeTrajet:: GetHead() const{
	return this->head;
} // ------- Fin de Methode

void ListeTrajet::SetHead(NodeTrajet* n) {
	this->head = n;
} // ------- Fin de Methode

