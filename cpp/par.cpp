#include "par.h"

par::par(int id)
{
	mId = id;
	mFeat = new vector<double>();
}

par::par(int size, double value, int id)
{
	mId = id;
	mFeat = new std::vector<double>(size,value);
}

par::~par()
{
	delete mFeat;
}

int par::getId()
{
	return mId;
}

string par::getLabel()
{
	return mLabel;	
}

void par::setLabel(string label)
{
	mLabel = label;	
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
	cout << ") " << mLabel << endl; 
}

double par::operator-(par &point)
{
	double result = 0;

	for (int i = 0; i < mFeat->size(); ++i)
		result += pow(this->get(i) - point.get(i), 2);
	return sqrt(result);
}
