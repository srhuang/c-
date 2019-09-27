/*****************************************************************
Name	:file_input
Author	:srhuang
Email	:lukyandy3162@gmail.com
History	:
	20181229 Initial Version

*****************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void outputLine(int, const char * const , double);

/*==============================================================*/
int main(){
	ifstream inputFile("input.dat", ios::in);
	if(!inputFile){
		cerr << "File could not be opened." << endl;
		exit(1);
	}

	int accout;
	char name[30];
	double balance;

	cout << left << setw(10) << "Accout" << setw(13) << "Name" << "Balance" << endl << fixed << showpoint;

	while(inputFile >> accout >> name >> balance){
		outputLine(accout, name , balance);
	}

	return 0;
}

void outputLine (int accout, const char *const name, double balance)
{
	cout << left << setw(10) << accout << setw(13) << name << setw(7) << setprecision(2) << right << balance << endl;
}