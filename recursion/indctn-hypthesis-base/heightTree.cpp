#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left = NULL;
    struct node* right = NULL;
};

node* newnode(int data){
    node* temp = new node;
    temp->data = data;
    return temp;
}

int hghtCal(node* root){
    if(root==NULL) return 0;
    else return 1+max(hghtCal(root->left),hghtCal(root->right));
}

int main(){
    // Tree structure
    //         1
    //        /
    //       2
    //        \
    //         3
    //        / \
    //       4   5
    //      /   / \
    //     6   7   8
    node* root = newnode(1);
    root->left = newnode(2);
    root->left->right = newnode(3);
    root->left->right->left = newnode(4);
    root->left->right->right = newnode(5);
    root->left->right->left->left = newnode(6);
    root->left->right->right->left = newnode(7);
    root->left->right->right->right = newnode(8);
    cout<<hghtCal(root);
}
