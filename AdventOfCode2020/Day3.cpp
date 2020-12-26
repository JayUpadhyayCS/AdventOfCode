#include <iostream>
#include <fstream>

using namespace std;
int trees(int position,int lines);
int main()
{
	cout << trees(1, 1) << endl;
	cout << trees(3, 1) << endl;
	cout << trees(5, 1) << endl;
	cout << trees(7, 1) << endl;
	cout << trees(1, 2) << endl;
	cout <<(unsigned int)(trees(1, 1) * trees(3, 1) * trees(5, 1) * trees(7, 1) * trees(1, 2)) << endl;
}
int trees(int increment, int lines)
{
	int position = 0;
	ifstream infile;
	string path;
	int counter = 0;
	infile.open("E:\\AdventOfCode\\AdventOfCode2020\\input1.txt");
	
	if (lines == 2)
	{
		infile >> path;
		//cout << path << endl;
		position = 1;
	}

	while (!infile.eof())
	{
		
		for(int i=0; i<lines; ++i)
		{
			infile >> path;
			/*if (lines == 2)
			{
				cout << path << endl;
			}*/
		}
		if (path[position] == '#')
		{
			counter++;
		}
		position += increment;
		if (position >= path.size())
		{
			position -= path.size();// might be 30
		}
	}
	infile.close();
	return counter;

}