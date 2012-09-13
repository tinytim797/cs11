/*		Author: David Flores
 *		Date: Sep 10, 2012
 *		Program: Aziz_Assign3_Paycheck.cpp
 *		Description: Calculates paycheck
 *              using tax rate.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	//ofstream outFile("output.txt");
	ofstream outFile;

	const double FedTax = 0.15, StateTax = 0.035, SocSecTax = 0.0575, MedTax = 0.0275, PenPlan = 0.05, HealthIns = 75.0;
	double fed = 0.0, state = 0.0, socSec = 0.0, med = 0.0, pen = 0.0, gPay = 0.0, netPay = 0.0;
	string emplFirstName = "";
	string emplLastName = "";

	//First Name, Last Name & Gross Salary User Input
	cout << "Paycheck Calculation By David Flores" << endl << endl;
	cout << "Enter First Name:   ";
	cin >> emplFirstName;
	cout << "Enter Last Name:    ";
	cin >> emplLastName;
	cout << "Enter Gross Salary: ";
	cin >> gPay;

	//Salary Deduction Calculations
	fed = ( FedTax * gPay );
	state = ( StateTax * gPay );
	socSec = ( SocSecTax * gPay );
	med = ( MedTax * gPay );
	pen = ( PenPlan * gPay );
	netPay = ( gPay - (fed + state + socSec + med + pen + HealthIns) );
	
	//Output to output.txt
	outFile.open("output.txt");

	outFile << fixed << showpoint << setprecision(2);

	outFile << emplFirstName << " " << emplLastName << endl;
	outFile << left << setw(30) << setfill('.') << "Gross Salary: "          << " $ " << right << setw(7) << setfill(' ') << gPay      << endl;
	outFile << left << setw(30) << setfill('.') << "Federal Tax: "           << " $ " << right << setw(7) << setfill(' ') << fed       << endl;
	outFile << left << setw(30) << setfill('.') << "State Tax: "             << " $ " << right << setw(7) << setfill(' ') << state     << endl;
	outFile << left << setw(30) << setfill('.') << "Social Security Tax: "   << " $ " << right << setw(7) << setfill(' ') << socSec    << endl;
	outFile << left << setw(30) << setfill('.') << "Medicare/Medicaid Tax: " << " $ " << right << setw(7) << setfill(' ') << med       << endl;
	outFile << left << setw(30) << setfill('.') << "Pension Plan: "          << " $ " << right << setw(7) << setfill(' ') << pen       << endl;
	outFile << left << setw(30) << setfill('.') << "Health Insurance: "      << " $ " << right << setw(7) << setfill(' ') << HealthIns << endl;
	outFile << left << setw(30) << setfill('.') << "Net Pay: "               << " $ " << right << setw(7) << setfill(' ') << netPay    << endl;

	outFile.close();
	return 0;
}