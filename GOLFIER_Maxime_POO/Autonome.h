#ifndef AUTONOME_H
#define AUTONOME_H

#include "Joueur.h"
#include "JoueurContract.h"
#include "Rupture.h"

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


