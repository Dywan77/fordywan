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

	//LES DESSIN DANS MENU
	if(m_activity == MENU){
		menu.draw(m_window);
	}

	//LES DESSIN EN JEUX
	else if(m_activity == GAME){
		m_scene.drawing(m_window);
	}

	//LES DESSINS DANS LA PAUSE
	else if(m_activity == PAUSE){
	}

	//SI IL Y A DES dessins a faire quelque soit lactivitee

	m_window.display();
}

// ICI tout les evenements
void Game::event(){
	//EVENEMENT NON SFML
	if(m_activity == MENU){
		if(everyTicks(500))
			menu.onSecond();
	}
	if(m_activity == GAME){
		if(everyTicks(850))
			m_scene.onSecond();
		if(everyTicks(800))
			m_scene.onGravity();
	}

	//EVENEMENT DE SFML
	while (m_window.pollEvent(m_event))
	{
		//EVENEMENT DANS LE MENU
		if(m_activity == MENU){
			if(m_event.type == sf::Event::KeyPressed)
			{
				if (m_event.key.code == sf::Keyboard::Enter)
				{
					m_activity = GAME;
					m_musique.playZone(MUSIQUEOPTION);
				}
			}

			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if(menu.onClick(m_mouse.getPosition(m_window)))
					m_activity = GAME;
			}
		}



		// EVENEMENT DANS LE JEU
		else if(m_activity == GAME){
			if(m_event.type == sf::Event::KeyPressed)
			{
				if (m_event.key.code == sf::Keyboard::Enter){
					if(m_boolChargement == true)
						m_musique.stop();
					if(m_scene.onPressEnter() == 1){
						m_musique.playZone(MUSIQUEJEUX);
						m_boolChargement = false;
					}
				}

				if (m_event.key.code == sf::Keyboard::Right){
					m_scene.onRight();	
				}

				if (m_event.key.code == sf::Keyboard::Left){
					m_scene.onLeft();
				}
				if (m_event.key.code == sf::Keyboard::Down){
					m_scene.onDown();
				}

			}
		}


		//EVENEMENT DANS LA PAUSE
		else if(m_activity == PAUSE){
		}



		//TOUT LES EVENEMENT DANS NIMPORTE QUELLE ACTIVITEE
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

Game::Game(unsigned inputSizeX, unsigned inputSizeY)
{
	createWindow(sf::Vector2u(inputSizeX, inputSizeY));
	m_window.setFramerateLimit(60);
}


//PROTECTED
void Game::createWindow(sf::Vector2u size){
	m_window.create(sf::VideoMode(size.x, size.y), "<|||||| COLLUMNS ||||||>");
	m_window.setPosition(sf::Vector2i(0, 0));

	m_activity = MENU;
	m_musique.playZone(MUSIQUEMENU);
}
