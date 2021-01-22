#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
// how many unique yesses
void funct1();
int main()
{
	int counter = 0;
	int persons=0;
	string input;
	map<char,int> dict;

	ifstream infile;
	infile.open("E:\\AdventOfCode\\AdventOfCode2020\\Day6.txt");
	// get line
	// go character by character
	// repeat until line is empty
	getline(infile, input);
	persons++;
	for (int x = 0; x < input.size(); x++)
	{
		dict.insert({ input[x], 1 });
	}
	while (!infile.eof())
	{
		getline(infile, input);
		persons++;
		if (input == "")
		{
			persons--;
			for (auto m : dict)
			{
				if (m.second == persons)
					counter++;
			}
			dict.clear();
			persons = 0;
			getline(infile, input);
			persons++;
			for (int x = 0; x < input.size(); x++)
			{
				dict.insert({ input[x], 1 });
			}
		}
		else {
			for (int x = 0; x < input.size(); x++)
			{
				if (dict.find(input[x]) != dict.end())
				{
					dict[input[x]]++;
				}

			}
		}
		
		
		
	}
	for (auto m : dict)
	{
		if (m.second == persons)
			counter++;
	}
	cout << counter;

	
}
void funct1()
{
	int counter = 0;
	string input;
	map<char, bool> dict;

	ifstream infile;
	infile.open("E:\\AdventOfCode\\AdventOfCode2020\\Day6.txt");
	// get line
	// go character by character
	// repeat until line is empty
	while (!infile.eof())
	{
		getline(infile, input);
		if (input == "")
		{
			counter += dict.size();
			dict.clear();
		}
		for (int x = 0; x < input.size(); x++)
		{
			dict.insert({ input[x], true });
		}

	}
	counter += dict.size();
	dict.clear();

	cout << counter;
}


