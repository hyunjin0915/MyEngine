#include "CokeTime.h"

namespace coke
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurFrequency = {};
	float Time::DeltaTimeValue=0.0f;

	void coke::Time::Initialize()
	{
		//CPU ���� ������ ���� 
		QueryPerformanceFrequency(&CpuFrequency);

		//���α׷��� �������� �� ���� ������ 
		QueryPerformanceCounter(&PrevFrequency);
	}

	void coke::Time::Update()
	{
		QueryPerformanceCounter(&CurFrequency);

		float differenceFrequency
			= static_cast<float>(CurFrequency.QuadPart - PrevFrequency.QuadPart);

		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;
		
		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %f", fps);
		int len = wcsnlen_s(str, 50);


		TextOut(hdc, 0, 0, str, len);
	}

}
