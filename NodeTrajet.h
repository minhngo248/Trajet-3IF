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
	Trajet* GetTrajet() const;
	// Mode d'emploi : prendre le trajet de ce élément
    //
	NodeTrajet* GetNext() const;
	// Mode d'emploi : prendre l'élément suivant 
    //
	void SetTrajet(Trajet*);
	// Mode d'emploi : mettre le trajet à la valeur du paramètre passé 
    //
	void SetNext(NodeTrajet*);
	// Mode d'emploi : mettre l'élément suivant à la valeur du paramètre passé 
    //
//-------------------------------------------- Constructeurs - destructeur	
	NodeTrajet();
	// Mode d'emploi (constructeur): initialiser et allouer des espaces dans
    //	la memoire pour "trajet"
	NodeTrajet(const NodeTrajet&); 
	// Mode d'emploi (constructeur de copie) : Créer une copie d'un élément contenant un trajet
	//
	~NodeTrajet();
	// Mode d'emploi (destructeur) : liberer les espaces dans la memoire pour
	// trajet et next
	
//------------------------------------------------------------------ PRIVE	
private:
	NodeTrajet* next;
	Trajet* trajet;
};

#endif // ! defined (LISTE_TRAJET_H)
