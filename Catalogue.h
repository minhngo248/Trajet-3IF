/*************************************************************************
                           Catalogue
                             -------------------
    d�but                : 23 novembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ------
#ifndef CATALOGUE_H
#define CALALOGUE_H
#include "ListeTrajet.h"
#include "Trajet.h"
#include <string>
// R�le de la classe <Catalogue>
// Gestion du Catalogue
//------------------------------------------------------------------------ 
class Catalogue {
//----------------------------------------------------------------- PUBLIC	
public:
//----------------------------------------------------- M�thodes publiques
	
	void Ajouter_trajet(Trajet*);
    // Mode d'emploi : ajouter des trajets dans le catalogue
    //
	void Rechercher( const string , const string ) const;
    // Mode d'emploi : recherche simple des trajets possibles
    //	a partir de la Ville du Depart et de la Ville Arrivee  	
	void Recherche_avancee(const string , const string) ;
    // Mode d'emploi : parcourir tous les elements dans la
	// listeTrajetAvance pour chercher des trajets appropries
	// a partir d'une VilleDepart et d'une VilleArrivee 	
	ListeTrajet* GetList() const;
	//
	void Afficher() const;
	// Mode d'emploi : afficher tous les trajets dans le catalogue
	
//-------------------------------------------- Constructeurs - destructeur 
	Catalogue();
	// Mode d'emploi (constructeur) : allocation des memoires pour la 
    // listeTrajet et listeTrajetAvance
    // 
	Catalogue(const Catalogue&); 
	// Mode d'emploi (constructeur de copie) : Cr�er une copie d'une catalogue
    // 
    //		
	~Catalogue();
	// Mode d'emploi (destructeur) : desallocation des memoires de la  
    // listeTrajet et de la listeTrajetAvance
    //
    
//------------------------------------------------------------------ PRIVE	
private:
//------------------------------------------------------- M�thodes priv�es
	void creer_liste_avancee(int&);
    // Mode d'emploi : creation d'une ListeTrajetAvance en reliant
	// des trajets ayant la meme nom de tete que celui de queue de
	// son noeud precedant

	ListeTrajet* listeTrajet; 
	//stokage de tous les trajets du catalogue
	ListeTrajet* listeTrajetAvance; 
	//stokage de tous les trajets reliables du catalogue
};

#endif // ! defined (CATALOGUE_H)
