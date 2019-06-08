#include <iostream>
#include <fstream>
using namespace std;

const int maxSize=1000;
int main()
{	char c;
	ifstream infile;
	
	int num1,num2,height,width,count;
	array int [maxSize][maxSize]={0};// Assign all to zero;
	string str;
	while (!infile.eof())
	{
		getline(infile,str);
//#1 @ 265,241: 16x26
		infile >> c>> num1<< c << num1<<c<<num2<< c<< height<< width;
		for(x=0; x<height; x++)
		{
			for(y=0;y<width;y++)
			{
				arr[num1+x][num2+y]++;
			}
		}
	}
	
	count=0;
	for(int i=0; i<maxSize;i++)
	{
		for(int x=0; x<maxSize; x++)
		{
			if (arr[i][x]>=2)
			{
			 count++
			{
		}
	}
	cout << count<< " is number of overlapping claims."<< endl;

}
