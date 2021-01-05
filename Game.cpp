//Function CPP
#include "Game.h"

int Game::mainGame(){
	while (m_window.isOpen())
	{
		event();
		drawing();
	}
	return 0;
}

// ICI tout va se dessiner
void Game::drawing(){
	m_window.clear();
	if(m_activity == MENU){
		menu.draw(m_window);
	}
	else if(m_activity == GAME){
	}
	else if(m_activity == PAUSE){
	}
	//SI IL Y A DES dessins a faire constamment vvvvvvv

	m_window.display();
}

// ICI tout les evenements
void Game::event(){
	while (m_window.pollEvent(m_event))
	{
		if(m_activity == MENU){
		}
		else if(m_activity == GAME){
		}
		else if(m_activity == PAUSE){
		}



		//TOUT LES EVENEMENT CONSTANT vvvvvvv ICI
		if (m_event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
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
	m_activity = MENU;
}
