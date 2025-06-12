#include "CokeApplication.h"
#include "CokeInput.h"
#include "CokeTime.h"
#include "CokeSceneManager.h"

namespace coke
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)
	{

	}
	Application::~Application()
	{

	}
	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		initalizeEtc();

		SceneManager::Initialize();
		//for (int i = 0; i < 10; i++)
		//{
		//	GameObject* gameObj = new GameObject();
		//	gameObj->SetPosition(rand() % 1600, rand() % 900);
		//	mGameObjects.push_back(gameObj);

		//}

	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		Input::Update();
		Time::Update();

		SceneManager::Update();
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		clearRenderTarget();

		Time::Render(mBackHdc);
		SceneManager::Render(mBackHdc);


		copyRenderTarget(mBackHdc, mHdc);
	}
	void Application::clearRenderTarget()
	{
		//뒷 도화지에 그림
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}
	void  Application::copyRenderTarget(HDC source, HDC dest)
	{
		//원본 도화지는 지금 백지임 -> 옮겨야 함
		BitBlt(dest, 0, 0, mWidth, mHeight
			, source, 0, 0, SRCCOPY);
	}
	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);


		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0
			, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		//윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		//새로 생성한 백버퍼를 가르킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		//디폴트로 생성되는 흰색 도화지 지우기,
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}
	void Application::initalizeEtc()
	{
		Input::Initialize();
		Time::Initialize();
	}
}
