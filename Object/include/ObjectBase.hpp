#pragma once
#include <functional>
#include <optional>

namespace phun
{
	class ObjectBase
	{
		friend class ObjectManager;
	public:
		ObjectBase();
	protected:
		size_t id_;
	};
}