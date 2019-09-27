/*****************************************************************
Name	:file_output
Author	:srhuang
Email	:lukyandy3162@gmail.com
History	:
	20181229 Initial Version
http://www.cplusplus.com/reference/fstream/ofstream/
*****************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

/*==============================================================*/
int main(){
	ofstream outFile("output.dat", ios::out);
	if(!outFile){ //exit program if unable to create file
		cerr << "File could not be opened." << endl;
		exit(1);
	}

	int accout=1;
	char name[30]="srhuang";
	double balance=3456;
	cout << "Enter the accout, name, and balance into File." << endl;
	//while(cin >> accout >> name >> balance){
		outFile << accout << ' ' << name << ' ' << balance << endl;
	//}

	return 0;
}