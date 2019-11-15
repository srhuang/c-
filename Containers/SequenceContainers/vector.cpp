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
    int size = vec.size();
    for(int i=0; i<size; i++){
        cout << vec.at(i) << " ";
    }
}

int main(int argc, char const *argv[]){
    /*
     * Initialization
     */
    cout << "\nInitialization" << endl;

    // Empty
    vector<int> vec; 
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    cout << "vec :";
    printAll(vec);
    cout << endl;

    // [c++11] Initializing with contents
    vector<string> vec2{"aaa", "bbb", "ccc"};

    // number with zero value
    vector<int> vec3(5);
    cout << "vec3 :";
    printAll(vec3);
    cout << endl;

    // number with specific value
    int n=3;
    vector<int> vec4(n, 10);
    cout << "vec4 :";
    printAll(vec4);
    cout << endl; 

    // Initializing from array
    int array[]={10,20,30};
    int size = sizeof(array)/sizeof(array[0]);
    vector<int> vec5(array, array+size);
    cout << "vec5 :";
    printAll(vec5);
    cout << endl;

    // Initializing by iterator
    vector<int> vec6(vec4.begin(), vec4.end());
    cout << "vec6 :";
    printAll(vec6);
    cout << endl;
    
    /*
     * Iterators
     */
    cout << "\nIterators" << endl;

    vector<int>::iterator itr;
    for(itr=vec.begin(); itr!=vec.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;

    /*
     * Capacity
     */
    cout << "\nCapacity" << endl;

    cout << "size:" << vec.size() << endl;
    cout << "capacity:" << vec.capacity() << endl;
    cout << "empty:" << vec.empty() << endl;

    /*
     * Element Access
     */
    cout << "\nElement Access" << endl;

    //operator [] There is no protection for the index.
    size = vec.size();
    cout << "operator[] :";
    for(int i=0; i<size; i++){
        cout << vec[i] << " ";
    }
    cout << endl;

    //at(i), The function automatically checks 
    //whether n is within the bounds of valid elements in the container.
    cout << "at() :";
    size = vec.size();
    for(int i=0; i<size; i++){
        cout << vec.at(i) << " ";
    }
    cout << endl;

    //front() / back()
    cout << "front :" << vec.front() << endl;
    cout << "back :" << vec.back() << endl;

    /*
     * Modifiers
     */
    cout << "\nModifiers " << endl;

    //push_back() / pop_back()
    vec.push_back(40);
    cout << "push_back :" << vec.back() << endl;
    vec.pop_back();
    cout << "pop_back :" << vec.back() << endl;

    //insert() / erase()
    vector<int>::iterator itr2;
    itr2 = vec.begin();
    vec.insert(itr2, 50);
    cout << "insert() :";
    printAll(vec);
    cout << endl;

    vec.erase(itr2+2);

    cout << "erase() :";
    printAll(vec);
    cout << endl;

    //clear() / swap()
    vec.clear();
    cout << "clear() :";
    printAll(vec);
    cout << endl;

    cout << "before swap() :";
    printAll(vec4);
    cout << endl;

    vector<int>().swap(vec4);

    cout << "after swap() :";
    printAll(vec4);
    cout << endl;

    return 0;
}
/*==============================================================*/

