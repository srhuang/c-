/*****************************************************************
Name    :stack
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
#include <stack>
#include <deque>
#include <vector>
using namespace std;
/*==============================================================*/

void popAll(stack<int> &st)
{
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

int main(int argc, char const *argv[]){
    /*
     * Initialization
     */
    cout << "\nInitialization" << endl;

    // Empty
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout << "st :";
    popAll(st);
    cout << endl;

    //Initializing with contents by default container deque
    deque<string> dk{"aaa", "bbb", "ccc"};
    stack<string> st2(dk);
    cout << "st2 top :" << st2.top() << endl;

    //Initializing with contents by vector
    vector<string> vec{"ddd", "eee", "fff"};
    stack<string, vector<string>> st3(vec);
    cout << "st3 top :" << st3.top() << endl;

    /*
     * Capacity
     */
    cout << "\nCapacity" << endl;

    cout << "size:" << st3.size() << endl;
    cout << "empty:" << st3.empty() << endl;

    /*
     * Element Access
     */
    cout << "\nElement Access" << endl;

    cout << "print all :";
    while(!st2.empty()){
        cout << st2.top() << " ";
        st2.pop();
    }
    cout << endl;

    /*
     * Modifiers
     */
    cout << "\nModifiers " << endl;
    st3.pop();
    cout << "st3 top :" << st3.top() << endl;

    /*
     * Others
     */
    cout << "\nOthers " << endl;
    stack<string> st4;
    st4.push("qqq");
    st4.push("www");
    st4.push("eee");
    st4.push("rrr");
    st2.swap(st4);
    cout << "st2 top :" << st2.top() << endl;
    //the container in the stack must be the same.
    //st3.swap(st2);

    return 0;
}
/*==============================================================*/