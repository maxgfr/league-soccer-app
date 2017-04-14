#include "stdafx.h"
#include "Thread.h"

#pragma region constructeur
Thread::Thread()
{
}


Thread::~Thread()
{
}
#pragma endregion constructeur

#pragma region thread
//la définition du thread de l'acheteur
DWORD WINAPI threadAcheteur(LPVOID acheteur)
{
	cout << "\n\n--------------Entree dans le thread de l'acheteur--------------" << endl;
	((NegoAcheteur*)acheteur)->faireLeBusiness();
	cout << "--------------Sortie du thread de l'acheteur--------------\n\n" << endl;
	return 0;
}

//la définition du thread du vendeur
DWORD WINAPI threadVendeur(LPVOID vendeur)
{
	cout << "\n\n--------------Entree dans le thread du vendeur--------------" << endl;
	((NegoVendeur*)vendeur)->faireLeBusiness();
	cout << "--------------Sortie du thread du vendeur--------------\n\n" << endl;
	return 0;
}

#pragma endregion thread

void Thread::launchThread(NegoAcheteur *acheteur, NegoVendeur *vendeur)
{
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
}
