/*****************************************************************
Name    :unordered_set
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191119 Initial Version
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
#include <unordered_set>
#include <vector>
using namespace std;
/*==============================================================*/

void printAll(unordered_set<int> &uset)
{
    unordered_set<int>::iterator it;
    for(it=uset.begin(); it!=uset.end(); it++)
    {
        cout << *it << " ";
    }
}

int main(int argc, char const *argv[]){
    /*
     * Initialization
     */
    cout << "\nInitialization" << endl;

    //Using default constructor
    unordered_set<int> uset;
    uset.insert(20);
    uset.insert(10);
    uset.insert(30);
    cout << "uset :";
    printAll(uset);
    cout << endl;

    //Using Initializer list constructor
    unordered_set<int> uset1({9,5,2,7,1,4,6});

    cout << "uset1 :";
    printAll(uset1);
    cout << endl;

    //Using range constructor
    vector<int> vec{9,5,2,7};
    unordered_set<int> uset2(vec.begin(), vec.end());

    cout << "uset2 :";
    printAll(uset2);
    cout << endl;

    //Using copy constructor
    unordered_set<int> uset3(uset);

    cout << "uset3 :";
    printAll(uset3);
    cout << endl;

    /*
     * Capacity
     */
    cout << "\nCapacity" << endl;

    cout << "size:" << uset.size() << endl;
    cout << "empty:" << uset.empty() << endl;

    /*
     * Element Access
     */
    cout << "\nElement Access" << endl;

    /*
     * Modifiers
     */
    cout << "\nModifiers " << endl;

    //insert()
    int input=55;
    vector<int> vec2{66,67,68};
    uset.insert(input); //copy insertion
    input = 58;
    uset.insert(44+33); //move insertion
    uset.insert(vec2.begin(), vec2.end()); //range insertion
    uset.insert({22,27}); //initializer list insertion
    cout << "insert uset :";
    printAll(uset);
    cout << endl;

    //erase() by key
    uset.erase(22);
    cout << "erase uset :";
    printAll(uset);
    cout << endl;

    //erase() by position
    unordered_set<int>::iterator it;
    it = uset.find(30);
    uset.erase(it);
    cout << "erase uset :";
    printAll(uset);
    cout << endl;

    //erase() by range
    it = uset.find(55);
    uset.erase(it, uset.end());
    cout << "erase uset :";
    printAll(uset);
    cout << endl;

    //clear()
    uset.clear();
    cout << "clear uset :";
    printAll(uset);
    cout << endl;

    //swap()
    cout << "swap uset2 :";
    printAll(uset2);
    cout << endl;

    unordered_set<int>().swap(uset2);

    cout << "swap uset2 :";
    printAll(uset2);
    cout << endl;

    /*
     * Others
     */
    cout << "\nOthers " << endl;

    //find()
    it = uset3.find(20);
    if(it!=uset3.end()){
        cout << "uset3 find :" << *it << endl;
    }

    //count()
    if(uset3.count(25)!=0){
        cout << "element is in the set." << endl;
    }else{
        cout << "element is NOT in the set." << endl;
    }

    return 0;
}
/*==============================================================*/