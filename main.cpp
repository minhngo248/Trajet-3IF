#include <bits/stdc++.h>
#include <stdio.h> 
using namespace std;
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

int main() {
	char c = 'y';
	int n, i, k;
	char uneVilleDepart[50], uneVilleArrivee[50], unMoyTrans[50];
	char uneVD[50], uneVA[50];
	Catalogue* C = new Catalogue();
	TrajetCompose* unTC;
	TrajetSimple* t = new TrajetSimple();
	do {	
		
		cout << "Veuillez choisir une demande \r\n" << endl;
		cout << "1. Ajouter un trajet simple. \r\n" << endl;
		cout << "2. Ajouter un trajet composee. \r\n" << endl;
		cout << "3. Rechercher des trajets. \r\n" << endl;
		cout << "4. Afficher tous les trajets dans le catalogue. \r\n" << endl;
			
		do {
			cout << "Veuillez choisir une demande entre 1,2,3,4" << endl;
			cin >> n;
		}while (n<1 || n>4);
		switch(n) {
			case 1:	
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
					cout << "Continue? (1 pour oui et 0 pour non)";	
					t = new TrajetSimple(uneVD , uneVA , unMoyTrans);	
									
					unTC->ajouter(t);
					i++;
					
					scanf("%d", &k);
				}while(k == 1);
				C->ajouter_trajet(unTC);
				break;		
			case 3:
				cout << endl << "--------Rechercher des trajets-----\r\n" << endl;
				cout << "Entrez une ville du depart : ";
				scanf(" %s", uneVilleDepart);
				cout << "Entrez une ville d'arrivee : ";
				scanf(" %s", uneVilleArrivee);
				C->rechercher(uneVilleDepart , uneVilleArrivee);
				break;
			default:
				C->afficher();
				break; }
		cout << "Tapez Y ou y pour continuer : ";
		cin >> c;				
	}while(c == 'Y' || c == 'y');
	
	//delete t;
	//delete unTC;
	delete C;
	
	return 0;
}
