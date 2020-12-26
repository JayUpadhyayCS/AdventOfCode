#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
iyr:2015 cid:189 ecl:oth byr:1947 hcl:#6c4ab1 eyr:2026
hgt:174cm
pid:526744288*/
int main()
{
	bool ecl, pid, eyr, hcl, byr, iyr, cid, hgt=false;
	ecl = pid = eyr = hcl = byr = iyr = cid = hgt = false;
	ifstream infile;
	string input;
	string temp;
	int counter = 0;
	infile.open("E:\\AdventOfCode\\AdventOfCode2020\\input1.txt");
	//temp.clear();
	//getline(infile, input);
	while (!infile.eof())
	{
		temp.clear();
		getline(infile, input);
		if (!input.size())
		{
			ecl = pid = eyr = hcl = byr = iyr = cid = hgt = false;
		}
		while (input.size())
		{

			temp.clear();
			if (input[0] == 'e' && input[1] == 'y' && input[2] == 'r')
			{
				temp.clear();
				eyr = true;
				input.erase(0,4);
				while (input[0] != ' '&& input.size())
				{
					temp.push_back(input[0]);
					input.erase(input.begin());
				}
				if (input.size())
				{
					input.erase(input.begin());
				}
				if (temp.size() != 4 || (stoi(temp) < 2020 || stoi(temp) > 2030))
				{
					eyr = false;
					//cout << stoi(temp);
				}
				else
				{
					//cout << temp << endl;
				}
				//cout << stoi(temp);
			}
			else if (input[0] == 'i' && input[1] == 'y' && input[2] == 'r')
			{
				temp.clear();
				iyr = true;
				input.erase(0, 4);
				while (input[0] != ' ' && input.size())
				{
					temp.push_back(input[0]);
					input.erase(input.begin());
				}
				if (input.size())
				{
					input.erase(input.begin());
				}
				if (temp.size() != 4 || (stoi(temp) < 2010 || stoi(temp) > 2020))
				{
					iyr = false;
					//cout << stoi(temp);
				}
				else
				{
					//cout << temp << endl;
				}
			}
			else if (input[0] == 'e' && input[1] == 'c' && input[2] == 'l')
			{

				temp.clear();

				if (ecl)
				{
					ecl = false;
				}
				else
				{


					ecl = true;
				}
				input.erase(0, 4);
				while (input[0] != ' ' && input.size())
				{
					temp.push_back(input[0]);
					input.erase(input.begin());
				}
				if (input.size())
				{
					input.erase(input.begin());
				}
				if (temp.size() != 3 || (temp != "amb" && temp != "blu" && temp != "brn" && temp != "gry" && temp != "grn" && temp != "hzl" && temp != "oth"))
				{
					ecl = false;
				}
				else
				{
					//cout << temp << endl;
				}
			}
			else if ((input[0] == 'p' && input[1] == 'i' && input[2] == 'd'))
			{
				temp.clear();
				pid = true;
				input.erase(0, 4);
				while (input[0] != ' ' && input.size())
				{
					temp.push_back(input[0]);
					input.erase(input.begin());
				}
				if (input.size())
				{
					input.erase(input.begin());
				}
				if (temp.size() != 9)
				{
					pid = false;
				}
				else
				{
					for (int i = 0; i < temp.size(); i++)
					{
						if (temp[i] >= '0' && temp[i] <= '9')
						{

						}
						else
						{

							pid = false;
						}
					}
				}
				if (pid)
				{
					//cout << temp << endl;
				}
			}
			else if ((input[0] == 'h' && input[1] == 'c' && input[2] == 'l'))
			{
				hcl = true;
				input.erase(0, 4);
				while (input[0] != ' ' && input.size())
				{
					temp.push_back(input[0]);
					input.erase(input.begin());
				}
				if (input.size())
				{
					input.erase(input.begin());
				}
				if (temp[0] != '#')
				{
					hcl = false;
					//cout << temp << endl;
				}
				else
				{
					temp.erase(temp.begin());
				}
				if (temp.size()!=6)
				{
					
					hcl = false;
				}
				else
				{
					for (int i = 0; i < temp.size(); i++)
					{
						if ((temp[i] >= '0' && temp[i] <='9') || (temp[i] >= 'a' && temp[i]<='f'))
						{
//							cout << "Within parameters" << endl;
						}
						else
						{
							hcl = false;
						}
					}
				}
				if (hcl)
				{
					//cout << temp << endl;
				}
			}
			else if ((input[0] == 'b' && input[1] == 'y' && input[2] == 'r'))
			{
				byr = true;
				input.erase(0, 4);
				while (input[0] != ' ' && input.size())
				{
					temp.push_back(input[0]);
					input.erase(input.begin());
				}
				if (input.size())
				{
					input.erase(input.begin());
				}
				if (temp.size() != 4 || (stoi(temp) < 1920 || stoi(temp) > 2002))
				{
					byr = false;
					//cout << stoi(temp);
				}
				//else
					//cout << temp << endl;
			}
			else if ((input[0] == 'c' && input[1] == 'i' && input[2] == 'd'))
			{
				cid = true;
				input.erase(0, 4);
				while (input[0] != ' ' && input.size())
				{
					temp.push_back(input[0]);
					input.erase(input.begin());
				}
				if (input.size())
				{
					input.erase(input.begin());
				}
			}
			else if ((input[0] == 'h' && input[1] == 'g' && input[2] == 't'))
			{
			//hgt:174cm
				hgt = true;
				input.erase(0, 4);
				while (input[0] != ' ' && input.size())
				{
					temp.push_back(input[0]);
					input.erase(input.begin());
				}
				if (input.size())
				{
					input.erase(input.begin());// to delete the space
				}
				if (temp[temp.size() - 1] == 'm' && temp[temp.size() - 2] == 'c')
				{
					temp.erase(temp.size() - 2, 2);
					if (stoi(temp) < 150 || stoi(temp) > 193)
					{
						hgt = false;
					}
				}
				else if (temp[temp.size() - 1] == 'n' && temp[temp.size() - 2] == 'i')
				{
					temp.erase(temp.size() - 2, 2);
					if (stoi(temp) < 59 || stoi(temp) > 76)
					{
						hgt = false;
					}
				}
				else
					hgt = false;
				if (hgt)
				{
					cout << temp << endl;
				}
			}
		}

			
			if (ecl && pid && eyr && hcl && byr && iyr && hgt)
			{
				counter++;
				ecl = pid = eyr = hcl = byr = iyr = cid = hgt = false;
				temp.clear();
				input.clear();
			}
			// dont run following loop

		//temp.clear();
		//getline(infile, input);
		
	}
	/*if (ecl && pid && eyr && hcl && byr && iyr && hgt)
	{
		counter++;
	}*/
	cout << counter << endl;
}
