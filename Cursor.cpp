#include "Cursor.h"

Cursor::Cursor(){
	m_t_selector.loadFromFile("image/selector.png");
	m_s_selector.setTexture(m_t_selector);
	m_s_selector.setPosition(32*8,0);
}

void Cursor::draw(sf::RenderWindow &window){
	window.draw(m_s_selector);
}
