#include <iostream>
using namespace std;
#include "Catalogue.h"

Catalogue::Catalogue() {
	listeTrajet = new ListeTrajet();
}

void Catalogue::ajouter_trajet(Trajet* trajet) {
	listeTrajet->ajouter_en_queue(trajet);
}

void Catalogue::rechercher(const char* uneVilleDepart, const char* uneVilleArrivee) {
	NodeTrajet* p = listeTrajet->head;
	char* villeStart;
	char* villeFinish;
	while (p != NULL) {
		villeStart = new char [50];
		villeFinish = new char [50];
		p->trajet->GetTrajet(villeStart , villeFinish);
		if (strcmp(villeStart , uneVilleDepart) == 0 && strcmp(villeFinish,uneVilleArrivee) == 0) {
			p->trajet->afficher(1);	
		}
		p = p->next;
	}
}

void Catalogue::afficher() {
	listeTrajet->afficher();
	cout << endl;
}

Catalogue::~Catalogue() {
	delete listeTrajet;
}
