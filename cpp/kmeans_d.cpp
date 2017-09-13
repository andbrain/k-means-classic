#include "kmeans_d.h"

kmeans_d::kmeans_d(int k, vector<par*>* v)
{
	cout << "Starting kmeans_d" << endl;
	srand(time(NULL));
	mK = k;
	mPoints = new map<int,par*>();
	initialize(v);
}

kmeans_d::~kmeans_d()
{
	delete mPoints;
	cout << "Finishing kmeans_d" << endl;
}


void kmeans_d::initialize(vector<par*>* v)
{
	//get all points from vector{par} to map{id|par}
	for (int i=0; i < v->size(); ++i)
		mPoints->insert(make_pair(i,v->at(i)));

	
	// choose random centers
	int iSecret;
	map<int,int> pChoosen;
	
	for (int i = 0; i < mK; ++i)
	{
		iSecret = rand() % mPoints->size();

		//TODO:: maybe it can begin an infinite loop
		while(pChoosen.find(iSecret) != pChoosen.end())
			iSecret = rand() % mPoints->size();
		pChoosen[iSecret] = 0;
		par* p = mPoints->at(iSecret);
		mCenters.push_back(p);
	}
}

int kmeans_d::process()
{
 
	return 0;
}