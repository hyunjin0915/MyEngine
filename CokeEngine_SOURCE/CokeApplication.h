#pragma once
#include "CommonInclude.h"
#include "CokeGameObject.h"

namespace coke
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();

		void Render();

	private:
		HWND mHwnd; //핸들 
		HDC mHdc; //DC도 미리 저장
		
		//플레이어
		GameObject mPlayer;
	};

}

