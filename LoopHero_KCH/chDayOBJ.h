#pragma once
#include "chGameObject.h"

namespace ch
{
	class Image;
	class chDayOBJ : public GameObject
	{
	public:
		chDayOBJ();
		~chDayOBJ();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void SetImage(const std::wstring& key, const std::wstring& fileName);
	private:
		Image* mImage;

	};

}