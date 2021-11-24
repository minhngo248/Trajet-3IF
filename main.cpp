#include <iostream>
using namespace std;
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"

int main() {
	Trajet * t = new TrajetSimple("Paris", "Lyon", "Avion");
//	t->afficher();
	Catalogue C;
	C.ajouter_trajet(t);
	C.afficher();
	return 0;
}
