#include <cstring>
using namespace std;
#include <iostream>
#include "ListeTrajet.h"

//------ Constructeurs - destructeur
ListeTrajet::ListeTrajet() {
	head = new NodeTrajet();	
}

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
}

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
}

void ListeTrajet::afficher() {
	NodeTrajet* p = head;
	while (p != nullptr) {
		p->trajet->afficher(1);
		p = p->next;
	}
}

ListeTrajet::~ListeTrajet() {
	delete head;
}
