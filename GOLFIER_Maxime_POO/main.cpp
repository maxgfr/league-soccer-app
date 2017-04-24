#include "stdafx.h"
#include "Affichage.h"
#include "LigueSoccer.h"
#include "Calendrier.h"

#include <iostream>

using namespace std;

//GOLFIER Maxime GOLM16039801
int main()
{
	LigueSoccer *lg = new LigueSoccer();
	Calendrier *cal = new Calendrier();
	Affichage::choixPrincipal(lg, cal);
	delete cal;
	delete lg;
	return 0;
}

