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
		Object() = delete;

		Object(T value)
		{
			refCount_ = new size_t();
			*refCount_ = 1;
			ObjectManager::instance().RegisterObject(std::move(this), std::move(value));
		}
		
		Object(const Object& other)
		{
			refCount_ = other.refCount_;
			IncreaseCounter_();
			id_ = other.id_;
		}

		~Object()
		{
			DecreaseCounter_();
		}

		Object<T>& operator=(const Object<T>& other)
		{
			DecreaseCounter_();
			refCount_ = other.refCount_;
			IncreaseCounter_();
			id_ = other.id_;
			return *this;
		}

		T& operator*()
		{
			return std::any_cast<T&>(ObjectManager::instance().getValue(*this));
		}

		T* operator->()
		{
			return &std::any_cast<T&>(ObjectManager::instance().getValue(*this));
		}

		T& Value()
		{
			return std::any_cast<T&>(ObjectManager::instance().getValue(*this));
		}

	private:
		void IncreaseCounter_()
		{
			++(*refCount_);
		}

		void DecreaseCounter_()
		{
			--(*refCount_);
			if (*refCount_ == 0)
				Release_();
		}

		void Release_()
		{
			ObjectManager::instance().remove(*this);
			delete refCount_;
			refCount_ = nullptr;
		}

	protected:
		size_t* refCount_;
	};
}