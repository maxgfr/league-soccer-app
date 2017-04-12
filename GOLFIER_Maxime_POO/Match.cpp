#include "stdafx.h"
#include "Match.h"

#pragma region Constructeur
Match::Match()
{
}

Match::Match(Equipe *e1, Equipe *e2, vector<Periode*> v, Resultat *r)
{
	setEquipeLocale(e1);
	setEquipeInvite(e2);
	setListePeriode(v);
	setResFinal(r);
}


Match::~Match()
{
	delete equipeLocale;
	delete equipeInvite;
	delete resFinal;
	for_each(listPeriode.begin(), listPeriode.end(), default_delete<Periode>());
}
#pragma endregion Constructeur

#pragma region Getter
Equipe * Match::getEquipeLocale()
{
	return equipeLocale;
}

Equipe * Match::getEquipeInvite()
{
	return equipeInvite;
}

vector<Periode*> Match::getListePeriode()
{
	return listPeriode;
}

Resultat * Match::getResFinal()
{
	return resFinal;
}
#pragma endregion Getter

#pragma region Setter
void Match::setEquipeLocale(Equipe *e)
{
	equipeLocale = e;
}

void Match::setEquipeInvite(Equipe *e)
{
	equipeInvite = e;
}

void Match::setListePeriode(vector<Periode*> l)
{
	listPeriode = l;
}

void Match::setResFinal(Resultat *r)
{
	resFinal = r;
}
#pragma endregion Setter