#include<bits/stdc++.h>
using namespace std;

template<typename N> class Node{
public:
    N val;
    Node* next;
    Node* prev;

    Node(N val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};

template<typename S> class Stack{
    Node<S> *head;
    Node<S> *top;
    int count=0;

public:
    //initialization
    Stack(){
        head=NULL;
        top=NULL;
    }
    //push
    void push(S val){
        Node<S> *newNode = new Node<S>(val);

        if(head==NULL){
            head=top=newNode;
            count++;
            return;
        }

        top->next=newNode;
        newNode->prev=top;
        top=newNode;
        count++;
    }
    //pop
    S pop(){
        Node<S> *delNode=top;
        S res;
        if(head==NULL){
            cout<<"Stack Underflow/Empty Stack"<<endl;
            return res;
        }
        if(head==top){
            head=top=NULL;
        }
        else{
            top=delNode->prev;
            top->next=NULL;
        }
        res=delNode->val;
        delete delNode;
        count--;
        return res;
    }
    //empty
    bool empty(){
        if(head==NULL)return true;
        else return false;
    }
    //Top
    S Top(){
        S chk;
        if(top==NULL){
            cout<<"Empty Stack/ underflow operation"<<endl;
            return chk;
        }
        chk=top->val;
        return chk;
    }
    //size
    int size(){
        return count;
    }
};
