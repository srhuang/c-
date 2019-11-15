/*****************************************************************
Name    :forward_list
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191115 Initial Version
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
#include <forward_list>
using namespace std;

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
void printAll(forward_list<int> &input)
{
    forward_list<int>::iterator itr;
    cout << "printf all :";
    for(itr=input.begin(); itr!=input.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
}

/*==============================================================*/
int main(int argc, char const *argv[]){
    /*
     * Initialization
     */

    //Empty list
    forward_list<int> fl;
    fl.push_front(10);
    fl.push_front(20);
    fl.push_front(30);
    cout << "\tpush_front" << endl;
    printAll(fl);

    // [c++11] Initializing like arrays
    forward_list<string> fl2{"aaa", "bbb", "ccc"};

    // Default value of all 5 ints will be 0
    forward_list<int> fl3(5);
    cout << "fl3 ";
    printAll(fl3);

    // Create a vector of size n with all values as 10.
    int n=3;
    forward_list<int> fl4(n, 10);
    cout << "fl4 ";
    printAll(fl4);

    // Initializing from array
    int array[]={10,20,30};
    int size = sizeof(array)/sizeof(array[0]);
    forward_list<int> fl5(array, array+size);
    cout << "fl5 ";
    printAll(fl5);

    // Initializing from another vector
    forward_list<int> fl6(fl4.begin(), fl4.end());
    cout << "fl6 ";
    printAll(fl6);

    /*
     * Iterators
     */
    cout << "\nIterators :";
    forward_list<int>::iterator it;
    for(it=fl.begin(); it!=fl.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    /*
     * Capacity
     */
    cout << "empty:" << fl.empty() << endl;

    /*
     * Element Access
     */

    //only front()
    cout << "front :" << fl.front() << endl;

    /*
     * Modifiers
     */

    //push_front() / pop_front()
    cout << "\nModifiers " << endl;
    fl.push_front(40);
    cout << "back :" << fl.front() << endl;
    fl.pop_front();
    cout << "back :" << fl.front() << endl;

    //insert_after() / erase_after()
    forward_list<int>::iterator itr2;
    itr2 = fl.begin();
    fl.insert_after(itr2, 50);
    printAll(fl);

    advance(itr2, 2);
    fl.erase_after(itr2);
    printAll(fl);

    //clear() / swap()
    fl.clear();
    cout << "\tafter clear() " << endl;
    printAll(fl);

    printAll(fl4);
    forward_list<int>().swap(fl4);
    cout << "\tafter swap() " << endl;
    printAll(fl4);

    return 0;
}
/*==============================================================*/