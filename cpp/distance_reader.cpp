#include "distance_reader.h"

distance_reader::distance_reader(string path)
{
	// cout << "Starting distance_reader" << endl;
	mInputPath = path;
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

	try{
		pFile = fopen(mInputPath.c_str(), "r");
		float n1,n2;

		while(fscanf(pFile, "%f %f", &n1, &n2) != EOF)
		{
			par *ponto = new par();
			ponto->x = n1;
			ponto->y = n2;
			mDist->push_back(ponto);
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
