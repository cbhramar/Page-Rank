#include <bits/stdc++.h>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(int n) {
	dimension = n;
}

void Matrix::appendRow(vector<float> row) {
	matrix.push_back(row);
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
			cout << matrix[i][j] << ", ";
		}
		cout << matrix[i][j] << endl;
	}
}
