/*
 *	Author: David Flores
 *	Date: Oct 15, 2012
 *	Program: Flores_Assign5_Barcode.cpp
 *	Description: Asks user for a ZIP code and prints the bar code
 */

#include <iostream>
#include <iomanip>

using namespace std;

int zipInput(int);
int correctionDigit(int, int, int, int, int);
void barcodeMatch(int);
void barcodeOutput(int, int, int, int, int, int);

int main()
{
	int zip = int();
	int checkDigit = int();

	zip = zipInput(zip);

	//Zipcode Separation into single digits
	int d5 = (zip % 10);
	int d4 = (zip / 10 ) % 10;
	int d3 = (zip / 100 ) % 10;
	int d2 = (zip / 1000 ) % 10;
	int d1 = (zip / 10000 );

	checkDigit = correctionDigit(d1, d2, d3, d4, d5);

	//Output
	barcodeOutput( d1, d2, d3, d4, d5, checkDigit);

	return 0;
}

int zipInput(int zip)
{
	cout << "Enter 5 digit Zip Code: ";
	cin >> zip;

	system("cls");

	return zip;
}

int correctionDigit(int d1, int d2, int d3, int d4, int d5)
{
	int sum = (d5 + d4 + d3 + d2 + d1);
	int remainder = sum % 10;
	int digit = int();
	
	if( remainder <= 10  && remainder > 0)
	{
		digit = (10 - remainder);
		return digit;
	}
	else if( remainder <= 5 || remainder == 0 )
	{
		return remainder;
	}
	
}

void barcodeMatch(int digit)
{
	switch(digit)
	{
	case 0:
		cout << "||:::";
		break;
	case 1:
		cout << ":::||";
		break;
	case 2:
		cout << "::|:|";
		break;
	case 3:
		cout << "::||:";
		break;
	case 4:
		cout << ":|::|";
		break;
	case 5:
		cout << ":|:|:";
		break;
	case 6:
		cout << ":||::";
		break;
	case 7:
		cout << "|:::|";
		break;
	case 8:
		cout << "|::|:";
		break;
	case 9:
		cout << "|:|::";
		break;
	}
}

void barcodeOutput(int d1, int d2, int d3, int d4, int d5, int checkDigit)
{
	cout << "|";
	barcodeMatch(d1);
	barcodeMatch(d2);
	barcodeMatch(d3);
	barcodeMatch(d4);
	barcodeMatch(d5);
	barcodeMatch(checkDigit);
	cout << "|" << endl;
	cout << right << setw(4) << d1 << setw(5) << d2 << setw(5) << d3 << setw(5)
		                     << d4 << setw(5) << d5 << setw(5) << checkDigit
							 << endl;
}