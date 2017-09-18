#include "kmeans_d.h"

kmeans_d::kmeans_d(int k, int maxit,vector<par*>* v)
{
	cout << "Starting kmeans_d" << endl;
	srand(time(NULL));
	mK = k;
	mMaxIt = maxit;
	mPoints = new map<int,par*>();
	mClusters = new map<int,vector<par*>*>();
	initialize(v);
}

kmeans_d::~kmeans_d()
{
	delete mPoints;

	for (std::vector<par*>::iterator i = mCenters.begin(); i != mCenters.end(); ++i)
		delete (*i);

	map<int,vector<par*>*>::iterator itClusters = mClusters->begin();
	for (itClusters; itClusters != mClusters->end(); ++itClusters)
		delete itClusters->second;

	cout << "Finishing kmeans_d" << endl;
}


void kmeans_d::initialize(vector<par*>* v)
{
	//get all points from vector{par} to map{id|par}
	for (int i=0; i < v->size(); ++i)
		mPoints->insert(make_pair(v->at(i)->getId(),v->at(i)));
	
	// choose random centers
	int iSecret;
	vector<par*> *vec;
	map<int,int> chosen;
	for (int i = 0; i < mK; ++i)
	{
		iSecret = rand() % mPoints->size();
		//TODO:: maybe it can begin an infinite loop
		while(chosen.find(iSecret) != chosen.end())
			iSecret = rand() % mPoints->size();
		chosen[iSecret] = 0;
		par *p = mPoints->at(iSecret);
		
		//initialize vector for each cluster
		vec = new vector<par*>();
		// vec->push_back(p);
		mClusters->insert(make_pair(mCenters.size(), vec));

		//add data point to vector of centers
		par *ponto = new par();
		for (int i = 0; i < p->size(); ++i)
			ponto->add(p->get(i));
		mCenters.push_back(ponto);
	}
}

int kmeans_d::process()
{
	// cout << "**Before assign to Centers**" << endl;
	// print();

	assignToNearestCenter(mPoints, &mCenters, mClusters);

	// cout << "**Assign to Centers**" << endl;
	// print();
	bool converge;
	for (int i = 0; i < mMaxIt; ++i)
	{
		cout << "Iteration " << i << endl;
		converge = clustersConverge(&mCenters, mClusters);
		
		if(converge)
			break;
		for (int clusterIndex = 0; clusterIndex < mClusters->size(); ++clusterIndex)
			refactCenter(clusterIndex,&mCenters, mClusters);
	}

	cout << endl;
	cout << endl;
	cout << "**Final clusters**" << endl;
	print();
	
	return 0;
}

void kmeans_d::print()
{
	//show data points available
	cout << "[Data Points]" << endl;
	map<int,par*>::iterator itPoints = mPoints->begin();
	for (itPoints; itPoints != mPoints->end(); ++itPoints)
	{
		// cout << "id: " << itPoints->first << " -> ";
		itPoints->second->print();
	}
	
	cout << endl;
	cout << "[Centers]" << endl;

	//show centers
	for (std::vector<par*>::iterator i = mCenters.begin(); i != mCenters.end(); ++i)
		(*i)->print(false);

	cout << endl;
	cout << "[Clusters]" << endl;

	//show clusters
	map<int,vector<par*>*>::iterator itClusters = mClusters->begin();
	for (itClusters; itClusters != mClusters->end(); ++itClusters)
	{
		cout << itClusters->first << ": " << endl;
		for (int i = 0; i < itClusters->second->size(); ++i)
		{
			cout << setfill(' ') << setw(5);
			itClusters->second->at(i)->print();
		}
	}
}