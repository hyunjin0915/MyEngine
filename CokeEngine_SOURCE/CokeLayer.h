#pragma once
#include "CokeEntity.h"
#include "CommonInclude.h"
#include "CokeGameObject.h"

namespace coke
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);

	private:
		enums::eLayerType mType;

		std::vector<GameObject*> mGameObjects;
	};


}
