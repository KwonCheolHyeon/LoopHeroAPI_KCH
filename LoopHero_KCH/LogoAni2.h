#pragma once
#include "chGameObject.h"

#include "chAnimator.h"
namespace ch 
{
	class Animator;
	class Image;
	class LogoAni2 : public GameObject
	{
	public:
		LogoAni2();
		~LogoAni2();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void SetImage(const std::wstring& key, const std::wstring& fileName);
		
	private:
		float mSpeed;
		Image* mImage;
		float imageLiveTime;
		//int alpha;



	};
}


