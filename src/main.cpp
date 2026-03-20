#include <iostream>
#include "ObjectBase.hpp"
#include "Object.hpp"
#include "ObjectManager.hpp"

int main()
{
	phun::Object<int> a = phun::Object<int>::Create(0);
	phun::Object<int> b = phun::Object<int>::Create(1);
	phun::Object<int> c = phun::Object<int>::Create(2);
	phun::ObjectManager::instance().remove(b);
	phun::Object<int> d = phun::Object<int>::Create(3);
}