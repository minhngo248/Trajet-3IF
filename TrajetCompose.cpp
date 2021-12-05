/*************************************************************************
                           TrajetCompose
                             -------------------
    début                : 23 novembre 2021
    copyright            : (C) 2021 par NGO Ngoc Minh, PHAM Quoc Viet
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose() {
	listeSimple = new ListeTrajet();
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //------ Fin de TrajetCompose

TrajetCompose::TrajetCompose(const TrajetCompose & unTC) {
	strcpy(villeDepart, unTC.villeDepart);
	strcpy(villeArrivee, unTC.villeArrivee);
	this->listeSimple->SetHead(unTC.listeSimple->GetHead());
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
} //------ Fin de TrajetCompose (constructeur de copie)

TrajetCompose::~TrajetCompose() {
	delete listeSimple;	
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif	
} //------ Fin de ~TrajetCompose

//----------------------------------------------------- Méthodes publiques

bool TrajetCompose::Ajouter(TrajetSimple* unTS) {
	bool b =false;
	if (listeSimple->GetHead()->GetTrajet()->GetVille(1)[0] == '\0') {
		strcpy(villeDepart, unTS->GetVille(1));
		listeSimple->Ajouter_en_queue(unTS);
		strcpy(villeArrivee, unTS->GetVille(2));
		b = true;
	}else{
		NodeTrajet* p = listeSimple->GetLastNode();
		if (strcmp(p->GetTrajet()->GetVille(2), unTS->GetVille(1)) ==0) {
			listeSimple->Ajouter_en_queue(unTS);
			strcpy(villeArrivee, unTS->GetVille(2));
			b = true;
		}
	}
	return b;
} // -------- Fin de Methode


void TrajetCompose::GetTrajet( char* villeStart , char* villeFinish ) const{
	NodeTrajet* p = listeSimple->GetHead();
	if (listeSimple->GetHead()->GetTrajet()->GetVille(1)[0] != '\0') {
		strcpy(villeStart, p->GetTrajet()->GetVille(1));
		while(p->GetNext() != nullptr) {
			p = p->GetNext();
		}
		strcpy(villeFinish , p->GetTrajet()->GetVille(2));
	}	
} // -------- Fin de Methode

void TrajetCompose::Afficher(const int i) const {
	cout << "TC: ";
	NodeTrajet* p = listeSimple->GetHead();
	while (p != NULL) {
		p->GetTrajet()->Afficher(0);
		if (p->GetNext() != NULL) {
			cout << " - ";
		}
		p = p->GetNext();
	} 
	cout << endl;
} // -------- Fin de Methode


