#ifndef MATRIX_H
#define MATRIX_H 

using namespace std;

class Matrix {
private:
	vector<vector<float>> matrix;
	int dimension;

public:
	Matrix(int n);

	float getCell(int rowId, int colId);
	void appendRow(vector<float> row);

	void multiplyScalar(float scalar);
	void addScalar(float scalar);

	vector<float> multiplyVector(vector<float> v);

	void print();
};

#endif