#include <bits/stdc++.h>
#include "RankVector.h"

using namespace std;

RankVector::RankVector(int n) {
	srand(time(0));
	dimension = n;
	rankVector = randomize();
	vectorSum = sum();
}

vector<float> RankVector::randomize() {
	vector<float> random;
	float r = 0.0;
	for (unsigned i = 0; i < dimension; ++i) {
		r = (rand()/(float)RAND_MAX);
		random.push_back(r);
	}
	return random;
}

float RankVector::sum() {
	float sum = 0;
	for (unsigned i = 0; i < dimension; ++i) 
		sum += rankVector[i];
	return sum;
}

void RankVector::normalize() {
	for (unsigned i = 0; i < dimension; ++i) {
		rankVector[i] = rankVector[i]/vectorSum;
	}
	vectorSum = sum();
}

vector<float> RankVector::getVector() {
	return rankVector;
}

void RankVector::print() {
	unsigned i = 0;
	for (; i < dimension-1; ++i) {
		cout << rankVector[i] << ", ";
	}
	cout << rankVector[i] << endl;
}
