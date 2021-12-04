/*************************************************************************
                           NodeTrajet  - noeud d'une liste chainee de type
                           "Trajet"
                             -------------------
    début                : 23 novembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- Interface de la <NodeTrajet> (fichier NodeTrajet.h) ------
#if ! defined (NODE_TRAJET_H)
#define NODE_TRAJET_H

#include "Trajet.h"
// Rôle de la classe <NodeTrajet>
//
//
//------------------------------------------------------------------------
class NodeTrajet {
	
public:
//----------------------------------------------------------------- PUBLIC
//-------------------------------------------- Constructeurs - destructeur	
	NodeTrajet();
	// Mode d'emploi (constructeur): initialiser et allouer des espaces dans
    //	la memoire pour "trajet"
	NodeTrajet(const NodeTrajet&); 
	// Mode d'emploi (constructeur de copie) :
	//
	~NodeTrajet();
	// Mode d'emploi (destructeur) : liberer les espaces dans la memoire pour
	// trajet et next
public:
	NodeTrajet* next;
	Trajet* trajet;
};

#endif // ! defined (LISTE_TRAJET_H)
