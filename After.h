#ifndef __AFTER_H__
#define __AFTER_H__

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cube.h"


class After{

	public:
		After();
		void draw(sf::RenderWindow &window);
		void getID(int *a, int *b, int *c)
		{
			*a = one.getID();
			*b = two.getID();
			*c = three.getID();
		}
		void shuffle();
	private:
		sf::Texture m_t_after;
		sf::Sprite m_s_after;
		Cube one;
		Cube two;
		Cube three;
		

};

#endif
