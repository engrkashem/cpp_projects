#include<bits/stdc++.h>

using namespace std;

template<typename N> class Node{
public:
    N val;
    Node* next;

    Node(N val){
        this->val=val;
        this->next=NULL;
    }
    //friend class Queue;
};

template<typename Q> class Queue{
    Node<Q> *first;
    Node<Q> *rear;
    int count=0;

public:
    Queue(){
        first=NULL;
        rear=NULL;
    }

    void push(Q val){
        Node<Q> *newNode=new Node<Q>(val);
        if(first==NULL){
            first=newNode;
            rear=newNode;
            count++;
            return;
        }
        rear->next=newNode;
        rear=rear->next;
        count++;
    }

    Q pop(){
        Q result;
        if(rear==NULL){
            cout<<"Queue Underflow | Empty Queue."<<endl;
            return result;
        }
        Node<Q> *delNode=first;
        first=first->next;
        if(first==NULL)rear=NULL;
        result=delNode->val;
        delete delNode;
        count--;
        return result;
    }

    Q front(){
        Q result=first->val;
        return result;
    }

    Q back(){
        Q result=rear->val;
        return result;
    }

    bool empty(){
        if(first==NULL && rear==NULL)return true;
        else return false;
    }

    int size(){
        return count;
    }

};

