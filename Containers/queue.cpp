/*****************************************************************
Name    :queue
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190927 Initial Version
http://www.cplusplus.com/reference/queue/queue/
*****************************************************************/
#include <iostream>
#include <queue>
using namespace std;
/*==============================================================*/

int main(int argc, char const *argv[]){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Queue Front : " << q.front() << endl;
    cout << "Queue Back : " << q.back() << endl;
    cout << "Queue Size : " << q.size()<< endl;
    int size = q.size();

    for(int i=0; i<size; i++){
        cout << "Queue pop(" << i << ") : " << q.front() << endl;
        q.pop();
    }

    return 0;
}
/*==============================================================*/