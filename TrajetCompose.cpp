using namespace std;
#include <iostream>
#include <cstring>
#include "TrajetSimple.h"
#include "TrajetCompose.h"

TrajetCompose::TrajetCompose() {
	
}

void TrajetCompose::ajouter(TrajetSimple unTS) {
	listeSimple.ajouter_en_queue(unTS);
}

TrajetCompose::TrajetCompose(const TrajetCompose & unTrajetCompose) {
	strcpy(villeDepart, unTrajetCompose.villeDepart);
	strcpy(villeArrivee, unTrajetCompose.villeArrivee);
	this->listeSimple.head = unTrajetCompose.listeSimple.head;
}


void TrajetCompose::afficher() const {
	NodeTrajet* p = listeSimple.head;
	while (p != NULL) {
		p->trajet.afficher();
		if (p->next != NULL) {
			cout << " - ";
		}
		p = p->next;
	} 
}

TrajetCompose::~TrajetCompose() {
	listeSimple.~ListeTrajet();	
}
