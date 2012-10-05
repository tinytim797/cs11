#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	ifstream inFile("inventory.txt");
	ofstream outFile("inventoryReport.txt");

	string item = " ";
	int qty = 0, i = 0;
	double cost = double(), total = double();
	double totalValue = double();
	double inventoryTotal = double();

	for( int i = 0; i < 79; i++ )
		{
			cout << '.';
			outFile << '.';
		}

	cout << endl;
	outFile << endl;

	cout << right << setw(65) << "Inventory Report For Jane Doe International Hardware" << endl;
	outFile << right << setw(65) << "Inventory Report For Jane Doe International Hardware" << endl;
	
	for( i = 0; i < 79; i++ )
		{
			cout << '.';
			outFile << '.';
		}

	cout << endl;
	outFile << endl;

	cout << right << "\nITEM" << setw(25) << "NUMBER OF UNITS" << setw(25) << "UNIT COST ($)"
		 << setw(25) << "TOTAL VALUE($)" << endl;

	outFile << right << "\nITEM" << setw(25) << "NUMBER OF UNITS" << setw(25) << "UNIT COST ($)"
		 << setw(25) << "TOTAL VALUE($)" << endl;

	for ( i = 0; i < 79; i++ )
	{
		cout << '-';
		outFile << '-';
	}

	cout << endl;
	outFile << endl;

	while(!inFile.eof())
	{		
		inFile >> item >> qty >> cost;
		inFile.ignore(4, '\n');
		
		totalValue = (qty * cost);
		inventoryTotal += totalValue;
		cout << showpoint << fixed << setprecision(2);
		outFile << showpoint << fixed << setprecision(2);
		
		cout << left << setw(6) << item << right << setw(17) << qty << setw(25) << cost 
			 << setw(26) << totalValue << endl;
		outFile << left << setw(6) << item << right << setw(17) << qty << setw(25) << cost 
			 << setw(26) << totalValue << endl;
	}

	for ( i = 0; i < 79; i++ )
	{
		cout << '-';
		outFile << '-';
	}

	cout << endl;
	outFile << endl;

	cout << left << setw(19) << "Inventory Total ($)" << right << setw(57) << inventoryTotal << endl;
	cout << endl;

	outFile << left << setw(19) << "Inventory Total ($)" << right << setw(57) << inventoryTotal << endl;
	outFile << endl;

	inFile.close();
	outFile.close();

}