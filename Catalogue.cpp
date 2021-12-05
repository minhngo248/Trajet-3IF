/*************************************************************************
                           Catalogue  -  methodes pour un catalogue de trajets
                             -------------------
    début                : 23 novembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
//----------------------------------------------------------------- PUBLIC


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue() {

	listeTrajet = new ListeTrajet();
	listeTrajetAvance = new ListeTrajet();
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue

//----------------------------------------------------- Méthodes publiques

void Catalogue::ajouter_trajet(Trajet* trajet) {
	listeTrajet->ajouter_en_queue(trajet);
} //----- Fin de Méthode


void Catalogue::creer_liste_avancee(int & num) {
// Algorithme : parcourir tous les elements de la listeTrajet et relier tous les 
// trajets possibles
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
		b = i - k1 + 1;
	}
	num = i;
} //----- Fin de Méthode

void Catalogue::recherche_avancee(const char* uneVilleDepart, const char* uneVilleArrivee) {
// Algorithme : Parcourir toute la listeTrajetAvance pour afficher les trajets possibles
//
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
			cout << endl << endl;
		}
	}
} //----- Fin de Méthode

void Catalogue::rechercher(const char* uneVilleDepart, const char* uneVilleArrivee) {
// Algorithme : parcourir tous les elements dans la listeTrajet
//
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
} //----- Fin de Méthode

void Catalogue::affiche_avancee() {
	int num;
	creer_liste_avancee(num);
	cout << num;
	for(int i=0;i<num;i++) {
		listeTrajetAvance[i].afficher();
		cout << endl << endl;
	}
	
}

void Catalogue::afficher() {
	if (listeTrajet->size()) {
		listeTrajet->afficher();
		cout << endl; }
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
Catalogue::~Catalogue() {
	delete listeTrajet;
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue
