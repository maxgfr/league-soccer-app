#ifndef HETERONOME_H
#define HETERONOME_H

#include "Joueur.h"
#include "JoueurContract.h"
class Contrat;
class JoueurContract;

class Heteronome : public JoueurContract, public Joueur
{

private:
	int nbAnneeRestante;

public:
#pragma region Constructeur
	Heteronome();
	Heteronome(string, string, float, float, string, vector<Parcours*>, int, Contrat*);
	~Heteronome();
#pragma endregion Constructeur

#pragma region Getter
	int getNbAnRest();
#pragma endregion Getter

#pragma region Setter
	void setNbAnRest(int);
#pragma endregion Setter

	void indiquerSonEtat();
};
#endif