#include "stdafx.h"
#include "NegoVendeur.h"

#pragma region Constructeur

NegoVendeur::NegoVendeur()
{
}

NegoVendeur::NegoVendeur(float mD, float mM, int d, Club *c, Mutex m) : Negociateur(mD, mM, d, c,m)
{
}

NegoVendeur::~NegoVendeur()
{
	//delete representantClub; => a été supprimé dans la base class
}
#pragma endregion Constructeur

void NegoVendeur::faireLeBusiness()
{
	//Le montant bloquant est le montant minimal ici
	Timer timer;
	float nouvMontant;
	
	timer.Start();

	while ((timer.GetTicks() / CLOCKS_PER_SEC) < dureeNegoc && !getEtat()) 
	{
		getMutex().Synchroniser();

		if (getSauv()->isOkay()) // c'est okay pour l'acheteur, le transfert à réussi
		{
			getSauv()->Offre("accepter", "vendeur", "Marche conclu", timer.GetTicks() / CLOCKS_PER_SEC, nouvMontant);
			setEtat(true);
		}

		nouvMontant = getMontantDesire() - (timer.GetTicks() / 500); //variation du prix

		if (nouvMontant > getMontantBloquant()) {	// plus grand que le montant Minimal
			getSauv()->Offre("offre", "vendeur", "Je te propose un nouveau prix", timer.GetTicks() / CLOCKS_PER_SEC, nouvMontant);
		}

		else if (nouvMontant == getMontantBloquant()) {
			getSauv()->Offre("accepter", "vendeur", "Marche conclu", timer.GetTicks() / CLOCKS_PER_SEC, nouvMontant);
			setEtat(true);
		}

		else if (nouvMontant < getMontantBloquant()){ // plus petit que le montant Minimal, on peut pas aller plus bas.. (y)
			getSauv()->Offre("refuser", "vendeur", "Je peux pas descendre plus bas...", timer.GetTicks() / CLOCKS_PER_SEC, nouvMontant);
			setEtat(true);
		}

		getSauv()->AfficheLastMessage();
		getMutex().Liberer();
	}

}