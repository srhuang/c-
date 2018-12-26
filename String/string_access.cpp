/*****************************************************************
Name	:string_access
Author	:srhuang
Email	:lukyandy3162@gmail.com
History	:
	20181226 Initial Version
http://www.cplusplus.com/reference/string/string/at/
http://www.cplusplus.com/reference/string/string/substr/
*****************************************************************/
#include <iostream>
using namespace std;
#include <string>

/*==============================================================*/
int main(){
	string string1("No pain, no gain.");
	cout << "String1 : " << string1 << endl;

	/* Access 1
	 * access character
	 */
	cout << "Access 1 : ";
	for(int i=3; i<7; i++)
		cout << string1.at(i);
	cout << endl;

	/* Access 2
	 * using substring
	 */
	cout << "Access 2 : ";
	cout << string1.substr(12, 15) << endl;

	return 0;
}