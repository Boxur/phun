#pragma once
#include "ObjectBase.hpp"
#include "ObjectManager.hpp"
#include <memory>
#include <any>
#include <cstdlib>

namespace phun
{
	template<class T>
	class Object : public ObjectBase
	{
	public:
		static Object<T>& Create(T value)
		{
			auto ptr = std::unique_ptr<Object<T>>(new Object<T>(std::move(value)));
			auto& baseRef = ObjectManager::instance().RegisterObject(std::move(ptr),std::move(value));
			return static_cast<Object<T>&>(baseRef);
		}

		Object<T>& operator=(Object<T> other)
		{
			decreaseCounter_();
			refCount = other.refCount;
			increaseCounter_();
			id_ = other.id_;
			return *this;
		}

		T& value()
		{
			return std::any_cast<T&>(ObjectManager::instance().getValue(*this));
		}

		Object() = delete;
		Object(const Object& other)
		{
			refCount = other.refCount;
			increaseCounter_();
			id_ = other.id_;
		}

		~Object()
		{
			decreaseCounter_();
		}

	private:
		explicit Object(T value)
		{
			refCount = new size_t();
			*refCount=0;
		}

		void increaseCounter_()
		{
			++(*refCount);
		}

		void decreaseCounter_()
		{
			--(*refCount);
			if (*refCount == 0)
				release();
		}

		void release()
		{
			ObjectManager::instance().remove(*this);
			delete refCount;
			refCount = nullptr;
		}

	public:
		size_t* refCount;
	};
}