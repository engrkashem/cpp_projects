#include<bits/stdc++.h>
#include"MYSTACK.h"
using namespace std;

int globalID=10001;

class Person{
    string name;
    int id;
    float salary;

public:
    Person(){
        string name="";
        int id=-1;
        float salary=-1.0;
    }
    void setName(string name){
        this->name=name;
    }
    void setSalary(float salary){
        this->salary=salary;
    }
    Person(string name, float salary){
        this->setName(name);
        this->setSalary(salary);
        this->id=globalID;
        globalID++;
    }
    string getName(){
        return this->name;
    }
    float getSalary(){
        return this->salary;
    }
    int getID(){
        return this->id;
    }
    void print(){
        cout<<this->name<<" | "<<this->id
            <<" | "<<this->salary<<endl;
    }
};

int main(){
//    Stack<pair<int, string>> st;
//    st.push(make_pair(1, "Abul Kashem"));
//    st.push(make_pair(1, "Sadat Sona"));
//    st.push(make_pair(1, "Jannatul Fateha"));
//    st.push(make_pair(1, "Umama"));
//    while(!st.empty()){
//        pair<int, string>result;
//        result=st.pop();
//        cout<<result.first<<" | "<<result.second<<endl;
//        //cout<<st.pop()<<endl;
//    }
//    cout<<st.size()<<endl;
//    if(!st.empty()){
//        pair<int, string>result;
//        result=st.Top();
//        cout<<result.first<<" | "<<result.second<<endl;
        //cout<<st.Top()<<endl;
//    }

    //Stack of class
    Person a("Abul Kashem", 158.3);
    Person b("Anar Koli", 254.6);
    Person c("Khairun Sundori", 881.9);
    //stack initialization
    Stack<Person> st;
    st.push(a);
    st.push(b);
    st.push(c);

//    while(!st.empty()){
//        Person printObj;
//        printObj=st.pop();
//        printObj.print();
//    }

    Person printObj;
    printObj=st.pop();
    printObj.print();
    cout<<st.size()<<endl;

return 0;
}
