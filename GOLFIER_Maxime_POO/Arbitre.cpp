#include "stdafx.h"
#include "Arbitre.h"

#pragma region Constructeur
Arbitre::Arbitre()
{
}

Arbitre::Arbitre(string a, string b, string c, int d) : Sportif(a, b)
{
	setLieu(c);
	setXp(d);
}


Arbitre::~Arbitre()
{
}

#pragma endregion Constructeur

#pragma region Getter
string Arbitre::getLieu()
{
	return lieuObtention;
}

int Arbitre::getXp()
{
	return xpArbitrage;
}
#pragma endregion Getter

#pragma region Setter
void Arbitre::setLieu(string a)
{
	lieuObtention = a;
}

void Arbitre::setXp(int x)
{
	xpArbitrage = x;
}
#pragma endregion Setter