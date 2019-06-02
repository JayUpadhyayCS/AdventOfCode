#include <iostream>
#include<fstream>
#include <vector>
#include <set>
#include <algorithm> 
using namespace std;
void load(ifstream&, set<int>&, int&, int&,bool&);
//void findDouble(vector<int>&, vector<int>&);
//void sort(vector<int>&);
int main()
{
	int counter=0;
	vector <int> twice;
	int x = 0;
	int vecSize;
	bool answer=false;
	ifstream infile;
	set <int> freq;
	infile.open("C:\\Users\\Jay\\Desktop\\day1.txt");
	//infile.open("C:\\Users\\Jay\\Desktop\\test.txt");
	//infile.open("C:\\Users\\student.CS\\Desktop\\day1.txt");
	//infile.open("C:\\Users\\student.CS\\Desktop\\test.txt");
	if (!infile)
	{
		cout << "Error opening file." << endl;
		exit(1);
	}
	freq.insert(x);

	load(infile, freq, x,counter, answer);// prime so i can find original size of vector
	//findDouble(freq, twice);
	//vecSize = freq.size();
	while (answer == false)
	{
		
		load(infile, freq,x,counter,answer);
		
		/*findDouble(freq,twice);
		if (4 * vecSize < freq.size())// Could make this bigger or smaller.Unsure.
		{
			freq.erase (freq.begin(), freq.begin()+vecSize);
		}
		if (twice.size() > 0)
		{
			answer = true;
		}
		*/
		
	}
//	sort(twice);
	infile.close();
}
void load(ifstream& infile, set<int>& freq, int& x,int& counter, bool& answer)
{
	
	int input;
	
	while (!infile.eof())
	{
		infile >> input;// Take input.
		x += input;// add input to frequency.
		if (!binary_search(freq.begin(),freq.end(),x))
			freq.insert(x);// put frequency in end of set
		else
		{
			cout << "Repeated frequency is " << x << "." << endl;
			answer = true;
		}
	}
	if (!infile)// Check for error??? What if file doesnthave integers or something. Doesn't seem to work right 
	{
		exit(3);
	}
	counter++;
	cout <<counter<<". "<< x << " is the frequency" << endl;
	infile.clear();
	infile.seekg(0, ios::beg);

}
/*void findDouble(vector<int>& freq, vector<int>& twice)
{
	for (int y = 0; y < freq.size(); y++)
	{
		for (int z = y + 1; z < freq.size(); z++)
		{
			if (freq.at(y) == freq.at(z))
			{
				twice.push_back(z);// saves the number which frequency is matched. Can compare second numbers to see which pair happened first.
				
			}
		}
	}
}
void sort(vector<int>& twice)
{
	int buffer = 0;
	for (int x = 0; x < (twice.size()-1); x++)// Must leave last number alone since previous number checks it.
	{
		if (twice.at(x) > twice.at(x + 1))
		{
			buffer = twice.at(x);
			twice.at(x) = twice.at(x + 1);
			twice.at(x + 1) = buffer;
			sort(twice);
		}
	}
}
*/