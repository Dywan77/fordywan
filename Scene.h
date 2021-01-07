#ifndef __SCENE_H__
#define __SCENE_H__

#include <SFML/Graphics.hpp>
#include <iostream>
#include "After.h"

class Scene
{
	public:
		Scene();
		void drawing(sf::RenderWindow &window);
		void onSecond();
	protected:
		void create();
	private:
		sf::Texture m_t_grille;
		sf::Sprite m_s_grille;
		
		//afterselector
		//cursorselector
		sf::Texture m_t_background;
		sf::Sprite m_s_background;

		sf::Sprite m_s_spriteWait;
		sf::Texture m_t_spriteWait;
		bool m_bool_waitbutton = true;

		After m_after;

};

#endif
