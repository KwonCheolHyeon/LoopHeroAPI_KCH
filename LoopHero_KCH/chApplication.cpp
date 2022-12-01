#include "chApplication.h"
#include "chSceneManager.h"
#include "chTime.h"
#include "chInput.h"
#include "chResources.h"
#include "chCollisionManager.h"
#include "chCamera.h"

namespace ch
{
	//Application Application::mInstance;
	void Application::Initialize(WindowData data)
	{
		initializeWindow(data);

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialize();
		Camera::Initialize();
		

	}

	void Application::initializeAtlasWindow(WindowData data)
	{
		mAtlasWindowData = data;
		mAtlasWindowData.hdc = GetDC(data.hWnd);
	}


	void Application::Tick()
	{
		Time::Tick();
		Input::Tick();

		Camera::Tick();
		SceneManager::Tick();
		CollisionManager::Tick();

		// clear
		//Brush brush(mWindowData.backBuffer, mBrushes[(UINT)eBrushColor::Gray]);
		HBRUSH hPrevBrush = (HBRUSH)SelectObject(mWindowData.backBuffer, mBrushes[(UINT)eBrushColor::Black]);
		Rectangle(mWindowData.backBuffer,
			-1, -1, mWindowData.width + 1, mWindowData.height + 1);
		SelectObject(mWindowData.backBuffer, hPrevBrush);

		SceneManager::Render(mWindowData.backBuffer);
		Camera::Render(mWindowData.backBuffer);
		Input::Render(mWindowData.backBuffer);
		Time::Render(mWindowData.backBuffer);

		// BitBlt 함수는 DC간에 이미지를 복사 해주는 함수
		BitBlt(mWindowData.hdc
			, 0, 0, mWindowData.width, mWindowData.height
			, mWindowData.backBuffer, 0, 0, SRCCOPY);

		// gameObject 삭제
		SceneManager::DetroyGameObject();
	}

	Application::Application()
	{
		mWindowData.clear();
	}

	Application::~Application()
	{
		SceneManager::Release();
		Resources::Release();

		ReleaseDC(mWindowData.hWnd, mWindowData.hdc);
		ReleaseDC(mWindowData.hWnd, mWindowData.backBuffer);
	}

	void Application::initializeWindow(WindowData data)
	{
		mWindowData = data;
		mWindowData.hdc = GetDC(data.hWnd);

		//1922 
		// 비트맵 해상도를 설정하기 위한 실제 위도우 크기 계산
		RECT rect = { 0, 0, mWindowData.width, mWindowData.height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		// 윈도우 크기 변경
		SetWindowPos(mWindowData.hWnd,
			nullptr, 0, 0
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0
		);

		ShowWindow(mWindowData.hWnd, true);

		mWindowData.backTexture
			= CreateCompatibleBitmap(mWindowData.hdc, mWindowData.width, mWindowData.height);

		mWindowData.backBuffer = CreateCompatibleDC(mWindowData.hdc);
		HBITMAP dafaultBitmap
			= (HBITMAP)SelectObject(mWindowData.backBuffer, mWindowData.backTexture);

		DeleteObject(dafaultBitmap);


		// 메모리 해재 해주어야한다.
		mPens[(UINT)ePenColor::Red] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		mPens[(UINT)ePenColor::Green] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		mPens[(UINT)ePenColor::Blue] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));

		mBrushes[(UINT)eBrushColor::Transparent] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
		mBrushes[(UINT)eBrushColor::Black] = (HBRUSH)GetStockObject(BLACK_BRUSH);
		mBrushes[(UINT)eBrushColor::Gray] = (HBRUSH)GetStockObject(GRAY_BRUSH);
		mBrushes[(UINT)eBrushColor::White] = (HBRUSH)GetStockObject(WHITE_BRUSH);

	}
}