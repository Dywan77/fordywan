#ifndef __CUBE_H__
#define __CUBE_H__

#include <SFML/Graphics.hpp>
#include <time.h>

enum Cubecouleur{
	CJAUNE, CORANGE, CVERT, CMAUVE, CROUGE, CBLEU, CNULL
};

class Cube{

	public:
		Cube();
		Cube(int index);
		Cube(sf::Vector2f position, int index);
		void draw(sf::RenderWindow &window);
		void setId();
		void setId(int id);
		void setPosition(sf::Vector2i pos);
		int getId();
		bool isOnCursor();
		void setisOnCursor(bool boolean);
		Cube *getPtr();
		sf::Vector2f getPosition();
		sf::Sprite &getSprite();
	private:
		int m_index = 0;
		bool m_isOnCursor = false;
		sf::Texture m_texture;
		sf::Sprite m_sprite;

};

#endif
