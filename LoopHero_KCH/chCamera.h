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
		static Vector2 mResolution; // ȭ�� �ػ�
		static Vector2 mLookPosition;
		static Vector2 mDistance; // �ػ� �ߤ�����ǥ�� ���� ī�޶��� ������
		static GameObject* mTarget;

		static eCameraEffect mEffect;
		static Image* mCutton;    //������ �̹���
		static float mAlphaTime;
		static float mCuttonAlpha;
		static float mEndTime;
	};


}