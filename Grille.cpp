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
	for(int i = 0; i < 81; i++)
	{
		m_tableauDeCube[i].setisOnCursor(false);	
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

void Grille::setAfter(Struct_Cubeid s_cubeid){
	for(int i = 0; i < 81; i++)
	{
		m_tableauDeCube[i].setisOnCursor(false);	
	}
	m_cursor.setAfter(getCubeVide(), getCubeVide(), getCubeVide(), s_cubeid);
}


//PROTECTED
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

// EVENEMENT
int Grille::onGravity(){
	for(int i = 0; i < 81; i++)
	{
		if(m_tableauDeCube[i].isOnCursor() == true){
			if(m_tableauDeCube[i].getPosition().y >= 480)
			{
				std::cout << "TOUCH " << m_tableauDeCube[i].isOnCursor() << '\n';
				return 42;
			}
		}
	}	
	std::cout << "fin\n";
	m_cursor.onGravity();
	return 0;
}

void Grille::onDown(){
}

void Grille::onLeft(){
	m_cursor.onLeft();
}

void Grille::onRight(){
	m_cursor.onRight();
}
