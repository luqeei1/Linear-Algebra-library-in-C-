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

double Matrix::determinant() const {
	int res = 0;
	if (rows() != columns()) {
		throw std::invalid_argument("Matrix is not square"); 
	}

	if (rows() == 1) { // general case for 1x1
		return values[0][0];
	}

	if (rows() == 2) { // general case for 2x2
		return values[0][0] * values[1][1] - values[0][1] * values[1][0];

	}
	
	for (int p = 0; p < columns(); p++) {
		Matrix subMatrix(rows() - 1, columns() - 1);
		for (int i = 1; i < rows(); i++) {
			int sub_j = 0;
			for (int j = 0; j < columns(); j++) {
				if (j == p) continue;
				subMatrix(i - 1, sub_j) = values[i][j];
				sub_j++;
			}
		}
		res += (p % 2 == 0 ? 1 : -1) * values[0][p] * subMatrix.determinant();
	}
	
	return res;

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

