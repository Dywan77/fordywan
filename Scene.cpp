#include "Scene.h"

Scene::Scene(){
	m_t_background.loadFromFile("image/background.png");
	m_s_background.setTexture(m_t_background);

	m_t_spriteWait.loadFromFile("image/startplay.png");
	m_s_spriteWait.setTexture(m_t_spriteWait);

	m_t_grille.loadFromFile("image/grille.png");
	m_s_grille.setTexture(m_t_grille);
	m_s_grille.setPosition(32*5, 32*2);

	m_buffer_song_lancement.loadFromFile("song/debut.wav");
	m_song_lancement.setBuffer(m_buffer_song_lancement);
}

void Scene::drawing(sf::RenderWindow &window){
	window.draw(m_s_background);
	window.draw(m_s_grille);
	m_after.draw(window);

	if(m_bool_waitbutton)
		window.draw(m_s_spriteWait);
}

//EVENEMENT

void Scene::onSecond(){
	if(m_bool_wait)
	{
		if(m_bool_waitbutton)
			m_bool_waitbutton = false;
		else
			m_bool_waitbutton = true;
	}
}

int Scene::onPressEnter(){
	std::cout << "its pressed\n";
	if(m_bool_wait = true)
	{
		m_bool_wait = false;
		m_bool_waitbutton = true;
		m_song_lancement.play();
		wait(2000);
		m_bool_waitbutton = false;
		return 1;
	}
	return 0;
}
