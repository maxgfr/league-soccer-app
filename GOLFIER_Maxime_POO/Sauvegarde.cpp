#include "stdafx.h"
#include "Sauvegarde.h"

inline string IntToString(const int &val)
{
	stringstream unflux;
	unflux << val;
	return unflux.str();
}

void Sauvegarde::EnregistrerJoueur(vector<Joueur*> liste, string nomClub)
{
	string taille, nom, prenom, ville, poids;
	vector<Joueur*>::iterator it;
	ofstream fichierJoueurs("../joueurs.txt", ios::app);

	fichierJoueurs.write(nomClub.c_str(), (streamsize)nomClub.size());
	if (liste.size() > 0) {
		fichierJoueurs.write("\n", 1);
	}

	for (it = liste.begin(); it != liste.end(); it++)
	{
		taille = IntToString(static_cast<int>((*it)->getTaille()));
		nom = (*it)->getNom();
		prenom = (*it)->getNom();
		ville = (*it)->getNom();
		poids = IntToString(static_cast<int>((*it)->getTaille()));
		vector<Parcours*> vec = (*it)->getParcoursJoueur();		

		fichierJoueurs.write(nom.c_str(), (streamsize)nom.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(prenom.c_str(), (streamsize)prenom.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(ville.c_str(), (streamsize)ville.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(taille.c_str(), (streamsize)taille.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(poids.c_str(), (streamsize)poids.size());
		fichierJoueurs.write("%", 1);
		EnregistrerParcours(vec, nomClub);
	}

	fichierJoueurs.write("\n", 1);
	fichierJoueurs.write(("FIN"+nomClub).c_str(), (streamsize)nomClub.size() + 3);
	fichierJoueurs.write("\n", 1);

	fichierJoueurs.close();
}

void Sauvegarde::EnregistrerParcours(vector<Parcours*> liste, string nomClu) {
	string jour, mois, annee, nomClubAct, nomClub;
	vector<Parcours*>::iterator it;
	ofstream fichierJoueurs("../parcours.txt", ios::app);

	fichierJoueurs.write(nomClu.c_str(), (streamsize)nomClu.size());
	if (liste.size() > 0) {
		fichierJoueurs.write("\n", 1);
	}

	for (it = liste.begin(); it != liste.end(); it++)
	{
		nomClubAct = (*it)->getNomClubActuel();
		nomClub = (*it)->getNomClub();
		jour = IntToString((*it)->getDate()->getJour());
		mois = IntToString((*it)->getDate()->getMois());
		annee = IntToString((*it)->getDate()->getAnnee());

		fichierJoueurs.write(nomClubAct.c_str(), (streamsize)nomClubAct.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(nomClub.c_str(), (streamsize)nomClub.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(jour.c_str(), (streamsize)jour.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(mois.c_str(), (streamsize)mois.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(annee.c_str(), (streamsize)annee.size());
		fichierJoueurs.write("%", 1);
	}

	fichierJoueurs.write("\n", 1);
	fichierJoueurs.write(("FIN" + nomClu).c_str(), (streamsize)nomClu.size() + 3);
	fichierJoueurs.write("\n", 1);

	fichierJoueurs.close();
}

void Sauvegarde::EnregistrerPersonne(vector<Personne*> liste, string nomClub) {
	string age, metier, nom, poids;
	vector<Personne*>::iterator it;
	ofstream fichierJoueurs("../personne.txt", ios::app);

	fichierJoueurs.write(nomClub.c_str(), (streamsize)nomClub.size());
	if (liste.size() > 0) {
		fichierJoueurs.write("\n", 1);
	}

	for (it = liste.begin(); it != liste.end(); it++)
	{
		age = IntToString((*it)->getAge());
		metier = IntToString(static_cast<int>((*it)->getMetier()));
		nom = (*it)->getNom();
		poids = IntToString(static_cast<int>((*it)->getPoids()));

		fichierJoueurs.write(nom.c_str(), (streamsize)nom.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(age.c_str(), (streamsize)age.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(metier.c_str(), (streamsize)metier.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(poids.c_str(), (streamsize)poids.size());
		fichierJoueurs.write("%", 1);
	}

	fichierJoueurs.write("\n", 1);
	fichierJoueurs.write(("FIN" + nomClub).c_str(), (streamsize)nomClub.size() + 3);
	fichierJoueurs.write("\n", 1);

	fichierJoueurs.close();
}

void Sauvegarde::EnregistrerPalmares(vector<Palmares*> liste, string nomClub) {
	string titre, type, jour, mois, annee;
	vector<Palmares*>::iterator it;
	ofstream fichierJoueurs("../palmares.txt", ios::app);

	fichierJoueurs.write(nomClub.c_str(), (streamsize)nomClub.size());
	if (liste.size() > 0) {
		fichierJoueurs.write("\n", 1);
	}

	for (it = liste.begin(); it != liste.end(); it++)
	{
		titre = (*it)->getTitre();
		type = IntToString(static_cast<int>((*it)->getType()));
		jour = IntToString((*it)->getDate()->getJour());
		mois = IntToString((*it)->getDate()->getMois());
		annee = IntToString((*it)->getDate()->getAnnee());

		fichierJoueurs.write(titre.c_str(), (streamsize)titre.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(type.c_str(), (streamsize)type.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(jour.c_str(), (streamsize)jour.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(mois.c_str(), (streamsize)mois.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(annee.c_str(), (streamsize)annee.size());
		fichierJoueurs.write("%", 1);

	}

	fichierJoueurs.write("\n", 1);
	fichierJoueurs.write(("FIN" + nomClub).c_str(), (streamsize)nomClub.size() + 3);
	fichierJoueurs.write("\n", 1);

	fichierJoueurs.close();
}

void Sauvegarde::EnregistrerContrat(vector<Contrat*> liste, string nomClub) {
	string adresse1, nom1, couleur1, histoire1, ville1;
	string adresse2, nom2, couleur2, histoire2, ville2;
	string nomj, prenomj, taillej, villej;
	string des, montantE, montantR, montantT, montantSeuil;
	string jour1, mois1, annee1;
	string jour2, mois2, annee2;
	string duree;
	vector<Contrat*>::iterator it;
	ofstream fichierJoueurs("../contrat.txt", ios::app);

	fichierJoueurs.write(nomClub.c_str(), (streamsize)nomClub.size());
	if (liste.size() > 0) {
		fichierJoueurs.write("\n", 1);
	}

	for (it = liste.begin(); it != liste.end(); it++)
	{
		adresse1 = (*it)->getClubContractant()->getAdresseClub();
		nom1 = (*it)->getClubContractant()->getNom();
		couleur1 = (*it)->getClubContractant()->getCouleur();
		histoire1 = (*it)->getClubContractant()->getHistoire();
		ville1 = (*it)->getClubContractant()->getVilleDuClub();

		adresse2 = (*it)->getClubLibere()->getAdresseClub();
		nom2 = (*it)->getClubLibere()->getNom();
		couleur2 = (*it)->getClubLibere()->getCouleur();
		histoire2 = (*it)->getClubLibere()->getHistoire();
		ville2 = (*it)->getClubLibere()->getVilleDuClub();

		nomj = (*it)->getJoueurContractant()->getNom();
		prenomj = (*it)->getJoueurContractant()->getPrenom();
		taillej = IntToString(static_cast<int>((*it)->getJoueurContractant()->getTaille()));
		villej = (*it)->getJoueurContractant()->getVilleNaissance();

		des = (*it)->getReglement()->getDescriptionDroit();
		montantE = IntToString(static_cast<int>((*it)->getReglement()->getMontantEncaisse()));
		montantR = IntToString(static_cast<int>((*it)->getReglement()->getMontantRestant()));
		montantT = IntToString(static_cast<int>((*it)->getReglement()->getMontantTransfert()));
		montantSeuil = IntToString(static_cast<int>((*it)->getReglement()->getSeuilVigueur()));


		jour1 = IntToString((*it)->getDateContrat()->getJour());
		mois1 = IntToString((*it)->getDateContrat()->getJour());
		annee1 = IntToString((*it)->getDateContrat()->getJour());

		jour2 = IntToString((*it)->getDateEntree()->getJour());
		mois2 = IntToString((*it)->getDateEntree()->getJour());
		annee2 = IntToString((*it)->getDateEntree()->getJour());

		duree = IntToString((*it)->getDureeContrat());

		fichierJoueurs.write(adresse1.c_str(), (streamsize)adresse1.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(nom1.c_str(), (streamsize)nom1.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(couleur1.c_str(), (streamsize)couleur1.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(histoire1.c_str(), (streamsize)histoire1.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(ville1.c_str(), (streamsize)ville1.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(adresse2.c_str(), (streamsize)adresse2.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(nom2.c_str(), (streamsize)nom2.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(couleur2.c_str(), (streamsize)couleur2.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(histoire2.c_str(), (streamsize)histoire2.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(ville2.c_str(), (streamsize)ville2.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(nomj.c_str(), (streamsize)nomj.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(prenomj.c_str(), (streamsize)prenomj.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(taillej.c_str(), (streamsize)taillej.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(villej.c_str(), (streamsize)villej.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(des.c_str(), (streamsize)des.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(montantE.c_str(), (streamsize)montantE.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(montantR.c_str(), (streamsize)montantR.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(montantT.c_str(), (streamsize)montantT.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(montantSeuil.c_str(), (streamsize)montantSeuil.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(jour1.c_str(), (streamsize)jour1.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(mois1.c_str(), (streamsize)mois1.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(annee1.c_str(), (streamsize)annee1.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(jour2.c_str(), (streamsize)jour2.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(mois2.c_str(), (streamsize)mois2.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(annee2.c_str(), (streamsize)annee2.size());
		fichierJoueurs.write("%", 1);	
	}

	fichierJoueurs.write("\n", 1);
	fichierJoueurs.write(("FIN" + nomClub).c_str(), (streamsize)nomClub.size() + 3);
	fichierJoueurs.write("\n", 1);

	fichierJoueurs.close();
}

void Sauvegarde::EnregistrerRupture(vector<Rupture*> liste, string nomClub) {
	string adresse1, nom1, couleur1, histoire1, ville1;
	string nomj, prenomj, taillej, villej;
	string penalite;
	string raison;
	vector<Rupture*>::iterator it;
	ofstream fichierJoueurs("../rupture.txt", ios::app);

	fichierJoueurs.write(nomClub.c_str(), (streamsize)nomClub.size());
	if (liste.size() > 0) {
		fichierJoueurs.write("\n", 1);
	}

	for (it = liste.begin(); it != liste.end(); it++)
	{
		raison = (*it)->getRaisonDep();
		penalite = IntToString(static_cast<int>((*it)->getPenalite()));

		adresse1 = (*it)->getNouvClub()->getAdresseClub();
		nom1 = (*it)->getNouvClub()->getNom();
		couleur1 = (*it)->getNouvClub()->getCouleur();
		histoire1 = (*it)->getNouvClub()->getHistoire();
		ville1 = (*it)->getNouvClub()->getVilleDuClub();

		nomj = (*it)->getJoueur()->getNom();
		prenomj = (*it)->getJoueur()->getPrenom();
		taillej = IntToString(static_cast<int>((*it)->getJoueur()->getTaille()));
		villej = (*it)->getJoueur()->getVilleNaissance();

		fichierJoueurs.write(raison.c_str(), (streamsize)raison.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(penalite.c_str(), (streamsize)penalite.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(adresse1.c_str(), (streamsize)adresse1.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(nom1.c_str(), (streamsize)nom1.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(couleur1.c_str(), (streamsize)couleur1.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(histoire1.c_str(), (streamsize)histoire1.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(ville1.c_str(), (streamsize)ville1.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(nomj.c_str(), (streamsize)nomj.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(prenomj.c_str(), (streamsize)prenomj.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(taillej.c_str(), (streamsize)taillej.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(villej.c_str(), (streamsize)villej.size());
		fichierJoueurs.write("%", 1);
	}

	fichierJoueurs.write("\n", 1);
	fichierJoueurs.write(("FIN" + nomClub).c_str(), (streamsize)nomClub.size() + 3);
	fichierJoueurs.write("\n", 1);

	fichierJoueurs.close();
}

void Sauvegarde::EnregistrerClub(vector<Club*> liste) {
	string adresse1, nom1, couleur1, histoire1, ville1;
	string jour, mois, annee;
	string adresseS, nomS, qualiteS;
	vector<Club*>::iterator it;
	ofstream fichierJoueurs("../club.txt", ios::out);

	//vider les fichiers pour la sauvegarde grâce à l'ouverture en out
	ofstream fichierA("../rupture.txt", ios::out);
	ofstream fichierB("../contrat.txt", ios::out);
	ofstream fichierC("../palmares.txt", ios::out);
	ofstream fichierD("../personne.txt", ios::out);
	ofstream fichierE("../parcours.txt", ios::out);
	ofstream fichierF("../joueurs.txt", ios::out);
	fichierA.close();
	fichierB.close();
	fichierC.close();
	fichierD.close();
	fichierE.close();
	fichierF.close();
	// Fin de l'effacement

	for (it = liste.begin(); it != liste.end(); it++)
	{
		adresse1 = (*it)->getAdresseClub();
		nom1 = (*it)->getNom();
		couleur1 = (*it)->getCouleur();
		histoire1 = (*it)->getHistoire();
		ville1 = (*it)->getVilleDuClub();

		jour = IntToString((*it)->getAnnee()->getJour());
		mois = IntToString((*it)->getAnnee()->getMois());
		annee = IntToString((*it)->getAnnee()->getAnnee());

		EnregistrerJoueur((*it)->getEffectif(),nom1);
		EnregistrerPersonne((*it)->getStaff(),nom1);
		EnregistrerPalmares((*it)->getPalmares(),nom1);
		EnregistrerContrat((*it)->getContrat(),nom1);
		EnregistrerRupture((*it)->getRupture(),nom1);

		adresseS = (*it)->getStadeDuClub()->getAdresse();
		nomS = (*it)->getStadeDuClub()->getNom();
		qualiteS = IntToString(static_cast<int>((*it)->getStadeDuClub()->getQualite()));

		fichierJoueurs.write(adresse1.c_str(), (streamsize)adresse1.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(nom1.c_str(), (streamsize)nom1.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(couleur1.c_str(), (streamsize)couleur1.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(histoire1.c_str(), (streamsize)histoire1.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(ville1.c_str(), (streamsize)ville1.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(jour.c_str(), (streamsize)jour.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(mois.c_str(), (streamsize)mois.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(annee.c_str(), (streamsize)annee.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(adresseS.c_str(), (streamsize)adresseS.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(nomS.c_str(), (streamsize)nomS.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write(qualiteS.c_str(), (streamsize)qualiteS.size());
		fichierJoueurs.write("%", 1);
		fichierJoueurs.write("\n", 1);
	}
	fichierJoueurs.close();
}