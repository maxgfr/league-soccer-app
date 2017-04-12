#include "stdafx.h"
#include "Parcours.h"

#pragma region constructeur
Parcours::Parcours() //inutile
{
}

Parcours::Parcours(string n, string na, Date *d)
{
	setNomClub(n);
	setNomCluActuel(na);
	setDate(d);
}

Parcours::~Parcours()
{
	delete dpassage;
}
#pragma endregion constructeur

#pragma region getter
string Parcours::getNomClub()
{
	return nomClub;
}

string Parcours::getNomClubActuel()
{
	return nomClubAcuel;
}

Date* Parcours::getDate()
{
	return dpassage;
}
#pragma endregion getter

#pragma region setter
void Parcours::setNomClub(string n)
{
	nomClub = n;
}

void Parcours::setNomCluActuel(string na)
{
	nomClubAcuel = na;
}

void Parcours::setDate(Date* dp)
{
	dpassage = dp;
}
#pragma endregion setter
