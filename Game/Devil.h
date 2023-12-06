#include "Character.h"
#include <cstdlib>

class Devil : public Character
{
private:
	void setRandomDirection();
public:
	Devil(int x, int y, sf::Texture &texture);
	~Devil();
	void collided(GameObject *obstacle);
	void move(sf::Time delta);
};
