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
#include "CokePlayerScript.h"
#include "CokeCamera.h"
#include "CokeRenderer.h"
#include "CokeAnimator.h"

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
		//main camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		/*SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(3.0f, 3.0f));*/
		mPlayer->AddComponent<PlayerScript>();
		
		graphics::Texture* pacmacTexture = Resources::Find<graphics::Texture>(L"MapleEffect");
		Animator* animator =  mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"CatFrontMove", pacmacTexture
			, Vector2(0.0f, 0.0f), Vector2(386.0f, 246.0f), Vector2::Zero, 8, 0.1f);
		animator->PlayAnimation(L"CatFrontMove", true);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
		mPlayer->GetComponent<Transform>()->SetRotation(30.0f);
		/*sr->SetTexture(pacmacTexture);*/


		GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::Particle);
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		//bgSr->SetSize(Vector2(3.0f, 3.0f));

		graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Bubble");
		bgSr->SetTexture(bgTexture);

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
		/*wchar_t str[50] = L"PlayScene";
		TextOut(hdc, 0, 0, str, 50);*/
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