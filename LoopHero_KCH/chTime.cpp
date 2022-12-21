#include "chTime.h"
#include "chApplication.h"

namespace ch
{
	LARGE_INTEGER Time::mCpuFrequency;
	LARGE_INTEGER Time::mPrevFrequency;
	LARGE_INTEGER Time::mCurFrequency;
	float Time::mDeltaTime = 0.0f;
	float Time::mTime = 0.0f;

	void Time::Initialize()
	{
		// Sleep();
		// CPU 초당 반복되는 진동수를 얻어오는 함수
		QueryPerformanceFrequency(&mCpuFrequency);

		// 프로그램 시작 했을때 cpu의 클럿 수
		QueryPerformanceCounter(&mPrevFrequency);
	}

	//초기화
	int Time::mDays = 0;
	float Time::mDayTime = 0;

	void Time::Tick()
	{
		QueryPerformanceCounter(&mCurFrequency);

		float differenceFrequency
			= static_cast<float>(mCurFrequency.QuadPart - mPrevFrequency.QuadPart);
		mDeltaTime = differenceFrequency / static_cast<float>(mCpuFrequency.QuadPart);

		// 다시 이전의 값을 새로운 지금 값으로 세팅
		mPrevFrequency.QuadPart = mCurFrequency.QuadPart;

		//DayTime
		mDayTime += mDeltaTime;

		mDays = 0;
		if (mDayTime >= 10.0f) 
		{
			mDays = 1;
			mDayTime = 0;
		}
		
	}

	void Time::Render(HDC hdc)
	{
		mTime += Time::DeltaTime();
		if (mTime > 1.0f)
		{
			wchar_t szFloat[50] = {};
			float fps = 1.0f / mDeltaTime;
			swprintf_s(szFloat, 50, L"fps : %f", fps);

			HWND hWnd
				= Application::GetInstance().GetWindowData().hWnd;

			SetWindowText(hWnd, szFloat);
			mTime = 0.0f;
		}
	}
}