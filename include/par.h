#ifndef PAR_H
#define PAR_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class par
{
public:
	par(int id=-1);
	par(int size, double value, int id=-1);
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
	void print(bool showId=true);

	double operator-(par &point);
	
private:
	int mId;
	vector<double> *mFeat;	
};

#endif