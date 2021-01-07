#include "Scene.h"

Scene::Scene(){
	m_t_background.loadFromFile("image/background.png");
	m_s_background.setTexture(m_t_background);
}

void Scene::drawing(sf::RenderWindow &window){
	window.draw(m_s_background);
}
