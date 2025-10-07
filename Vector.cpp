
#include "Vector.h"

Vector::Vector() : elements(0) {}; 
Vector::Vector(int size) : elements(size, 0.0) {}; 
Vector::Vector(const std::vector<double>& values) : elements(values) {};

int Vector::size() const {
	return elements.size();
}

double& Vector::operator[](int index) {
	return elements[index]; 
}

const double& Vector::operator[](int index) const {
	return elements[index]; 
}

Vector Vector::operator+(const Vector& other) const {
	if (size() != other.size()) {
		throw std::invalid_argument("Vectors are not the same size");
	}

	Vector result(size());
	for (int i = 0; i < size(); i++) {
		result[i] = elements[i] + other[i];
	}
	return result;
}

Vector Vector::operator-(const Vector& other) const {
	if (size() != other.size()) {
		throw std::invalid_argument("Vectors are not the same size");
	}

	Vector result(size());
	for (int i = 0; i < size(); i++) {
		result[i] = elements[i] - other[i]; 
	}

	return result;
}

double Vector::dot(const Vector& other) const{
	if (size() != other.size()) {
		throw std::invalid_argument("Vectors are not the same size");
	}

	double result = 0.0;

	for (int i = 0; i < size(); i++) {
		result += other[i] * elements[i];
	}

	return result; 
	
}

void Vector::print() const {
	std::cout << "[" << std::endl;
	for (int i = 0; i < size(); i++) {
		std::cout << " " << elements[i] << std::endl;
	}
	std::cout << "]" << std::endl;
}



