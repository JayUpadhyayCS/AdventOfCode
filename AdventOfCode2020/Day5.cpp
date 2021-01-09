#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int BinarySearch(string &input, int lowRange, int highRange);
int BinarySearch2(string& input, int lowRange, int highRange);
int main()
{
	bool arr[128][8] = { false };
	int row, column, high = 0;
	string input;
	ifstream infile;
	int counter = 0;
	infile.open("E:\\AdventOfCode\\AdventOfCode2020\\Day5.txt");
	while (!infile.eof())
	{
		getline(infile, input);
		counter++;
		row = BinarySearch(input, 0, 127);
		column = BinarySearch2(input, 0, 7);
		arr[row][column] = true;
		if (high < (row * 8 + column))
			high = row * 8 + column;
	}
	for (int x = 1; x < 7; x++)
	{
		for (int j = 0; j < 128; j++)
		{
			if (!arr[j][x] && arr[j][x-1]&&arr[j][x + 1])
			{
				cout << j * 8 + x << endl;
			}
		}
	}


}
int BinarySearch(string &input, int lowRange, int highRange) {
	if (input.empty())
		return 0;
	else if (input[0] == 'L' || input[0] == 'R')
		return lowRange;
	else if((input[0] == 'F') || (input[0] == 'B'))
	{
		if (input[0] == 'F')// lower half
		{
			input.erase(input.begin());
			
			// 0-127--> 0,63
			// 44-45-->44
			// 
			return BinarySearch(input, lowRange, (highRange + lowRange)/2);
		}
		else if (input[0] == 'B')// higher half
		{
			// 0-63--> 32,63
			// 44-45-->45,45
			input.erase(input.begin());
			return BinarySearch(input, ((highRange+1 +lowRange) / 2), highRange);
		}
	}
}
int BinarySearch2(string& input, int lowRange, int highRange) {
	if (input.empty())
		return lowRange;
	if (input[0] == 'L')// lower half
	{
		input.erase(input.begin());

			// 0-127--> 0,63
			// 44-45-->44
			// 
		return BinarySearch2(input, lowRange, (highRange + lowRange) / 2);
	}
	else if (input[0] == 'R')// higher half
	{
			// 0-63--> 32,63
			// 44-45-->45,45
			input.erase(input.begin());
			return BinarySearch2(input, ((highRange + 1 + lowRange) / 2), highRange);// could cause error
	}
	
}