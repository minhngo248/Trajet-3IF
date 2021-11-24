#include "NodeTrajet.h"
#include <iostream>

NodeTrajet::NodeTrajet() {
	next = NULL;
}

NodeTrajet::~NodeTrajet() {
	delete trajet;
	if(next!= nullptr) {
		delete next;
	}
}
