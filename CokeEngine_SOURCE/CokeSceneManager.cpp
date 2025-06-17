#include "CokeSceneManager.h"

namespace coke
{
	std::map<std::wstring, Scene*> SceneManager::mScene;
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
		//mActiveScene->Initialize();
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}
}
