/*************************************************************************
                           main 
                             -------------------
    debut                : 23 novembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/
//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <bits/stdc++.h>
#include <string> 
using namespace std;
//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

int main() {
	char c, c_n;
	int n, i, k;
	string uneVilleDepart, uneVilleArrivee, unMoyTrans;
	Catalogue C;
	TrajetCompose* unTC = new TrajetCompose();
	TrajetSimple* t = new TrajetSimple();
	do {	
		//Menu
		cout << "Veuillez choisir une demande \r\n" << endl;
		cout << "1. Ajouter un trajet simple. \r\n" << endl;
		cout << "2. Ajouter un trajet composee. \r\n" << endl;
		cout << "3. Rechercher des trajets directs. \r\n" << endl;
		cout << "4. Rechercher tous les trajets possibles. \r\n" << endl;
		cout << "5. Afficher tous les trajets dans le catalogue. \r\n" << endl;
		cout << "6. Lecture dans un fichier. \r\n" << endl;
		do {
			cout << "Veuillez choisir une demande entre 1,2,3,4,5,6 " << endl;
			cin >> c_n;
			cin.get();
			n = c_n -'0';
		}while (n<1 || n>6);
		switch(n) {
			case 1:	
				cout << endl << "-------AJOUTER UN TRAJET SIMPLE-----\r\n" << endl;
				cout << "Entrez une ville du depart : ";
				getline(cin, uneVilleDepart);
				cout << "Entrez une ville d'arrivee : ";
				getline(cin, uneVilleArrivee);
				cout << "Entrez un moyen de transport : ";
				getline(cin, unMoyTrans);
				t = new TrajetSimple(uneVilleDepart , uneVilleArrivee , unMoyTrans);					
				C.Ajouter_trajet(t);
				break;
			case 2: 
				cout << endl << "-------AJOUTER UN TRAJET COMPOSE-----\r\n" << endl;
				i = 1;
				unTC = new TrajetCompose();
				do {
					cout << "Entrez un trajet simple #" << i << endl;
					cout << "Entrez une ville du depart : ";
					getline(cin, uneVilleDepart, '\n');
					cout << "Entrez une ville d'arrivee : ";
					getline(cin, uneVilleArrivee, '\n');
					cout << "Entrez un moyen de transport : ";
					getline(cin, unMoyTrans, '\n');
						
					t = new TrajetSimple(uneVilleDepart , uneVilleArrivee , unMoyTrans);					
					if(unTC->Ajouter(t) == false) {
						cout << "Erreur en ajoutant le trajet!" << endl;
					}else{
						i++;
					}
					cout << "Continue ? (1 pour oui et 0 pour non)";
					cin >> k;
					cin.get();
				}while(k == 1);
				C.Ajouter_trajet(unTC);
				break;		
			case 3:
				cout << endl << "--------RECHERCHER DES TRAJETS-----\r\n" << endl;
				cout << "Entrez une ville du depart : ";
				getline(cin, uneVilleDepart, '\n');
				cout << "Entrez une ville d'arrivee : ";
				getline(cin, uneVilleArrivee, '\n');
				C.Rechercher(uneVilleDepart , uneVilleArrivee);
				break;
			case 4:
				cout << endl << "--------RECHERCHE AVANCEE DES TRAJETS-----\r\n" << endl;
				cout << "Entrez une ville du depart : ";
				getline(cin, uneVilleDepart, '\n');
				cout << "Entrez une ville d'arrivee : ";
				getline(cin, uneVilleArrivee, '\n');
				C.Recherche_avancee(uneVilleDepart , uneVilleArrivee);
				break;
			case 5:	
				cout << endl << "--------AFFICHER TOUS LES TRAJETS DANS LE CATALOGUE---------\r\n" << endl;
				C.Afficher();
				break;
			default:
				cout << endl << "--------LECTURE DANS UN FICHIER---------\r\n" << endl;
				C.Lecture_fichier();
				break;	
			}
		cout << endl << "Tapez Y ou y pour continuer : " << endl;
		cin >> c;
		if (c != 'Y' && c != 'y') C.Ecriture_fichier();				
	}while(c == 'Y' || c == 'y');
	
//	delete t;
//	delete unTC;
	return 0;
}
