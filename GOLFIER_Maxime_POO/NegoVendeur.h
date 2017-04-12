#ifndef NEGOVENDEUR_H
#define NEGOVENDEUR_H

#include "Negociateur.h"

class NegoVendeur : public Negociateur
{
public:
#pragma region Constructeur
	NegoVendeur();
	NegoVendeur(float, float, int, Club*,Mutex);
	~NegoVendeur();
#pragma endregion Constructeur

#pragma region Transfert	
	void faireLeBusiness();
#pragma endregion Transfert

};

#endif
