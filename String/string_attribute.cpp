/*****************************************************************
Name	:string_attribute
Author	:srhuang
Email	:lukyandy3162@gmail.com
History	:
	20181226 Initial Version
http://www.cplusplus.com/reference/string/string/capacity/
http://www.cplusplus.com/reference/string/string/empty/
http://www.cplusplus.com/reference/string/string/length/
http://www.cplusplus.com/reference/string/string/max_size/
http://www.cplusplus.com/reference/string/string/size/
*****************************************************************/
#include <iostream>
using namespace std;
#include <string>

/*==============================================================*/

void printAttribute(const string &);

int main(){
	string string1;

	cout << "Before Input: \n" << boolalpha;
	printAttribute(string1);

	string1="Test"; //4

	cout << "\nAfter Input: " << string1 << endl;
	printAttribute(string1);

	string1 += " 123456789"; //1+9

	cout << "\nAfter Input: " << string1 << endl;
	printAttribute(string1);

	string1 += " abcdefghijklmnopqrstuvwxyz"; //1+26

	cout << "\nAfter Input: " << string1 << endl;
	printAttribute(string1);

	return 0;
}

void printAttribute(const string &stringRef)
{
	cout << "capacity: " << stringRef.capacity()
		<< "\nempty: " << stringRef.empty()
		<< "\nlength:" << stringRef.length()
		<< "\nmax_size: " << stringRef.max_size()
		<< "\nsize: " << stringRef.size() << endl;
}