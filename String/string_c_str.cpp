/*****************************************************************
Name	:string_c_str
Author	:srhuang
Email	:lukyandy3162@gmail.com
History	:
	20181227 Initial Version
http://www.cplusplus.com/reference/string/string/c_str/
*****************************************************************/
#include <iostream>
using namespace std;
#include <string>

/*==============================================================*/
int main(){
	string string1("This is a string.");

	//for c printf
	printf("string1 for C char* : %s\n", string1.c_str());

	//for c char*
	const char *ptr = 0;
	ptr = string1.data();

	cout << "Output each character : ";
	for(int i=0; i<string1.length(); i++){
		cout << *(ptr+i);
	}
	cout << endl;

	return 0;
}