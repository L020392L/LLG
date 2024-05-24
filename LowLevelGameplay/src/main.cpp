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

	LLGP::GameObject* child = new LLGP::GameObject();
	child->transform->SetLocation(Vector2<float>(225, 225));
	objects.push_back(child);
	child->AddComponent<Sprite>();
	child->GetComponent<Sprite>()->setSprite(Vector2<float>(20, 20), "Sprites/ChildForward.png");

	LLGP::GameObject* mother = new LLGP::GameObject();
	mother->transform->SetLocation(Vector2<float>(675, 225));
	objects.push_back(mother);
	mother->AddComponent<Sprite>();
	mother->GetComponent<Sprite>()->setSprite(Vector2<float>(20, 20), "Sprites/MotherForward.png");

	LLGP::GameObject* father = new LLGP::GameObject();
	father->transform->SetLocation(Vector2<float>(450, 337));
	objects.push_back(father);
	father->AddComponent<Sprite>();
	father->GetComponent<Sprite>()->setSprite(Vector2<float>(20, 20), "Sprites/FatherForward.png");

	LLGP::GameObject* enemy = new LLGP::GameObject();
	enemy->transform->SetLocation(Vector2<float>(450, 113));
	objects.push_back(enemy);
	enemy->AddComponent<Sprite>();
	enemy->GetComponent<Sprite>()->setSprite(Vector2<float>(20, 20), "Sprites/Enemy.png");

	while (window.isOpen())
	{
		std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
		deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - lastTime).count() / 1000000.f;
		lastTime = now;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player->transform->SetLocation(player->transform->GetLocation() + Vector2<float>(0, -.05));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player->transform->SetLocation(player->transform->GetLocation() + Vector2<float>(0, .05));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player->transform->SetLocation(player->transform->GetLocation() + Vector2<float>(-.05, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player->transform->SetLocation(player->transform->GetLocation() + Vector2<float>(.05, 0));
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