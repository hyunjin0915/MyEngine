#pragma once
#include "..\\CokeEngine_SOURCE\\CokeGameObject.h"

namespace coke
{
	class Player : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};

}

