#include "Sprite.h"

void LLGP::Sprite::setSprite(Vector2<float>size, std::string filepath)
{
	rectSize = size;
	rectPos = _GameObject->transform->GetLocation();
	rectTex.loadFromFile(filepath);
	shape = sf::RectangleShape(rectSize);
	shape.setTexture(&rectTex);
	shape.setOrigin(rectSize / 2);
	shape.setPosition(rectPos);
}

void LLGP::Sprite::UpdateSprite(float deltaTime)
{
	rectPos = GetGameObject()->transform->GetLocation();
	shape.setPosition(rectPos);
}
