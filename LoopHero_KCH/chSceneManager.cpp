#include "chSceneManager.h"
#include "chLogoScene.h"
#include "chTitleScene.h"
#include "chPlayScene.h"
#include "chEndScene.h"
#include "chObject.h"
#include "chIdlePlayScene.h"

namespace ch
{
	Scene* SceneManager::mScenes[(UINT)eSceneType::Max] = {};
	Scene* SceneManager::mPlayScene = nullptr;

	void SceneManager::Initialize()
	{

		// �������� �ʱ�ȭ
		
		mScenes[(UINT)eSceneType::Logo] = new LogoScene();
		mScenes[(UINT)eSceneType::Logo]->Initialize();
		
		mScenes[(UINT)eSceneType::Title] = new TitleScene();
		mScenes[(UINT)eSceneType::Title]->Initialize();

		mScenes[(UINT)eSceneType::Play] = new PlayScene();
		mScenes[(UINT)eSceneType::Play]->Initialize();

		mScenes[(UINT)eSceneType::End] = new EndScene();
		mScenes[(UINT)eSceneType::End]->Initialize();

		mScenes[(UINT)eSceneType::IdlePlay] = new chIdlePlayScene();
		mScenes[(UINT)eSceneType::IdlePlay]->Initialize();

		ChangeScene(eSceneType::Play);
		// ��ĳ����
		// �ٿ�ĳ����

		//Scene* t = new LogoScene();
		//t->Initialize();
	}

	void SceneManager::Tick()
	{
		//���� ������ update Tick
		mPlayScene->Tick();
	}

	void SceneManager::Render(HDC hdc)
	{
		//����� ������
		mPlayScene->Render(hdc);
	}

	void SceneManager::DetroyGameObject()
	{
		ch::object::Release();
	}

	void SceneManager::Release()
	{
		// ���α׷� ����ɋ� �ѹ��� ȣ��
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			delete scene;
			scene = nullptr;
		}
	}

	void SceneManager::ChangeScene(eSceneType type)
	{
		if (mScenes[(UINT)type] == nullptr)
			return;

		mPlayScene->Exit();
		mPlayScene = mScenes[(UINT)type];

		mPlayScene->Enter();
	}
}