#pragma once
#include "chScene.h"
#include "chCamera.h"

namespace ch
{
	class Monster;
	class LogoScene : public Scene 
	{
	public:
		LogoScene();
		~LogoScene();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;

		virtual void Enter();
		virtual void Exit();

	private:
		Monster* mons[2];
		float nextLogo = 0;
		bool logo2start = true;
		
	};

}


