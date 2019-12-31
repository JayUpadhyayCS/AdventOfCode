#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
	class Shift{
	public:
		int super;
		int time;
		string action;
		void Super(int month, int day, int time1, int time2);
	};
	class Guard {
		int ID;
		int sleep;

	};
	void swapOb(vector<Shift> &arr, int one, int two)
	{
		Shift buffer;
		buffer = arr.at(one);
		arr.at(one) = arr.at(two);
		arr.at(two) = buffer;
	}
	int partions(vector<Shift>& shiftVec, int left, int right)
	{
		int pivot = shiftVec.at((left + right) / 2).super;
		while (left <= right)
		{
			while (shiftVec.at(left).super < pivot)
			{
				left++;
			}
			while (shiftVec.at(right).super > pivot)
			{
				right--;
			}
			if (left <= right)
			{
				swapOb(shiftVec, left, right);
				right--;
				left++;
			}

		}
		return left;// left and right are equal, essentially index of pivot?
	}
	void quickSort(vector<Shift>& shiftVec, int left, int right)
	{
		if (left >= right)
		{
			return;
		}
		int index = partions(shiftVec, left, right);
		quickSort(shiftVec, left, index - 1);// Excluding index so it doesnt overlapping);
		quickSort(shiftVec, index, right);
	
	}
	int main()
	{
		std::ifstream ifs("D:\\AdventTest\\Day4\\input.txt"); std::vector<std::string> lines;
		for (std::string l; std::getline(ifs, l);) { lines.push_back(l); }
		sort(lines.begin(), lines.end());
		for (int x = 0; x < lines.size(); x++)
		{
			cout << lines.at(x) << endl;
		}
		exit(3);
		Shift buffer;
		int month;
		int day;
		char trash;
		int time1;
		int time2;
		ifstream infile;
		int superNum;
		infile.open("D:\\AdventTest\\Day4\\input.txt");
		if (!infile)
		{
			cout << "Error" << endl;
		}
		vector<Shift> shiftVec;
		while (!infile.eof())
		{
			infile >> trash >> month >> trash >> month >> trash >> day >> time1 >> trash >> time2 >> trash;
			getline(infile, buffer.action);
			buffer.Super(month, day, time1, time2);
			buffer.time = buffer.super % 10000;
			// << buffer.super << endl << buffer.action << endl << buffer.time << endl;
			shiftVec.push_back(buffer);

		}
		quickSort(shiftVec, 0, shiftVec.size() - 1);
		for (int x = 0; x < shiftVec.size(); x++)
		{
			cout << shiftVec.at(x).super << "   " << shiftVec.at(x).action <<endl;
		}
	
		vector<Guard> list;
		// Find action for sleep, record time until wakes up. Compare time to highest time and replace if needed. Make sure to save indexes of when they began and ended their sleep.
		// Go to index they began their sleep and backtrack until you find their #
		// Multiply their number by the amount of time they were asleep.
		// Win game and at life. 
	}	

	void Shift::Super(int month, int day, int time1, int time2)
	{
		this->super= ((month * 1000000) + (day * 10000) + (time1 * 100) + time2);
	}