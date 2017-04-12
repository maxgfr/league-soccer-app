#ifndef RENCONTRE_H
#define RENCONTRE_H

#include "Date.h"
#include "Club.h"
#include "Match.h"


class Rencontre
{

private: 
	Date *dateMatch;
	Club *clubReceveur;
	Club *clubAdverse;
	Match *resMatch;

public:

#pragma region Constructeur
	Rencontre();
	Rencontre(Date*, Club*, Club*, Match*);
	~Rencontre();
#pragma endregion Constructeur

#pragma region Getter
	Date* getDateMatch();
	Club* getClubReceveur();
	Club* getClubAdverse();
	Match* getResMatch();
#pragma endregion Getter

#pragma region Setter
	void setDateMatch(Date*);
	void setClubReceveur(Club*);
	void setClubAdverse(Club*);
	void setResMatch(Match*);
#pragma endregion Setter
};

#endif