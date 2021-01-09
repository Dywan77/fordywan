#ifndef __CURSOR_H__
#define __CURSOR_H__
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cube.h"
#include "After.h"

class Cursor{
	public:
		Cursor();
		void draw(sf::RenderWindow &window);
		void setAfter(Cube *a, Cube *b, Cube *c, Struct_Cubeid struct_cubeid);
		void onLeft();
		void onRight();
		void up();
		void onGravity();
		void onkeypush();
	protected:
		void replace();
	private:
		sf::Texture m_t_selector;
		sf::Sprite 	m_s_selector;
		Cube *m_one = nullptr;
		Cube *m_two = nullptr;
		Cube *m_three = nullptr;
};

#endif
