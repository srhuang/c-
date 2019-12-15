/*****************************************************************
Name    :binary_heap
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
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
class MaxBinaryHeap{
    void Heapify(vector<int> &input, int root_index);
    void BuildHeap(vector<int> &input);
public:
    vector<int> data;
    int size;
    MaxBinaryHeap(int *arr, int size);
    void insert(int input);
    int pop();
    int peek();
};

//top-down
void MaxBinaryHeap::Heapify(vector<int> &input, int parent_index)
{
    int left_index = 2*parent_index + 1;
    int right_index = 2*parent_index + 2;
    int largest_index;

    //check left child
    if((left_index < size) &&
        input[left_index] > input[parent_index])
    {
        largest_index = left_index;
    }else{
        largest_index = parent_index;
    }

    //check right child
    if((right_index < size) &&
        input[right_index] > input[largest_index])
    {
        largest_index = right_index;
    }

    //check if need heapify
    if(largest_index != parent_index){
        //swap
        int temp = input[parent_index];
        input[parent_index] = input[largest_index];
        input[largest_index] = temp;

        //keep heapify
        Heapify(input, largest_index);
    }

}

//bottom-up
void MaxBinaryHeap::BuildHeap(vector<int> &input)
{
    for(int i=(size-2)/2; i>=0; i--){
        Heapify(input, i);
    }
}

MaxBinaryHeap::MaxBinaryHeap(int *arr, int size)
{
    data = vector<int>(arr, arr+size);
    this->size = size;
    BuildHeap(data);
}

//public insert
void MaxBinaryHeap::insert(int input)
{
    data.push_back(input);
    size = data.size();
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

int MaxBinaryHeap::pop()
{
    int result = data[0];

    data[0] = data.back();
    data.pop_back();
    size = data.size();

    //top-down
    Heapify(data, 0);

    return result;
}

int MaxBinaryHeap::peek()
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

    MaxBinaryHeap myHeap(random_data, n);



#if DEBUG
    cout << "\nAfter build Heap :";
    size = myHeap.size;
    for(int i=0; i<size; i++){
        cout << myHeap.data[i] << " ";
    }
    cout << endl;
#endif

    myHeap.insert(11);

#if DEBUG
    cout << "\nAfter insert :";
    size = myHeap.size;
    for(int i=0; i<size; i++){
        cout << myHeap.data[i] << " ";
    }
    cout << endl;
#endif

    int max = myHeap.pop();
    
#if DEBUG
    cout << "\nAfter pop :";
    size = myHeap.size;
    for(int i=0; i<size; i++){
        cout << myHeap.data[i] << " ";
    }
    cout << endl;
#endif

    cout << "peek :" << myHeap.peek() << endl;

    cout << "Heap sort :";
    size = myHeap.size;
    for(int i=0; i<size; i++){
        cout << myHeap.pop() << " ";
    }
    cout << endl;

    return 0;
}
/*==============================================================*/