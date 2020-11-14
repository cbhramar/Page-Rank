#include <bits/stdc++.h>
#include "Matrix.h"
#include "RankVector.h"

using namespace std;

class PageRank {
private:
	vector<float> pageRankVector;
	int iterations;
	float dampingFactor;
	int dimension;
public:
	PageRank(int dimension, int iterations, float dampingFactor) {
		this->dimension = dimension;
		this->iterations = iterations;
		this->dampingFactor = dampingFactor;
		RankVector v = RankVector(dimension);
		v.normalize();
		pageRankVector = v.getVector();
	}

	void pagerank(Matrix matrix) {
		matrix.multiplyScalar(dampingFactor);
		matrix.addScalar((1 - dampingFactor)/dimension);

		for (unsigned i = 0; i < iterations; ++i)
			pageRankVector = matrix.multiplyVector(pageRankVector);
	}

	void print() {
		cout << "Page Rank Vector: " << endl;
		for (unsigned i = 0; i < dimension; ++i)
			cout << right << setw(12) << pageRankVector[i] << endl;
	}
	
};


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

	int dimension = 5;
	int iterations = 100;
	float dampingFactor = 0.85;
	Matrix matrix = exampleMatrix();
	matrix.print();

	PageRank pageRank = PageRank(dimension, iterations, dampingFactor);
	pageRank.pagerank(matrix);
	pageRank.print();

	return 0;
}
