/*****************************************************************
Name    :priority_queue
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
#include <deque>
using namespace std;
/*==============================================================*/

void popAll(priority_queue<int> &pq)
{
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}

class mycomparison
{ 
public: 
  bool operator() (const int& lhs, const int&rhs) const
  {
     return (lhs<rhs);
  }
};

bool myfunction (int i,int j) { return (i<j); }

int main(int argc, char const *argv[]){
    /*
     * Initialization
     */
    cout << "\nInitialization" << endl;

    //Using default constructor
    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(40);
    cout << "pq :";
    popAll(pq);
    cout << endl;

    //Initializing with contents by default container vector
    vector<int> vec{2, 1, 3, 6, 4};
    priority_queue<int> pq2(less<int>(), vec);
    cout << "pq2 top :" << pq2.top() << endl;

    //custom comparator function
    priority_queue<int, vector<int>, bool(*)(int, int)> pq3(&myfunction, vec);
    //priority_queue<int, vector<int>, decltype(&myfunction)> pq4(&myfunction, vec);
    cout << "pq3 top :" << pq3.top() << endl;

    //custom comparator class
    priority_queue<int, vector<int>, mycomparison> pq4(mycomparison(), vec);
    cout << "pq4 top :" << pq4.top() << endl;

    //using lamda function
    auto compareFunc = [](int a, int b) { return a > b; };
    priority_queue<int, vector<int>, decltype(compareFunc)> pq5(compareFunc, vec);
    cout << "pq5 top :" << pq5.top() << endl;

    //using iterator
    vector<int> vec2{10,60,50,20};
    priority_queue<int, vector<int>, greater<int>> pq6(vec2.begin(), vec2.end());
    cout << "pq6 top :" << pq6.top() << endl;

    //Initializing with contents by deque
    deque<int> dk{10,60,50,20};
    priority_queue<int, deque<int>, less<int>> pq7(dk.begin(), dk.end());
    cout << "pq7 top :" << pq7.top() << endl;

    /*
     * Capacity
     */
    cout << "\nCapacity" << endl;

    cout << "size:" << pq3.size() << endl;
    cout << "empty:" << pq3.empty() << endl;

    /*
     * Element Access
     */
    cout << "\nElement Access" << endl;

    cout << "print all :";
    while(!pq7.empty()){
        cout << pq7.top() << " ";
        pq7.pop();
    }
    cout << endl;

    /*
     * Modifiers
     */
    cout << "\nModifiers " << endl;

    pq3.pop();
    cout << "pq3 top :" << pq3.top() << endl;

    /*
     * Others
     */
    cout << "\nOthers " << endl;
    vector<int> vec3{30, 20, 40, 70, 10, 50, 60};
    priority_queue<int> pq8(less<int>(), vec3);
    cout << "pq8 top :" << pq8.top() << endl;
    pq8.swap(pq2);
    //the comparator function shoule be match
    //pq3.swap(pq2);
    cout << "pq8 top :" << pq8.top() << endl;

    return 0;
}
/*==============================================================*/