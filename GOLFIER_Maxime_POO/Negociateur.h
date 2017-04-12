#ifndef NEGOCIATEUR_H
#define NEGOCIATEUR_H

#include "Message.h"
#include "Timer.h"
#include "Negociation.h"
#include "Club.h"
#include "Mutex.h"

#include <iostream>
#include <vector>

using namespace std;

class Negociateur
{

protected:
	float montantDesire;
	float montantBloquant;
	int dureeNegoc;
	Club *representantClub;
	bool etat;
	Mutex unMutex;
	Negociation *sauv;

public:
#pragma region Constructeur
	Negociateur();
	Negociateur(float, float, int, Club*,Mutex);
	~Negociateur();
#pragma endregion Constructeur

#pragma region Getter
	float getMontantDesire();
	float getMontantBloquant();
	int getDureeNegoc();
	Club* getClubRepresentant();
	bool getEtat();
	Mutex getMutex();
	Negociation* getSauv();
#pragma endregion Getter

#pragma region Setter
	void setMontantDesire(float);
	void setMontantMax(float);
	void setDureeNegoc(int);
	void setClubRepresentant(Club*);
	void setEtat(bool);
	void setMutex(Mutex);
	void setSauv(Negociation*);
#pragma endregion Setter

#pragma region fonction
	virtual void faireLeBusiness() = 0;
#pragma endregion fonction

};
#endif

