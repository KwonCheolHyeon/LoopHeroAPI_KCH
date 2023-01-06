#include "chItemBG.h"
#include "chResources.h"
#include "chImage.h"
#include "chCollider.h"
#include "chInput.h"
#include "chItemBase.h"
#include "chCollisionManager.h"
#include "chMouseObject.h"
#include "GameMap.h"
#include "WarriorMini.h"
#include "chSound.h"
#include "chSoundManager.h"

namespace ch
{
	ItemBG::ItemBG(int rank, int item, int itemtype)
		: mBGImage(nullptr)
		, mItemImage(nullptr)
	{


		bagPos[0][0] = { 1335,325 };
		bagPos[0][1] = { 1400,325 };
		bagPos[0][2] = { 1465,325 };
		bagPos[0][3] = { 1525,325 };
		bagPos[1][0] = { 1335,388 };
		bagPos[1][1] = { 1400,388 };
		bagPos[1][2] = { 1465,388 };
		bagPos[1][3] = { 1525,388 };
		bagPos[2][0] = { 1335,450 };
		bagPos[2][1] = { 1400,450 };
		bagPos[2][2] = { 1465,450 };
		bagPos[2][3] = { 1525,450 };
		//���â ���� ������ ��ġ
		equipPos[0] = { 1327,67 };
		equipPos[1] = { 1327,137 };
		equipPos[2] = { 1327,200 };
		equipPos[3] = { 1395,200 };

		iRank = rank;
		items = item;
		iItemType = itemtype;
		setRank();
		itembagCheck();

		equipItem = Resources::Load<Sound>(L"equipItem", L"..\\Resources\\sound\\effect\\snd_equip_item.wav");

		Collider* collider = new Collider();
		AddComponent(collider);
		collider->SetOffset(Vector2(25, 25));
		collider->SetScale(Vector2(50, 50));

	
		
	}

	ItemBG* ItemBG::bagChecks[3][4];// 
	ItemBG* ItemBG::equipCheck[];// 

	ItemBG::~ItemBG()
	{

	}

	void ItemBG::Initialize()
	{


	}

	void ItemBG::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}

	void ItemBG::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();
		Vector2 finalPos = pos;

		Vector2 rect;
		rect.x = mBGImage->GetWidth() * scale.x;
		rect.y = mBGImage->GetHeight() * scale.y;

		Vector2 rectCard;
		rectCard.x = mItemImage->GetWidth() * 2.5f;
		rectCard.y = mItemImage->GetHeight() * 2.5f;



		TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y
			, mBGImage->GetDC(), 0, 0, mBGImage->GetWidth(), mBGImage->GetHeight()
			, RGB(255, 0, 255));

		TransparentBlt(hdc, finalPos.x, finalPos.y, rectCard.x, rectCard.y
			, mItemImage->GetDC(), 0, 0, mItemImage->GetWidth(), mItemImage->GetHeight()
			, RGB(255, 0, 255));

		GameObject::Render(hdc);
	}

	void ItemBG::OnCollisionEnter(Collider* other)
	{

	}

	void ItemBG::OnCollisionStay(Collider* other)
	{
		if (KEY_DOWN(eKeyCode::LBTN))
		{
			int it = this->Getitems();

			if (it == 0) //��
			{
				if (equipCheck[0] != nullptr)
				{
					equipCheck[0]->Death();
					equipCheck[0] = nullptr;
				}
				this->chWepMaxATTs = chNormal.wMaxAttack;
				this->chWepMinATTs = chNormal.wMinAttack;
				this->chHps = chNormal.aHP;
				this->chDefs = chNormal.rDef + chNormal.sDef + chDefend.eDefense;
				this->cHCounters = chCounter.eCounter;
				this->chWepSpeeds = chAttSpeed.eAttSpeed;
				this->chEvades = chEvade.eEvade;
				equipItem->Play(false);
				this->SetPos(equipPos[0]);
				equipCheck[0] = this;
			}
			else if (it == 1) // ����
			{
				if (equipCheck[1] != nullptr)
				{
					equipCheck[1]->Death();
					equipCheck[1] = nullptr;
				}
				this->chWepMaxATTs = chNormal.wMaxAttack;
				this->chWepMinATTs = chNormal.wMinAttack;
				this->chHps = chNormal.aHP;
				this->chDefs = chNormal.rDef + chNormal.sDef + chDefend.eDefense;
				this->cHCounters = chCounter.eCounter;
				this->chWepSpeeds = chAttSpeed.eAttSpeed;
				this->chEvades = chEvade.eEvade;
				equipItem->Play(false);
				this->SetPos(equipPos[1]);
				equipCheck[1] = this;
				
			}
			else if (it == 2) // ����
			{
				if (equipCheck[2] != nullptr)
				{
					equipCheck[2]->Death();
					equipCheck[2] = nullptr;
				}
				this->chWepMaxATTs = chNormal.wMaxAttack;
				this->chWepMinATTs = chNormal.wMinAttack;
				this->chHps = chNormal.aHP;
				this->chDefs = chNormal.rDef + chNormal.sDef + chDefend.eDefense;
				this->cHCounters = chCounter.eCounter;
				this->chWepSpeeds = chAttSpeed.eAttSpeed;
				this->chEvades = chEvade.eEvade;
				equipItem->Play(false);
				this->SetPos(equipPos[2]);
				equipCheck[2] = this;
				
			}
			else if (it == 3) // ����
			{
				if (equipCheck[3] != nullptr)
				{
					equipCheck[3]->Death();
					equipCheck[3] = nullptr;
				}
				this->chWepMaxATTs = chNormal.wMaxAttack;
				this->chWepMinATTs = chNormal.wMinAttack;
				this->chHps = chNormal.aHP;
				this->chDefs = chNormal.rDef + chNormal.sDef + chDefend.eDefense;
				this->cHCounters = chCounter.eCounter;
				this->chWepSpeeds = chAttSpeed.eAttSpeed;
				this->chEvades = chEvade.eEvade;
				equipItem->Play(false);
				this->SetPos(equipPos[3]);
				equipCheck[3] = this;
				WarriorMini::miniHP = equipCheck[3]->chHps + WarriorMini::miniNowHp;
			}


			removeBag();
			
		}
	}

	void ItemBG::OnCollisionExit(Collider* other)
	{
	}

	void ItemBG::SetBGImage(const std::wstring& key, const std::wstring& fileName)
	{
		std::wstring path = L"..\\Resources\\loophero\\Equipment\\itemBG\\itemEffect\\";
		path += fileName;

		mBGImage = Resources::Load<Image>(key, path);
	}

	void ItemBG::SetItemImage(const std::wstring& key, const std::wstring& fileName)
	{
		std::wstring path = L"..\\Resources\\loophero\\Equipment\\EquipMent\\all\\";
		path += fileName;

		mItemImage = Resources::Load<Image>(key, path);
	}

	/*
	void ItemBG::setItemBG(int rank, int item, int itemtype)
	{
		iRank = rank;
		items = item;
		iItemType = itemtype;

		setRank();
		itembagCheck();

		Collider* collider = new Collider();
		AddComponent(collider);

	}*/

	void ItemBG::setRank()
	{
		if (iRank == 0) // �Ϲ�
		{
			this->SetBGImage(L"normal", L"items_bg_0.bmp");

		}
		else if (iRank == 1)  // ���
		{
			this->SetBGImage(L"rare", L"items_bg_1.bmp");

		}
		else if (iRank == 2)  //���� 
		{
			this->SetBGImage(L"Hero", L"items_bg_2.bmp");

		}
		else if (iRank == 3)  // ����
		{
			this->SetBGImage(L"Legend", L"items_bg_3.bmp");

		}
		this->SetScale(Vector2(2.5, 2.5));
		setItem();
	}

	void ItemBG::setItem()
	{
		if (items == 0) // ��
		{
			if (iItemType == 0) // �Ϲ�
			{
				this->SetItemImage(L"wbasic", L"weapons_0.bmp");
			}
			else if (iItemType == 1) // ����
			{
				this->SetItemImage(L"wdefend", L"weapons_10.bmp");
			}
			else if (iItemType == 2) // ī����
			{
				this->SetItemImage(L"wcounter", L"weapons_6.bmp");
			}
			else if (iItemType == 3) // ���ݼӵ�
			{
				this->SetItemImage(L"wspeed", L"weapons_9.bmp");
			}
			else if (iItemType == 4) // ȸ����
			{
				this->SetItemImage(L"wevade", L"weapons_4.bmp");
			}
		}
		else if (items == 1) // ����
		{
			if (iItemType == 0) // �Ϲ�
			{
				this->SetItemImage(L"rbasic", L"rings_3.bmp");

			}
			else if (iItemType == 1) // ����
			{
				this->SetItemImage(L"rdefend", L"rings_6.bmp");

			}
			else if (iItemType == 2) // ī����
			{
				this->SetItemImage(L"rcounter", L"rings_4.bmp");
			}
			else if (iItemType == 3) // ���ݼӵ�
			{
				this->SetItemImage(L"rspeed", L"rings_8.bmp");
			}
			else if (iItemType == 4) // ȸ����
			{
				this->SetItemImage(L"revade", L"rings_7.bmp");
			}

		}
		else if (items == 2) // ����
		{
			if (iItemType == 0) // �Ϲ�
			{
				this->SetItemImage(L"sbasic", L"shilds_1.bmp");
			}
			else if (iItemType == 1) // ����
			{
				this->SetItemImage(L"sdefend", L"shilds_6.bmp");
			}
			else if (iItemType == 2) // ī����
			{
				this->SetItemImage(L"scounter", L"shilds_3.bmp");
			}
			else if (iItemType == 3) // ���ݼӵ�
			{
				this->SetItemImage(L"sspeed", L"shilds_8.bmp");
			}
			else if (iItemType == 4) // ȸ����
			{
				this->SetItemImage(L"sevade", L"shilds_5.bmp");
			}
		}
		else if (items == 3) // ����
		{
			if (iItemType == 0) // �Ϲ�
			{
				this->SetItemImage(L"abasic", L"kiraski_0.bmp");
			}
			else if (iItemType == 1) // ����
			{
				this->SetItemImage(L"adefend", L"kiraski_6.bmp");
			}
			else if (iItemType == 2) // ī����
			{
				this->SetItemImage(L"acounter", L"kiraski_5.bmp");
			}
			else if (iItemType == 3) // ���ݼӵ�
			{
				this->SetItemImage(L"aspeed", L"kiraski_3.bmp");
			}
			else if (iItemType == 4) // ȸ����
			{
				this->SetItemImage(L"aevade", L"kiraski_9.bmp");
			}
		}
		this->itemStatCheck();
	}

	void ItemBG::itembagCheck()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (bagChecks[i][j] == nullptr)
				{
					this->SetPos(bagPos[i][j]);
					bagChecks[i][j] = this;
					int a = 0;
					return;
				}

			}

		}

	}

	void ItemBG::removeBag()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (this == bagChecks[i][j])
				{
					bagChecks[i][j] = nullptr;
					return;
				}
			}
		}
	}

	bool ItemBG::fullItemCheck()
	{
		int count = 0;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{

				if (bagChecks[i][j] != nullptr)
				{
					count++;


				}

				if (count >= 13)
				{
					return false;
				}
				else if (count <= 12)
				{
					return true;
				}
			}
		}
	}

	void ItemBG::itemStatCheck()
	{
		chNormal.wMaxAttack = 0;
		chNormal.wMinAttack = 0;
		chDefend.eDefense = 0;
		chCounter.eCounter = 0;
		chAttSpeed.eAttSpeed = 0;
		chEvade.eEvade = 0;

		if (iRank == 0) // �Ϲݵ���� �� �⺻ ����
		{
			if (items == 0) // ��
			{
				chNormal.wMaxAttack = 6;
				chNormal.wMinAttack = 4;

			}
			else if (items == 1) // ����
			{
				chNormal.rDef = 5;
			}
			else if (items == 2) // ����
			{
				chNormal.sDef = 4;
			}
			else if (items == 3) // ����
			{
				chNormal.aHP = 90;
			}
		}
		else if (iRank == 1)  // ��͵��
		{
			if (items == 0) // ��
			{
				chNormal.wMaxAttack = 6;
				chNormal.wMinAttack = 4;

				if (iItemType == 0) // �Ϲ�
				{

				}
				else if (iItemType == 1) // ����
				{
					chDefend.eDefense = 5;
				}
				else if (iItemType == 2) // ī����
				{
					chCounter.eCounter = 5;
				}
				else if (iItemType == 3) // ���ݼӵ�
				{
					chAttSpeed.eAttSpeed = 4;
				}
				else if (iItemType == 4) // ȸ����
				{
					chEvade.eEvade = 3;
				}
			}
			else if (items == 1) // ����
			{
				chNormal.rDef = 5;
				if (iItemType == 0) // �Ϲ�
				{

				}
				else if (iItemType == 1) // ����
				{
					chDefend.eDefense = 5;
				}
				else if (iItemType == 2) // ī����
				{
					chCounter.eCounter = 5;
				}
				else if (iItemType == 3) // ���ݼӵ�
				{
					chAttSpeed.eAttSpeed = 4;
				}
				else if (iItemType == 4) // ȸ����
				{
					chEvade.eEvade = 3;
				}
			}
			else if (items == 2) // ����
			{
				chNormal.sDef = 4;
				if (iItemType == 0) // �Ϲ�
				{

				}
				else if (iItemType == 1) // ����
				{
					chDefend.eDefense = 5;
				}
				else if (iItemType == 2) // ī����
				{
					chCounter.eCounter = 5;
				}
				else if (iItemType == 3) // ���ݼӵ�
				{
					chAttSpeed.eAttSpeed = 4;
				}
				else if (iItemType == 4) // ȸ����
				{
					chEvade.eEvade = 3;
				}
			}
			else if (items == 3) // ����
			{
				chNormal.aHP = 90;
				if (iItemType == 0) // �Ϲ�
				{

				}
				else if (iItemType == 1) // ����
				{
					chDefend.eDefense = 5;
				}
				else if (iItemType == 2) // ī����
				{
					chCounter.eCounter = 5;
				}
				else if (iItemType == 3) // ���ݼӵ�
				{
					chAttSpeed.eAttSpeed = 4;
				}
				else if (iItemType == 4) // ȸ����
				{
					chEvade.eEvade = 3;
				}
			}

		}
		else if (iRank == 2)  //���� ���
		{
			if (items == 0) // ��
			{
				chNormal.wMaxAttack = 6;
				chNormal.wMinAttack = 4;

				if (iItemType == 0) // �Ϲ�
				{

				}
				else if (iItemType == 1) // ����
				{
					chDefend.eDefense = 5 * 2;
				}
				else if (iItemType == 2) // ī����
				{
					chCounter.eCounter = 5 * 2;
				}
				else if (iItemType == 3) // ���ݼӵ�
				{
					chAttSpeed.eAttSpeed = 4 * 2;
				}
				else if (iItemType == 4) // ȸ����
				{
					chEvade.eEvade = 3 * 2;
				}
			}
			else if (items == 1) // ����
			{
				chNormal.rDef = 5;
				if (iItemType == 0) // �Ϲ�
				{

				}
				else if (iItemType == 1) // ����
				{
					chDefend.eDefense = 5 * 2;
				}
				else if (iItemType == 2) // ī����
				{
					chCounter.eCounter = 5 * 2;
				}
				else if (iItemType == 3) // ���ݼӵ�
				{
					chAttSpeed.eAttSpeed = 4 * 2;
				}
				else if (iItemType == 4) // ȸ����
				{
					chEvade.eEvade = 3 * 2;
				}
			}
			else if (items == 2) // ����
			{
				chNormal.sDef = 4;
				if (iItemType == 0) // �Ϲ�
				{

				}
				else if (iItemType == 1) // ����
				{
					chDefend.eDefense = 5 * 2;
				}
				else if (iItemType == 2) // ī����
				{
					chCounter.eCounter = 5 * 2;
				}
				else if (iItemType == 3) // ���ݼӵ�
				{
					chAttSpeed.eAttSpeed = 4 * 2;
				}
				else if (iItemType == 4) // ȸ����
				{
					chEvade.eEvade = 3 * 2;
				}
			}
			else if (items == 3) // ����
			{
				chNormal.aHP = 90;
				if (iItemType == 0) // �Ϲ�
				{

				}
				else if (iItemType == 1) // ����
				{
					chDefend.eDefense = 5 * 2;
				}
				else if (iItemType == 2) // ī����
				{
					chCounter.eCounter = 5 * 2;
				}
				else if (iItemType == 3) // ���ݼӵ�
				{
					chAttSpeed.eAttSpeed = 4 * 2;
				}
				else if (iItemType == 4) // ȸ����
				{
					chEvade.eEvade = 3 * 2;
				}
			}

		}
		else if (iRank == 3)  // ���� ���
		{

			if (items == 0) // ��
			{
				chNormal.wMaxAttack = 6;
				chNormal.wMinAttack = 4;

				if (iItemType == 0) // �Ϲ�
				{

				}
				else if (iItemType == 1) // ����
				{
					chDefend.eDefense = 5 * 3;
				}
				else if (iItemType == 2) // ī����
				{
					chCounter.eCounter = 5 * 3;
				}
				else if (iItemType == 3) // ���ݼӵ�
				{
					chAttSpeed.eAttSpeed = 4 * 3;
				}
				else if (iItemType == 4) // ȸ����
				{
					chEvade.eEvade = 3 * 3;
				}
			}
			else if (items == 1) // ����
			{
				chNormal.rDef = 5;
				if (iItemType == 0) // �Ϲ�
				{

				}
				else if (iItemType == 1) // ����
				{
					chDefend.eDefense = 5 * 3;
				}
				else if (iItemType == 2) // ī����
				{
					chCounter.eCounter = 5 * 3;
				}
				else if (iItemType == 3) // ���ݼӵ�
				{
					chAttSpeed.eAttSpeed = 4 * 3;
				}
				else if (iItemType == 4) // ȸ����
				{
					chEvade.eEvade = 3 * 3;
				}
			}
			else if (items == 2) // ����
			{
				chNormal.sDef = 4;
				if (iItemType == 0) // �Ϲ�
				{

				}
				else if (iItemType == 1) // ����
				{
					chDefend.eDefense = 5 * 3;
				}
				else if (iItemType == 2) // ī����
				{
					chCounter.eCounter = 5 * 3;
				}
				else if (iItemType == 3) // ���ݼӵ�
				{
					chAttSpeed.eAttSpeed = 4 * 3;
				}
				else if (iItemType == 4) // ȸ����
				{
					chEvade.eEvade = 3 * 3;
				}
			}
			else if (items == 3) // ����
			{
				chNormal.aHP = 90;
				if (iItemType == 0) // �Ϲ�
				{

				}
				else if (iItemType == 1) // ����
				{
					chDefend.eDefense = 5 * 3;
				}
				else if (iItemType == 2) // ī����
				{
					chCounter.eCounter = 5 * 3;
				}
				else if (iItemType == 3) // ���ݼӵ�
				{
					chAttSpeed.eAttSpeed = 4 * 3;
				}
				else if (iItemType == 4) // ȸ����
				{
					chEvade.eEvade = 3 * 3;
				}
			}

		}
	}
}