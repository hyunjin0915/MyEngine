#include "CokeGameObject.h"
#include "CokeInput.h"
#include "CokeTime.h"
#include "CokeComponent.h"
#include "CokeTransform.h"

namespace coke
{
	GameObject::GameObject()
	{
		mComponents.resize((UINT)enums::eComponentType::End);
		InitializeTransform();
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
			{
				continue;
			}
			comp->Initialize();
		}
	}
	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
			{
				continue;
			}
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
			if (comp == nullptr)
			{
				continue;
			}
			comp->LateUpdate();
		}
	}
	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
			{
				continue;
			}
			comp->Render(hdc);
		}
		
	}
	void GameObject::InitializeTransform()
	{
		AddComponent<Transform>();
	}
}
