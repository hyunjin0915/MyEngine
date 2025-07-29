#pragma once
#include "..\\CokeEngine_SOURCE\\CokeSceneManager.h"
#include "..\\CokeEngine\\CokePlayScene.h"
#include "..\\CokeEngine\\CokeTitleScene.h"


#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\CokeEngine.lib")
#else
#pragma comment (lib, "..\\x64\\Release\\CokeEngine.lib")
#endif

namespace coke
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::LoadScene(L"PlayScene");

	}
}