#include "stdafx.h"
#include "Resultat.h"

#pragma region Constructeur
Resultat::Resultat()
{
}

Resultat::Resultat(int n, int m)
{
	setNbLocal(n);
	setNbAdverse(m);
}


Resultat::~Resultat()
{
}
#pragma endregion Constructeur

#pragma region Getter
int Resultat::getNbLocal()
{
	return nbTotButLocal;
}

int Resultat::getNbAdverse()
{
	return nbTotButAdverse;
}
#pragma endregion Getter

#pragma region Setter
void Resultat::setNbLocal(int n)
{
	nbTotButLocal = n;
}

void Resultat::setNbAdverse(int n)
{
	nbTotButAdverse = n;
}
#pragma endregion Setter
