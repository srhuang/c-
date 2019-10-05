/*****************************************************************
Name    :vector
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190927 Initial Version
http://www.cplusplus.com/reference/vector/vector/
*****************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/*==============================================================*/

int main(int argc, char const *argv[]){
    vector<int> vec;
    
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    cout << "size:" << vec.size() << ", capacity:" << vec.capacity() << endl;

    //using index
    int size = vec.size();
    for(int i=0; i<size; i++){
        cout << "Vector (" << i << ") : " << vec[i] << endl;
    }

    //using iterator
    vector<int>::iterator itr;
    for(itr=vec.begin(); itr!=vec.end(); itr++){
        cout << *itr << endl;
    }

    vec.clear();

    cout << "size:" << vec.size() << ", capacity:" << vec.capacity() << endl;

    vector<int>().swap(vec);
    cout << "size:" << vec.size() << ", capacity:" << vec.capacity() << endl;


    return 0;
}
/*==============================================================*/