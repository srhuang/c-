/*****************************************************************
Name	:string_assignment
Author	:srhuang
Email	:lukyandy3162@gmail.com
History	:
	20181225 Initial Version
http://www.cplusplus.com/reference/string/string/assign/
*****************************************************************/
#include <iostream>
using namespace std;
#include <string>

/*==============================================================*/
int main(){
	string string1("Everything will be alright!!!");
	cout << "String1 : " << string1 << endl;

	/* Assignment 1
	 * assign string1 to string2
	 */
	string string2;
	string2=string1;
	cout << "String2 : " << string2 << endl;

	/* Assignment 2
	 * assign string1 to string3
	 */
	string string3;
	string3.assign(string1);
	cout << "String3 : " << string3 << endl;

	/* Assignment 4
	 * assign partial string1 to string4
	 */
	string string4;
	string4.assign(string1, 11, 10);
	cout << "String4 : " << string4 << endl;

	/* Assignment 5
	 * modify partial string
	 */
	string string5;
	string2[10]='x';
	cout << "String2 : " << string2 << endl;

    return 0;
}
/*==============================================================*/