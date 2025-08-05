#pragma once
#include "..\\CokeEngine_SOURCE\\CokeResources.h"
#include "..\\CokeEngine_SOURCE\\CokeTexture.h"

namespace coke
{
	void LoadReaources()
	{
		//Resources::Load<graphics::Texture>(L"BG", L"C:\\GitHub\\MyEngine\\CokeEngine\\Resources\\noon.png");
		Resources::Load<graphics::Texture>(L"Map", L"C:\\GitHub\\MyEngine\\CokeEngine\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"Pacman", L"C:\\GitHub\\MyEngine\\CokeEngine\\Resources\\img\\pacman\\0.png");
		Resources::Load<graphics::Texture>(L"Cat", L"C:\\GitHub\\MyEngine\\CokeEngine\\Resources\\ChickenAlpha.bmp");
	}
}