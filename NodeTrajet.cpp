using namespace std;
#include "NodeTrajet.h"
#include <iostream>

NodeTrajet::NodeTrajet() {
	next = nullptr;
	trajet = new Trajet();
}

NodeTrajet::~NodeTrajet() {
	delete trajet;
	if(this->next != nullptr) {
		delete next;
	}
}
