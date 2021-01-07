#include "oneverytime.h"

bool everyTicks(int ticks){
	std::map<int, int> static tabl;
	static sf::Clock clock;
	//std::cout << tabl[ticks] << '\n';
	//std::cout << clock.getElapsedTime().asMilliseconds() << '\n';
	
	if(tabl[ticks] < clock.getElapsedTime().asMilliseconds())
	{
		tabl[ticks] = clock.getElapsedTime().asMilliseconds() + ticks;
		return true;
	}
	//std::cout << clock()/CLOCKS_PER_SEC << '\n';
	return false;
}
