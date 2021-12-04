/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 23 novembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ------
#ifndef CATALOGUE_H
#define CALALOGUE_H
#include "ListeTrajet.h"
#include "Trajet.h"
#include <cstring>
// Rôle de la classe <Catalogue>
// Gestion du Catalogue
//------------------------------------------------------------------------ 
class Catalogue {
//----------------------------------------------------------------- PUBLIC	
public:
//----------------------------------------------------- Méthodes publiques
	
	void ajouter_trajet(Trajet*);
    // Mode d'emploi : ajouter des trajets dans le catalogue
    //
	void rechercher( const char* , const char* );
    // Mode d'emploi : recherche simple des trajets possibles
    //	a partir de la Ville du Depart et de la Ville Arrivee
	void creer_liste_avancee(int&);
    // Mode d'emploi : creation d'une ListeTrajetAvance en reliant
	// des trajets ayant la meme nom de tete que celui de queue de
	// son noeud precedant  	
	void recherche_avancee(const char* , const char*);
    // Mode d'emploi : parcourir tous les elements dans la
	// listeTrajetAvance pour chercher des trajets appropries
	// a partir d'une VilleDepart et d'une VilleArrivee 	
	void afficher();
	// Mode d'emploi : afficher tous les trajets dans le catalogue
	
//-------------------------------------------- Constructeurs - destructeur 
	Catalogue();
	// Mode d'emploi (constructeur) : allocation des memoires pour la 
    // listeTrajet et listeTrajetAvance
    // 
	Catalogue(const Catalogue&); 
	// Mode d'emploi (constructeur de copie) : 
    // 
    //		
	~Catalogue();
	// Mode d'emploi (destructeur) : desallocation des memoires de la  
    // listeTrajet et de la listeTrajetAvance
    //
	
private:
//------------------------------------------------------------------ PRIVE
	ListeTrajet* listeTrajet; 
	//stokage tous les trajets du catalogue
	ListeTrajet* listeTrajetAvance; 
	//stokage tous les trajets reliables du catalogue
};

#endif // ! defined (CATALOGUE_H)
