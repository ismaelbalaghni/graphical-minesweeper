#pragma once
class Case
{
private:
	char cache;
	int devoile;
	int etat;
	int drapeau;
public:
	Case();
	virtual ~Case();
	void remplissage_etat(int);
	void remplissage_devoile(int);
	void remplissage_cache(int);
	void remplissage_drapeau(int);
	char valeur_etat(void);
	int valeur_cache(void);
	int valeur_devoile(void);
	int valeur_drapeau(void);
};

