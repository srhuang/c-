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

    //Using default constructor
    forward_list<int> fl;
    fl.push_front(10);
    fl.push_front(20);
    fl.push_front(30);
    cout << "fl :";
    printAll(fl);
    cout << endl;

    //Using Initializer list constructor
    forward_list<string> fl2{"aaa", "bbb", "ccc"};

    //Using fill constructor
    forward_list<int> fl3(5);
    cout << "fl3 :";
    printAll(fl3);
    cout << endl;

    //Using fill constructor
    int n=3;
    forward_list<int> fl4(n, 10);
    cout << "fl4 :";
    printAll(fl4);
    cout << endl;

    //Using range constructor
    int array[]={10,20,30};
    int size = sizeof(array)/sizeof(array[0]);
    forward_list<int> fl5(array, array+size);
    cout << "fl5 :";
    printAll(fl5);
    cout << endl;

    //Using range constructor
    forward_list<int> fl6(fl4.begin(), fl4.end());
    cout << "fl6 :";
    printAll(fl6);
    cout << endl;

    /*
     * Iterators
     */
    cout << "\nIterators" << endl;

    forward_list<int>::iterator it;
    for(it=fl.begin(); it!=fl.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    /*
     * Capacity
     */
    cout << "\nCapacity" << endl;

    cout << "empty:" << fl.empty() << endl;

    /*
     * Element Access
     */
    cout << "\nElement Access" << endl;

    //only front()
    cout << "front :" << fl.front() << endl;

    /*
     * Modifiers
     */
    cout << "\nModifiers " << endl;

    //push_front() / pop_front()
    fl.push_front(40);
    cout << "push_front :" << fl.front() << endl;
    fl.pop_front();
    cout << "pop_front :" << fl.front() << endl;

    //insert_after() / erase_after()
    forward_list<int>::iterator itr2;
    itr2 = fl.begin();
    fl.insert_after(itr2, 50);
    cout << "insert_after() :";
    printAll(fl);
    cout << endl;

    advance(itr2, 2);
    fl.erase_after(itr2);

    cout << "erase_after() :";
    printAll(fl);
    cout << endl;

    //clear() / swap()
    fl.clear();
    cout << "clear() :";
    printAll(fl);
    cout << endl;

    cout << "before swap() :";
    printAll(fl4);
    cout << endl;

    forward_list<int>().swap(fl4);

    cout << "after swap() :";
    printAll(fl4);
    cout << endl;

    return 0;
}
/*==============================================================*/