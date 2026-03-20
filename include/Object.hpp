#pragma once
#include "ObjectBase.hpp"
#include "ObjectManager.hpp"
#include <memory>
#include <utility>

namespace phun
{
	template<class T>
	class Object : public ObjectBase
	{
	public:
		static Object<T>& Create(T value)
		{
			auto ptr = std::unique_ptr<Object<T>>(new Object<T>(std::move(value)));
			auto& baseRef = ObjectManager::instance().RegisterObject(std::move(ptr));
			return static_cast<Object<T>&>(baseRef);
		}
	private:
		explicit Object(T value) : value(std::move(value)) {}

	public:
		T value;
	};
}