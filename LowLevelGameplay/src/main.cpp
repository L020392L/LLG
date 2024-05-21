#include <SFML/Graphics.hpp>
#include <Vector2.h>
#include <chrono>
using namespace LLGP;

int main()
{
	std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();
	float deltaTime = 0.f;

	sf::RenderWindow window(sf::VideoMode(900, 450), "SFML works!");
	
	Vector2<float> rectSize = Vector2<float>(900, 450);
	Vector2<float> rectPos = Vector2<float>(450, 225);
	sf::Texture rectTex; rectTex.loadFromFile("Space.png");
	sf::RectangleShape shape(rectSize);
	shape.setTexture(&rectTex);
	shape.setOrigin(rectSize / 2);
	shape.setPosition(rectPos);

	while (window.isOpen())
	{
		std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
		deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - lastTime).count() / 1000000.f;
		lastTime = now;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			
		}

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