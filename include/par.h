#ifndef PAR_H
#define PAR_H

#include <iostream>
#include <vector>

using namespace std;

class par
{
public:
	par(int id);
	~par();

	inline void add(double value)
	{
		mFeat->push_back(value);
	}

	inline double get(int pos)
	{
		return mFeat->at(pos);
	}

	inline void set(int pos, double value)
	{
		mFeat->at(pos) = value;
	}

	int getId();
	int size();
	void print();
	
private:
	int mId;
	vector<double> *mFeat;	
};

#endif