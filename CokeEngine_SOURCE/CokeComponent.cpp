#include "CokeComponent.h"

coke::Component::Component(enums::eComponentType type)
	: mType(type)
{
}

coke::Component::~Component()
{
}

void coke::Component::Initialize()
{
}

void coke::Component::Update()
{
}

void coke::Component::LateUpdate()
{
}

void coke::Component::Render(HDC hdc)
{
}
