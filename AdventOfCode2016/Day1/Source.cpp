#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
void sumDir(char letter, int num, char& cardinal, int& north, int& south, int& west, int& east, int &x, int &y, bool arr[700][700]);
int main()
{
	bool arr[700][700]={0};
	int north = 0;
	int south = 0;
	int west = 0;
	int east = 0;
	int x = 350;
	int y=350;
	char cardinal = 'N';
	int num;
	char trash;
	char letter;
	ifstream infile;
	infile.open("D:\\AdventOfCode\\AdventOfCode2016\\Day1\\input.txt");
	if (!infile)
	{
		cout << "Error opening" << endl;

	}
	while (!infile.eof())
	{
		infile >> letter >> num>> trash;
		cout << letter << num << endl;
		sumDir(letter, num, cardinal, north, south, west, east,x,y,arr);
	}
	cout << north << " " << west << " " << south << " " << east << endl;
	cout << north - south << endl << east - west << endl;

}
void sumDir(char letter, int num, char& cardinal, int &north, int &south , int &west , int& east,int &x, int &y,bool arr[700][700])
{
	if (cardinal == 'N')
	{
		if (letter == 'L')
		{
			west= west + num;
			cardinal = 'W';
			for (int a = 0; a < num; a++)
			{
				if (arr[x - a][y] == 1)
				{
					cout << x - a - 350 << endl;
					cout << y - 350 << endl;
					exit(5);
				}
				arr[x - a][y] = 1;
			}
			x -= num;
			
		}
		else {
			east = east + num;
			cardinal = 'E';
			for (int a = 0; a < num; a++)
			{
				if (arr[x + a][y] == 1)
				{
					cout << x + a - 350 << endl;
					cout << y - 350 << endl;
					exit(5);
				}
				arr[x + a][y] = 1;
			}
			x += num;
		}
	}
	else if (cardinal == 'S')
	{
		if (letter == 'R')
		{
			west = west + num;
			cardinal = 'W';
			for (int a = 0; a < num; a++)
			{
				if (arr[x - a][y] == 1)
				{
					cout << x - a - 350 << endl;
					cout << y - 350 << endl;
					exit(5);
				}
				arr[x - a][y] = 1;
			}
			x -= num;
		}
		else {
			east = east + num;
			cardinal = 'E';
			for (int a = 0; a < num; a++)
			{
				if (arr[x+a][y] == 1)
				{
					cout << x+a -350<< endl;
					cout << y - 350 << endl;
					exit(5);
				}
				arr[x + a][y] = 1;
			}
			x += num;
		}
	}
	else if (cardinal == 'W')
	{
		if (letter == 'R')
		{
			north = north + num;
			cardinal = 'N';
			for (int a = 0; a < num; a++)
			{
				if (arr[x][y + a] == 1)
				{
					cout << x-350 << endl;
					cout << y + a - 350 << endl;
					exit(5);
				}
				arr[x][y+a] = 1;
			}
			y += num;
		}
		else {
			south = south + num;
			cardinal = 'S';
			for (int a = 0; a < num; a++)
			{
				
				if (arr[x][y - a] == 1)
				{
					cout << x -350<< endl;
					cout << y - a - 350 << endl;
					exit(5);
				}
				arr[x][y - a] = 1;
			}
			y -= num;
		}
	}
	else if (cardinal == 'E')
	{
		if (letter == 'L')
		{
			north = north + num;
			cardinal = 'N';
			for (int a = 0; a < num; a++)
			{
				if (arr[x][y + a] == 1)
				{
					cout << x -350<< endl;
					cout << y + a - 350 << endl;
					exit(5);
				}
				arr[x][y + a] = 1;

			}
			y += num;
		}
		else {
			south = south + num;
			cardinal = 'S';
			for (int a = 0; a < num; a++)
			{
				if (arr[x][y - a] == 1)
				{
					cout << x-350 << endl;
					cout << y - a - 350 << endl;
					exit(5);
				}
				arr[x][y - a] = 1;
			}
			y -= num;
		}
	}
	else
	{
		cout << "Error2" << endl;
		cout << letter << num << " " << cardinal << endl;
	}
}