#include<bits/stdc++.h>

using namespace std;

class treeNode
{
public:
    int data;
    treeNode* leftChild;
    treeNode* rightChild;

    treeNode(int val)
    {
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
treeNode* constTreePreIn(int preOrder[], int inOrder[], int start, int end);
int searchInorder(int inOrder[], int current, int start, int end);

int main()
{
    int n;
    cin>>n;
    int preOrderAr[n], inOrderAr[n];
    for(int i=0; i<n; i++)
    {
        cin>>preOrderAr[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>inOrderAr[i];
    }

    treeNode* root= constTreePreIn(preOrderAr, inOrderAr, 0, n-1);

    string strPre="";
    preOrder(root, strPre);
    cout<<strPre<<endl<<endl;

    return 0;
}

int searchInorder(int inOrder[], int current, int start, int end){
    for(int i=start; i<=end; i++){
        if(inOrder[i]==current)return i;
    }
    return -1;
}

treeNode* constTreePreIn(int preOrder[], int inOrder[], int start, int end){
    static int index=0;
    int current=preOrder[index];
    index++;
    treeNode* newNode=new treeNode(current);

    if(start==end)return newNode;

    int pos=searchInorder(inOrder, current, start, end);

    newNode->leftChild = constTreePreIn(preOrder, inOrder, start, pos-1);
    newNode->rightChild = constTreePreIn(preOrder, inOrder, pos+1, end);

    return newNode;
}

void preOrder(treeNode* root, string &preStr)
{
    if(root==NULL)return;

    preStr+=to_string(root->data);
    preOrder(root->leftChild, preStr);
    preOrder(root->rightChild, preStr);
};

void postOrder(treeNode* root, string &postStr)
{
    if(root==NULL)return;

    postOrder(root->leftChild, postStr);
    postOrder(root->rightChild, postStr);
    postStr+=to_string(root->data);
};

void inOrder(treeNode* root, string &inStr)
{
    if(root==NULL)return;

    inOrder(root->leftChild, inStr);
    inStr+=to_string(root->data);
    inOrder(root->rightChild, inStr);
};

void levelOrder(treeNode* root, string &inStr)
{

    if(root==NULL)return;

    queue<treeNode*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        treeNode* chkNode=q.front();
        q.pop();

        if(chkNode!=NULL)
        {
            //cout<<chkNode->data<<" ";
            inStr+=to_string(chkNode->data);
            if(chkNode->leftChild!=NULL)q.push(chkNode->leftChild);
            if(chkNode->rightChild!=NULL)q.push(chkNode->rightChild);
        }
        else
        {
            if(!q.empty())q.push(NULL);
        }
    }
};

int maxAtKLevel(treeNode* root, int k)
{
    if(root==NULL)return -1;

    queue<treeNode*> q;
    q.push(root);
    q.push(NULL);

    int level=0, max=INT_MIN;

    while(!q.empty())
    {
        treeNode* chkNode=q.front();
        q.pop();

        if(chkNode!=NULL)
        {
            if(level==k)
            {
                if(max<chkNode->data)max=chkNode->data;
            }
            if(chkNode->leftChild!=NULL)q.push(chkNode->leftChild);
            if(chkNode->rightChild!=NULL)q.push(chkNode->rightChild);
        }
        else
        {
            if(!q.empty())
            {
                q.push(NULL);
                level++;
            }
        }
    }
    return max;
};

void printTreePreOrder(treeNode* root, int level)
{
    if(root==NULL)return;

    if(root->leftChild==NULL && root->rightChild==NULL) //for leaf node
    {
        cout<<root->data<<endl;
        return;
    }
    else
    {
        cout<<endl;
        printSpace(level);
        cout<<"Root: "<<root->data<<endl;
    }

    if(root->leftChild!=NULL)
    {
        printSpace(level);
        cout<<"Left: ";
        printTreePreOrder(root->leftChild, level+1);
    }
    if(root->rightChild!=NULL)
    {
        printSpace(level);
        cout<<"Right: ";
        printTreePreOrder(root->rightChild, level+1);
    }
};

void printTreePostOrder(treeNode* root, int level)
{
    if(root==NULL)return;
    if(root->leftChild==NULL && root->rightChild==NULL)
    {
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

void printTreeInOrder(treeNode* root, int level)
{
    if(root==NULL)return;

    if(root->leftChild==NULL && root->rightChild==NULL)
    {
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

void printSpace(int level)
{
    for(int i=0; i<level; i++)
    {
        cout<<"    ";
    }
};

