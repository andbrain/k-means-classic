#include "distance_reader.h"

distance_reader::distance_reader(string path, int features)
{
	// cout << "Starting distance_reader" << endl;
	mInputPath = path;
	mFeat = features;
	mDist = new vector<par*>();
}

distance_reader::~distance_reader()
{
	for (std::vector<par*>::iterator i = mDist->begin(); i != mDist->end(); ++i)
		delete (*i);
	// cout << "Finishing distance_reader" << endl;
}

int distance_reader::process()
{
	FILE *pFile;
	int objCounter;
	float featArray[mFeat];
	par *point;

	try{
		pFile = fopen(mInputPath.c_str(), "r");

		while(fscanf(pFile, "%f", &featArray[0]) != EOF)
		{
			objCounter = 0;

			//read all features for some obj
			for (int i = 1; i < mFeat; ++i)
				fscanf(pFile, "%f", &featArray[i]);
			
			//create pair of features and push to vector of distances
			point = new par(objCounter);
			for (int i = 0; i < mFeat; ++i)
				point->add(featArray[i]);
			
			mDist->push_back(point);
			objCounter++;
		}
		fclose(pFile);
	}
	catch(exception& e)
	{
		cout << "[ERROR] exception: " << e.what() << endl;
		return 0;
	}

	return 1;
}

vector<par*>* distance_reader::getDistances()
{
	return mDist;
}
