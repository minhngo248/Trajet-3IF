using namespace std;
#include <iostream>
#include <cstring>
#include "TrajetCompose.h"

TrajetCompose::TrajetCompose() {
	listeSimple = new ListeTrajet();
}

void TrajetCompose::ajouter(TrajetSimple* unTS) {
	if (listeSimple->head->trajet->GetVille(1)[0] == '\0') {
		strcpy(villeDepart, unTS->GetVille(1));
	}
	listeSimple->ajouter_en_queue(unTS);
	strcpy(villeArrivee, unTS->GetVille(2));
}

TrajetCompose::TrajetCompose(const TrajetCompose & unTC) {
/*	strcpy(villeDepart, unTC.villeDepart);
	strcpy(villeArrivee, unTC.villeArrivee);
	this->listeSimple->head = unTC.listeSimple->head; */
}

void TrajetCompose::GetTrajet( char* villeStart , char* villeFinish ) {
	NodeTrajet* p = listeSimple->head;
	if (listeSimple->head->trajet->GetVille(1)[0] != '\0') {
		strcpy(villeStart, p->trajet->GetVille(1));
		while(p->next != nullptr) {
			p = p->next;
		}
		strcpy(villeFinish , p->trajet->GetVille(2));
	}	
}

void TrajetCompose::afficher(const int i) const {
	cout << "TC: ";
	NodeTrajet* p = listeSimple->head;
	while (p != NULL) {
		p->trajet->afficher(0);
		if (p->next != NULL) {
			cout << " - ";
		}
		p = p->next;
	} 
	cout << endl;
}

TrajetCompose::~TrajetCompose() {
	delete listeSimple;	
}
