#ifndef CLUB_H
#define CLUB_H

#include "Date.h"
#include "Personne.h"
#include "Joueur.h"
#include "Stade.h"
#include "Palmares.h"
#include "Rupture.h"
#include "Contrat.h"
#include "Autonome.h"
#include "Heteronome.h"
class Rupture;
class Contrat;

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

class Club
{
private:
	string nom;
	string histoireClub;
	string couleurClub;
	Date *anneeCreation;
	vector<Joueur *> effectif;
	Stade *stadeDuClub;
	string villeDuClub;
	string adresseClub;
	vector<Personne *> staff;
	vector<Palmares*> palmares;
	vector<Contrat*> contrats;
	vector<Rupture*> ruptures;
public:

#pragma region Constructeur
	Club();
	Club(string, string, string, Date*, vector<Joueur*>, Stade*, string, string, vector<Personne*>, vector<Palmares*>);
	Club(string, string, string, Date*, vector<Joueur*>, Stade*, string, string, vector<Personne*>, vector<Palmares*>, vector<Contrat*>, vector<Rupture*>);
	~Club();
#pragma endregion Constructeur

#pragma region Getter
	string getHistoire();
	vector<Palmares*> getPalmares();
	string getNom();
	string getCouleur();
	Date* getAnnee();
	vector<Joueur*> getEffectif();
	Stade* getStadeDuClub();
	string getVilleDuClub();
	string getAdresseClub();
	vector<Personne*> getStaff();
	vector<Contrat*> getContrat();
	vector<Rupture*> getRupture();
#pragma endregion Getter

#pragma region Setter
	void setHistoire(string);
	void setNom(string);
	void setPalmares(vector<Palmares*>);
	void setCouleur(string);
	void setAnnee(Date*);
	void setEffectif(vector<Joueur*>);
	void setStadeDuClub(Stade*);
	void setVilleDuClub(string);
	void setAdresseClub(string);
	void setStaff(vector<Personne*>);
	void setContrat(vector<Contrat*>);
	void setRupture(vector<Rupture*>);
#pragma endregion Setter

	void AjoutStaff(Personne *);
	void AjoutContrat(Contrat *);
	void AjoutJoueur(Joueur *);
	void AjoutRupture(Rupture *);
	void SupprimerJoueur(Joueur *);
	void SupprimerPersonne(Personne *);
	void SupprimerContrat(Contrat *);
	void SupprimerRupture(Rupture *);
	int RechJoueur(Joueur *);
	int RechJoueurParNom(string);
	int RechPersonne(Personne *);
	int RechPersonneParNom(string);
	int RechContrat(Contrat *);
	int RechRupture(Rupture *);

	bool operator==(const Club &) const;

};

#endif

