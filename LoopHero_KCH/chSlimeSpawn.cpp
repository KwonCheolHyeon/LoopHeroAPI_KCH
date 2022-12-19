#include "chSlimeSpawn.h"
#include "chObject.h"
#include "chSlimeMinIcon.h"

namespace ch 
{
	SlimeSpawn::SlimeSpawn()
	{
		
	}

	SlimeSpawn::~SlimeSpawn()
	{
	}

	void SlimeSpawn::Initialize()
	{
	}

	void SlimeSpawn::Tick()
	{
	}

	void SlimeSpawn::Render(HDC hdc)
	{
	}

	void SlimeSpawn::slimeSpawn()
	{

		

	}

	Vector2 SlimeSpawn::MapPosCalc(int y, int x)
	{
		Vector2 indexPos(x, y);
		indexPos.x = x * (TILE_SIZE * TILE_SCALE);
		indexPos.y = y * (TILE_SIZE * TILE_SCALE);
		indexPos.y += (TILE_SIZE * TILE_SCALE);

		Vector2 objectPos = indexPos;

		return objectPos;
	}
}