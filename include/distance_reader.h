#ifndef DISTANCE_READER_H
#define DISTANCE_READER_H
#include <iostream>
#include <vector>
#include <cstdio>
#include "par.h"

using namespace std;

class distance_reader
{
public:
	distance_reader(string path, int features, bool labeled=false);
	~distance_reader();
	int process();
	vector<par*>* getDistances();
private:
	string mInputPath;
	int mFeat;
	bool mLabeled;
	vector<par*>* mDist;
};

#endif