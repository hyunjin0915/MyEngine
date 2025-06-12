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

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initalizeEtc();


	private:
		HWND mHwnd; //핸들 
		HDC mHdc; //DC도 미리 저장

		HDC mBackHdc;
		HBITMAP mBackBitmap;
		
		UINT mWidth;
		UINT mHeight;

		//std::vector<Scene*> mScenes;
		//std::vector<GameObject*> mGameObjects;
	};

}

