/*****************************************************************
Name    :BT_from_array
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20181225 Initial Version
*****************************************************************/
#include <iostream>
#include <sstream>
#include <queue>
using namespace std;
/*==============================================================*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(-1), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree{
private:
    void LevelorderConstruct(stringstream &ss);
public:
    TreeNode *root;
    BinaryTree(const char *str);
    void preorderTraversal(TreeNode *parent);
    void inorderTraversal(TreeNode *parent);
    void postorderTraversal(TreeNode *parent);
};

BinaryTree::BinaryTree(const char *str)
{
    stringstream ss;
    ss << str;

    root = new TreeNode;
    ss >> root->val;

    LevelorderConstruct(ss);
}

void BinaryTree::LevelorderConstruct(stringstream &ss)
{
    queue<TreeNode*> q;
    TreeNode *current = root;
    char input;

    while(ss >> input){
        cout << "input=" << input << endl;

        //handle the left child
        if(input != 'x'){
            TreeNode *newNode = new TreeNode(input-'0');
            current->left = newNode;
            q.push(newNode);
        }

        if(!(ss >> input)){
            break;
        }
        
        if(input != 'x'){
            TreeNode *newNode = new TreeNode(input-'0');
            current->right = newNode;
            q.push(newNode);
        }

        current = q.front();
        q.pop();
    }
}

void BinaryTree::preorderTraversal(TreeNode *parent)
{
    if(NULL == parent){
        return;
    }

    //do the right things
    cout << " " << parent->val;
    preorderTraversal(parent->left);
    preorderTraversal(parent->right);
}

void BinaryTree::inorderTraversal(TreeNode *parent)
{
    if(NULL == parent){
        return;
    }

    inorderTraversal(parent->left);
    //do the right things
    cout << " " << parent->val;
    inorderTraversal(parent->right);
}

void BinaryTree::postorderTraversal(TreeNode *parent)
{
    if(NULL == parent){
        return;
    }

    postorderTraversal(parent->left);
    postorderTraversal(parent->right);
    //do the right things
    cout << " " << parent->val;
}

int main(int argc, char const *argv[]){
    const char *input = "1 2 3 x x 4 5 6 7";
    BinaryTree BT(input);

    TreeNode *temp = BT.root->right;
    cout << "test : " << temp->right->val << endl;

    cout << "inorder :";
    BT.inorderTraversal(BT.root);
    cout << endl;

    cout << "preorder :";
    BT.preorderTraversal(BT.root);
    cout << endl;

    cout << "postorder :";
    BT.postorderTraversal(BT.root);
    cout << endl;

    return 0;
}
/*==============================================================*/