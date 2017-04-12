#ifndef PARCOURS_H
#define PARCOURS_H

#include "Date.h"
#include <iostream>
using namespace std;

class Parcours
{

private:
	string nomClub;
	string nomClubAcuel;
	Date *dpassage;

public:

#pragma region Constructeur
	Parcours();
	Parcours(string, string, Date*);
	~Parcours();
#pragma endregion Constructeur

#pragma region Getter
	string getNomClub();
	string getNomClubActuel();
	Date* getDate();
#pragma endregion Getter

#pragma region Setter
	void setNomClub(string);
	void setNomCluActuel(string);
	void setDate(Date*);
#pragma endregion Setter

};

#endif

