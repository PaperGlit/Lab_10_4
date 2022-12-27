#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CreateTXT(char* fname) 
{
	ofstream fout(fname, ios_base::app);
	char ch; 
	string s;
	cin.get();
	cin.sync();
	cout << "Enter line : "; getline(cin, s);
	fout << s << endl;
	cout << endl;
}

void PrintTXT(char* fname)
{
	ifstream fin(fname);
	string s;
	while (getline(fin, s))
	{
		cout << s << endl;
	}
	cout << endl;
}

void ProcessTXT(char* fname, char* gname, string search)
{
	string s;
	ofstream g(gname);
	ifstream f(fname);
	int k = 0;
	while (getline(f, s))
		if (s.find(search) != string::npos)
		{
			k++;
			g << s << endl;
		}	
	g << "Lines found : " << k << endl;
}

int main()
{
	int response;
	string search;
	char fname[255];
	char gname[255];
	char yorn;
	cout << "Enter filename : "; cin >> fname;
	do {
		cout << "1 - Enter a new line; 2 - Search : "; cin >> response;
		if (response == 1)
			CreateTXT(fname);
		else if (response == 2)
		{
			cout << "Enter filename 2 : "; cin >> gname;
			cout << "Enter a line to search : "; cin >> search;
			ProcessTXT(fname, gname, search);
			PrintTXT(gname);
		}
		else
			cout << "Wrong input, please try again" << endl;
		cout << "Continue? (y) : "; cin >> yorn;
	} while (yorn == 'y' || yorn == 'Y');
	return 0;
}