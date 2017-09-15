#ifndef UTIL_H
#define UTIL_H
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "par.h"

using namespace std;
// send datapoint to nearest cluster 
void assignToNearestCenter(map<int,par*> *points, vector<par*> *centers, map<int,vector<par*>*> *clusters);

// check if all data points are in the correct cluster
void reviewClusters(vector<par*> *centers, map<int,vector<par*>*> *clusters);

// calculate distance from data point to centers, return index of nearest cluster
int findNearestCenter(par* dataPoint, vector<par*> *centers);

#endif