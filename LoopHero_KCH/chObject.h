#pragma once
#include "chScene.h"
#include "chGameObject.h"
#include "chSceneManager.h"

namespace ch
{
	namespace object
	{
		template <typename T>
		static __forceinline T* Instantiate(eColliderLayer type)
		{
			T* gameObject = new T();
			Scene* scene = SceneManager::GetPlayScene();
			scene->AddGameObject(dynamic_cast<GameObject*>(gameObject), type);

			return gameObject;
		}

		template <typename T>
		static __forceinline T* Instantiate(Vector2 position, eColliderLayer type)
		{
			T* gameObject = new T(position);
			Scene* scene = SceneManager::GetPlayScene();
			scene->AddGameObject(dynamic_cast<GameObject*>(gameObject), type);

			return gameObject;
		}

		static __forceinline void Destroy(GameObject* gameObj)
		{
			gameObj->Death();
		}

		// 시간 측정해서 지우기
		static __forceinline void Destroy(GameObject* gameObj, float deathTime)
		{
			gameObj->SetDeathTime(deathTime);
		}

		static __forceinline void Release()
		{
			Scene* scene = SceneManager::GetPlayScene();
			std::vector<std::vector<GameObject*>> objects = scene->GetGameObjects();

			for (size_t y = 0; y < _COLLIDER_LAYER; y++)
			{
				for (std::vector<GameObject*>::iterator iter = objects[y].begin()
					; iter != objects[y].end();)
				{
					if ((*iter)->IsDeath() == true)
					{
						iter = objects[y].erase(iter);
						continue;
					}
					++iter;
				}
			}
		}

	}
}