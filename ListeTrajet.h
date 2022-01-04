/*************************************************************************
                           ListeTrajet  - structure de donnees pour 
                           sauvegarder des trajets
                             -------------------
    d�but                : 14 d�cembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- Interface de la <ListeTrajet> (fichier ListeTrajet.h) ------
#if ! defined ( LISTE_TRAJET_H )
#define LISTE_TRAJET_H
// R�le de la classe <ListeTrajet> : definition de la structure de donnees
// (liste chainee) type Trajet
//
//------------------------------------------------------------------------

#include "NodeTrajet.h"
#include <string>

class ListeTrajet {
//----------------------------------------------------------------- PUBLIC
	
public:
//----------------------------------------------------- M�thodes publiques		
	int Size();
	// Mode d'emploi : taille de la ListeTrajet
    //
	NodeTrajet* GetLastNode() const;
	// Mode d'emploi : prendre le dernier �l�ment 
    //
    NodeTrajet* GetHead() const;
    // Mode d'emploi : prendre le premier �l�ment 
    //
    void SetHead(NodeTrajet*);
    // Mode d'emploi : mettre la valeur du premier �l�ment � la valeur du param�tre pass� 
    //
	void GetVille(string& , string&) const;
	// Mode d'emploi : prendre la Ville Debut et la Ville en fin de la liste
    //
	void Ajouter_en_queue(Trajet*); 
	// Mode d'emploi : ajouter un noeud en queue de la liste
    //	
	void Afficher() const; 
	// Mode d'emploi : afficher tous les noeud de la liste
    //	    
//-------------------------------------------- Constructeurs - destructeur
	ListeTrajet();
	// Mode d'emploi (constructeur) : initialiser et allouer des espaces dans la 
    //	memoires pour le premier noeud de la liste chainee (head)
	ListeTrajet(const ListeTrajet&); 
	// Mode d'emploi (constructeur de copie) : Cr�er une copie d'une liste de trajets
	//
	~ListeTrajet();
	// Mode d'emploi (destructeur) : liberer l'espace de "head"
	// 
	
//------------------------------------------------------------------ PRIVE
private:
	NodeTrajet* head;	  
};

#endif // ! defined (LISTE_TRAJET_H)
