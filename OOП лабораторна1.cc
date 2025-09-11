#include <iostream>
#include <math.h>

using namespace std;

float funcB(float x,float y,float z)
{
	return 1 + pow(abs(y - x), 2.) / pow(abs(z - 1), 1.34) + pow(z - x, 2.) / pow(sin(z), 2.) + pow(abs(y - z), 2.) / cos(pow(y, 2.));
}

float funcA(float x, float y, float z,float B)
{
	return pow(x + y, 2.) + x + pow(z, 3.) / pow(pow(B, 2.) + y, 2.) / 1 + exp(-(x - y)) + pow(abs(z), 0.34);
}

int main()
{
	float x = 0.48 * 3, y = 0.47 * 3, z = 1.32 * 3;

		float B = funcB(x, y, z);
		float A = funcA(x, y, z, B);

		cout << "\t\ttask 1" << endl;
		cout << "FuncA=" << A << "\t" << "FuncB=" << B << endl;
		cout << "\n\n\n";


		for (float x_tab = -1; x_tab <= 1; x_tab += 0.2)
		{
			float B_tab = funcB(x_tab, y, z);
			float A_tab = funcA(x_tab, y, z, B_tab);

				cout << "x=" << x_tab << "\tB="<<B_tab<<"\tA="<<A_tab << endl;
		}
		
	
	return 0;
}


