#ifndef RANKVECTOR_H
#define RANKVECTOR_H 

using namespace std;

class RankVector {
private:
	vector<float> rankVector;
	int dimension;
	float vectorSum;

public:
	RankVector(int n);

	float sum();
	void normalize();

	vector<float> randomize();

	vector<float> getVector();

	void print();
};

#endif