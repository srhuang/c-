/*****************************************************************
Name    :RandomAccessSort
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191116 Initial Version
*****************************************************************/
#include <iostream>
#include <list>
#include <vector>
using namespace std;

/*==============================================================*/
//Global area

/*==============================================================*/
//Function area

/*==============================================================*/
int main(int argc, char const *argv[]){
    list<int> l{2,5,3,1,4};
    vector<int> vec{2,5,3,1,4};

    //list is not random access
    //sort(l.begin(), l.end());
    sort(vec.begin(), vec.end());

    return 0;
}
/*==============================================================*/