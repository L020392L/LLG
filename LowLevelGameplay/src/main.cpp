#include <SFML/Graphics.hpp>
#include <Vector2.h>
#include <chrono>
#include <GameObject.h>
using namespace LLGP;

std::vector<LLGP::GameObject*> objects;

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

	LLGP::GameObject* player = new LLGP::GameObject();
	player->transform->SetLocation(Vector2<float>(450, 225));
	objects.push_back(player);
	player->AddComponent<Sprite>();
	player->GetComponent<Sprite>()->setSprite(Vector2<float>(20, 20), "Sprites/PlayerForward.png");

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

		for (int i = 0; i < objects.size(); i++)
		{
			if (objects[i]->GetComponent<Sprite>())
			{
				objects[i]->GetComponent<Sprite>()->UpdateSprite(deltaTime);
				window.draw(objects[i]->GetComponent<Sprite>()->shape);
			}
		}

		window.display();
	}	

	return 0;
}