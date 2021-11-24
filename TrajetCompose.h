#if ! defined ( TRAJET_COMPOSE_H )
#define TRAJET_COMPOSE_H
#include "TrajetSimple.h"
#include "ListeTrajet.h"


class TrajetCompose : public Trajet {

public:

    TrajetCompose();
	void ajouter(TrajetSimple unTS); 
	TrajetCompose(const TrajetCompose & unTrajetCompose);
	void afficher() const;
    ~TrajetCompose();

protected:
	ListeTrajet* listeSimple;
};

#endif 


