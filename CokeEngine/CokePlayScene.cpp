#include "CokePlayScene.h"
#include "CokeGameObject.h"
#include "CokePlayer.h"
#include "CokeTransform.h"
#include "CokeSpriteRenderer.h"
#include "CokeInput.h"
#include "CokeTitleScene.h"
#include "CokeSceneManager.h"
#include "CokeObject.h"
#include "CokeTexture.h"
#include "CokeResources.h"

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
		 //게임오브젝트 만들기 전에 리소스들 전부 Load 해두면 좋음
		bg = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
		SpriteRenderer* sr
			= bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->SetTexture(Resources::Find<graphics::Texture>(L"BG"));

		/*graphics::Texture* tex = new graphics::Texture();
		tex->Load(L"C:\\hj\\GitHub\\MyEngine\\CokeEngine\\Resources\\noon.png");*/

		//게임오브젝트 생성 후에 레이어와 게임오브젝트들의 init 함수 호출
		Scene::Initialize();
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
		/*Transform* tr = bg -> GetComponent<Transform>();
		tr->SetPosition(Vector2(0,0));*/
	}
}