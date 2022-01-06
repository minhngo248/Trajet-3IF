/*************************************************************************
                           TrajetSimple  - caracterise par une Ville Depart
                           une Ville Arrivee et un Moyen de Transport
                             -------------------
    d�but                : 14 d�cembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- Interface de la <TrajetSimple> (fichier TrajetSimple.h) ------
#if ! defined ( TRAJET_SIMPLE_H )
#define TRAJET_SIMPLE_H
#include "Trajet.h"
#include <string>
#include <fstream>
// R�le de la classe <TrajetSimple> : definition d'un trajet simple
// Heritage de l'objet Trajet
//
//------------------------------------------------------------------------
class TrajetSimple : public Trajet {
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- M�thodes publiques
    
    void GetTrajet( string& , string& ) const;
	// Mode d'emploi : Prendre soit la ville de d�part et la ville d'arriv�e en m�me temps
	//
    void Afficher(const int) const;
	// Mode d'emploi :  afficher les caracteristique d'un Trajet simple :
	// une Ville Depart, une Ville Arrivee et un Moyen de Transport 
	//	
	void FicWrite(ofstream & , const int);
	// Mode d'emploi: �crire dans le fichier les caract�ristiques de
	// ce trajet
	//
//-------------------------------------------- Constructeurs - destructeur	
	TrajetSimple (const TrajetSimple&);
	// Mode d'emploi (constructeur de copie): Cr�er une copie d'un trajet simple
	//
	TrajetSimple (const string = "",const string = "",const string = "");
	// Mode d'emploi (constructeur) : affectation des caracteristiques d'un 
	// trajet simple
	//
    ~TrajetSimple();
    // Mode d'emploi (destructeur) : liberer les memoires du trajet
	//

protected:
//----------------------------------------------------- Attributs prot�g�s
	string moyTrans;
};

#endif // ! defined (TRAJET_SIMPLE_H)


