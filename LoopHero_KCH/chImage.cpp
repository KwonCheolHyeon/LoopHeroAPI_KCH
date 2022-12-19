#include "chImage.h"
#include "chApplication.h"
#include "chResources.h"

namespace ch
{
	Image* Image::Create(const std::wstring& key, UINT width, UINT height)
	{
		Image* image = Resources::Find<Image>(key);
		if (image != nullptr)
		{
		
			return image;
		}

		// �̹����� ����������Ѵ�.
		image = new Image();
		HDC mainHdc = Application::GetInstance().GetHdc();

		image->mBitmap = CreateCompatibleBitmap(mainHdc, width, height);
		image->mHdc = CreateCompatibleDC(mainHdc);

		if (image->mBitmap == NULL
			|| image->mHdc == NULL)
			return nullptr;

		// ���� ������ ��Ʈ�ʰ� DC �� ���� ����������մϴ�.
		HBITMAP defaultBitmap = (HBITMAP)SelectObject(image->mHdc, image->mBitmap);
		DeleteObject(defaultBitmap);

		//��Ʈ�� ���� Ȯ��
		BITMAP bitmap = {};
		GetObject(image->mBitmap, sizeof(BITMAP), &bitmap);

		image->mWidth = bitmap.bmWidth;
		image->mHeight = bitmap.bmHeight;

		image->SetKey(key);
		Resources::Insert<Image>(key, image);

		return image;
	}
	Image::Image()
		: mBitmap(NULL)
		, mHdc(NULL)
		, mWidth(0)
		, mHeight(0)
	{
	}

	Image::~Image()
	{
		HWND hWnd = Application::GetInstance().GetWindowData().hWnd;
		ReleaseDC(hWnd, mHdc);
	}

	HRESULT Image::Load(const std::wstring& path)
	{
		mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str()
			, IMAGE_BITMAP, 0, 0
			, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		if (mBitmap == nullptr)
		{
			return E_FAIL;
		}

		BITMAP bitInfo = {};
		GetObject(mBitmap, sizeof(BITMAP), &bitInfo);

		mWidth = bitInfo.bmWidth;
		mHeight = bitInfo.bmHeight;

		HDC mainDC = Application::GetInstance().GetWindowData().hdc;
		mHdc = CreateCompatibleDC(mainDC);

		HBITMAP prevBit = (HBITMAP)SelectObject(mHdc, mBitmap);
		DeleteObject(prevBit);

		return S_OK;
	}
}

