// Generating seeds that are at the center of cells. 

#include<math.h>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<stdio.h>
#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	float xmin = -3.14159;
	float ymin = -3.14159;
	float zmin = 0.0;
	
	float xmax = 3.14159;
	float ymax = 3.14159;
	float zmax = 6.28319;

	float x_offset, y_offset, z_offset;
	float x_spacing, y_spacing, z_spacing;

	int dims[3];
	dims[0] = 17;
	dims[1] = 17;
	dims[2] = 17;

	x_spacing = (xmax-xmin)/(dims[0]-1);
	y_spacing = (ymax-ymin)/(dims[1]-1);
	z_spacing = (zmax-zmin)/(dims[2]-1);

	x_offset = x_spacing/2.0;
	y_offset = y_spacing/2.0;
	z_offset = z_spacing/2.0;

	cout << "Offsets: " << x_offset << " " << y_offset << " " << z_offset << endl;
	cout << "Spacing: " << x_spacing << " " << y_spacing << " " << z_spacing << endl;

	ofstream seedfile;
	seedfile.open("TGV_Seeds.txt");

	float x,y,z;
	for(int i = 0; i < dims[0]-1; i++)
	{
		for(int j = 0; j < dims[1]-1; j++)
		{
			for(int k = 0; k < dims[2]-1; k++)
			{
				x = xmin + x_offset + i*x_spacing;
				y = ymin + y_offset + j*y_spacing;
				z = zmin + z_offset + k*z_spacing;

				seedfile << x << "\t" << y << "\t" << z << "\n";
			}
		}
	}	

	seedfile.close();
}

