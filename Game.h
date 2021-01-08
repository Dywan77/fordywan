#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Graphics.hpp>
#include <iostream>
#include "oneverytime.h"
#include "Menu.h"
#include "Musique.h"
#include "Scene.h"

enum Activity {MENU, PAUSE, GAME};

class Game
{
	public:
		Game();
		Game(unsigned inputSizeX, unsigned inputSizeY);
		

		int mainGame();
	protected:
		void createWindow(sf::Vector2u size);
		void event();
		void drawing();

	private :
		Menu menu;
		Activity m_activity;
		sf::Mouse m_mouse;
		int m_sizeX;
		int m_sizeY;
		sf::Event m_event;
		sf::RenderWindow m_window;
		Musique m_musique;
		Scene m_scene;
		bool m_boolChargement = true;
};

#endif
