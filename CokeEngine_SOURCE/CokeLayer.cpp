#include "CokeLayer.h"

namespace coke
{
	Layer::Layer()
	{

	}
	Layer::~Layer()
	{

	}
	void Layer::Initialize()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr) return;

			gameObj->Initialize();
		}
	}
	void Layer::Update()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr) return;

			gameObj->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr) return;

			gameObj->LateUpdate();
		}
	}
	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr) return;

			gameObj->Render(hdc);
		}
	}
	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr) return;
		mGameObjects.push_back(gameObject);
	}

}
