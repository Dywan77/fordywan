#ifndef __MENU_H__
#define __MENU_H__

#include <SFML/Graphics.hpp>

class Menu{
	public:
		Menu();
		void draw(sf::RenderWindow &window);
	private:
		sf::Texture m_t_background;
		sf::Sprite 	m_s_background;


};

#endif
