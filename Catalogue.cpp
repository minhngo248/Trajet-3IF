#include <iostream>
using namespace std;
#include "Catalogue.h"

Catalogue::Catalogue() {
	listeTrajet = new ListeTrajet();
}

void Catalogue::ajouter_trajet(Trajet* trajet) {
	listeTrajet->ajouter_en_queue(trajet);
}

/*void Catalogue::rechercher() {
	
} */

void Catalogue::afficher() {
	listeTrajet->afficher();
	cout << endl;
}

Catalogue::~Catalogue() {
	delete listeTrajet;
}
