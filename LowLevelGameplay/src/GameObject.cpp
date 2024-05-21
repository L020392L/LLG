#include <Object.h>
#include <GameObject.h>
#include <Component.h>

namespace LLGP
{
	class GameObject;

	template<class T> requires isComponent<T>
	T* GameObject::GetComponent()
	{
		T* returnComp = nullptr;
		for (int i = 0; i < m_Components.size(); i++)
		{
			returnComp = static_Cast<T*>(m_Components[i].get());
			if (returnComp != nullptr)
			{
				break;
			}
		}
		return returnComp;
	}

	template<class T> requires isComponent<T>
	T* GameObject::AddComponent()
	{
		std::unique_ptr<Component> newComp = makeunique<T>(this);
		m_Components.push_back(std::move(newComp));
		return static_cast<T*>(m_Components[m_Components.size()].get());
	}
}