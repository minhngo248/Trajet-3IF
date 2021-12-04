/*************************************************************************
                           Trajet  - definition d'un trajet
                             -------------------
    début                : 23 novembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- Interface de la <Trajet> (fichier Trajet.h) ------
#if ! defined TRAJET_H
#define TRAJET_H
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------
class Trajet {
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
  
	virtual char* GetVille(int);
	// Mode d'emploi : 
    //	
	virtual void GetTrajet( char* , char* );
	// Mode d'emploi : prendre la Ville Depart et la Ville Arrivee d'un Trajet
    //	
    virtual void afficher(const int) const;
	// Mode d'emploi : afficher les caracteristique d'un Trajet : la Ville Depart, 
	// la Ville Arrivee et le Moyen de Transport
	//
//-------------------------------------------- Constructeurs - destructeur	
	Trajet();
	// Mode d'emploi (constructeur) : initialiser et allouer des espaces de memoire pour 
	// les caracteristiques d'un trajet : villeDepart et villeArrivee
	// 
    Trajet (const Trajet&);
    // Mode d'emploi (constructeur de copie) :
    //
    //
    Trajet ( const char* , const char* );
	// Mode d'emploi (constructeur) :
	//     
	virtual ~Trajet();
	// Mode d'emploi (destructeur) : liberer les memoires de la VilleDepart et villeArrivee
	//
protected:
//----------------------------------------------------- Attributs protégés	
	char* villeDepart;
	char* villeArrivee;
};
#endif // ! defined (TRAJET_H)
