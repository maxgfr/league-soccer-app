#ifndef AUTONOME_H
#define AUTONOME_H

#include "Joueur.h"
#include "Rupture.h"
#include "JoueurContract.h"
class Contrat;
class Rupture;

class Autonome :  public JoueurContract, public Joueur
{

private:
	Rupture *rupture;

public:

#pragma region Constructeur
	Autonome();
	Autonome(string, string, float, float, string, vector<Parcours*>, Rupture*, Contrat*);
	~Autonome();
#pragma endregion Constructeur

#pragma region Getter
	Rupture* getRupture();
#pragma endregion Getter

#pragma region Setter
	void setRupture(Rupture*);
#pragma endregion Setter

	void indiquerSonEtat();
};
#endif


