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

		class GameObject* mTarget; //���� Ÿ��
		Vector2 mDistance; //ī�޶��� ��ġ
		Vector2 mResolution; //ȭ�� �ػ�
		Vector2 mLookPosition;
	};

}

