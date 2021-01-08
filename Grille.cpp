#include "Grille.h"

Grille::Grille(){
	m_t_grille.loadFromFile("image/grille.png");
	m_s_grille.setTexture(m_t_grille);
	m_s_grille.setPosition(32*5, 32*3);
	//std::begin();
	//std::end();
	for(auto i : m_tableauDeCube)
	{
		std::cout << "ici: " << i.getID() << '\n';
		//m_tableauDeCube[0] = new Cube(CNULL);	
	}
}

void Grille::draw(sf::RenderWindow &window){
	window.draw(m_s_grille);
	m_cursor.draw(window);
	//std::cout << "on print: " << m_tableauDeCube[50]->getID() << '\n';
	/*for(int i=0; i < 81; i++){
		if(m_tableauDeCube[i]->getID() == CNULL)
			std::cout << "on print: " << i;
	}*/
}

int Grille::getCubeVide(){
	for(int i=0; i < 81; i++)
	{
		//std::cout << "ici: " << i << '\n';
		//if(m_tableauDeCube[i].data()->getID() == CNULL)
		//	return i;
	}
	return -1;
}
