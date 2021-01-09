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

	//on pointe sur les cubes donnes
	m_one = a;
	m_two = b;
	m_three = c;
	//On lui donne l'ID quil y a dans after
	m_one->setId(struct_cubeid.a);
	m_two->setId(struct_cubeid.b);
	m_three->setId(struct_cubeid.c);
	//On definit ce cube comme etant dans le cursor
	m_one->setisOnCursor(true);
	m_two->setisOnCursor(true);
	m_three->setisOnCursor(true);
	//on replace le curseur en haut a droite
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
void Cursor::up(){
		m_s_selector.move(0,-32);
		m_one->getSprite().move(0,-32);
		m_two->getSprite().move(0,-32);
		m_three->getSprite().move(0,-32);
}

//EVENEMENT

void Cursor::onkeypush(){
	int id;
	id = m_one->getId();
	m_one->setId(m_two->getId());
	m_two->setId(m_three->getId());
	m_three->setId(id);
}

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
	//if(!(m_s_selector.getPosition().y == 416))
	//{
		m_s_selector.move(0,32);
		m_one->getSprite().move(0,32);
		m_two->getSprite().move(0,32);
		m_three->getSprite().move(0,32);
	//}	
}
