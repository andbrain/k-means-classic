#ifndef KMEANS_D_H
#define KMEANS_D_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "par.h"
#include "util.h"

using namespace std;

class kmeans_d
{
public:
	kmeans_d(int k, vector<par*>* v);
	~kmeans_d();
	int process();
private:
	int mK;
	map<int,par*> *mPoints;
	vector<par*> mCenters;
	map<int,vector<par*>*> *mClusters;
	void initialize(vector<par*>* v);
	void print();
};

#endif