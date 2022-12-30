#pragma once
#include "chGameObject.h"
#include "chAnimator.h"

namespace ch 
{
	class Image;
	class MiniIconStore : public GameObject
	{
	public:
		MiniIconStore(Vector2 pos);
		MiniIconStore(int index, Vector2 pos);
		~MiniIconStore();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		static MiniIconStore* gameObjsStore[11][21][6];
		static void ClearGameObjs(int y,int x);
	private:
		Image* mImage;
		Animator* mAnimator;
		Vector2 miniOffset[6];

		int MonsterSetPos(Vector2 pos);
		Vector2 InMapPosCalc(Vector2 pos);

	};


}