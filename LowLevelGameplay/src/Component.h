#pragma once

#include <Object.h>
#include <Vector2.h>

namespace LLGP
{

	class GameObject;

	class Component : public Object
	{
	public:
		Component(GameObject* owner) : _GameObject(owner) { _GameObject = owner; }
		Component() = default;
		~Component() {}

		GameObject* GetGameObject() { return _GameObject; }

		virtual void OwnerActiveChange(bool newActive) {}

	protected:
		GameObject* _GameObject;
	};
}