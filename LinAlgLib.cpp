// LinAlgLib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"
#include "Matrix.h"

int main()
{
	std::cout << "Testing the linalg library!\n"; 
	Vector v1({1.0, 2.0, 3.0});
	Vector v2({4.0, 5.0, 6.0});
	Vector v3 = v1 + v2;
	std::cout << "v1 + v2 = ";
	v3.print();
	Matrix m1({ {1, 2}, {3, 4} });
	Matrix m2({ {5, 6}, {7, 8} });
	Matrix m3 = m1 * m2;
	std::cout << "m1 * m2 = ";
	m3.print();
	Matrix m4 = m3.transpose();
	std::cout << "the transpose of m3 is then ";
	m4.print();
	return 0;
}
