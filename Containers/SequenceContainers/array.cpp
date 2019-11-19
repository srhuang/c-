/*****************************************************************
Name    :array
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
#include <array>
using namespace std;
/*==============================================================*/
template<std::size_t SIZE>
void printAll(array<int,SIZE> &input)
{
    int size = input.size();
    for(int i=0; i<size; i++){
        cout << input.at(i) << " ";
    }
}

int main(int argc, char const *argv[]){
    /*
     * Initialization
     */
    cout << "\nInitialization" << endl;

    //Using default constructor
    array<int, 3> arr;
    arr[0]=10;
    arr[1]=20;
    arr[2]=30;
    cout << "arr :";
    printAll(arr);
    cout << endl;

    //Using Initializer list constructor
    array<string, 3> arr2{"aaa", "bbb", "ccc"};

    //Using fill constructor
    array<int, 5> arr3{0};
    cout << "arr3 :";
    printAll(arr3);
    cout << endl;

    //Using fill constructor
    int n=3;
    array<int, 3> arr4; 
    arr4.fill(10);
    cout << "arr4 :";
    printAll(arr4);
    cout << endl;

    // Transfer C-style array into array container in C++
    int array_C[]={40,50,60};
    const int size = sizeof(array_C)/sizeof(array_C[0]);
    array<int, size> arr5;
    copy(begin(array_C), end(array_C), arr5.begin());
    cout << "arr5 :";
    printAll(arr5);
    cout << endl;

    // Initializing by iterator
    array<int, 3> arr6;
    copy(arr4.begin(), arr4.end(), arr6.begin());
    cout << "arr6 :";
    printAll(arr6);
    cout << endl;

    /*
     * Iterators
     */
    cout << "\nIterators" << endl;

    for(auto itr=arr.begin(); itr!=arr.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;

    /*
     * Capacity
     */
    cout << "\nCapacity" << endl;

    cout << "size:" << arr.size();
    cout << " empty:" << arr.empty() << endl;

    /*
     * Element Access
     */
    cout << "\nElement Access" << endl;

    //operator [] There is no protection for the index.
    int size2 = arr.size();
    cout << "operator[] :";
    for(int i=0; i<size2; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    //at(i), The function automatically checks 
    //whether n is within the bounds of valid elements in the container.
    cout << "at() :";
    size2 = arr.size();
    for(int i=0; i<size2; i++){
        cout << arr.at(i) << " ";
    }
    cout << endl;

    //front() / back()
    cout << "front :" << arr.front() << endl;
    cout << "back :" << arr.back() << endl;

    /*
     * Modifiers
     */
    cout << "\nModifiers " << endl;

    //swap()
    cout << "before swap() :";
    printAll(arr4);
    cout << endl;

    array<int, 3>().swap(arr4);

    cout << "after swap() :";
    printAll(arr4);
    cout << endl;

    return 0;
}
/*==============================================================*/

