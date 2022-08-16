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

struct Search{
    int position[1000];
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

void reversedListPrint(Node *n) {
    if (n != NULL) {
        reversedListPrint(n->Next);
        cout<<n->value<<" ";
    }
}

int lengthOfLinkedList(Node *&head){
    int length=0;
    Node *temp=head;
    while(temp != NULL){
        length++;
        temp=temp->Next;
    }
    return length;
}

void insertAtPosition(Node *&head, int pos, int val){
    Node *newNode= new Node(val);
    Node *temp=head;
    int count=1;//count=0
    while(count<pos-1){//count<pos-2
        temp=temp->Next;
        count++;
    }
    newNode->Next=temp->Next;
    temp->Next=newNode;
}

int searchByValueUnique(Node *&head, int val){
    Node *temp=head;
    if(temp==NULL)return -1;
    int count=1;
    while(temp->value != val){
        if(temp->Next == NULL)return -1;
        temp=temp->Next;
        count++;
    }
    return count;
}

void searchByValueDuplicate(Node *&head, int val){
    Node* temp=head;
    int size=lengthOfLinkedList(head);
    int count=1, k=1, positions[size+1];
    bool isFound=false;
    while(temp!=NULL){
        if(temp->value==val){
            positions[k]=count;
            isFound=true;
            k++;
        }
        count++;
        temp=temp->Next;
    }
    positions[0]=k;
    if(!isFound)cout<<"The number is not yet in the list"<<endl;
    else{
        cout<<"Your number is in position: ";
        int i=1;
        while(i<positions[0]){
            cout<<positions[i];
            if(i<positions[0]-1)cout<<" -> ";
            i++;
        }
        cout<<endl;
    }
}

Search searchByValueDuplicateReturn(Node *&head, int val){
    Node* temp=head;
    Search search;
    int count=1, k=1;
    while(temp!=NULL){
        if(temp->value==val){
            search.position[k]=count;
            k++;
        }
        count++;
        temp=temp->Next;
    }
    search.position[0]=k;
    return search;
}

void insertAfterValueInUniqueList(Node *&head, int sVal, int val){
    int pos=searchByValueUnique(head, sVal);
    insertAtPosition(head, pos+1, val);
}

void insertAfterValueInDuplicateList(Node *&head, int sVal, int val){
    Search search;
    search=searchByValueDuplicateReturn(head, sVal);
    for(int i=1; i<search.position[0]; i++){
        int pos=search.position[i]+i;
        insertAtPosition(head, pos, val);
    }
}

void deleteAtHead(Node *&head){
    if(head==NULL)cout<<"There is no value in the linked list."<<endl;
    else{
        Node* temp=head;
        head=temp->Next;
        delete temp;
    }
}

void deleteAtTail(Node *&head){
    Node* temp=head;
    if(temp==NULL)cout<<"There is no value in the linked list"<<endl;
    else if(temp->Next==NULL)deleteAtHead(head);
    else{
        while(temp->Next->Next != NULL){
            temp=temp->Next;
        }
        Node *delNode=temp->Next;
        temp->Next=NULL;
        delete delNode;
        cout<<"Deletion at tail is successful."<<endl;
    }
}

void deleteAtPosition(Node *&head, int pos){
    Node *temp=head;
    if(temp->Next==NULL || pos==1){
        deleteAtHead(head);
        return;
    }

    int i=1;
    while(i<pos-1){
        temp=temp->Next;
        i++;
    }
    if(temp->Next==NULL)cout<<"Your Entered Position does not exist in the linked list"<<endl;
    //else if(temp->Next->Next==NULL)deleteAtTail(head);
    else{
        Node *delNode=temp->Next;
        temp->Next=delNode->Next;
        delete delNode;
    }
}

void deleteByValue(Node *&head, int val){
    Node* temp=head;
    int pos=searchByValueUnique(head, val);
    if(pos != -1)deleteAtPosition(head,pos);
    else cout<<"The value does not exist in the linked list"<<endl;
}

void deleteByValueDuplicate(Node *&head, int val){
    Search search;
    search=searchByValueDuplicateReturn(head, val);
    for(int i=1; i<search.position[0]; i++){
        int pos=search.position[i]-i+1;
        deleteAtPosition(head,pos);
    }
}

Node* reverseList(Node* &head){
    if(head->Next==NULL)return head;
    Node* prev=NULL;
    Node* current=head;
    Node* next=current->Next;
    while(1){
        current->Next=prev;
        prev=current;
        current=next;
        if(current==NULL)break;
        next=next->Next;
    }
    return prev;
}

Node* reverseListRecursively(Node* &head){
    //Base call
    if(head->Next==NULL)return head;
    //RECURSIVE CALL
    Node* newNode=reverseListRecursively(head->Next);
    head->Next->Next=head;
    head->Next=NULL;
    return newNode;
}

int main(){
    Node* head=NULL;
    int choice, value, pos, searchValue;
    cout<<"Choice 1: To insert at Head. "<<endl
        <<"Choice 2: To insert at Tail. "<<endl
        <<"Choice 3: To insert at Specific Position. "<<endl
        <<"Choice 4: To Search a value in Unique List. "<<endl
        <<"Choice 5: To Search a value in Duplicate Enabled List. "<<endl
        <<"Choice 6: Insert after a value in Unique List. "<<endl
        <<"Choice 7: Insert after a value in Duplicate eNABLED List. "<<endl
        <<"Choice 8: Deletion at Head "<<endl
        <<"Choice 9: Deletion at Tail "<<endl
        <<"Choice 10: Deletion at Specific Position "<<endl
        <<"Choice 11: Deletion by Value.(Unique List)"<<endl
        <<"Choice 12: Deletion by Value (Duplicate Enabled List)."<<endl
        <<"Choice 13: Display the Linked List "<<endl
        <<"Choice 14: Reverse the Linked List(Non recursively) "<<endl
        <<"Choice 15: Reverse the Linked List(Recursively) "<<endl
        <<"Choice 0: To Exit "<<endl;
    cin>>choice;

    while(choice){
        switch(choice){
            case 1:
                cout<<"Enter Number : ";
                cin>>value;
                insertAtHead(head,value);
                break;

            case 2:
                cout<<"Enter Number : ";
                cin>>value;
                insertAtTail(head,value);
                break;

            case 3:
                cout<<"Enter Position : ";
                cin>>pos;
                cout<<"Enter Number : ";
                cin>>value;
                insertAtPosition(head, pos, value);
                break;

            case 4:
                cout<<"Enter Your Desired Number : ";
                cin>>value;
                pos=searchByValueUnique(head, value);
                if(pos == -1)cout<<"The Number is not Found in the list"<<endl;
                else cout<<"The position of your number in the list is "<<pos<<endl;
                break;

            case 5:
                cout<<"Enter Your Desired Number : ";
                cin>>value;
                //searchByValueDuplicate(head, value);
                Search srch;
                srch=searchByValueDuplicateReturn(head, value);
                if(srch.position[0] == 1)cout<<"The Number is not Found in the list"<<endl;
                else {
                    cout<<"The position of your number in the list is ";
                    for(int i=1; i<srch.position[0]; i++){
                        cout<<srch.position[i];
                        if(i<srch.position[0]-1)cout<<" -> ";
                    }
                    cout<<endl;
                }
                break;

            case 6:
                cout<<"Enter the value after which you want to inserted ";
                cin>>searchValue;
                cout<<"Enter the value to be inserted ";
                cin>>value;
                insertAfterValueInUniqueList(head, searchValue, value);
                break;

            case 7:
                cout<<"Enter the value after which you want to inserted ";
                cin>>searchValue;
                cout<<"Enter the value to be inserted ";
                cin>>value;
                insertAfterValueInDuplicateList(head, searchValue, value);
                break;

            case 8:
                deleteAtHead(head);
                break;

            case 9:
                deleteAtTail(head);
                break;

            case 10:
                if(head==NULL){
                    cout<<"Linked list is Empty."<<endl;
                    break;
                }
                cout<<"Enter the position you want to delete ";
                cin>>pos;
                deleteAtPosition(head, pos);
                break;

            case 11:
                if(head==NULL){
                    cout<<"Linked list is Empty."<<endl;
                    break;
                }
                cout<<"Enter the value you want to delete ";
                cin>>value;
                deleteByValue(head, value);
                break;

            case 12:
                if(head==NULL){
                    cout<<"Linked list is Empty."<<endl;
                    break;
                }
                cout<<"Enter the value you want to delete ";
                cin>>value;
                deleteByValueDuplicate(head, value);
                break;

            case 13:
                if(head==NULL){
                    cout<<"Linked list is Empty."<<endl;
                }
                else display(head);
                cout<<endl;
                break;

            case 14:
                if(head==NULL){
                    cout<<"Linked list is Empty."<<endl;
                }
                else head=reverseList(head);
                break;

            case 15:
                if(head==NULL){
                    cout<<"Linked list is Empty."<<endl;
                }
                else head=reverseListRecursively(head);
                break;

            default:
                break;
        }
        cout<<"Next Choice: ";
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
    //cout<<endl;
    //display(head);
    cout<<endl;
    //reversedListPrint(head);
    cout<<endl;
    cout<<"The Length of Linked List is: "<<lengthOfLinkedList(head)<<endl;


return 0;
}
