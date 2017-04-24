#ifndef NOUVOBJET_H
#define NOUVOBJET_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>

#include "Club.h"
#include "Date.h"
#include "Entraineur.h"
#include "Joueur.h"
#include "LigueSoccer.h"
#include "Palmares.h"
#include "Parcours.h"
#include "Stade.h"
#include "TitreGagne.h"
#include "Rencontre.h"
#include "Calendrier.h"
#include "Chargement.h"
#include "NegoAcheteur.h"
#include "NegoVendeur.h"
#include "Negociation.h"
#include "Mutex.h"
#include "Negociation.h"
#include "JoueurContract.h"
#include "Sauvegarde.h"
#include "Thread.h"
#include "Exception_Chiffre.h"

using namespace std;

class NouvObjet
{
public:
#pragma region nouvObjet
#pragma region TP1
	static Date * nouvDate();
	static Palmares * nouvPalm();
	static Joueur * nouvJoueur();
	static Parcours * nouvParcours();
	static Personne * nouvPersonne();
	static Stade * nouvStade();
	static Entraineur * nouvEntraineur(LigueSoccer *lg);
	static TitreGagne * nouvTitreGagne(LigueSoccer *lg);
	static Club * nouvClub(LigueSoccer *lg);
	static Club * nouvClubCherch(LigueSoccer *lg);
	static Club * nouvClubVide();
	static Joueur * nouvJoueurVide();
#pragma endregion TP1

#pragma region TP2
	static Rencontre * nouvRencontre(LigueSoccer *lg);
	static Match * nouvMatch(LigueSoccer *lg);
	static Equipe * nouvEquipe(LigueSoccer *lg);
	static Joueur * nouvJoueurCherch(Club * c);
	static Resultat * nouvRes(int, int);
	static Periode * nouvPeriode();
	static Contrat * nouvContrat(LigueSoccer * lg);
	static Rupture * nouvRupture(LigueSoccer * lg, Club *);
	static Reglement * nouvReglement();
	static Club * nouvEquipeCherche(LigueSoccer *, Calendrier *);
#pragma endregion TP2

#pragma region TP3
	static NegoAcheteur * nouvNegoAcheteur(LigueSoccer *lg, int duree, Mutex m, Negociation*);
	static NegoVendeur * nouvNegoVendeur(LigueSoccer *lg, int duree, Mutex m, Negociation*);
#pragma endregion TP3

#pragma endregion nouvObjet
};

#endif

