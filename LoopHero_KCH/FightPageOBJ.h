#pragma once
#include "chGameObject.h"
#include "chUiBase.h"
#include "chScene.h"
namespace ch
{
	class Image;
	class Monsters;
	class LoopWarrior;
	class FigjtPageTimeAni;
	class FightPageOBJ : public GameObject
	{
	public:
		FightPageOBJ(int y,int x);
		FightPageOBJ(eUIType type);
		~FightPageOBJ();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void SetImage(const std::wstring& key, const std::wstring& fileName);
		
		static void objDeath();
		
	public: //몬스터 전투 관련
		Vector2 enemyPos[6];
		Vector2 playerPos;

		//LoopWarrior *player;
		static Monsters *enemys[6];
		//static Monsters *Testenemy;
		static LoopWarrior *Testplayer;
		static FigjtPageTimeAni *FightPageAniObj;
		static int fightPageMonsterCount;
	


		void FightStarts();//전투 시작시 플레이어 위치와 몬스터 위치 
		void prevFightCheck();//전투 시작전 해당 위치의 적의 갯수와 적의 타입 구별
		
	private:
		float mSpeed;
		Image* mImage;
		int tileYpos;
		int tileXpos;
		//int alpha;
	};
}
