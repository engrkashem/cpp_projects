#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;

bool checkParenthesesBalance(string str){
    Stack<char> st;
    for(int i=0; i<str.length(); i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            st.push(str[i]);
            continue;
        }

        if(str[i]==')' || str[i]=='}' || str[i]==']'){
            if(st.empty())return false;
            char chk=st.pop();
            if(str[i]==')' && chk=='(')continue;
            if(str[i]=='}' && chk=='{')continue;
            if(str[i]==']' && chk=='[')continue;
            return false;
        }
    }
    if(st.empty())return true;
    else return false;
}

int main(){
    string str="({(())[{}]})";//({(())[{}])"; "[(])"; "[()]{}{[()()]()}";
    bool isBalance=checkParenthesesBalance(str);
    if(isBalance)cout<<"Balanced Parentheses"<<endl;
    else cout<<"Unbalanced Parentheses"<<endl;

return 0;
}
