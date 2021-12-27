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

string toUpper (const string& str) {
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

void addTrajetSimple (Catalogue* C, string line, TrajetCompose* TC = nullptr, const int k =0, const string VD = "", const string VA = "") {
	bool bVD = (toUpper(VD) == "NON"); // Si l'utilisateur n'avez pas besoin de une ville de depart specifique
	bool bVA = (toUpper(VA) == "NON"); // Si l'utilisateur n'avez pas besoin de une ville d'arrivee specifique
	
	string delimiter = ", ";
	string* membre = new string[3];
	
	size_t pos = 0;
	int i =0;
	
	TrajetSimple * TS;
	
	line.append(delimiter);
	while ((pos = line.find(delimiter)) != string::npos) {
		membre[i] = line.substr(0, pos);
		line.erase(0, pos + delimiter.length());
		i++;
	}
	
	if (k ==3) {
		if (!((toUpper(membre[0]) == VD || bVD) && (toUpper(membre[1]) == VA || bVA))) {
			return;
		}
	}
	
	TS = new TrajetSimple(membre[0],membre[1],membre[2]);
	if (TC == nullptr) {
		C->Ajouter_trajet(TS);
	}else{
		TC->Ajouter(TS);
	}
}

void addTrajetCompose (Catalogue* C, string line, const int k =0, const string VD = "", const string VA = "") {
	bool bVD = (toUpper(VD) == "NON"); // Si l'utilisateur n'avez pas besoin de une ville de depart specifique
	bool bVA = (toUpper(VA) == "NON"); // Si l'utilisateur n'avez pas besoin de une ville d'arrivee specifique
	
	string characTrajet;	
	string delimiter = "; ";
	
	size_t pos = 0;	
	
	TrajetCompose* TC = new TrajetCompose();
	
	line.append(delimiter);
	while ((pos = line.find(delimiter)) != string::npos) {
		characTrajet = line.substr(0,pos);
		addTrajetSimple(C, characTrajet, TC);				
		line.erase(0, pos + delimiter.length());
	}
	if (k ==3) {
		if (!((toUpper(TC->GetVille(1)) == toUpper(VD) || bVD) && (toUpper(TC->GetVille(2)) == toUpper(VA) || bVA))) {
			delete TC;
			return;
		}
	}
	C->Ajouter_trajet(TC);
}

void addFromFile(Catalogue* C, const string& fileName, const int k, const string trajet = "", const string VD = "", const string VA = "") {
	
	ifstream myFile;
	string line;
	string typeTrajet;
	
	string delimiter = ": ";
	size_t pos = 0;	
	
	TrajetSimple * TS;
	TrajetCompose* TC = nullptr;
	
	myFile.open(fileName);
	while (getline(myFile,line)) {
		pos = line.find(delimiter);
		typeTrajet = line.substr(0, pos);
		line.erase(0, pos + delimiter.length());
		
		switch(k) {
			case 1:
				if (typeTrajet.compare("TS") ==0) {
					addTrajetSimple(C, line);
				}
				else {
					addTrajetCompose(C, line);	
				}
				break;
			case 2:
				if (trajet.compare("TS") ==0) {
					if (typeTrajet.compare("TS") ==0) {
						addTrajetSimple(C, line);
					}
				}else{
					if (typeTrajet.compare("TC") ==0) {
						addTrajetCompose(C, line);
					}
				}
				break;
			case 3:
				if (typeTrajet.compare("TS") ==0) {
					addTrajetSimple(C, line, TC, k, VD, VA);
				}
				else {
					addTrajetCompose(C, line, k, VD, VA);	
				}
			case 4:
				break;
			default:
				break;
		}		
	}
	myFile.close();
}

void saveToFile (Catalogue* C, const string& fileName, const int k, const string trajet = "", const string VD = "", const string VA = "") {
	
	bool bVD = (toUpper(VD) == "NON"); // Si l'utilisateur n'avez pas besoin de une ville de depart specifique
	bool bVA = (toUpper(VA) == "NON"); // Si l'utilisateur n'avez pas besoin de une ville d'arrivee specifique
	
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
				if ((toUpper(n->GetTrajet()->GetVille(1)) == toUpper(VD) || bVD) && ((toUpper(n->GetTrajet()->GetVille(2)) == toUpper(VA) || bVA))) {
					n->GetTrajet()->FicWrite(myFile, 1);	
				}
				n = n->GetNext();
			}
			break;
		default:
			break;
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
				cout << endl << "-------CHARGEMENT D'UN CATALOGUE DE TRAJETS-----\r\n" << endl;
				cout << "Vous voulez charger quels trajets ? " << endl ;
				cout << "1. Chargement de tous les trajets. " << endl ;
				cout << "2. Chargement de tous les trajets simples ou de trajets composes." << endl ;
				cout << "3. Chargement de tous les trajets selon une ville de depart ou une ville d'arrivee." << endl ;
				cout << "4. Chargement de (n - m + 1) trajets." << endl ;
				cout << "5. Quitter" << endl;
				cout << endl << "Choississez un choix" << endl ;
				
				cin >> c_n;
				cin.get();
				n = c_n -'0';
				
				switch(n) {
					case 1:
						addFromFile(C, "Trajets.txt", 1);
						break;
					case 2:
						cout << "1. Chargement de tous les trajets simples" << endl;
						cout << "2. Chargement de tous les trajets composes" << endl;
						cout << "3. Quitter" << endl;
						cout << "Veuillez choisir un choix" << endl;
						cin >> k;
						cin.get();
						if (k == 1) {
							addFromFile(C, "Trajets.txt", 2, "TS");
						}else if (k==2){
							addFromFile(C, "Trajets.txt", 2, "TC");
						}
						break;
					case 3:
						cout << "Entrez une ville du depart (Entrez Non/non si vous n'en avez pas besoin): ";
						getline(cin, uneVilleDepart);
						cout << "Entrez une ville d'arrivee (Entrez Non/non si vous n'en avez pas besoin): ";
						getline(cin, uneVilleArrivee);
						
						addFromFile(C, "Trajets.txt", 3, "",uneVilleDepart , uneVilleArrivee);
						break;
					case 4:
						break;
					
					default:
						break;
			
				}	
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
				cout << endl << "-------SAUVEGARDE DU CATALOGUE COURANT-----\r\n" << endl;
				cout << "Vous voulez sauvegarder quels trajets ? " << endl ;
				cout << "1. Sauvegarde de tous les trajets. " << endl ;
				cout << "2. Sauvegarde de tous les trajets simples ou de trajets composes." << endl ;
				cout << "3. Sauvegarde de tous les trajets selon une ville de depart ou une ville d'arrivee." << endl ;
				cout << "4. Sauvegarde de (n - m + 1) trajets." << endl ;
				cout << "5. Quitter" << endl;
				cout << endl << "Choississez un choix" << endl ;
				
				cin >> c_n;
				cin.get();
				n = c_n -'0';		
				
				switch(n) {
					case 1:
						saveToFile(C, "Trajets.txt", 1);
						break;
					case 2:
						cout << "1. Sauvegarde de tous les trajets simples" << endl;
						cout << "2. Sauvegarde de tous les trajets composes" << endl;
						cout << "3. Quitter" << endl;
						cout << "Veuillez choisir un choix" << endl;
						cin >> k;
						cin.get();
						if (k == 1) {
							saveToFile(C, "Trajets.txt", 2, "TS");
						}else if (k==2){
							saveToFile(C, "Trajets.txt", 2, "TC");
						}
						break;
					case 3:
						cout << "Entrez une ville du depart (Entrez Non/non si vous n'en avez pas besoin): ";
						getline(cin, uneVilleDepart);
						cout << "Entrez une ville d'arrivee (Entrez Non/non si vous n'en avez pas besoin): ";
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
	} while(c == 'Y' || c == 'y');
	
	delete C;
		
	return 0;
}
