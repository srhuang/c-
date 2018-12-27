/*****************************************************************
Name	:string_stream
Author	:srhuang
Email	:lukyandy3162@gmail.com
History	:
	20181227 Initial Version
	http://www.cplusplus.com/reference/sstream/stringstream/str/
*****************************************************************/
#include <iostream>
using namespace std;
#include <string>
#include <sstream>

/*==============================================================*/
int main(){
	/* 
	 * Output String Stream
	 */
	string string1("string1");
	string string2("string2");
	string string3("string3");

	int x = 9527;
	double y = 3.14159;

	ostringstream outputstring;
	outputstring << string1 << " " << x << " "
		<< string2 << " " << y << " "
		<< string3 << endl;
	//call str to output string
	cout << "Output String : \n" << outputstring.str();

	/* 
	 * Input String Stream
	 */
	string input("Input 5438 9.8 ");
	string string4;
	int xx;
	double yy;

	istringstream inputstring(input);
	inputstring >> string4 >> xx >> yy;
	cout << "string4:" << string4
		<< "\txx:" << xx
		<< "\tyy:" << yy << endl;

	return 0;
}