#include "kmeans_d.h"

kmeans_d::kmeans_d(int k, vector<par*>* v)
{
	cout << "Starting kmeans_d" << endl;
	srand(time(NULL));
	mK = k;
	mPoints = new map<int,par*>();
	mClusters = new map<int,vector<par*>*>();
	initialize(v);
}

kmeans_d::~kmeans_d()
{
	delete mPoints;

	map<int,vector<par*>*>::iterator itClusters = mClusters->begin();
	for (itClusters; itClusters != mClusters->end(); ++itClusters)
		delete itClusters->second;

	cout << "Finishing kmeans_d" << endl;
}


void kmeans_d::initialize(vector<par*>* v)
{
	//get all points from vector{par} to map{id|par}
	for (int i=0; i < v->size(); ++i)
		mPoints->insert(make_pair(i,v->at(i)));
	
	// choose random centers
	int iSecret;
	int nk = 1;
	vector<par*> *vec;

	for (int i = 0; i < mK; ++i)
	{
		iSecret = rand() % mPoints->size();
		//TODO:: maybe it can begin an infinite loop
		while(mClusters->find(iSecret) != mClusters->end())
			iSecret = rand() % mPoints->size();
		cout << "Secret: " << iSecret << endl;
		
		par* p = mPoints->at(iSecret);

		//add data point to vector of centers
		mCenters.push_back(p);
		
		//add data point to correct cluster
		vec = new vector<par*>;
		vec->push_back(p);
		
		mClusters->insert(make_pair(nk, vec));
		nk++;
	}
}

int kmeans_d::process()
{
	map<int,vector<par*>*>::iterator itClusters = mClusters->begin();
	for (itClusters; itClusters != mClusters->end(); ++itClusters)
	{
		cout << itClusters->first << " => " << itClusters->second->at(0)->x << "," << itClusters->second->at(0)->y << endl;
	}

	return 0;
}