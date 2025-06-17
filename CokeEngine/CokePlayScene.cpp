#include "CokePlayScene.h"
#include "CokeGameObject.h"
#include "CokePlayer.h"
#include "CokeTransform.h"
#include "CokeSpriteRenderer.h"
#include "CokeInput.h"
#include "CokeTitleScene.h"
#include "CokeSceneManager.h"

namespace coke
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		/*Player* pl = new Player();
		Transform* tr
			= pl->AddComponent<Transform>();
		tr->SetPos(800, 450);

		tr->SetName(L"TR");

		SpriteRenderer* sr
			= pl->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");

		AddGameObject(pl);*/

		 bg = new Player();
			Transform* tr
			= bg->AddComponent<Transform>();
		tr->SetPos(Vector2(0, 0));

		tr->SetName(L"TR");

		SpriteRenderer* sr
			= bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\Github\\MyEngine\\CokeEngine\\Resources\\CloudOcean.png");


		AddGameObject(bg);
	}
	void PlayScene::Update()
	{
		Scene::Update();
		/*for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Update();
		}
		*/
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"PlayScene";
		TextOut(hdc, 0, 0, str, 50);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		Transform* tr = bg -> GetComponent<Transform>();
		tr->SetPos(Vector2(0,0));
	}
}