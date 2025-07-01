#pragma once

namespace coke ::enums
{
	enum class eLayerType
	{
		None,
		BackGround,
		Player,
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		//Mesh,
		//Shader,
		AudioClip,
		Prefab,
		End,
	};
}