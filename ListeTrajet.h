#if ! defined ( LISTE_TRAJET_H )
#define LISTE_TRAJET_H

#include "NodeTrajet.h"

class ListeTrajet {
	public:
		NodeTrajet* head;
	public:
		ListeTrajet();
		ListeTrajet(const ListeTrajet&); //constructeur de copie
		~ListeTrajet(); 
		int size();
		void getVille(char*, char*);
		void ajouter_en_queue(Trajet*); 
		void afficher(); 
		  
};

#endif
