//#include <cstring>
using namespace std;
#include <iostream>
#include "ListeTrajet.h"

//------ Constructeurs - destructeur
ListeTrajet::ListeTrajet() {
	head = new NodeTrajet();	
}

/*void ListeTrajet::ajouter_en_tete(Trajet* trajet) {
	if (head == NULL) {
		head = new NodeTrajet();
		head->trajet = trajet;
		head->next = NULL;
	}
	else {
		NodeTrajet* p = new NodeTrajet();
		p->trajet = trajet;
		p->next = head;
		head = p;
	}
}

void ListeTrajet::rechercher ( Trajet trajet ) {
	int i=0;
	NodeTrajet* p = new NodeTrajet();
	p = head;

	while (p != NULL) {
		if (p->trajet == trajet) {
			printf("pos : %d\n", i);
		}
		p = p->next;
		i++;
	}
}*/

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
}

void ListeTrajet::afficher() {
	NodeTrajet* p = head;
	while (p != nullptr) { //afficher que les trajets simples
		p->trajet->afficher(1);
		p = p->next;
	}
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
