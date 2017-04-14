#include "stdafx.h"
#include "NegoVendeur.h"
#include <math.h>

#define PUISSANCE_NEGO 1000

#pragma region Constructeur

NegoVendeur::NegoVendeur()
{
}

NegoVendeur::NegoVendeur(float mD, float mM, int d, Club *c, Mutex m, Negociation *nego) : Negociateur(mD, mM, d, c,m,nego)
{
}

NegoVendeur::~NegoVendeur()
{
	//tout a été supprimé dans la base class
}
#pragma endregion Constructeur

void NegoVendeur::faireLeBusiness()
{
	//Le montant bloquant est le montant minimal ici
	Timer timer;
	float nouvMontant,prixAdverse;
	
	timer.Start();

	while ((timer.GetTicks() / CLOCKS_PER_SEC) < dureeNegoc && !getEtat()) 
	{
		getMutex().Synchroniser();

		nouvMontant = getMontantDesire() - (timer.GetTicks() / PUISSANCE_NEGO); //variation du prix
		
		prixAdverse = getSauv()->GetLastMontant();

		if (nouvMontant <= prixAdverse && prixAdverse != NULL) { // c'est okay pour l'acheteur, le transfert à réussi
			getSauv()->Offre("accepter", "vendeur", "Marche conclu", timer.GetTicks() / CLOCKS_PER_SEC, nouvMontant);
			setEtat(true);
			return;
		}

		if (getSauv()->isDeception()) { // si l'acheteur refuse........
			getSauv()->Offre("refuser", "vendeur", "Bah si t'as pas assez de sous, tu peux pas l'acheter mon pote !", timer.GetTicks() / CLOCKS_PER_SEC, nouvMontant);
			setEtat(true);
			return;
		}
		

		if (nouvMontant > getMontantBloquant()) {	// plus grand que le montant Minimal
			getSauv()->Offre("offre", "vendeur", "Je te propose un nouveau prix", timer.GetTicks() / CLOCKS_PER_SEC, nouvMontant);
		} else { // plus petit que le montant Minimal, on peut pas aller plus bas.. (y)
			getSauv()->Offre("refuser", "vendeur", "Je peux pas descendre plus bas...", timer.GetTicks() / CLOCKS_PER_SEC, nouvMontant);
			setEtat(true);
			return;
		}
		
		getMutex().Liberer();
	}

}