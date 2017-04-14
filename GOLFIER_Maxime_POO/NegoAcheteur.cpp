#include "stdafx.h"
#include "negoAcheteur.h"
#include <math.h>

#define PUISSANCE_NEGO 1000

#pragma region Constructeur
NegoAcheteur::NegoAcheteur()
{
}

NegoAcheteur::NegoAcheteur(float mD, float mM, int d, Club *c, Mutex m, Negociation *sauv) : Negociateur(mD, mM, d, c, m, sauv)
{
}

NegoAcheteur::~NegoAcheteur()
{
	//tout a été supprimé dans la base class
}
#pragma endregion Constructeur

void NegoAcheteur::faireLeBusiness()
{
	//Le montant bloquant est le montant maximal
	Timer timer;
	float nouvMontant,prixAdverse;

	timer.Start();
	
	while ((timer.GetTicks() / CLOCKS_PER_SEC) < dureeNegoc && !getEtat()) {

		getMutex().Synchroniser();

		nouvMontant = getMontantDesire() + (timer.GetTicks() / PUISSANCE_NEGO); //variation du montant

		prixAdverse = getSauv()->GetLastMontant();

		if (nouvMontant >= prixAdverse && prixAdverse != NULL) { // c'est okay pour le vendeur, le transfert à réussi
			getSauv()->Offre("accepter", "acheteur", "Marche conclu", timer.GetTicks() / CLOCKS_PER_SEC, nouvMontant);
			setEtat(true);
			return;
		}

		if (getSauv()->isDeception()) { // si le vendeur refuse........
			getSauv()->Offre("refuser", "acheteur", "Tu demandes trop de sous la ! Je suis desole mais le transfert est fini !", timer.GetTicks() / CLOCKS_PER_SEC, nouvMontant);
			setEtat(true);
			return;
		}

		if (nouvMontant <= getMontantBloquant()) {	// plus petit que montant Max
			getSauv()->Offre("offre", "acheteur", "Je te propose une nouvelle offre", timer.GetTicks() / CLOCKS_PER_SEC, nouvMontant);
			
		} else { //plus grand que le montant Max, c'est trop cher
			getSauv()->Offre("refuser", "acheteur", "Je peux pas aller plus haut....", timer.GetTicks() / CLOCKS_PER_SEC, nouvMontant);
			setEtat(true);
			return;
		}
		
		getMutex().Liberer();
	}
}
