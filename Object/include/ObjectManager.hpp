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
		ObjectManager() {}
		ObjectManager(const ObjectManager&) = delete;
		ObjectManager& operator=(const ObjectManager&) = delete;

		void RegisterObject(ObjectBase* obj,std::any value);

		void UnregisterObject(ObjectBase& obj);

		std::any& GetValue(ObjectBase& obj);

		std::mutex mutex_;

		std::vector<size_t>		  objectIndexes_;
		std::vector<size_t>		  ids_;
		std::vector<ObjectBase*>  objects_;
		std::vector<std::any>	  values_;
	};
}