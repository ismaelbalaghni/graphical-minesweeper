#include "fonctions.h"
#include "pch.h"

void effacer_ecran(void) //fonction pour effacer l'�cran
{
	system("cls");
}

int nb_aleatoire(int min, int max) //fonction pour g�n�rer un nombre al�atoire
{
	return (rand() % (max - min + 1)) + min;
}

void coordonnee_aleatoire(int tailleX, int tailleY, int &x, int &y) //fonction pour generer des cooordonnees aleatoire
{
	x = nb_aleatoire(0, tailleX - 1);
	y = nb_aleatoire(0, tailleY - 1);
}

void affichage_verif(int tailleX, int tailleY)
{
	int i, j;

	for (i = 0; i < tailleX; i++)
	{
		for (j = 0; j < tailleY; j++)
		{
			if (case_dem[i][j].valeur_etat() == 'r' || case_dem[i][j].valeur_etat() == 'b')
			{
				//printf("%c ",tableau[i][j].etat);
				cout << case_dem[i][j].valeur_etat() << " ";
			}
			else
			{
				//printf("%d ",tableau[i][j].etat);
				cout << case_dem[i][j].valeur_etat() << " ";
			}
		}
		cout << endl;
	}
}

void affichage_tableau(int tailleX, int tailleY)
{
	int i, j;

	for (i = 0; i < tailleX; i++)
	{
		for (j = 0; j < tailleY; j++)
		{
			if (case_dem[i][j].valeur_drapeau() == 1)
			{
				//printf("# ");
				cout << "| ";
			}

			else if (case_dem[i][j].valeur_cache() == 1)
			{
				//printf("* ");
				cout << "* ";
			}
			else
			{
				if (case_dem[i][j].valeur_etat() == 'r')
				{
					cout << "r ";
				}
				else if (case_dem[i][j].valeur_etat() == 'b') {
					cout << "b ";
				}
				else
				{
					cout << (int)case_dem[i][j].valeur_etat() << " ";
				}
			}
		}
		cout << endl;
	}
}

int saisie_coordonnees(int tailleX, int tailleY, int &coord1, int &coord2)
{

	int ok;
	char action;
	int act;

	do {
		//printf("\nIndiquer action (bombe ou drapeau) et quelles coordonnees : ");
		cout << "\nIndiquer action (bombe ou drapeau) et quelles coordonnees : ";
		cin >> action;
		cin >> coord1;
		cin >> coord2;
		//scanf("%c %d %d",&action, coord1, coord2);
		if ((coord1 < 0) || (coord1 > tailleX))
		{
			cout << endl;
			cout << "Coordonnee inexistante" << endl;
			//printf("Coordonnee inexistante\n");
			ok = 0;
		}
		else if ((coord2 < 0) || (coord2 > tailleY))
		{
			cout << endl;
			cout << "Coordonnee inexistante" << endl;
			ok = 0;
		}
		else
		{
			cout << endl << "Vous avez selectionne la case " << coord1 << coord2 << endl;
			//printf("\nVous avez selectionne la case %d %d\n", coord1, coord2);
			ok = 1;
			//while(getchar()!='\n') {};
		}
	} while (ok != 1);

	if (action == 'b')
	{
		act = 1;
	}
	else
	{
		act = 0;
	}
	return act;
}