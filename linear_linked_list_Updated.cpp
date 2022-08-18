#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *next;
    //constructor
    Node(int value){
        this->value=value;
        this->next=NULL;
    };
};
struct Search{
    int position[1000];
};

int getLength(Node *&root);
void displayList(Node *&root);
void insertHead(Node *&root, int value);
void insertTail(Node *&root, int value);
void insertPosition(Node *&root, int position, int value);
int searchValueUnique(Node *&root, int value);
Search searchValueDuplicate(Node *&root, int value);
void insertAfterValueUnique(Node *&root, int srcVal, int value);
void insertAfterValueDuplicate(Node *&root, int srcVal, int value);
void deleteHead(Node *&root);
void deleteTail(Node *&root);
void deletePosition(Node *&root, int position);
void deleteByValueUnique(Node *&root, int value);
void deleteByValueDuplicate(Node *&root, int value);
int findMid(Node* &root);
void createCycle(Node* &root, int position);
bool detectCycle(Node* root);
void removeCycle(Node* &root);

int main(){
    Node *root=NULL;
    int choice, value, position, srcVal;
    bool isCycle;
    cout<<"Choice 1: Counting the Size of Linked List"<<endl
        <<"Choice 2: Display Linked List"<<endl
        <<"Choice 3: Insertion at Head"<<endl
        <<"Choice 4: Insertion at Tail"<<endl
        <<"Choice 5: Insertion at Specific Position"<<endl
        <<"Choice 6: Search a value (Unique List)"<<endl
        <<"Choice 7: Search a value (Duplication enabled List)"<<endl
        <<"Choice 8: Insertion after a specific value (Unique List)"<<endl
        <<"Choice 9: Insertion after a specific value (Duplication enabled List)"<<endl
        <<"Choice 10: Deletion at Head"<<endl
        <<"Choice 11: Deletion at Tail"<<endl
        <<"Choice 12: Deletion at a Specific Position"<<endl
        <<"Choice 13: Deletion by Value (Unique List)"<<endl
        <<"Choice 14: Deletion by Value(Duplication enabled List)"<<endl
        <<"Choice 15: Find Mid Node if Linked List"<<endl
        <<"Choice 16: Create Cycle by Position in Linked List"<<endl
        <<"Choice 17: Detect Cycle in Linked List"<<endl
        <<"Choice 18: Remove Cycle in Linked List"<<endl
        <<"Choice 0: To Exit."<<endl;
        cin>>choice;

        while(choice){
            switch(choice){
            case 1:
                cout<<"Length of List = "<<getLength(root)<<endl;
                break;
            case 2:
                if(root==NULL){
                    cout<<"Linked List is Empty."<<endl;
                }
                else displayList(root);
                break;
            case 3:
                cout<<"Enter Value to Insert: ";
                cin>>value;
                insertHead(root, value);
                break;
            case 4:
                cout<<"Enter Value to Insert: ";
                cin>>value;
                insertTail(root, value);
                break;
            case 5:
                cout<<"Enter Value to Insert: ";
                cin>>value;
                cout<<"Enter Position where to insert: ";
                cin>>position;
                insertPosition(root, position, value);
                break;
            case 6:
                if(root==NULL){
                    cout<<"Linked List is Empty."<<endl;
                }
                else{
                    cout<<"Enter Value to Search: ";
                    cin>>value;
                    position=searchValueUnique(root, value);
                    if(position==-1)cout<<"Value does not exist in List"<<endl;
                    else cout<<"Position of "<<value<<" in List is "<<position<<endl;
                }
                break;
            case 7:
                if(root==NULL){
                    cout<<"Linked List is Empty."<<endl;
                }
                else{
                    cout<<"Enter Value to Search: ";
                    cin>>value;
                    Search res;
                    res=searchValueDuplicate(root, value);
                    if(res.position[1]== -1){
                        cout<<"Value does not exist in List"<<endl;
                        break;
                    }
                    cout<<"Positions of "<<value<<" in List are ";
                    for(int i=1; i<res.position[0]; i++ ){
                    cout<<res.position[i]<<" ";
                    }
                    cout<<endl;
                }
                break;
            case 8:
                if(root==NULL){
                    cout<<"Linked List is Empty."<<endl;
                }
                else{
                    cout<<"Enter Value to Insert: ";
                    cin>>value;
                    cout<<"Enter Value to Search: ";
                    cin>>srcVal;
                    insertAfterValueUnique(root, srcVal, value);
                }
                break;
            case 9:
                if(root==NULL){
                    cout<<"Linked List is Empty."<<endl;
                }
                else{
                    cout<<"Enter Value to Insert: ";
                    cin>>value;
                    cout<<"Enter Value to Search: ";
                    cin>>srcVal;
                    insertAfterValueDuplicate(root, srcVal, value);
                }
                break;
            case 10:
                if(root==NULL){
                    cout<<"Linked List is Empty."<<endl;
                }
                else deleteHead(root);
                break;
            case 11:
                if(root==NULL){
                    cout<<"Linked List is Empty."<<endl;
                }
                else deleteTail(root);
                break;
            case 12:
                if(root==NULL){
                    cout<<"Linked List is Empty."<<endl;
                }
                else{
                    cout<<"Enter Position where to insert: ";
                    cin>>position;
                    deletePosition(root, position);
                }
                break;
            case 13:
                if(root==NULL){
                    cout<<"Linked List is Empty."<<endl;
                }
                else{
                    cout<<"Enter Value to Delete: ";
                    cin>>value;
                    deleteByValueUnique(root, value);
                }
                break;
            case 14:
                if(root==NULL){
                    cout<<"Linked List is Empty."<<endl;
                }
                else{
                    cout<<"Enter Value to Delete: ";
                    cin>>value;
                    deleteByValueDuplicate(root, value);
                }
                break;
            case 15:
                if(root==NULL){
                    cout<<"Linked List is Empty."<<endl;
                }
                else{
                    int mid=findMid(root);
                    cout<<"The mid Node is ["<<mid<<"]"<<endl;
                }
                break;
            case 16:
                if(root==NULL){
                    cout<<"Linked List is Empty."<<endl;
                }
                else{
                    cout<<"Enter Position to create cycle ";
                    cin>>position;
                    createCycle(root, position);
                }
                break;
            case 17:
                if(root==NULL){
                    cout<<"Linked List is Empty."<<endl;
                }
                else{
                    isCycle=detectCycle(root);
                    if(isCycle)cout<<"Cycle is detected"<<endl;
                    else cout<<"There is NO cycle in the List"<<endl;
                }
                break;
            case 18:
                if(root==NULL){
                    cout<<"Linked List is Empty."<<endl;
                }
                else{
                    isCycle=detectCycle(root);
                    if(isCycle)removeCycle(root);
                    else cout<<"There is NO cycle in the List"<<endl;
                }
                break;

            default: break;
            }
            cout<<"Next Choice: ";
            cin>>choice;
        }

return 0;
};

int getLength(Node *&root){
    Node* temp=root;
    int c=0;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    return c;
};
void displayList(Node *&root){
    Node* temp=root;
    while(temp!=NULL){
        cout<<temp->value;
        if(temp->next!=NULL)cout<<" -> ";
        temp=temp->next;
    }
    cout<<endl;
};
void insertHead(Node *&root, int value){
    Node *newNode= new Node(value);
    newNode->next=root;
    root=newNode;
};
void insertTail(Node *&root, int value){
    Node *newNode=new Node(value);
    Node* temp=root;
    if(root==NULL)root=newNode;
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
};
void insertPosition(Node *&root, int position, int value){
    int size=getLength(root);
    if(position==1)insertHead(root, value);
    else if(position==size+1)insertTail(root, value);
    else if(position>size+1 || root==NULL || position<1){
        cout<<"position is not exist in List / Invalid"<<endl;
    }
    else{
        int count=1;
        Node *newNode=new Node(value);
        Node *temp=root;
        while(count<position-1){
            count++;
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
};
int searchValueUnique(Node *&root, int value){
    Node *temp=root;
    int c=1;
    while(temp!=NULL){
        if(temp->value == value)return c;
        c++;
        temp=temp->next;
    }
    return -1;
};
Search searchValueDuplicate(Node *&root, int value){
    Node *temp=root;
    Search res;
    int k=1, count=1, flag=0;
    while(temp!=NULL){
        if(temp->value == value){
            flag=1;
            res.position[k]=count;
            k++;
        }
        count++;
        temp=temp->next;
    }
    res.position[0]=k;
    if(flag==0)res.position[1]= -1;
    return res;
};
void insertAfterValueUnique(Node *&root, int srcVal, int value){
    int pos=searchValueUnique(root, srcVal);
    insertPosition(root, pos+1, value);
};
void insertAfterValueDuplicate(Node *&root, int srcVal, int value){
    Search res=searchValueDuplicate(root, srcVal);
    for(int i=1; i<res.position[0]; i++){
        int pos=res.position[i]+i;
        insertPosition(root, pos, value);
    }
};
void deleteHead(Node *&root){
    Node *delNode=root;
    root=delNode->next;
    delete delNode;
};
void deleteTail(Node *&root){
    Node *temp=root;
    if(temp->next==NULL) deleteHead(root);
    else{
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        Node *delNode=temp->next;
        temp->next=NULL;
        delete delNode;
    }
};
void deletePosition(Node *&root, int position){
    int size=getLength(root);
    if(position>size || position<1)cout<<"Position does not exist in List"<<endl;
    else if(position==1)deleteHead(root);
    else{
        int count=1;
        Node *temp=root;
        while(count<position-1){
            temp=temp->next;
            count++;
        }
        Node *delNode=temp->next;
        temp->next=delNode->next;
        delete delNode;
    }
};
void deleteByValueUnique(Node *&root, int value){
    int pos=searchValueUnique(root, value);
    if(pos!=-1) deletePosition(root, pos);
    else cout<<"Value does not exist in List"<<endl;
};
void deleteByValueDuplicate(Node *&root, int value){
    Search res=searchValueDuplicate(root, value);
    if(res.position[1]==-1) cout<<"Value does not exist in List"<<endl;
    else{
        for(int i=1; i<res.position[0]; i++){
            int pos=res.position[i]-i+1;
            deletePosition(root, pos);
        }
    }
};
int findMid(Node* &root){
    Node* fast=root;
    Node* slow=root;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->value;
};
void createCycle(Node* &root, int position){
    Node* temp=root;
    Node* startNode;
    int count=1;

    while(temp->next!=NULL){
        if(count==position)startNode=temp;
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
};
bool detectCycle(Node* root){
    Node* slow=root;
    Node* fast=root;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)return true;
    }
    return false;
};
void removeCycle(Node* &root){
    Node* slow=root;
    Node* fast=root;
    do{
        fast=fast->next->next;
        slow=slow->next;
    }while(fast!=slow);

    //reinitialize fast
    fast=root;
    //remove cycle by making last node->next=NULL;
    while(fast->next!=slow->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
};
