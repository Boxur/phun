#pragma once
#include "ObjectBase.hpp"
#include "Object.hpp"
#include <mutex>
#include <vector>
#include <memory>
#include <any>

namespace phun
{
	class ObjectManager
	{
		template<class T>
		friend class Object;
	public:
		static ObjectManager& instance();
	private:
		void RegisterObject(ObjectBase* obj,std::any value);

		void remove(ObjectBase& obj);

		std::any& getValue(ObjectBase& obj);


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