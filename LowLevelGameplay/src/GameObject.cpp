#include <GameObject.h>


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
	std::unique_ptr<Component> newComp = std::makeunique<T>(this);
	m_Componentrs.pushh_back(std::move(neComp));
	return static_cast<T*>(m_Components[m_Components.size()].get());
}