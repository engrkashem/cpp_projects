#include<bits/stdc++.h>
using namespace std;
//template is used to generalize a function
//    or structure in terms of data type

template<typename T> T myMax(T a, T b){
    return a>b?a:b;
}

int main(){
    //function calling system
    //functionName <data type> (parameter)
    cout<<myMax <int>(3,7)<<endl;
    cout<<myMax<float>(3.5,8.7)<<endl;
    cout<<myMax<char>('a','d')<<endl;

return 0;
}
