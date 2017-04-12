#ifndef CALENDRIER_H
#define CALENDRIER_H

#include "Rencontre.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

class Calendrier
{

private :
	vector<Rencontre*> listRencontre;

public:

#pragma region Constructeur
	Calendrier();
	Calendrier(vector<Rencontre*>);
	~Calendrier();
#pragma endregion Constructeur

#pragma region Getter
	vector<Rencontre*> getListeRencontre();
#pragma endregion Getter

#pragma region Setter
	void setListeRencontre(vector<Rencontre*>);
#pragma endregion Setter

	void AjoutRencontre(Rencontre*);
	void SupprimerRencontre(Rencontre *c);
	Rencontre* RechRencontre(Date*, string);
	int RechEquipe(string nom);
	vector<Rencontre*> RencontrePourUnClub(string);
};

#endif

