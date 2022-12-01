#pragma once
#include "TileMapObject.h"

namespace ch
{

class Image;
class Vampire_Mansion : public TileMapObject
{
public:
	Vampire_Mansion();
	Vampire_Mansion(Vector2 pos);
	~Vampire_Mansion();

	virtual void Initialize() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

private:
	Image* mImage;
	


};
}

