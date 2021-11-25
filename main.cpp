#include <bits/stdc++.h>
#include <stdio.h> 
using namespace std;
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

int main() {
//	t->afficher();
	char c;
	int n, i;
	char uneVilleDepart[50], uneVilleArrivee[50], unMoyTrans[50];
	char uneVD[50], uneVA[50];
	Catalogue C;
	TrajetCompose unTC;
	TrajetSimple t;
	cout << "Veuillez choisir une demande \r\n" << endl;
	cout << "1. Ajouter un trajet simple. \r\n" << endl;
	cout << "2. Ajouter un trajet composee. \r\n" << endl;
	cout << "3. Afficher tous les trajets dans le catalogue. \r\n" << endl;	
	do {	
		cin >> n;
		switch(n) {
			case 1:	
				cout << "Entrez une ville du depart : ";
				scanf(" %s", uneVilleDepart);
				cout << "Entrez une ville d'arrivee : ";
				scanf(" %s", uneVilleArrivee);
				cout << "Entrez un moyen de transport : ";
				scanf(" %s", unMoyTrans);
				t.SetTrajet(uneVilleDepart , uneVilleArrivee , unMoyTrans);					
				C.ajouter_trajet(t);
				break;
			case 2: 
				cout << "Entrez une ville du depart : ";
				scanf(" %s", uneVilleDepart);
				cout << "Entrez une ville d'arrivee : ";
				scanf(" %s", uneVilleArrivee);
				i = 1;
				do {
					cout << "Entrez un trajet simple #" << i << endl;
					cout << "Entrez une ville du depart : ";
					scanf(" %s", uneVD);
					cout << "Entrez une ville d'arrivee : ";
					scanf(" %s", uneVA);
					cout << "Entrez un moyen de transport : ";
					scanf(" %s", unMoyTrans);
					t.SetTrajet(uneVD , uneVA , unMoyTrans);						
					unTC.ajouter(t);
					i++;
				}while(strcmp(uneVA , uneVilleArrivee) != 0);
				C.ajouter_trajet(unTC);
				break;
			default:
				C.afficher();
				break; }
		cout << "Tapez Y ou y pour continuer : ";
		cin >> c;				
	}while(c == 'Y' || c == 'y');
	return 0;
}
