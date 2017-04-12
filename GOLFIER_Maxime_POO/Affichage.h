#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "NouvObjet.h"

class Affichage
{
public:

#pragma region menu

	static void choixPrincipal(LigueSoccer*,Calendrier*);
	static char menuPrincipal();

#pragma region TP1
	static void choixClub(LigueSoccer *lg);
	static char menuClub();
	static void rechercheClub(LigueSoccer *lg);
	static char menuRechercheClub();
#pragma endregion TP1

#pragma region TP2
	static void choixTransf(LigueSoccer *lg, Calendrier *cal);
	static char menuTransf();
	static void rechercheTransf(LigueSoccer *lg, Calendrier *cal);
	static char menuRechercheTransf();
#pragma endregion TP2

#pragma endregion menu

#pragma region fonction
#pragma region TP1
	static void AjoutClub(LigueSoccer *lg);
	static void SuppresionClub(LigueSoccer *lg);
	static void AjoutEntraineur(LigueSoccer *lg);
	static void SuppresionEntraineur(LigueSoccer *lg);
	static void AfficherAllClub(LigueSoccer *lg);
	static void AfficherAllEntraineur(LigueSoccer *lg);
	static void AfficherJoueurClub(LigueSoccer *lg);
	static void AfficherClubLePlusTitre(LigueSoccer *lg);
	static void AfficherUnEntraineur(LigueSoccer * lg, Entraineur * c);
	static void AfficherUnClub(LigueSoccer * lg, Club * c);
	static void AfficherEntraineurLePlusTitre(LigueSoccer *lg);
#pragma endregion TP1

#pragma region TP2
	static void AjoutCalendrier(LigueSoccer *lg, Calendrier *cal);
	static void MajCalendrier(LigueSoccer *lg, Calendrier *cal);
	static void TransacEngagement(LigueSoccer *lg, Calendrier *cal);
	static void TransacRupture(LigueSoccer *lg, Calendrier *cal);
	static void CreaMatch(LigueSoccer *lg, Calendrier *cal);
	static void AfficherUnRencontre(LigueSoccer *lg, Rencontre *c);
	static void AfficherTousRencontre(LigueSoccer * lg, Calendrier * cal);
	static void AfficherRencontreClub(LigueSoccer *lg, Calendrier *cal);
	static void AfficherMontantTransfClub(LigueSoccer *lg, Calendrier *cal);
	static void AfficherResClub(LigueSoccer *lg, Calendrier *cal);
#pragma endregion TP2

#pragma region TP3
	static void CreerNegociation(LigueSoccer *lg);
#pragma endregion TP3

#pragma region Chargement
	static void chargeAll(LigueSoccer*, Calendrier*);
	static void sauvAll(LigueSoccer *, Calendrier *);
#pragma endregion Chargement
#pragma endregion fonction

};

#endif

