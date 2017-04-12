#include "stdafx.h"
#include "Periode.h"

#pragma region Constructeur
Periode::Periode()
{
}

Periode::Periode(int a, int b, int c)
{
	setDuree(a);
	setButLocal(b);
	setButAdverse(c);
}


Periode::~Periode()
{
}
#pragma endregion Constructeur

#pragma region Getter
int Periode::getDuree()
{
	return duree;
}

int Periode::getButLocal()
{
	return butMarquesLocal;
}

int Periode::getButAdverse()
{
	return butMarquesAdverse;
}
#pragma endregion Getter

#pragma region Setter
void Periode::setDuree(int d)
{
	duree = d;
}

void Periode::setButLocal(int n)
{
	butMarquesLocal = n;
}

void Periode::setButAdverse(int n)
{
	butMarquesAdverse = n;
}
#pragma endregion Setter