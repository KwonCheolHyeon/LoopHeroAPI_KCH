#pragma once
#include "chGameObject.h"
#include "chItemBase.h"
namespace ch {
	class Image;
	class ItemBG : public GameObject
	{
	public:
		ItemBG(int rank, int item, int itemtype);
		~ItemBG();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		void SetBGImage(const std::wstring& key, const std::wstring& fileName);
		void SetItemImage(const std::wstring& key, const std::wstring& fileName);

		void Setitems(int item) { items = item; }
		int Getitems() { return items; }		

		
	public:
		// 아이템 가방관련 함수
		void setRank();//아이템 랭크
		void setItem();//아이템 타입
		void itembagCheck();
		bool fullItemCheck();

		Vector2 bagPos[3][4];
		static ItemBG *bagChecks[3][4];// 
		void removeBag();//위치 이동시켜주고 가방 삭제후 null처리

	public: // 장비
		Vector2 equipPos[4];
		static ItemBG* equipCheck[4];

	public:
		wBasicSword chNormal;
		wDefense chDefend;
		wCounter chCounter;
		wAttSpeed chAttSpeed;
		wEvade chEvade;
		void itemStatCheck();

	public: // 무기 스텟
		int chWepMaxATTs;
		int chWepMinATTs;
		int chDefs;
		int chHps;
		int cHCounters;
		int chWepSpeeds;
		int chEvades;
	private:
		Image* mBGImage;
		Image* mItemImage;
		
	private:
		int iRank;
		int items;
		int iItemType;
	};
}
