#include<bits/stdc++.h>
#include"PRACTICESTACK.h"

using namespace std;

int checkPrecision(char c){
    if(c=='+' || c=='-')return 1;
    else if(c=='*' || c=='/')return 2;
    else if(c=='^')return 3;
    else return -1;
}

string infixToPrefix(string str){
    Stack<char>st;
    string result;
    for(int i=str.length()-1; i>=0; i--){
        if(str[i]>='0' && str[i]<='9'){// 'a' to 'z' && 'A' to 'Z'
            result+=str[i];
        }
        else if(str[i]==')'){
            st.push(str[i]);
        }
        else if(str[i]=='('){
            while(!st.empty() && st.Top()!=')'){
                result+=st.pop();
            }
            if(!st.empty())st.pop();
        }
        else{
            while(!st.empty() && checkPrecision(st.Top()) > checkPrecision(str[i])){
                result+=st.pop();
            }
            st.push(str[i]);
        }
    }
    while(!st.empty()){
        result+=st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

string infixToPostfix(string str){
    Stack<char>st;
    string result;
    for(int i=0; i<str.length(); i++){
        if(str[i]>='0' && str[i]<='9'){// 'a' to 'z' && 'A' to 'Z'
            result+=str[i];
        }
        else if(str[i]=='('){
            st.push(str[i]);
        }
        else if(str[i]==')'){
            while(!st.empty() && st.Top()!='('){
                result+=st.pop();
            }
            if(!st.empty())st.pop();
        }
        else{
            while(!st.empty() && checkPrecision(st.Top()) > checkPrecision(str[i])){
                result+=st.pop();
            }
            st.push(str[i]);
        }
    }
    while(!st.empty()){
        result+=st.pop();
    }
    //reverse(result.begin(), result.end());
    return result;
}

int prefixEvaluation(string str){
    Stack<int> st;
    int a,b;
    for(int i=str.length()-1; i>=0; i--){
        switch(str[i]){
        case '+':
            a=st.pop();
            b=st.pop();
            st.push(a+b);
            break;
        case '-':
            a=st.pop();
            b=st.pop();
            st.push(a-b);
            break;
        case '*':
            a=st.pop();
            b=st.pop();
            st.push(a*b);
            break;
        case '/':
            a=st.pop();
            b=st.pop();
            st.push(a/b);
            break;
        case '^':
            a=st.pop();
            b=st.pop();
            st.push(pow(a,b));
            break;
        default:
            st.push(str[i]-'0');
            break;
        }
    }
    //int res=st.Top();
    return st.Top();
}

int main(){
    string infix="(7+(4*5))-(2+0)";//"(4*(3+5))-(2+0)";//"(7+(4*5))-(2+0)";
    //cin>>infix;
    string prefix=infixToPrefix(infix);
    string postfix=infixToPostfix(infix);
    int result1=prefixEvaluation(prefix);
    int result2=prefixEvaluation(postfix);
    cout<<endl
        <<prefix<<" ||| "<<result1<<endl
        <<postfix<<" ||| "<<result1<<endl;

return 0;
}
