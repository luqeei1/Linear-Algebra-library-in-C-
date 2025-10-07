#include "Matrix.h"
#include "Vector.h"
#include <iostream>

Matrix::Matrix() : values(0), rowsCount(0), columnsCount(0) {};
Matrix::Matrix(int rows, int columns) : values(rows, vector<double>(columns, 0.0)), rowsCount(rows), columnsCount(columns) {};
Matrix::Matrix(const vector<vector<double>>& vals) : values(vals), rowsCount(vals.size()), columnsCount(vals.empty() ? 0 : vals[0].size()) {};


int Matrix::rows() const {
	return rowsCount;

}

int Matrix::columns() const {
	return columnsCount; 
}

double& Matrix::operator()(int row, int col) {
	return values[row][col];
}

const double& Matrix::operator()(int row, int col) const{
	return values[row][col];
}

Matrix Matrix::operator+(const Matrix& other) const {
	if (rows() != other.rows() || columns() != other.columns()) {
		throw std::invalid_argument("Matrices are not valid sizes");
	}

	Matrix result(rows(), columns());
	for (int i = 0; i < rows(); i++) {
		for (int j = 0; j < columns(); j++) {
			result(i,j) = values[i][j] + other(i, j);
		}
	}

	return result; 
}

Matrix Matrix::operator-(const Matrix& other) const {
	if (rows() != other.rows() || columns() != other.columns()) {
		throw std::invalid_argument("Matrices are not valid sizes");
	}

	Matrix result(rows(), columns());
	for(int i = 0; i < rows(); i++) {
		for (int j = 0; j < columns(); j++) {
			result(i, j) = values[i][j] - other(i, j);
		}
	}

	return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
	if (columns() != other.rows()) {
		throw std::invalid_argument("Matrices are not valid sizes");
	}

	Matrix result(rows(), other.columns());
	for (int i = 0; i < rows(); i++) { // this is the row of the first matrix
		for (int j = 0; j < other.columns(); j++) { // this is the column of the second matrix
			for (int k = 0; k < columns(); k++) { // this is the result of the dot product
				result(i, j) += values[i][k] * other(k, j);
			}
		}
	}

	return result;
}

Matrix Matrix::transpose() const {
	Matrix result(columns(), rows());
	for (int i = 0; i < rows(); i++) {
		for (int j = 0; j < columns(); j++) {
			result(j,i) = values[i][j]; 
		}
	}

	return result; 
}

void Matrix::print() const {
	std::cout << "[" << std::endl;
	for (int i = 0; i < rows(); i++) {
		std::cout << "[ ";
		for (int j = 0; j < columns(); j++) {
			std::cout << " " << values[i][j];
		}
		std::cout << " ]" << std::endl;
	}
}

