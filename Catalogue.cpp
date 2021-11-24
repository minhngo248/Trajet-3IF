#include <iostream>
using namespace std;
#include "Catalogue.h"

Catalogue::Catalogue() {
	listeTrajet = nullptr;
}

void Catalogue::ajouter_trajet(Trajet *trajet) {
	if (listeTrajet == nullptr) {
		listeTrajet = new ListeTrajet();
		listeTrajet->ajouter_en_queue(trajet);
		//listeTrajet->head = new NodeTrajet();
		//listeTrajet->head->trajet = trajet;
	}
	else {
		listeTrajet->ajouter_en_queue(trajet);
	}
}

/*void Catalogue::rechercher() {
	
} */

void Catalogue::afficher() {
	listeTrajet->afficher();
}

Catalogue::~Catalogue() {
	delete listeTrajet;
}
