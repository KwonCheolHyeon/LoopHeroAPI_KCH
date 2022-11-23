#pragma once
#include "chScene.h"

namespace ch
{
	class EndScene : public Scene
	{
	public:
		EndScene();
		~EndScene();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;

		virtual void Enter();
		virtual void Exit();

	private:

	};

}
