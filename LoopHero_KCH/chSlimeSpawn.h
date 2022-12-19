#pragma once
#include <stdlib.h>
#include "chGameObject.h"

namespace ch 
{
	class SlimeSpawn
	{
		SlimeSpawn();
		~SlimeSpawn();


		virtual void Initialize();
		virtual void Tick() ;
		virtual void Render(HDC hdc) ;

		void slimeSpawn();
		Vector2 MapPosCalc(int y, int x);
	private:
		double SpawnTime;



	};
}


