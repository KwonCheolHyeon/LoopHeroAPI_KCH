#pragma once
#include "chResource.h"

namespace ch
{
	class Image : public Resource
	{
	public:
		static Image* Create(const std::wstring& key, UINT width, UINT height);
		Image();
		~Image();

		virtual HRESULT Load(const std::wstring& path) override;

		HDC GetDC() { return mHdc; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }

	private:
		HBITMAP mBitmap;
		HDC mHdc;
		UINT mWidth;
		UINT mHeight;
	};
}


