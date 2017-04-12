#include "stdafx.h"
#include "Rupture.h"

#pragma region Constructeur
Rupture::Rupture()
{
}

Rupture::Rupture(Joueur *a, string b, Club *c, float d)
{
	setJoueur(a);
	setRaisonDep(b);
	setNouvClub(c);
	setPenalite(d);
}


Rupture::~Rupture()
{
	delete joueur;
	delete nouvClub;
}
#pragma endregion Constructeur

#pragma region Getter
Joueur * Rupture::getJoueur()
{
	return joueur;
}

string Rupture::getRaisonDep()
{
	return raisonDep;
}

Club * Rupture::getNouvClub()
{
	return nouvClub;
}

float Rupture::getPenalite()
{
	return penalite;
}
#pragma endregion Getter

#pragma region Setter
void Rupture::setJoueur(Joueur *j)
{
	joueur = j;
}

void Rupture::setRaisonDep(string a)
{
	raisonDep = a;
}

void Rupture::setNouvClub(Club *c)
{
	nouvClub = c;
}

void Rupture::setPenalite(float p)
{
	penalite = p;
}
#pragma endregion Setter