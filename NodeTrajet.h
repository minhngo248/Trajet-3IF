/*************************************************************************
                           NodeTrajet  - noeud d'une liste chainee de type
                           "Trajet"
                             -------------------
    d�but                : 23 novembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- Interface de la <NodeTrajet> (fichier NodeTrajet.h) ------
#if ! defined (NODE_TRAJET_H)
#define NODE_TRAJET_H

#include "Trajet.h"
// R�le de la classe <NodeTrajet>
//
//
//------------------------------------------------------------------------
class NodeTrajet {
	
public:
//----------------------------------------------------------------- PUBLIC
	Trajet* GetTrajet() const;
	// Mode d'emploi : prendre le trajet de ce �l�ment
    //
	NodeTrajet* GetNext() const;
	// Mode d'emploi : prendre l'�l�ment suivant 
    //
	void SetTrajet(Trajet*);
	// Mode d'emploi : mettre le trajet � la valeur du param�tre pass� 
    //
	void SetNext(NodeTrajet*);
	// Mode d'emploi : mettre l'�l�ment suivant � la valeur du param�tre pass� 
    //
//-------------------------------------------- Constructeurs - destructeur	
	NodeTrajet();
	// Mode d'emploi (constructeur): initialiser et allouer des espaces dans
    //	la memoire pour "trajet"
	NodeTrajet(const NodeTrajet&); 
	// Mode d'emploi (constructeur de copie) : Cr�er une copie d'un �l�ment contenant un trajet
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
