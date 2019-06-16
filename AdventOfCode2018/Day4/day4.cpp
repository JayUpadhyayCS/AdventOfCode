#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
struct datas
{
	//[1518 - 05 - 12 00:39] wakes up
	int day;
	int month;
	int time;
	string action;
	// char,num, char, num,char num, num char num
};
int combine(int a, int b);
void bub2 (vector<vector<datas>>&,datas);

int main()
{
	vector<vector<datas>> arr;
	vector<datas> dat;
	for (int x = 0; x < 12; x++)
	{
		arr.push_back(dat);
	}
	int a, b;
	char trash;
	datas buffer;
	//vector<datas> arr[12];

	ifstream infile;
	infile.open("C:\\Users\\Jay\\Desktop\\Advent2018\\AdventOfCode2018\\AdventOfCode2018\\Day4\\input.txt");
	if (!infile)
	{
		cout << "ERROR opening infile" << endl;
		exit(2);
	}
	while (!infile.eof())
	{
		infile >> trash >> buffer.day >> trash >> buffer.month >> trash >> buffer.day;
		infile >> a >> trash >> b >> trash;
		buffer.time = combine(a, b);
		getline(infile, buffer.action);
		arr.at(buffer.month - 1).push_back(buffer);
	}
	infile.close();

	cout << "Finished sorting month." << endl;
	int max=0;
	int yval2;
	int counter=0;
	pair<int, int> coord;
	int yval;
	bub2(arr, buffer);
	cout << "Finished sorting day" << endl;
	cout << "Finished sorting time" << endl;
	cout << arr[10].at(arr[10].size() - 1).action << endl;

	string hold;
	// Need to find amount of time each guard is sleeping.
	for (int x = 0; x < 12; x++)
	{
		if (arr.at(x).size() == 0 || arr.at(x).size() == 1)
		{
			cout << "Empty Month" << endl;
		}
		else 
		{
			for (int y = 0; y < arr.at(x).size(); y++)
			{

				if (arr.at(x).at(y).action == " falls asleep")
				{
					coord.first = x;
					coord.second = y;
					yval = arr.at(x).at(y).time;
					while (arr.at(x).at(y).action != " wakes up")
					{
						y++;
						if (y == arr.at(x).size()-1)
						{
							x++;
							y = 0;
						}
					}
					yval2 = arr.at(x).at(y).time;
					if (yval < 60 && yval2< 60)
					{
						if (max < (yval2 - yval))
						{
							max = yval2 - yval;

							int countx=0;
							int placeholder = coord.second;
							while (arr.at(coord.first-countx).at(coord.second-counter).action == " falls asleep" || arr.at(coord.first).at(coord.second-counter).action == " wakes up")// what if goon is previous month.
							{
								counter++;
								if (coord.second - counter == -1)// CHANGED FROM NEG 1
								{
									coord.second = arr.at(coord.first - countx).size();
									countx = 1;
									counter = 0;
								}
								
							}
							hold = arr.at(coord.first - countx).at(coord.second - counter).action;
							coord.second = placeholder;


						}
						// need to find out which guard goes to sleep and store the data.
					}
					else 
					{
						if (max < (2360 - yval) + yval2)
						{
							max = (2360 - yval) + yval2;
							y = y - counter;
							counter = 0;
							int countx = 0;
							int placeholder = coord.second;
							while (arr.at(coord.first - countx).at(coord.second - counter).action == " falls asleep" || arr.at(coord.first).at(coord.second - counter).action == " wakes up")// what if goon is previous month.
							{
								counter++;
								if (coord.second - counter == -1)
								{
									coord.second = arr.at(coord.first - countx).size();
									countx = 1;
									counter = 0;
								}

							}
							hold = arr.at(coord.first - countx).at(coord.second - counter).action;
							coord.second = placeholder;
						}
					}

				}
			}
		}
	}
	cout << max << endl << hold << endl;
}
int combine(int a, int b)
{// check this funciton

	if (a==0)
	{
		return b;
	}
	if (a==23)
	{
		return 2300+b;
	}
	cout << "Error with combine function"<< endl;
	return 0;

}


void bub2(vector<vector<datas>>&arr,datas buffer)
{
	bool clean = false;
	while (clean == false)
	{
		clean = true;
		for (int x = 0; x < 12; x++)
		{
			if (arr.at(x).size() == 0 || arr.at(x).size() == 1)
			{
				cout << "Empty Month" << endl;
			}
			else
			{
				for (int y = 0; y < arr.at(x).size() - 1; y++)
				{

					if (arr.at(x).at(y).day > arr.at(x).at(y + 1).day)
					{

						buffer = arr.at(x).at(y);
						arr.at(x).at(y) = arr.at(x).at(y + 1);
						arr.at(x).at(y + 1) = buffer;
						clean = false;

					}
					if (arr.at(x).at(y).day == (arr.at(x).at(y + 1).day))
					{
						if (arr.at(x).at(y).time > arr.at(x).at(y + 1).time)
						{
							buffer = arr.at(x).at(y);
							arr.at(x).at(y) = arr.at(x).at(y + 1);
							arr.at(x).at(y + 1) = buffer;
							clean = false;

						}
					}

				}
			}
		}
	}

}
