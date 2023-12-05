#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <string>

class GameObject
{
protected:
	float size;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f prevLocation{0,0};
	sf::Vector2f location{0,0};
	void setTexture(std::string imagePath);
public:
	bool collidable{false};
	GameObject(int xLocation, int yLocation);
	virtual ~GameObject();
	virtual void move(sf::Time delta) = 0;
	void draw(sf::RenderWindow &window);
	virtual void collided(GameObject *obstacle);
	float upBound();
	float downBound();
	float leftBound();
	float rightBound();
};


#endif