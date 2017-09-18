# k-means-classic
Classic k-means using euclidean distance in C++

## Installation
- Cmake (3.5 or >)
> cmake . <BR/>
> make

## Usage
> ./kmeans.out \<K\> \<INPUT\> \<OUTPUT\> \<TYPE\> \<FEATURES\> \<MAXIT\> \<LABELED\> <BR/>

- K => Number of clusters
- INPUT => File path of input collection
- OUTPUT => File path for clusters file
- TYPE =>
	- 0 -> for distance
	- 1 -> for similarity
- FEATURES => number of features
- MAXIT => max of iterations
- LABELED =>
	- 0 -> for non labeled
	- 1 -> labeled
	
## Author
@andbrain -> andbrain@gmail.com
