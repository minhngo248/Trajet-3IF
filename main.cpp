/*************************************************************************
                           main 
                             -------------------
    debut                : 23 novembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/
//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <bits/stdc++.h>
#include <cstdio> 
using namespace std;
//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

int main() {
	char c;
	int n, i, k;
	char uneVilleDepart[50], uneVilleArrivee[50], unMoyTrans[50];
	char uneVD[50], uneVA[50];
	Catalogue* C = new Catalogue();
	TrajetCompose* unTC;
	TrajetSimple* t = new TrajetSimple();
	do { 	
		//Menu
		cout << "Veuillez choisir une demande \r\n" << endl;
		cout << "1. Ajouter un trajet simple. \r\n" << endl;
		cout << "2. Ajouter un trajet composee. \r\n" << endl;
		cout << "3. Rechercher des trajets. \r\n" << endl;
		cout << "4. Recherche avancee des trajets. \r\n" << endl;
		cout << "5. Afficher tous les trajets dans le catalogue. \r\n" << endl;
			
		do {
			cout << "Veuillez choisir une demande entre 1,2,3,4,5 " << endl;
			cin >> n;
		}while (n<1 || n>5);
		switch(n) {
			case 1:	
				cout << endl << "-------AJOUTER UN TRAJET SIMPLE-----\r\n" << endl;
				cout << "Entrez une ville du depart : ";
				scanf(" %s", uneVilleDepart);
				cout << "Entrez une ville d'arrivee : ";
				scanf(" %s", uneVilleArrivee);
				cout << "Entrez un moyen de transport : ";
				scanf(" %s", unMoyTrans);
				t = new TrajetSimple(uneVilleDepart , uneVilleArrivee , unMoyTrans);					
				C->ajouter_trajet(t);
				break;
			
			case 2: 
				cout << endl << "-------AJOUTER UN TRAJET COMPOSE-----\r\n" << endl;
				unTC = new TrajetCompose();
				i = 1;
				do {
					cout << "Entrez un trajet simple #" << i << endl;
					cout << "Entrez une ville du depart : ";
					scanf(" %s", uneVD);
					cout << "Entrez une ville d'arrivee : ";
					scanf(" %s", uneVA);
					cout << "Entrez un moyen de transport : ";
					scanf(" %s", unMoyTrans);
					cout << "Continue ? (1 pour oui et 0 pour non)";	
					t = new TrajetSimple(uneVD , uneVA , unMoyTrans);					
					unTC->ajouter(t);
					i++;
					cin >> k;
				}while(k == 1);
				C->ajouter_trajet(unTC);
				break;		
			case 3:
				cout << endl << "--------RECHERCHER DES TRAJETS-----\r\n" << endl;
				cout << "Entrez une ville du depart : ";
				scanf(" %s", uneVilleDepart);
				cout << "Entrez une ville d'arrivee : ";
				scanf(" %s", uneVilleArrivee);
				C->rechercher(uneVilleDepart , uneVilleArrivee);
				break;
			case 4:
				cout << endl << "--------RECHERCHE AVANCEE DES TRAJETS-----\r\n" << endl;
				cout << "Entrez une ville du depart : ";
				scanf(" %s", uneVilleDepart);
				cout << "Entrez une ville d'arrivee : ";
				scanf(" %s", uneVilleArrivee);
				C->recherche_avancee(uneVilleDepart , uneVilleArrivee);
				break;
			default:	
				cout << endl << "--------AFFICHER TOUS LES TRAJETS DANS LE CATALOGUE---------\r\n" << endl;
				C->afficher();
				break;						
			}
		cout << endl << "Tapez Y ou y pour continuer : ";
		cin >> c;				
	}while(c == 'Y' || c == 'y');
	
//	delete t;
//	delete unTC;
	delete C;
	
	return 0;
}
