#include <Object.h>
#include <GameObject.h>
#include <Component.h>
#include <Transform.h>

namespace LLGP
{
	GameObject::GameObject()
	{
		transform = AddComponent<Transform>();
	}

	
}