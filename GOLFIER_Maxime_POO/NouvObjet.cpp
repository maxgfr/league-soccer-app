#include "stdafx.h"
#include "NouvObjet.h"

#pragma region nouveaux objets implicites

Date* NouvObjet::nouvDate()
{
	int jour, mois, annee;

	cout << "Le jour ?\n";
	cin >> jour;
	while (jour < 1 || jour > 31) {
		cout << "La date est invalide, recommencez" << endl;
		cout << "Le jour svp?\n";
		cin >> jour;

	}
	cout << "Le mois ?\n";
	cin >> mois;
	while (mois < 1 || mois > 12) {
		cout << "La date est invalide, recommencez" << endl;
		cout << "Le mois svp?\n";
		cin >> mois;
	}
	cout << "L'annee ?\n";
	cin >> annee;
	while (annee < 1900 || annee > 2100) {
		cout << "La date est invalide, recommencez" << endl;
		cout << "L'annee svp?\n";
		cin >> annee;
	}

	Date *d = new Date(jour, mois, annee);
	return d;
}

Palmares* NouvObjet::nouvPalm()
{
	string titre;
	int type;

	Date *date = nouvDate();

	cout << "Le titre du palmares\n";
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, titre);

	cout << "Le type du titre\n";
	cout << "0 pour competition, 1 pour championnat\n";
	cin >> type;

	while (type < 0 || type > 1) {
		cout << "Le type est invalide est invalide, recommencez" << endl;
		cout << "0 pour competition, 1 pour championnat\n";
		cin >> type;
	}

	Palmares *p = new Palmares(titre, static_cast<Type>(type), date);
	return p;
}

Joueur* NouvObjet::nouvJoueur()
{
	string nom, prenom, villeDeNaissance;
	float taille, poids;
	char rep1 = 'O';
	vector<Parcours*> parcoursDuJoueur;

	cout << "Donner le nom du joueur\n";
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, nom);
	cout << "Donner le prenom du joueur\n";
	getline(cin, prenom);
	cout << "Donner la ville de naissance du joueur\n";
	getline(cin, villeDeNaissance);
	cout << "Donner la taille du joueur\n";
	cin >> taille;
	cout << "Donner le poids du joueur\n";
	cin >> poids;

	cout << "\n---Creation du parcours du joueur---" << endl;
	while (rep1 != 'X') {
		Parcours *p = nouvParcours();
		parcoursDuJoueur.push_back(p);
		cout << "Appuyer sur X pour arreter la saisie d'un nouveau parcours pour le joueur, sinon valider une autre touche pour continuer ? : ";
		cin >> rep1;
	}

	Joueur *j = new Joueur(nom, prenom, taille, poids, villeDeNaissance, parcoursDuJoueur);
	return j;
}

Parcours* NouvObjet::nouvParcours()
{
	string nomClub, nomClubAcuel;

	cout << "Donner son nom de club actuel\n";
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, nomClubAcuel);
	cout << "Donner le nom du club ou il est passe\n";
	getline(cin, nomClub);
	cout << "Donner la date de son passage\n";
	Date *date = nouvDate();


	Parcours *p = new Parcours(nomClub, nomClubAcuel, date);
	return p;
}

Personne* NouvObjet::nouvPersonne()
{
	string nom;
	int age, choix;
	float poids;

	cout << "Donner le nom de la personne\n";
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, nom);
	cout << "Donner l'age la personne\n";
	cin >> age;
	cout << "Donner le poids de la personne\n";
	cin >> poids;
	cout << "0 pour que la personne soit President; 1 pour qu'elle soit Infirmier\n 2 pour qu'elle soit Secretaire; 3 pour qu'elle soit Recruteur\n4 pour qu'elle soit Entraineur\n";
	cin >> choix;
	while (choix < 0 || choix > 4) {
		cout << "0 pour que la personne soit President; 1 pour qu'elle soit Infirmier\n 2 pour qu'elle soit Secretaire; 3 pour qu'elle soit Recruteur\n4 pour qu'elle soit Entraineur\n";
		cin >> choix;
	}

	Personne *p = new Personne(nom, age, poids, static_cast<Metier>(choix));
	return p;
}

Stade* NouvObjet::nouvStade()
{
	string nom, adresse;
	int nbplace, type;

	cout << "L adresse du stade\n";
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, adresse);
	cout << "Le nom du stade\n";
	getline(cin, nom);
	cout << "Sa capacite\n";
	cin >> nbplace;

	cout << "La qualite du gazon\n";
	cout << "0 pour gazon, 1 pour synthetique \n";
	cin >> type;

	while (type < 0 || type > 1) {
		cout << "La qualite est invalide est invalide, recommencez" << endl;
		cout << "0 pour gazon, 1 pour synthetique\n";
		cin >> type;
	}

	Stade *p = new Stade(nom, adresse, static_cast<Qualite>(type), nbplace);
	return p;
}

Entraineur * NouvObjet::nouvEntraineur(LigueSoccer *lg)
{
	string prenom, nom;
	vector<TitreGagne*> list;
	char rep1 = 'O';

	cout << "Le prenom de l'entraineur :\n";
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, prenom);

	cout << "Le nom de l'entraineur :\n";
	getline(cin, nom);

	cout << "\n---Creation de titres gagnes par l'entraineur---" << endl;
	while (rep1 != 'X') {
		TitreGagne *t = nouvTitreGagne(lg);
		list.push_back(t);
		cout << "Appuyer sur X pour arreter la saisie d'un titre gagne par l'entraineur, pour continuer valider sur n'importe qu'elle autre touche : ";
		cin >> rep1;
	}

	Entraineur *p = new Entraineur(nom, prenom, list);
	return p;
}

TitreGagne * NouvObjet::nouvTitreGagne(LigueSoccer *lg)
{
	string nom;
	vector<Palmares*> s;
	char rep3 = 'O', rep = 'O';

	cout << "---Creation de Palmares---" << endl;
	while (rep3 != 'X') {
		Palmares *palm = nouvPalm();
		s.push_back(palm);
		cout << "Appuyer sur X pour arreter la saisie d'un nouveau palmares,  pour continuer tapez une autre touche et validez :";
		cin >> rep3;
	}

	cout << "Quel est le nom du club ou il a eu ce palmares svp?\n";
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, nom);
	int res = lg->RechClub(nom);

	while (res == -1)
	{
		cout << "Le club : " << nom << " n'existe pas... Vous ne pouvez pas creer un entraineur sans qu'il soit lie a un club !\n";
		cout << "Appuyez et validez N pour mettre un club par defaut ! sinon appuyer sur une autre touche pour chercher un club!\n";
		cin >> rep;
		if (rep == 'N')
		{
			Club *c = nouvClubVide();
			TitreGagne *g = new TitreGagne(s, c);
			return g;
		}
		cout << "\nQuel est le nom du club ou il a eu ce palmares svp?\n";
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		getline(cin, nom);
		res = lg->RechClub(nom);
	}

	cout << "Le club : " << nom << " existe\n";
	Club *c = lg->getListeClub().at(res);
	TitreGagne *g = new TitreGagne(s, c);
	return g;
}

Club * NouvObjet::nouvClub(LigueSoccer *lg)
{
	string nom, histoire, adresse, ville, couleur;
	char rep1 = 'O', rep2 = 'O', rep3 = 'O', rep4 = 'O';
	vector<Joueur*> effectif;
	vector<Personne*> staff;
	vector <Palmares*> pa;

	cout << "\n\nL'histoire du club?\n";
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, histoire);
	cout << "Donner le nom du club\n";
	getline(cin, nom);
	cout << "L'adresse du club?\n";;
	getline(cin, adresse);
	cout << "La ville du club?\n";
	getline(cin, ville);
	cout << "La couleur du club?\n";
	getline(cin, couleur);
	cout << "\n---Date de creation---" << endl;
	Date *date = nouvDate();
	cout << "\n---Creation d'un nouveau stade---" << endl;
	Stade *stade = nouvStade();

	cout << "\n---Creation de joueur(s)---" << endl;
	while (rep1 != 'X') {
		Joueur *j = nouvJoueur();
		effectif.push_back(j);
		cout << "Appuyer sur X pour arreter la saisie de nouveau joueur, pour continuer tapez une autre touche et validez:";
		cin >> rep1;
	}

	cout << "\n---Creation de staff(s)---" << endl;
	while (rep2 != 'X') {
		Personne *p = nouvPersonne();
		if (p->getMetier() == 4)
		{
			Entraineur *entraineur = nouvEntraineur(lg);
			lg->AjoutEntraineur(entraineur);
		}
		staff.push_back(p);
		cout << "\nAppuyer sur X pour arreter la saisie d'une nouvelle personne, pour continuer tapez une autre touche et validez :";
		cin >> rep2;
	}

	cout << "\n---Voulez vous crer un Palmares X pour non une autre touche pour valider---" << endl;
	cin >> rep4;
	if (rep4 != 'X')
	{
		cout << "\n---Creation de Palmares du club---" << endl;
		while (rep3 != 'X') {
			Palmares *palm = nouvPalm();
			pa.push_back(palm);
			cout << "Appuyer sur X pour arreter la saisie d'un nouveau palmares,  pour continuer tapez une autre touche et validez :";
			cin >> rep3;
		}
	}
	else {
		Palmares *palm = new Palmares("", Type::championnat, new Date(1, 1, 1950));
		pa.push_back(palm);
	}



	Club *c = new Club(nom, histoire, couleur, date, effectif, stade, ville, adresse, staff, pa);

	return c;
}

Joueur * NouvObjet::nouvJoueurVide()
{
	vector<Parcours*> pa;
	Parcours *p = new Parcours("", "", new Date(1, 1, 1950));
	pa.push_back(p);
	Joueur *j = new Joueur("", "", 0, 0, "", pa);
	return j;
}

Club * NouvObjet::nouvClubVide()
{
	string nom = "", histoire = "", adresse = "", ville = "", couleur = "";
	vector<Joueur*> effectif;
	vector<Personne*> staff;
	vector <Palmares*> pa;
	vector <Parcours*> parc;
	Parcours* pp = new Parcours("", "", new Date(1, 1, 1950));
	parc.push_back(pp);
	Joueur *j = new Joueur("", "", 0, 0, "", parc);
	effectif.push_back(j);
	Personne *p = new Personne("", 1, 0, Metier::infirmier);
	staff.push_back(p);
	Palmares *palm = new Palmares("", Type::championnat, new Date(1, 1, 1950));
	pa.push_back(palm);
	Club *c = new Club(nom, histoire, couleur, new Date(1, 1, 1950), effectif, new Stade("", "", Qualite::gazon, 0), ville, adresse, staff, pa);
	return c;
}

Club * NouvObjet::nouvClubCherch(LigueSoccer *lg) {

	string nom;
	char rep = 'X';

	cout << "Donner le nom du club\n";
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, nom);
	int res = lg->RechClub(nom);
	while (res == -1)
	{
		cout << "Le club : " << nom << " n'existe pas...\n";
		cout << "Appuyez et validez N pour mettre un club par defaut ! sinon appuyer sur une autre touche pour chercher un club!\n";
		cin >> rep;
		if (rep == 'N')
		{
			Club *c1 = nouvClubVide();
			return c1;
		}
		cout << "\nQuel est le nom du club svp?\n";
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		getline(cin, nom);
		res = lg->RechClub(nom);
	}
	cout << "Le club : " << nom << " existe\n";
	Club *c1 = lg->getListeClub().at(res);
	return c1;
}

Rencontre* NouvObjet::nouvRencontre(LigueSoccer *lg)
{
	cout << "\n---DATE DU MATCH---\n" << endl;
	Date *d = nouvDate();
	cout << "\n---CLUB QUI RECOIT---\n";
	Club *c1 = nouvClubCherch(lg);
	cout << "\n---CLUB ADVERSE---\n";
	Club *c2 = nouvClubCherch(lg);
	cout << "\n---Creation d'un nouveau match---\n" << endl;
	Match *match = nouvMatch(lg);
	Rencontre *c = new Rencontre(d, c1, c2, match);
	return c;
}

Match * NouvObjet::nouvMatch(LigueSoccer *lg)
{
	char rep1 = 'O';
	vector<Periode*> pe;

	cout << "----Creation de l equipe qui reçoit----";
	Equipe *e1 = nouvEquipe(lg);
	cout << "----Creation de l equipe adverse---- ";
	Equipe *e2 = nouvEquipe(lg);


	cout << "\n---Creation de periode(s)---" << endl;
	while (rep1 != 'X') {
		Periode *p = nouvPeriode();
		pe.push_back(p);
		cout << "Appuyer sur X pour arreter la saisie d'une nouvelle periode, sinon valider une autre touche pour continuer : ";
		cin >> rep1;
	}

	int but1 = 0, but2 = 0;
	int size = pe.size();
	for (int i = 0; i < size; i++) {
		but1 += pe.at(i)->getButLocal();
		but2 += pe.at(i)->getButAdverse();
	}
	Resultat *res = nouvRes(but1, but2);

	Match *m = new Match(e1, e2, pe, res);
	return m;
}

Equipe * NouvObjet::nouvEquipe(LigueSoccer *lg)
{
	int a, b;
	Club *c = nouvClubCherch(lg);
	cout << "Donner le nombre de joueur pouvant etre sur le terrain\n";
	cin >> a;
	cout << "Donner le nombre de  gardien\n";
	cin >> b;
	cout << "\n---Saisie du capitaine---\n";
	Joueur * joueur = nouvJoueurCherch(c);
	Equipe *e = new Equipe(c, a, b, joueur);
	return e;
}

Joueur * NouvObjet::nouvJoueurCherch(Club *c)
{
	char rep2 = 'O';
	string nono;

	cout << "Donner le nom du joueur a chercher\n";
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, nono);
	int res3 = c->RechJoueurParNom(nono);

	while (res3 == -1)
	{
		cout << "Le joueur : " << nono << " n'existe pas... \n";
		cout << "Appuyez et validez N pour mettre un joueur par defaut ! sinon appuyer sur une autre touche pour chercher un joueur !\n";
		cin >> rep2;
		if (rep2 == 'N')
		{
			Joueur *joueur = nouvJoueurVide();
			return joueur;
		}
		cout << "Donner le nom du joueur a chercher\n";
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		getline(cin, nono);
		res3 = c->RechJoueurParNom(nono);
	}

	cout << "Le joueur : " << nono << " existe\n";
	Joueur *joueur = c->getEffectif().at(res3);
	return joueur;
}

Resultat * NouvObjet::nouvRes(int a, int b)
{
	Resultat *r = new Resultat(a, b);
	return r;
}

Periode * NouvObjet::nouvPeriode()
{
	int a, b, c;
	cout << "Duree de la periode\n";
	cin >> a;
	cout << "Nombre de buts marques par l'equipe locale dans la periode\n";
	cin >> b;
	cout << "Nombre de buts marques par l'equipe adverse dans la periode\n";
	cin >> c;
	Periode *p = new Periode(a, b, c);
	return p;
}

Contrat * NouvObjet::nouvContrat(LigueSoccer *lg)
{
	int duree;
	cout << "---ANCIEN CLUB---\n";
	Club *club1 = nouvClubCherch(lg);
	cout << "---JOUEUR EN QUESTION---\n";
	Joueur *joueur = nouvJoueurCherch(club1);
	cout << "---NOUVEAU CLUB---\n";
	Club *club2 = nouvClubCherch(lg);
	cout << "Donnez la duree du contrat\n";
	cin >> duree;
	cout << "---DATE ENTREE---\n";
	Date *dateEntree = nouvDate();
	cout << "---DATE CONTRAT---\n";
	Date *dateContrat = nouvDate();
	cout << "---INFORMATION PAIEMENT---\n";
	Reglement *reglement = nouvReglement();
	Contrat *c = new Contrat(joueur, club1, club2, duree, dateEntree, reglement, dateContrat);
	return c;
}

Rupture * NouvObjet::nouvRupture(LigueSoccer *lg, Club *dep)
{
	float penalite;
	string raison;
	cout << "---NOUVEAU CLUB---\n";
	Club *club = nouvClubCherch(lg);
	cout << "---JOUEUR EN QUESTION---\n";
	Joueur *joueur = nouvJoueurCherch(dep);
	cout << "Donner la raison \n";
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, raison);
	cout << "Donner le montant de la penalite\n";
	cin >> penalite;
	Rupture *r = new Rupture(joueur, raison, club, penalite);
	return r;
}

Reglement * NouvObjet::nouvReglement()
{
	float seuilVigueur, montantTransfert, montantEncaisse, montantRestant;
	string desc;
	cout << "Donner le seuil en vigueur\n";
	cin >> seuilVigueur;
	cout << "Donner le montant du transfert en vigueur\n";
	cin >> montantTransfert;
	cout << "Donner le montant encaisse par l ancien club\n";
	cin >> montantEncaisse;
	cout << "Donner le montant restant encaisse par le joueur\n";
	cin >> montantRestant;
	cout << "Donner la description des droits\n";
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, desc);
	Reglement *reg = new Reglement(seuilVigueur, desc, montantTransfert, montantEncaisse, montantRestant);
	return reg;
}

Club * NouvObjet::nouvEquipeCherche(LigueSoccer *lg, Calendrier *cal)
{
	char rep2 = 'O';
	string nono;

	cout << "Donner le nom de l'equipe qui recoit\n";
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, nono);

	int res3 = cal->RechEquipe(nono);

	while (res3 == -1)
	{
		cout << "L'equipe : " << nono << " n'existe pas... \n";
		cout << "Appuyez et validez N pour mettre un club par defaut ! sinon appuyer sur une autre touche pour chercher un joueur !\n";
		cin >> rep2;
		if (rep2 == 'N')
		{
			Club *e = nouvClubVide();
			return e;
		}
		cout << "Donner le nom de lequipe qui recoit \n";
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		getline(cin, nono);
		res3 = cal->RechEquipe(nono);
	}

	Club *c = cal->getListeRencontre().at(res3)->getClubReceveur();
	return c;
}
NegoAcheteur * NouvObjet::nouvNegoAcheteur(LigueSoccer * lg, int duree, Mutex m)
{
	float montantDesire, montantMax;
	cout << "Donner le montant desire pour l'acheteur\n";
	cin >> montantDesire;
	cout << "Ainsi que le montant maximum qu'il peut faire\n";
	cin >> montantMax;
	Club *club = nouvClubCherch(lg);

	NegoAcheteur *acheteur = new NegoAcheteur(montantDesire, montantMax, duree, club,m);
	return acheteur;
}
NegoVendeur * NouvObjet::nouvNegoVendeur(LigueSoccer * lg, int duree, Mutex m)
{

	float montantDesire, montantMin;

	cout << "Donner le montant desire pour le vendeur \n";
	cin >> montantDesire;
	cout << "Ainsi que le montant maximum qu'il peut faire\n";
	cin >> montantMin;
	Club *club = nouvClubCherch(lg);

	NegoVendeur *vendeur = new NegoVendeur(montantDesire, montantMin, duree, club,m);
	return vendeur;
}
#pragma endregion nouveaux objets implicites