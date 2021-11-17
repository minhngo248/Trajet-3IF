
#if ! defined ( Trajet_H )
#define Trajet_H

class Trajet {

public:

    Trajet (const Trajet & unTrajet );

    Trajet (const char* uneVilleDepart,const char* uneVilleArrivee) 

    ~Trajet();


protected:
	char * villeDepart;
	char * villeArrivee;

#endif
