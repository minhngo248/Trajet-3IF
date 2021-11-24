#if ! defined TRAJET_H
#define TRAJET_H
//#include "TrajetSimple.h"
//#include "TrajetCompose.h"

class Trajet {

public:

	Trajet();
    Trajet (const Trajet&);
    Trajet (const char* ,const char* );    
    virtual void afficher() const;
    virtual ~Trajet();

protected:
	char * villeDepart;
	char * villeArrivee;
};
#endif
