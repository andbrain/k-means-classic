#ifndef DISTANCE_READER_H
#define DISTANCE_READER_H
#include <iostream>
#include <vector>
#include <cstdio>
#include "util.h"

using namespace std;

class distance_reader
{
public:
	distance_reader(string path);
	~distance_reader();
	int process();
	vector<par*>* getDistances();
private:
	string mInputPath;
	vector<par*>* mDist;
};

#endif