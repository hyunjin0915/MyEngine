#include "CokeScene.h"

namespace coke
{
	Scene::Scene()
		: mLayers{}
	{
		mLayers.resize((UINT)enums::eLayerType::Max);
		for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++)
		{
			mLayers[i] = new Layer();
		}
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr) return;

			layer->Initialize();
		}

	}

	void Scene::Update()
	{
		for(Layer* layer : mLayers)
		{
			if (layer == nullptr) return;

			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr) return;

			layer->LateUpdate();
		}

	}

	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr) return;

			layer->Render(hdc);
		}

	}
	void Scene::AddGameObject(GameObject* gameObject, enums::eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObject);
	}
	void Scene::OnEnter()
	{

	}
	void Scene::OnExit()
	{

	}


}
