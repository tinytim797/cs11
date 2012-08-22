/*		Author: David Flores
		Date: Aug. 22, 2012
		Program: Aziz_Assign1_Salary.cpp
		Description: This program displays
		EmployeeID, Hours worked, Rate per
		hour, and Gross Salary
*/

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	//Variables
	int	   id;
	double hours;
	double rate;
	double salary;

	//Title
	cout << "Author's Name: David Flores             "  << endl;
	cout << "Program Name : Aziz_Assign1_Salary.cpp  "  << endl;
	cout << "Date         : August 22, 2012          "  << endl;
	cout << "School Name  : Long Beach City College  "  << endl;
	cout << "======================================\n"  << endl;
	
	//User Input
	cout << "Please Enter your Employee ID: ";
	cin  >> id;
	cout << "Please Enter Hours Worked:     ";
	cin  >> hours;
	cout << "Please Enter Rate Per Hour:    ";
	cin  >> rate;

	salary = hours * rate;

	//Output
	cout << "======================================\n"  << endl;
	cout << "Employee ID  : "  << id     << endl;
	cout << "Hours Worked : "  << hours  << endl;
	cout << "Rate per Hour: $" << rate   << endl;
	cout << "Gross Salary : $" << salary << "/week" << endl;
}