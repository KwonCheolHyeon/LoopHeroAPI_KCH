#pragma once
#include "chEntity.h"


namespace ch {

	class Image;
	class UiBase : public Entity
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}

			void operator()()
			{
				if (mEvent)
					mEvent();
			}

			std::function<void()> mEvent;
		};


		UiBase(eUIType type);
		virtual ~UiBase();

		/// <summary>
		/// UI �� �ε� �Ǿ����� �Ҹ��� �ʱ�ȭ �Լ�
		/// </summary>
		void Initialize();
		/// <summary>
		/// UI �� Ȱ��ȭ�Ǹ� �Ҹ��� �Լ�
		/// </summary>
		void Active();
		/// <summary>
		/// UI �� ��Ȱ��ȭ�Ǹ� �Ҹ��� �Լ�
		/// </summary>
		void InActive();

		/// <summary>
		/// UI�� ������Ʈ �ɶ����� ȣ��Ǵ� �Լ�
		/// </summary>
		void Tick();
		void Render(HDC hdc);

		/// <summary>
		/// UI�� ������� ȣ��Ǵ� �Լ�
		/// </summary>
		void UIClear();

		void ImageLoad(const std::wstring& key, const std::wstring& path);
		void AddChild(UiBase* uiBase);

		eUIType GetType() { return mType; }
		bool GetIsFullScreen() { return mbFullScreen; }
		void SetIsFullScreen(bool enable) { mbFullScreen = enable; }
		void SetParent(UiBase* parent) { mParent = parent; }
		void SetPos(Vector2 pos) { mPos = pos; }
		Vector2 GetPos() { return mPos; }
		void SetSize(Vector2 size) { mSize = size; }
		Vector2 GetSize() { return mSize; }

	protected:
		UiBase* mParent;
		Image* mImage;
		Vector2 mPos;
		Vector2 mSize;
		Vector2 mScreenPos;

	private:
		virtual void OnInit() {};
		virtual void OnActive() {};
		virtual void OnInActive() {};
		virtual void OnTick() {};
		virtual void OnRender(HDC hdc) {};
		virtual void OnClear() {};

	private:
		std::vector<UiBase*> mChilds;

		eUIType mType;
		bool mbFullScreen;
		bool mbEnable;

	};
}