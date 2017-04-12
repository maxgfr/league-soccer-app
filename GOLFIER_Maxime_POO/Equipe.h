#ifndef EQUIPE_H
#define EQUIPE_H

#include "Club.h"
#include "Joueur.h"

class Equipe
{

private:
	Club *club;
	int nbJoueurTerrain;
	int nbGardiens;
	Joueur *capitaine;

public:

#pragma region Constructeur
	Equipe();
	Equipe(Club*, int, int, Joueur*);
	~Equipe();
#pragma endregion Constructeur

#pragma region Getter
	Club* getClub();
	int getNbJoueur();
	int getNbGardien();
	Joueur* getCapitaine();
#pragma endregion Getter

#pragma region Setter
	void setClub(Club*);
	void setNbJoueur(int);
	void setNbGardien(int);
	void setCapitaine(Joueur*);
#pragma endregion Setter
};

#endif