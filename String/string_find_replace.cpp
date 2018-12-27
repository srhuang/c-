/*****************************************************************
Name	:string_find_replace
Author	:srhuang
Email	:lukyandy3162@gmail.com
History	:
	20181226 Initial Version
http://www.cplusplus.com/reference/string/string/find/
http://www.cplusplus.com/reference/string/string/rfind/
http://www.cplusplus.com/reference/string/string/find_first_of/
http://www.cplusplus.com/reference/string/string/find_last_of/
http://www.cplusplus.com/reference/string/string/find_first_not_of/
http://www.cplusplus.com/reference/string/string/find_last_not_of/
http://www.cplusplus.com/reference/string/string/replace/
*****************************************************************/
#include <iostream>
using namespace std;
#include <string>

/*==============================================================*/
int main(){
	/* 
	 * Find
	 */
	string string1("Dream as you will live forever, and live as you will die today.");
	cout << "String : " << string1 << "(" << string1.length() << ")" <<endl;

	//find "as"
	cout << "find as : " << string1.find("as") << endl;
	cout << "rfind as : " << string1.rfind("as") << endl;

	int location;
	//find 'e'
	location = string1.find_first_of("ey");
	cout << "find_first_of ey : " << location << endl;

	//find 'y'
	location = string1.find_last_of("ey");
	cout << "find_last_of ey : " << location << endl;

	location = string1.find_first_not_of("abcdeABCDEr");
	cout << "find_first_not_of abcdeABCDE : " << location << endl;

	location = string1.find_last_not_of("abcdeABCDEy.");
	cout << "find_last_not_of abcdeABCDE : " << location << endl;

	//Not find
	string string2("asdf");
	cout << "\nString 2 : " << string2 << endl;
	location = string2.find_first_of("gh");
	cout << "find_first_of gh : " << location << endl;

	/* 
	 * Replace 1
	 * replace all spaces
	 */
	int position = string1.find(" ");
	while(position != string::npos) {
		string1.replace(position, 1, ".");
		position = string1.find(" ", position+1);
	}
	cout << "\nAfter first replacement:\n" << string1 << endl;

	/* 
	 * Replace 2
	 * replacement with substring
	 */
	position = string1.find(".");
	while(position != string::npos) {
		string1.replace(position, 1, "xxxyyyzzz", 3, 3);
		position = string1.find(".", position+1);
	}
	cout << "\nAfter second replacement:\n" << string1 << endl;
	
	return 0;
}