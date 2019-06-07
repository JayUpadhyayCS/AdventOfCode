#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <set>
#include <vector>
const int SIZE = 7;
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
	infile.open("C:\\Users\\Jay\\Desktop\\Advent2018\\AdventOfCode2018\\AdventOfCode2018\\Day2\\TestInput.txt");
	
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
	while(infile.eof())
	{
		inputs.push_back(word);
		infile>> word;
	}
	cout << "Loaded." << endl;
	infile.close();
}
void part2(vector<string> &inputs)
{
	cout << "Aim" << endl;
	int vecSize=inputs.size();
	int counter=0;

	int sim=0;
	int maxsim=0;
	string test1;
	string test2;
	cout << "Reach"<< endl;
	
	vector<string>::iterator it=inputs.begin();
	vector<string>::iterator it2=inputs.begin();
	vector<string>::iterator save;
	vector<string>::iterator save2;
	it2++;
	cout << "Maybe" << endl;
	while(it!=inputs.end())
	{
		counter++;
		it2=inputs.begin();
		advance(it2,counter);
		
		test1=*it;// Error here...
		cout << "Here"<< endl;
		cout << test1<< endl;
		while(it2!=inputs.end())
		{
			
			test2=(*it2);
			for(int x=0; x<SIZE; x++)// iterate through each letter
			{
				if (test1.at(x)==test2.at(x))
				{
					sim++;// Count amount of similarities in a comparisons
				}
			}
			cout << "Shoot" << endl;
			if(sim>maxsim)
			{
				save=it;//Find first line
				save2=it2;// Math is shoddy
				maxsim=sim;
			}
			it2++;
		}
		it++;
	}

	cout << (*save)<< endl;

	cout << (*save2)<< endl;
	cout << maxsim << "similarities."<< endl;
	cout << "Fire!"<< endl;
}
