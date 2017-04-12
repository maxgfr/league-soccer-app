#include "stdafx.h"
#include "CTimer.h"

CTimer* CTimer::Instance()
{
	static CTimer instance;

	return &instance;
}

bool CTimer::IsTimeExpired()
{
	float Elapsed = clock() - MonTimer;
	if (Elapsed > TimeLimit)
	{
		return true;
	}
	return false;
}
