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
		/*static Object<T>& Create(T value)
		{

			std::unique_ptr<Object<T>> ptr;
			ptr->refCount_ = new size_t();
			*ptr->refCount_ = 0;
			auto& baseRef = ObjectManager::instance().RegisterObject(std::move(ptr),std::move(value));
			return static_cast<Object<T>&>(baseRef);
		}*/

		Object(T value)
		{
			refCount_ = new size_t();
			*refCount_ = 1;
			ObjectManager::instance().RegisterObject(std::move(this), std::move(value));
		}

		Object<T>& operator=(const Object<T>& other)
		{
			decreaseCounter_();
			refCount_ = other.refCount_;
			increaseCounter_();
			id_ = other.id_;
			return *this;
		}

		T& Value()
		{
			return std::any_cast<T&>(ObjectManager::instance().getValue(*this));
		}

		T& operator*()
		{
			return std::any_cast<T&>(ObjectManager::instance().getValue(*this));
		}

		T* operator->()
		{
			return &std::any_cast<T&>(ObjectManager::instance().getValue(*this));
		}

		Object() = delete;
		Object(const Object& other)
		{
			refCount_ = other.refCount_;
			increaseCounter_();
			id_ = other.id_;
		}

		~Object()
		{
			decreaseCounter_();
		}

	private:
		void increaseCounter_()
		{
			++(*refCount_);
		}

		void decreaseCounter_()
		{
			--(*refCount_);
			if (*refCount_ == 0)
				release_();
		}

		void release_()
		{
			ObjectManager::instance().remove(*this);
			delete refCount_;
			refCount_ = nullptr;
		}

	protected:
		size_t* refCount_;
	};
}