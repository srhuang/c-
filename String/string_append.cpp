/*****************************************************************
Name	:string_append
Author	:srhuang
Email	:lukyandy3162@gmail.com
History	:
	20181226 Initial Version
http://www.cplusplus.com/reference/string/string/append/
*****************************************************************/
#include <iostream>
using namespace std;
#include <string>

/*==============================================================*/
int main(){
	string string1("Everything will be alright!!!");
	cout << "String1 : " << string1 << endl;

	/* Append 1
	 * apend string2 to string1
	 */
	string string2("\tTomorrow will be fine.");
	string1 += string2;
	cout << "String1 : " << string1 << endl;

	/* Append 2
	 * apend string3 to string1
	 */
	string string3("\tThe sun still shiny.");
	string1.append(string3);
	cout << "String1 : " << string1 << endl;

	/* Append 3
	 * substring apend string4 to string1
	 */
	string string4("xxxHey, the earth still rotate.");
	string1.append("\t");
	string1.append(string4, 3, string4.length());
	cout << "String1 : " << string1 << endl;

	/* Append 4
	 * substring apend string5 to string1
	 */
	string string5("yyyyyGo, Go, Go!!!");
	string1.append("\t");
	string1.append(string5.begin()+5, string5.end());
	cout << "String1 : " << string1 << endl;

	return 0;
}