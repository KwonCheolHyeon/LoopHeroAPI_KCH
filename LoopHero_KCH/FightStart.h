#pragma once
#include "chGameObject.h"
namespace ch {

	class FightStart

	{
	public:
		FightStart();

		Vector2 enemyPos[6];
		Vector2 playerPos;

		GameObject enemyType[6];
		GameObject player;

		void FightStarts();//���� ���۽� �÷��̾� ��ġ�� ���� ��ġ 

	};
}
