#include<bits/stdc++.h>

using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;

    TreeNode(int val){
        this->data=val;
        this->leftChild=NULL;
        this->rightChild=NULL;
    }
};

void inOrder(TreeNode* root, int k){
    if(root==NULL)return;

    if(root->leftChild==NULL && root->rightChild==NULL){
        cout<<root->data;
        return;
    }

    inOrder(root->leftChild,k);
    cout<<root->data;
    inOrder(root->rightChild,k);
}

int main(){
//    int n,k;
//    cin>>n>>k;
//    TreeNode* allNodes[n];
//    for(int i=0; i<n; i++){
//        allNodes[i]=new TreeNode(-1);
//    }
//    for(int i=0; i<n; i++){
//        int val, left, right;
//        cin>>val>>left>>right;
//        allNodes[i]->data=val;
//
//        if(left>n-1 || right>n-1){
//            cout<<"Invalid index."<<endl;
//            break;
//        }
//
//        if(left!=-1)allNodes[i]->leftChild=allNodes[left];
//        if(right!=-1)allNodes[i]->rightChild=allNodes[right];
//    }
//    inOrder(allNodes[0], 0);
//    cout<<endl;

    int n;
    cin>>n;
    TreeNode* allNodes[n];
    for(int i=0; i<n; i++){
        allNodes[i]=new TreeNode(-1);
    }

    allNodes[0]->data=0;
    allNodes[0]->leftChild=allNodes[1];
    allNodes[0]->rightChild=allNodes[2];

    allNodes[1]->data=1;
    allNodes[1]->leftChild=allNodes[3];
    allNodes[1]->rightChild=allNodes[4];

    allNodes[2]->data=2;
    allNodes[2]->leftChild=allNodes[5];
    allNodes[2]->rightChild=allNodes[6];

    allNodes[3]->data=3;

    allNodes[4]->data=4;

    allNodes[5]->data=5;
    allNodes[5]->leftChild=allNodes[7];
    allNodes[5]->rightChild=allNodes[8];

    allNodes[6]->data=6;

    allNodes[7]->data=7;

    //allNodes[8]->data=8;

    inOrder(allNodes[0],0);
return 0;
}
