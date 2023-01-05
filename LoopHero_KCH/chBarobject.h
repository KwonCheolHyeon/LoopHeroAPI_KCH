#pragma once
#include "chGameObject.h"
#include "chAnimator.h"

namespace ch
{
	class Animator;
	class Image;
	class Barobject : public GameObject
	{
	public:
		Barobject(int type);
		~Barobject();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void SetImage(const std::wstring& key, const std::wstring& fileName);

	private:
		Image* mImage;
		
		int types;

	private:
		HWND m_hwnd;
		BLENDFUNCTION m_Blend;
		int m_Alpha;

	};
}