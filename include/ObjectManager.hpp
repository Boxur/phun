#pragma once
#include "ObjectBase.hpp"
#include <mutex>
#include <vector>
#include <memory>

namespace phun
{
	class ObjectManager
	{
	public:
		static ObjectManager& instance();

		ObjectBase& RegisterObject(std::unique_ptr<ObjectBase> obj);

		void remove(ObjectBase& obj);


	private:
		ObjectManager() {}
		ObjectManager(const ObjectManager&) = delete;
		ObjectManager& operator=(const ObjectManager&) = delete;
		std::mutex mutex_;

		std::vector<size_t>					objectIndexes_;
		std::vector<size_t>							  ids_;
		std::vector<std::unique_ptr<ObjectBase>>  objects_;
	};
}