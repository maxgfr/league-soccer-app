#ifndef NEGOACHETEUR_H
#define NEGOACHETEUR_H

#include "Negociateur.h"

class NegoAcheteur : public Negociateur
{
public:
#pragma region Constructeur
	NegoAcheteur();
	NegoAcheteur(float, float, int, Club*,Mutex);
	~NegoAcheteur();
#pragma endregion Constructeur

#pragma region Transfert	
	void faireLeBusiness();
#pragma endregion Transfert

};

#endif

