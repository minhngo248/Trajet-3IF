/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <listtrajet> (fichier Xxx.h) ----------------
#if ! defined ( LISTE_TRAJET_H )
#define LISTE_TRAJET_H
class ListeTrajet {
	public:
		NodeTrajet* head;
	public:
		ListeTrajet();
		void ajouter_en_tete(Trajet); 
		void rechercher(Trajet);
		void ajouter_en_queue(Trajet); 
		void afficher(); 
		void supprimer(Trajet);  
};

#endif
