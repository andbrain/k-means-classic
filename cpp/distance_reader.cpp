#include "distance_reader.h"

distance_reader::distance_reader(string path)
{
	cout << "Starting distance_reader" << endl;
	mInputPath = path;
	vector<pair<double,double>* >* mDist = new vector<pair<double,double>* >();
}

distance_reader::~distance_reader()
{
	// TODO:: delete all pairs of vector mDist
	cout << "Finishing distance_reader" << endl;
}

int distance_reader::process()
{

	return 0;
}

vector<pair<double,double>* >* distance_reader::getDistances()
{
	return mDist;
}
