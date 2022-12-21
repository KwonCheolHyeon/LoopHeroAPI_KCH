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

		void FightStarts();//전투 시작시 플레이어 위치와 몬스터 위치 

	};
}
