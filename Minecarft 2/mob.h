#include <SFML/Graphics.hpp>

class Mob
{
protected:
	sf::RectangleShape body;
	int hp;
	int atk;
public:
	int gethp()
	{
		return hp;
	}
	int getatk()
	{
		return atk;
	}
};

class Creeper : private Mob
{
	Creeper()
	{
		hp = 20;
		atk = 30;
	}
};

class Zombie : private Mob
{
	Zombie()
	{
		hp = 25;
		atk = 20;
	}
};