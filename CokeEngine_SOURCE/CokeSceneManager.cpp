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

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (mActiveScene)  mActiveScene->OnExit();

		std::map<std::wstring, Scene*>::iterator iter = mScene.find(name);
		if (iter == mScene.end())
		{
			return nullptr;
		}
		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		return iter->second;
	}

}
