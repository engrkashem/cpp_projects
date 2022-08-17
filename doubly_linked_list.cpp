#include<bits/stdc++.h>
using namespace std;

class DNode{
public:
    int val;
    DNode *prev;
    DNode *next;

    DNode(int val){
        this->val=val;
        this->prev=NULL;
        this->next=NULL;
    }
};
struct Search{
    int position[1000];
};

int getSize(DNode* &head);
void display(DNode* &head);
void insertHead(DNode* &head, int val);
void insertTail(DNode* &head, int val);
void insertPositionWise(DNode* &head, int pos, int val);
int searchValueUniqueList(DNode* &head, int val);
Search searchValueDuplicateList(DNode* &head, int val);
void deleteHead(DNode* &head);
void deleteTail(DNode* &head);
void deletePositionWise(DNode* &head, int pos);
void printReverse(DNode* &head);

int main(){
    DNode* head=NULL;
    Search result;
    cout<<"Choice 1: Find Length of List"<<endl
        <<"Choice 2: Display Doubly List"<<endl
        <<"Choice 3: Insert At Head"<<endl
        <<"Choice 4: Insert At Tail"<<endl
        <<"Choice 5: Insert At Specific Position"<<endl
        <<"Choice 6: Search a Value from Unique List"<<endl
        <<"Choice 7: Search a Value from Duplicate Enabled List"<<endl
        <<"Choice 8: Insert After a Value in Unique List"<<endl
        <<"Choice 9: Insert After a Value in Duplicate Enabled List"<<endl
        <<"Choice 10: Delete At Head"<<endl
        <<"Choice 11: Delete At Tail"<<endl
        <<"Choice 12: Delete At Specific Position"<<endl
        <<"Choice 13: Delete Value from Unique List"<<endl
        <<"Choice 14: Delete Value from Duplicate Enabled List"<<endl
        <<"Choice 15: Reverse the Doubly List"<<endl
        <<"Choice 0: To Exit."<<endl;
        int choice, val, n, res;
        cin>>choice;
        while(choice!=0){
            switch(choice){
            case 1:
                cout<<"List Size is: "<<getSize(head)<<endl;
                break;
            case 2:
                if(head==NULL)cout<<"Doubly Linked List is Empty."
                                  <<endl;
                else display(head);
                break;
            case 3:
                cout<<"Enter the Value to Insert ";
                cin>>val;
                insertHead(head, val);
                break;
            case 4:
                cout<<"Enter the Value to Insert ";
                cin>>val;
                insertTail(head, val);
                break;
            case 5:
                cout<<"Enter the Value to Insert ";
                cin>>val;
                cout<<"Enter The Position Where to Insert ";
                cin>>n;
                insertPositionWise(head, n, val);
                break;
            case 6:
                if(head==NULL)cout<<"Doubly Linked List is Empty."
                                  <<endl;
                else{
                    cout<<"Enter the Value To Search ";
                    cin>>val;
                    n=searchValueUniqueList(head,val);
                    if(n==-1)
                        cout<<"Value Does not Exist in List"<<endl;
                    else
                    cout<<"The Position of "<<val<<" is: "<<n<<endl;
                }
                break;
            case 7:
                if(head==NULL)
                    cout<<"Doubly Linked List is Empty."<<endl;
                else{
                    cout<<"Enter the Value To Search ";
                    cin>>val;
                    result=searchValueDuplicateList(head,val);
                    if(result.position[1] == -1)
                        cout<<"Value Does not Exist in List"<<endl;
                    else{
                        cout<<"The Positions of "<<val<<" are: ";
                        for(int i=1; i<result.position[0]; i++){
                            cout<<result.position[i];
                            if(i!= result.position[0]-1)cout<<" , ";
                            else cout<<endl;
                        }
                    }
                }
                break;
            case 8:
                if(head==NULL)
                    cout<<"Doubly Linked List is Empty."<<endl;
                else{
                    cout<<"Enter the Value To Search ";
                    cin>>n;
                    cout<<"Enter The Value to Insert ";
                    cin>>val;
                    res=searchValueUniqueList(head,n);
                    if(res == -1)
                        cout<<"Value Does not Exist in List"<<endl;
                    else insertPositionWise(head, res+1, val);
                }
                break;
            case 9:
                if(head==NULL)
                    cout<<"Doubly Linked List is Empty."<<endl;
                else{
                    cout<<"Enter the Value To Search ";
                    cin>>n;
                    cout<<"Enter The Value to Insert ";
                    cin>>val;
                    result=searchValueDuplicateList(head,n);
                    if(result.position[1] == -1)
                        cout<<"Value Does not Exist in List"<<endl;
                    else{
                        for(int i=1; i<result.position[0]; i++){
                            res=result.position[i]+i;
                            insertPositionWise(head, res, val);
                        }
                    }
                }
                break;
            case 10:
                if(head==NULL)
                    cout<<"Doubly Linked List is Empty."<<endl;
                else deleteHead(head);
                break;
            case 11:
                if(head==NULL)
                    cout<<"Doubly Linked List is Empty."<<endl;
                else deleteTail(head);
                break;
            case 12:
                if(head==NULL)
                    cout<<"Doubly Linked List is Empty."<<endl;
                else{
                    cout<<"Enter The Position that want to Delete ";
                    cin>>n;
                    deletePositionWise(head, n);
                }
                break;
            case 13:
                if(head==NULL)
                    cout<<"Doubly Linked List is Empty."<<endl;
                else{
                    cout<<"Enter the Value You Want to Delete ";
                    cin>>val;
                    res=searchValueUniqueList(head, val);
                    if(res == -1)
                        cout<<"Value Does not Exist in List"<<endl;
                    else deletePositionWise(head, res);
                }
                break;
            case 14:
                if(head==NULL)
                    cout<<"Doubly Linked List is Empty."<<endl;
                else{
                    cout<<"Enter the Value You Want to Delete ";
                    cin>>val;
                    result=searchValueDuplicateList(head,val);
                    if(result.position[1] == -1)
                        cout<<"Value Does not Exist in List"<<endl;
                    else{
                        for(int i=1; i<result.position[0]; i++){
                            res=result.position[i]-i+1;
                            deletePositionWise(head, res);
                        }
                    }
                }
                break;
            case 15:
                if(head==NULL)
                    cout<<"Doubly Linked List is Empty."<<endl;
                else printReverse(head);
            break;
            default: break;
            }
        cout<<"Next Choice: ";
        cin>>choice;
        }

return 0;
};

int getSize(DNode* &head){
    DNode *temp=head;
    int count=0;
    while(temp != NULL){
        count++;
        temp=temp->next;
    }
    return count;
};
void display(DNode* &head){
    DNode* temp=head;
    while(temp!=NULL){
        cout<<temp->val;
        if(temp->next!=NULL)cout<<" <---> ";
        temp=temp->next;
    }
    cout<<endl;
};
void insertHead(DNode* &head, int val){
    DNode *newNode= new DNode(val);
    if(head==NULL){
        head=newNode;
        return;
    }
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
};
void insertTail(DNode* &head, int val){
    DNode *newNode=new DNode(val);
    if(head==NULL)head=newNode;
    else{
        DNode *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
};
void insertPositionWise(DNode* &head, int pos, int val){
    int size=getSize(head);
    if(pos==1)insertHead(head, val);
    else if(pos==size+1)insertTail(head, val);
    else if(pos>size+1)
        cout<<"Position does not Exist/Invalid in List"<<endl;
    else{
        DNode *newNode=new DNode(val);
        DNode *temp=head;
        int count=1;
        while(count<pos-1){
            temp=temp->next;
            count++;
        }
        newNode->next=temp->next;
        newNode->prev=temp;
        temp->next->prev=newNode;
        temp->next=newNode;
    }
};
int searchValueUniqueList(DNode* &head, int val){
    DNode *temp=head;
    int count=1, flag=0;
    while(temp!=NULL){
        if(temp->val==val){
            flag=1;
            break;
        }
        count++;
        temp=temp->next;
    }
    if(flag==0)return -1;
    return count;
};
Search searchValueDuplicateList(DNode* &head, int val){
    DNode *temp=head;
    Search res;
    int count=1, k=1, flag=0;
    while(temp!=NULL){
        if(temp->val==val){
            res.position[k]=count;
            k++;
            flag=1;
        }
        count++;
        temp=temp->next;
    }
    res.position[0]=k;
    if(flag==0)res.position[1]=-1;
    return res;
};
void deleteHead(DNode* &head){
   DNode *delNode=head;
   head=delNode->next;
   delete delNode;
};
void deleteTail(DNode* &head){
    DNode *temp=head;
    if(temp->next==NULL)deleteHead(head);
    else{
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        DNode *delNode=temp->next;
        temp->next=NULL;
        delete delNode;
    }
};
void deletePositionWise(DNode* &head, int pos){
    int size=getSize(head);
    if(pos>size)cout<<"Position does not Exist/Invalid in List"<<endl;
    else{
        int count=1;
        DNode *temp=head;
        while(count<pos-1){
            temp=temp->next;
            count++;
        }
        if(pos==1)deleteHead(head);
        else if(temp->next->next==NULL)deleteTail(head);
        else{
            DNode *delNode=temp->next;
            temp->next=delNode->next;
            delNode->next->prev=temp;
            delete delNode;
        }
    }
};
void printReverse(DNode* &head){
    DNode* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    while(temp!=NULL){
        cout<<temp->val;
        if(temp->prev!=NULL)cout<<" <--> ";
        temp=temp->prev;
    }
    cout<<endl;
};
