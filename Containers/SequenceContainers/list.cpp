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
    for(itr=input.begin(); itr!=input.end(); itr++)
    {
        cout << *itr << " ";
    }
}

/*==============================================================*/
int main(int argc, char const *argv[]){
    /*
     * Initialization
     */
    cout << "\nInitialization" << endl;

    //Empty
    list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    cout << "l :";
    printAll(l);
    cout << endl;

    // [c++11] Initializing with contents
    list<string> l2{"aaa", "bbb", "ccc"};

    // number with zero value
    list<int> l3(5);
    cout << "l3 :";
    printAll(l3);
    cout << endl;

    // number with specific value
    int n=3;
    list<int> l4(n, 10);
    cout << "l4 :";
    printAll(l4);
    cout << endl;

    // Initializing from array
    int array[]={10,20,30};
    int size = sizeof(array)/sizeof(array[0]);
    list<int> l5(array, array+size);
    cout << "l5 :";
    printAll(l5);
    cout << endl;

    // Initializing by iterator
    list<int> l6(l4.begin(), l4.end());
    cout << "l6 :";
    printAll(l6);
    cout << endl;

    /*
     * Iterators
     */
    cout << "\nIterators" << endl;

    list<int>::iterator it;
    for(it=l.begin(); it!=l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    /*
     * Capacity
     */
    cout << "\nCapacity" << endl;

    cout << "size:" << l.size() << endl;
    cout << "empty:" << l.empty() << endl;

    /*
     * Element Access
     */
    cout << "\nElement Access" << endl;

    //front() / back()
    cout << "front :" << l.front() << endl;
    cout << "back :" << l.back() << endl;

    /*
     * Modifiers
     */
    cout << "\nModifiers " << endl;

    //push_back() / pop_back()
    l.push_back(40);
    cout << "push_back :" << l.back() << endl;
    l.pop_back();
    cout << "pop_back :" << l.back() << endl;

    //insert() / erase()
    list<int>::iterator itr2;
    itr2 = l.begin();
    l.insert(itr2, 50);
    cout << "insert() :";
    printAll(l);
    cout << endl;

    itr2 = l.begin();
    //l.erase(itr2+2); list DO NOT support random access iterator
    //you could use advance
    advance(itr2, 2);
    l.erase(itr2);

    cout << "erase() :";
    printAll(l);
    cout << endl;

    //clear() / swap()
    l.clear();
    cout << "clear() :";
    printAll(l);
    cout << endl;

    cout << "before swap() :";
    printAll(l4);
    cout << endl;

    list<int>().swap(l4);

    cout << "after swap() :";
    printAll(l4);
    cout << endl;

    return 0;
}
/*==============================================================*/