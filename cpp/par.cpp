#include "par.h"

par::par(int id)
{
	mId = id;
	mFeat = new vector<double>();
}

par::~par()
{
	delete mFeat;
}

int par::getId()
{
	return mId;
}


int par::size()
{
	return mFeat->size();
}

void par::print()
{
	cout << "{id: " << mId << "}" << " ( ";
	for (vector<double>::iterator i = mFeat->begin(); i != mFeat->end(); ++i)
	{
		cout << (*i) << " ";
	}
	cout << ")" << endl;
}