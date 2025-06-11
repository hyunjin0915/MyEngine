#include "CokeGameObject.h"
#include "CokeInput.h"

namespace coke
{
	GameObject::GameObject()
		:mX(0.0f)
		,mY(0.0f)
	{

	}

	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{
		//Å° ÀÔ·Â 
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= 0.01f;
		}
		if (Input::GetKey(eKeyCode::D))
		{
			mX += 0.01f;
		}
		if (Input::GetKey(eKeyCode::W))
		{
			mY -= 0.01f;
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mY += 0.01f;
		}

	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);

		/*HPEN newPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(mHdc, newPen);
		Ellipse(mHdc, 200, 200, 300, 300);

		SelectObject(mHdc, oldPen);
		DeleteObject(newPen);

		HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
		oldBrush = (HBRUSH)SelectObject(mHdc, grayBrush);
		Rectangle(mHdc, 400, 400, 500, 500);*/
	}
}
