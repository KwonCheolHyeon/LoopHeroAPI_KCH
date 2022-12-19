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
		//CPU ���� ������ ( 1�ʴ� ��� ) 1�� 12000�� �����ϴ� CPU
		static LARGE_INTEGER mCpuFrequency;
		static LARGE_INTEGER mPrevFrequency;
		static LARGE_INTEGER mCurFrequency;

		static float mDeltaTime;
		static float mTime;
	};
}
