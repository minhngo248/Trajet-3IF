#if ! defined (NODE_TRAJET_H)
#define NODE_TRAJET_H

#include "Trajet.h"

class NodeTrajet 
{
	public:
		NodeTrajet* next;
		Trajet trajet; 
	public:
		NodeTrajet();
};

#endif
