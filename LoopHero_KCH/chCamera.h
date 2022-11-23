#pragma once
#include "Common.h"


namespace ch
{
	class Image;
	class GameObject;
	class Camera
	{
	public:
		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);
		static Vector2 CalculatePos(Vector2 pos) { return pos - mDistance; }
		static void SetTarget(GameObject* gameObj) { mTarget = gameObj; }
		static void SetCameraEffect(eCameraEffect effect) { mEffect = effect; mAlphaTime = 0.0f;  }


	private:
		Camera() = default;
		~Camera() = default;

	protected:
		static Vector2 mResolution; // 화면 해상도
		static Vector2 mLookPosition;
		static Vector2 mDistance; // 해상도 중ㅇ심좌표와 현제 카메라의 간격차
		static GameObject* mTarget;

		static eCameraEffect mEffect;
		static Image* mCutton;    //검정색 이미지
		static float mAlphaTime;
		static float mCuttonAlpha;
		static float mEndTime;
	};


}