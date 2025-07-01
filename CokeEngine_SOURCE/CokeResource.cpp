#include "CokeResource.h"

namespace coke
{
	Resource::Resource(enums::eResourceType type)
		: mType(type)
	{
	}
	Resource::~Resource(){}
}