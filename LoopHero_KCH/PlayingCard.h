#pragma once
#include "chGameObject.h"

namespace ch {
	class Image;
	class PlayingCard : public GameObject
	{
	public:
		PlayingCard();
		~PlayingCard();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		void SetBGImage(const std::wstring& key, const std::wstring& fileName);
		void SetCardImage(const std::wstring& key, const std::wstring& fileName);

		
	private:
		Image* mBGImage;
		Image* mCardImage;
		int mTileType;
		int type;
	};
}
