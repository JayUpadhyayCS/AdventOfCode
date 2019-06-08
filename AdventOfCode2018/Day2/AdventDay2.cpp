#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <set>
#include <vector>
const int SIZE = 27;
using namespace std;
void part1(ifstream &);
void load(ifstream &, vector<string> &);
void part2(vector<string> &);

int main() 
{ 
	vector<string> inputs;
	ifstream infile;
	part1(infile);
	load(infile,inputs);
	part2(inputs);



	///Part 2 Let the punches roll
	

}
void part1(ifstream & infile)
{
	int tw = 0;
	int thr=0;
	int two = 0;
	int three = 0;
	char input[SIZE];
	int counter = 0;
	infile.open("C:\\Users\\Jay\\Desktop\\Advent2018\\AdventOfCode2018\\AdventOfCode2018\\Day2\\Input.txt");
	
	while (!infile.eof()) 
	{
		infile >> input;
		
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
	cout << "Math for part 1"<< endl;
	cout << tw << " " << thr << endl;
	cout << tw * thr << endl;
}
void load(ifstream &infile,vector<string> &inputs)
{	string word;

    infile.seekg(ios_base::beg);
	cout << "Put to beginning"<< endl;
	infile >> word;
	cout << word;
	while(!infile.eof())
	{
		inputs.push_back (word);
		infile >> word;
		cout << word;
	}
	cout << "Loaded." << endl;
	cout << inputs.at(1)<< endl;
	infile.close();
}
void part2(vector<string> &inputs)
{
	cout << "Aim" << endl;
	int vecSize=inputs.size();
	int counter=0;
	string solution,solution2;
	int sim=0;
	int maxsim=0;
	string test1;
	string test2;
	cout << "Reach"<< endl;
	cout << "Maybe" << endl;
	for(int x=0; x<(vecSize-1); x++)
	{
		test1=inputs.at(x);
		cout << "Here"<< endl;
		cout << test1<< endl;
		for(int y=x+1;y<vecSize;y++)
		{
			sim = 0;
			test2=inputs.at(y);

			for(int z=0; z<(SIZE-1); z++)// iterate through each letter
			{
				if (test1.at(z)==test2.at(z))
				{
					sim++;// Count amount of similarities in a comparisons
				}
			}
			cout << "Shoot" << endl;
			if(sim>maxsim)
			{
				solution=test1;//Find first line
				solution2=test2;// Math is shoddy
				maxsim=sim;
			}
			
		}
		
	}

	cout << solution << endl;

	cout << solution2<< endl;
	cout << maxsim << " similarities."<< endl;
	cout << "Fire!"<< endl;
	for(int z=0; z<SIZE-1; z++)// iterate through each letter
	{
		if (solution.at(z)==solution2.at(z))
		{
			cout << solution.at(z);// Count amount of similarities in a comparisons
		}
	}
	cout << endl<< "Fin";
}
