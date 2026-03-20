#pragma once
#include <functional>
#include <optional>

namespace phun
{
	class ObjectBase
	{
	public:
		friend class ObjectManager;
	public:
		ObjectBase();
	protected:
		
		size_t id_;
	};
}