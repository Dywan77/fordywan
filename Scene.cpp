#include "Scene.h"

Scene::Scene(){
	m_t_background.loadFromFile("image/background.png");
	m_s_background.setTexture(m_t_background);
	
	m_t_spriteWait.loadFromFile("image/startplay.png");
	m_s_spriteWait.setTexture(m_t_spriteWait);
	
	m_t_grille.loadFromFile("image/grille.png");
	m_s_grille.setTexture(m_t_grille);
	m_s_grille.setPosition(32*5, 32*2);
}

void Scene::drawing(sf::RenderWindow &window){
	window.draw(m_s_background);
	window.draw(m_s_grille);
	m_after.draw(window);

	if(m_bool_waitbutton)
		window.draw(m_s_spriteWait);
}

void Scene::onSecond(){
	if(m_bool_waitbutton)
		m_bool_waitbutton = false;
	else
		m_bool_waitbutton = true;
}
