#pragma once
#include "chGameObject.h"

namespace ch
{
	class Image;
	class FightPageOBJ : public GameObject
	{
	public:
		FightPageOBJ();
		~FightPageOBJ();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void SetImage(const std::wstring& key, const std::wstring& fileName);

	private:
		float mSpeed;
		Image* mImage;
		//int alpha;
	};
}
