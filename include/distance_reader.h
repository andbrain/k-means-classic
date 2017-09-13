#ifndef DISTANCE_READER_H
#include <iostream>
#include <vector>

using namespace std;

class distance_reader
{
public:
	distance_reader(string path);
	~distance_reader();
	int process();
	vector< pair<double,double>* >* getDistances();
private:
	string mInputPath;
	vector<pair<double,double>* >* mDist;
};

#endif