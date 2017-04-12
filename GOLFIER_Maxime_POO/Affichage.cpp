#include "stdafx.h"
#include "Affichage.h"

#pragma region menu
#pragma region Menu_Principal
void Affichage::choixPrincipal(LigueSoccer *lg, Calendrier *cal)
{
	char choix;
	do
	{
		choix = menuPrincipal();
		switch (toupper(choix))
		{
		case 'A': choixClub(lg); break;
		case 'B': choixTransf(lg,cal); break;
		case 'C': CreerNegociation(lg); break;
		case 'D': chargeAll(lg, cal); break;
		case 'E': sauvAll(lg, cal); break;
		default: break;
		}
	} while (choix != 'X');
}

char Affichage::menuPrincipal()
{
	char choix;
	std::cout << "\n----Menu principal:----\n";
	std::cout << "\tA-Menu du TP1\n";
	std::cout << "\tB-Menu du TP2\n";
	std::cout << "\tC-Creation d'une negociation\n";
	std::cout << "\tD-Charger\n";
	std::cout << "\tE-Sauvegarder\n";
	std::cout << "\tX-Quitter\n";
	std::cout << "\t\tVotre choix:";
	std::cin >> choix;
	return toupper(choix);
}
#pragma endregion Menu_Principal

#pragma region Menu_TP1
#pragma region menuPrincipal
void Affichage::choixClub(LigueSoccer *lg)
{
	char choix;
	do
	{
		choix = menuClub();
		switch (toupper(choix))
		{
		case 'A': AjoutClub(lg); break;
		case 'B': SuppresionClub(lg); break;
		case 'C': AjoutEntraineur(lg); break;
		case 'D': SuppresionEntraineur(lg); break;
		case 'E': rechercheClub(lg); break;
		default: break;
		}
	} while (choix != 'X');
}

char Affichage::menuClub()
{
	char choix;
	cout << "\nMenu principal:\n";
	cout << "\tA-Ajouter un club\n";
	cout << "\tB-Supprimer un club\n";
	cout << "\tC-Ajouter un entraineur\n";
	cout << "\tD-Supprimer un entraineur\n";
	cout << "\tE-Rechercher\n";
	cout << "\tX-Quitter\n";
	cout << "\t\tVotre choix:";
	cin >> choix;
	return toupper(choix);
}
#pragma endregion menuPrincipal

#pragma region rech
void Affichage::rechercheClub(LigueSoccer *lg)
{
	char choix;
	do
	{
		choix = menuRechercheClub();
		switch (toupper(choix))
		{
		case 'A': AfficherAllClub(lg); break;
		case 'B': AfficherJoueurClub(lg); break;
		case 'C': AfficherClubLePlusTitre(lg); break;
		case 'D': AfficherEntraineurLePlusTitre(lg); break;
		case 'E': AfficherAllEntraineur(lg); break;
		default: break;
		}
	} while (choix != 'X');
}

char Affichage::menuRechercheClub()
{
	char choix;
	cout << "\nMenu principal:\n";
	cout << "\tA-Afficher tous les clubs\n";
	cout << "\tB-Afficher les joueurs d'un certain club\n";
	cout << "\tC-Afficher le club le plus titre\n";
	cout << "\tD-Afficher l'entraineur le plus titre\n";
	cout << "\tE-Afficher tous les entraineurs\n";
	cout << "\tX-Quitter\n";
	cout << "\t\tVotre choix:";
	cin >> choix;
	return toupper(choix);
}
#pragma endregion rech
#pragma endregion Menu_TP1

#pragma region Menu_TP2
#pragma region menuPrincipal
void Affichage::choixTransf(LigueSoccer *lg, Calendrier *cal)
{
	char choix;
	do
	{
		choix = menuTransf();
		switch (toupper(choix))
		{
		case 'A': AjoutCalendrier(lg,cal); break;
		case 'B': MajCalendrier(lg,cal); break;
		case 'C': TransacEngagement(lg,cal); break;
		case 'D': TransacRupture(lg,cal); break;
		case 'E': CreaMatch(lg,cal); break;
		case 'F': rechercheTransf(lg,cal); break;
		default: break;
		}
	} while (choix != 'X');
}

char Affichage::menuTransf()
{
	char choix;
	cout << "\nMenu principal:\n";
	cout << "\tA-Creation calendrier de rencontres\n";
	cout << "\tB-Mise a jour calendrier de rencontres\n";
	cout << "\tC-Transaction :  Contrat d'engagement\n";
	cout << "\tD-Transaction : Rupture contrat\n";
	cout << "\tE-Creation d'un match entre deux equipes\n";
	cout << "\tF-Rechercher\n";
	cout << "\tX-Quitter\n";
	cout << "\t\tVotre choix:";
	cin >> choix;
	return toupper(choix);
}
#pragma endregion menuPrincipal

#pragma region rech
void Affichage::rechercheTransf(LigueSoccer *lg, Calendrier *cal)
{
	char choix;
	do
	{
		choix = menuRechercheTransf();
		switch (toupper(choix))
		{
			case 'A': AfficherTousRencontre(lg, cal); break;
			case 'B': AfficherRencontreClub(lg,cal); break;
			case 'C': AfficherMontantTransfClub(lg,cal); break;
			case 'D': AfficherResClub(lg,cal); break;
			default: break;
		}
	} while (choix != 'X');
}

char Affichage::menuRechercheTransf()
{
	char choix;
	cout << "\nMenu principal:\n";
	cout << "\tA-Afficher toutes les rencontres du calendrier\n";
	cout << "\tB-Afficher toutes les rencontres d'un club donne\n";
	cout << "\tC-Afficher montants de transfert encaisses par un club par rapport a une date donnee\n";
	cout << "\tD-Affichage d un resultat d un match entre deux equipes a une date donnee\n";
	cout << "\tX-Quitter\n";
	cout << "\t\tVotre choix:";
	cin >> choix;
	return toupper(choix);
}
#pragma endregion rech
#pragma endregion Menu_TP2

#pragma endregion menu

#pragma region fonction
#pragma region TP1

void Affichage::AjoutClub(LigueSoccer *lg)
{
	Club *c = NouvObjet::nouvClub(lg);
	lg->AjoutClub(c);
	cout << "\n\nClub ajoute avec succes ;)\nVoila les informations que vous avez mis : \n" << endl;
	AfficherUnClub(lg,c);
}

void Affichage::SuppresionClub(LigueSoccer *lg)
{
	string nom;
	Club c;

	cout << "Quel est le nom du club a supprime svp?\n";
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, nom);

	c.setNom(nom);
	lg->SupprimerClub(&c);
}

void Affichage::AjoutEntraineur(LigueSoccer *lg)
{
	Entraineur *c = NouvObjet::nouvEntraineur(lg);
	lg->AjoutEntraineur(c);
	cout << "\nEntraineur ajoute avec succes ;)\nVoila les informations que vous avez mis : \n" << endl;
	AfficherUnEntraineur(lg, c);
}

void Affichage::SuppresionEntraineur(LigueSoccer *lg)
{
	string nom;
	Entraineur c;

	cout << "Quel est le nom de l'entraineur a supprime svp?\n";
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, nom);

	c.setNom(nom);
	lg->SupprimerEntraineur(&c);
}

void Affichage::AfficherAllClub(LigueSoccer *lg)
{
	cout << "\n\nVoici la liste des clubs avec leurs caracteristiques de base \n";
	for (int i = 0; i != lg->getListeClub().size(); i++)
	{
		AfficherUnClub(lg, lg->getListeClub()[i]);
		cout << "\n\n";
	}
}

void Affichage::AfficherAllEntraineur(LigueSoccer *lg)
{
	cout << "\n\nVoici la liste des clubs avec leurs caracteristiques de base \n";
	for (int i = 0; i != lg->getListeEntraineur().size(); i++)
	{
		AfficherUnEntraineur(lg, lg->getListeEntraineur()[i]);
		cout << "\n\n";
	}
}

void Affichage::AfficherJoueurClub(LigueSoccer *lg)
{
	string nom;

	cout << "Quel est le nom du club svp?\n";
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, nom);	

	int res = lg->RechClub(nom);

	if (res != -1) {
		cout << "Voici la liste des joueurs du club : " << nom << "\n";
		for (int i = 0; i != lg->getListeClub().at(res)->getEffectif().size(); i++)
		{
			cout << lg->getListeClub().at(res)->getEffectif()[i]->getNom() << '\n' << endl;
		}
	} else {
		cout << "Le club : " << nom << " n'existe pas...\n";
	}
		
}

void Affichage::AfficherClubLePlusTitre(LigueSoccer *lg)
{
	int res = lg->RechClubPlusTitre();
	if (res != -1) {
		cout << "Voici le club le plus titre :\n";
		AfficherUnClub(lg, lg->getListeClub()[res]);
	}
}

void Affichage::AfficherUnClub(LigueSoccer *lg, Club *c)
{
	cout << "Le nom du club est :" << c->getNom() << '\n';
	cout << "L'adresse du club est :" << c->getAdresseClub() << '\n';
	cout << "L'annee de creation du club est :" << c->getAnnee()->getAnnee() << '\n';
	cout << "La couleur du club est :" << c->getCouleur() << '\n';
	cout << "L'histoire du club est :" << c->getHistoire() << '\n';
	cout << "Le nom du stade du club  est :" << c->getStadeDuClub()->getNom() << '\n';
	cout << "La ville du club est :" << c->getVilleDuClub() << '\n';
	cout << "Voici la liste des palamres du club\n";
	for (int i = 0; i != c->getPalmares().size(); i++)
	{
		cout << c->getPalmares()[i]->getTitre() << '\n' << endl;
	}
	cout << "Voici la liste des joueurs du club\n";
	for (int i = 0; i != c->getEffectif().size(); i++)
	{
		cout << c->getEffectif()[i]->getNom() << '\n' << endl;
	}
	cout << "Voici la liste du staff du club \n";
	for (int j = 0; j != c->getStaff().size(); j++)
	{
		cout << c->getStaff()[j]->getNom() << '\n' << endl;
	}
}

void Affichage::AfficherUnEntraineur(LigueSoccer *lg, Entraineur *c)
{
	cout << "Le nom de l'entraineur est :" << c->getNom() << '\n';
	cout << "Le prenom de l'entraineur est :" << c->getPrenom() << '\n';
	cout << "Le palmares de l'entraineur est : \n";
	for (int i = 0; i != c->getListeTitre().size(); i++)
	{
		if (c->getListeTitre()[i]->getClub()->getNom().empty())
		{
			cout << "\t" << i << ") --CLUB INCONNU--\n";
		} else {
			cout << "\t" << i << ") Dans le club : " << c->getListeTitre()[i]->getClub()->getNom() << '\n' << endl;
		}
		cout << "Il a eu les trophees suivant :" << '\n' << endl;
		for (int j = 0; j != c->getListeTitre()[i]->getEnsPalm().size(); j++)
		{
			cout << "\t\t" << j << ") " << c->getListeTitre()[i]->getEnsPalm()[j]->getTitre() << '\n' << endl;
		}
	}
}

void Affichage::AfficherEntraineurLePlusTitre(LigueSoccer *lg)
{
	int res = lg->RechEntraineurPlusTitre();
	if (res != -1) {
		cout << "Le nom de l'entraineur le plus titre :\n";
		cout << lg->getListeEntraineur()[res]->getNom() << endl;
	}
}

#pragma endregion TP1

#pragma region TP2
void Affichage::AjoutCalendrier(LigueSoccer * lg, Calendrier *cal)
{
	char rep = 'O';
	cout << "\n---Creation de rencontre(s)---" << endl;
	while (rep != 'X') {
		Rencontre *c = NouvObjet::nouvRencontre(lg);
		cal->AjoutRencontre(c);
		cout << "\n\nRencontre ajoute avec succes ;)\nVoila les informations que vous avez mis : \n" << endl;
		AfficherUnRencontre(lg, c);
		cout << "\nAppuyer sur X pour arreter la saisie d'une nouvelle rencontre, pour continuer tapez une autre touche et validez :";
		cin >> rep;
	}
}

void Affichage::MajCalendrier(LigueSoccer * lg, Calendrier *cal)
{
	string nom;
	cout << "\n---Mise a jour de rencontre(s)---" << endl;
	cout << "Pour mettre a jour une rencontre, il faut deux parametres : la date et le nom d un club (adverse ou local)\n";
	Date *d = NouvObjet::nouvDate();
	cout << "Maintenant saisissez le nom d'un club (adverse ou local)\n";
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, nom);
	Rencontre *c = cal->RechRencontre(d, nom);
	if (c == NULL) {
		cout << "Rencontre non trouvee... Reessayez plus tard\n";
		return;
	}
	cout << "\n---Voici la rencontre trouvee :---" << endl;
	AfficherUnRencontre(lg, c);
	cal->SupprimerRencontre(c);
	cout << "\n---Saisissez les nouvelles informations de mise a jour :---" << endl;
	Rencontre *renc = NouvObjet::nouvRencontre(lg);
	cal->AjoutRencontre(renc);
	AfficherTousRencontre(lg, cal);

}

void Affichage::TransacEngagement(LigueSoccer * lg, Calendrier *cal)
{
	cout << "\n---Ajout d'un contrat d'engagement de contrat pour un joueur---\n";
	Contrat *contrat = NouvObjet::nouvContrat(lg);
	lg->MajTransac(contrat);
}

void Affichage::TransacRupture(LigueSoccer * lg, Calendrier *cal)
{
	cout << "\n---Ajout d'une rupture de contrat---\n";
	cout << "---ANCIEN CLUB---\n";
	Club *club = NouvObjet::nouvClubCherch(lg);
	Rupture *rup = NouvObjet::nouvRupture(lg,club);
	lg->MajRupture(rup,club);
}

void Affichage::CreaMatch(LigueSoccer * lg, Calendrier *cal)
{
	cout << "Creation d'un match entre deux equipes de deux clubs différents.\n";
	Match *m = NouvObjet::nouvMatch(lg);
	if (m->getEquipeLocale()->getClub() == m->getEquipeInvite()->getClub()) {
		cout << "D apres la consigne il faut deux clubs differents, reesayez avec d'autres equipes plus tard\n";
		return;
	}
	cout << "Renseignez la date de l affrontement\n";
	Date *date = NouvObjet::nouvDate();
	Rencontre *c = new Rencontre(date, m->getEquipeLocale()->getClub(), m->getEquipeInvite()->getClub(), m);
	cal->AjoutRencontre(c);
}

void Affichage::AfficherUnRencontre(LigueSoccer * lg, Rencontre * c)
{
	cout << "Le nom du club adverse est : " << c->getClubAdverse()->getNom() << '\n';
	cout << "Le nom du club qui recoit est : " << c->getClubReceveur()->getNom() << '\n';
	cout << "Le jour ou le match se passe est le : " << c->getDateMatch()->getJour() << '\n';
	cout << "Voici le nombre de but de l equipe locale a la fin : " << c->getResMatch()->getResFinal()->getNbLocal() << '\n';
	cout << "Voici le nombre de but de l equipe adverse a la fin : " << c->getResMatch()->getResFinal()->getNbAdverse() << '\n';
	cout << "La duree de la premiere periode est : " << c->getResMatch()->getListePeriode()[0]->getDuree()<< '\n';
}

void Affichage::AfficherTousRencontre(LigueSoccer * lg, Calendrier * cal)
{
	cout << "\n\nVoici la liste de toutes les rencontres \n";
	for (int i = 0; i != cal->getListeRencontre().size(); i++)
	{
		AfficherUnRencontre(lg, cal->getListeRencontre()[i]);
		cout << "\n\n";
	}
}

void Affichage::AfficherRencontreClub(LigueSoccer * lg, Calendrier *cal)
{
	string nom;
	cout << "Saisissez le nom d'un club\n";
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, nom);
	AfficherTousRencontre(lg, new Calendrier(cal->RencontrePourUnClub(nom)));
}

void Affichage::AfficherMontantTransfClub(LigueSoccer * lg, Calendrier *cal)
{
	float tot = 0;
	Club *c = NouvObjet::nouvClubCherch(lg);
	cout << "--Donner une date pour afficher les transferts encaisses a partir de celle ci--\n";
	Date *d = NouvObjet::nouvDate();
	for (int i = 0; i != lg->getListeClub().size(); i++) {
		if (lg->getListeClub()[i] == c) {
			for (int j = 0; j != lg->getListeClub()[i]->getContrat().size(); j++) {
				if (lg->getListeClub()[i]->getContrat()[j]->getDateEntree() > d)
				{			
					tot += lg->getListeClub()[i]->getContrat()[j]->getReglement()->getMontantEncaisse();
					cout << "Le club a encaisse " << lg->getListeClub()[i]->getContrat()[j]->getReglement()->getMontantEncaisse() << " euros le : " << *(lg->getListeClub()[i]->getContrat()[j]->getDateEntree()) << "\n";
				}
			}
		}
	}	
	cout << "\nLe montant total encaisses depuis le :" << *d << " est de : " << tot << "\n";
	delete d;
}

void Affichage::AfficherResClub(LigueSoccer * lg, Calendrier *cal)
{
	Club *c;
	c = NouvObjet::nouvEquipeCherche(lg, cal);
	cout << "Donnez une date pour afficher le resultat du match\n";
	Date *d = NouvObjet::nouvDate();
	for (int i = 0; i != cal->getListeRencontre().size(); i++) {
		if (*(cal->getListeRencontre()[i]->getDateMatch()) == *d) {
			int resAdverse = cal->getListeRencontre()[i]->getResMatch()->getResFinal()->getNbAdverse();
			int resLocal = cal->getListeRencontre()[i]->getResMatch()->getResFinal()->getNbLocal();
			cout << "\nL equipe adverse a marque :" << resAdverse << " but(s)\n";
			cout << "L equipe locale a marque :" << resLocal << " but(s)\n";
		}
	}
	delete d;
}

#pragma endregion TP2

#pragma region TP3

#pragma region thread
//la définition du thread de l'acheteur
DWORD WINAPI threadAcheteur(LPVOID acheteur)
{
	cout << "\n\n-------Entree dans le thread de l'acheteur-------\n\n" << endl;
	((NegoAcheteur*)acheteur)->faireLeBusiness();
	cout << "\n\n-------Sortie du thread de l'acheteur-------\n\n" << endl;
	return 0;
}

//la définition du thread du vendeur
DWORD WINAPI threadVendeur(LPVOID vendeur)
{
	cout << "\n\n-------Entree dans le thread du vendeur-------\n\n" << endl;
	((NegoVendeur*)vendeur)->faireLeBusiness();
	cout << "\n\n-------Sortie du thread du vendeur-------\n\n" << endl;
	return 0;
}

#pragma endregion thread

void Affichage::CreerNegociation(LigueSoccer * lg)
{
	int duree;
	bool business;
	Mutex m;

	cout << "---Creation de la negociation---\n";	
	cout << "Veuillez indiquer la duree de la negociation\n";
	cin >> duree;
	cout << "\n---ACHETEUR---\n";
	NegoAcheteur *acheteur = NouvObjet::nouvNegoAcheteur(lg,duree,m);
	cout << "\n---VENDEUR---\n";
	NegoVendeur *vendeur = NouvObjet::nouvNegoVendeur(lg,duree,m);

	int nbreThread = 2;

	//déclaration d'un tableau de thread. 
	HANDLE *threads = new HANDLE[nbreThread];

	//déclaration des identificateurs de thread.
	DWORD *idThread1 = new DWORD();
	DWORD *idThread2 = new DWORD();

	//creation de deux threads
	threads[0] = CreateThread(0, 0, threadAcheteur, acheteur, 0, idThread1);
	threads[1] = CreateThread(0, 0, threadVendeur, vendeur, 0, idThread2);

	//attendre jusqu'à ce que tous les threads terminent
	WaitForMultipleObjects(nbreThread, threads, true, INFINITE);
	
	business = acheteur->getSauv()->isOkay();

	if (business) {
		cout << "Creation d'un contrat pour le joueur signé !\n";
	}
}
#pragma endregion TP3

#pragma region Chargement + Sauvegarde
void Affichage::chargeAll(LigueSoccer *lg, Calendrier *cal)
{
	//singleton
	Chargement* c = Chargement::get_instance();
	lg->setListeClub(c->ChargerClub());
	Chargement::destroy_instance();
}

void Affichage::sauvAll(LigueSoccer *lg, Calendrier *cal)
{
	//singleton
	Sauvegarde* s = Sauvegarde::get_instance();
	s->EnregistrerClub(lg->getListeClub());
	Sauvegarde::destroy_instance();
}
#pragma endregion Chargement + Sauvegarde

#pragma endregion fonction
