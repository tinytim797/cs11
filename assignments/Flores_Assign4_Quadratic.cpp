/*
 *	Author: David Flores
 *	Date: Sep 27, 2012
 *	Program: Aziz_Assign3_Quadratic.cpp
 *	Description: Read the coefficients
 *  of a quadratic equation and, if the
 *  leading coefficient is non-zero,
 *  calculate and report the solutions.
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//Calculations
	double a = 0.0, b = 0.0, c = 0.0;
	bool calc = true, input = true;
	char cont = char();
	
	while(calc)
	{
		//Check Input Failure
		while (input)
		{
			//User input for values of a, b, c		
			cout << "Enter a: ";
			cin >> a;
			cout << "Enter b: ";
			cin >> b;
			cout << "Enter c: ";
			cin >> c;
			cout << endl;
	
			if ( cin.fail() )
			{
				cin.clear();
				cin.ignore(1000, '\n');
				system("cls");
				cout << "Invalid Input...Please enter a number only.\n" << endl;
			}
			else
			{
				input = false;
				system("cls");
			}
		}
		
		//Equations
		double valA = (-b/(2*a));
		double valB = (((b*b) - (4*a*c)));
		double valC = sqrt(valB);
		double valD = (sqrt(valB) / (2*a));
		double valE = (sqrt(-1 * valB) / (2*a));
		double quadEqPos = (valA + valD);
		double quadEqNeg = (valA - valD);

		//Output
		cout << fixed << setprecision(0);

		cout << "David Flores -\n" << endl;
		cout << "Values:" << endl;
		cout << "a = " << right << setw(3) << a << endl;
		cout << "b = " << right << setw(3) << b << endl;
		cout << "c = " << right << setw(3) << c << endl;
		cout << endl;

		//Check if equation has solutions (Imaginary or Real or No Solution)
		cout << fixed << setprecision(4) << scientific;

		if ( !a )
		{
			cout << "No solutions will be calculated for a leading coefficient of 0!\n" << endl;
		}
		else if ( valB < 0 )
		{
			cout << "The two imaginary solutions are:\n" << endl;
			cout << "x = " << right << setw(13) << valA << " + " << valE << "*I" << endl;
			cout << "x = " << right << setw(13) << valA << " - " << valE << "*I\n" << endl;
		}
		else if ( quadEqPos == quadEqNeg )
		{
			cout << "The one real solution is:\n" << endl;
			cout << "x = " << right << setw(13) << quadEqPos << endl << endl;
		}
		else 
		{
			cout << "The two real solutions are:\n" << endl;
			cout << "x = " << right << setw(13) << quadEqPos << endl;
			cout << "x = " << right << setw(13) << quadEqNeg << endl << endl;
		}

		cout << "Would you like to run the quadratic calculator again? (y/n): ";
		cin >> cont;

		if ( cont == 'Y' || cont == 'y' )
		{
			input = true;
		}
		else
		{
			calc = false;
		}
		system("cls");
	}

	return 0;
}