#include "stdafx.h"
#include "Palmares.h"

#pragma region constructeur
Palmares::Palmares() //inutile
{
}

Palmares::Palmares(string t, Type ty, Date *d)
{
	setTitre(t);
	setType(ty);
	setDate(d);
}


Palmares::~Palmares()
{
	delete obtention;
}
#pragma endregion constructeur

#pragma region getter
string Palmares::getTitre()
{
	return titre;
}

Type Palmares::getType()
{
	return type;
}

Date* Palmares::getDate()
{
	return obtention;
}
#pragma endregion getter

#pragma region setter
void Palmares::setTitre(string t)
{
	titre = t;
}

void Palmares::setType(Type t)
{
	type = t;
}

void Palmares::setDate(Date *d)
{
	obtention = d;
}
#pragma endregion setter

bool operator==(Palmares p1, Palmares p2) {
	if (p1.getTitre().compare(p2.getTitre()) == 0 ) {
		if (p1.getType() == p2.getType()) {
			return true;
		}else {
			return false;
		}
	}else {
		return false;
	}
}