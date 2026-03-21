#include "ObjectManager.hpp"


namespace phun
{
	ObjectManager& ObjectManager::instance()
	{
		static ObjectManager inst;
		return inst;
	}

	ObjectBase& ObjectManager::RegisterObject(std::unique_ptr<ObjectBase> obj, std::any value)
	{
		std::lock_guard<std::mutex> lock(mutex_);
		if (objects_.size() >= ids_.size())
		{
			objectIndexes_.push_back(static_cast<int>(objectIndexes_.size()));
			ids_.push_back(static_cast<int>(ids_.size()));
		}
		obj->id_ = ids_[objects_.size()];
		objects_.push_back(std::move(obj));
		objects_[objects_.size()-1]->id_ = ids_[objects_.size() - 1];
		values_.push_back(value);
		return *objects_.back();
	}

	std::any& ObjectManager::getValue(ObjectBase& obj)
	{
		return values_[objectIndexes_[obj.id_]];
	}

	void ObjectManager::remove(ObjectBase& obj)
	{
		std::lock_guard<std::mutex> lock(mutex_);
		if (objectIndexes_[obj.id_] != objects_.size() - 1)
		{
			std::swap(ids_[objectIndexes_[obj.id_]], ids_[objects_.size() - 1]);
			std::swap(objects_[objectIndexes_[obj.id_]], objects_[objects_.size() - 1]);
			std::swap(values_[objectIndexes_[obj.id_]], values_[objects_.size() - 1]);
			objectIndexes_[ids_[objectIndexes_[obj.id_]]] = objectIndexes_[obj.id_];
			objectIndexes_[ids_[objects_.size() - 1]] = objects_.size() - 1;
		}
		objects_.pop_back();
		values_.pop_back();
		obj.id_=-1;
	}
}