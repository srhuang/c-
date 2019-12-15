/*****************************************************************
Name    :leftist_heap
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191212 Initial Version
*****************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#define DEBUG (1)
#define SCALE (10)
using namespace std;
using namespace std::chrono;

/*==============================================================*/
//Global area
struct LeftistNode{
    int data;
    LeftistNode *left=NULL;
    LeftistNode *right=NULL;
    int s_value=1;
};

class MaxLeftistHeap{
    LeftistNode *meld(LeftistNode *h1, LeftistNode *h2);
public:
    LeftistNode *root;
    int size;
    MaxLeftistHeap(int *arr, int size);
    void insert(int input);
    int pop();
    int peek();
    void merge(MaxLeftistHeap &lh);

    //for learning not necessary
    void preorderTraversal(LeftistNode *parent);
};

LeftistNode *MaxLeftistHeap::meld(LeftistNode *h1, LeftistNode *h2)
{
    LeftistNode *meld_root;
    LeftistNode *meld_child;

    //check the null head
    if(NULL == h1){
        return h2;
    }
    if(NULL == h2){
        return h1;
    }

    //pick the new root
    if(h2->data > h1->data){
        meld_root = h2;
        meld_child = h1;
    }else{
        meld_root = h1;
        meld_child = h2;
    }

    //recursive meld the right child
    meld_root->right = meld(meld_root->right, meld_child);

    //check the leftist
    if(NULL == meld_root->left){
        meld_root->left = meld_root->right;
        meld_root->right = NULL;
    }else{
        //check the s value
        if(meld_root->left->s_value < meld_root->right->s_value){
            LeftistNode *temp;
            temp = meld_root->left;
            meld_root->left = meld_root->right;
            meld_root->right = temp;
        }

        meld_root->s_value = meld_root->right->s_value + 1;
    }

    return meld_root;
}

//constructor
MaxLeftistHeap::MaxLeftistHeap(int *arr, int size)
{
    //assign size
    this->size = size;

    //push into queue
    queue<LeftistNode*> q;
    for(int i=0; i<size; i++){
        LeftistNode *newNode = new LeftistNode;
        newNode->data = arr[i];
        q.push(newNode);
    }

    //pop two elements and then meld before push back into the queue
    while(q.size() >= 2){
        //pop two elements
        LeftistNode *h1 = q.front();
        q.pop();
        LeftistNode *h2 = q.front();
        q.pop();

        //meld
        LeftistNode *h_meld = meld(h1, h2);

        //push back into queue
        q.push(h_meld);
    }

    root = q.front();
    q.pop();
}

int MaxLeftistHeap::peek()
{
    return root->data;
}

//for learning not necessary
void MaxLeftistHeap::preorderTraversal(LeftistNode *parent)
{
    if(NULL == parent){
        return;
    }

    cout << " " << parent->data;
    preorderTraversal(parent->left);
    preorderTraversal(parent->right);
}

//pop
int MaxLeftistHeap::pop()
{
    LeftistNode *pre = root;

    //meld two subtree
    root = meld(root->left, root->right);

    //delete
    delete pre;

    //update size
    size--;

    return pre->data;
}

//insert
void MaxLeftistHeap::insert(int input)
{
    LeftistNode *newNode = new LeftistNode;
    newNode->data = input;
    root = meld(root, newNode);

    //update size
    size++;
}

//merge
void MaxLeftistHeap::merge(MaxLeftistHeap &lh)
{
    root = meld(root, lh.root);
    size = size + lh.size;
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

    //generate data
    int *random_data = random_case(n);

#if DEBUG
    cout << "Before build Heap :";
    for(int i=0; i<n; i++){
        cout << random_data[i] << " ";
    }
    cout << endl;
#endif

    //constructor
    MaxLeftistHeap myHeap(random_data, n);
    cout << "myHeap size :" << myHeap.size << endl;

    cout << "The root is :" << myHeap.root->data <<
         ", s-value :" << myHeap.root->s_value <<endl;

    cout << "preorder Traversal :";
    myHeap.preorderTraversal(myHeap.root);
    cout << endl;

    //insertion
    int input = 7;
    cout << "Heap Insertion :" << input << endl;
    myHeap.insert(input);
    cout << "myHeap size :" << myHeap.size << endl;

    //merge
    int *random_data2 = random_case(n*2);
    MaxLeftistHeap myHeap2(random_data2, n*2);
    myHeap.merge(myHeap2);
    cout << "myHeap size :" << myHeap.size << endl;

    //pop
    cout << "Heap sort :";
    int size = myHeap.size;
    for(int i=0; i<size; i++){
        cout << myHeap.pop() << " ";
    }
    cout << endl;

    return 0;
}
/*==============================================================*/