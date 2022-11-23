#include "chAnimation.h"
#include "chImage.h"
#include "chAnimator.h"
#include "chGameObject.h"
#include "chCamera.h"
#include "chTime.h"

namespace ch
{
	Animation::Animation()
	{

	}
	Animation::~Animation()
	{

	}

	void Animation::Tick()
	{
		if (mbComplete)
			return;

		mTime += Time::DeltaTime();
		if (mSpriteSheet[mSpriteIndex].duration < mTime)
		{
			mTime = 0.0f;
			if (mSpriteSheet.size() <= mSpriteIndex + 1)
				mbComplete = true;
			else
				mSpriteIndex++;
		}
	}

	void Animation::Render(HDC hdc)
	{
		GameObject* gameObj = mAnimator->GetOwner();
		Vector2 pos = gameObj->GetPos();

		

		if (mAffectedCamera)
			pos = Camera::CalculatePos(pos);


		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 255; // 0 - 225

		pos += mSpriteSheet[mSpriteIndex].offset;

		AlphaBlend(hdc
			, int(pos.x - mSpriteSheet[mSpriteIndex].size.x / 2.0f)
			, int(pos.y - mSpriteSheet[mSpriteIndex].size.y / 2.0f)
			, int(mSpriteSheet[mSpriteIndex].size.x * 2.5f)// animation object scale 
			, int(mSpriteSheet[mSpriteIndex].size.y * 2.5f)
			, mImage->GetDC()
			, int(mSpriteSheet[mSpriteIndex].leftTop.x)
			, int(mSpriteSheet[mSpriteIndex].leftTop.y)
			, int(mSpriteSheet[mSpriteIndex].size.x)
			, int(mSpriteSheet[mSpriteIndex].size.y)
			, func);

	}

	void Animation::Create(Image* image, Vector2 leftTop, Vector2 size, Vector2 offset
		, UINT spriteLegth, float duration, bool bAffectedCamera)
	{
		mImage = image;
		mAffectedCamera = bAffectedCamera;

		for (size_t i = 0; i < spriteLegth; i++)
		{
			Sprite sprite;
			sprite.leftTop.x = leftTop.x + (size.x * (float)i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			
			sprite.offset = offset;
			sprite.duration = duration;

			mSpriteSheet.push_back(sprite);
		}
	}

	void Animation::Reset()
	{
		mSpriteIndex = 0;
		mTime = 0.0f;
		mbComplete = false;
	}
}