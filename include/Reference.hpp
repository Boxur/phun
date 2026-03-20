#pragma once

namespace phun
{
	template<class T>
	struct Reference
	{
		size_t refCount;
		T value;
	};
}