#include <SFML/Graphics.hpp>
#include <iostream>

class Game
{
	public:
		Game();
		Game(unsigned inputSizeX, unsigned inputSizeY);
		

		int getSizeXW();
		int getSizeYW();

		bool setSizeXW(int setX);

		bool setSizeYW(int setY);
		int mainGame();
	protected:
		void createWindow(sf::Vector2u size);

	private :
		int m_sizeX;
		int m_sizeY;
		sf::Event m_event;
		sf::RenderWindow m_window;
};
