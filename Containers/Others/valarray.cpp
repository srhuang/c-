/*****************************************************************
Name    :valarray
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191120 Initial Version
*****************************************************************/
/*****************************************************************
Outline
    1. Initialization
    2. Meta
    3. Element Access
    4. Modifiers
    5. Others
*****************************************************************/

#include <iostream>
#include <valarray>
#include <vector>
using namespace std;
/*==============================================================*/

void printAll(valarray<int> &va)
{
    for(auto it=begin(va); it!=end(va); it++){
        cout << *it << " ";
    }
}

int increment (int x) {return ++x;}

int main(int argc, char const *argv[]){
    /*
     * Initialization
     */
    cout << "\nInitialization" << endl;

    //Using default constructor
    valarray<int> va;
    cout << "va :";
    printAll(va);
    cout << endl;

    //Using size-initialization
    valarray<int> va2(5);
    cout << "va2 :";
    printAll(va2);
    cout << endl;

    //Using fill-initialization
    valarray<int> va3(10, 5);
    cout << "va3 :";
    printAll(va3);
    cout << endl;

    //Using array-initialization
    int input[]={10,20,30,40,50};
    valarray<int> va4(input, sizeof(input)/sizeof(input[0]));
    cout << "va4 :";
    printAll(va4);
    cout << endl;

    //Using initializer list constructor
    valarray<int> va5{1,2,3,4,5};
    cout << "va5 :";
    printAll(va5);
    cout << endl;

    //Using copy constructor
    valarray<int> va6(va4);
    cout << "va6 :";
    printAll(va6);
    cout << endl;

    /*
     * Meta
     */
    cout << "\nMeta" << endl;

    //int
    cout << "size of va4 :" << va4.size() << endl;
    cout << "max of va4 :" << va4.max() << endl;
    cout << "min of va4 :" << va4.min() << endl;
    cout << "sum of va4 :" << va4.sum() << endl;

    //string
    valarray<string> va7{"aaa", "bbb", "ccc"};
    cout << "size of va7 :" << va7.size() << endl;
    cout << "max of va7 :" << va7.max() << endl;
    cout << "min of va7 :" << va7.min() << endl;
    cout << "sum of va7 :" << va7.sum() << endl;

    /*
     * Element Access
     */
    cout << "\nElement Access" << endl;

    //operator[]
    cout << "operator[] :";
    for(int i=0; i<va4.size(); i++){
        cout << va4[i] << " ";
    }
    cout << endl;

    /*
     * Modifiers
     */
    cout << "\nModifiers" << endl;

    //shift (left)
    va3 = va3.shift(2);
    cout << "va3 shift :";
    printAll(va3);
    cout << endl;

    va3 = va3.shift(-1);
    cout << "va3 shift :";
    printAll(va3);
    cout << endl;

    //cshift (left)
    va4 = va4.cshift(2);
    cout << "va4 cshift :";
    printAll(va4);
    cout << endl;

    va4 = va4.cshift(-1);
    cout << "va4 cshift :";
    printAll(va4);
    cout << endl;

    //resize
    cout << "va3 before resize :";
    printAll(va3);
    cout << endl;

    va3.resize(3);

    cout << "va3 after resize :";
    printAll(va3);
    cout << endl;

    /*
     * Others
     */
    cout << "\nOthers" << endl;

    //apply
    va4 = va4.apply(increment);
    cout << "va4 apply increment :";
    printAll(va4);
    cout << endl;

    //swap
    va3.swap(va4);
    cout << "va3 :";
    printAll(va3);
    cout << endl;
    cout << "va4 :";
    printAll(va4);
    cout << endl;

    return 0;
}
/*==============================================================*/

