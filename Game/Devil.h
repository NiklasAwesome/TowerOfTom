#include "Character.h"
#include <cstdlib>

class Devil : public Character
{
private:
	void setRandomDirection();
public:
	Devil(int x, int y);
	~Devil();
	void collided(GameObject *obstacle);
	void move(sf::Time delta);
};
