/*****************************************************************
Name    :deque
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
#include <deque>
using namespace std;
/*==============================================================*/

void printAll(deque<int> &input)
{
    deque<int>::iterator itr;
    cout << "printf all :";
    for(itr=input.begin(); itr!=input.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[]){
    /*
     * Initialization
     */
    //Empty list
    deque<int> dk;
    dk.push_back(10);
    dk.push_back(20);
    dk.push_back(30);
    printAll(dk);

    // [c++11] Initializing like arrays
    deque<string> dk2{"aaa", "bbb", "ccc"};

    // Default value of all 5 ints will be 0
    deque<int> dk3(5);
    cout << "dk3 ";
    printAll(dk3);

    // Create a vector of size n with all values as 10.
    int n=3;
    deque<int> dk4(n, 10);
    cout << "dk4 ";
    printAll(dk4);

    // Initializing from array
    int array[]={10,20,30};
    int size = sizeof(array)/sizeof(array[0]);
    deque<int> dk5(array, array+size);
    cout << "dk5 ";
    printAll(dk5);

    // Initializing from another vector
    deque<int> dk6(dk4.begin(), dk4.end());
    cout << "dk6 ";
    printAll(dk6);

    /*
     * Iterators
     */
    cout << "\nIterators :";
    deque<int>::iterator it;
    for(it=dk.begin(); it!=dk.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    /*
     * Capacity
     */
    cout << "size:" << dk.size();
    cout << " empty:" << dk.empty() << endl;

    /*
     * Element Access
     */

    //front() / back()
    cout << "front :" << dk.front() << " back :" << dk.back() << endl;

    /*
     * Modifiers
     */
    //push_back() / pop_back()
    cout << "\nModifiers " << endl;
    dk.push_back(40);
    cout << "back :" << dk.back() << endl;
    dk.pop_back();
    cout << "back :" << dk.back() << endl;

    //insert() / erase()
    deque<int>::iterator itr2;
    itr2 = dk.begin();
    dk.insert(itr2, 50);
    printAll(dk);

    dk.erase(itr2+2);
    printAll(dk);

    //clear() / swap()
    dk.clear();
    cout << "\tafter clear() " << endl;
    printAll(dk);

    printAll(dk4);
    deque<int>().swap(dk4);
    cout << "\tafter swap() " << endl;
    printAll(dk4);

    return 0;
}
/*==============================================================*/

