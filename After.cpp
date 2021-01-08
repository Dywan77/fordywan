#include "After.h"

After::After(){
	m_t_after.loadFromFile("image/after.png");
	m_s_after.setTexture(m_t_after);
	m_s_after.setPosition(32*12, 32*4);

	m_one.setId();
	m_two.setId();
	m_three.setId();

	m_one.getSprite().setPosition(384, 128);
	m_two.getSprite().setPosition(384, 160);
	m_three.getSprite().setPosition(384,192);
}

void After::draw(sf::RenderWindow &window){
	window.draw(m_s_after);
	window.draw(m_one.getSprite());
	window.draw(m_two.getSprite());
	window.draw(m_three.getSprite());

}
void After::shuffle(){
	m_one.setId();
	m_two.setId();
	m_three.setId();
}
Struct_Cubeid After::getID(){
	Struct_Cubeid result;
	result.a = m_one.getId();
	result.b = m_two.getId();
	result.c = m_three.getId();
	return result;
}
