using namespace std;
#include <iostream>
#include <cstring>
#include "TrajetCompose.h"

TrajetCompose::TrajetCompose() {
	listeSimple = new ListeTrajet();
}

int TrajetCompose::ajouter(TrajetSimple* unTS) {
	int i =0;
	if (listeSimple->head->trajet->GetVille(1)[0] == '\0') {
		strcpy(villeDepart, unTS->GetVille(1));
		listeSimple->ajouter_en_queue(unTS);
		strcpy(villeArrivee, unTS->GetVille(2));
		i =1;
	}else{
		NodeTrajet* p = listeSimple->getLastNode();
		if (strcmp(p->trajet->GetVille(2), unTS->GetVille(1)) ==0) {
			listeSimple->ajouter_en_queue(unTS);
			strcpy(villeArrivee, unTS->GetVille(2));
			i =1;
		}
	}
	return i;
}

TrajetCompose::TrajetCompose(const TrajetCompose & unTC) {
	strcpy(villeDepart, unTC.villeDepart);
	strcpy(villeArrivee, unTC.villeArrivee);
	this->listeSimple->head = unTC.listeSimple->head; 
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
	delete p;	
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
	delete p;
}

TrajetCompose::~TrajetCompose() {
	delete listeSimple;	
}
