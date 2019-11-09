/*****************************************************************
Name    :stack
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190927 Initial Version
http://www.cplusplus.com/reference/stack/stack/
*****************************************************************/
#include <iostream>
#include <stack>
using namespace std;
/*==============================================================*/

int main(int argc, char const *argv[]){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Stack Top : " << s.top() << endl;
    cout << "Stack Size : " << s.size()<< endl;

    int i=0;
    while(s.size()){
        cout << "Stack pop(" << i++ << ") : " << s.top() << endl;
        s.pop();
    }

    return 0;
}
/*==============================================================*/