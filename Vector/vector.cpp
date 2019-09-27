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

    int size = vec.size();
    for(int i=0; i<size; i++){
        cout << "Vector (" << i << ") : " << vec[i] << endl;
    }

    return 0;
}
/*==============================================================*/