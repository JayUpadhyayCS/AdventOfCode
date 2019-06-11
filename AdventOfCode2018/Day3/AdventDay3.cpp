#include <iostream>
#include <fstream>
using namespace std;

const int maxSize=1000;
int main()
{	char c;
	ifstream infile;
	infile.open("C:\\Users\\Jay\\Desktop\\Advent2018\\AdventOfCode2018\\AdventOfCode2018\\Day3\\input.txt");
	cout << "Heres"<< endl;
	int num1,num2,height,width,count;
	int arr[maxSize][maxSize]={0};// Assign all to zero;
	string str;
    infile >> c>> num1>> c >> num1>>c>>num2>> c>> height>>c>> width;
	while (!infile.eof())
	{
//#1 @ 265,241: 16x26
		
        if(!infile)
        {   
            cout << "Error" << endl;
            exit(3);
        }
		for(int x=0; x<height; x++)
		{
			for(int y=0;y<width;y++)
			{
				arr[num1+x][num2+y]++;
			}
		}
        infile >> c>> num1>> c >> num1>>c>>num2>> c>> height>>c>> width;
	}
	cout << "Here"<< endl;
	count=0;
	for(int i=0; i<maxSize;i++)
	{
		for(int x=0; x<maxSize; x++)
		{
			if (arr[i][x]>=2)
			{
			    count++;
            }
		}
	}
	cout << count<< " is number of overlapping claims."<< endl;

}
