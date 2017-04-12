#ifndef MATCH_H
#define MATCH_H

#include "Equipe.h"
#include "Palmares.h"
#include "Periode.h"
#include "Resultat.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

class Match
{

private:
	Equipe *equipeLocale;
	Equipe *equipeInvite;
	vector<Periode*> listPeriode;
	Resultat *resFinal;

public:
#pragma region Constructeur
	Match();
	Match(Equipe*, Equipe*, vector<Periode*>, Resultat*);
	~Match();
#pragma endregion Constructeur

#pragma region Getter
	Equipe* getEquipeLocale();
	Equipe* getEquipeInvite();
	vector<Periode*> getListePeriode();
	Resultat* getResFinal();
#pragma endregion Getter

#pragma region Setter
	void setEquipeLocale(Equipe*);
	void setEquipeInvite(Equipe*);
	void setListePeriode(vector<Periode*>);
	void setResFinal(Resultat*);
#pragma endregion Setter
};

#endif

