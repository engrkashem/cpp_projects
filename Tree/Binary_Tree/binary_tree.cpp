#include<bits/stdc++.h>

using namespace std;

class treeNode{
public:
    int data;
    treeNode* leftChild;
    treeNode* rightChild;

    treeNode(int val){
    this->data=val;
    this->leftChild=NULL;
    this->rightChild=NULL;
    }
};

void printTreePreOrder(treeNode* root, int level);
void printSpace(int level);
void inOrder(treeNode* root, string &inStr);
void preOrder(treeNode* root, string &inStr);
void postOrder(treeNode* root, string &inStr);
void levelOrder(treeNode* root, string &inStr);
void printTreePostOrder(treeNode* root, int level);
void printTreeInOrder(treeNode* root, int level);
int maxAtKLevel(treeNode* root, int k);
void printLeaves(treeNode* root);
void printLBnonLeaves(treeNode* root);
void printRBnonLeaves(treeNode* root);
void boundaryTraversal(treeNode* root);

int main(){
    int n;
    cin>>n;
    treeNode* allNodes[n];

    for(int i=0; i<n; i++){
        allNodes[i]=new treeNode(-1);
    }

    for(int i=0; i<n; i++){
        int val, left, right;
        cin>>val>>left>>right;
        allNodes[i]->data=val;
        if(left>n-1 || right>n-1){
            cout<<"Invalid Index. "<<endl;
            break;
        }
        if(left!=-1)allNodes[i]->leftChild=allNodes[left];

        if(right!=-1)allNodes[i]->rightChild=allNodes[right];
    }
//    printTreePreOrder(allNodes[0], 0);
//    cout<<endl<<endl;
//    printTreePostOrder(allNodes[0], 0);
//    cout<<endl<<endl;
//    printTreeInOrder(allNodes[0], 0);

    cout<<endl<<endl;
    string inOrderTraversal="";
    inOrder(allNodes[0], inOrderTraversal);
    cout<<"Inorder traversal: "<<inOrderTraversal<<endl;

    string preOrderTraversal="";
    preOrder(allNodes[0], preOrderTraversal);
    cout<<"Preorder traversal: "<<preOrderTraversal<<endl;

    string postOrderTraversal="";
    postOrder(allNodes[0], postOrderTraversal);
    cout<<"Postorder traversal: "<<postOrderTraversal<<endl;

    string levelOrderTraversal="";
    levelOrder(allNodes[0],levelOrderTraversal);
    cout<<"Level Order Traversal: "<<levelOrderTraversal<<endl<<endl;

//    int maxAtLevelK=maxAtKLevel(allNodes[0], k);
//    cout<<"Maximun Value at "<<k<<" is: "<<maxAtLevelK<<endl;

    boundaryTraversal(allNodes[0]);

return 0;
}

void printLeaves(treeNode* root){
    if(root==NULL)return;

    if(root->leftChild==NULL && root->rightChild==NULL){
        cout<<root->data<<" ";
        return;
    }

    if(root->leftChild!=NULL)printLeaves(root->leftChild);

    if(root->rightChild!=NULL)printLeaves(root->rightChild);
};

void printLBnonLeaves(treeNode* root){
    if(root==NULL)return;

    if(root->leftChild!=NULL){
        cout<<root->data<<" ";
        printLBnonLeaves(root->leftChild);
    }
    else if(root->rightChild!=NULL){
        cout<<root->data<<" ";
        printLBnonLeaves(root->rightChild);
    }
};

void printRBnonLeaves(treeNode* root){
    if(root==NULL)return;

    if(root->rightChild!=NULL){
        cout<<root->data<<" ";
        printRBnonLeaves(root->rightChild);
    }
    else if(root->leftChild!=NULL){
        cout<<root->data<<" ";
        printRBnonLeaves(root->leftChild);
    }
};

void boundaryTraversal(treeNode* root){
    if(root==NULL)return;
    cout<<"Boundary Traversal: ";
    //print root first
    cout<<root->data<<" ";
    //LB non leaves printing
    printLBnonLeaves(root->leftChild);
    //LB leaves printing
    printLeaves(root->leftChild);
    //RB leaves printing
    printLeaves(root->rightChild);
    //RB non leaves printing
    printRBnonLeaves(root->rightChild);
};

void preOrder(treeNode* root, string &preStr){
    if(root==NULL)return;

    preStr+=to_string(root->data);
    preOrder(root->leftChild, preStr);
    preOrder(root->rightChild, preStr);
};

void postOrder(treeNode* root, string &postStr){
    if(root==NULL)return;

    postOrder(root->leftChild, postStr);
    postOrder(root->rightChild, postStr);
    postStr+=to_string(root->data);
};

void inOrder(treeNode* root, string &inStr){
    if(root==NULL)return;

    inOrder(root->leftChild, inStr);
    inStr+=to_string(root->data);
    inOrder(root->rightChild, inStr);
};

void levelOrder(treeNode* root, string &inStr){

    if(root==NULL)return;

    queue<treeNode*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        treeNode* chkNode=q.front();
        q.pop();

        if(chkNode!=NULL){
            //cout<<chkNode->data<<" ";
            inStr+=to_string(chkNode->data);
            if(chkNode->leftChild!=NULL)q.push(chkNode->leftChild);
            if(chkNode->rightChild!=NULL)q.push(chkNode->rightChild);
        }
        else{
            if(!q.empty())q.push(NULL);
        }
    }
};

int maxAtKLevel(treeNode* root, int k){
    if(root==NULL)return -1;

    queue<treeNode*> q;
    q.push(root);
    q.push(NULL);

    int level=0, max=INT_MIN;

    while(!q.empty()){
        treeNode* chkNode=q.front();
        q.pop();

        if(chkNode!=NULL){
            if(level==k){
                if(max<chkNode->data)max=chkNode->data;
            }
            if(chkNode->leftChild!=NULL)q.push(chkNode->leftChild);
            if(chkNode->rightChild!=NULL)q.push(chkNode->rightChild);
        }
        else{
            if(!q.empty()){
                q.push(NULL);
                level++;
            }
        }
    }
    return max;
};

void printTreePreOrder(treeNode* root, int level){
    if(root==NULL)return;

    if(root->leftChild==NULL && root->rightChild==NULL){//for leaf node
        cout<<root->data<<endl;
        return;
    }
    else{
        cout<<endl;
        printSpace(level);
        cout<<"Root: "<<root->data<<endl;
    }

    if(root->leftChild!=NULL){
        printSpace(level);
        cout<<"Left: ";
        printTreePreOrder(root->leftChild, level+1);
    }
    if(root->rightChild!=NULL){
        printSpace(level);
        cout<<"Right: ";
        printTreePreOrder(root->rightChild, level+1);
    }
};

void printTreePostOrder(treeNode* root, int level){
    if(root==NULL)return;
    if(root->leftChild==NULL && root->rightChild==NULL){
        cout<<root->data<<endl;
        return;
    }
    cout<<endl;
    printSpace(level);
    cout<<"Left: ";
    printTreePostOrder(root->leftChild, level+1);
    //cout<<endl;
    printSpace(level);
    cout<<"Right: ";
    printTreePostOrder(root->rightChild, level+1);
    printSpace(level);
    cout<<"Root: "<<root->data<<endl;
};

void printTreeInOrder(treeNode* root, int level){
    if(root==NULL)return;

    if(root->leftChild==NULL && root->rightChild==NULL){
        cout<<root->data<<endl;
        return;
    }

    cout<<endl;
    printSpace(level);
    cout<<"Left: ";
    printTreeInOrder(root->leftChild, level+1);

    printSpace(level);
    cout<<"Root: "<<root->data<<endl;

    printSpace(level);
    cout<<"Right: ";
    printTreeInOrder(root->rightChild, level+1);
};

void printSpace(int level){
    for(int i=0; i<level; i++){
        cout<<"    ";
    }
};
