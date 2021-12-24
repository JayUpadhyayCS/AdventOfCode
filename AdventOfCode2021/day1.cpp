#include <iostream>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	ifstream infile;

	int counter = 0;
	int input=9999999;
	int input2;
	infile.open("D:\\AdventOfCode\\AdventOfCode2021\\day1.txt");
	if (!infile)// Check for error??? What if file doesnthave integers or something. Doesn't seem to work right 
	{
		exit(3);
	}
	infile >> input >> input2;
	while (!infile.eof())
	{
		if (input2 > input)
		{
			counter++;
		}
		input = input2;
		infile >> input2;
		

	}
	cout << counter << endl;



}