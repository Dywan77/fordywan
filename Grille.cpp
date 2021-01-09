#include "Grille.h"

Grille::Grille(){
	m_t_grille.loadFromFile("image/grille.png");
	m_s_grille.setTexture(m_t_grille);
	m_s_grille.setPosition(32*5, 32*3);
	for(int i = 0; i < 81; i++)
	{
		m_tableauDeCube[i].setId(CNULL);	
		//std::cout << "ici: " << m_tableauDeCube[i].getId() << '\n';
	}
	for(int i = 0; i < 81; i++)
	{
		m_tableauDeCube[i].setisOnCursor(false);	
		//std::cout << "ici: " << m_tableauDeCube[i].getId() << '\n';
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
				return 42;
			}
			for(int n = 0; n < 81; n++){
				if(m_tableauDeCube[n].isOnCursor() == true){continue;}
				sf::FloatRect tmpRect = m_tableauDeCube[i].getSprite().getGlobalBounds();
				tmpRect.top = tmpRect.top + 32;
				if(m_tableauDeCube[n].getSprite().getGlobalBounds().intersects(tmpRect)){
					//std::cout << "COLLISION";
					//m_cursor.up();
					return 42;
				}
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
	for(int i = 0; i < 81; i++)
	{
		if(m_tableauDeCube[i].isOnCursor() == false){continue;}//que le cursorblock
		
		for(int n = 0; n < 81; n++){
			if(m_tableauDeCube[n].isOnCursor() == true){continue;}//que les blockcarte
			sf::FloatRect tmpRect = m_tableauDeCube[i].getSprite().getGlobalBounds();
			
			tmpRect.left = tmpRect.left - 32;
			if(m_tableauDeCube[n].getSprite().getGlobalBounds().intersects(tmpRect)){
				return;
			}
		}
	}
	m_cursor.onLeft();
}

void Grille::onRight(){
	for(int i = 0; i < 81; i++)
	{
		if(m_tableauDeCube[i].isOnCursor() == false){continue;}//que le cursorblock
		
		for(int n = 0; n < 81; n++){
			if(m_tableauDeCube[n].isOnCursor() == true){continue;}//que les blockcarte
			sf::FloatRect tmpRect = m_tableauDeCube[i].getSprite().getGlobalBounds();
			
			tmpRect.left = tmpRect.left + 32;
			if(m_tableauDeCube[n].getSprite().getGlobalBounds().intersects(tmpRect)){
				return;
			}
		}
	}
	m_cursor.onRight();
}
