#pragma once
#include "chGameObject.h"
namespace ch {

	

	class FightPos
	{
	public:
		
		struct TestPos
		{
			int posX;
			int posY;
			GameObject Player;
			GameObject Monster;

		};

		void FightStart();//전투 시작시 플레이어 위치와 몬스터 위치 

	};
}
