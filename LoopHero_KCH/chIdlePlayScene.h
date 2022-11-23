#pragma once
#include "chScene.h"

namespace ch
{
	class chIdlePlayScene : public Scene
	{
	public:
		chIdlePlayScene();
		~chIdlePlayScene();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;

		virtual void Enter();
		virtual void Exit();

	private:

	};

}