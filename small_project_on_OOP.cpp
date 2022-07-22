#include<bits/stdc++.h>

using namespace std;
//practice problem of practice module 6.5

class Student{
    public:
        string name;
        char sec;
        int roll;

    protected:
        int english_mark;

    private:
        string password;

    public:
        void set_marks(int m){
            english_mark=m;
        }
        int get_marks(){
            return english_mark;
        }
        void set_password(string p){
            password=p;
        }
        string get_password(){
            return password;
        }
        void update_marks(string pass, int u_m){
            if(password==pass){
                english_mark=u_m;
            }
            else{
                cout<<"Password did not matched"<<endl;
            }
        }
};

int main(){
    int n;
    cin>>n;
    Student a[n];
    for(int i=0; i<n; i++){
        cin>>a[i].name>>a[i].sec>>a[i].roll;
        int m;
        cin>>m;
        a[i].set_marks(m);
        string p;
        cin>>p;
        a[i].set_password(p);
    }

    int roll, marks;
    string pass;
    cin>>roll>>marks>>pass;
    for(int i=0; i<n; i++){
        if(a[i].roll==roll){
            a[i].update_marks(pass, marks);
        }
    }

    for(int i=0; i<n; i++){
        cout<<a[i].name<<" "<<a[i].sec<<" "<<a[i].roll<<" ";
        cout<<a[i].get_marks()<<endl;
    }


return 0;
}
