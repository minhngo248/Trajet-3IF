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
	listeTrajetAvance = nullptr;
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue

Catalogue::~Catalogue() {
	delete listeTrajet;
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue

//----------------------------------------------------- Méthodes publiques

string Catalogue::toUpper (const string& str) const{
	char c;
	unsigned i;
	string s = "";
	for (i=0; i < str.length(); ++i) {
		c = str.at(i);
		if (c >= 97 && c <= 122) {
			c = c -32;
		}
		s.append(1,c);
	}
	return s;	
}

void Catalogue::Ajouter_trajet(Trajet* trajet) {
	listeTrajet->Ajouter_en_queue(trajet);
} //----- Fin de Méthode

void Catalogue::creer_liste_avancee(int & num) {
// Algorithme : parcourir tous les elements de la listeTrajet et relier tous les 
// trajets possibles
	long m = pow(2, listeTrajet->Size()) - 1;
	listeTrajetAvance = new ListeTrajet [m];
	int i, j; //compteur de LTA
	NodeTrajet* p = listeTrajet->GetHead();
	NodeTrajet* q;
	for (i = 0 ; i<listeTrajet->Size() ; i++) { //1 noeud
		listeTrajetAvance[i].Ajouter_en_queue(p->GetTrajet());
		p = p->GetNext();
	}
	string villeTail1 ="a";	
	string villeHead1 ="a";	
	string villeTail2 ="a"; 
	string villeHead2 ="a";
	
	int a = 0, b = listeTrajet->Size() - 1, k1;
	int n = 2;
	while (n <= listeTrajet->Size()) {
		j = a;
		k1 = i;
		while (a <= j && j <= b) {
			p = listeTrajet->GetHead();
			while(p != nullptr) { 
				listeTrajetAvance[j].GetVille(villeHead1, villeTail1);
				p->GetTrajet()->GetTrajet(villeHead2, villeTail2);
				if (villeTail1.compare(villeHead2) == 0 && villeHead1.compare(villeTail2) != 0) { 
					q = listeTrajetAvance[j].GetHead();
					while (q != nullptr) {
						listeTrajetAvance[i].Ajouter_en_queue(q->GetTrajet());
						q = q->GetNext();
					}
					listeTrajetAvance[i].Ajouter_en_queue(p->GetTrajet());
					i++;
				} 
				p = p->GetNext(); 
			}
			j++;
		}
		n++;
		a = k1;
		b = i - k1 + 1;
	}
	num = i;
} //----- Fin de Méthode

void Catalogue::Recherche_avancee(const string uneVilleDepart, const string uneVilleArrivee) {
// Algorithme : Parcourir toute la listeTrajetAvance pour afficher les trajets possibles
//
	int num = 0;
	string uneVD ="a", uneVA ="a";
	creer_liste_avancee(num);
	for (int i=0;i<num;i++) {
		listeTrajetAvance[i].GetVille(uneVD, uneVA);
		if (toUpper(uneVD).compare(uneVilleDepart) == 0 && toUpper(uneVA).compare(uneVilleArrivee) ==0) {
			cout << endl ;
			listeTrajetAvance[i].Afficher();
		}
	}
} //----- Fin de Méthode

void Catalogue::Rechercher(const string uneVilleDepart, const string uneVilleArrivee) const{
// Algorithme : parcourir tous les elements dans la listeTrajet
//
	NodeTrajet* p = listeTrajet->GetHead();
	string villeStart = "a", villeFinish = "a";
	while (p != NULL) {
		p->GetTrajet()->GetTrajet(villeStart , villeFinish);
		if (toUpper(villeStart).compare(uneVilleDepart) == 0 && toUpper(villeFinish).compare(uneVilleArrivee) == 0) {
			p->GetTrajet()->Afficher(1);	
		}
		p = p->GetNext();
	}
} //----- Fin de Méthode

ListeTrajet* Catalogue::GetList() const{
	return this->listeTrajet;
}//----- Fin de Méthode

void Catalogue::Afficher() const{
	listeTrajet->Afficher();
	cout << endl; 
} //----- Fin de Méthode

