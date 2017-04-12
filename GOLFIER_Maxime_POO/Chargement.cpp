#include "stdafx.h"
#include "Chargement.h"

vector<Joueur*> Chargement::ChargerJoueur(string debut) {
	char *nxtok, *line = new char[500];
	Joueur *unJoueur;
	vector<Joueur*> listeJoueurs;
	string r, fin,s;
	fin = "FIN" + debut;
	bool bol = false;
	ifstream fichierJoueurs("../joueurs.txt", ios::in);
	while (!fichierJoueurs.eof()) {
		fichierJoueurs.getline(line, 500);
		if (strlen(line) > 0) {
			r = strtok_s(line, "%", &nxtok);
			if (r.compare(debut) == 0 || bol == true) {
				bol = true;
				fichierJoueurs.getline(line, 500);
				if (r.compare(fin) == 0) return listeJoueurs;
				s = strtok_s(line, "%", &nxtok);
				unJoueur = new Joueur();
				unJoueur->setNom(s);
				unJoueur->setPrenom(strtok_s(NULL, "%", &nxtok));
				unJoueur->setVilleNaissance(strtok_s(NULL, "%", &nxtok));
				unJoueur->setTaille(static_cast<float>(atof((strtok_s(NULL, "%", &nxtok)))));
				unJoueur->setPoids(static_cast<float>(atof((strtok_s(NULL, "%", &nxtok)))));
				unJoueur->setParcoursJoueur(ChargerParcours(debut));
				listeJoueurs.push_back(unJoueur);
			}
		}
	}
	fichierJoueurs.close();
	delete[] line;
	return listeJoueurs;
}

vector<Parcours*> Chargement::ChargerParcours(string debut) {
	char *nxtok, *line = new char[500];
	int jour, mois, annee;
	Parcours *unParcours;
	vector<Parcours*> listeParcours;
	Date *d;
	string r,fin,s;
	fin = "FIN" + debut;
	bool bol = false;
	ifstream fichierJoueurs("../parcours.txt", ios::in);
	while (!fichierJoueurs.eof()) {
		jour = mois = annee = 0;
		fichierJoueurs.getline(line, 500);
		if (strlen(line) > 0) {
			r = strtok_s(line, "%", &nxtok);
			if (r.compare(debut) == 0 || bol == true) {
				bol = true;
				fichierJoueurs.getline(line, 500);
				s = strtok_s(line, "%", &nxtok);
				if (r.compare(fin) == 0 || fin.compare(s)==0) return listeParcours;
				unParcours = new Parcours();
				unParcours->setNomCluActuel(s);
				unParcours->setNomClub(strtok_s(NULL, "%", &nxtok));
				jour = atoi(strtok_s(NULL, "%", &nxtok));
				mois = atoi(strtok_s(NULL, "%", &nxtok));
				annee = atoi(strtok_s(NULL, "%", &nxtok));
				d = new Date(jour, mois, annee);
				unParcours->setDate(d);
				listeParcours.push_back(unParcours);
			}	
		}
	}
	fichierJoueurs.close();
	delete[] line;
	return listeParcours;
}

vector<Personne*> Chargement::ChargerPersonne(string debut) {
	char *nxtok, *line = new char[500];
	Personne *unePersonne;
	vector<Personne*> listePersonne;
	string r, fin,s;
	fin = "FIN" + debut;
	bool bol = false;
	ifstream fichierJoueurs("../personne.txt", ios::in);
	while (!fichierJoueurs.eof()) {
		fichierJoueurs.getline(line, 500);
		if (strlen(line) > 0) {
			r = strtok_s(line, "%", &nxtok);
			if (r.compare(debut) == 0 || bol == true) {
				bol = true;
				fichierJoueurs.getline(line, 500);
				s = strtok_s(line, "%", &nxtok);
				if (r.compare(fin) == 0 || fin.compare(s)==0) return listePersonne;
				unePersonne = new Personne();
				unePersonne->setNom(s);
				unePersonne->setAge(atoi(strtok_s(NULL, "%", &nxtok)));
				unePersonne->setMetier((Metier)atoi(strtok_s(NULL, "%", &nxtok)));			
				unePersonne->setPoids(static_cast<float>(atof((strtok_s(NULL, "%", &nxtok)))));
				listePersonne.push_back(unePersonne);
			}
		}
	}
	fichierJoueurs.close();
	delete[] line;
	return listePersonne;
}

vector<Palmares*> Chargement::ChargerPalmares(string debut) {
	char *nxtok, *line = new char[500];
	Palmares *unPalmares;
	vector<Palmares*> listePalmares;
	Date *d;
	int jour, mois, annee;
	string r, fin,s;
	fin = "FIN" + debut;
	bool bol = false;
	ifstream fichierJoueurs("../palmares.txt", ios::in);
	while (!fichierJoueurs.eof()) {
		fichierJoueurs.getline(line, 500);
		jour = mois = annee = 0;
		if (strlen(line) > 0) {
			r = strtok_s(line, "%", &nxtok);
			if (r.compare(debut) == 0 || bol == true) {
				bol = true;
				fichierJoueurs.getline(line, 500);
				s = strtok_s(line, "%", &nxtok);
				if (r.compare(fin) == 0 || fin.compare(s) ==0) return listePalmares;
				unPalmares = new Palmares();
				unPalmares->setTitre(s);
				unPalmares->setType((Type)atoi(strtok_s(NULL, "%", &nxtok)));
				jour = atoi(strtok_s(NULL, "%", &nxtok));
				mois = atoi(strtok_s(NULL, "%", &nxtok));
				annee = atoi(strtok_s(NULL, "%", &nxtok));
				d = new Date(jour, mois, annee);
				unPalmares->setDate(d);

				listePalmares.push_back(unPalmares);
			}
		}
	}
	fichierJoueurs.close();
	delete[] line;
	return listePalmares;
}

vector<Contrat*> Chargement::ChargerContrat(string debut) {
	char *nxtok, *line = new char[5000];
	Contrat *unContrat;
	vector<Contrat*> listeCOntrat;
	Date *d1;
	Date *d2;
	Reglement *reg;
	Club *unClub;
	Club *un2Club;
	Joueur *joueur;
	string r, fin,s;
	fin = "FIN" + debut;
	bool bol = false;
	int jour1, mois1, annee1, jour2,mois2,annee2;
	ifstream fichierJoueurs("../contrat.txt", ios::in);
	while (!fichierJoueurs.eof()) {
		fichierJoueurs.getline(line, 500);
		jour1 = mois1 = annee1 = 0;
		jour2 = mois2 = annee2 = 0;
		if (strlen(line) > 0) {
			r = strtok_s(line, "%", &nxtok);
			if (r.compare(debut) == 0 || bol == true) {
				bol = true;
				fichierJoueurs.getline(line, 500);
				s = strtok_s(line, "%", &nxtok);
				if (r.compare(fin)==0 || fin.compare(s)==0) return listeCOntrat;
				unContrat = new Contrat();

				unClub = new Club();
				unClub->setAdresseClub(s);
				unClub->setNom(strtok_s(NULL, "%", &nxtok));
				unClub->setCouleur(strtok_s(NULL, "%", &nxtok));
				unClub->setHistoire(strtok_s(NULL, "%", &nxtok));
				unClub->setVilleDuClub(strtok_s(NULL, "%", &nxtok));
				unContrat->setClubContractant(unClub);

				un2Club = new Club();
				un2Club->setAdresseClub(strtok_s(NULL, "%", &nxtok));
				un2Club->setNom(strtok_s(NULL, "%", &nxtok));
				un2Club->setCouleur(strtok_s(NULL, "%", &nxtok));
				un2Club->setHistoire(strtok_s(NULL, "%", &nxtok));
				un2Club->setVilleDuClub(strtok_s(NULL, "%", &nxtok));
				unContrat->setClubLibere(un2Club);

				joueur = new Joueur();
				joueur->setNom(strtok_s(NULL, "%", &nxtok));
				joueur->setPrenom(strtok_s(NULL, "%", &nxtok));
				joueur->setTaille(static_cast<float>(atof((strtok_s(NULL, "%", &nxtok)))));
				joueur->setVilleNaissance(strtok_s(NULL, "%", &nxtok));
				unContrat->setJoueurContractant(joueur);

				reg = new Reglement();
				reg->setDescriptionDroit(strtok_s(NULL, "%", &nxtok));
				reg->setMontantEncaisse(static_cast<float>(atof((strtok_s(NULL, "%", &nxtok)))));
				reg->setMontantRestant(static_cast<float>(atof((strtok_s(NULL, "%", &nxtok)))));
				reg->setMontantTransfert(static_cast<float>(atof((strtok_s(NULL, "%", &nxtok)))));
				reg->setSeuilVigueur(static_cast<float>(atof((strtok_s(NULL, "%", &nxtok)))));
				unContrat->setReglement(reg);

				jour1 = atoi(strtok_s(NULL, "%", &nxtok));
				mois1 = atoi(strtok_s(NULL, "%", &nxtok));
				annee1 = atoi(strtok_s(NULL, "%", &nxtok));
				d1 = new Date(jour1, mois1, annee1);
				unContrat->setDateContrat(d1);

				jour2 = atoi(strtok_s(NULL, "%", &nxtok));
				mois2 = atoi(strtok_s(NULL, "%", &nxtok));
				annee2 = atoi(strtok_s(NULL, "%", &nxtok));
				d2 = new Date(jour2, mois2, annee2);
				unContrat->setDateEntree(d2);

				unContrat->setDureeContrat(atoi(strtok_s(NULL, "%", &nxtok)));

				listeCOntrat.push_back(unContrat);
			}
		}
	}
	fichierJoueurs.close();
	delete[] line;
	return listeCOntrat;
}

vector<Rupture*> Chargement::ChargerRupture(string debut) {
	char *nxtok, *line = new char[5000];
	Rupture *uneRupture;
	vector<Rupture*> listeRupture;
	Club *unClub;
	Joueur *joueur;
	string r, fin,s;
	fin = "FIN" + debut;
	bool bol = false;
	ifstream fichierJoueurs("../rupture.txt", ios::in);
	while (!fichierJoueurs.eof()) {
		fichierJoueurs.getline(line, 500);
		if (strlen(line) > 0) {
			r = strtok_s(line, "%", &nxtok);
			if (r.compare(debut) == 0 || bol == true) {
				bol = true;
				fichierJoueurs.getline(line, 500);
				s = strtok_s(line, "%", &nxtok);
				if (r.compare(fin) == 0 || fin.compare(s) == 0) return listeRupture;
				uneRupture = new Rupture();

				uneRupture->setRaisonDep(s);
				uneRupture->setPenalite(static_cast<float>(atof((strtok_s(line, "%", &nxtok)))));				

				unClub = new Club();
				unClub->setAdresseClub(strtok_s(NULL, "%", &nxtok));
				unClub->setNom(strtok_s(NULL, "%", &nxtok));
				unClub->setCouleur(strtok_s(NULL, "%", &nxtok));
				unClub->setHistoire(strtok_s(NULL, "%", &nxtok));
				unClub->setVilleDuClub(strtok_s(NULL, "%", &nxtok));
				uneRupture->setNouvClub(unClub);

				joueur = new Joueur();
				joueur->setNom(strtok_s(NULL, "%", &nxtok));
				joueur->setPrenom(strtok_s(NULL, "%", &nxtok));
				joueur->setTaille(static_cast<float>(atof((strtok_s(NULL, "%", &nxtok)))));
				joueur->setVilleNaissance(strtok_s(NULL, "%", &nxtok));
				uneRupture->setJoueur(joueur);

				listeRupture.push_back(uneRupture);
			}
		}
	}
	fichierJoueurs.close();
	delete[] line;
	return listeRupture;
}

vector<Club*> Chargement::ChargerClub(void) {
	char *nxtok, *line = new char[5000];
	Club *unClub;
	Stade *stade;
	Date *d;
	vector<Club*> listeClub;
	string test;
	int jour, mois, annee;
	ifstream fichierJoueurs("../club.txt", ios::in);
	while (!fichierJoueurs.eof()) {
		jour = mois = annee = 0;
		fichierJoueurs.getline(line, 500);
		if (strlen(line) > 0) {
			
			unClub = new Club();
			unClub->setAdresseClub(strtok_s(line, "%", &nxtok));
			unClub->setNom(strtok_s(NULL, "%", &nxtok));
			unClub->setCouleur(strtok_s(NULL, "%", &nxtok));
			unClub->setHistoire(strtok_s(NULL, "%", &nxtok));
			unClub->setVilleDuClub(strtok_s(NULL, "%", &nxtok));

			jour = atoi(strtok_s(NULL, "%", &nxtok));
			mois = atoi(strtok_s(NULL, "%", &nxtok));
			annee = atoi(strtok_s(NULL, "%", &nxtok));
			d = new Date(jour, mois, annee);
			unClub->setAnnee(d);

			unClub->setEffectif(ChargerJoueur(unClub->getNom()));
			unClub->setStaff(ChargerPersonne(unClub->getNom()));
			unClub->setPalmares(ChargerPalmares(unClub->getNom()));
			unClub->setContrat(ChargerContrat(unClub->getNom()));
			unClub->setRupture(ChargerRupture(unClub->getNom()));

			stade = new Stade();
			stade->setAdresse(strtok_s(NULL, "%", &nxtok));
			stade->setNom(strtok_s(NULL, "%", &nxtok));
			stade->setQualite((Qualite)atoi(strtok_s(NULL, "%", &nxtok)));
			unClub->setStadeDuClub(stade);
			
			listeClub.push_back(unClub);
		}
	}
	fichierJoueurs.close();
	delete[] line;
	return listeClub;
}