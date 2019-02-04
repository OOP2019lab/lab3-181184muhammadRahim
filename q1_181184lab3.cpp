#include<iostream>
#include<fstream>
#include"Header.h"
#include<string>
using namespace std;
int main()
{
	cout << "how many users?" << endl;
	int count;
	cin >> count;
	GitHubUser *ar1 = new GitHubUser[count];
	cout << "menu for student management system" << endl;
	cout << "press 1 for inputting data?" << endl;
	cout << "press 2 for comparison of two git hub users" << endl;
	cout << "press 3 for read data from file and assigning gitHub folders name" << endl;
	cout << "press 4 for printing information of specified Git hub user" << endl;
	cout << "press 5 for removing educational background" << endl;
	int option;
	cout << "enter your choice?" << endl;
	cin >> option;
	if (option < 1 || option>5)
	{ 
		bool flag = false;
		for (int i = 0; flag == false; i++)
		{
			cout << "wrong option please re-enter" << endl;
			cin >> option;
			if (option > 0 && option<6)
			{
				flag = true;
			}
		}
	}
	bool flag2 = false;
	for (int i = 0; flag2 == false; i++)
	{
		if (i > 0)
		{
			cout << "menu for student management system" << endl;
			cout << "press 1 for inputting data?" << endl;
			cout << "press 2 for comparison of two git hub users" << endl;
			cout << "press 3 for read data from file and assigning gitHub folders name" << endl;
			cout << "press 4 for printing information of specified Git hub user" << endl;
			cout << "press 5 for removing educational background" << endl;

		}
		if (option == 1)
		{
			inputfromuser(ar1, count);
		}
		if (option == 2)
		{
			cout << "please enter student no." << endl;
			int a;
			cin >> a;
			cout << "please enter 2nd student no." << endl;
			int b;
			cin >> b;
			Comparison(ar1[a - 1], ar1[b - 1]);
		}
		if (option == 3)
		{
			string a;
			cout << "please enter file name" << endl;
			cin >> a;
			readDataFromFile(ar1, a);
		}
		if (option == 4)
		{
			cout << "please enter student no. who's data is required" << endl;
			int q;
			cin >> q;
			print(ar1[q - 1]);
		}
		if (option == 5)
		{
			cout << "please enter student no. who's data you want to remove" << endl;
			int x;
			cin >> x;
			if (*ar1[x - 1].institute_name != "not available")
			{
				remove(ar1[x - 1]);
			}
			else
			{
				bool flag1 = false;
				for (int i = 0; flag1 == false; i++)
				{
					cout << "wrong student no. please re-enter" << endl;
					cin >> x;
					if (*ar1[x - 1].institute_name != "not available")
					{
						remove(ar1[x - 1]);
						flag1 = true;
					}
				}
			}

		}
		cout << "do you want to re-enter?" << endl;
		cout << "please press 1 and press enter for yes or press 2 and press enter for no" << endl;
		int option1;
		cin >> option1;
		if (option1 == 2)
		{
			flag2 = true;
		}
	}

	system("pause");
}