#ifndef STADE_H
#define STADE_H


#include <iostream>
#include "Enum_Qualite.h"
using namespace std;

class Stade
{

private:
	string nom;
	string adresse;
	Qualite qualite;
	int nbplace;

public:

#pragma region Constructeur
	Stade();
	Stade(string, string, Qualite, int);
	~Stade();
#pragma endregion Constructeur

#pragma region Getter
	string getNom();
	string getAdresse();
	Qualite getQualite();
	int getNbPlace();
#pragma endregion Getter

#pragma region Setter
	void setNom(string);
	void setAdresse(string);
	void setQualite(Qualite);
#pragma endregion Setter

};

#endif

