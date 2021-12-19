#include "pch.h"
#include "Grille.h"
const int taille_case = 30;


Grille::Grille(int x, int y, int text_size) : 
	taille_X (x), taille_Y (y), 
	lineH(sf::Vector2f(taille_X*taille_case, 1.f)), lineV(sf::Vector2f(1.f, taille_Y*taille_case)),
	rectangle(sf::Vector2f(taille_case, taille_case)), fond_fenetre(sf::Vector2f(nb_case_x*taille_case, nb_case_y*taille_case))
{
	gril = new Case*[taille_X];
	for (int i = 0; i < taille_X; i++) {
		gril[i] = new Case[taille_Y];
	}
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
		std::cout << "Error loading font!" << std::endl;
	}
	text.setFont(font);
	text.setCharacterSize(text_size);
}

;


Grille::~Grille()
{
	delete[] gril;
}

 int Grille::getX(void)
{
	 return taille_X;

 }

 int Grille::getY(void)
 {
	 return taille_Y;

 }

 int Grille::getDevoile(void)
 {
	 return nb_devoile;
 }

 void Grille::setDevoile(int nb_d)
 {
	 nb_devoile = nb_d;
 }

 Case* Grille::getCase(int x, int y)
 {
	 return &gril[x][y];
 }

 void Grille::countBomb(void)
 {
	 int i, j, compteur;

	 for (i = 0; i < getX(); i++)
	 {
		 for (j = 0; j < getY(); j++)
		 {
			 compteur = 0;
			 if (getCase(i, j)->valeur_etat() == 'r')
			 {
				 //on compte le nombre de bombe autour de la case
				 if (gril[i + 1][j].valeur_etat() == 'b'&& i + 1 < getX())
				 {
					 compteur++;
				 }
				 if (gril[i + 1][j + 1].valeur_etat() == 'b'&& j + 1 < getY() && i + 1 < getX())
				 {
					 compteur++;
				 }
				 if (gril[i][j + 1].valeur_etat() == 'b'&& j + 1 < getY())
				 {
					 compteur++;
				 }

				 if (gril[i - 1][j + 1].valeur_etat() == 'b'&& j + 1 < getY() && i - 1 >= 0)
				 {
					 compteur++;
				 }

				 if (gril[i - 1][j].valeur_etat() == 'b'&& i - 1 >= 0)
				 {
					 compteur++;
				 }
				 if (gril[i - 1][j - 1].valeur_etat() == 'b' && j - 1 >= 0 && i - 1 >= 0)
				 {
					 compteur++;
				 }
				 if (gril[i][j - 1].valeur_etat() == 'b' && j - 1 >= 0)
				 {
					 compteur++;
				 }
				 if (gril[i + 1][j - 1].valeur_etat() == 'b'&& i + 1 < getX() && j - 1 >= 0)
				 {
					 compteur++;
				 }
				 if (compteur != 0)
				 {
					 gril[i][j].remplissage_etat(compteur);
				 }
			 }
		 }
	 }
 }

 int Grille::devoilerGrille(void)
{
	int i, j, modif = 0;
	for (i = 0; i < getX(); i++)
	{
		for (j = 0; j < getY(); j++)
		{
			if ((gril[i][j].valeur_devoile() == 0) && (gril[i][j].valeur_cache() == 0) && gril[i][j].valeur_etat() == 'r')
			{
				gril[i][j].remplissage_devoile(1);
				modif = 1;
				if ((i)+1 < getX())
				{
					if (gril[i + 1][j].valeur_cache() == 1)
					{
						gril[i + 1][j].remplissage_cache(0);
						nb_devoile++;
					}
				}
				if ((j)+1 < getY() && (i)+1 < getX())
				{
					if (gril[i + 1][j + 1].valeur_cache() == 1)
					{
						gril[i + 1][j + 1].remplissage_cache(0);
						nb_devoile++;
					}
				}
				if ((j)+1 < getY())
				{
					if (gril[i][j + 1].valeur_cache() == 1)
					{
						gril[i][j + 1].remplissage_cache(0);
						nb_devoile++;
					}
				}
				if ((j)+1 < getY() && (i)-1 >= 0)
				{
					if (gril[i - 1][j + 1].valeur_cache() == 1)
					{
						gril[i - 1][j + 1].remplissage_cache(0);
						nb_devoile++;
					}
				}

				if ((i)-1 >= 0)
				{
					if (gril[i - 1][j].valeur_cache() == 1)
					{
						gril[i - 1][j].remplissage_cache(0);
						nb_devoile++;
					}
				}
				if ((j)-1 >= 0 && (i)-1 >= 0)
				{
					if (gril[i - 1][j - 1].valeur_cache() == 1)
					{
						gril[i - 1][j - 1].remplissage_cache(0);
						nb_devoile++;
					}
				}
				if ((j)-1 >= 0)
				{
					if (gril[i][j - 1].valeur_cache() == 1)
					{
						gril[i][j - 1].remplissage_cache(0);
						nb_devoile++;
					}
				}
				if ((i)+1 < getX() && (j)-1 >= 0)
				{
					if (gril[i + 1][j - 1].valeur_cache() == 1)
					{
						gril[i + 1][j - 1].remplissage_cache(0);
						nb_devoile++;
					}
				}
			}
		}

	}
	return modif;
}

 void Grille::afficher(sf::RenderWindow & window, sf::RectangleShape & lineH, sf::RectangleShape & lineV  )
 {

 }

 void Grille::setX(int x)
 {
	 taille_X = x;
 }

 void Grille::setY(int y)
 {
	 taille_Y = y;
 }
