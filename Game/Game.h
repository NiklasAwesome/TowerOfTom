#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
#include "Map.h"

class Game
{
private:
	sf::RenderWindow window{sf::VideoMode(1024, 576), "Gametitle"};
	Map map;
	void update(sf::Time delta);
public:
	Game(/* args */);
	~Game();
	void run();
};
