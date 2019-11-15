/*****************************************************************
Name    :list
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
#include <list>
using namespace std;

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area
void printAll(list<int> &input)
{
    list<int>::iterator itr;
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
    list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    // [c++11] Initializing like arrays
    list<string> l2{"aaa", "bbb", "ccc"};

    // Default value of all 5 ints will be 0
    list<int> l3(5);
    cout << "l3 ";
    printAll(l3);

    // Create a vector of size n with all values as 10.
    int n=3;
    list<int> l4(n, 10);
    cout << "l4 ";
    printAll(l4);

    // Initializing from array
    int array[]={10,20,30};
    int size = sizeof(array)/sizeof(array[0]);
    list<int> l5(array, array+size);
    cout << "l5 ";
    printAll(l5);

    // Initializing from another vector
    list<int> l6(l4.begin(), l4.end());
    cout << "l6 ";
    printAll(l6);

    /*
     * Iterators
     */
    cout << "\nIterators :";
    list<int>::iterator it;
    for(it=l.begin(); it!=l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    /*
     * Capacity
     */
    cout << "size:" << l.size();
    cout << " empty:" << l.empty() << endl;

    /*
     * Element Access
     */

    //front() / back()
    cout << "front :" << l.front() << " back :" << l.back() << endl;

    /*
     * Modifiers
     */
    //push_back() / pop_back()
    cout << "\nModifiers " << endl;
    l.push_back(40);
    cout << "back :" << l.back() << endl;
    l.pop_back();
    cout << "back :" << l.back() << endl;

    //insert() / erase()
    list<int>::iterator itr2;
    itr2 = l.begin();
    l.insert(itr2, 50);
    printAll(l);

    itr2 = l.begin();
    //l.erase(itr2+2); list DO NOT support random access iterator
    //you could use advance
    advance(itr2, 2);
    l.erase(itr2);

    size = l.size();
    printAll(l);

    //clear() / swap()
    l.clear();
    cout << "\tafter clear() " << endl;
    printAll(l);

    printAll(l4);
    list<int>().swap(l4);
    cout << "\tafter swap() " << endl;
    printAll(l4);

    return 0;
}
/*==============================================================*/