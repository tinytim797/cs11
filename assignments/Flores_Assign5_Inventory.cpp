#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	ifstream inFile("inventory.txt");
	ofstream outFile("report.txt");

	string item = " ";
	int qty = 0, i = 0;
	double cost = double(), total = double();
	double totalValue = double();
	double inventoryTotal = double();

	for( int i = 0; i < 80; i++ )
		{
			cout << '.';
		}

	cout << endl;
	cout << right << setw(65) << "Inventory Report For Jane Doe International Hardware" << endl;
	
	for( i = 0; i < 80; i++ )
		{
			cout << '.';
		}


	cout << right << "\nITEM" << setw(25) << "NUMBER OF UNITS" << setw(25) << "UNIT COST ($)"
		 << setw(26) << "TOTAL VALUE($)";

	for ( i = 0; i < 80; i++ )
	{
		cout << '-';
	}

	//system("pause");

	while(!inFile.eof())
	{		
		inFile >> item >> qty >> cost;
		inFile.ignore(4, '\n');
		
		totalValue = (qty * cost);
		inventoryTotal += totalValue;
		cout << fixed << setprecision(2);
		
		cout << left << setw(6) << item << right << setw(17) << qty << setw(25) << cost 
			 << setw(28) << totalValue << endl; 
	}

	for ( i = 0; i < 80; i++ )
	{
		cout << '-';
	}

	cout << left << setw(19) << "Inventory Total ($)" << right << setw(57) << inventoryTotal << endl;
	cout << endl;

	inFile.close();
	outFile.close();

}