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
			refCount_ = other.refCount_;
			increaseCounter_();
			id_ = other.id_;
			return *this;
		}

		T& value()
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
		explicit Object(T value)
		{
			refCount_ = new size_t();
			*refCount_=0;
		}

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

	public:
		size_t* refCount_;
	};
}