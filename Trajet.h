/*************************************************************************
                           Trajet  - definition d'un trajet
                             -------------------
    d�but                : 14 d�cembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- Interface de la <Trajet> (fichier Trajet.h) ------
#if ! defined TRAJET_H
#define TRAJET_H
// R�le de la classe <Trajet>
//
//
//------------------------------------------------------------------------
#include <string>
#include <fstream>
class Trajet {
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- M�thodes publiques
  
	string GetVille(int) const;
	// Mode d'emploi : prendre soit la Ville Depart ou la Ville Arrivee
    //	
	virtual void GetTrajet( string& , string& ) const;
	// Mode d'emploi : prendre la Ville Depart et la Ville Arrivee d'un Trajet
    //	
    virtual void Afficher(const int) const;
	// Mode d'emploi : afficher les caracteristique d'un Trajet : la Ville Depart, 
	// la Ville Arrivee et le Moyen de Transport
	//
	virtual void FicWrite(ofstream & , const int);
	// Mode d'emploi: �crire dans le fichier les caract�ristiques de
	// ce trajet
	//
//-------------------------------------------- Constructeurs - destructeur	
	Trajet();
	// Mode d'emploi (constructeur) : initialiser 
	// les caracteristiques d'un trajet : villeDepart et villeArrivee
	// 
    Trajet (const Trajet&);
    // Mode d'emploi (constructeur de copie) : Cr�er une copie d'un Trajet
    //
    Trajet ( const string , const string );
	// Mode d'emploi (constructeur) : Cr�er un trajet � partir d'une ville de d�part et
	// une ville d'arriv�e
	//     
	virtual ~Trajet();
	// Mode d'emploi (destructeur) : liberer les memoires du trajet
	//
protected:
//----------------------------------------------------- Attributs prot�g�s	
	string villeDepart;
	string villeArrivee;
};
#endif // ! defined (TRAJET_H)
