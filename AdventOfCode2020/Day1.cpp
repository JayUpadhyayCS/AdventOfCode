#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

int main()
{

	set<int> arr2;

	// 1,3,5,7,13,8,2
	// 20 7/8/5
	vector<int> arr;
	int test;
	int res;
	bool finished = false;
	ifstream infile;
	infile.open("input.txt");
	while (!infile.eof())
	{
		infile >> test;
		arr2.insert(test);
	}
	for (set<int>::iterator i = arr2.begin(); i != arr2.end(); i++)
	{
		int start = *i;
		for (int j = 1; j < (start / 2); j++)
		{

			if (arr2.find(j) != arr2.end() && arr2.find(2020-start-j) != arr2.end())
			{
				cout << j << " " << start << " " << 2020 - start - j << endl;
				cout << j + 2020 - start - j + start << endl;
				cout << j * (2020 - start - j) * start << endl;
				exit(1);
				//cout << j * 2020 - start + j * start << endl;
			}
		}
	}
	/*while (!infile.eof()&&!finished)
	{
		infile >> test;
		for (int i = 0; i < arr.size() &&!finished; i++)
		{
			if ((test  ==arr.at(i)))
			{
				cout << (2020-test) * arr.at(i);
				finished = true;
			}
		}
		arr.push_back(2020-test);

	}*/

}