#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	int lowBound, highBound;
	char letter, trash;
	string input;
	ifstream infile;
	infile.open("input.txt");
	int valid = 0;
	while (!infile.eof())
	{
	
		//6-7 z: dqzzzjbzz
		//13 - 16 j: jjjvjmjjkjjjjjjj
		//int counter = 0;
		infile >> lowBound  >> trash >> highBound >>  letter >> trash >> input;
		//cout << lowBound << " " << highBound <<" " <<letter << " "<< input;
		if ((input[lowBound-1] == letter) ^ (input[highBound-1] == letter))
		{
			valid++;
		}
	}
	cout << valid;
}

/*for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == letter)
			{
				counter++;
			}
		}
		if (counter >= lowBound && counter <= highBound)
		{
			valid++;
		}*/

