#include<bits/stdc++.h>

using namespace std;

struct node
{
   int data;
   struct node *leftChild;
   struct node *rightChild;
};

typedef struct node bst;

bst *rot = NULL;

bst* insrt(bst* root,int val)
{
    if(root == NULL)
    {
        bst *newNode = (bst*)malloc(sizeof(bst));
        newNode->data = val;
        newNode ->leftChild = NULL;
        newNode ->rightChild = NULL;
        root = newNode;
    }
    else if(val <= root->data)
    {
        root->leftChild = insrt(root->leftChild,val);
    }
    else if(val > root->data)
    {
        root->rightChild = insrt(root->rightChild,val);
    }

    return root;
}


bool srch(bst* root, int val)
{
    if(root == NULL)return false;
    else if(root->data == val) return true;
    else if(val <= root->data) return srch(root->leftChild,val);
    else return srch(root->rightChild,val);

}

void pre(bst *root)
{
    if(!root)return;

    cout << root->data << " ";
    pre(root->leftChild);
    pre(root->rightChild);
}

void post(bst* root)
{
    if(!root)return;

    post(root->leftChild);
    post(root->rightChild);
    cout << root->data << " ";
}

void in(bst* root)
{
    if(!root)return;

    in(root->leftChild);
    cout << root->data << " ";
    in(root->rightChild);

}

int main()
{
    bst* root = insrt(rot,14);
    insrt(root,52);
    insrt(root,5);

    cout << "Pre-order: ";
    pre(root);
    cout << endl << "post-order:" << " ";
    post(root);
    cout << endl <<  "In-order: ";
    in(root);



//    if(srch(root,5))cout << " found  " << endl;
//    else cout << "not found" << endl;




    return 0;
}
