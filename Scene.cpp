#include "Scene.h"

Scene::Scene(){
	m_t_background.loadFromFile("image/background.png");
	m_s_background.setTexture(m_t_background);
	m_t_spriteWait.loadFromFile("image/startplay.png");
	m_s_spriteWait.setTexture(m_t_spriteWait);
}

void Scene::drawing(sf::RenderWindow &window){
	window.draw(m_s_background);
	if(m_bool_waitbutton)
		window.draw(m_s_spriteWait);
}

void Scene::onSecond(){
	if(m_bool_waitbutton)
		m_bool_waitbutton = false;
	else
		m_bool_waitbutton = true;
}
