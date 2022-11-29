#pragma once
#include "chGameObject.h"

namespace ch
{

class Image;
class Vampire_Mansion : public GameObject
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

