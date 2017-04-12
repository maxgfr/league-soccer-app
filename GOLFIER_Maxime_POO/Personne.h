#ifndef PERSONNE_H
#define PERSONNE_H

#include <iostream>
#include <vector>
#include "Enum_Metier.h"

using namespace std;

class Personne
{
protected:
	string nom;
	int age;
	float poids;
	Metier metier;

public:

#pragma region Constructeur
	Personne();
	Personne(string, int, float, Metier);
	~Personne();
#pragma endregion Constructeur

#pragma region Getter
	Metier getMetier();
	string getNom();
	int getAge();
	float getPoids();
#pragma endregion Getter

#pragma region Setter
	void setMetier(Metier);
	void setNom(string);
	void setAge(int);
	void setPoids(float);
#pragma endregion Setter
};

#endif

