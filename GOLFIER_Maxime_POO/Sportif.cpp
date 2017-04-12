#include "stdafx.h"
#include "Sportif.h"

#pragma region Constructeur
Sportif::Sportif()
{

}

Sportif::Sportif(string n, string p)
{
	setNom(n);
	setPrenom(p);
}


Sportif::~Sportif()
{
}
#pragma endregion Constructeur

#pragma region Getter
string Sportif::getNom()
{
	return nom;
}

string Sportif::getPrenom()
{
	return prenom;
}
#pragma endregion Getter

#pragma region Setter
void Sportif::setNom(string n)
{
	nom = n;
}

void Sportif::setPrenom(string p)
{
	prenom = p;
}
#pragma endregion Setter

