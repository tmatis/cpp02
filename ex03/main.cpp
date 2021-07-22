#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <assert.h>

void	test_bsp(bool bsp_result, bool expected)
{
	static int	n = 0;

	std::cout << "test " << ++n << ": ";
	if (bsp_result == expected)
		std::cout << "\033[32m[OK]";
	else
		std::cout << "\033[31m[FAILED]";
	std::cout << "\033[0m" << std::endl;
}

int main(void)
{
    Point a(4, 5);
    Point b(6, 2);
    Point c(2, 2);
    Point point(4, 3);
    Point point2(10, 3);

    test_bsp(bsp(a, b, c, point), true);
    test_bsp(bsp(a, b, c, point2), false);
    test_bsp(bsp(a, b, c, a), true);
    test_bsp(bsp(a, b, c, b), true);
    test_bsp(bsp(a, b, c, c), true);
    return 0;
}
