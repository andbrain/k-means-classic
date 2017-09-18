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

void par::print(bool showId)
{
	if(showId)
		cout << "{id: " << mId << "} ";
	cout << "( ";
	for (vector<double>::iterator i = mFeat->begin(); i != mFeat->end(); ++i)
	{
		cout << (*i) << " ";
	}
	cout << ")" << endl;
}

double par::operator-(par &point)
{
	double result = 0;

	for (int i = 0; i < mFeat->size(); ++i)
		result += pow(this->get(i) - point.get(i), 2);
	return sqrt(result);
}
