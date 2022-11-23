#include "chAnimator.h"
#include "chGameObject.h"
#include "chImage.h"
#include "chCamera.h"
#include "chResources.h"

namespace ch
{
	Animator::Animator()
		: Component(eComponentType::Aimator)
		, mPlayAnimaion(nullptr)
		, mbLoop(false)
	{
		//mImage = Resources::Load<Image>(L"Player", L"..\\Resources\\Image\\Player.bmp");
	}

	Animator::~Animator()
	{
		//std::map<std::wstring, Animation*> mAnimations;
		for (auto iter : mAnimations)
		{
			delete iter.second;
		}

		//std::map<std::wstring, Events*> mEvents;
		for (auto iter : mEvents)
		{
			delete iter.second;
		}
	}

	void Animator::Tick()
	{
		if (mPlayAnimaion != nullptr)
		{
			mPlayAnimaion->Tick();

			if (mbLoop && mPlayAnimaion->isComplete())
			{
				Animator::Events* events
					= FindEvents(mPlayAnimaion->GetName());
				if (events != nullptr)
					events->mCompleteEvent();

				mPlayAnimaion->Reset();
			}
		}
	}

	void Animator::Render(HDC hdc)
	{
		if (mPlayAnimaion != nullptr)
		{
			mPlayAnimaion->Render(hdc);
		}


		//BLENDFUNCTION func = {};
		//func.BlendOp = AC_SRC_OVER;
		//func.BlendFlags = 0;
		//func.AlphaFormat = AC_SRC_ALPHA;
		//func.SourceConstantAlpha = 255; // 0 - 225

		//AlphaBlend(hdc
		//	, 0
		//	, 0
		//	, mSPriteSheet->GetWidth()
		//	, mSPriteSheet->GetHeight()
		//	, mSPriteSheet->GetDC()
		//	, 0
		//	, 0
		//	, mSPriteSheet->GetWidth()
		//	, mSPriteSheet->GetHeight()
		//	, func);
	}

	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		std::map<std::wstring, Animation*>::iterator iter = mAnimations.find(name);
		if (iter == mAnimations.end())
			return nullptr;

		return iter->second;
	}

	void Animator::CreateAnimation(const std::wstring& name, Image* image
		, Vector2 leftTop, Vector2 size, Vector2 offset
		, UINT spriteLegth, float duration, bool bAffectedCamera)
	{
		Animation* animation = FindAnimation(name);
		if (animation != nullptr)
		{
			MessageBox(nullptr, L"중복 키 애니메이션 생성", L"애니메이션 생성 실패!", MB_OK);
			return;
		}

		animation = new Animation();
		animation->Create(image, leftTop, size, offset, spriteLegth, duration, bAffectedCamera);

		animation->SetName(name);
		animation->SetAnimator(this);

		mAnimations.insert(std::make_pair(name, animation));

		Events* events = new Events();
		mEvents.insert(std::make_pair(name, events));
	}

	void Animator::CreateAnimations(const std::wstring& path
		, const std::wstring& name
		, Vector2 offset
		, float duration)
	{
		UINT width = 0;
		UINT height = 0;
		UINT fileCount = 0;

		std::filesystem::path fs(path);
		std::vector<Image*> images;
		for (auto& p : std::filesystem::recursive_directory_iterator(path))
		{
			std::wstring fileName = p.path().filename();;
			std::wstring fullName = path + L"\\" + fileName;
			Image* image = Resources::Load<Image>(fileName, fullName);
			images.push_back(image);

			if (width < image->GetWidth())
				width = image->GetWidth();

			if (height < image->GetHeight())
				height = image->GetHeight();

			fileCount++;
		}

		mSPriteSheet = Image::Create(name, width * fileCount, height);
		int index = 0;
		for (Image* image : images)
		{
			BitBlt(mSPriteSheet->GetDC(), width * index, 0, image->GetWidth(), image->GetHeight()
				, image->GetDC(), 0, 0, SRCCOPY);
			index++;
		}

		CreateAnimation(name, mSPriteSheet
			, Vector2(0.0f, 0.0f), Vector2(width, height)
			, offset, fileCount, duration);
	}

	void Animator::Play(const std::wstring& name, bool bLoop)
	{
		Animator::Events* events = FindEvents(name);
		if (events != nullptr)
			events->mStartEvent();

		Animation* prevAnimation = mPlayAnimaion;
		mPlayAnimaion = FindAnimation(name);
		mPlayAnimaion->Reset();
		mbLoop = bLoop;

		if (prevAnimation != mPlayAnimaion)
		{
			if (events != nullptr)
				events->mEndEvent();
		}
	}
	Animator::Events* Animator::FindEvents(const std::wstring key)
	{
		std::map<std::wstring, Events*>::iterator iter = mEvents.find(key);
		if (iter == mEvents.end())
		{
			return nullptr;
		}

		return iter->second;
	}

	std::function<void()>& Animator::GetStartEvent(const std::wstring key)
	{
		Events* events = FindEvents(key);

		return events->mStartEvent.mEvent;
	}

	std::function<void()>& Animator::GetCompleteEvent(const std::wstring key)
	{
		Events* events = FindEvents(key);

		return events->mCompleteEvent.mEvent;
	}

	std::function<void()>& Animator::GetEndEvent(const std::wstring key)
	{
		Events* events = FindEvents(key);

		return events->mEndEvent.mEvent;
	}

}
