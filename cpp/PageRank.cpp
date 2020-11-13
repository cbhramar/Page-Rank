#include <bits/stdc++.h>

using namespace std;

void printVector(vector<float> v) {
	unsigned i = 0;
	for (; i < v.size()-1; ++i) {
		cout << v[i] << ", ";
	}
	cout << v[i] << endl;
}

class Matrix {
private:
	vector<vector<float>> matrix;
	int dimension;
public:
	Matrix(int n) {
		dimension = n;
	};

	void appendRow(vector<float> row) {
		matrix.push_back(row);
	}

	float getCell(int rowId, int colId) {
		if (rowId >= dimension || colId >= dimension) 
			return -1.0;
		return matrix[rowId][colId];
	}

	void multiplyScalar(float scalar) {
		for (unsigned i = 0; i < dimension; ++i) {
			for (unsigned j = 0; j < dimension; ++j) {
				matrix[i][j] *= scalar;
			}
		}
	}

	void addScalar(float scalar) {
		for (unsigned i = 0; i < dimension; ++i) {
			for (unsigned j = 0; j < dimension; ++j) {
				matrix[i][j] += scalar;
			}
		}
	}

	vector<float> multiplyVector(vector<float> v) {
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

	void print() {
		for (unsigned i = 0; i < dimension; ++i) {
			printVector(matrix[i]);
			cout << endl;
		}
	}

};

vector<float> randomVector(int dimension) {
	vector<float> random;
	float r = 0.0;
	for (unsigned i = 0; i < dimension; ++i) {
		r = (rand()/(float)RAND_MAX);
		random.push_back(r);
	}
	return random;
}

void normalizeVector(vector<float> &v, int n) {
	float normalizer = 0.0;
	for (unsigned i = 0; i < n; ++i)
		normalizer += v[i];
	for (unsigned i = 0; i < n; ++i) {
		v[i] = v[i]/normalizer;
	}
}

vector<float> randomNormalVector(int dimension) {
	vector<float> random = randomVector(dimension);
	normalizeVector(random, dimension);
	return random; 
}

Matrix testMatrix() {
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

vector<float> pagerank(Matrix matrix, int dimension, int iterations, float dampingFactor) {
	vector<float> rankVector = randomNormalVector(dimension);

	matrix.multiplyScalar(dampingFactor);
	matrix.addScalar((1 - dampingFactor)/dimension);

	for (unsigned i = 0; i < iterations; ++i) {
		rankVector = matrix.multiplyVector(rankVector);
	}

	return rankVector;
}

int main() {
	srand(time(0));

	int n = 5;
	int iterations = 100;
	float dampingFactor = 0.85;
	Matrix matrix = testMatrix();

	vector<float> v = pagerank(matrix, n, iterations, dampingFactor);
	cout << "Page rank vector:" << endl;
	printVector(v);

	return 0;
}
