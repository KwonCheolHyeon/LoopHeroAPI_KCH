#pragma once

namespace ch 
{
		struct wBasicSword //�Ϲ�
		{
			//����
			int	wMinAttack= 0;
			int wMaxAttack = 0;

			//����
			int aHP = 0;


			//����
			int sDef =0;


			//����
			int rDef = 0; //����

			
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
			int	wMinAttack = 0;
			int wMaxAttack = 0;

			//����
			int aHP =0;


			//����
			int sDef = 0;


			//����
			int rDef = 0; //����

			int eDefense = 0;
		};
	
		struct wCounter // ī����   5%����
		{
			//����
			int	wMinAttack = 0;
			int wMaxAttack = 0;

			//����
			int aHP = 0;


			//����
			int sDef =0;


			//����
			int rDef =0; //����

			int eCounter = 0;
		};

		struct wAttSpeed // ���ݼӵ� 4%����
		{
			//����
			int	wMinAttack = 0;
			int wMaxAttack = 0;
			

			//����
			int aHP =0;


			//����
			int sDef = 0;


			//����
			int rDef = 0; //����


			int eAttSpeed = 0;

		};

		struct wEvade // ȸ����    3%����
		{

			//����
			int	wMinAttack = 0;
			int wMaxAttack = 0;
			

			//����
			int aHP = 0;
			

			//����
			int sDef = 0;
		

			//����
			int rDef =0; //����
			

			int eEvade = 0;

		};
}