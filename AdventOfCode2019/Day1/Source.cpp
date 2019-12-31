#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream infile;
	infile.open("C:\\Users\\jupad\\OneDrive\\Desktop\\input.txt");
	if (!infile)
	{
		cout << "Fuck" << endl;
		exit(1);
	}
	
	int temp;
	int total=0;

	while (!infile.eof())
	{
		infile >> temp;
		temp = (temp / 3) - 2;
		while (temp > 0)
		{
			
			total += temp;
			temp = (temp / 3) - 2;
		}
	}
	cout << total;
}