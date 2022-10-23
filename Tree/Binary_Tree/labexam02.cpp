#include<bits/stdc++.h>

using namespace std;

class  Node
{
public:
    char data;
    Node* leftChild;
    Node* rightChild;

    Node(char val)
    {
        this->data=val;
        this->leftChild=NULL;
        this->rightChild=NULL;
    }
};

void levelOrder(Node* root)
{

    if(root==NULL)return;

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* chkNode=q.front();
        q.pop();

        if(chkNode!=NULL)
        {
            cout<<chkNode->data<<" ";
            if(chkNode->leftChild!=NULL)q.push(chkNode->leftChild);
            if(chkNode->rightChild!=NULL)q.push(chkNode->rightChild);
        }
        else
        {
            if(!q.empty())q.push(NULL);
        }
    }
}

void inOrder(Node* root){
    if(root==NULL)return;

    inOrder(root->leftChild);
    cout<<root->data<<" ";
    inOrder(root->rightChild);
};

void printPathLeft(Node* root, string &left){
    if(root==NULL)return;

    if(root->leftChild==NULL && root->rightChild==NULL){
        left+=root->data;
        return;
    }

    left+=root->data;
    if(root->leftChild!=NULL)printPathLeft(root->leftChild, left);

};

void printPathRight(Node* root, string &right){
    if(root==NULL)return;

    if(root->leftChild==NULL && root->rightChild==NULL){
        right+=root->data;
        return;
    }

    right+=root->data;

    if(root->rightChild!=NULL)printPathRight(root->rightChild, right);

};

int main()
{
    string str;
    cin>>str;
    int r1;
    cin>>r1;
    Node* root1=new Node(str[r1]);

    queue<Node*>q1;
    q1.push(root1);

    while(!q1.empty())
    {
        Node* currentNode=q1.front();
        q1.pop();
        int left, right;
        cin>>left>>right;
        Node* n1=NULL;
        Node* n2=NULL;
        if(left!=-1)n1=new Node(str[left]);
        if(right!=-1)n2=new Node(str[right]);
        //connecting new node to parent node
        currentNode->leftChild=n1;
        currentNode->rightChild=n2;
        // keeping new node to queue for adding children
        if(n1!=NULL)q1.push(n1);
        if(n2!=NULL)q1.push(n2);
    }



    string left="";
    printPathLeft(root1, left);
    cout<<left<<endl;

    string right="";
    printPathRight(root1, right);
    cout<<right<<endl;






    return 0;
};




