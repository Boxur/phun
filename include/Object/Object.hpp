#pragma once
#include "ObjectBase.hpp"
#include "ObjectManager.hpp"
#include "Reference.hpp"
#include <memory>
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
			auto& baseRef = ObjectManager::instance().RegisterObject(std::move(ptr));
			return static_cast<Object<T>&>(baseRef);
		}

		Object<T>& operator=(Object<T> other)
		{
			decreaseCounter_();
			reference = other.reference;
			increaseCounter_();
			id_ = other.id_;
			return *this;
		}

		Object() = delete;
		Object(const Object& other)
		{
			reference = other.reference;
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
			reference = new Reference<T>();
			reference->value = value;
			reference->refCount=0;
		}

		void increaseCounter_()
		{
			++reference->refCount;
		}

		void decreaseCounter_()
		{
			--reference->refCount;
			if (reference->refCount == 0)
				release();
		}

		void release()
		{
			ObjectManager::instance().remove(*this);
			delete reference;
			reference = nullptr;
		}

	public:
		Reference<T>* reference;
	};
}