#pragma once

namespace ch 
{
		struct wBasicSword //�Ϲ�
		{
			//����
			int	wMinAttack= 4;
			int wMaxAttack = 6;

			//����
			int aHP = 90;


			//����
			int sDef = 4;


			//����
			int rDef = 5; //����

			
		};

		struct wVampireSword //����  4%         /����
		{

			//����
			int	wMinAttack = 4;
			int wMaxAttack = 6;

			//����
			int aHP = 90;


			//����
			int sDef = 4;


			//����
			int rDef = 5; //����

			int eVampire = 4;
		};

		struct wAllDamageSword //��ü �� Ÿ�� ����  2��     /����
		{

			//����
			int	wMinAttack = 4;
			int wMaxAttack = 6;

			//����
			int aHP = 90;


			//����
			int sDef = 4;


			//����
			int rDef = 5; //����

			int eAlldamage = 2;
		};

		struct wDefense // ���   5����
		{

			//����
			int	wMinAttack = 4;
			int wMaxAttack = 6;

			//����
			int aHP = 90;


			//����
			int sDef = 4;


			//����
			int rDef = 5; //����

			int eDefense = 5;
		};

		struct wCounter // ī����   5%����
		{
			//����
			int	wMinAttack = 4;
			int wMaxAttack = 6;

			//����
			int aHP = 90;


			//����
			int sDef = 4;


			//����
			int rDef = 5; //����

			int eCounter = 5;
		};

		struct wAttSpeed // ���ݼӵ� 4%����
		{
			//����
			int	wMinAttack = 4;
			int wMaxAttack = 6;
			

			//����
			int aHP = 90;


			//����
			int sDef = 4;


			//����
			int rDef = 5; //����


			int eAttSpeed = 4;

		};

		struct wEvade // ȸ����    3%����
		{

			//����
			int	wMinAttack = 4;
			int wMaxAttack = 6;
			

			//����
			int aHP = 90;
			

			//����
			int sDef = 4;
		

			//����
			int rDef = 5; //����
			

			int eEvade = 3;

		};
}