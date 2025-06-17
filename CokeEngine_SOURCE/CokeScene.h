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

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObject);

	private:
		std::vector<GameObject*> mGameObjects;


	};


}
