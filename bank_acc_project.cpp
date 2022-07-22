#include<bits/stdc++.h>

using namespace std;

class BankAcc{
public:
    string acc_name;
    string address;
    int age;
    int acc_number;
protected:
    int balance;
private:
    string password;
public:
    BankAcc(string acc_name, string address, int age, string password){
        this->acc_name=acc_name;
        //this is a pointer that denotes relative class member.
        this->address=address;
        this->age=age;
        this->password=password;
        this->acc_number=rand()%1000000000;
        this->balance=0;
        cout<<"Your Account number is "<<this->acc_number<<endl;
    }
    int show_balance(string password){
        if(this->password==password){
            return balance;
        }
        else return 0;
    }
    void add_money(string password, int amount){
        if(amount<0){
            cout<<"invalid amount"<<endl;
            return;
        }
        if(this->password==password){
            balance+=amount;
            cout<<"Add money success"<<endl;
        }
        else cout<<"Enter to a valid password to add money to your Bank balance"<<endl;
    }
    void deposit_money(string password, int amount){
        if(amount<0){
            cout<<"invalid amount"<<endl;
            return;
        }
        if(this->balance<amount){
            cout<<"Insufficient balance"<<endl;
            return;
        }
        if(this->password==password){
            balance-=amount;
            cout<<"Deposit money success"<<endl;
        }
        else cout<<"Enter to a valid password to Deposit money to your Bank balance"<<endl;
    }
    friend class MyCash;
};

class MyCash{
protected:
    int balance;
public:
    MyCash(){
    this->balance=0;
    }
    void add_money_from_bank(BankAcc *myAccount, string password, int amount)
    {
        if(amount<0){
            cout<<"invalid amount"<<endl;
            return;
        }
        if(myAccount->balance<amount){
            cout<<"Insufficient balance"<<endl;
            return;
        }
        if(myAccount->password==password){
            this->balance += amount;
            myAccount->balance -= amount;
            cout<<"Add money from Bank success"<<endl;
        }
        else cout<<"Password didn't matched"<<endl;
    }
    int show_balance(){
        return balance;
    }
};

BankAcc* create_acc(){
    string acc_name, address, password;
    int age;
    cout<<"CREATE ACCOUNT"<<endl;
    cin>>acc_name>>address>>age>>password;
    BankAcc *myAccount=new BankAcc(acc_name, address, age, password);
    return myAccount;
}

void add_money(BankAcc *myAccount){
    string password;
    int amount;
    cout<<"ADD MONEY"<<endl;
    cin>>password>>amount;
    myAccount->add_money(password,amount);
    cout<<"Your Balance is "<<myAccount->show_balance("abc")<<endl;
}
void deposit_money(BankAcc *myAccount){
    string password;
    int amount;
    cout<<"DEPOSIT MONEY"<<endl;
    cin>>password>>amount;
    myAccount->deposit_money(password,amount);
    cout<<"Your Balance is "<<myAccount->show_balance("abc")<<endl;
}

void add_money_from_bank(MyCash *myCash, BankAcc *myAccount){
    string password;
    int amount;
    cout<<"ADD MONEY FROM BANK TO MYCASH"<<endl;
    cin>>password>>amount;
    myCash->add_money_from_bank(myAccount, password, amount);
    cout<<"Your Balance is "<<myAccount->show_balance("abc")<<endl;
    cout<<"Your MyCash Balance is "<<myCash->show_balance()<<endl;
}

int main(){
    BankAcc *myAccount = create_acc();
    //MyCash mc;
    //MyCash *myCash=&mc;
    MyCash *myCash= new MyCash();
    Start:
        cout<<"Select Option"<<endl;
        cout<<"1. Add Money to Bank"<<endl;
        cout<<"2. Deposit Money From bank"<<endl;
        cout<<"3. Add Money to Mycash from bank"<<endl;
        cout<<"0. To Exit"<<endl;
        int option;
        cin>>option;
        if(option==1)add_money(myAccount);
        else if(option==2)deposit_money(myAccount);
        else if(option==3)add_money_from_bank(myCash, myAccount);
        else if(option==0){
            delete myAccount;
            delete myCash;
            return 0;
        }
        else cout<<"Invalid option"<<endl;
        goto Start;

return 0;
}
