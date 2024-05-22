#include <concepts>
#include <string>
#include <arithmetic_concept.h>
#include <Object.h>
#include <Vector2.h>
#include <Component.h>
#include <Concept.h>

namespace LLGP {

	struct Transform
	{
		Vector2<float> location;
		float rotation;
		Vector2<float> scale;
	};

	class GameObject :public Object
	{
	public:
		GameObject();
		GameObject(const GameObject&) = default;
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
}