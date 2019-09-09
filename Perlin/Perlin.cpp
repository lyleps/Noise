/**
   An implementation of ND Perlin Noise
   by Lyle A. Pierson Stachecki
 **/

#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

default_random_engine gen;
uniform_real_distribution<double> dist(-1.0,1.0);
int Dim;
double* space;


/*
  Create a 2D vector of length one pointing in a random direction
  @param vec:
    The address for a vector of double points
  @param D:
    The dimension of the vector to assign
 */
int assign_vec(double* vec, int D)
{
	double len_2; // the square of the length
	//create vector of length <= 1
	do
	{
		len_2 = 0;
		for(int i = 0; i < D; i++)
		{
			double val = dist(gen);
			vec[i] = val;
			len_2 += val*val;
		}
	} while (len_2 > 1);

	// normalize vec
	double len = sqrt(len_2); // the length of vec
	for(int i = 0; i < D; i++)
	{
		vec[i] = vec[i]/len;
	}
	return 0;
}


int main(int argc, char* argv[])
{
	Dim = argc - 1; // The dimension of the space to create noise in
	if(Dim <= 0) exit(0); // if dimension is 0 quit the program
	int dim_sz[Dim]; // size of each dimension

	// print the Dim
	cout << "Dimension: " << Dim << endl;

	// Get the size  the space
	int vol = 1;
	for(int i = 1; i < argc; i++)
	{
		cout << "Dim_" << i << " len: " << argv[i] << endl;
		dim_sz[i-1] = atoi(argv[i]);
		vol = vol * dim_sz[i-1];
	}

	// allocate the space to hold Dim dimension vectors of doubles
	space = (double*) calloc(vol * Dim, sizeof(double));

	// set the memory to unit vectors of size Dim
	for(int i = 0; i < vol*Dim; i += Dim)
		assign_vec(&space[i], Dim);

	// initialize delimiters for dimensions when printing
	int delims[Dim-1];
	for(int i = 0; i < Dim - 1; i++)
	{
		if(i == 0) delims[i] = dim_sz[i] * Dim;
		else delims[i] = delims[i-1] * dim_sz[i];
	}

	// print the vecs
	for(int i = 0; i < vol*Dim; i++)
	{
		for(int j = 0; j < Dim - 1; j++)
			if(i % delims[j] == 0) cout << endl;
		if (i == 0) cout << "[";
		else if(i % Dim == 0) cout << "[";
		cout << space[i];
		if (i % Dim == Dim -1) cout << "]";
		else cout << ",";
	}

	cout << endl;
	
	
	return 0;
}

