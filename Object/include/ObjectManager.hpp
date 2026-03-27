#pragma once
#include <mutex>
#include <vector>
#include <cstddef>
#include <utility>

namespace phun
{

	template<class T>
	class ID
	{
		template<class U>
		friend class ObjectManager;
	public:
		ID() = delete;

		ID(const ID<T>& other)
		{
			id_ = other.id_;
			ObjectManager<T>::instance().RegisterObject(*this);
		}

		ID<T>& operator=(const ID<T>& other)
		{
			ObjectManager<T>::instance().UnregisterObject(*this);
			id_ = other.id_;
			ObjectManager<T>::instance().RegisterObject(*this);
			return *this;
		}

		~ID()
		{
			ObjectManager<T>::instance().UnregisterObject(*this);
		}

		T& operator*()
		{
			return ObjectManager<T>::instance().GetValue(*this);
		}

		size_t id() const
		{
			return id_;
		}

	private:

		ID(const size_t& id) : id_(id) {}

		size_t id_;
	};

	template<class T>
	class ObjectManager
	{
		template<class U>
		friend class ID;
	public:
		inline static ObjectManager& instance()
		{
			static ObjectManager inst;
			return inst;
		}

		ID<T> CreateObject()
		{
			std::lock_guard<std::mutex> lock(mutex_);
			if (objects_.size() >= ids_.size())
			{
				objectIndexes_.push_back(objectIndexes_.size());
				ids_.push_back(ids_.size()+1);
				refCounts_.push_back(0);
			}
			objects_.push_back(T{});
			++refCounts_[ids_.size() - 1];
			return ids_[ids_.size() - 1];
		}

		T& GetValue(const ID<T>& id)
		{
			static T zero;
			zero = {};
			if (id.id_ == 0)
				return zero;
			std::lock_guard<std::mutex> lock(mutex_);
			return objects_[objectIndexes_[id.id_-1]];
		}

	private:
		ObjectManager() {}
		ObjectManager(const ObjectManager&) = delete;
		ObjectManager& operator=(const ObjectManager&) = delete;

		void RegisterObject(const ID<T>& id)
		{
			std::lock_guard<std::mutex> lock(mutex_);
			++refCounts_[objectIndexes_[id.id_ - 1]];
		}

		void UnregisterObject(ID<T>& id)
		{
			if (id.id_ == 0)
				return;
			int index = id.id_ - 1;
			std::lock_guard<std::mutex> lock(mutex_);
			if (--refCounts_[index] != 0)
				return;
			if (objectIndexes_[index] != objects_.size() - 1)
			{
				std::swap(ids_[objectIndexes_[index]], ids_[objects_.size() - 1]);
				std::swap(objects_[objectIndexes_[index]], objects_[objects_.size() - 1]);
				std::swap(refCounts_[objectIndexes_[index]], refCounts_[objects_.size() - 1]);
				objectIndexes_[ids_[objectIndexes_[index]]] = objectIndexes_[index];
				objectIndexes_[ids_[objects_.size() - 1]] = objects_.size() - 1;
			}
			objects_.pop_back();
			id.id_ = 0;
		}

		std::mutex mutex_;

		std::vector<size_t>	objectIndexes_;
		std::vector<size_t> ids_;
		std::vector<size_t> refCounts_;
		std::vector<T>		objects_;
	};

}