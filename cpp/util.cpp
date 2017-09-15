#include "util.h"

int findNearestCenter(par* dataPoint, vector<par*> *centers)
{
	int iLowest;
	double diff;
	vector<double> distances;
	par *center;

	// cout << "Calculate diffs" << endl;
	for (vector<par*>::iterator i = centers->begin(); i != centers->end(); ++i)
	{
		center = (*i);
		diff = *dataPoint - *center;
		// dataPoint->print();
		// center->print();
		// cout << "Diff: " << diff << endl;
		distances.push_back(diff);
	}

	iLowest = min_element(distances.begin(), distances.end()) - distances.begin();
	// cout << "Lowest dist.: " << distances[iLowest] << endl; 

	return iLowest;
}

void assignToNearestCenter(map<int,par*> *points, vector<par*> *centers, map<int,vector<par*>*> *clusters)
{
	map<int,par*>::iterator itPoint = points->begin();

	par* dataPoint;
	int nearestCluster;
	vector<par*>* cList;
	//iterate all data points
	for(;itPoint != points->end(); ++itPoint)
	{
		dataPoint = itPoint->second;
		nearestCluster = findNearestCenter(dataPoint, centers);
		clusters->at(nearestCluster)->push_back(dataPoint);
		// TODO:: Include new data point and adjust center of cluster
	}
}

void reviewClusters(vector<par*> *centers, map<int,vector<par*>*> *clusters)
{

}
