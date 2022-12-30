#pragma once
#include "chGameObject.h"
#include "chAnimator.h"
#include "TileMapObject.h"
namespace ch
{

	class Image;
	class WarriorMini : public GameObject
	{
	public:
		WarriorMini();
		WarriorMini(Vector2 pos);
		~WarriorMini();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		

	public:
		int loopTIme = 1; ////////현재 루프 UI 에 넣어도 될듯///////
		int gameSpeedCount = 1;
		static int Loop;

	public:
		
		//1.방향 결정 , 2. 지금 내 위치, 3. 이동해야하는 위치
		void moveTo(int dir, Vector2 pos);
		int dirSelect(int pY, int pX);//방향 정하기
		int Pdir;
		int pY;//플레이어 y값
		int pX;//플레이어 x값
		int prevPY;//이전 위치
		int prevPX;//이전 위치


		double distanceOne; // 한칸 거리 한칸 만큼 이동 해야 하기 때문
		double gameSpeed; //움직이는 속도 조절

		Vector2 MapPosCalcOffset(int y, int x);

		std::vector<std::vector<TileMapObject*>>& roadTilesCopy = GameMap::Instance().GetRoadTiles();

		FightPageOBJ* fpg2;
	private:
		
		Image* mImage;
		Animator* mAnimator;
		Vector2 miniOffset ={25.0f,25.0f};
		Vector2 pIndex;//플레이어 현위치
		
	};
}