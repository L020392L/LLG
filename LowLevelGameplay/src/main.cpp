#include <SFML/Graphics.hpp>
#include <Vector2.h>
using namespace LLGP;

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	
	Vector2<float> rectSize = Vector2<float>::one * 100;
	Vector2<float> rectPos = Vector2<float>(900, 450);
	sf::RectangleShape shape(rectSize);
	shape.setOrigin(rectSize / 2);
	shape.setPosition(rectPos);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}