#ifndef __CURSOR_H__
#define __CURSOR_H__
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cube.h"

class Cursor{
	public:
		Cursor();
		void draw(sf::RenderWindow &window);
	private:
		sf::Texture m_t_selector;
		sf::Sprite 	m_s_selector;

};

#endif
