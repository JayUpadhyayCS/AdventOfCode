#include <iostream>
#include<fstream>

using namespace std;

int main()
{
	int counter=0;
	int counter2 = 0;
	int arr[16];
	int high;
	int low;
	double check;
	ifstream infile;
	infile.open("D:\\AdventOfCode\\AdventOfCode2017\\Day2\\Day2\\input.txt");
	if (!infile)
	{
		cout << "Terrible error" << endl;
		exit(2);
	}
	while (!infile.eof())
	{
		infile >> arr[0];
		high = arr[0];
		low = arr[0];
		for (int x = 1; x < 16; x++)
		{	
			infile >> arr[x];
			if (arr[x] > high)
			{
				high = arr[x];
			}
			if (arr[x] < low)
			{
				low = arr[x];
			}
			
			
		}
		// solution for part 2
		for (int x = 0; x < 15; x++)
		{
			for (int i = x+1; i < 16; i++)
			{
				if (arr[x] > arr[i])
				{
					if (arr[x] % arr[i] == 0)
					{
						counter2 += arr[x] / arr[i];
					}
				}
				else {
					if (arr[i] % arr[x] == 0)
					{
						counter2 += arr[i] / arr[x];
					}
				}
			}
		}

		counter += (high - low);
	}
	cout << counter << endl;
	cout << counter2 << endl;
	cout << 5 % 3 << endl;


	
}