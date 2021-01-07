#ifndef __MENU_H__
#define __MENU_H__

#include <SFML/Graphics.hpp>
#include <iostream>

class Menu{
	public:
		Menu();
		void draw(sf::RenderWindow &window);
		int onClick(sf::Vector2i mousePosition);
		void onSecond();
	private:
		sf::Texture m_t_background;
		sf::Sprite 	m_s_background;
		sf::Texture m_t_title;
		sf::Sprite 	m_s_title;
		sf::Texture m_t_ange;
		sf::Sprite 	m_s_ange;
		sf::Texture m_t_buttonStart;
		sf::Sprite 	m_s_buttonStart;
		bool m_affichageButtonStart;


};

#endif
