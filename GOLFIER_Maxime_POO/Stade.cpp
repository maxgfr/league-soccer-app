#include "stdafx.h"
#include "Stade.h"

#pragma region constructeur
Stade::Stade() //inutile
{
}

Stade::Stade(string n, string a, Qualite q, int pl)
{
	setNom(n);
	setAdresse(a);
	setQualite(q);
	nbplace = pl;
}

Stade::~Stade()
{
}
#pragma endregion constructeur

#pragma region getter
string Stade::getNom()
{
	return nom;
}

string Stade::getAdresse()
{
	return adresse;
}

Qualite Stade::getQualite()
{
	return qualite;
}

int Stade::getNbPlace()
{
	return nbplace;
}
#pragma endregion getter

#pragma region setter
void Stade::setNom(string n)
{
	nom = n;
}

void Stade::setAdresse(string a)
{
	adresse = a;
}

void Stade::setQualite(Qualite q)
{
	qualite = q;
}
#pragma endregion setter