/*****************************************************************
Name    :returnCopy
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191108 extend the vector
    20190927 Initial Version
*****************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/*==============================================================*/

/*Test Constructor and Deconstructor*/
vector<string> foo()
{
    vector<string> result;
    
    result.push_back("aaa");
    result.push_back("bbb");
    result.push_back("ccc");
    cout << "address of result(foo) :" << &result << endl;
    return result;
}

vector<string>* foo2()
{
    vector<string> *result = new vector<string>;
    result->push_back("aaa");
    result->push_back("bbb");
    result->push_back("ccc");
    cout << "address of result(foo2) :" << result << endl;
    return result;
}

int main(int argc, char const *argv[]){
    //test constructor
    vector<string> testFoo;
    testFoo = foo(); //this will copy all elements
    cout << "address of testFoo :" << &testFoo << endl;
    cout << "test constructor :";
    cout << testFoo.back() << endl;

    vector<string> *testFoo2;
    testFoo2 = foo2(); //this will copy all elements
    cout << "address of testFoo2 :" << testFoo2 << endl;
    cout << "test constructor :";
    cout << testFoo2->back() << endl;
    delete testFoo2;

    return 0;
}

