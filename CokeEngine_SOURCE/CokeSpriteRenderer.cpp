#include "CokeSpriteRenderer.h"
#include "CokeGameObject.h"
#include "CokeTransform.h"


namespace coke
{
	SpriteRenderer::SpriteRenderer()
	{
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Initialize()
	{
	}

	void SpriteRenderer::Update()
	{
	}

	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Rectangle(hdc, tr->GetX(), tr->GetY(), 100 + tr->GetX(), 100 + tr->GetY());

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);

	}

}
