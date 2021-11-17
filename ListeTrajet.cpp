/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include "ListeTrajet.h"

//-------------------------------------------- Constructeurs - destructeur
ListeTrajet::ListeTrajet() {
	head = new NodeTrajet();
	head = NULL;	
}

void ListeTrajet::ajouter_en_tete(Trajet trajet) {
	if (head == NULL) {
		head->trajet = trajet;
		head->next = NULL;
	}
	else {
		NodeTrajet* p = new NodeTrajet();
		p->trajet = trajet;
		p->next = head;
		head = p;
	}
}

Xxx::Xxx ( const Xxx & unXxx )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif
} //----- Fin de Xxx (constructeur de copie)


Xxx::Xxx ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Xxx>" << endl;
#endif
} //----- Fin de Xxx


Xxx::~Xxx ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} //----- Fin de ~Xxx


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

