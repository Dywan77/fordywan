#include "Grille.h"

Grille::Grille(){
	m_t_grille.loadFromFile("image/grille.png");
	m_s_grille.setTexture(m_t_grille);
	m_s_grille.setPosition(32*5, 32*3);
	for(int i = 0; i < 81; i++)
	{
		m_tableauDeCube[i].setId(CNULL);	
		std::cout << "ici: " << m_tableauDeCube[i].getId() << '\n';
	}
}

void Grille::draw(sf::RenderWindow &window){
	window.draw(m_s_grille);
	m_cursor.draw(window);
	for(int i = 0; i < 81; i++)
	{
		//std::cout << "ici: " << i << '\n';
		if(m_tableauDeCube[i].getId() != CNULL)
		{
			m_tableauDeCube[i].draw(window);
		}
	}
}

Cube *Grille::getCubeVide(){
	for(int i = 0; i < 81; i++)
	{
		//std::cout << "ici: " << i << '\n';
		if(m_tableauDeCube[i].getId() == CNULL)
		{
			m_tableauDeCube[i].setId(1);
			return &m_tableauDeCube[i];
		}
	}
	return NULL;
}
void Grille::setAfter(Struct_Cubeid s_cubeid){

	m_cursor.setAfter(getCubeVide(), getCubeVide(), getCubeVide(), s_cubeid);
}

// EVENEMENT
void Grille::onGravity(){
	m_cursor.onGravity();
}
void Grille::onDown(){
}
void Grille::onLeft(){
	m_cursor.onLeft();
}
void Grille::onRight(){
	m_cursor.onRight();
}
