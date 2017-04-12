#include "stdafx.h"
#include "Personne.h"

#pragma region constructeur
Personne::Personne()
{
}

Personne::Personne(string n, int a, float p, Metier m)
{
	setMetier(m);
	setNom(n);
	setAge(a);
	setPoids(p);
}


Personne::~Personne()
{
}
#pragma endregion constructeur


#pragma region getter
Metier Personne::getMetier()
{
	return metier;
}
string Personne::getNom()
{
	return nom;
}

int Personne::getAge()
{
	return age;
}

float Personne::getPoids()
{
	return poids;
}
#pragma endregion getter


#pragma region setter
void Personne::setMetier(Metier m)
{
	metier = m;
}
void Personne::setNom(string n)
{
	nom = n;
}

void Personne::setAge(int a)
{
	age = a;
}

void Personne::setPoids(float p)
{
	poids = p;
}
#pragma endregion setter
