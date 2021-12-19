#include "pch.h"
#include "Case.h"
#include <cstdlib>
#include <ctime>

Case::Case()
{
	cache = 1;
	devoile = 0;
	etat = 0;
	drapeau = 0;
}


Case::~Case()
{
}

void Case::remplissage_etat(int v)
{
	etat = v;
}

void Case::remplissage_devoile(int v)
{
	devoile = v;
}

void Case::remplissage_cache(int v)
{
	cache = v;
}

void Case::remplissage_drapeau(int v)
{
	drapeau = v;
}
char Case::valeur_etat(void)
{
	return etat;
}

int Case::valeur_cache(void)
{
	return cache;
}

int Case::valeur_devoile(void)
{
	return devoile;
}

int Case::valeur_drapeau(void)
{
	return drapeau;
}
