#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct GitHubUser
{
	string firstname;
	string username;
	string email;
	string password;
	int foldercount;
	string *githubfolders;
	string *institute_name;
	string *qualification_level;

};
void setEduBckGrnd(GitHubUser &user);
bool usernameexists(GitHubUser* arr, int size, string Username, int index);
GitHubUser* Searchuser(GitHubUser*user, int size, string Username);
bool Comparison(GitHubUser s, GitHubUser p) //compare two github users
{
	if (s.firstname != p.firstname)
	{
		return false;
	}
	else if (s.username != p.username)
	{
		return false;
	}
	else if (s.email != p.email)
	{
		return false;
	}
	else if (s.foldercount != p.foldercount)
	{
		return false;
	}
	else if (s.password != p.password)
	{
		return false;
	}
	else
	{
		return true;
	}

}
void inputfromuser(GitHubUser* arr, int size) //take input from user according to specified size
{
	int k = 10, a = 10;
	cout << "please enter first name of" << size << "github users" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "first name" << endl;
		cin >> arr[i].firstname;
	}
	cout << "please enter usernames of" << size << "github users" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << " username" << endl;
		cin >> arr[i].username;
		k = usernameexists(arr, size, arr[i].username, i);
		//cout << "value of k=" <<k<< endl; //debugging perform
		if (k == 0)
		{
			bool check = false;
			while (check == false)
			{
				cout << "user name already exist please re-enter" << endl;
				cin >> arr[i].username;
				a = usernameexists(arr, size, arr[i].username, i);
				if (a == 1)
				{
					check = true;
					k = 10;
					a = 10;
				}
				else
				{
					check = false;
				}
			}
		}
	}
	cout << "please enter emails of" << size << "github users" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << " email" << endl;
		cin >> arr[i].email;
	}
	cout << "please enter folder counts of " << size << "github users" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "folder counts " << endl;
		cin >> arr[i].email;
	}
	cout << "please enter passwords of " << size << "github users" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "passwords " << endl;
		cin >> arr[i].password;
	}
	int N = 0;
	for (int i = 0; i < size; i++)
	{
		cout << "do you want to enter educational data for user " << i + 1 << "?" << endl;
		cout << "press 1 and enter for yes or 2 and enter for no" << endl;
		cin >> N;
		if (N == 1)
		{
			setEduBckGrnd(arr[i]);
		}
		else
		{
			string a = "not available";
			string b = "not available";
			*arr[i].institute_name = a;
			*arr[i].qualification_level = b;
		}
	}

}
bool usernameexists(GitHubUser* arr, int size, string Username, int index) //usernameexists functionality
{
	bool flag = true;
	int a = 0;
	for (int i = 0; i < size && flag == true; i++)
	{
		if (i != index)
		{
			if (Username == arr[i].username)
			{
				flag = false;
				a = 1;
				return false;
			}
		}
	}
	if (a == 0)
	{
		return true;
	}
}
/*GitHubUser* Searchuser(GitHubUser*user, int size, string Username, int &check)//searching user functionality
{
	int a = 0;
	bool flag = false;
	GitHubUser *p;
	for (int i = 0; i < size && flag == false; i++)
	{
		if (Username == user[i].username)
		{
			a = 10;
			flag = true;
			p = &user[i];

		}
	}
	if (a = 10)
	{
		return p;
	}
	else
	{
		check = 1;
		p = nullptr;

	}


}*/
void readDataFromFile(GitHubUser* &users, string filepath)
{
	ifstream fin(filepath);
	int count;
	fin >> count;
	for (int i = 0; i < count; i++)
	{
		fin >> users[i].firstname;
		fin >> users[i].username;
		fin >> users[i].email;
		fin >> users[i].foldercount;
		users[i].githubfolders = new string[users[i].foldercount];
		int r = users[i].foldercount;
		for (int j = 0; j < r; j++)
		{
			fin >> users[i].githubfolders[j];
		}
		r = 0;
	}



}
void setEduBckGrnd(GitHubUser &user)
{
	string a, b;
	cout <<user.firstname<< " please enter institution name:" << endl;
	cin >> a;
	cout <<user.firstname<< " please enter qualification" << endl;
	cin >> b;
	*user.institute_name = a;
	*user.qualification_level = b;
}
void print(GitHubUser &user)
{
	cout << "first name:" << user.firstname << endl;
	cout << "user name:" << user.username << endl;
	cout << "email:" << user.email << endl;
	cout << "password:" << user.password << endl;
	cout << "folder count" << user.foldercount << endl;
	if (*user.institute_name != "not available")
	{
		cout << "institute name:" << *user.institute_name << endl;
		cout << "qualification level:" << *user.qualification_level << endl;
	}
}
void remove(GitHubUser &user)
{
	string a = "not available";
	string b = "not available";
	*user.institute_name = a;
	*user.qualification_level = b;
}
void backup(GitHubUser *originalArry, GitHubUser *&backupArry, int userCount)
{
	for (int i = 0; i < userCount; i++)
	{
		backupArry[i].firstname = originalArry[i].firstname;
		backupArry[i].username = originalArry[i].username;
		backupArry[i].email = originalArry[i].email;
		backupArry[i].foldercount = originalArry[i].foldercount;
		*backupArry[i].institute_name = *originalArry[i].institute_name;
		backupArry[i].password = originalArry[i].password;
		*backupArry[i].qualification_level = *originalArry[i].qualification_level;
		backupArry[i].githubfolders = new string[backupArry[i].foldercount];
		for (int j = 0; j < originalArry[i].foldercount; j++)
		{
			backupArry[i].githubfolders[j] = originalArry[i].githubfolders[j];
		}

	}
}