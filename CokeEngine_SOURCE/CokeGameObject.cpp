#include "CokeGameObject.h"
#include "CokeInput.h"
#include "CokeTime.h"
#include "CokeComponent.h"
#include "CokeTransform.h"

namespace coke
{
	GameObject::GameObject()
	{
		InitializeTransform();
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			comp->Initialize();
		}
	}
	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			comp->Update();
		}
		//const int speed = 100.0f;
		////Å° ÀÔ·Â 
		//if (Input::GetKey(eKeyCode::A))
		//{
		//	mX -= speed * Time::DeltaTime();
		//}
		//if (Input::GetKey(eKeyCode::D))
		//{
		//	mX += speed * Time::DeltaTime();
		//}
		//if (Input::GetKey(eKeyCode::W))
		//{
		//	mY -= speed * Time::DeltaTime();
		//}
		//if (Input::GetKey(eKeyCode::S))
		//{
		//	mY += speed * Time::DeltaTime();
		//}

	}
	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			comp->LateUpdate();
		}
	}
	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			comp->Render(hdc);
		}
		
	}
	void GameObject::InitializeTransform()
	{
		AddComponent<Transform>();
	}
}
