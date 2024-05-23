#include <concepts>
#include <string>
#include <arithmetic_concept.h>
#include <Object.h>
#include <Vector2.h>
#include <Component.h>
#include <Concept.h>
#include <Transform.h>

namespace LLGP {

	

	class GameObject :public Object
	{
	public:
		GameObject();
		GameObject(const GameObject&) = default;

		~GameObject();

		Transform* transform;
		inline void SetName(std::string newName) { m_Name = newName; }
		inline std::string GetName() { return m_Name; }

		void SetActive(bool newActive);
		inline bool GetActive() { return m_Active; }

		inline void SetTag(std::string newtag) { m_Tag = newtag; }
		inline bool CompareTag(std::string comp) { return m_Tag == comp; }

		template<class T> requires isComponent<T> T* GetComponent();
		template<class T> requires isComponent<T> T* AddComponent();
		template<class T> requires isComponent<T> bool RemoveComponent(T* comp);

	private:
		std::string m_Name;
		bool m_Active;
		std::string m_Tag;
		std::vector<std::unique_ptr<Component>> m_Components;

	public:
		inline bool operator==(const GameObject& other) { return this->uuid == other.uuid; }
		inline bool operator!=(const GameObject& other) { return !(*this == other); }
	};

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
		std::unique_ptr<Component> newComp = std::make_unique<T>(this);
		m_Components.push_back(std::move(newComp));
		return dynamic_cast<T*>(m_Components[m_Components.size() -1].get());
	}
}