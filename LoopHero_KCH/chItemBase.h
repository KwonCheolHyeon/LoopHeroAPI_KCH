#pragma once

namespace ch 
{
		struct wBasicSword //일반
		{
			//무기
			int	wMinAttack= 4;
			int wMaxAttack = 6;

			//갑옷
			int aHP = 90;


			//방패
			int sDef = 4;


			//반지
			int rDef = 5; //고정

			
		};

		struct wVampireSword //피흡  4%         /빼기
		{

			//무기
			int	wMinAttack = 4;
			int wMaxAttack = 6;

			//갑옷
			int aHP = 90;


			//방패
			int sDef = 4;


			//반지
			int rDef = 5; //고정

			int eVampire = 4;
		};

		struct wAllDamageSword //전체 적 타격 절반  2뎀     /빼고
		{

			//무기
			int	wMinAttack = 4;
			int wMaxAttack = 6;

			//갑옷
			int aHP = 90;


			//방패
			int sDef = 4;


			//반지
			int rDef = 5; //고정

			int eAlldamage = 2;
		};

		struct wDefense // 방어   5단위
		{

			//무기
			int	wMinAttack = 4;
			int wMaxAttack = 6;

			//갑옷
			int aHP = 90;


			//방패
			int sDef = 4;


			//반지
			int rDef = 5; //고정

			int eDefense = 5;
		};

		struct wCounter // 카운터   5%단위
		{
			//무기
			int	wMinAttack = 4;
			int wMaxAttack = 6;

			//갑옷
			int aHP = 90;


			//방패
			int sDef = 4;


			//반지
			int rDef = 5; //고정

			int eCounter = 5;
		};

		struct wAttSpeed // 공격속도 4%단위
		{
			//무기
			int	wMinAttack = 4;
			int wMaxAttack = 6;
			

			//갑옷
			int aHP = 90;


			//방패
			int sDef = 4;


			//반지
			int rDef = 5; //고정


			int eAttSpeed = 4;

		};

		struct wEvade // 회피율    3%단위
		{

			//무기
			int	wMinAttack = 4;
			int wMaxAttack = 6;
			

			//갑옷
			int aHP = 90;
			

			//방패
			int sDef = 4;
		

			//반지
			int rDef = 5; //고정
			

			int eEvade = 3;

		};
}