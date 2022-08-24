#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;

bool checkParenthesesBalance(string str){
    Stack<char> st;
    for(int i=0; i<str.length(); i++){
        if(st.empty()){
            st.push(str[i]);
            continue;
        }

        if((str[i]==')' && st.Top()=='(')
           || (str[i]=='}' && st.Top()=='{')
           || (str[i]==']' && st.Top()=='[')){
            st.pop();
        }
        else{
            st.push(str[i]);
        }
    }
    if(st.empty())return true;

    return false;
}

int main(){
    string str="({(())[{}])";//"({(())[{}]})"; "({(())[{}])"; "[(])"; "[()]{}{[()()]()}";
    bool isBalance=checkParenthesesBalance(str);
    if(isBalance)cout<<"Balanced Parentheses"<<endl;
    else cout<<"Unbalanced Parentheses"<<endl;

return 0;
}
