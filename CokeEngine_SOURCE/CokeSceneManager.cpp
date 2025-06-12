#include "CokeSceneManager.h"

namespace coke
{

	void coke::SceneManager::Initialize()
	{
	}

	void coke::SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void coke::SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void coke::SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}
}
