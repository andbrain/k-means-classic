#include "util.h"

int findNearestCenter(par* dataPoint, vector<par*> *centers)
{
	int iLowest;
	double diff;
	vector<double> distances;
	par *center;

	for (vector<par*>::iterator i = centers->begin(); i != centers->end(); ++i)
	{
		center = (*i);
		diff = *dataPoint - *center;
		distances.push_back(diff);
	}
	iLowest = min_element(distances.begin(), distances.end()) - distances.begin();

	return iLowest;
}

void refactCenter(int nearest, vector<par*> *centers, map<int,vector<par*>*> *clusters)
{
	// adjust center of cluster

	par *nearestCenter = centers->at(nearest);
	vector<par*> *nearestCluster = clusters->at(nearest);

	int numberOfFeat = nearestCluster->at(0)->size();

	par counter(numberOfFeat, 0);
	double aux, value;
	
	//accumulate values
	for (int i = 0; i < nearestCluster->size(); ++i)
		for (int j = 0; j < numberOfFeat; ++j)
		{
			aux = counter.get(j);
			value = nearestCluster->at(i)->get(j);
			counter.set(j, aux + value);
		}

	//average of all features
	for (int i = 0; i < numberOfFeat; ++i)
		centers->at(nearest)->set(i,counter.get(i)/nearestCluster->size());
}

void assignToNearestCenter(map<int,par*> *points, vector<par*> *centers, map<int,vector<par*>*> *clusters)
{
	map<int,par*>::iterator itPoint = points->begin();

	par* dataPoint;
	int nearestCluster;
	
	//iterate all data points
	for(;itPoint != points->end(); ++itPoint)
	{
		dataPoint = itPoint->second;
		nearestCluster = findNearestCenter(dataPoint, centers);
		clusters->at(nearestCluster)->push_back(dataPoint);
		refactCenter(nearestCluster,centers, clusters);
	}
}

bool clustersConverge(vector<par*> *centers, map<int,vector<par*>*> *clusters)
{
	bool result = true;
	int nearestCluster;
	par* dataPoint;

	map<int,vector<par*>*>::iterator itClusters = clusters->begin();
	for (itClusters; itClusters != clusters->end(); ++itClusters)
	{
		for (int i = 0; i < itClusters->second->size(); ++i)
		{
			dataPoint = itClusters->second->at(i);
			nearestCluster = findNearestCenter(dataPoint, centers);

			//check if current cluster is the nearest cluster
			if(nearestCluster != itClusters->first)
			{
				result = false;
				//erase from current cluster
				itClusters->second->erase(itClusters->second->begin() + i);
				//add into the nearest cluster
				clusters->at(nearestCluster)->push_back(dataPoint);
			}
		}
	}

	return result;
}