#pragma once
#include "CommonInclude.h"

namespace coke
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return DeltaTimeValue;}

	private:
		static LARGE_INTEGER CpuFrequency; //내 cpu 고유 진동수 
		static LARGE_INTEGER PrevFrequency; //내 cpu 고유 진동수 
		static LARGE_INTEGER CurFrequency; //내 cpu 고유 진동수 
		static float DeltaTimeValue;
	};

}

