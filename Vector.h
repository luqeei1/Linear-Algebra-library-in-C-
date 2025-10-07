#pragma once

#include<vector>
#include<iostream>



class Vector {
private:
	std::vector<double> elements;

public: 
	Vector();
	Vector(int size); 
	Vector(const std::vector<double>& values); 


	int size() const; 


	double& operator[](int index); // means we can modify the value
	const double& operator[](int index) const; // means we cannot modify the value


	Vector operator+(const Vector& other) const;
	Vector operator-(const Vector& other) const;
	double dot(const Vector& other) const; 


	void print() const; 



};
