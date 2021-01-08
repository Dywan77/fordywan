#ifndef __AFTER_H__
#define __AFTER_H__

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cube.h"

typedef struct Struct_Cubeid{
	int a;
	int b;
	int c;
} Struct_Cubeid;

class After{

	public:
		After();
		void draw(sf::RenderWindow &window);
		Struct_Cubeid getID();	
		void shuffle();
	private:
		sf::Texture m_t_after;
		sf::Sprite m_s_after;
		Cube m_one;
		Cube m_two;
		Cube m_three;
		

};

#endif
