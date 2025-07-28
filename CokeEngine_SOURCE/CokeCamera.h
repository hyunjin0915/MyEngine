#pragma once
#include "CokeComponent.h"

namespace coke
{
	using  namespace coke::math;

	class Camera : public Component
	{
	public:
		Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; };

		Camera();
		~Camera();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;
	private:
		//std::vector<GameObject*> mGameObjects;

		class GameObject* mTarget; //따라갈 타겟
		Vector2 mDistance; //카메라의 위치
		Vector2 mResolution; //화면 해상도
		Vector2 mLookPosition;
	};

}

