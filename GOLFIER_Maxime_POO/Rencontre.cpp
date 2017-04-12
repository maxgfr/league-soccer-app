#include "stdafx.h"
#include "Rencontre.h"

#pragma region Constructeur
Rencontre::Rencontre()
{
}

Rencontre::Rencontre(Date *d, Club *c, Club *cc, Match *m)
{
	setDateMatch(d);
	setClubReceveur(c);
	setClubAdverse(cc);
	setResMatch(m);
}


Rencontre::~Rencontre()
{
	delete dateMatch;
	delete clubReceveur;
	delete clubAdverse;
	delete resMatch;
}
#pragma endregion Constructeur

#pragma region Getter
Date * Rencontre::getDateMatch()
{
	return dateMatch;
}

Club * Rencontre::getClubReceveur()
{
	return clubReceveur;
}

Club * Rencontre::getClubAdverse()
{
	return clubAdverse;
}

Match * Rencontre::getResMatch()
{
	return resMatch;
}
#pragma endregion Getter

#pragma region Setter
void Rencontre::setDateMatch(Date *d)
{
	dateMatch = d;
}

void Rencontre::setClubReceveur(Club *c)
{
	clubReceveur = c;
}

void Rencontre::setClubAdverse(Club *c)
{
	clubAdverse = c;
}

void Rencontre::setResMatch(Match *r)
{
	resMatch = r;
}
#pragma endregion Setter