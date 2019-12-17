/*****************************************************************
Name    :binary_heap
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191218 change to min heap
    20191129 Initial Version
*****************************************************************/
#include <iostream>
#include <vector>
#define DEBUG (1)
#define SCALE (10)
using namespace std;
using namespace std::chrono;

/*==============================================================*/
//Global area
class BinaryHeap{
    //core operation
    void Heapify(int root_index);
public:
    vector<int> data;

    BinaryHeap(int *arr, int size);
    void insert(int input);
    int extract_min();
    int minimum();
};

//core operation
void BinaryHeap::Heapify(int parent_index)
{
    int left_index = 2*parent_index + 1;
    int right_index = 2*parent_index + 2;
    int largest_index;
    int size = data.size();

    //check left child
    if((left_index < size) &&
        data[left_index] > data[parent_index])
    {
        largest_index = left_index;
    }else{
        largest_index = parent_index;
    }

    //check right child
    if((right_index < size) &&
        data[right_index] > data[largest_index])
    {
        largest_index = right_index;
    }

    //check if need heapify
    if(largest_index != parent_index){
        //swap
        int temp = data[parent_index];
        data[parent_index] = data[largest_index];
        data[largest_index] = temp;

        //keep heapify
        Heapify(largest_index);
    }

}

BinaryHeap::BinaryHeap(int *arr, int arr_size)
{
    data = vector<int>(arr, arr+arr_size);
    int size = data.size();
    for(int i=(size-2)/2; i>=0; i--){
        Heapify(i);
    }
}

//insert
void BinaryHeap::insert(int input)
{
    data.push_back(input);
    int size = data.size();
    int current_index = size-1;
    int parent_index = (current_index-1)/2;
    while(current_index > 0 && (data[parent_index] < data[current_index]))
    {
        //swap
        int temp = data[current_index];
        data[current_index] = data[parent_index];
        data[parent_index] = temp;

        //bottom-up
        current_index = (current_index-1)/2;
        parent_index = (current_index-1)/2;
    }
}

//extract min
int BinaryHeap::extract_min()
{
    int result = data[0];

    data[0] = data.back();
    data.pop_back();

    //heapify from the root
    Heapify(0);

    return result;
}

//minimum
int BinaryHeap::minimum()
{
    return data[0];
}

/*==============================================================*/
//Function area
int *random_case(int number)
{
    int *result = new int[number];

    //generate index ordered arrary
    for(int i=0; i<number; i++){
        result[i]=i+1;
    }

    //swap each position
    srand(time(NULL));
    for(int i=0; i<number-1; i++){
        int j = i + rand() / (RAND_MAX / (number-i));
        //swap
        int t=result[i];
        result[i] = result[j];
        result[j]=t;
    }

    return result;
}

/*==============================================================*/
int main(int argc, char const *argv[]){
    int n=SCALE;
    int size;

    //generate data
    int *random_data = random_case(n);

#if DEBUG
    cout << "Before build Heap :";
    for(int i=0; i<n; i++){
        cout << random_data[i] << " ";
    }
    cout << endl;
#endif

    BinaryHeap myHeap(random_data, n);



#if DEBUG
    cout << "\nAfter build Heap :";
    size = myHeap.data.size();
    for(int i=0; i<size; i++){
        cout << myHeap.data[i] << " ";
    }
    cout << endl;
#endif

    myHeap.insert(11);

#if DEBUG
    cout << "\nAfter insert :";
    size = myHeap.data.size();
    for(int i=0; i<size; i++){
        cout << myHeap.data[i] << " ";
    }
    cout << endl;
#endif

    int max = myHeap.extract_min();
    
#if DEBUG
    cout << "\nAfter extract min :";
    size = myHeap.data.size();
    for(int i=0; i<size; i++){
        cout << myHeap.data[i] << " ";
    }
    cout << endl;
#endif

    cout << "minimum :" << myHeap.minimum() << endl;

    cout << "Heap sort :";
    size = myHeap.data.size();
    for(int i=0; i<size; i++){
        cout << myHeap.extract_min() << " ";
    }
    cout << endl;

    return 0;
}
/*==============================================================*/