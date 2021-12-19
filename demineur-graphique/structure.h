#pragma once
#include 

typedef struct t_touche t_touche;

struct t_touche {
	sf::Vector2i souris_position;
	int clic_gauche, clic_droit;
};