#pragma once
#include "..\\CokeEngine_SOURCE\\CokeScene.h"

namespace coke
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update()override;
		void LateUpdate()override;
		void Render(HDC hdc)override;
	private:

	};


}
