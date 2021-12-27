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
#include "NodeTrajet.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

void addTrajetSimple (Catalogue* C, string line) {
	string delimiter2 = ", ";
	string* membre = new string[3];
	
	size_t posD2 = 0;
	int i =0;
	
	TrajetSimple * TS;
	
	line.append(delimiter2);
	while ((posD2 = line.find(delimiter2)) != string::npos) {
		membre[i] = line.substr(0, posD2);
		line.erase(0, posD2 + delimiter2.length());
		i++;
	}
	TS = new TrajetSimple(membre[0],membre[1],membre[2]);
	C->Ajouter_trajet(TS);
}

void addTrajetCompose (Catalogue* C, string line) {
	string characTrajet;
	
	string delimiter1 = "; ";
	string delimiter2 = ", ";
	string* membre = new string[3];
	
	size_t posD1 = 0;	
	size_t posD2 = 0;
	int i;
	
	TrajetSimple * TS;
	TrajetCompose* TC = new TrajetCompose();
	
	line.append(delimiter1);
	while ((posD1 = line.find(delimiter1)) != string::npos) {
		i =0;
		characTrajet = line.substr(0,posD1);
		characTrajet.append(delimiter2);
		while ((posD2 = characTrajet.find(delimiter2)) != string::npos) {
			membre[i] = characTrajet.substr(0, posD2);
			characTrajet.erase(0, posD2 + delimiter2.length());
			i++;
		}
		TS = new TrajetSimple(membre[0],membre[1],membre[2]);
		TC->Ajouter(TS);				
		line.erase(0, posD1 + delimiter1.length());
	}
	C->Ajouter_trajet(TC);	
}

void addFromFile(Catalogue* C, const string fileName) {
	ifstream myFile;
	string line;
	string typeTrajet;
	
	string delimiter = ": ";
	
	size_t posD1 = 0;	
	
	TrajetSimple * TS = new TrajetSimple();
	TrajetCompose* TC;
	
	myFile.open(fileName);
	while (getline(myFile,line)) {
		posD1 = line.find(delimiter);
		typeTrajet = line.substr(0, posD1);
		line.erase(0, posD1 + delimiter.length());
		
		if (typeTrajet.compare("TS") ==0) {
			addTrajetSimple(C, line);
		}
		
		else if (typeTrajet.compare("TC") ==0) {
			addTrajetCompose(C, line);	
		}
	}
	myFile.close();
}

void saveToFile (Catalogue* C, const string fileName, const int k, const string trajet, const string VD, const string VA) {
	
	bool bVD = ((VD == "Non") || (VD == "non") || (VD == "NON")); // Si l'utilisateur n'avez pas besoin de une ville de depart specifique
	bool bVA = ((VA == "Non") || (VA == "non") || (VA == "NON")); // Si l'utilisateur n'avez pas besoin de une ville d'arrivee specifique
	
	ofstream myFile;
	NodeTrajet* n;
	TrajetSimple* TS;
	
	myFile.open(fileName, ios::app);
	myFile << endl;
		
	n = C->GetList()->GetHead();
	switch(k) {
		case 1:
			while (n != nullptr) {
				n->GetTrajet()->FicWrite(myFile, 1);	
				n = n->GetNext();
			}
			break;
		case 2:
			if (trajet.compare("TS") ==0) {
				while (n != nullptr) {
					TS = dynamic_cast <TrajetSimple*> (n->GetTrajet());
					if (TS != nullptr) { 
						n->GetTrajet()->FicWrite(myFile, 1);	
					}
					n = n->GetNext();
				}
			}else{
				while (n != nullptr) {
					TS = dynamic_cast <TrajetSimple*> (n->GetTrajet());
					if (TS == nullptr) { 
						n->GetTrajet()->FicWrite(myFile, 1);	
					}
					n = n->GetNext();
				}
			}
			break;	
		case 3:
			while (n != nullptr) {
				if ((n->GetTrajet()->GetVille(1).compare(VD)==0 || bVD) && (n->GetTrajet()->GetVille(2).compare(VA)==0 || bVA)) {
					n->GetTrajet()->FicWrite(myFile, 1);	
				}
				n = n->GetNext();
			}
			break;
		default:
			cout <<"a";
	}
}

int main() {
	char c, c_n;
	int n , i, k;
	string uneVilleDepart, uneVilleArrivee, unMoyTrans;
	string uneVD, uneVA;
	Catalogue* C = new Catalogue();
	TrajetCompose* unTC = new TrajetCompose();
	TrajetSimple* t = new TrajetSimple();

	do {	
		//Menu
		cout << "Veuillez choisir une demande \r\n" << endl;
		cout << "1. Charger d'un fichier \r\n" << endl;
		cout << "2. Ajouter un trajet simple. \r\n" << endl;
		cout << "3. Ajouter un trajet composee. \r\n" << endl;
		cout << "4. Rechercher des trajets directs. \r\n" << endl;
		cout << "5. Rechercher tous les trajets possibles. \r\n" << endl;
		cout << "6. Afficher tous les trajets dans le catalogue. \r\n" << endl;
		cout << "7. Saugarder \r\n" << endl;
		cout << "8. Quitter \r\n" << endl;
		
		cin >> c_n;
		cin.get();
		n = c_n -'0';
			
		switch(n) {
			case 1:
				addFromFile(C, "Trajets.txt");
				break;
			case 2:	
				cout << endl << "-------AJOUTER UN TRAJET SIMPLE-----\r\n" << endl;
				cout << "Entrez une ville du depart : ";
				getline(cin, uneVilleDepart);
				cout << "Entrez une ville d'arrivee : ";
				getline(cin, uneVilleArrivee);
				cout << "Entrez un moyen de transport : ";
				getline(cin, unMoyTrans);
				t = new TrajetSimple(uneVilleDepart , uneVilleArrivee , unMoyTrans);					
				C->Ajouter_trajet(t);
				break;
			case 3: 
				cout << endl << "-------AJOUTER UN TRAJET COMPOSE-----\r\n" << endl;
				unTC = new TrajetCompose();
				i = 1;
				do {
					cout << "Entrez un trajet simple #" << i << endl;
					cout << "Entrez une ville du depart : ";
					getline(cin, uneVD, '\n');
					cout << "Entrez une ville d'arrivee : ";
					getline(cin, uneVA, '\n');
					cout << "Entrez un moyen de transport : ";
					getline(cin, unMoyTrans, '\n');
						
					t = new TrajetSimple(uneVD , uneVA , unMoyTrans);					
					if(unTC->Ajouter(t) ==false) {
						cout << "Erreur en ajoutant le trajet!" << endl;
					}else{
						i++;
					}
					
					cout << "Continue ? (1 pour oui et 0 pour non)";
					cin >> k;
					cin.get();
				}while(k == 1);
				C->Ajouter_trajet(unTC);
				break;		
			case 4:
				cout << endl << "--------RECHERCHER DES TRAJETS-----\r\n" << endl;
				cout << "Entrez une ville du depart : ";
				getline(cin, uneVilleDepart, '\n');
				cout << "Entrez une ville d'arrivee : ";
				getline(cin, uneVilleArrivee, '\n');
				C->Rechercher(uneVilleDepart , uneVilleArrivee);
				break;
			case 5:
				cout << endl << "--------RECHERCHE AVANCEE DES TRAJETS-----\r\n" << endl;
				cout << "Entrez une ville du depart : ";
				getline(cin, uneVilleDepart, '\n');
				cout << "Entrez une ville d'arrivee : ";
				getline(cin, uneVilleArrivee, '\n');
				C->Recherche_avancee(uneVilleDepart , uneVilleArrivee);
				break;
			case 6:	
				cout << endl << "--------AFFICHER TOUS LES TRAJETS DANS LE CATALOGUE---------\r\n" << endl;
				C->Afficher();
				break;			
			case 7:
				cout << "Vous voulez sauvegarder quels trajets ? " << endl ;
				cout << "1. Sauvegarde de tous les trajets. " << endl ;
				cout << "2. Sauvegarde de tous les trajets simples ou de trajets composes." << endl ;
				cout << "3. Sauvegarde de tous les trajets selon une ville de depart ou une ville d'arrivee." << endl ;
				cout << "4. Sauvegarde de (n - m + 1) trajets." << endl ;
				cout << "5. Quitter" << endl;
				cout << "Choississez un choix" << endl ;
				
				cin >> c_n;
				cin.get();
				n = c_n -'0';		
				
				switch(n) {
					case 1:
						saveToFile(C, "Trajets.txt", 1, "", "", "");
						break;
					case 2:
						cout << "1. Sauvegarde de tous les trajets simples" << endl;
						cout << "2. Sauvegarde de tous les trajets composes" << endl;
						cout << "3. Quitter" << endl;
						cout << "Veuillez choisir un choix" << endl;
						cin >> k;
						cin.get();
						if (k == 1) {
							saveToFile(C, "Trajets.txt", 2, "TS", "", "");
						}else if (k==2){
							saveToFile(C, "Trajets.txt", 2, "TC", "", "");
						}
						break;
					case 3:
						cout << "Entrez une ville du depart (Entrez Non/non si vous n'en avez pas besoin):";
						getline(cin, uneVilleDepart);
						cout << "Entrez une ville d'arrivee (Entrez Non/non si vous n'en avez pas besoin):";
						getline(cin, uneVilleArrivee);
						
						saveToFile(C, "Trajets.txt", 3, "",uneVilleDepart , uneVilleArrivee);
						break;
					case 4:
						break;
					
					default:
						break;
				}
				break;
			
			default:
				break;
		}
		
		if (n <1 || n>7) {
			break;
		}
			
		cout << endl << "Tapez Y ou y pour continuer : " << endl;
		cin >> c;				
	}while(c == 'Y' || c == 'y');
	

//	delete t;
//	delete unTC;
	delete C;
	
	
	return 0;
}
