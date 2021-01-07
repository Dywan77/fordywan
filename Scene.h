#ifndef __SCENE_H__
#define __SCENE_H__

#include <SFML/Graphics.hpp>
#include <iostream>

class Scene
{
	public:
		Scene();
		void drawing(sf::RenderWindow &window);
	protected:
		void create();
	private:
		//grille
		//threeselector
		//cursorselector
		sf::Texture m_t_background;
		sf::Sprite m_s_background;

};

#endif
