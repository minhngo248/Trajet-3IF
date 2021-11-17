/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if ! defined ( LISTE_TRAJET_H )
#define LISTE_TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------



//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur



//----------------------------------------------------- Méthodes protégées
class ListeTrajet {
	public:
		NodeTrajet* head;
	public:
		ListeTrajet();
		void ajouter_en_tete(); 

		void rechercher(); {
		int x,i=0;
	elem* p = malloc(sizeof(elem));
	p = list;
	printf("Vous voulez trouver quel nombre ");
	scanf("%d", &x);
	while (p != NULL) {
		if (p->value == x) {
			printf("pos : %d\n", i);
		}
		p = p->next;
		i++;
	}
}

void ajouter_en_queue() {
	int x;
	printf("Entrez un nombre ");
	scanf("%d", &x);
	elem* p = malloc(sizeof(elem));
	p = list;
	while(p->next != NULL) {
		p = p->next;
	}
	elem* q = malloc(sizeof(elem));
	q->value = x;
	q->next = NULL;
	p->next = q;
} 

void afficher() {
	elem* p = list;
	while (p != NULL) {
		printf("%d\t", p->value);
		p = p->next;
	}
}

void supprimer() {
	int x;
	printf("Entrez un nombre ");
	scanf("%d", &x);
	elem* p = malloc(sizeof(elem));
	if (list->value == x) {
		list = list->next;
	}
	p = list;
	while(p->next != NULL) {
		if(p->next->value == x) {
			elem* q = malloc(sizeof(elem));
			q = p->next;
			p->next = q->next;
			free(q);
		}
		p = p->next;
	}
}

void dupliquer() {
	int x;
	printf("Entrez un nombre ");
	scanf("%d", &x);
	elem *p = malloc(sizeof(elem));
	p = list;
	while (p != NULL) {
		if (p->value == x) {
			elem* q = malloc(sizeof(elem));
			q->value = x;
			q->next = p->next;
			p->next = q;
			p = p->next;
		}
		p = p->next;
	}
}

void ajouter_en_place() {
	if (est_triee()) {
		int x;
		printf("Entrez x ");
		scanf("%d", &x);
		elem* p = malloc(sizeof(elem));
		if(list->value > x) {
			p->value = x;
			p->next = list;
			list = p;
		}
		else {
			p = list;
			while (p->next->value < x && p->next != NULL) {
				p = p->next;
			}
			elem* q = malloc(sizeof(elem));
			q->value = x;
			q->next = p->next;
			p->next = q;
		}
	}	
}
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H

