#pragma once
#include "..\\CokeEngine_SOURCE\\CokeResources.h"
#include "..\\CokeEngine_SOURCE\\CokeTexture.h"

namespace coke
{
	void LoadReaources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"C:\\hj\\GitHub\\MyEngine\\CokeEngine\\Resources\\noon.png");

	}
}