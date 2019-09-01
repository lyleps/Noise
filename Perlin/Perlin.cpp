/**
   An implementation of 2D Perlin Noise
   by Lyle A. Pierson Stachecki
 **/

#include <stdlib.h>
#include <iostream>

#define X 10
#define Y 10

using namespace std;

int grid[Y][X] {};

int main(int argc, char* argv[])
{
	for(int i = 0; i < Y; i++)
	{
		for(int j = 0; j < X; j++)
		{
			cout << grid[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
