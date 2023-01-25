#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CreateTXT(char* fname) 
{
	ofstream fout(fname);
	string s;
	cin.get();
	cin.sync();
	cout << "Enter line : "; getline(cin, s);
	fout << s << endl;
	cout << endl;
}

string PrintTXT(char* fname)
{
	ifstream fin(fname);
	string s, s1;
	while (getline(fin, s))
	{
		s1 += s + "\n";
	}
	return s1;
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
		cout << "1 - Enter a new line; 2 - Search; 3 - Print : "; cin >> response;
		if (response == 1)
			CreateTXT(fname);
		else if (response == 2)
		{
			cout << "Enter filename 2 : "; cin >> gname;
			cout << "Enter a line to search : "; cin >> search;
			ProcessTXT(fname, gname, search);
			cout << PrintTXT(gname) << endl;;
		}
		else if (response == 3)
			cout << PrintTXT(fname) << endl;
		else
			cout << "Wrong input, please try again" << endl;
		cout << "Continue? (y) : "; cin >> yorn;
	} while (yorn == 'y' || yorn == 'Y');
	return 0;
}