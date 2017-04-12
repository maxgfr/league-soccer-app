#ifndef ARBITRE_H
#define ARBITRE_H

#include "Sportif.h"

class Arbitre : public Sportif
{

private:
	string lieuObtention;
	int xpArbitrage;

public:
#pragma region Constructeur
	Arbitre();
	Arbitre(string, string, string, int);
	~Arbitre();
#pragma endregion Constructeur

#pragma region Getter
	string getLieu();
	int getXp();
#pragma endregion Getter

#pragma region Setter
	void setLieu(string);
	void setXp(int);
#pragma endregion Setter
};

#endif
