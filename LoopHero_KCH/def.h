#pragma once
#define KEY_PREESE(KEY) ch::Input::GetKeyState(KEY) == ch::eKeyState::PRESSED
#define KEY_DOWN(KEY) ch::Input::GetKeyState(KEY) == ch::eKeyState::DOWN
#define KEY_UP(KEY) ch::Input::GetKeyState(KEY) == ch::eKeyState::UP

enum class eSceneType
{
	Logo,
	Title,
	Play,
	IdlePlay,
	End,
	Tool,
	Max,
};

enum class ePenColor
{
	Red,
	Green,
	Blue,
	End,
};

enum class eBrushColor
{
	Transparent, //≈ı∏Ì
	Black,
	Gray, //167 0 67
	White,
	End,
};

enum class eComponentType
{
	Aimator,
	Collider,
	Sound,
	End,
};

#define _COLLIDER_LAYER 16
enum class eColliderLayer
{
	Default,
	Greed,
	BackGround,
	Tile,
	Card,
	Player,
	Player_Projecttile,
	Monster,
	Monster_Projecttile,
	Warrior,

	BackPack,
	Mouse,
	UI = _COLLIDER_LAYER - 1,
	End = _COLLIDER_LAYER,
};

enum class eCameraEffect
{
	FadeIn,
	FadeOut,
	None,
};

enum class eUIType
{
	HP,
	MP,
	SHOP,
	INVENTORY,
	OPTION,


	END,
};

union ColliderID
{
	struct
	{
		UINT32 left;
		UINT32 right;
	};

	UINT64 ID;
};



#define TILE_SIZE 25
#define TILE_SCALE 2.5f

#define TILE_LINE_X 8
#define TILE_LINE_Y 3

