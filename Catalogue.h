#ifndef CATALOGUE_H
#define CALALOGUE_H
#include "ListeTrajet.h"
#include "Trajet.h"
class Catalogue {
	
public:
	Catalogue();
	void ajouter_trajet(Trajet*);
//	void rechercher(char* uneVilleDepart, char* uneVilleArrivee);
	void afficher();
	~Catalogue();
	
private:
	ListeTrajet* listeTrajet;
};

#endif
