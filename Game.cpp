//Function CPP
#include "Game.h"

int Game::mainGame(){
	while (m_window.isOpen())
	{
		while (m_window.pollEvent(m_event))	//TU peux gerer les evenement
											//dans une autre fontion ce que je recommande
		{
			//ici on recupere tout les evenement SELON lactivitee
			if (m_event.type == sf::Event::Closed)
			{
				m_window.close();
			}
		}
	m_window.clear();

	//ici on dessine tout les autre objets

	m_window.display();
	}
	return 0;
}



// CONSTRUCTOR
Game::Game()
{
	createWindow(sf::Vector2u(500, 500));
	m_window.setFramerateLimit(60);
}


//PROTECTED
void Game::createWindow(sf::Vector2u size){
	m_window.create(sf::VideoMode(size.x, size.y), "SFML works!");
	m_window.setPosition(sf::Vector2i(0, 0));
}
