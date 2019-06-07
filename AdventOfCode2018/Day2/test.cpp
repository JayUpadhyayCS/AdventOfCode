#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string test;
    ifstream infile;
    infile.open("C:\\Users\\Jay\\Desktop\\Advent2018\\AdventOfCode2018\\AdventOfCode2018\\Day2\\TestInput.txt");
    infile >> test;
    cout << test << endl;
    infile.seekg(ios_base::beg);
    infile >> test;
    cout << test << endl;
}