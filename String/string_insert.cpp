/*****************************************************************
Name	:string_insert
Author	:srhuang
Email	:lukyandy3162@gmail.com
History	:
	20181227 Initial Version
http://www.cplusplus.com/reference/string/string/insert/
*****************************************************************/
#include <iostream>
using namespace std;
#include <string>

/*==============================================================*/
int main(){
	//insert string2 at position 5
	string string1("front end");
	string string2(" middle");
	cout << "Before Insert string1 : " << string1 << endl;
	string1.insert(5, string2);
	cout << "After Insert string1 : " << string1 << endl;

	//insert substring
	string string3("123456789");
	string string4("xxxyyyzzz");
	cout << "Before Insert string3 : " << string3 << endl;
	string3.insert(4, string4, 3, 3);
	cout << "After Insert string3 : " << string3 << endl;


	return 0;
}