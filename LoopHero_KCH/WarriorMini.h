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
		int loopTIme = 1; ////////���� ���� UI �� �־ �ɵ�///////
		int gameSpeedCount = 1;
		static int Loop;

	public:
		
		//1.���� ���� , 2. ���� �� ��ġ, 3. �̵��ؾ��ϴ� ��ġ
		void moveTo(int dir, Vector2 pos);
		int dirSelect(int pY, int pX);//���� ���ϱ�
		int Pdir;
		int pY;//�÷��̾� y��
		int pX;//�÷��̾� x��
		int prevPY;//���� ��ġ
		int prevPX;//���� ��ġ


		double distanceOne; // ��ĭ �Ÿ� ��ĭ ��ŭ �̵� �ؾ� �ϱ� ����
		double gameSpeed; //�����̴� �ӵ� ����

		Vector2 MapPosCalcOffset(int y, int x);

		std::vector<std::vector<TileMapObject*>>& roadTilesCopy = GameMap::Instance().GetRoadTiles();

		FightPageOBJ* fpg2;
	private:
		
		Image* mImage;
		Animator* mAnimator;
		Vector2 miniOffset ={25.0f,25.0f};
		Vector2 pIndex;//�÷��̾� ����ġ
		
	};
}