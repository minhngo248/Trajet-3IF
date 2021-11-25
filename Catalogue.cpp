#include <iostream>
using namespace std;
#include "Catalogue.h"

Catalogue::Catalogue() {
	
}

void Catalogue::ajouter_trajet(Trajet trajet) {
	listeTrajet.ajouter_en_queue(trajet);
}

/*void Catalogue::rechercher() {
	
} */

void Catalogue::afficher() {
	listeTrajet.afficher();
}

Catalogue::~Catalogue() {
	
}
