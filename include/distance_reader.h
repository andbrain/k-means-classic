#ifndef DISTANCE_READER_H
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct par
{
	double x;
	double y;
};

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