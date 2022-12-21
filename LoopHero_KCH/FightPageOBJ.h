#pragma once
#include "chGameObject.h"

namespace ch
{
	class Image;
	class FightPageOBJ : public GameObject
	{
	public:
		FightPageOBJ(int y,int x);
		~FightPageOBJ();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void SetImage(const std::wstring& key, const std::wstring& fileName);

	public: //���� ���� ����
		Vector2 enemyPos[6];
		Vector2 playerPos;

		GameObject enemyType[6];
		GameObject player;

		void FightStarts();//���� ���۽� �÷��̾� ��ġ�� ���� ��ġ 

	private:
		float mSpeed;
		Image* mImage;
		int tileYpos;
		int tileXpos;
		//int alpha;
	};
}
