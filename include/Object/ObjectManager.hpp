#pragma once
#include "ObjectBase.hpp"
#include <mutex>
#include <vector>
#include <memory>
#include <any>

namespace phun
{
	class ObjectManager
	{
	public:
		static ObjectManager& instance();

		void RegisterObject(ObjectBase* obj,std::any value);

		void remove(ObjectBase& obj);

		std::any& getValue(ObjectBase& obj);

	private:
		ObjectManager() {}
		ObjectManager(const ObjectManager&) = delete;
		ObjectManager& operator=(const ObjectManager&) = delete;
		std::mutex mutex_;

		std::vector<size_t>					objectIndexes_;
		std::vector<size_t>							  ids_;
		std::vector<ObjectBase*>  objects_;
		std::vector<std::any>					   values_;
	};
}