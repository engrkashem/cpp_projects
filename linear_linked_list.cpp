#include<bits/stdc++.h>

using namespace std;


class Node{
public:
    int value;
    Node *Next;

    Node(int val){
        value=val;
        Next=NULL;
    }
};

void insertAtTail(Node* &head, int val){
    Node *newNode= new Node(val);
    if(head==NULL) {
        head=newNode;
        return;
    }
    Node *temp=head;

    while(temp->Next!=NULL){
        temp=temp->Next;
    }
    temp->Next=newNode;

}

void insertAtHead(Node* &head, int val){
    //creation of a new node
    Node *newNode=new Node(val);
    //update newnode-> next by head address
    newNode->Next=head;
    //update head
    head=newNode;
}

void display(Node* n){
    while(n!=NULL){
        cout<<n->value<<" ";
        n = n->Next;
    }
}

int main(){
    Node* head=NULL;
    int choice=2;
    while(choice==1 || choice==2){
        cout<<"Enter Number : ";
        int n;
        cin>>n;
        if(choice==1)insertAtHead(head,n);
        else insertAtTail(head,n);
        cout<<"Choice 1: To insert at Head. "<<endl;
        cout<<"Choice 2: To insert at Tail. "<<endl;
        cout<<"Choice any other number: To Exit "<<endl;
        cin>>choice;
    }

    //insertAtTail(head,5);
    //insertAtTail(head,8);
    //insertAtTail(head,9);
    //insertAtTail(head,10);

    //Node* second=new Node();
    //Node* third=new Node();
    //Node* fourth=new Node();

    //head->value = 1;
    //head->Next = second;
    //second->value = 5;
    //second->Next = third;
    //third->value = 8;
    //third->Next = fourth;
    //fourth->value = 9;
    //fourth->Next = NULL;

    display(head);

return 0;
}
