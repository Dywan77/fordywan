#include "After.h"

After::After(){
	m_t_after.loadFromFile("image/after.png");
	m_s_after.setTexture(m_t_after);
	m_s_after.setPosition(32*12, 32*4);

	one.changeID();
	two.changeID();
	three.changeID();

	one.getSprite().setPosition(384, 128);
	two.getSprite().setPosition(384, 160);
	three.getSprite().setPosition(384,192);
}

void After::draw(sf::RenderWindow &window){
	window.draw(m_s_after);
	window.draw(one.getSprite());
	window.draw(two.getSprite());
	window.draw(three.getSprite());

}
void After::shuffle(){
	one.changeID();
	two.changeID();
	three.changeID();
}
