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
		static LARGE_INTEGER CpuFrequency; //�� cpu ���� ������ 
		static LARGE_INTEGER PrevFrequency; //�� cpu ���� ������ 
		static LARGE_INTEGER CurFrequency; //�� cpu ���� ������ 
		static float DeltaTimeValue;
	};

}

