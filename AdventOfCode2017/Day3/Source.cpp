#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int arr[4];
	int x = 312051;
	int sqrtt;
	int initMid;
	int increm;
	int upperBound;
	int lowBound;
	int row;
	int low=10000;
	sqrtt = sqrt(x);
	if (sqrtt % 2 != 0)
	{
		upperBound = sqrtt + 2;
		lowBound = sqrtt;
	}
	else {
		upperBound = sqrtt + 1;
		lowBound = sqrtt - 1;
	}
	cout << lowBound << " to " << upperBound << endl;
	row = upperBound / 2;
	lowBound *= lowBound;
	upperBound *= upperBound;
	lowBound += 1;
	cout << lowBound << " to " << upperBound << endl;
	


	
	cout << row << endl;
	initMid = row - 1;
	increm = row * 2;
	arr[0] = lowBound  + initMid;
	arr[1] = arr[0] + increm;
	arr[2] = arr[1] + increm;
	arr[3] = arr[2] + increm;
	for (int i = 0; i < 4; i++)
	{
		if (low > abs(arr[i] - x))
			low = abs(arr[i] - x);

	}
	cout << low + row << "is the answer" << endl;
 
}

/*for (int i = 0; i < 10000; i++)
	{
		row = (2 * i) + 1;
		if (row >= sqrt(x))
		{
			row = i;
			break;
		}
	}*/