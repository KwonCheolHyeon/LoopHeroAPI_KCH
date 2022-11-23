#include "chCamera.h"
#include "chApplication.h"
#include "chGameObject.h"
#include "chInput.h"
#include "chTime.h"
#include "chImage.h"

namespace ch
{
	Vector2 Camera::mResolution = Vector2::Zero;
	Vector2 Camera::mLookPosition = Vector2::Zero;
	Vector2 Camera::mDistance = Vector2::Zero;
	GameObject* Camera::mTarget = nullptr;

	eCameraEffect Camera::mEffect = eCameraEffect::None;;
	Image* Camera::mCutton = nullptr;
	float Camera::mAlphaTime = 0.0f;
	float Camera::mCuttonAlpha = 0.0f;
	float Camera::mEndTime = 5.0f;

	void Camera::Initialize()
	{
		WindowData data = Application::GetInstance().GetWindowData();
		mResolution = Vector2(data.width, data.height);
		mLookPosition = (mResolution / 2.0f);

		//mEffect = eCameraEffect::FadeOut;
		mCutton = Image::Create(L"CameraCutton", 1600, 900);
	}

	void Camera::Tick()
	{
		if (mAlphaTime <= mEndTime)
		{
			
			mAlphaTime += Time::DeltaTime() * 2;
			float ratio = (mAlphaTime / mEndTime);

			if (eCameraEffect::FadeIn == mEffect)
			{
				
				mCuttonAlpha = 1.0f - ratio;
			}
			else if (eCameraEffect::FadeOut == mEffect)
			{
				mCuttonAlpha = ratio;
			}
		}



		if (KEY_PREESE(eKeyCode::UP))
		{
			mLookPosition.y -= 600.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(eKeyCode::DOWN))
		{
			mLookPosition.y += 600.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(eKeyCode::LEFT))
		{
			mLookPosition.x -= 600.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(eKeyCode::RIGHT))
		{
			mLookPosition.x += 600.0f * Time::DeltaTime();
		}


		if (mTarget != nullptr)
			mLookPosition = mTarget->GetPos();

		mDistance = mLookPosition - (mResolution / 2.0f);
	}

	void Camera::Render(HDC hdc)
	{
		if (mCuttonAlpha <= 0.0f)
			return;

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = 0;
		func.SourceConstantAlpha = (BYTE)(255.0f * mCuttonAlpha);

		AlphaBlend(hdc, 0, 0
			, mCutton->GetWidth(), mCutton->GetHeight()
			, mCutton->GetDC(), 0, 0
			, mCutton->GetWidth(), mCutton->GetHeight()
			, func);
	}
}