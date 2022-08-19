#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};

class Stack{
    Node* head;
    Node* top;
    int count=0;

public:
    //initialization
    Stack(){
        head=NULL;
        top=NULL;
    }
    //push
    void push(int val){
        Node* newNode = new Node(val);

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
    int pop(){
        Node *delNode=top;
        int res=-1;
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
    int Top(){
        if(top==NULL){
            cout<<"Empty Stack/ underflow operation"<<endl;
            return -1;
        }
        return top->val;
    }
    //size
    int size(){
        return count;
    }
};
