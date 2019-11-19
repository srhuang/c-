/*****************************************************************
Name    :queue
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191116 Initial Version
*****************************************************************/
/*****************************************************************
Outline
    1. Initialization
    2. Capacity
    3. Element Access
    4. Modifiers
    5. Others
*****************************************************************/
#include <iostream>
#include <queue>
#include <list>
using namespace std;
/*==============================================================*/

void popAll(queue<int> &q)
{
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}

int main(int argc, char const *argv[]){
    /*
     * Initialization
     */
    cout << "\nInitialization" << endl;

    //Using default constructor
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << "q :";
    popAll(q);
    cout << endl;

    //Initializing with contents by default container deque
    deque<string> dk{"aaa", "bbb", "ccc"};
    queue<string> q2(dk);
    cout << "q2 front :" << q2.front() << endl;

    //Initializing with contents by list
    list<string> l{"ddd", "eee", "fff"};
    queue<string, list<string>> q3(l);
    cout << "q3 front :" << q3.front() << endl;

    /*
     * Capacity
     */
    cout << "\nCapacity" << endl;

    cout << "size:" << q3.size() << endl;
    cout << "empty:" << q3.empty() << endl;

    /*
     * Element Access
     */
    cout << "\nElement Access" << endl;
    cout << "print all :";
    while(!q2.empty()){
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;

    /*
     * Modifiers
     */
    cout << "\nModifiers " << endl;

    q3.pop();
    cout << "q3 front :" << q3.front() << endl;

    /*
     * Others
     */
    cout << "\nOthers " << endl;

    queue<string> q4;
    q4.push("qqq");
    q4.push("www");
    q4.push("eee");
    q4.push("rrr");
    q2.swap(q4);
    cout << "q2 front :" << q2.front() << endl;
    //the container in the queue must be the same.
    //q3.swap(q2);

    return 0;
}
/*==============================================================*/