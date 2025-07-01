#pragma once
#include "CokeComponent.h"
#include "CokeGameObject.h"
#include "CokeLayer.h"
#include "CokeScene.h"
#include "CokeSceneManager.h"
#include "CokeTransform.h"


namespace coke::object
{
	template <typename T>
	static T* Instantiate(coke::enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}
	
	template <typename T>
	static T* Instantiate(coke::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr ->SetPosition(position);

		return gameObject;
	}
}