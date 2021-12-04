#include <iostream>
#include <cmath>
using namespace std;
#include "Catalogue.h"

Catalogue::Catalogue() {
	listeTrajet = new ListeTrajet();
	listeTrajetAvance = new ListeTrajet();
}

void Catalogue::ajouter_trajet(Trajet* trajet) {
	listeTrajet->ajouter_en_queue(trajet);
}

void Catalogue::creer_liste_avancee(int & num) {
	long m = pow(2, listeTrajet->size()) - 1;
	listeTrajetAvance = new ListeTrajet [m];
	int i, j; //compteur de LTA
	NodeTrajet* p = listeTrajet->head;
	NodeTrajet* q;
	for (i = 0 ; i<listeTrajet->size() ; i++) { //1 noeud
		listeTrajetAvance[i].ajouter_en_queue(p->trajet);
		p = p->next;
	}
	char* villeTail1;	char* villeHead1;	char* villeTail2; char* villeHead2;
	int a = 0, b = listeTrajet->size() - 1, k1;
	int n = 2;
	while (n <= listeTrajet->size()) {
		j = a;
		k1 = i;
		while (a <= j && j <= b) {
			p = listeTrajet->head;
			while(p != nullptr) {
				villeHead1 = new char [50];
				villeTail1 = new char [50]; //tail de liste
				villeHead2 = new char [50]; //head de trajet courant
				villeTail2 = new char [50]; 
				listeTrajetAvance[j].getVille(villeHead1, villeTail1);
				p->trajet->GetTrajet(villeHead2, villeTail2);
				if (strcmp(villeTail1, villeHead2) == 0 && strcmp(villeHead1, villeTail2) != 0) { 
					q = listeTrajetAvance[j].head;
					while (q != nullptr) {
						listeTrajetAvance[i].ajouter_en_queue(q->trajet);
						q = q->next;
					}
					listeTrajetAvance[i].ajouter_en_queue(p->trajet);
					i++;
				} 
				p = p->next; }
			j++;
		}
		n++;
		a = k1;
		b = i - k1;
	}
	num = i;
} 

void Catalogue::recherche_avancee(const char* uneVilleDepart, const char* uneVilleArrivee) {
	int num;
	char* uneVD;
	char* uneVA;
	creer_liste_avancee(num);
	for (int i=0;i<num;i++) {
		uneVD = new char [50];
		uneVA = new char [50];
		listeTrajetAvance[i].getVille(uneVD, uneVA);
		if (strcmp(uneVD, uneVilleDepart) == 0 && strcmp(uneVA, uneVilleArrivee)==0) {
			listeTrajetAvance[i].afficher();
		}
	}
}

void Catalogue::rechercher(const char* uneVilleDepart, const char* uneVilleArrivee) {
	NodeTrajet* p = listeTrajet->head;
	char* villeStart;
	char* villeFinish;
	while (p != NULL) {
		villeStart = new char [50];
		villeFinish = new char [50];
		p->trajet->GetTrajet(villeStart , villeFinish);
		if (strcmp(villeStart , uneVilleDepart) == 0 && strcmp(villeFinish,uneVilleArrivee) == 0) {
			p->trajet->afficher(1);	
		}
		p = p->next;
	}
}

void Catalogue::afficher() {
	listeTrajet->afficher();
	cout << endl;
}

void Catalogue::affiche_toute_avancee() {
	int num;
	creer_liste_avancee(num);
	cout << num;
	for(int i = 0; i < num ; i++) {
		listeTrajetAvance[i].afficher();
		cout << endl << endl;
	} 
}

Catalogue::~Catalogue() {
	delete listeTrajet;
//	delete[] listeTrajetAvance;
}
