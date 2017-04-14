#ifndef CONTRAT_H
#define CONTRAT_H

#include "Reglement.h"
#include "Date.h"
class Joueur;
class Club;

class Contrat
{

private:
	Joueur *joueurContractant;
	Club *clubContractant;
	Club *clubLibere;
	int dureeContrat;
	Date *dateEntree;
	Reglement *reglement;
	Date *dateContrat;

public:
#pragma region Constructeur
	Contrat();
	Contrat(Joueur*, Club*, Club*, int, Date*, Reglement*, Date*);
	~Contrat();
#pragma endregion Constructeur

#pragma region Getter
	Joueur* getJoueurContractant();
	Club* getClubContractant();
	Club* getClubLibere();
	int getDureeContrat();
	Date* getDateEntree();
	Reglement* getReglement();
	Date* getDateContrat();
#pragma endregion Getter

#pragma region Setter
	void setJoueurContractant(Joueur*);
	void setClubContractant(Club*);
	void setClubLibere(Club*);
	void setDureeContrat(int);
	void setDateEntree(Date*);
	void setReglement(Reglement*);
	void setDateContrat(Date*);
#pragma endregion Setter

};

#endif

