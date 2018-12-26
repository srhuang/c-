/*****************************************************************
Name	:string_swap
Author	:srhuang
Email	:lukyandy3162@gmail.com
History	:
	20181226 Initial Version
http://www.cplusplus.com/reference/string/string/swap/
*****************************************************************/
#include <iostream>
using namespace std;
#include <string>

/*==============================================================*/
int main(){
	string first("one");
	string second("second");

	cout << "Before swap : \n First : " << first
		<< "\nSecond : " << second << endl;

	first.swap(second);

	cout << "After swap : \n First : " << first
		<< "\nSecond : " << second << endl;

	return 0;
}