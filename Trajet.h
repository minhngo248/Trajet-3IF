#if ! defined ( Trajet_H )
#define Trajet_H

class Trajet {

public:

	Trajet();
    Trajet (const Trajet&);
    Trajet (const char* ,const char* );    
    virtual void afficher() const;
    virtual ~Trajet();
    virtual bool comparer(Trajet);

protected:
	char * villeDepart;
	char * villeArrivee;
};
#endif
