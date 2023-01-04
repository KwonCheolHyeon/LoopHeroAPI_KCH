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
		// ������ ������� �Լ�
		void setRank();//������ ��ũ
		void setItem();//������ Ÿ��
		void itembagCheck();
		bool fullItemCheck();

		Vector2 bagPos[3][4];
		static ItemBG *bagChecks[3][4];// 
		void removeBag();//��ġ �̵������ְ� ���� ������ nulló��

	public: // ���
		Vector2 equipPos[4];
		static ItemBG* equipCheck[4];

	public:
		wBasicSword chNormal;
		wDefense chDefend;
		wCounter chCounter;
		wAttSpeed chAttSpeed;
		wEvade chEvade;
		void itemStatCheck();

	public: // ���� ����
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
