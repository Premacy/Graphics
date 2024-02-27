#include <iostream>
#include <fstream>
#include "math/Vec2.h"

using namespace Math;

int main(void)
{
	Vec2 v1(1,2);
	Vec2 v2(3,4);

	//std::cout << v1 + v2 << std::endl;
	std::cout << Vec2::dist(v1, v2) << std::endl;
	std::cout << Vec2::scalar_product(v1, v2) << std::endl;
	std::cout << v1[0] << std::endl;

	Vec2 v3 = v1 - v2;

	std::cout << v3 << std::endl;

	v1 == v2;

	return 0;
}