#pragma once

#include<vector>
#include<iostream>


using namespace std; 

class Matrix {
private:
	vector<vector<double>> values;
	int rowsCount;
	int columnsCount; 

public:

	Matrix(); 
	Matrix(int rows, int columns);
	Matrix(const vector<vector<double>>& vals);


	int rows() const;
	int columns() const; 

	double& operator()(int row, int col); 
	const double& operator()(int row, int col) const; // first const means we cannot modify the value, second const means the method itself does not modify the object
	
	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;
	Matrix operator*(const Matrix& other) const;
	Matrix transpose() const;
	void print() const;
};