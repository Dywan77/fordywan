#include "Cursor.h"

Cursor::Cursor(){
	m_t_selector.loadFromFile("image/selector.png");
	m_s_selector.setTexture(m_t_selector);
	replace();
}

void Cursor::draw(sf::RenderWindow &window){
	window.draw(m_s_selector);
	/*if(m_one != NULL)
	  {
	  m_one->draw(window);
	  m_two->draw(window);
	  m_three->draw(window);
	  }*/
}
void Cursor::setAfter(Cube *a, Cube *b, Cube *c, Struct_Cubeid struct_cubeid){

	m_one = a;
	m_two = b;
	m_three = c;
	std::cout << "ici ca crash:" << '\n';
	std::cout << m_one << '\n';
	std::cout << m_two << '\n';
	std::cout << m_three << '\n';
	m_one->setId(struct_cubeid.a);
	m_two->setId(struct_cubeid.b);
	m_three->setId(struct_cubeid.c);
	std::cout << "Fin ?" << '\n';
	replace();

}
void Cursor::replace(){
	m_s_selector.setPosition(32*8,0);
	if(m_one != NULL)
	{
		m_one->setPosition(sf::Vector2i(32*8,0));
		m_two->setPosition(sf::Vector2i(32*8,32));
		m_three->setPosition(sf::Vector2i(32*8,64));
	}
}

//EVENEMENT
void Cursor::onLeft(){
	if(!(m_s_selector.getPosition().x == 160))
	{
		m_s_selector.move(-32,0);
		m_one->getSprite().move(-32,0);
		m_two->getSprite().move(-32,0);
		m_three->getSprite().move(-32,0);
	}
}
void Cursor::onRight(){
	if(!(m_s_selector.getPosition().x == 320))
	{
		m_s_selector.move(32,0);
		m_one->getSprite().move(32,0);
		m_two->getSprite().move(32,0);
		m_three->getSprite().move(32,0);
	}
}
void Cursor::onGravity(){
	if(!(m_s_selector.getPosition().x == 320))
	{
		m_s_selector.move(0,32);
		m_one->getSprite().move(0,32);
		m_two->getSprite().move(0,32);
		m_three->getSprite().move(0,32);
	}	
}
