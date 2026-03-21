#include "Object.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"
#include <iostream>

int main()
{
	auto A = phun::Object<phun::Matrix>::Create({ { 3,0,2,2,1,0,1,4,2 } });
	A->Invert();
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << (*A)(i, j) << " ";
		std::cout << std::endl;
	}
	return 0;
}