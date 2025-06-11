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
		HWND mHwnd; //�ڵ� 
		HDC mHdc; //DC�� �̸� ����
		
		//�÷��̾�
		GameObject mPlayer;
	};

}

