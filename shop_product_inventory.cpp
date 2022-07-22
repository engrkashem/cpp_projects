#include<bits/stdc++.h>

using namespace std;

class Shop{
public:
    string product_name[10];
    int product_price[10];
    int product_quantity[10];
protected:
    int total_income;
private:
    string password;
public:
    Shop(){
        this->total_income=0;
    }
    int get_total_income(){
        return this->total_income;
    }
    void set_total_balance(int total_income){
        this->total_income+=total_income;
    }
};

Shop* create_products(int n){
    Shop *myProduct=new Shop();
    for(int i=0; i<n; i++){
        cout<<"Product "<<i+1<<" name: ";
        cin>>myProduct->product_name[i];
        cout<<"Product "<<i+1<<" price: ";
        cin>>myProduct->product_price[i];
        cout<<"Product "<<i+1<<" quantity: ";
        cin>>myProduct->product_quantity[i];
    }
    return myProduct;
}

void show_all_product(Shop *myProduct, int n){
    cout<<endl;
    cout<<"\t\t BUY PRODUCT"<<endl;
    cout<<"\t\t____________"<<endl;
    cout<<"Product Number\t\t";
    for(int i=0; i<n; i++){
        cout<<i+1<<"\t";
    }
    cout<<endl;

    cout<<"Product Name\t\t";
    for(int i=0; i<n; i++){
        cout<<myProduct->product_name[i] <<"\t";
    }
    cout<<endl;

    cout<<"Product Price\t\t";
    for(int i=0; i<n; i++){
        cout<<myProduct->product_price[i] <<"\t";
    }
    cout<<endl;

    cout<<"Product Quantity\t";
    for(int i=0; i<n; i++){
        cout<<myProduct->product_quantity[i] <<"\t";
    }
    cout<<endl;
}
void take_order(int n, Shop *myProduct){
    cout<<"Which Product do you want? from 1 to "<<n<<" : ";
        int p_num, qty;
        cin>>p_num;
        p_num--;
        cout<<"Quantity do you want to buy "<<myProduct->product_name[p_num] <<" ?: ";
        cin>>qty;
        if(myProduct->product_quantity[p_num] <qty){
            cout<<"Insufficient Stock of "<<myProduct->product_name[p_num]<<endl;
        }
        else{
            myProduct->set_total_balance( qty * myProduct->product_price[p_num] );
            myProduct->product_quantity[p_num] -= qty;
            cout<<endl;
            cout<<"Your Order for "<<qty<<" of "<<myProduct->product_name[p_num]<<" is successful."<<endl;
            cout<<"Your Total Income is: "<<myProduct->get_total_income()<<endl;
        }
}

int main(){
    int n;
    cout<<"Number of Products: ";
    cin>>n;
    Shop *myProduct=create_products(n);
    Start:
        show_all_product(myProduct,n);
        take_order(n,myProduct);
    goto Start;

return 0;
}
