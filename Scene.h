#ifndef __SCENE_H__
#define __SCENE_H__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "oneverytime.h"
#include "After.h"
#include "Grille.h"

class Scene
{
	public:
		Scene();
		void drawing(sf::RenderWindow &window);
		void onSecond();
		int onPressEnter();
	protected:
		void create();
	private:
		sf::SoundBuffer m_buffer_song_lancement;
		sf::Sound m_song_lancement;
		
		Grille m_grille;
		sf::Texture m_t_background;
		sf::Sprite m_s_background;

		sf::Sprite m_s_spriteWait;
		sf::Texture m_t_spriteWait;
		bool m_bool_waitbutton = true;
		bool m_bool_wait = true;

		After m_after;

};

#endif
