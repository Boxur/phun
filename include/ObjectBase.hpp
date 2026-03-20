#pragma once
#include <functional>
#include <optional>

namespace phun
{
	class ObjectBase
	{
	public:
		ObjectBase() : id_(-1) {}
		friend class ObjectManager;
	private:
		int id_;
	};
}