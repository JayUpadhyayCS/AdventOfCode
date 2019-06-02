#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
const int SIZE = 27;
using namespace std;
int main() 
{ 
	int tw = 0;
	int thr=0;
	int two = 0;
	int three = 0;
	char input[SIZE];
	ifstream infile;
	infile.open("C:\\Users\\Jay\\Desktop\\Advent2018\\AdventOfCode2018\\AdventOfCode2018\\Day2\\Input.txt");
	
	while (!infile.eof()) 
	{
		infile >> input;
		int counter = 0;
		for (int x = 0; x < SIZE; x++)
		{
			for (int y =x+1; y < SIZE; y++)
			{
				if (input[x] != '/')
				{
					if (input[x] == input[y])
					{
						input[y] = '/';
						counter++;
					}


				}
			}
			if (counter == 1)
			{
				counter = 0;
				two = 1;
			}
			else if (counter == 2)
			{
				counter = 0;
				three = 1;
			}
		}
		tw += two;
		thr += three;
		two = 0;
		three = 0;
		
		
	}
	
	cout << tw << " " << thr << endl;
	cout << tw * thr << endl;
}
