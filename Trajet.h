#if ! defined TRAJET_H
#define TRAJET_H

class Trajet {

public:

	Trajet();
    Trajet (const Trajet&);
    Trajet ( const char* , const char* );  
	//void getTrajet(char* , char* );  
	virtual char* GetVille(int);
	virtual void GetTrajet( char* , char* );
    virtual void afficher(const int) const;
    virtual ~Trajet();

protected:
	char* villeDepart;
	char* villeArrivee;
};
#endif
