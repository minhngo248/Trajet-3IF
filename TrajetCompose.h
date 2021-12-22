/*************************************************************************
                           TrajetCompose  - une liste de chainee de trajets
                           simples
                             -------------------
    d�but                : 23 novembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- Interface de la <TrajetCompose> (fichier TrajetCompose.h) ------
#if ! defined ( TRAJET_COMPOSE_H )
#define TRAJET_COMPOSE_H
#include "TrajetSimple.h"
#include "ListeTrajet.h"
#include <string>
#include <fstream>
// R�le de la classe <TrajetCompose> : definition d'un trajet compose
// Heritage de l'objet Trajet
//
//------------------------------------------------------------------------
class TrajetCompose : public Trajet {
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- M�thodes publiques
    
	bool Ajouter( TrajetSimple* ); 
	// Mode d'emploi : ajouter un Trajet Simple en queue du Trajet Compose
	//
	void Afficher(const int) const;
	// Mode d'emploi : afficher tous les Trajets Simples dans la liste
	//	
	void GetTrajet(string& , string&) const;
	// Mode d'emploi : prendre la Ville Debut et la Ville en fin de la
	//	liste
	//
	void FicWrite(ofstream & , const int);
	//
	//
	//
//-------------------------------------------- Constructeurs - destructeur	
     
	TrajetCompose(const TrajetCompose & unTrajetCompose);
	// Mode d'emploi (constructeur de copie) : Cr�er une copie d'un trajet compos�
	// 
	TrajetCompose();
	// Mode d'emploi (constructeur) : initialiser la listeSimple
	//	
	~TrajetCompose();
	// Mode d'emploi (destructeur) : liberer la listeSimple
	//
protected:
//----------------------------------------------------- Attributs prot�g�s	
	ListeTrajet* listeSimple;
};

#endif // ! defined (TRAJET_COMPOSE_H)


