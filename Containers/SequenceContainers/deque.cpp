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
    for(itr=input.begin(); itr!=input.end(); itr++)
    {
        cout << *itr << " ";
    }
}

int main(int argc, char const *argv[]){
    /*
     * Initialization
     */
    cout << "\nInitialization" << endl;

    //Empty
    deque<int> dk;
    dk.push_back(10);
    dk.push_back(20);
    dk.push_back(30);
    cout << "dk :";
    printAll(dk);
    cout << endl;

    // [c++11] Initializing with contents
    deque<string> dk2{"aaa", "bbb", "ccc"};

    // number with zero value
    deque<int> dk3(5);
    cout << "dk3 :";
    printAll(dk3);
    cout << endl;

    // number with specific value
    int n=3;
    deque<int> dk4(n, 10);
    cout << "dk4 :";
    printAll(dk4);
    cout << endl;

    // Initializing from array
    int array[]={10,20,30};
    int size = sizeof(array)/sizeof(array[0]);
    deque<int> dk5(array, array+size);
    cout << "dk5 :";
    printAll(dk5);
    cout << endl;

    // Initializing from another vector
    deque<int> dk6(dk4.begin(), dk4.end());
    cout << "dk6 :";
    printAll(dk6);
    cout << endl;

    /*
     * Iterators
     */
    cout << "\nIterators" << endl;

    deque<int>::iterator it;
    for(it=dk.begin(); it!=dk.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    /*
     * Capacity
     */
    cout << "\nCapacity" << endl;

    cout << "size:" << dk.size() << endl;
    cout << "empty:" << dk.empty() << endl;

    /*
     * Element Access
     */
    cout << "\nElement Access" << endl;

    //operator [] There is no protection for the index.
    size = dk.size();
    cout << "operator[] :";
    for(int i=0; i<size; i++){
        cout << dk[i] << " ";
    }
    cout << endl;

    //at(i), The function automatically checks 
    //whether n is within the bounds of valid elements in the container.
    cout << "at() :";
    size = dk.size();
    for(int i=0; i<size; i++){
        cout << dk.at(i) << " ";
    }
    cout << endl;

    //front() / back()
    cout << "front :" << dk.front() << endl; 
    cout << "back :" << dk.back() << endl;

    /*
     * Modifiers
     */
    cout << "\nModifiers " << endl;

    //push_back() / pop_back()
    dk.push_back(40);
    cout << "push_back :" << dk.back() << endl;
    dk.pop_back();
    cout << "pop_back :" << dk.back() << endl;

    //insert() / erase()
    deque<int>::iterator itr2;
    itr2 = dk.begin();
    dk.insert(itr2, 50);
    cout << "insert() :";
    printAll(dk);
    cout << endl;

    dk.erase(itr2+2);
    cout << "erase() :";
    printAll(dk);
    cout << endl;

    //clear() / swap()
    dk.clear();
    cout << "clear() :";
    printAll(dk);
    cout << endl;

    cout << "before swap() :";
    printAll(dk4);
    cout << endl;

    deque<int>().swap(dk4);

    cout << "after swap() :";
    printAll(dk4);
    cout << endl;

    return 0;
}
/*==============================================================*/

