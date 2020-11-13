#include <bits/stdc++.h>
#include "Matrix.h"
#include "RankVector.h"

using namespace std;

vector<float> pagerank(Matrix matrix, int dimension, int iterations, float dampingFactor) {
	RankVector v = RankVector(dimension);
	v.normalize();
	vector<float> rankVector = v.getVector();

	matrix.multiplyScalar(dampingFactor);
	matrix.addScalar((1 - dampingFactor)/dimension);

	for (unsigned i = 0; i < iterations; ++i) {
		rankVector = matrix.multiplyVector(rankVector);
	}

	return rankVector;
}


Matrix exampleMatrix() {
	Matrix matrix = Matrix(5);

	vector<float> v0{0.0,0.0,0.0,0.0,1.0};
	vector<float> v1{0.5,0.0,0.0,0.0,0.0};
	vector<float> v2{0.0,1.0,0.5,0.0,0.0};
	vector<float> v3{0.0,0.0,0.5,1.0,0.0};
	vector<float> v4{0.5,0.0,0.0,0.0,0.0};

	matrix.appendRow(v0);
	matrix.appendRow(v1);
	matrix.appendRow(v2);
	matrix.appendRow(v3);
	matrix.appendRow(v4);

	return matrix;
}


int main() {
	srand(time(0));

	int n = 5;
	int iterations = 100;
	float dampingFactor = 0.85;
	Matrix matrix = exampleMatrix();

	vector<float> v = pagerank(matrix, n, iterations, dampingFactor);
	cout << "Page rank vector:" << endl;
	for (unsigned i = 0; i < n; ++i) 
		cout << v[i] << endl;
	return 0;
}
