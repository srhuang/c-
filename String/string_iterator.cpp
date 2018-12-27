/*****************************************************************
Name	:string_iterator
Author	:srhuang
Email	:lukyandy3162@gmail.com
History	:
	20181227 Initial Version
http://www.cplusplus.com/reference/string/string/begin/
http://www.cplusplus.com/reference/string/string/end/
http://www.cplusplus.com/reference/string/string/rbegin/
http://www.cplusplus.com/reference/string/string/rend/
*****************************************************************/
#include <iostream>
using namespace std;
#include <string>

/*==============================================================*/
int main(){
	string string1("123456789");
	cout << "string1 : " << string1 << endl;

	//Testing iterator
	string::const_iterator iterator1 = string1.begin();
	cout << "Testing iterator1 : ";
	while(iterator1 != string1.end()){
		cout << *iterator1;
		iterator1++;
	}
	cout << endl;

	//Testing reverse iterator
	string::const_reverse_iterator iterator2 = string1.rbegin();
	cout << "Testing reverse iterator2 : ";
	while(iterator2 != string1.rend()){
		cout << *iterator2;
		iterator2++;
	}
	cout << endl;

	return 0;
}