#pragma once
#include <Vector2.h>
#include <Component.h>

namespace LLGP 
{
	class Transform : public Component
	{
	public:
		Transform(GameObject* owner) :Component(owner) { location = (Vector2<float>::zero), rotation = (0.0f), scale = (Vector2<float>::one); }

		void SetTransform(Vector2<float> _location, float _rotation, Vector2<float> _scale) { location = _location; rotation = _rotation; scale = _scale; };
		
		Vector2<float> GetLocation() { return location; };
		void SetLocation(Vector2<float> _location) { location = _location; };

		float GetRotation() { return rotation; };
		void SetRotation(float _rotation) { rotation = _rotation; };

		Vector2<float> GetScale() { return scale; };
		void SetScale(Vector2<float> _scale) { scale = _scale; };
	private:
		Vector2<float> location;
		float rotation;
		Vector2<float> scale;
	};
}