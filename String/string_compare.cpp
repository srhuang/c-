/*****************************************************************
Name	:string_compare
Author	:srhuang
Email	:lukyandy3162@gmail.com
History	:
	20181226 Initial Version
http://www.cplusplus.com/reference/string/string/compare/
*****************************************************************/
#include <iostream>
using namespace std;
#include <string>

/*==============================================================*/
int main(){
	string string1("abcdefg");
	string string2("abcxxxxcdeyyyyy");

	/* Compare 1
	 * compare string1 and string2
	 */
	cout << "Compare 1 : ";
	if(string1 == string2){
		cout << "string1 = string2\n";
	}else if(string1 > string2){
		cout << "string1 > string2\n";
	}else{
		cout << "string1 < string2\n";
	}

	/* Compare 2
	 * compare string1 and string2
	 */
	cout << "Compare 2 : ";
	int result = string1.compare(string2);
	if(0 == result){
		cout << "string1 = string2\n";
	}else if(result > 0){
		cout << "string1 > string2\n";
	}else{
		cout << "string1 < string2\n";
	}

	/* Compare 3
	 * substring compare string1 and string2
	 */
	cout << "Compare 3 : ";
	result = string1.compare(2, 3, string2, 7, 3);
	if(0 == result){
		cout << "string1 = string2\n";
	}else if(result > 0){
		cout << "string1 > string2\n";
	}else{
		cout << "string1 < string2\n";
	}

	/* Compare 4
	 * substring compare string1 and string3
	 */
	cout << "Compare 4 : ";
	string string3("defg");
	result = string1.compare(3, string1.length(), string3);
	if(0 == result){
		cout << "string1 = string3\n";
	}else if(result > 0){
		cout << "string1 > string3\n";
	}else{
		cout << "string1 < string3\n";
	}


	return 0;
}