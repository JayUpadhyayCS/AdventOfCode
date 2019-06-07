#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <set>

const int SIZE = 7;
using namespace std;
void part1(ifstream &);
void load(ifstream &, set<string> &);
void part2(set<string> &);
/*struct node
{
	struct node *child[27];
	bool isWord=false;
	int counter=0;
	data 
};
*/
int main() 
{ 
	set<string> inputs;
	ifstream infile;
	part1(infile);
	load(infile,inputs);
	part2(inputs);



	///Part 2 Let the punches roll
	
	char input [SIZE];
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
void load(ifstream &infile,set<string> &inputs)
{	string word;

    infile.seekg(ios_base::beg);
	cout << "Put to beginning"<< endl;
	infile >> word;
	cout << word << endl;
	while(infile.eof())
	{
		inputs.insert(word);
		infile>> word;
	}
	cout << "Loaded." << endl;
	infile.close();
}
void part2(set<string> &inputs)
{
	cout << "Aim" << endl;
	int count=0;
	int counter=0;
	int target1=0;
	int target2=1;
	int sim=0;
	int maxsim=0;
	string test1;
	string test2;
	set<string>::iterator it=inputs.begin();
	while(it!=inputs.end())
	{
		counter++;
		test1=(*it);
		while(it!=inputs.end())
		{
			it++;
			test2=(*it);
			count++;
			for(int x=0; x<SIZE; x++)// iterate through each letter
			{
				if (test1.at(x)==test2.at(x))
				{
					sim++;// Count amount of similarities in a comparisons
				}
			}
			if(sim>maxsim)
			{
				target1=counter-1;//Find first line
				target2=counter+count-1;// Math is shoddy
				maxsim=sim;
			}
		}

		it=inputs.begin();
		advance(it,counter);
	}
	it=inputs.begin();
	advance(it,target1);
	cout << (*it)<< endl;
	it=inputs.begin();
	advance(it,target2);
	cout << (*it)<< endl;
	cout << maxsim << "similarities."<< endl;
	cout << "Fire!"<< endl;
}

	/*node *trav;// initialize moving pointer
	
	char input[SIZE];
	node tree;// Initialize tree
	infile.beg;
	while (infile.eof())
	{
		infile >>input;
		trav=&tree;// Pointer to tree.
		for(int x; x<SIZE;x++)
		{
			trav->child[input[x]-141];
			trav->isWord=true;
			trav->counter++;

		}
	}
	*/