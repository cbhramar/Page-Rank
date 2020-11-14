#ifndef MATRIX_H
#define MATRIX_H 

using namespace std;

class Matrix {
private:
	vector<vector<float>> matrix;
	int dimension;

public:
	Matrix();
	Matrix(int n);

	float getCell(int rowId, int colId);
	vector<float> getRow(unsigned rowId);
	int getDimension();

	void appendRow(vector<float> row);

	void multiplyScalar(float scalar);
	void addScalar(float scalar);

	vector<float> multiplyVector(vector<float> v);

	void print();
};

#endif