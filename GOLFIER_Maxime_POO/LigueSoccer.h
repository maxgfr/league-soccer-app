#ifndef LIGUESOCCER_H
#define LIGUESOCCER_H

#include "Club.h"
#include "Entraineur.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

class LigueSoccer
{

private:
	vector<Club*> listClub;
	vector<Entraineur*> listEntraineur;

public:

#pragma region Constructeur
	LigueSoccer();
	LigueSoccer(vector<Club*>,vector<Entraineur*>);
	~LigueSoccer();
#pragma endregion Constructeur

#pragma region Getter
	vector<Club*> getListeClub();
	vector<Entraineur*> getListeEntraineur();
#pragma endregion Getter

#pragma region Setter
	void setListeClub(vector<Club*>);
	void setListeEntraineur(vector<Entraineur*>);
#pragma endregion Setter

	void AjoutClub(Club *);
	void AjoutEntraineur(Entraineur *);
	void SupprimerClub(Club *);
	void SupprimerEntraineur(Entraineur *);
	int RechClub(string);
	int RechEntraineur(string);
	int RechClubPlusTitre();
	int RechEntraineurPlusTitre();
	void MajTransac(Contrat*);
	void MajRupture(Rupture*, Club*);

};

#endif


