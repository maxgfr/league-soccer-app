#include "stdafx.h"
#include "Reglement.h"

#pragma region Constructeur
Reglement::Reglement()
{
}

Reglement::Reglement(float a, string b, float c, float d, float e)
{
	setSeuilVigueur(a);
	setDescriptionDroit(b);
	setMontantTransfert(c);
	setMontantEncaisse(d);
	setMontantRestant(e);
}


Reglement::~Reglement()
{
}
#pragma endregion Constructeur

#pragma region Getter
float Reglement::getSeuilVigueur()
{
	return seuilVigueur;
}

string Reglement::getDescriptionDroit()
{
	return descriptionDroit;
}

float Reglement::getMontantTransfert()
{
	return montantTransfert;
}

float Reglement::getMontantEncaisse()
{
	return montantEncaisse;
}

float Reglement::getMontantRestant()
{
	return montantRestant;
}
#pragma endregion Getter

#pragma region Setter
void Reglement::setSeuilVigueur(float a)
{
	seuilVigueur = a;
}

void Reglement::setDescriptionDroit(string d)
{
	descriptionDroit = d;
}

void Reglement::setMontantTransfert(float m)
{
	montantTransfert = m;
}

void Reglement::setMontantEncaisse(float e)
{
	montantEncaisse = e;
}

void Reglement::setMontantRestant(float r)
{
	montantRestant = r;
}
#pragma endregion Setter
