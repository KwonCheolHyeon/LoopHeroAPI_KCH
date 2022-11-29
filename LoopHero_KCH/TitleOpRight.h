#pragma once
#include "chGameObject.h"
#include "chAnimator.h"

namespace ch {
	class Animator;
	class Image;
	class TitleOpRight : public GameObject
	{
	public:
		TitleOpRight();
		~TitleOpRight();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void SetImage(const std::wstring& key, const std::wstring& fileName);

	private:
		float mSpeed;
		Image* mImage;
		float imageLiveTime;
		//int alpha;

	private:
		HWND m_hwnd;
		BLENDFUNCTION m_Blend;
		int m_Alpha;

	};
}