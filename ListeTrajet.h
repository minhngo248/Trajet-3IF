#if ! defined ( LISTE_TRAJET_H )
#define LISTE_TRAJET_H

#include "NodeTrajet.h"

class ListeTrajet {
	public:
		NodeTrajet* head;
	public:
		ListeTrajet();
		ListeTrajet(const ListeTrajet&);
		~ListeTrajet(); 
		//void rechercher(Trajet);
		NodeTrajet* getLastNode();
		void ajouter_en_queue(Trajet*); 
		void afficher(); 
		//void supprimer(Trajet);  
};

#endif
