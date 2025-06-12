#pragma once
#include "CommonInclude.h"

namespace coke
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name };
		std::wstring& GetName() { return mName; } //���� ���ϸ� ����ż� �Ѿ - �ð� �̽�

	private:
		std::wstring mName;
	};

}

