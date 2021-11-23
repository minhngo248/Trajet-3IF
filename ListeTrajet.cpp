using namespace std;
#include <iostream>
#include "ListeTrajet.h"

//------ Constructeurs - destructeur
ListeTrajet::ListeTrajet() {
	head = new NodeTrajet();
	head = NULL;	
}

void ListeTrajet::ajouter_en_tete(Trajet trajet) {
	if (head == NULL) {
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
}

void ListeTrajet::ajouter_en_queue(Trajet trajet) 
{
	NodeTrajet* p = new NodeTrajet();
	p = head;
	while(p->next != NULL) {
		p = p->next;
	}
	NodeTrajet* q = new NodeTrajet();
	q->trajet = trajet;
	q->next = NULL;
	p->next = q;	
}

void ListeTrajet::afficher() {
	NodeTrajet* p = head;
	while (p != NULL) {
	//	printf("%d\t", p->value);
		p = p->next;
	}
}

void ListeTrajet::supprimer(Trajet trajet) {
	NodeTrajet* p = new NodeTrajet();
	if (head->trajet == trajet) {
		head = head->next;
	}
	p = head;
	while(p->next != NULL) {
		if(p->next->trajet == trajet) {
			NodeTrajet* q = new NodeTrajet();
			q = p->next;
			p->next = q->next;
			delete q;
		}
		p = p->next;
	}
}


ListeTrajet::~ListeTrajet() {
	NodeTrajet* p;
	p = head;
	while (p != NULL) {
		p->trajet.~Trajet();
		p = p->next;
	}
	delete head;
}
