#ifndef TITREGAGNE_H
#define TITREGAGNE_H

#include "Club.h"
#include "Palmares.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

class TitreGagne
{
private:
	vector<Palmares*> ensPalm;
	Club* club;

public:

#pragma region Constructeur
	TitreGagne();
	TitreGagne(vector<Palmares*>, Club*);
	~TitreGagne();
#pragma endregion Constructeur

#pragma region Getter
	vector<Palmares*> getEnsPalm();
	Club* getClub();
#pragma endregion Getter

#pragma region Setter
	void setEnsPalm(vector<Palmares*>);
	void setClub(Club*);
#pragma endregion Setter

	void AjoutPalm(Palmares*);
	void SupprimerPalm(Palmares *);
	int rechPalm(Palmares *);
};

#endif

