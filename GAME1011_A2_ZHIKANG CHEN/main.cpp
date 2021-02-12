// This program was wriiten by Zhikang Chen
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

int main()
{
	int n;
	string i;

	cout << "Wellcome to the application! INSERT NAME HERE" << endl;

	LOOP:
	try 
	{
		cout << "\nPlease enter the number of participation" << endl;
		cin >> i;
		n = stoi(i);
		if(n > 500 || n < 0)
		{
			cout << "\nInvalid Number" << endl;
			goto LOOP;
		}
	}
	catch (std::invalid_argument)
	{
		cout << "\nInvalid Input" << endl;
		goto LOOP;
	}
	
	Survey s(n);

	do
	{
		cout << "Are you ready to process the survey? INSERT NAME HERE (y/n)" << endl;
		cin >> i;
	} while (tolower(i[0]) != 'y');
	cout << endl;
	cout << s.Process();
	cout << endl;
	s.Clean();
	return 0;
}
