#pragma once

#include <Vector2.h>
#include <Component.h>
#include <GameObject.h>
#include <string>

namespace LLGP
{
	class Sprite : public Component
	{
	public:
		Sprite(GameObject* owner) { _GameObject = owner; }
		~Sprite() {}
		Vector2<float> rectSize = Vector2<float>().zero;
		Vector2<float> rectPos = Vector2<float>().zero;
		sf::Texture rectTex;
		sf::RectangleShape shape;

		void setSprite(Vector2<float>size, std::string fp);

		void UpdateSprite(float deltaTime);
	};
}