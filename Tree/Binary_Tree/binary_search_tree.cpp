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
treeNode* insertionBST(treeNode* root, int val);
treeNode* searchBST(treeNode* root, int val);
treeNode* deletionBST(treeNode* root, int val);
treeNode* inorderSuccessor(treeNode* root);
void zigZagTraversal(treeNode* root);

int main(){
    int n;
    cin>>n;
    treeNode* root=NULL;

    for(int i=0; i<n; i++){
        int val;
        cin>>val;
        root=insertionBST(root, val);
    }
    string inorderStr="";
    inOrder(root, inorderStr);
    cout<<inorderStr<<endl<<endl;

    zigZagTraversal(root);

//    int key;
//    cin>>key;
//    if(searchBST(root, key)==NULL)cout<<endl<<"value does not exist"<<endl;
//    else cout<<endl<<"value exist in BST"<<endl;

//    root=deletionBST(root, key);
//
//    string inStrafterDeletion="";
//    inOrder(root, inStrafterDeletion);
//    cout<<inStrafterDeletion<<endl;

    //11
    //11 5 9 43 34 1 2 7 8 21

return 0;
}

void zigZagTraversal(treeNode* root){
    stack<treeNode*>currentLevel;
    stack<treeNode*>nextLevel;

    bool leftToRight=true;
    currentLevel.push(root);

    while(!currentLevel.empty()){
        treeNode* x=currentLevel.top();
        currentLevel.pop();

        cout<<x->data<<" ";

        if(leftToRight){
            if(x->leftChild)nextLevel.push(x->leftChild);
            if(x->rightChild)nextLevel.push(x->rightChild);
        }
        else{
            if(x->rightChild)nextLevel.push(x->rightChild);
            if(x->leftChild)nextLevel.push(x->leftChild);
        }

        if(currentLevel.empty()){
            leftToRight=!leftToRight;
            swap(nextLevel,currentLevel);
        }
    }
};

treeNode* inorderSuccessor(treeNode* root){
    treeNode* currentNode= root;
    while(currentNode->leftChild !=NULL){
        currentNode=currentNode->leftChild;
    }
    return currentNode;
};

treeNode* deletionBST(treeNode* root, int val){
    if(val<root->data){
        root->leftChild=deletionBST(root->leftChild, val);
    }
    else if(val>root->data){
        root->rightChild=deletionBST(root->rightChild, val);
    }
    else{
        // implementation of 3 case
        if(root->leftChild==NULL){
            treeNode* temp=root->rightChild;
            free(root);
            return temp;
        }
        else if(root->rightChild==NULL){
            treeNode* temp=root->leftChild;
            free(root);
            return temp;
        }
        else{
            treeNode* temp=inorderSuccessor(root->rightChild);
            root->data=temp->data;
            root->rightChild=deletionBST(root->rightChild, temp->data);
        }
        return root;
    }
};

treeNode* searchBST(treeNode* root, int val){
    if(root==NULL)return NULL;

    if(root->data==val){
        cout<<root->data;
        return root;
    }

    if(val < root->data){
        cout<<root->data<<" -> ";
        searchBST(root->leftChild, val);
    }
    else{
        cout<<root->data<<" -> ";
        searchBST(root->rightChild, val);
    }
};

treeNode* insertionBST(treeNode* root, int val){
    treeNode* newNode=new treeNode(val);
    if(root==NULL){
        root=newNode;
        return root;
    }
    //if val < root->data
    if(val<root->data){
        root->leftChild=insertionBST(root->leftChild, val);
        return root;
    }
    //if val > root->data
    if(val>root->data){
        root->rightChild=insertionBST(root->rightChild, val);
        return root;
    }
};

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
    inStr+=to_string(root->data)+" ";
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

