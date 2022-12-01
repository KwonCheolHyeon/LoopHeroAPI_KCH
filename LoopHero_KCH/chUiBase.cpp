#include "chUiBase.h"
#include "chResources.h"
#include "chImage.h"

namespace ch {
	UiBase::UiBase(eUIType type)
		: mType(type)
		, mbFullScreen(false)
		, mbEnable(false)
		, mParent(nullptr)
		, mPos(Vector2::Zero)
		, mSize(Vector2::Zero)
	{
	}

	UiBase::~UiBase()
	{
	}

	void UiBase::Initialize()
	{
		OnInit();

		for (UiBase* child : mChilds)
		{
			child->OnInit();
		}
	}

	void UiBase::Active()
	{
		mbEnable = true;
		OnActive();

		for (UiBase* child : mChilds)
		{
			child->mbEnable = true;
			child->OnActive();
		}
	}

	void UiBase::InActive()
	{
		for (UiBase* child : mChilds)
		{
			child->OnInActive();
			child->mbEnable = false;
		}
		OnInActive();
		mbEnable = false;
	}

	void UiBase::Tick()
	{
		if (mbEnable == false)
			return;

		OnTick();
		if (mParent)
			mScreenPos = mParent->GetPos() + mPos;
		else
			mScreenPos = mPos;


		for (UiBase* child : mChilds)
		{
			if (child->mbEnable)
				child->Tick();
		}
	}

	void UiBase::Render(HDC hdc)
	{
		if (mbEnable == false)
			return;

		OnRender(hdc);
		for (UiBase* child : mChilds)
		{
			if (child->mbEnable)
				child->OnRender(hdc);
		}
	}

	void UiBase::UIClear()
	{
		for (UiBase* child : mChilds)
		{
			child->OnClear();
		}
		OnClear();
	}

	void UiBase::ImageLoad(const std::wstring& key, const std::wstring& path)
	{
		mImage = Resources::Load<Image>(key, path);

		SetSize(Vector2(mImage->GetWidth(), mImage->GetHeight()));
	}

	void UiBase::AddChild(UiBase* uiBase)
	{
		mChilds.push_back(uiBase);
		uiBase->mParent = this;
	}
}