#include "chLogoScene.h"
#include "chApplication.h"
#include "chImage.h"
#include "chPlayer.h"
#include "chMonster.h"
#include "chInput.h"
#include "chSceneManager.h"
#include "chBgImageObject.h"
#include "chCollisionManager.h"
#include "chObject.h"
#include "LogoObject.h"
#include "chTime.h"
#include "LogoAni2.h"
#include "chCamera.h"
namespace ch
{


	LogoScene::LogoScene()
	{
		LogoObject* logo2 = new LogoObject();
		logo2->SetImage(L"LogoObject2", L"s_intro_logo_0.bmp");
		logo2->Initialize();
		

		AddGameObject(logo2, eColliderLayer::BackGround);
		
		
	}

	LogoScene::~LogoScene()
	{
	}

	void LogoScene::Initialize()
	{
		
		
	

	}

	void LogoScene::Tick()
	{

		Scene::Tick();
		Camera::SetCameraEffect(eCameraEffect::FadeOut);

		nextLogo += Time::DeltaTime();

		
		if (nextLogo >= 5.0f && logo2start) 
		{
			
			Camera::SetCameraEffect(eCameraEffect::FadeIn);

			LogoAni2* logo1 = new LogoAni2();
			logo1->SetImage(L"LogoObject1", L"s_devolver_logo_1.bmp");
			logo1->Initialize();

			AddGameObject(logo1, eColliderLayer::Tile);
			logo2start = false;
		}
		if (nextLogo >= 10.0f)
		{
			SceneManager::ChangeScene(eSceneType::Title);
		}
	}

	void LogoScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		
		


		
	}



	void LogoScene::Enter()
	{
	}
	void LogoScene::Exit()
	{
	}
}