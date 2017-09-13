#include <iostream>
#include <string>
#include "mat.h"
#include "kmeans_d.h"
#include "kmeans_s.h"
#include "distance_reader.h"

using namespace std;

int k, type;
string *inputPath, *outputPath;

void checkInputParameters(int argc, char const *argv[]);

int main(int argc, char const *argv[])
{
	checkInputParameters(argc, argv);

	if(!type)
	{
		//kmeans based on euclidean distance
		distance_reader *dr = new distance_reader(*inputPath);
		dr->process();
		vector< pair<double,double>* > *distances = dr->getDistances();
		// TODO:: kmeans classic

		delete dr;
	}
	else
	{
		//kmeans based on similarity

		// TODO:: similarities reader
		// TODO:: spherical kmeans
	}

	delete inputPath;
	delete outputPath;

	return 0;
}

void checkInputParameters(int argc, char const *argv[])
{
	if(argc == 5)
	{
		try{
			k = stoi(argv[1]);
			inputPath = new string(argv[2]);
			outputPath = new string(argv[3]);
			type = stoi(argv[4]);
		}
		catch(exception& e){
			cout << "[ERROR] Exception: " << e.what() << endl;
			exit(1);
		}
	}
	else
	{
		cout << "[ERROR]: Missing parameters" << endl;
		cout << "e.g: ./kmeans.out <K> <INPUT> <OUTPUT> <TYPE>" << endl;
		cout << "K => number of clusters" << endl;
		cout << "INPUT => dataset file" << endl;
		cout << "OUTPUT => output file of clusters" << endl;
		cout << "TYPE => {0 = distance | 1 = similarity}" << endl;
		exit(1);
	}
}