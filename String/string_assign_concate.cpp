/*****************************************************************
Name	:string_assign_conctate
Author	:srhuang
Email	:lukyandy3162@gmail.com
History	:
	20181225 Initial Version
*****************************************************************/
#include <iostream>
using namespace std;
#include <string>

/*==============================================================*/
int main(){
	string string1("cat");
	string string2;
	string string3;

	string2=string1; //assign string1 to string2
	string3.assign(string1); //assgin string1 to string3
	cout << "String1 : " << string1 << "\nstring2 : " << string2
		<< "\nstring3 : " << string3 << "\n\n";

    return 0;
}
/*==============================================================*/