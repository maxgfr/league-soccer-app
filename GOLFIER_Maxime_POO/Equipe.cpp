#include "stdafx.h"
#include "Equipe.h"


#pragma region Constructeur
Equipe::Equipe()
{
}

Equipe::Equipe(Club *c, int n, int g, Joueur *j)
{
	setClub(c);
	setNbJoueur(n);
	setNbGardien(g);
	setCapitaine(j);
}


Equipe::~Equipe()
{
	delete club;
	delete capitaine;
}
#pragma endregion Constructeur

#pragma region Getter
Club * Equipe::getClub()
{
	return club;
}

int Equipe::getNbJoueur()
{
	return nbJoueurTerrain;
}

int Equipe::getNbGardien()
{
	return nbGardiens;
}

Joueur * Equipe::getCapitaine()
{
	return capitaine;
}
#pragma endregion Getter

#pragma region Setter
void Equipe::setClub(Club *c)
{
	club = c;
}

void Equipe::setNbJoueur(int n)
{
	nbJoueurTerrain = n;
}

void Equipe::setNbGardien(int n)
{
	nbGardiens = n;
}

void Equipe::setCapitaine(Joueur *c)
{
	capitaine = c;
}
#pragma endregion Setter
