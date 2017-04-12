#include "stdafx.h"
#include "negoAcheteur.h"

#pragma region Constructeur
NegoAcheteur::NegoAcheteur()
{
}

NegoAcheteur::NegoAcheteur(float mD, float mM, int d, Club *c, Mutex m) : Negociateur(mD, mM, d, c, m)
{
}

NegoAcheteur::~NegoAcheteur()
{
	//delete representantClub;  => a été supprimé dans la base class
}
#pragma endregion Constructeur

void NegoAcheteur::faireLeBusiness()
{
	//Le montant bloquant est le montant maximal
	Timer timer;
	float nouvMontant;

	timer.Start();
	
	while ((timer.GetTicks() / CLOCKS_PER_SEC) < dureeNegoc && !getEtat()) {

		getMutex().Synchroniser();

		if (getSauv()->isOkay()) // c'est okay pour le vendeur, le transfert à réussi
		{
			getSauv()->Offre("accepter", "acheteur", "Marche conclu", timer.GetTicks() / CLOCKS_PER_SEC, nouvMontant);
			setEtat(true);
		}

		nouvMontant = getMontantDesire() + (timer.GetTicks() / 500); //variation du montant

		if (nouvMontant < getMontantBloquant()) {	// plus petit que montant Max
			getSauv()->Offre("offre", "acheteur", "Je te propose une nouvelle offre", timer.GetTicks() / CLOCKS_PER_SEC, nouvMontant);
		} 

		else if (nouvMontant == getMontantBloquant()) {
			getSauv()->Offre("accepter", "acheteur", "Marche conclu", timer.GetTicks() / CLOCKS_PER_SEC, nouvMontant);
			setEtat(true);
		}

		else if (nouvMontant > getMontantBloquant()) { //plus grand que le montant Max, c'est trop cher
			getSauv()->Offre("refuser", "acheteur", "Je te propose ma derniere offre", timer.GetTicks() / CLOCKS_PER_SEC, nouvMontant);
			setEtat(true);
		}
		getSauv()->AfficheLastMessage();
		getMutex().Liberer();
	}
}
