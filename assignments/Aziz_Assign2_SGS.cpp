/**		Author: David Flores
 *		Date: Aug. 28, 2012
 *		Program: Aziz_Assign2_SGS.cpp
 *		Description: Displays grades
 *		appropriate for the student
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//Variables
	int    id;
	string name = string();
	string lname = string();
	double gradeOne;
	double gradeTwo;
	double gradeThree;
	double total;
	double average;

	//Title
	cout << "============================" << endl;
	cout << "Student Grading System (SGS)" << endl;
	cout << "Long Beach City College"      << endl;
	cout << "David Flores"                 << endl;
	cout << "August 28, 2012"              << endl;
	cout << "============================" << endl;

	//User Input
	cout << "\nEnter Student ID:     ";
	cin  >> id;
	cout << "Enter First Name:     ";
	cin  >> name;
	cout << "Enter Last Name:      ";
	cin  >> lname;
	cout << "Enter Grade for CS11: ";
	cin  >> gradeOne;
	cout << "Enter Grade for CS12: ";
	cin  >> gradeTwo;
	cout << "Enter Grade for CS21: ";
	cin  >> gradeThree;

	//Calulations for total & average
	total = gradeOne + gradeTwo + gradeThree;
	average = total / 3;

	//Output
	cout << "\nStudent Information for " << name << " " << lname << endl;
	cout << "============================" << endl;
	cout << "ID:         " << id << endl;
	cout << "First Name: " << name << endl;
	cout << "Last Name:  " << lname << endl;
	cout << "Total:      " << total << endl;
	cout << "Average:    " << average << "%" << endl;
	
	//Letter Grading + Comments
	if (average >= 90)
	{
		cout << "Grade:      A" << endl;
		cout << "Comments:   Congratualtions on your achievements!" << endl;
	}
	
	else if (average <90 && average >= 80)
	{	
		cout << "Grade:      B" << endl;
	    cout << "Comments:   Good job!" << endl;
	}    
	else if (average <80 && average >= 70)
	{
		cout << "Grade:      C" << endl;
		cout << "Comments:   Study just a little bit more!" << endl;
	}
	else if (average <70 && average >= 60)
	{
		cout << "Grade:      D" << endl;
		cout << "Comments:   You can do better!" << endl;
	}
	else if (average < 60)
	{
		cout << "Grade:      F" << endl;
		cout << "Comments:   Apply Yourself!" << endl;
	}

    return 0;
}