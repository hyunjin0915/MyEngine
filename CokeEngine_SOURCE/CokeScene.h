#pragma once
#include "CokeEntity.h"
#include "CokeGameObject.h"

namespace coke
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);
	private:
		std::vector<GameObject*> mGameObjects;


	};


}
