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
	Matrix matrix;
public:
	PageRank(Matrix matrix, int dimension, int iterations = 100, float dampingFactor = 0.85) {
		this->dimension = dimension;
		this->iterations = iterations;
		this->dampingFactor = dampingFactor;
		this->matrix = matrix;
		RankVector v = RankVector(dimension);
		v.normalize();
		pageRankVector = v.getVector();
	}

	void pagerank() {
		matrix.multiplyScalar(dampingFactor);
		matrix.addScalar((1 - dampingFactor)/dimension);

		for (unsigned i = 0; i < iterations; ++i)
			pageRankVector = matrix.multiplyVector(pageRankVector);
	}

	void print() {
		cout << "Dimension: " << dimension << endl;
		cout << "Iterations: " << iterations << endl;
		cout << "Damping Factor: " << dampingFactor << endl;
		cout << "Page Rank Vector: " << endl;
		cout.precision(10);
		cout.setf(ios::fixed);
		for (unsigned i = 0; i < dimension; ++i)
			cout << right << setw(14) << pageRankVector[i] << endl;
	}
	
};


Matrix exampleMatrix() {
	Matrix matrix = Matrix(6);

	vector<float> v0{0.0250, 0.0250, 0.0250, 0.8750, 0.1667, 0.8750};
	vector<float> v1{0.4500, 0.0250, 0.0250, 0.0250, 0.1667, 0.0250};
	vector<float> v2{0.0250, 0.4500, 0.0250, 0.0250, 0.1667, 0.0250};
	vector<float> v3{0.0250, 0.4500, 0.3083, 0.0250, 0.1667, 0.0250};
	vector<float> v4{0.0250, 0.0250, 0.3083, 0.0250, 0.1667, 0.0250};
	vector<float> v5{0.4500, 0.0250, 0.3083, 0.0250, 0.1667, 0.0250};

	matrix.appendRow(v0);
	matrix.appendRow(v1);
	matrix.appendRow(v2);
	matrix.appendRow(v3);
	matrix.appendRow(v4);
	matrix.appendRow(v5);

	return matrix;
}

int main() {
	srand(time(0));

	int iterations = 100;
	float dampingFactor = 0.85;
	Matrix matrix = exampleMatrix();
	int dimension = matrix.getDimension();
	matrix.print();

	PageRank pageRank = PageRank(matrix, dimension, iterations, dampingFactor);
	pageRank.pagerank();
	pageRank.print();

	return 0;
}
