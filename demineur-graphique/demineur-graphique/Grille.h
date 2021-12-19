#pragma once
#include "Case.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


class Grille 
{
public:
	Grille(int,int,int);
	virtual ~Grille();
	void setX(int);
	void setY(int);
	int getX(void);
	int getY(void);
	int getDevoile(void);
	void setDevoile(int);
	Case* getCase(int,int);
	void countBomb(void);
	int devoilerGrille(void);
	void afficher(sf::RenderWindow &window, sf::RectangleShape & lineH, sf::RectangleShape & lineV);
private:
	int taille_X;
	int taille_Y;
	//Case gril[100][100];
	Case** gril;
	int nb_devoile;
	sf::RenderWindow window;
	sf::RectangleShape lineH;
	sf::RectangleShape lineV;
	sf::RectangleShape rectangle;
	sf::RectangleShape fond_fenetre;
	sf::Text text;
	sf::Font font;
};

