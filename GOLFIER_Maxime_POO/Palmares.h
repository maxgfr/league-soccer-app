#ifndef PALMARES_H
#define PALMARES_H

#include "Date.h"
#include "Enum_Type.h"
#include <iostream>
using namespace std;

class Palmares
{

private:
	string titre;
	Type type;
	Date *obtention;

public:

#pragma region Constructeur
	Palmares();
	Palmares(string, Type, Date*);
	~Palmares();
#pragma endregion Constructeur

#pragma region Getter
	string getTitre();
	Type getType();
	Date* getDate();
#pragma endregion Getter

#pragma region Setter
	void setTitre(string);
	void setType(Type);
	void setDate(Date*);
#pragma endregion Setter

	friend bool operator==(Palmares, Palmares);
};

#endif

