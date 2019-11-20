/*****************************************************************
Name    :bitset
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
#include <bitset>
using namespace std;
/*==============================================================*/

int main(int argc, char const *argv[]){
    /*
     * Initialization
     */
    cout << "\nInitialization" << endl;

    //Using default constructor
    bitset<8> bs;
    cout << "bs :" << bs << endl;

    //Using initialization from integer value
    bitset<8> bs2(0x4f);
    cout << "bs2 :" << bs2 << endl;

    //Using initialization from string
    bitset<8> bs3("01010011");
    cout << "bs3 :" << bs3 << endl;

    /*
     * Mate
     */
    cout << "\nMeta" << endl;

    cout << "size of bs :" << bs.size() << endl;
    cout << "count of bs :" << bs.count() << endl;
    cout << "any of bs :" << bs.any() << endl;
    cout << "none of bs :" << bs.none() << endl;
    cout << "all of bs :" << bs.all() << endl;

    /*
     * Element Access
     */
    cout << "\nElement Access" << endl;

    //test
    cout << "test :";
    for(int i=0; i<bs2.size(); i++){
        cout << bs2.test(i) << " ";
    }
    cout << endl;

    //operator[]
    cout << "operator[] :";
    for(int i=0; i<bs2.size(); i++){
        cout << bs2[i] << " ";
    }
    cout << endl;

    /*
     * Modifiers
     */
    cout << "\nModifiers" << endl;

    //set
    bs.set(1);
    cout << "set :" << bs << endl;
    bs.set(1, 0);
    cout << "set :" << bs << endl;
    bs.set();
    cout << "set :" << bs << endl;

    //reset
    bs.reset(1);
    cout << "reset :" << bs << endl;
    bs.reset();
    cout << "reset :" << bs << endl;

    //flip
    bs.flip(1);
    cout << "flip :" << bs << endl;
    bs.flip();
    cout << "flip :" << bs << endl;

    /*
     * Others
     */
    cout << "\nOthers" << endl;

    //to_string
    string str = bs.to_string();
    cout << "to_string :" << str.substr(2,5) << endl;

    //to_ulong
    unsigned long ul = bs.to_ulong();
    cout << "to_ulong :" << bs.to_ulong() << endl;

    //to_ullong
    unsigned long long ull = bs.to_ullong();
    cout << "to_ulong :" << bs.to_ullong() << endl;

    return 0;
}
/*==============================================================*/

