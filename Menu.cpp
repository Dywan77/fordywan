#include "Menu.h"

Menu::Menu(){
	m_t_background.loadFromFile("image/background.png");
	m_s_background.setTexture(m_t_background);
}

void Menu::draw(sf::RenderWindow &window){
	window.draw(m_s_background);
}
