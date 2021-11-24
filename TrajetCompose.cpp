using namespace std;
#include <iostream>
#include <cstring>

#include "TrajetCompose.h"

TrajetCompose::TrajetCompose() {
	listeSimple = new ListeTrajet();
}

TrajetCompose::ajouter(TrajetSimple unTS) {
	listeSimple->ajouter_en_queue(unTS);
}

TrajetCompose::TrajetCompose(const TrajetCompose & unTrajetCompose) {
	strcpy(villeDepart, unTrajetCompose.villeDepart);
	strcpy(villeArrivee, unTrajetCompose.villeArrivee);
	
	this->listeSimple.head = unTrajetCompose.listeSimple.head;
}


void afficher() const {
	NodeTrajet* p = listeSimple->head;
	while (p != NULL) {
		p->trajet.afficher();
		if (p->next != NULL) {
			cout << " - ";
		}
	} 
}

TrajetCompose::~TrajetCompose() {
	delete[] villeDepart;
	delete[] villeArrivee;
	listeSimple.~ListeTrajet();	
}
