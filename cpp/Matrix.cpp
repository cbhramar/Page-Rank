#include <bits/stdc++.h>
#include "Matrix.h"

using namespace std;

Matrix::Matrix() {
	dimension = -1;
}

Matrix::Matrix(int n) {
	dimension = n;
}

void Matrix::appendRow(vector<float> row) {
	matrix.push_back(row);
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
	cout << right << setw(dimension*4) << "--Matrix--" << endl;
	for (unsigned i = 0; i < dimension; ++i) {
		unsigned j = 0;
		for (j; j < dimension-1; ++j) {
			cout << right << setw(4) << matrix[i][j] << "| ";
		}
		cout << right << setw(4) << matrix[i][j] << "| " << endl;
	}
	cout << right << setw(dimension*4) << "----------" << endl;
}
