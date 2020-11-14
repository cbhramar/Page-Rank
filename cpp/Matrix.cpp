#include <bits/stdc++.h>
#include "Matrix.h"

using namespace std;

const unsigned PRINT_WIDTH = 6;

Matrix::Matrix() {
	dimension = -1;
}

Matrix::Matrix(int n) {
	dimension = n;
}

void Matrix::appendRow(vector<float> row) {
	matrix.push_back(row);
}

void Matrix::operator=(const Matrix& m) {
	this->dimension = m.dimension;
	for (unsigned i = 0; i < dimension; ++i) {
		this->matrix.push_back(m.matrix[i]);
	}
}

int Matrix::getDimension() {
	return dimension;
}

vector<float> Matrix::getRow(unsigned rowId) {
	return matrix[rowId];
}

float Matrix::getCell(int rowId, int colId) {
	if (rowId >= dimension || colId >= dimension) 
		return -1.0;
	return matrix[rowId][colId];
}

void Matrix::multiplyScalar(float scalar) {
	for (unsigned i = 0; i < dimension; ++i) {
		for (unsigned j = 0; j < dimension; ++j) {
			matrix[i][j] *= scalar;
		}
	}
}

void Matrix::addScalar(float scalar) {
	for (unsigned i = 0; i < dimension; ++i) {
		for (unsigned j = 0; j < dimension; ++j) {
			matrix[i][j] += scalar;
		}
	}
}

vector<float> Matrix::multiplyVector(vector<float> v) {
	vector<float> multipliedVector;
	for (unsigned i = 0; i < dimension; ++i) {
		float rank = 0.0;
		for (unsigned j = 0; j < dimension; ++j) {
			rank += matrix[i][j]*v[j];
		}
		multipliedVector.push_back(rank);
	}
	return multipliedVector;
}

void Matrix::print() {
	for (unsigned i = 0; i < dimension; ++i) {
		unsigned j = 0;
		for (j; j < dimension-1; ++j) {
			cout << right << setw(PRINT_WIDTH) << matrix[i][j] << "| ";
		}
		cout << right << setw(PRINT_WIDTH) << matrix[i][j] << "| " << endl;
	}
}
