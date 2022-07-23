#include<bits/stdc++.h>

using namespace std;

//making restaurant class with access modifier (Q&A-1)
class Restaurant{
public:
    int food_codes[12];
    string food_names[12];
    int food_prices[12];
protected:
    int total_tax;
public:
    Restaurant(){
        this->total_tax=0;
    }
    void set_tax(int total_tax){
        this->total_tax += total_tax;
    }
    int show_tax(){
        return this->total_tax;
    }
};

//making class to collect food order with food code and quantity
class OrderedFoods{
public:
    int code;
    int quantity;
};

//Taking input of all food items available in the restaurant (Q&A-2)
Restaurant* create_menu(int n){
    Restaurant *foodMenu = new Restaurant();
    for(int i=0; i<n; i++){
        cin>>foodMenu->food_codes[i];
        char temp;
        cin>>temp;
        getline(cin,foodMenu->food_names[i]);
        foodMenu->food_names[i] =temp+foodMenu->food_names[i];
        cin>>foodMenu->food_prices[i];
    }

return foodMenu;
}

//Showing food menu with item code, name and price (Q&A-3)
void show_menu(Restaurant *foodMenu, int n){
    cout<<"\t\t\tMAKE BILL"<<endl;
    cout<<"\t\t_________________________"<<endl;
    cout<<"Item Code\t\t  "<<" Item Name\t\t\t"<<"Item Price"<<endl;
    for(int i=0; i<n; i++){
        cout<<foodMenu->food_codes[i]<<"\t\t\t";
        cout<<foodMenu->food_names[i] <<"\t\t";
        cout<<foodMenu->food_prices[i] <<endl;
    }
}

void process_order(int num_of_order, int num_of_items,
                    Restaurant *foodMenu, int table_no){
    OrderedFoods foodOrder[num_of_order];

    //receiving food order (Q&A-4)
    for(int i=0; i<num_of_order; i++){
        Code:
        cout<<"Enter Item "<<i+1<<" code: ";
        cin>>foodOrder[i].code;

        //verifying the availability of food item (Q&A-8)
        bool code_found=false;
        for(int j=0; j<num_of_items; j++){
            if(foodOrder[i].code==foodMenu->food_codes[j]){
                code_found=true;
            }
        }
        if(!code_found){
            cout<<"The Food you ordered is unavailable. please order other Item."<<endl;
            goto Code;
        }

        cout<<"Enter Item "<<i+1<<" Quantity: ";
        cin>>foodOrder[i].quantity;
    }

    //showing customer orders as summery (Q&A-5)
    cout<<"\t\t\tBILL SUMMARY"<<endl;
    cout<<"\t\t__________________________"<<endl;
    cout<<"Table No: "<<table_no<<endl;
    cout<<"Item Code\t "<<" Item Name\t\t"<<"Item Price\t";
    cout<<"Item Qty\t"<<"Total Price"<<endl;

    int total_price=0, item_price=0;
    float tax=0, net_total=0;

    for(int i=0; i<num_of_order; i++){
        for(int j=0; j<num_of_items; j++){
            if(foodOrder[i].code==foodMenu->food_codes[j]){
                cout<<foodMenu->food_codes[j]<<"\t\t";
                cout<<foodMenu->food_names[j]<<"\t";
                cout<<foodMenu->food_prices[j]<<"\t\t";
                cout<<foodOrder[i].quantity<<"\t\t";
                item_price=foodMenu->food_prices[j] * foodOrder[i].quantity;
                total_price+=item_price;
                cout<<item_price<<endl;

                //calculating tax (Q&A-6)
                tax += (float) item_price*0.05;
                break;
            }
        }
    }
    cout<<"TAX\t\t\t\t\t\t\t\t\t"<<tax<<endl;
    cout<<"________________________________________________";
    cout<<"________________________________________________"<<endl;
    net_total=total_price+tax;
    cout<<"NET TOTAL\t\t\t\t\t\t\t\t"<<net_total<<endl;

    //adding tax to total_tax in the restaurant class (Q&A-7)
    foodMenu->set_tax(tax);
    cout<<endl;
}


int main(){
    int num_of_items;
    cin>>num_of_items;
    Restaurant *foodMenu = create_menu(num_of_items);
    Start:
        show_menu(foodMenu,num_of_items);

        //taking order from customer (Q&A-4)
        int table_no, num_of_order;
        cout<<"Enter Table No: ";
        cin>>table_no;
        cout<<"Enter Number of Items: ";
        cin>>num_of_order;

        //taking order and processing order (Q&A- 4,5,6,7,8)
        process_order(num_of_order, num_of_items, foodMenu, table_no);

        goto Start;

return 0;
}
