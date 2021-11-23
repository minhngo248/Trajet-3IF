#if ! defined ( TRAJET_COMPOSE_H )
#define TRAJET_COMPOSE_H
#include <TrajetSimple.h>


class TrajetCompose : public Trajet {

public:

    TrajetCompose();

	
	TrajetCompose(const TrajetSimple trajetA, const TrajetSimple trajetB); 
	
	TrajetCompose(const TrajetCompose & unTrajetCompose);
	
	
    ~TrajetCompose();


protected:

	ListeTrajet listeSimple;
};

#endif 


