#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Case.h"
#include "Grille.h"
#include "structure.h"
#include "fonctions.h"

const int taille_case = 30;
using namespace std;

int main()
{
	
	int nb_case_x;
	int nb_case_y;
	t_touche touche;
	std::cout << "Entrer valeur pour nb cases x tableau: " << std::endl;
	std::cin >> nb_case_x;
	std::cout << "Entrer valeur pour nb cases y tableau: " << std::endl;
	std::cin >> nb_case_y;
	Grille grille(nb_case_x, nb_case_y,20);
	sf::RenderWindow window(sf::VideoMode(nb_case_x*taille_case, nb_case_y*taille_case), "Test of zi SFML");
	
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		return EXIT_FAILURE;
	sf::Text text("Hello SFML", font, 50);


	// select the font
	 // font is a sf::Font
	// set the string to display
	text.setString("1");
	// set the character size
	 // in pixels, not points!
	// set the color
	text.setFillColor(sf::Color::Red);
	// set the text style
	text.setStyle(sf::Text::Bold);
	text.setPosition(10, 2.5);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			touche.souris_position = sf::Mouse::getPosition(window);
		}
		window.clear();
		window.display();
	}
	
	return 0;
}