#ifndef CATALOGUE_H
#define CALALOGUE_H
#include "ListeTrajet.h"
#include "Trajet.h"
#include <cstring>
class Catalogue {
	
public:
	Catalogue();
	Catalogue(const Catalogue&);
	void ajouter_trajet(Trajet*);
	void rechercher( const char* , const char* );
	void afficher();
	~Catalogue();
	
private:
	ListeTrajet* listeTrajet;
};

#endif
