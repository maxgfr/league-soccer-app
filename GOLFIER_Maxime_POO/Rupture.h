#ifndef RUPTURE_H
#define RUPTURE_H

#include "Club.h"
class Club;

class Rupture
{
private:
	Joueur *joueur;
	string raisonDep;
	Club *nouvClub;
	float penalite;

public:

#pragma region Constructeur
	Rupture();
	Rupture(Joueur*, string, Club*, float);
	~Rupture();
#pragma endregion Constructeur

#pragma region Getter
	Joueur* getJoueur();
	string getRaisonDep();
	Club* getNouvClub();
	float getPenalite();
#pragma endregion Getter

#pragma region Setter
	void setJoueur(Joueur*);
	void setRaisonDep(string);
	void setNouvClub(Club*);
	void setPenalite(float);
#pragma endregion Setter
};

#endif