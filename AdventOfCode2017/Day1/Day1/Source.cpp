#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	char digit;
	int num1;
	

	int total=0;
	vector<int> list;
	ifstream infile;
	infile.open("D:\\AdventOfCode\\AdventOfCode2017\\Day1\\Day1\\input.txt");
	if (!infile)
	{
		cout << "Error opening" << endl;
		exit(1);
	}

	infile >> digit;
	num1 = digit - '0';
	while (!infile.eof())
	{
		list.push_back(num1);
		infile >> digit;
		num1 = digit - '0';
		

	}

	int next = (list.size() / 2);
	for (int x = 0; x < list.size(); x++)
	{
		if (x + next >= list.size())
		{
			next = 0 - x;
		}

		if (list.at(x) == list.at(x+next))
		{
			total += list.at(x);
		}
	}
	cout << total;
}