#ifndef __Musique_H__
#define __Musique_H__

#include <SFML/Audio.hpp>
#include <iostream>

enum e_musique{
	MUSIQUEMENU = 0,
	MUSIQUEJEUX = 3,
	MUSIQUEOPTION = 2
};

class Musique{

	public:
		Musique();
		void playZone(int zone);
		void stop()
		{
			m_music.stop();
		}
		void intro(){
			m_music.setLoop(false);
			m_music.openFromFile("song/debut.wav");
			m_music.play();
			sf::Clock tmpclock;
			while(tmpclock.getElapsedTime().asMilliseconds() <= 2500);
			m_music.stop();
			m_music.setLoop(true);
			std::cout << "HAHAHAHAH" << std::endl << std::endl;
		}
	private:
		sf::Music m_music;
};




#endif
