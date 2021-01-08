#ifndef __SCENE_H__
#define __SCENE_H__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "oneverytime.h"
#include "After.h"

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
		sf::Texture m_t_grille;
		sf::Sprite m_s_grille;
		sf::SoundBuffer m_buffer_song_lancement;
		sf::Sound m_song_lancement;

		//cursorselector
		sf::Texture m_t_background;
		sf::Sprite m_s_background;

		sf::Sprite m_s_spriteWait;
		sf::Texture m_t_spriteWait;
		bool m_bool_waitbutton = true;
		bool m_bool_wait = true;

		After m_after;

};

#endif
