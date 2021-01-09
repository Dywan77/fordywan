#include "Cube.h"

Cube::Cube()
{
	m_texture.loadFromFile("image/jewel.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	m_isOnCursor = false;
}
Cube::Cube(int index)
{
	m_texture.loadFromFile("image/jewel.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(index * 32, 0, 32, 32));
	m_index = index;
}
Cube::Cube(sf::Vector2f position, int index)
{
	m_texture.loadFromFile("image/jewel.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(position);
	this->setId(index);
}
void Cube::setPosition(sf::Vector2i pos){
	m_sprite.setPosition(pos.x, pos.y);
}


void Cube::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}
void Cube::setId(int id)
{
	m_index = id;
	m_sprite.setTextureRect(sf::IntRect(id * 32, 0, 32, 32));
}
void Cube::setId()
{
	m_index = rand() % (5 - 0 + 1);
	m_sprite.setTextureRect(sf::IntRect(m_index * 32, 0, 32, 32));
}
int Cube::getId(){
	return m_index;
}
sf::Vector2f Cube::getPosition()
{
	return m_sprite.getPosition();
}
sf::Sprite &Cube::getSprite()
{
	return m_sprite;
}
Cube *Cube::getPtr(){
	return this;
}
bool Cube::isOnCursor(){
	return m_isOnCursor;
}
void Cube::setisOnCursor(bool boolean){
	m_isOnCursor = boolean;
}
