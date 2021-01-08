#ifndef __GRILE_H__
#define __GRILE_H__
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cube.h"
#include "Cursor.h"
#include <vector>

class Grille{
	public:
		Grille();
		void draw(sf::RenderWindow &window);
		void setAfter(int *a, int *b, int *c);
	protected:
		int getCubeVide();

	private:
		sf::Texture m_t_grille;
		sf::Sprite m_s_grille;
		Cube *m_tableauDeCube[81];
		Cursor m_cursor;
};
#endif
