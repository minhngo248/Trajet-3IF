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

//une méthode pour mettre les lettres en majuscule pour la comparaison de strings
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


// une méthode pour ajouter un trajet simple au catalogue
bool addTrajetSimple (Catalogue* C, string line, TrajetCompose* TC = nullptr, const int k =0, const string VD = "", const string VA = "") {
	bool bVD = (toUpper(VD) == "NON"); // Si l'utilisateur n'avez pas besoin de une ville de depart specifique
	bool bVA = (toUpper(VA) == "NON"); // Si l'utilisateur n'avez pas besoin de une ville d'arrivee specifique
	bool b = true;
	
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
			return b;
		}
	}
	
	TS = new TrajetSimple(membre[0],membre[1],membre[2]);
	if (TC == nullptr) {
		C->Ajouter_trajet(TS);
	}else{
		b = TC->Ajouter(TS);
	}
	return b;
}


// une méthode pour ajouter un trajet composé au catalogue
void addTrajetCompose (Catalogue* C, string line, const int k =0, const string VD = "", const string VA = "") {
	bool bVD = (toUpper(VD) == "NON"); // Si l'utilisateur n'avez pas besoin de une ville de depart specifique
	bool bVA = (toUpper(VA) == "NON"); // Si l'utilisateur n'avez pas besoin de une ville d'arrivee specifique
	bool addTS = true; // Si un trajet simple est ajouté avec succèss
	
	string characTrajet;	
	string delimiter = "; ";
	
	size_t pos = 0;	
	
	TrajetCompose* TC = new TrajetCompose();
	
	line.append(delimiter);
	while ((pos = line.find(delimiter)) != string::npos) {
		characTrajet = line.substr(0,pos);
		addTS = addTrajetSimple(C, characTrajet, TC);
		if (!addTS) {
			delete TC;
			return;
		}				
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


// Dans cette méthode, la variable k va décider nous sommes dans quel cas
void addFromFile(Catalogue* C, const string& fileName, const int k, const string trajet = "", const string VD = "", const string VA = "", unsigned int n =0, unsigned int m =0) {
	
	ifstream myFile;
	string line;
	string typeTrajet;
	
	string delimiter = ": ";
	size_t pos = 0;	
	
	int count = 1;
	
	TrajetSimple * TS;
	TrajetCompose* TC = nullptr;
	
	myFile.open(fileName);
	while (getline(myFile,line)) {
		pos = line.find(delimiter);
		if (pos == string::npos) {
			continue;
		}
		
		typeTrajet = line.substr(0, pos);
		line.erase(0, pos + delimiter.length());
		
		switch(k) {
			case 1:  //Chargement de tous les trajets
				if (typeTrajet == "TS") {
					addTrajetSimple(C, line);
				}
				else if (typeTrajet == "TC") {
					addTrajetCompose(C, line);	
				}
				break;
			case 2:  //Chargement des trajets selon leur type
				if (typeTrajet == "TS") {
					if (typeTrajet.compare("TS") ==0) {
						addTrajetSimple(C, line);
					}
				}
				else if (typeTrajet == "TC") {
					if (typeTrajet.compare("TC") ==0) {
						addTrajetCompose(C, line);
					}
				}
				break;
			case 3:  //Chargement des trajets selon leur ville de départ et/ou leur ville d'arrivée
				if (typeTrajet == "TS") {
					addTrajetSimple(C, line, TC, k, VD, VA);
				}
				else if (typeTrajet == "TC") {
					addTrajetCompose(C, line, k, VD, VA);	
				}
				break;
			default:  //Chargement des trajets selon leur position dans le fichier
				if ((typeTrajet == "TS" || typeTrajet == "TC") && count < n) {
					++count;
					continue;
				}
				if (typeTrajet == "TS" && count >= n && count <= m) {
					++count;
					addTrajetSimple(C, line);
				}
				else if (typeTrajet == "TC" && count >= n && count <= m) {
					++count;
					addTrajetCompose(C, line);
				}
				
				
		}		
	}
	if (k>3) {
		if (count <= n) {
			cout << endl << "Accuns trajets sont ajoutés au catalogue." << endl;
		}else {
			cout << endl << "Les trajets en position de " << n << " à " << count-1 << " sont ajoutés au catalogue." << endl;
		}	
	}
	myFile.close();
}


// Dans cette méthode, la variable k va décider nous sommes dans quel cas
void saveToFile (Catalogue* C, const string& fileName, const int k, const string trajet = "", const string VD = "", const string VA = "", unsigned int p=0, unsigned int m=0) {
	
	bool bVD = (toUpper(VD) == "NON"); // Si l'utilisateur n'avez pas besoin de une ville de depart specifique
	bool bVA = (toUpper(VA) == "NON"); // Si l'utilisateur n'avez pas besoin de une ville d'arrivee specifique
	
	ofstream myFile;
	NodeTrajet* n;
	TrajetSimple* TS;
	
	int count = 1;
	
	myFile.open(fileName, ios::app);
		
	n = C->GetList()->GetHead();
	switch(k) {
		case 1:  //Sauvegarde de tous les trajets
			while (n != nullptr) {
				n->GetTrajet()->FicWrite(myFile, 1);	
				n = n->GetNext();
			}
			break;
		case 2:  //Sauvegarde des trajets selon leur type
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
		case 3:  //Sauvegarde des trajets selon leur ville de départ et/ou leur ville d'arrivée
			while (n != nullptr) {
				if ((toUpper(n->GetTrajet()->GetVille(1)) == toUpper(VD) || bVD) && ((toUpper(n->GetTrajet()->GetVille(2)) == toUpper(VA) || bVA))) {
					n->GetTrajet()->FicWrite(myFile, 1);	
				}
				n = n->GetNext();
			}
			break;
		default:  //Sauvegarde des trajets selon leur position dans le fichier
			while (n != nullptr && count < p) {	
				n = n->GetNext();
				++count;
			}
			
			while (n != nullptr && count <= m) {
				n->GetTrajet()->FicWrite(myFile, 1);
				n = n->GetNext();
				++count;
			}
			
			if (count <= p) {
				cout << endl << "Accuns trajets sont sauvegardés." << endl;
			}else {
				cout << endl << "Les trajets en position de " << p << " à " << count-1 << " sont sauvegardés." << endl;
			}		
			break;
	}
	myFile.close();
}

int main() {
	char c, c_n;
	int n, m , i, k;
	bool quit = false;
	unsigned int p1, p2;
	
	string uneVilleDepart, uneVilleArrivee, unMoyTrans;
	Catalogue* C = new Catalogue();
	TrajetCompose* unTC;
	TrajetSimple* t;
	
	do {	
		//Menu
		cout << endl << "Veuillez choisir une demande \r\n" << endl;
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
						cout << endl << "Entrez un  n : ";
						cin >> n;
						cin.get();
						cout << "Entrez un nombre m : ";
						cin >> m;
						cin.get();
						addFromFile(C, "Trajets.txt", 4,"","","",n,m);
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
					getline(cin, uneVilleDepart, '\n');
					cout << "Entrez une ville d'arrivee : ";
					getline(cin, uneVilleArrivee, '\n');
					cout << "Entrez un moyen de transport : ";
					getline(cin, unMoyTrans, '\n');
						
					t = new TrajetSimple(uneVilleDepart , uneVilleArrivee , unMoyTrans);					
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
				C->Rechercher(toUpper(uneVilleDepart) , toUpper(uneVilleArrivee));
				break;
			case 5:
				cout << endl << "--------RECHERCHE AVANCEE DES TRAJETS-----\r\n" << endl;
				cout << "Entrez une ville du depart : ";
				getline(cin, uneVilleDepart, '\n');
				cout << "Entrez une ville d'arrivee : ";
				getline(cin, uneVilleArrivee, '\n');
				C->Recherche_avancee(toUpper(uneVilleDepart) , toUpper(uneVilleArrivee));
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
				cout << "4. Sauvegarde d'une intervalle de trajets [n,m]." << endl ;
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
						cout << endl << "Entrez la postion du premier trajet: ";
						cin >> p1;
						cin.get();
						cout << "Entrez la postion du dernier trajet: ";
						cin >> p2;
						cin.get();
						saveToFile(C,"Trajets.txt",4,"","","",p1,p2);
						break;
					
					default:
						break;
				}
				break;
			
			default:
				quit = true;
				break;
		}
		
		if (quit) {
			break;
		}
			
		cout << endl << "Tapez Y ou y pour continuer : " << endl;
		cin >> c;				
	} while(c == 'Y' || c == 'y');
	
	delete C;
		
	return 0;
}
