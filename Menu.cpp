#include "Menu.h"

Menu::Menu(){
	m_t_background.loadFromFile("image/background.png");
	m_s_background.setTexture(m_t_background);

	m_t_ange.loadFromFile("image/ange.png");
	m_s_ange.setTexture(m_t_ange);
	m_s_ange.setPosition(0, 250);


	m_t_title.loadFromFile("image/titre.png");
	m_s_title.setTexture(m_t_title);

	m_t_buttonStart.loadFromFile("image/start.png");
	m_s_buttonStart.setTexture(m_t_buttonStart);
	m_s_buttonStart.setPosition(0, 490);
}

void Menu::draw(sf::RenderWindow &window){
	window.draw(m_s_background);
	window.draw(m_s_title);
	window.draw(m_s_ange);
	window.draw(m_s_buttonStart);
}
//EVENT

int Menu::onClick(sf::Vector2i mousePosition){
	if(m_s_buttonStart.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
	{
		return 1;  //le bouton est cliquer
	}
	return 0;// le bouton nest pas cliquer
}
