#pragma once
#include "Common.h"


namespace ch
{
	class Time
	{
	public:
		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);

		static float DeltaTime() { return mDeltaTime; }

		static float DayTime() { return mDayTime; }

		//DayTime 
		static float mDayTime;
		static int mDays;

	private:
		//CPU 고유 진동수 ( 1초당 몇번 ) 1초 12000번 진동하는 CPU
		static LARGE_INTEGER mCpuFrequency;
		static LARGE_INTEGER mPrevFrequency;
		static LARGE_INTEGER mCurFrequency;

		static float mDeltaTime;
		static float mTime;
	};
}
