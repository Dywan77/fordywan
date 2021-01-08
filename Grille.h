#ifndef __GRILE_H__
#define __GRILE_H__
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cube.h"
#include "Cursor.h"
#include "After.h"
#include <array>

class Grille{
	public:
		Grille();
		void draw(sf::RenderWindow &window);
		void setAfter(Struct_Cubeid s_cubeid);
		void onGravity();
		void onDown();
		void onLeft();
		void onRight();
	protected:
		Cube *getCubeVide();

	private:
		sf::Texture m_t_grille;
		sf::Sprite m_s_grille;
		std::array<Cube, 81> m_tableauDeCube;
		Cursor m_cursor;
};
#endif
