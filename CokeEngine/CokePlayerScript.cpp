#include "CokePlayerScript.h"
#include "CokeInput.h"
#include "CokeTransform.h"
#include "CokeTime.h"
#include "CokeGameObject.h"

namespace coke
{
	coke::PlayerScript::PlayerScript()
	{
	}

	coke::PlayerScript::~PlayerScript()
	{
	}

	void coke::PlayerScript::Initialize()
	{
	}

	void coke::PlayerScript::Update()
	{
		if (Input::GetKeyDown(eKeyCode::Right))
		{
			Transform* tr = GetOwner()-> GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		if (Input::GetKeyDown(eKeyCode::Left))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x -= 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
	}

	void coke::PlayerScript::LateUpdate()
	{
	}

	void coke::PlayerScript::Render(HDC hdc)
	{
	}

}
