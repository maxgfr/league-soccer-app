#ifndef ENTRAINEUR_H
#define ENTRAINEUR_H

#include "TitreGagne.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

class Entraineur : public Sportif
{
private:
	vector<TitreGagne*> listeTitre;

public:

#pragma region Constructeur
	Entraineur();
	Entraineur(string, string,vector<TitreGagne*>);
	~Entraineur();
#pragma endregion Constructeur

#pragma region Getter
	vector<TitreGagne*> getListeTitre();
#pragma endregion Getter

#pragma region Setter
	void setListeTitre(vector<TitreGagne*>);
#pragma endregion Setter

	void AjoutTitre(TitreGagne *);
	void SupprimerTitre(TitreGagne *);
	int rechPalm(TitreGagne *);

};

#endif

