#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int maxSize=1000;
int main()
{	char c;
	ifstream infile;
	infile.open("C:\\Users\\Jay\\Desktop\\Advent2018\\AdventOfCode2018\\AdventOfCode2018\\Day3\\input.txt");
	cout << "Heres"<< endl;
	int num1,num2,height,width,count;
	//int arr[maxSize][maxSize]={0};// Assign all to zero;
	vector<int> row;
	vector <vector<int>> col;
	for (int x = 0; x < maxSize; x++)
	{
		row.push_back(0);
	}
	for (int x = 0; x < maxSize; x++)
	{
		col.push_back(row);// Initialize a vector of vectors. Essentially 1000 rows of 1000 spaces.
	}

   
	while (!infile.eof())
	{
//#1 @ 265,241: 16x26
		infile >> c >> num1 >> c >> num1 >> c >> num2 >> c >> height >> c >> width;// Height and width are the last numbers. num1 and num2 are the coordinates of origin.
        if(!infile)
        {   
            cout << "Error" << endl;
            exit(3);
        }
		for(int x=0; x<height; x++)
		{
			for(int y=0;y<width;y++)
			{
				col.at(num1+x).at(num2+y)++;// Starts at origin and then traverses the row, then comes back to begin another row until all is filled.
			}
		}
	}
	cout << "Here"<< endl;
	count=0;
	for(int i=0; i<maxSize;i++)
	{
		for(int x=0; x<maxSize; x++)
		{
			if (col.at(i).at(x)>=2)
			{
			    count++;
            }
		}
	}
	cout << count<< " is number of overlapping claims."<< endl;
	infile.clear();
	infile.seekg(ios::beg);
	while (!infile.eof())
	{
		int number;
		bool found=true;

		//#1 @ 265,241: 16x26
		infile >> c >> number >> c >> num1 >> c >> num2 >> c >> height >> c >> width;// Height and width are the last numbers. num1 and num2 are the coordinates of origin.
		if (!infile)
		{
			cout << "Error" << endl;
			exit(3);
		}
		for (int x = 0; x < height; x++)
		{
			for (int y = 0; y < width; y++)
			{
				if (col.at(num1 + x).at(num2 + y) != 1)
				{
					found = false;
				}

			}
		}
		if (found == true)
		{
			cout << number << " is the answer" << endl;
		}
	}
}
