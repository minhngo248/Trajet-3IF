/*************************************************************************
                           ListeTrajet  - structure de donnees pour 
                           sauvegarder des trajets
                             -------------------
    d�but                : 23 novembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- Interface de la <ListeTrajet> (fichier ListeTrajet.h) ------
#if ! defined ( LISTE_TRAJET_H )
#define LISTE_TRAJET_H
#include "NodeTrajet.h"
// R�le de la classe <ListeTrajet> : definition de la structure de donnees
// (liste chainee) type Trajet
//
//------------------------------------------------------------------------
class ListeTrajet {
//----------------------------------------------------------------- PUBLIC
	
public:
//----------------------------------------------------- M�thodes publiques		
	int size();
	// Mode d'emploi : taille de la ListeTrajet
    //
	NodeTrajet* getLastNode();
	// Mode d'emploi : taille de la ListeTrajet
    //
	void getVille(char*, char*);
	// Mode d'emploi : prendre la Ville Debut et la Ville en fin de la liste
    //
	void ajouter_en_queue(Trajet*); 
	// Mode d'emploi : ajouter un noeud en queue de la liste
    //	
	void afficher(); 
	// Mode d'emploi : afficher tous les noeud de la liste
    //	
    
//-------------------------------------------- Constructeurs - destructeur
	ListeTrajet();
	// Mode d'emploi (constructeur) : initialiser et allouer des espaces dans la 
    //	memoires pour le premier noeud de la liste chainee (head)
	ListeTrajet(const ListeTrajet&); 
	// Mode d'emploi (constructeur de copie) :
	//
	~ListeTrajet();
	// Mode d'emploi (destructeur) : liberer l'espace de "head"
	// 
public:
	NodeTrajet* head;	  
};

#endif // ! defined (LISTE_TRAJET_H)
