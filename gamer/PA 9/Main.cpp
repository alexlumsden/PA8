#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<string>
#include<iostream>

int main() {
	// test
	int area = 0, check = 0, newarea = 0, hassword = 0;
	//Create Window
	sf::RenderWindow window(sf::VideoMode(1280, 720), "MineCrap");
	window.setFramerateLimit(60);

	//Create Font (display score)
	sf::Font font;
	font.loadFromFile("comicz.ttf");


	sf::Music music;
	music.openFromFile("images/inthestone.wav");
	music.play();
	
	sf::Texture gamer1;
	if (!gamer1.loadFromFile("images/gamertexture.png", sf::IntRect(0, 0, 100, 100)))
	{

		// error...
	}
	sf::Sprite gamer1S(gamer1);

	
	sf::Texture sword;
	if (!sword.loadFromFile("images/sword.png", sf::IntRect(0, 0, 250, 100)))
	{

		// error...
	}
	sf::Sprite swordS(sword);


	sf::Texture inventory;
	if (!inventory.loadFromFile("images/inventory.png", sf::IntRect(0, 0, 250, 100)))
	{

		// error...
	}
	sf::Sprite inventoryS(inventory);


	sf::Texture land1;
	if (!land1.loadFromFile("images/land1.png", sf::IntRect(0, 0, 1280, 720)))
	{

		// error...
	}
	sf::Sprite land1S(land1);


	sf::Texture land2;
	if (!land2.loadFromFile("images/land2.png", sf::IntRect(0, 0, 1280, 720)))
	{

		// error...
	}
	sf::Sprite land2S(land2);


	sf::Texture land2v2;
	if (!land2v2.loadFromFile("images/land2v2.png", sf::IntRect(0, 0, 1280, 720)))
	{

		// error...
	}
	sf::Sprite land2v2S(land2v2);


	sf::Texture land3;
	if (!land3.loadFromFile("images/land3.png", sf::IntRect(0, 0, 1280, 720)))
	{

		// error...
	}
	sf::Sprite land3S(land3);


	sf::Texture end1;
	if (!end1.loadFromFile("images/end1.png", sf::IntRect(0, 0, 1280, 720)))
	{

		// error...
	}
	sf::Sprite end1S(end1);


	sf::Texture end2;
	if (!end2.loadFromFile("images/end2.png", sf::IntRect(0, 0, 1280, 720)))
	{

		// error...
	}
	sf::Sprite end2S(end2);

	//Game Loop
	while (window.isOpen()) {
		
		sf::Vector2f coords = gamer1S.getPosition();
		if (area == 1)
		{
			if (newarea == 1)
			{
				gamer1S.setPosition(1000, 400);
				newarea = 0;
			}
			if (coords.x > 0)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					gamer1S.move(-10, 0);
				}

			}
			if (coords.x < 1280)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					gamer1S.move(10, 0);
					if (coords.x > 1180)
					{
						newarea = 1;
						area = 0;
						hassword = 1;
					}
				}
			}
			if (coords.y > 220 || coords.x > 900)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					gamer1S.move(0, -10);
				}
			}
			else
			{
				if (check == 0)
				{
					gamer1S.move(200, 350);
				}
			}
			if (coords.y < 520)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					gamer1S.move(0, 10);
				}
			}
		}
		if (area == 2)
		{
			if (newarea == 1)
			{
				gamer1S.setPosition(20, 600);
				newarea = 2;
			}
			if (coords.x > 0)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					gamer1S.move(-10, 0);
				}

			}
			if (coords.x < 680)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					gamer1S.move(10, 0);
				}
			}
			if (coords.y > 320 || coords.x > 600)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					gamer1S.move(0, -10);
					if (coords.y < 200 && newarea == 0)
					{
						if (hassword == 0)
						{
							area = 4;
						}
						else
						{
							area = 5;
						}
					}
					newarea = 0;
				}
			}
			else
			{
				if (check == 0)
				{
					gamer1S.move(200, 350);
				}
			}
			if (coords.y < 520)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					gamer1S.move(0, 10);
				}
			}
		}
		if (area == 0)
		{
			if (newarea == 1)
			{
				gamer1S.setPosition(20, 400);
				newarea = 0;
			}
			if (coords.x > 0)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					gamer1S.move(-10, 0);
					if (coords.x < 15)
					{
						newarea = 1;
						area = 1;
					}
				}

			}
			if (coords.x < 980)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					gamer1S.move(10, 0);
				}
			}
			if (coords.y > 220 || coords.x > 900)
			{
				check = 1;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					gamer1S.move(0, -10);
				}
				if (coords.x > 900 && coords.y < 100)
				{
					newarea = 1;
					area = 2;
				}
			}
			else
			{
				if (check == 0)
				{
					gamer1S.move(200, 350);
				}
			}
			if (coords.y < 520)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					gamer1S.move(0, 10);
				}
			}
			
		}

		//Check if the window was closed
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
		}

		//Render
		window.clear();
		if (area == 0)
		{
			window.draw(land1S);
			window.draw(gamer1S);
		}
		if (area == 2)
		{
			window.draw(land3S);
			window.draw(gamer1S);
		}
		if (area == 1)
		{
			if (hassword == 0)
			{
				window.draw(land2S);
			}
			else
			{
				window.draw(land2v2S);
			}
			window.draw(gamer1S);
		}
		if (area == 4)
		{
			window.draw(end1S);
		}
		if (area == 5)
		{
			window.draw(end2S);
		}
		if (area < 4)
		{
			if (hassword == 0)
			{
				window.draw(inventoryS);
			}
			else
			{
				window.draw(swordS);
			}
		}
		window.display();
	}
	return 0;
}