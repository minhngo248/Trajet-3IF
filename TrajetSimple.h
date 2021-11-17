
#if ! defined ( TRAJET_SIMPLE_H )
#define TRAJET_SIMPLE_H
#include <Trajet.h>


class TrajetSimple : public Trajet {

public:

    TrajetSimple (const TrajetSimple & unTrajetSimple);


    TrajetSimple();

	
	TrajetSimple(const char* uneVilleDepart,const char* uneVilleArrivee,const char* unMoyTrans) 
    : Trajet(villeDepart, villeArrivee), moyTrans(unMoyTrans);
	
    ~TrajetSimple();


protected:

	char* moyTrans;
};

#endif 


