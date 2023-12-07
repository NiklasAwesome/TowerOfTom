#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
#include "Map.h"

class Game
{
private:
	/**
	 * @brief The window that the game is displayed in.
	 * 
	 */
	sf::RenderWindow window{sf::VideoMode(1024, 576), "Tower of Tom"};
	/**
	 * @brief The object that represents the games map.
	 * 
	 */
	Map map;
	/**
	 * @brief updates everything about the game from movements to damage and beyond.
	 * 
	 * @param delta The diffrents in time since last update cycle.
	 */
	void update(sf::Time delta);
	void endScreen(bool won, sf::Time playTime);
	float finalPlayTime{0};
public:
	Game(/* args */);
	~Game();
	/**
	 * @brief Runs the game.
	 * 
	 * 
	 */
	void run();
};
