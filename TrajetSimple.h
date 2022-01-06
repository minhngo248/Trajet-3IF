/*************************************************************************
                           TrajetSimple  - caracterise par une Ville Depart
                           une Ville Arrivee et un Moyen de Transport
                             -------------------
    début                : 14 décembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- Interface de la <TrajetSimple> (fichier TrajetSimple.h) ------
#if ! defined ( TRAJET_SIMPLE_H )
#define TRAJET_SIMPLE_H
#include "Trajet.h"
#include <string>
#include <fstream>
// Rôle de la classe <TrajetSimple> : definition d'un trajet simple
// Heritage de l'objet Trajet
//
//------------------------------------------------------------------------
class TrajetSimple : public Trajet {
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    
    void GetTrajet( string& , string& ) const;
	// Mode d'emploi : Prendre soit la ville de départ et la ville d'arrivée en même temps
	//
    void Afficher(const int) const;
	// Mode d'emploi :  afficher les caracteristique d'un Trajet simple :
	// une Ville Depart, une Ville Arrivee et un Moyen de Transport 
	//	
	void FicWrite(ofstream & , const int);
	// Mode d'emploi: écrire dans le fichier les caractéristiques de
	// ce trajet
	//
//-------------------------------------------- Constructeurs - destructeur	
	TrajetSimple (const TrajetSimple&);
	// Mode d'emploi (constructeur de copie): Créer une copie d'un trajet simple
	//
	TrajetSimple (const string = "",const string = "",const string = "");
	// Mode d'emploi (constructeur) : affectation des caracteristiques d'un 
	// trajet simple
	//
    ~TrajetSimple();
    // Mode d'emploi (destructeur) : liberer les memoires du trajet
	//

protected:
//----------------------------------------------------- Attributs protégés
	string moyTrans;
};

#endif // ! defined (TRAJET_SIMPLE_H)


