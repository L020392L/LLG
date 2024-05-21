#pragma once

#include <Object.h>

namespace LLGP
{

	class GameObject;

	class Component : public Object
	{
		Component(GameObject* owner) : _GameObject(owner) {}
		~Component() {}

		GameObject* GetGameObject() { return _GameObject; }

		virtual void OwnerActiveChange(bool newActive) {}

	protected:
		GameObject* _GameObject;
	};
}