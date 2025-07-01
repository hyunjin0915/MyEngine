#pragma once
#include "CokeResource.h"

namespace coke::graphics
{
	class Texture :public Resource
	{
	public:
		enum class eTextureType
		{
			Bmp,
			Png,
			None,
		};

		Texture();
		~Texture();

		virtual HRESULT Load(const std::wstring& path) override;

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		HDC GetHdc() { return mHdc; }
		eTextureType GetTextureType() { return mType; }
		Gdiplus::Image* GetImage() { return mImage; }

	private:
		eTextureType mType;
		Gdiplus::Image* mImage;
		HBITMAP mBitmap;
		HDC mHdc; // dc 를 따로 만들어 줘야 함

		UINT mWidth;
		UINT mHeight;
	};

}

