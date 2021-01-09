#include "Scene.h"

Scene::Scene(){
	m_t_background.loadFromFile("image/background.png");
	m_s_background.setTexture(m_t_background);
	
	m_t_cache.loadFromFile("image/cache.png");
	m_s_cache.setTexture(m_t_cache);

	m_t_spriteWait.loadFromFile("image/startplay.png");
	m_s_spriteWait.setTexture(m_t_spriteWait);


	m_buffer_song_lancement.loadFromFile("song/debut.wav");
	m_song_lancement.setBuffer(m_buffer_song_lancement);
}

void Scene::drawing(sf::RenderWindow &window){
	window.draw(m_s_background);
	m_after.draw(window);
	m_grille.draw(window);
	window.draw(m_s_cache);

	if(m_bool_waitbutton)
		window.draw(m_s_spriteWait);
}

//EVENEMENT
void Scene::onkeypush(){
	m_grille.onkeypush();
}
void Scene::onDown(){
	onGravity();
}
void Scene::onLeft(){
	if(m_bool_wait == false)
		m_grille.onLeft();
}
void Scene::onRight(){
	if(m_bool_wait == false)
		m_grille.onRight();
}

void Scene::onSecond(){
	if(m_bool_wait)
	{
		if(m_bool_waitbutton)
			m_bool_waitbutton = false;
		else
			m_bool_waitbutton = true;
	}
}
void Scene::onGravity(){
	if(m_bool_wait == false)
	{
		if(m_grille.onGravity() == 42){
			m_grille.setAfter(m_after.getID());
			m_after.shuffle();
		}
	}
}

int Scene::onPressEnter(){
	std::cout << "its pressed\n";
	if(m_bool_wait == true)
	{
		m_bool_wait = false;
		m_bool_waitbutton = true;
		m_song_lancement.play();
		wait(2000);
		m_bool_waitbutton = false;
		//on donne after a grille
		m_grille.setAfter(m_after.getID());
		m_after.shuffle();
		return 1;
	}
	return 0;
}
