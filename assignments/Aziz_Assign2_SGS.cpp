/**		Author: David Flores
 *		Date: Sep 02, 2012
 *		Program: Aziz_Assign2_SGS.cpp
 *		Description: Displays grades
 *		appropriate for the student
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "============================" << endl;
	cout << "Student Grading System (SGS)" << endl;
	cout << "Long Beach City College"      << endl;
	cout << "David Flores"                 << endl;
	cout << "August 28, 2012"              << endl;
	cout << "============================" << endl;
	cout << endl;

	int    id;
	string name,lname;
	double gradeOne,gradeTwo,gradeThree;

	cout << "Enter Student ID:     ";
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
	cout << endl;

	double total = ( gradeOne + gradeTwo + gradeThree );
	double average = ( total / 3 );

	string letterGrade;

	if ( average >= 90 )
		letterGrade = "A";
	else if ( average >= 80 )
		letterGrade = "B";
	else if ( average >= 70 )
		letterGrade = "C";
	else if ( average >= 60 )
		letterGrade = "D";
	else
		letterGrade = "F";

	cout << "Student Information:" << endl;
	cout << "============================" << endl;
	cout << "ID: .......... " << id << endl;
	cout << "First Name: .. " << name << endl;
	cout << "Last Name: ... " << lname << endl;
	cout << "Total: ....... " << total << endl;
	cout << "Average: ..... " << average << "%" << endl;
	cout << "Grade: ....... " << letterGrade << endl;

	if ( letterGrade == "A" )
		cout << "Comment: ..... Congratulations on your achievements!" << endl;
	else if ( letterGrade == "F" )
		cout << "Comment: ..... Apply Yourself!" << endl;

	return 0;
}