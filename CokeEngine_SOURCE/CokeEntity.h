#pragma once
#include "CommonInclude.h"

using namespace coke::math;
namespace coke
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

 		void SetName(const std::wstring& name) { mName = name; };
		std::wstring& GetName() { return mName; } //참조 안하면 복사돼서 넘어감 - 시간 이슈

	private:
		std::wstring mName;
	};

}

