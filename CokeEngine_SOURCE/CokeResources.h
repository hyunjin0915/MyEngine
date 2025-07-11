#pragma once
#include "CokeResource.h"

namespace coke
{
	class Resources
	{
	public:
		template <typename T>
		static T* Find(const std::wstring& key)
		{
			std::map<std::wstring, Resource*>::iterator iter = mResources.find(key);
			if (iter == mResources.end())
			{
				return nullptr;
			}
			return dynamic_cast<T*>(iter->second);
		}

		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			T* resource = Resources::Find<T>(key);
			if (resource != nullptr)
			{
				return resource;
			}
			resource = new T();
			if (FAILED(resource->Load(path)))
			{
				assert(false);
				//MessageBox(nullptr,  L"Image Load Failed!", L"Error", MB_OK);
			}
			resource->SetName(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));

			return resource;
		}
	private:
		static std::map<std::wstring, Resource*> mResources;
	};

}

