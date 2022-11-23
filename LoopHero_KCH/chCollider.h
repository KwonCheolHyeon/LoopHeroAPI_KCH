#pragma once
#include "chComponent.h"

namespace ch
{
	class Collider : public Component
	{
	public:
		Collider();
		~Collider();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		void SetScale(Vector2 scale) { mScale = scale; }
		void SetPos(Vector2 pos) { mPos = pos; }
		void SetOffset(Vector2 pos) { mOffset = pos; }

		Vector2 GetPos() { return mPos; }
		Vector2 GetOffset() { return mOffset; }
		Vector2 GetScale() { return mScale; }

	private:
		Vector2 mOffset;
		Vector2 mPos;
		Vector2 mScale;

		UINT mCollisionCount;
	};
}