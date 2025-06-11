#include "CokeGameObject.h"

namespace coke
{
	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{
		//Å° ÀÔ·Â 
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= 0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
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
