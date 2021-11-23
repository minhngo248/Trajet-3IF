using namespace std;
#include <iostream>
#include <cstring>

#include <TrajetCompose.h>

TrajetCompose::TrajetCompose() {
	
}

TrajetCompose::TrajetCompose(const TrajetSimple trajetA, const TrajetSimple trajetB) {
	bool b = true;
	if (strcmp(trajetA.villeArrivee, trajetB.villeDepart) == 0) {
		b = false;
		strcpy(this->villeDepart, trajetA.villeDepart);
		strcpy(this->villeArrivee, trajetB.villeArrivee);
		
		listeSimple.ajouter_en_tete(trajetB);
		listeSimple.ajouter_en_tete(trajetA);
	}
	if (strcmp(trajetA.villeDepart, trajetB.villeArrivee) == 0) {
		b = false;
		
		strcpy(this->villeDepart, trajetB.villeDepart);
		strcpy(this->villeArrivee, trajetA.villeArrivee);
		
		listeSimple.ajouter_en_tete(trajetA);
		listeSimple.ajouter_en_tete(trajetB);
	}
	
	if (b) {
		cout << "Erreur en créant un trajet composé\r\n";
	}
}

TrajetCompose::TrajetCompose(const TrajetCompose & unTrajetCompose) {
	strcpy(villeDepart, unTrajetCompose.villeDepart);
	strcpy(villeArrivee, unTrajetCompose.villeArrivee);
	
	this->listeSimple.head = unTrajetCompose.listeSimple.head;
}

TrajetCompose::~TrajetCompose() {
	Trajet::~Trajet();
	listeSimple.~ListeTrajet();

	
}
