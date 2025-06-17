#include "CokeTitleScene.h"
#include "CokeInput.h"
#include "CokePlayScene.h"
#include "CokeSceneManager.h"

namespace coke
{
	TitleScene::TitleScene()
	{
	}

	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Initialize()
	{
		Scene::Initialize();
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void TitleScene::Render(HDC hdc)
	{

		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 50);
	}

}
