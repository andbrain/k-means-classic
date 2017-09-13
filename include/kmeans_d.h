#ifndef KMEANS_D_H
#include <iostream>
#include <vector>

using namespace std;

class kmeans_d
{
public:
	kmeans_d();
	~kmeans_d();
	int process();
private:
	vector< pair<double,double> > mDist;
};

#endif