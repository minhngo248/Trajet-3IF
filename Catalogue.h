#ifndef CATALOGUE_H
#define CALALOGUE_H
#include "ListeTrajet.h"
#include "Trajet.h"
#include <cstring>
class Catalogue {
	
public:
	Catalogue();
	Catalogue(const Catalogue&); //constructeur de copie
	void ajouter_trajet(Trajet*);
	void rechercher( const char* , const char* );
	
	void creer_liste_avancee(int&);
	void recherche_avancee(const char* , const char*);
	void afficher();
	void affiche_toute_avancee();
	~Catalogue();
	
private:
	ListeTrajet* listeTrajet;
	ListeTrajet* listeTrajetAvance;
};

#endif
