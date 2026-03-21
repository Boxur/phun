#include "Object.hpp"
#include <iostream>

int main()
{
	phun::Object<int> a = phun::Object<int>::Create(0);
	std::cout << a.value()<<std::endl;
	{
		phun::Object<int> b = phun::Object<int>::Create(1);
		std::cout << a.value() << std::endl;
		a = b;
		std::cout << a.value() << std::endl;
		b.value() = 3;
		std::cout << a.value() << std::endl;

	}
	std::cout << a.value() << std::endl;
	phun::Object<int> c = phun::Object<int>::Create(2);
	phun::Object<int> d = phun::Object<int>::Create(3);
	return 0;
}