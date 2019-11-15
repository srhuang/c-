/*****************************************************************
Name    :vector
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191108 extend the vector
    20190927 Initial Version
*****************************************************************/
/*****************************************************************
Outline
    1. Initialization
    2. Iterators
    3. Capacity
    4. Element Access
    5. Modifiers
    6. Others
*****************************************************************/

#include <iostream>
#include <vector>
using namespace std;
/*==============================================================*/

void printAll(vector<int> &vec)
{
    cout << "print all :";
    for(int i=0; i<size; i++){
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

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
    /*
     * Initialization
     */

    // Empty vector
    vector<int> vec; 
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // [c++11] Initializing like arrays
    vector<string> vec2{"aaa", "bbb", "ccc"};

    // Default value of all 5 ints will be 0
    vector<int> vec3(5);

    // Create a vector of size n with all values as 10.
    int n=3;
    vector<int> vec4(n, 10); 

    // Initializing from array
    int array[]={10,20,30};
    int size = sizeof(array)/sizeof(array[0]);
    vector<int> vec5(array, array+size);

    // Initializing from another vector
    vector<int> vec6(vec4.begin(), vec4.end());
    
    /*
     * Iterators
     */
    cout << "Iterators :";
    vector<int>::iterator itr;
    for(itr=vec.begin(); itr!=vec.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;

    /*
     * Capacity
     */
    cout << "size:" << vec.size();
    cout << " capacity:" << vec.capacity();
    cout << " empty:" << vec.empty() << endl;

    /*
     * Element Access
     */

    //operator [] There is no protection for the index.
    size = vec.size();
    cout << "Vector operator[] :";
    for(int i=0; i<size; i++){
        cout << vec[i] << " ";
    }
    cout << endl;

    //at(i), The function automatically checks 
    //whether n is within the bounds of valid elements in the vector.
    cout << "Vector at() :";
    size = vec.size();
    for(int i=0; i<size; i++){
        cout << vec.at(i) << " ";
    }
    cout << endl;

    //front() / back()
    cout << "front :" << vec.front() << " back :" << vec.back() << endl;

    /*
     * Modifiers
     */
    //push_back() / pop_back()
    vec.push_back(40);
    cout << "back :" << vec.back() << endl;
    vec.pop_back();
    cout << "back :" << vec.back() << endl;

    //insert() / erase()
    vector<int>::iterator itr2;
    itr2 = vec.begin();
    vec.insert(itr2, 50);
    printAll(vec);

    vec.erase(itr2+2);

    size = vec.size();
    printAll(vec);

    //clear() / swap()
    vec.clear();
    printAll(vec);

    printAll(vec4);
    vector<int>().swap(vec4);
    printAll(vec4);

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
/*==============================================================*/

