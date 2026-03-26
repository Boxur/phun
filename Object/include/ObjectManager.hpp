#pragma once
#include <memory>
#include <mutex>
#include <vector>

namespace phun
{

	template<class T>
	class ID
	{
		template<class U>
		friend class ObjectManager;
	public:
		ID() = delete;
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
	public:
		
	public:
		inline static ObjectManager& ObjectManager::instance()
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
				ids_.push_back(ids_.size());
			}
			objects_.push_back(T{});
			return ids_[ids_.size() - 1];
		}

		void UnregisterObject(const ID<T>& id)
		{
			std::lock_guard<std::mutex> lock(mutex_);
			if (objectIndexes_[id.id()] != objects_.size() - 1)
			{
				std::swap(ids_[objectIndexes_[id.id()]], ids_[objects_.size() - 1]);
				std::swap(objects_[objectIndexes_[id.id()]], objects_[objects_.size() - 1]);
				objectIndexes_[ids_[objectIndexes_[id.id()]]] = objectIndexes_[id.id()];
				objectIndexes_[ids_[objects_.size() - 1]] = objects_.size() - 1;
			}
			objects_.pop_back();
		}

		T& GetValue(const ID<T>& id)
		{
			return objects_[objectIndexes_[id.id()]];
		}

	private:
		ObjectManager() {}
		ObjectManager(const ObjectManager&) = delete;
		ObjectManager& operator=(const ObjectManager&) = delete;

		std::mutex mutex_;

		std::vector<size_t>	objectIndexes_;
		std::vector<size_t> ids_;
		std::vector<T>		objects_;
	};

}