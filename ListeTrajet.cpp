//#include <cstring>
using namespace std;
#include <iostream>
#include "ListeTrajet.h"

//------ Constructeurs - destructeur
ListeTrajet::ListeTrajet() {
	head = new NodeTrajet();	
}

ListeTrajet::ListeTrajet(const ListeTrajet& unLT) {
	head = new NodeTrajet();
	head = unLT.head;
}

NodeTrajet* ListeTrajet::getLastNode() {	
	NodeTrajet* p;
	p = head;
	while(p->next != NULL) {
		p = p->next;
	}
	return p;
}

void ListeTrajet::ajouter_en_queue(Trajet* unTrajet) {
	if (head->trajet->GetVille(1)[0] == '\0') {
		head->trajet = unTrajet;
		head->next = nullptr;
	}else{
		NodeTrajet* p;
		p = this->getLastNode();
		NodeTrajet* q = new NodeTrajet();
		q->trajet = unTrajet;
		q->next = nullptr;
		p->next = q; 
	}
	
}

void ListeTrajet::afficher() {
	bool b = true;
	
	NodeTrajet* p = head;
	while (p != nullptr && p->trajet->GetVille(1)[0] != '\0' ) { //afficher que les trajets simples
		p->trajet->afficher(1);
		p = p->next;
		b = false;
	}
	
	if (b) {
		cout << "Il n'y a accun trajet." <<endl;
	}
	delete p;
}

/*void ListeTrajet::supprimer(Trajet unT) {
	NodeTrajet* p = new NodeTrajet();
	if (strcmp(head->trajet.villeDepart,unT.villeDepart)) {
		head = head->next;
	}
	p = head;
	while(p->next != NULL) {
		if(p->next->trajet == unT) {
			NodeTrajet* q = new NodeTrajet();
			q = p->next;
			p->next = q->next;
			delete q;
		}
		p = p->next;
	}
}*/


ListeTrajet::~ListeTrajet() {
	delete head;
}
